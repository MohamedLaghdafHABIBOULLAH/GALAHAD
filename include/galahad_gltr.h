//* \file galahad_gltr.h */

/*
 * THIS VERSION: GALAHAD 3.3 - 16/12/2021 AT 10:16 GMT.
 *
 *-*-*-*-*-*-*-*-*-  GALAHAD_GLTR C INTERFACE  *-*-*-*-*-*-*-*-*-*-
 *
 *  Copyright reserved, Gould/Orban/Toint, for GALAHAD productions
 *  Principal author: Jaroslav Fowkes & Nick Gould
 *
 *  History -
 *   originally released GALAHAD Version 3.3. December 16th 2021
 *
 *  For full documentation, see
 *   http://galahad.rl.ac.uk/galahad-www/specs.html
 */

/*! \mainpage GALAHAD C package gltr

  \section gltr_intro Introduction

  \subsection gltr_purpose Purpose

  Given real \f$n\f$ by \f$n\f$ symmetric matrices \f$H\f$ and \f$M\f$
  (with \f$M\f$ positive definite), a real \f$n\f$ vector \f$c\f$ and
  scalars \f$\Delta>0\f$ and \f$f_0\f$, this package finds an
  <b> approximate minimizer of the quadratic objective function
  \f$\frac{1}{2} x^T H x  +  c^T x + f_0\f$, where the vector \f$x\f$ is
  required to satisfy the constraint \f$\|x\|_M \leq  \Delta\f$</b>, and
  where the \f$M\f$-norm of \f$x\f$ is \f$\|x\|_M = \sqrt{x^T M x}\f$.
  This problem commonly occurs as a trust-region subproblem in nonlinear
  optimization calculations.
  The method may be suitable for large \f$n\f$ as no factorization of \f$H\f$
  is required. Reverse communication is used to obtain
  matrix-vector products of the form \f$H z\f$ and \f$M^{-1} z\f$.

  The package may also be used to solve the related problem in which \f$x\f$ is
  instead required to satisfy the
  <b>equality constraint \f$\|x\|_M = \Delta\f$</b>.

  \subsection gltr_authors Authors

  N. I. M. Gould, STFC-Rutherford Appleton Laboratory, England.

  C interface, additionally J. Fowkes, STFC-Rutherford Appleton Laboratory.

  Julia interface, additionally A. Montoison and D. Orban, Polytechnique Montréal.

  \subsection gltr_date Originally released

  April 1997, C interface December 2021.

  \subsection gltr_terminology Terminology

  \subsection gltr_method Method

  The required solution \f$x\f$ necessarily satisfies the optimality condition
  \f$H x + \lambda M x + c = 0\f$, where \f$\lambda \geq 0\f$  is a Lagrange
  multiplier corresponding to the constraint \f$\|x\|_M  \leq  \Delta\f$.
  In addition, the matrix \f$H + \lambda M\f$ will be positive definite.

  The method is iterative. Starting  with the vector \f$M^{-1} c\f$,
  a matrix of Lanczos vectors is built one column at a time
  so that the \f$k\f$-th column is generated during
  iteration \f$k\f$. These columns span a so-called Krylov space.
  The resulting \f$n\f$ by \f$k\f$ matrix \f$Q_k \f$ has the
  property that \f$Q_k^T H Q_k^{}  =  T_k^{}\f$,
  where \f$T_k\f$ is tridiagonal. An approximation to the
  required solution may then be expressed formally as
  \f[x_{k+1}  =  Q_k y_k,\f]
\manonly
\n
   x_{k+1}  =  Q_k y_k,
\n
\endmanonly
  where \f$y_k \f$ solves the ``tridiagonal'' subproblem of minimizing
\f[(1) \;\;\; \frac{1}{2} y^T T_k y  + \|c\|_{M^{-1}} e_1^T y\;\mbox{subject to the constraint}\; \|y\|_2  \leq  \Delta,\f]
\manonly
\n
  (1)    1/2 y^T T_k y  + ||c||_M^{-1} e_1^T y
         subject to the constraint \|y\|_2  leq  Delta,
\n
\endmanonly
  and where \f$e_1\f$ is the first unit vector.

  If the solution to (1) lies interior to the constraint, the required
  solution \f$x_{k+1}\f$ may simply be found as the \f$k\f$-th (preconditioned)
  conjugate-gradient iterate. This solution can be obtained without the need to
  access the whole matrix \f$Q_k\f$.   These conjugate-gradient iterates
   increase in \f$M\f$-norm, and thus once one of them exceeds
  \f$\Delta\f$ in \f$M\f$-norm, the solution must occur
  on the constraint boundary. Thereafter, the solution to (1) is less
  easy to obtain, but an efficient inner iteration to solve (1) is
  nonetheless achievable because \f$T_k \f$ is tridiagonal.
  It is possible to observe the optimality measure
  \f$\|H x  +  \lambda M x  +  c\|_{M^{-1}}\f$
  without computing \f$x_{k+1}\f$, and thus without
  needing \f$Q_k \f$. Once this measure is sufficiently small, a second pass
  is required to obtain the estimate \f$x_{k+1} \f$ from \f$y_k \f$.
  As this second pass is an additional expense, a record is kept of the
  optimal objective function values for each value of \f$k\f$, and the second
  pass is only performed so far as to ensure a given fraction of the
  final optimal objective value. Large savings may be made in the second
  pass by choosing the required fraction to be significantly smaller than one.

  A cheaper alternative is to use the Steihuag-Toint strategy, which is simply
  to stop at the first boundary point encountered along the piecewise
  linear path generated by the conjugate-gradient iterates. Note that if
  \f$H\f$ is significantly indefinite, this strategy often produces a far from
  optimal point, but is effective when \f$H\f$ is positive definite or almost

  \subsection gltr_references Reference

  The method is described in detail in

  N. I. M. Gould, S. Lucidi, M. Roma and Ph. L. Toint,
  Solving the trust-region subproblem using the Lanczos method.
  SIAM Journal on Optimization <b>9:2</b> (1999), 504-525.

  \subsection gltr_call_order Call order

  To solve a given problem, functions from the gltr package must be called
  in the following order:

  - \link gltr_initialize \endlink - provide default control parameters and
      set up initial data structures
  - \link gltr_read_specfile \endlink (optional) - override control values
      by reading replacement values from a file
  - \link gltr_import_control \endlink - import control parameters prior to
      solution
  - \link gltr_solve_problem \endlink - solve the problem by reverse
      communication, a sequence of calls are made under control of a status
      parameter, each exit either asks the user to provide additional
      informaton and to re-enter, or reports that either the solution has
      been found or that an error has occurred
  - \link gltr_information \endlink (optional) - recover information about
    the solution and solution process
  - \link gltr_terminate \endlink - deallocate data structures

  \latexonly
  See Section~\ref{examples} for an example of use.
  \endlatexonly
  \htmlonly
  See the <a href="examples.html">examples tab</a> for an illustration of use.
  \endhtmlonly
  \manonly
  See the examples section for an illustration of use.
  \endmanonly
 */

#ifdef __cplusplus
extern "C" {
#else
#include <stdbool.h>
#include <stdint.h>
#endif

// include guard
#ifndef GALAHAD_GLTR_H
#define GALAHAD_GLTR_H

// precision
#include "galahad_precision.h"
#include "galahad_cfunctions.h"

/**
 * control derived type as a C struct
 */
struct gltr_control_type {

    /// \brief
    /// use C or Fortran sparse matrix indexing
    bool f_indexing;

    /// \brief
    /// error and warning diagnostics occur on stream error
    ipc_ error;

    /// \brief
    /// general output occurs on stream out
    ipc_ out;

    /// \brief
    /// the level of output required is specified by print_level
    ipc_ print_level;

    /// \brief
    /// the maximum number of iterations allowed (-ve = no bound)
    ipc_ itmax;

    /// \brief
    /// the maximum number of iterations allowed once the boundary has been
    /// encountered (-ve = no bound)
    ipc_ Lanczos_itmax;

    /// \brief
    /// the number of extra work vectors of length n used
    ipc_ extra_vectors;

    /// \brief
    /// the unit number for writing debug Ritz values
    ipc_ ritz_printout_device;

    /// \brief
    /// the iteration stops successfully when the gradient in the M(inverse) nor
    /// is smaller than max( stop_relative * initial M(inverse)
    /// gradient norm, stop_absolute )
    real_wp_ stop_relative;
    /// see stop_relative
    real_wp_ stop_absolute;

    /// \brief
    /// an estimate of the solution that gives at least .fraction_opt times
    /// the optimal objective value will be found
    real_wp_ fraction_opt;

    /// \brief
    /// the iteration stops if the objective-function value is lower than f_min
    real_wp_ f_min;

    /// \brief
    /// the smallest value that the square of the M norm of the gradient of the
    /// the objective may be before it is considered to be zero
    real_wp_ rminvr_zero;

    /// \brief
    /// the constant term, \f$f_0\f$, in the objective function
    real_wp_ f_0;

    /// \brief
    /// is \f$M\f$ the identity matrix ?
    bool unitm;

    /// \brief
    /// should the iteration stop when the Trust-region is first encountered ?
    bool steihaug_toint;

    /// \brief
    /// is the solution thought to lie on the constraint boundary ?
    bool boundary;

    /// \brief
    /// is the solution required to lie on the constraint boundary ?
    bool equality_problem;

    /// \brief
    /// if .space_critical true, every effort will be made to use as little
    /// space as possible. This may result in longer computation time
    bool space_critical;

    /// \brief
    /// if .deallocate_error_fatal is true, any array/pointer deallocation error
    /// will terminate execution. Otherwise, computation will continue
    bool deallocate_error_fatal;

    /// \brief
    /// should the Ritz values be written to the debug stream?
    bool print_ritz_values;

    /// \brief
    /// name of debug file containing the Ritz values
    char ritz_file_name[31];

    /// \brief
    /// all output lines will be prefixed by .prefix(2:LEN(TRIM(.prefix))-1)
    /// where .prefix contains the required string enclosed in
    /// quotes, e.g. "string" or 'string'
    char prefix[31];
};

/**
 * inform derived type as a C struct
 */
struct gltr_inform_type {

    /// \brief
    /// return status. See \link gltr_solve_problem \endlink for details
    ipc_ status;

    /// \brief
    /// the status of the last attempted allocation/deallocation
    ipc_ alloc_status;

    /// \brief
    /// the name of the array for which an allocation/deallocation error
    /// occurred
    char bad_alloc[81];

    /// \brief
    /// the total number of iterations required
    ipc_ iter;

    /// \brief
    /// the total number of pass-2 iterations required if the solution lies on
    /// the trust-region boundary
    ipc_ iter_pass2;

    /// \brief
    /// the value of the quadratic function
    real_wp_ obj;

    /// \brief
    /// the Lagrange multiplier corresponding to the trust-region constraint
    real_wp_ multiplier;

    /// \brief
    /// the \f$M\f$-norm of \f$x\f$
    real_wp_ mnormx;

    /// \brief
    /// the latest pivot in the Cholesky factorization of the Lanczos tridiagona
    real_wp_ piv;

    /// \brief
    /// the most negative cuurvature encountered
    real_wp_ curv;

    /// \brief
    /// the current Rayleigh quotient
    real_wp_ rayleigh;

    /// \brief
    /// an estimate of the leftmost generalized eigenvalue of the pencil
    /// \f$(H,M)\f$
    real_wp_ leftmost;

    /// \brief
    /// was negative curvature encountered ?
    bool negative_curvature;

    /// \brief
    /// did the hard case occur ?
    bool hard_case;
};

// *-*-*-*-*-*-*-*-*-*-    G L T R  _ I N I T I A L I Z E    -*-*-*-*-*-*-*-*-*

void gltr_initialize( void **data,
                     struct gltr_control_type *control,
                     ipc_ *status );

/*!<
 Set default control values and initialize private data

  @param[in,out] data holds private internal data

  @param[out] control is a struct containing control information
              (see gltr_control_type)

  @param[out] status is a scalar variable of type int, that gives
    the exit status from the package. Possible values are (currently):  \li  0. The import was succesful.
*/

// *-*-*-*-*-*-*-*-*-    G L T R  _ R E A D _ S P E C F I L E   -*-*-*-*-*-*-*

void gltr_read_specfile( struct gltr_control_type *control,
                         const char specfile[] );

/*!<
  Read the content of a specification file, and assign values associated
  with given keywords to the corresponding control parameters.
  By default, the spcification file will be named RUNGLTR.SPC and
  lie in the current directory.
  Refer to Table 2.1 in the fortran documentation provided in
  $GALAHAD/doc/gltr.pdf for a list of keywords that may be set.

  @param[in,out]  control is a struct containing control information
              (see gltr_control_type)
  @param[in]  specfile is a character string containing the name of
              the specification file
*/

// *-*-*-*-*-*-*-*-*-    G L T R  _ I M P O R T _ C O N T R O L  -*-*-*-*-*-*-

void gltr_import_control( struct gltr_control_type *control,
                          void **data,
                          ipc_ *status );

/*!<
 Import control parameters prior to solution.

 @param[in] control is a struct whose members provide control
  paramters for the remaining prcedures (see gltr_control_type)

 @param[in,out] data holds private internal data

 @param[in,out] status is a scalar variable of type int, that gives
    the exit status from the package. Possible values are (currently):
  \li  1. The import was succesful, and the package is ready for the solve phase
*/

//  *-*-*-*-*-*-*-*-*-  G L T R _ S O L V E _ P R O B L E M   -*-*-*-*-*-*-*-*-

void gltr_solve_problem( void **data,
                        ipc_ *status,
                        ipc_ n,
                        const real_wp_ radius,
                        real_wp_ x[],
                        real_wp_ r[],
                        real_wp_ vector[] );

/*!<
 Solve the trust-region problem using reverse communication.

 @param[in,out] data holds private internal data

 @param[in,out] status is a scalar variable of type int, that gives
    the entry and exit status from the package. \n

   This must be set to
   \li  1. on initial entry. Set r (below) to \f$c\f$ for this entry.
   \li  4. the iteration is to be restarted with a smaller radius but
         with all other data unchanged. Set r (below) to \f$c\f$ for this entry.

   Possible exit values are:
   \li  0. the solution has been found
   \li  2. the inverse of \f$M\f$ must be applied to
         vector with the result returned in vector and the function
         re-entered with all other data unchanged.
         This will only happen if control.unitm is false
   \li  3. the product \f$H\f$ * vector must be formed, with
         the result returned in vector and the function re-entered
          with all other data unchanged
   \li  5. The iteration must be restarted. Reset r (below) to \f$c\f$ and
         re-enter with all other data unchanged.
         This exit will only occur if control.steihaug_toint is
         false and the solution lies on the trust-region boundary
   \li -1. an array allocation has failed
   \li -2. an array deallocation has failed
   \li -3. n and/or radius is not positive
   \li -15. the matrix \f$M\f$ appears to be indefinite
   \li -18. the iteration limit has been exceeded
   \li -30. the trust-region has been encountered in Steihaug-Toint mode
   \li -31. the function value is smaller than control.f_min

 @param[in] n is a scalar variable of type int, that holds the number of
    variables

 @param[in] radius is a scalar of type double, that holds the trust-region
    radius, \f$\Delta\f$, used. radius must be strictly positive

 @param[in,out] x is a one-dimensional array of size n and type double, that
    holds the solution \f$x\f$.
    The j-th component of x, j = 0, ... ,  n-1, contains  \f$x_j \f$.

 @param[in,out] r is a one-dimensional array of size n and type double, that
    that must be set to \f$c\f$ on entry (status = 1) and re-entry
!   (status = 4, 5). On exit, r contains the resiual \f$H x + c\f$.

 @param[in,out] vector is a one-dimensional array of size n and type double,
    that should be used and reset appropriately when status = 2 and 3
    as directed.

*/

// *-*-*-*-*-*-*-*-*-*-    G L T R  _ I N F O R M A T I O N   -*-*-*-*-*-*-*-*

void gltr_information( void **data,
                      struct gltr_inform_type *inform,
                      ipc_ *status );

/*!<
  Provides output information

  @param[in,out] data  holds private internal data

  @param[out] inform   is a struct containing output information
              (see gltr_inform_type)

  @param[out] status is a scalar variable of type int, that gives
              the exit status from the package.
              Possible values are (currently):
  \li  0. The values were recorded succesfully
*/

// *-*-*-*-*-*-*-*-*-*-    G L T R  _ T E R M I N A T E   -*-*-*-*-*-*-*-*-*-*

void gltr_terminate( void **data,
                    struct gltr_control_type *control,
                    struct gltr_inform_type *inform );

/*!<
  Deallocate all internal private storage

  @param[in,out] data  holds private internal data

  @param[out] control  is a struct containing control information
              (see gltr_control_type)

  @param[out] inform   is a struct containing output information
              (see gltr_inform_type)
 */

/** \anchor examples
   \f$\label{examples}\f$
   \example gltrt.c
   This is an example of how to use the package to solve a trust-region
   problem. The use of default and non-default scaling matrices, and restarts
   with a smaller trust-region radius are illustrated.
 */

// end include guard
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
