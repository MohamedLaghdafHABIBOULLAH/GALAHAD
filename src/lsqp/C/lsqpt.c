/* lsqpt.c */
/* Full test for the LSQP C interface using C sparse matrix indexing */

#include <stdio.h>
#include <math.h>
#include "lsqp.h"

int main(void) {

    // Derived types
    void *data;
    struct lsqp_control_type control;
    struct lsqp_inform_type inform;

    // Set problem data
    int n = 3; // dimension
    int m = 2; // number of general constraints
    double g[] = {0.0, 2.0, 0.0};   // linear term in the objective
    double f = 1.0;  // constant term in the objective
    int A_ne = 4; // Jacobian elements
    int A_row[] = {0, 0, 1, 1}; // row indices
    int A_col[] = {0, 1, 1, 2}; // column indices
    int A_ptr[] = {0, 2, 4}; // row pointers
    double A_val[] = {2.0, 1.0, 1.0, 1.0 }; // values
    double c_l[] = {1.0, 2.0};   // constraint lower bound
    double c_u[] = {2.0, 2.0};   // constraint upper bound
    double x_l[] = {-1.0, - INFINITY, - INFINITY}; // variable lower bound
    double x_u[] = {1.0, INFINITY, 2.0}; // variable upper bound
    double w[] = {1.0,1.0,1.0};
    double x_0[] = {0.0,0.0,0.0};

    // Set output storage
    double c[m]; // constraint values
    int x_stat[n]; // variable status
    int c_stat[m]; // constraint status
    char st;
    int status;

    printf(" C sparse matrix indexing\n\n");

    printf(" basic tests of qp storage formats\n\n");

    for( int d=1; d <= 3; d++){

        // Initialize LSQP
        lsqp_initialize( &data, &control, &status );

        // Set user-defined control options
        control.f_indexing = false; // C sparse matrix indexing

        // Start from 0
        double x[] = {0.0,0.0,0.0};
        double y[] = {0.0,0.0};
        double z[] = {0.0,0.0,0.0};

        switch(d){
            case 1: // sparse co-ordinate storage
                st = 'C';
                lsqp_import( &control, &data, &status, n, m,
                            "coordinate", A_ne, A_row, A_col, NULL );
                lsqp_solve_qp( &data, &status, n, m, w, x_0, g, f, 
                               A_ne, A_val, c_l, c_u, x_l, x_u, x, c, y, z, 
                               x_stat, c_stat );
                break;
            printf(" case %1i break\n",d);
            case 2: // sparse by rows
                st = 'R';
                lsqp_import( &control, &data, &status, n, m, 
                             "sparse_by_rows", A_ne, NULL, A_col, A_ptr );
                lsqp_solve_qp( &data, &status, n, m, w, x_0, g, f, 
                               A_ne, A_val, c_l, c_u, x_l, x_u, x, c, y, z, 
                               x_stat, c_stat );
                break;
            case 3: // dense
                st = 'D';
                int A_dense_ne = 6; // number of elements of A
                double A_dense[] = {2.0, 1.0, 0.0, 0.0, 1.0, 1.0};
                lsqp_import( &control, &data, &status, n, m,
                             "dense", A_dense_ne, NULL, NULL, NULL );
                lsqp_solve_qp( &data, &status, n, m, w, x_0, g, f, 
                               A_dense_ne, A_dense, c_l, c_u, x_l, x_u, 
                               x, c, y, z, x_stat, c_stat );
                break;
            }
        lsqp_information( &data, &inform, &status );

        if(inform.status == 0){
            printf("%c:%6i iterations. Optimal objective value = %5.2f status = %1i\n",
                   st, inform.iter, inform.obj, inform.status);
        }else{
            printf("%c: LSQP_solve exit status = %1i\n", st, inform.status);
        }
        //printf("x: ");
        //for( int i = 0; i < n; i++) printf("%f ", x[i]);
        //printf("\n");
        //printf("gradient: ");
        //for( int i = 0; i < n; i++) printf("%f ", g[i]);
        //printf("\n");

        // Delete internal workspace
        lsqp_terminate( &data, &control, &inform );
    }
}

