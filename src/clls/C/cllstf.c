/* cllstf.c */
/* Full test for the CLLS C interface using Fortran sparse matrix indexing */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "galahad_precision.h"
#include "galahad_cfunctions.h"
#include "galahad_clls.h"

int main(void) {

    // Derived types
    void *data;
    struct clls_control_type control;
    struct clls_inform_type inform;

    // Set problem data
    int n = 3; // dimension
    int o = 4; // number of observations
    int m = 2; // number of general constraints
    real_wp_ b[] = {2.0, 2.0, 3.0, 1.0};   // observations
    real_wp_ c_l[] = {1.0, 2.0};   // constraint lower bound
    real_wp_ c_u[] = {2.0, 2.0};   // constraint upper bound
    real_wp_ x_l[] = {-1.0, - INFINITY, - INFINITY}; // variable lower bound
    real_wp_ x_u[] = {1.0, INFINITY, 2.0}; // variable upper bound
    real_wp_ w[] = {1.0, 1.0, 1.0, 2.0}; // weights

    // Set output storage
    real_wp_ r[o]; // residual values
    real_wp_ c[m]; // constraint values
    int x_stat[n]; // variable status
    int c_stat[m]; // constraint status
    char st[3];
    int status;

    printf(" Fortran sparse matrix indexing\n\n");

    printf(" basic tests of clls storage formats\n\n");

    for( int d=1; d <= 5; d++){

        // Initialize CLLS
        clls_initialize( &data, &control, &status );

        // Set user-defined control options
        control.f_indexing = true; // Fortran sparse matrix indexing

        // Start from 0
        real_wp_ x[] = {0.0,0.0,0.0};
        real_wp_ y[] = {0.0,0.0};
        real_wp_ z[] = {0.0,0.0,0.0};

        switch(d){
            case 1: // sparse co-ordinate storage
                strcpy(st, "CO");
                {
                int Ao_ne = 7; // objective Jacobian elements
                int Ao_row[] = {1, 1, 2, 2, 3, 3, 4};   // row indices
                int Ao_col[] = {1, 2, 2, 3, 1, 3, 2};    // column indices
                real_wp_ Ao_val[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}; // vals
                int A_ne = 4; // constraint Jacobian elements
                int A_row[] = {1, 1, 2, 2}; // row indices
                int A_col[] = {1, 2, 2, 3}; // column indices
                real_wp_ A_val[] = {2.0, 1.0, 1.0, 1.0}; // values
                clls_import( &control, &data, &status, n, o, m,
                            "coordinate", Ao_ne, Ao_row, Ao_col, 0, NULL,
                            "coordinate", A_ne, A_row, A_col, 0, NULL );
                clls_solve_clls( &data, &status, n, o, m, Ao_ne, Ao_val, b, 
                                 A_ne, A_val, c_l, c_u, x_l, x_u, 
                                 x, r, c, y, z, x_stat, c_stat, w, 0.0 );
                }
                break;
            case 2: // sparse by rows
                strcpy(st, "SR");
                {
                int Ao_ne = 7; // objective Jacobian elements
                int Ao_col[] = {1, 2, 2, 3, 1, 3, 2};    // column indices
                int Ao_ptr_ne = 5; // number of row pointers
                int Ao_ptr[] = {1, 3, 5, 7, 8}; // row pointers
                real_wp_ Ao_val[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}; // vals
                int A_ne = 4; // constraint Jacobian elements
                int A_col[] = {1, 2, 2, 3}; // column indices
                int A_ptr_ne = 3; // number of row pointers
                int A_ptr[] = {1, 3, 5}; // row pointers
                real_wp_ A_val[] = {2.0, 1.0, 1.0, 1.0 }; // values
                clls_import( &control, &data, &status, n, o, m, 
                             "sparse_by_rows", Ao_ne, NULL, Ao_col, 
                             Ao_ptr_ne, Ao_ptr,
                             "sparse_by_rows", A_ne, NULL, A_col, 
                             A_ptr_ne, A_ptr );
                clls_solve_clls( &data, &status, n, o, m, Ao_ne, Ao_val, b, 
                                 A_ne, A_val, c_l, c_u, x_l, x_u, 
                                 x, r, c, y, z, x_stat, c_stat, w, 0.0 );
                }
                break;
            case 3: // sparse by columns
                strcpy(st, "SC");
                {
                int Ao_ne = 7; // objective Jacobian elements
                int Ao_row[] = {1, 3, 1, 2, 4, 2, 3};   // row indices
                int Ao_ptr_ne = 4; // number of column pointers
                int Ao_ptr[] = {1, 3, 6, 8}; // column pointers
                real_wp_ Ao_val[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}; // vals
                int A_ne = 4; // constraint Jacobian elements
                int A_row[] = {1, 1, 2, 2}; // row indices
                int A_ptr_ne = 4; // number of column pointers
                int A_ptr[] = {1, 2, 4, 5}; // column pointers
                real_wp_ A_val[] = {2.0, 1.0, 1.0, 1.0 }; // values
                clls_import( &control, &data, &status, n, o, m, 
                             "sparse_by_columns", Ao_ne, Ao_row, NULL, 
                             Ao_ptr_ne, Ao_ptr,
                             "sparse_by_columns", A_ne, A_row, NULL,
                             A_ptr_ne, A_ptr );
                clls_solve_clls( &data, &status, n, o, m, Ao_ne, Ao_val, b, 
                                 A_ne, A_val, c_l, c_u, x_l, x_u, 
                                 x, r, c, y, z, x_stat, c_stat, w, 0.0 );
                }
                break;
            case 4: // dense by rows
                strcpy(st, "DR");
                {
                int Ao_ne = 12; // objective Jacobian elements
                real_wp_ Ao_dense[] = {1.0, 1.0, 0.0, 0.0, 1.0, 1.0,
                                       1.0, 0.0, 1.0, 0.0, 1.0, 0.0};
                int A_ne = 6; // constraint Jacobian elements
                real_wp_ A_dense[] = {2.0, 1.0, 0.0, 0.0, 1.0, 1.0};
                clls_import( &control, &data, &status, n, o, m,
                             "dense", Ao_ne, NULL, NULL, 0, NULL,
                             "dense", A_ne, NULL, NULL, 0, NULL );
                clls_solve_clls( &data, &status, n, o, m, Ao_ne, Ao_dense, b, 
                                 A_ne, A_dense, c_l, c_u, x_l, x_u, 
                                 x, r, c, y, z, x_stat, c_stat, w, 0.0 );
                }
                break;
            case 5: // dense by cols
                strcpy(st, "DC");
                {
                int Ao_ne = 12; // objective Jacobian elements
                real_wp_ Ao_dense[] = {1.0, 0.0, 1.0, 0.0, 1.0, 1.0,
                                       0.0, 1.0, 0.0, 1.0, 1.0, 0.0};
                int A_ne = 6; // constraint Jacobian elements
                real_wp_ A_dense[] = {2.0, 0.0, 1.0, 1.0, 0.0, 1.0};
                clls_import( &control, &data, &status, n, o, m,
                             "dense_by_columns", Ao_ne, NULL, NULL, 0, NULL,
                             "dense_by_columns", A_ne, NULL, NULL, 0, NULL );
                clls_solve_clls( &data, &status, n, o, m, Ao_ne, Ao_dense, b, 
                                 A_ne, A_dense, c_l, c_u, x_l, x_u, 
                                 x, r, c, y, z, x_stat, c_stat, w, 0.0 );
                }
                break;
            }
        clls_information( &data, &inform, &status );

        if(inform.status == 0){
            printf("%s:%6i iterations. Optimal objective value = %5.2f status = %1i\n",
                   st, inform.iter, inform.obj, inform.status);
        }else{
            printf("%s: CLLS_solve exit status = %1i\n", st, inform.status);
        }
        //printf("x: ");
        //for( int i = 0; i < n; i++) printf("%f ", x[i]);
        //printf("\n");
        //printf("gradient: ");
        //for( int i = 0; i < n; i++) printf("%f ", g[i]);
        //printf("\n");

        // Delete internal workspace
        clls_terminate( &data, &control, &inform );
    }
}

