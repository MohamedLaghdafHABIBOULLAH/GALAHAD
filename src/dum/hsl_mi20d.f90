! THIS VERSION: GALAHAD 4.3 - 2024-01-25 AT 09:30 GMT.

#include "galahad_modules.h"

!-*-*-*-*-  G A L A H A D  -  D U M M Y   M I 2 0   M O D U L E  -*-*-*-

   module hsl_mi20_double

     USE GALAHAD_KINDS
     USE GALAHAD_SYMBOLS
     use hsl_zd11_double
     use hsl_mc65_double
     use hsl_ma48_double

     implicit none

     type mi20_control
       integer(ip_) :: aggressive = 1
       integer(ip_) :: c_fail = 1
       integer(ip_) :: max_levels = 100
       integer(ip_) :: max_points = 1
       real (kind=dp_) :: reduction = 0.8
       integer(ip_) :: st_method = 2
       real(kind=dp_) :: st_parameter = 0.25
       integer(ip_) :: testing = 1
       real (kind=dp_) :: trunc_parameter = 0.0
       integer(ip_) :: coarse_solver = 3
       integer(ip_) :: coarse_solver_its = 10
       real(kind=dp_) :: damping = 0.8
       real(kind=dp_) :: err_tol = 1.0e10
       integer(ip_) :: levels = -1
       integer(ip_) :: ma48 = 0
       integer(ip_) :: pre_smoothing = 2
       integer(ip_) :: smoother = 2
       integer(ip_) :: post_smoothing = 2
       integer(ip_) :: v_iterations = 1
       integer(ip_) :: print_level = 1
       integer(ip_) :: print = 6
       integer(ip_) :: error = 6
       logical(lp_) :: one_pass_coarsen = .false.
!      real(kind=dp_) ::  tol = -one
!      logical(lp_) ::  tol_relative = .true.
     end type mi20_control

     type mi20_info
       integer(ip_) :: flag = 0
       integer(ip_) :: clevels = 0
       integer(ip_) :: cpoints = 0
       integer(ip_) :: cnnz = 0
       integer(ip_) :: stat
       integer(ip_) :: getrf_info
       integer(ip_) :: iterations
       real(kind=dp_) :: residual
       type(ma48_ainfo):: ma48_ainfo
       type(ma48_finfo):: ma48_finfo
       type(ma48_sinfo):: ma48_sinfo
     end type mi20_info

     type mi20_keep
       logical(lp_) :: new_preconditioner = .true.
       integer(ip_) :: clevels = 0
       real(kind=dp_), dimension(:,:), allocatable :: lapack_factors
       integer(ip_),  dimension(:), allocatable :: lapack_pivots
       integer(ip_) :: st_method
       logical(lp_) :: lapack_data = .false.
       integer(ip_) :: ma48_data = 0
       type(ma48_factors) :: ma48_factors
       type(ma48_control) :: ma48_cntrl
       type(zd11_type) :: ma48_matrix
       logical(lp_) :: ma48_matrix_exists = .false.
       integer(ip_) :: dsolve_level = -1
       integer(ip_) :: max_its = 0
       logical(lp_) :: zd11_internal_conversion = .false.
       type( zd11_type ) :: A
     end type mi20_keep

     type mi20_data
       type(zd11_type) :: A_mat
       type(zd11_type) :: I_mat
     end type mi20_data

   contains

     subroutine mi20_setup(matrix, coarse_data, keep, control, info)
     type(zd11_type), intent(inout) :: matrix
     type(mi20_data), dimension(:), allocatable, intent(inout) :: coarse_data
     type(mi20_keep), intent(inout) :: keep
     type(mi20_control), intent(in) :: control
     type(mi20_info), intent(out) :: info
     info%flag = GALAHAD_unavailable_option
     return
     end subroutine mi20_setup

     subroutine mi20_finalize(coarse_data, keep, control, info, ma48_cntrl)
     type(mi20_data), allocatable, dimension(:), intent(inout) :: coarse_data
     type(mi20_keep), intent(inout) :: keep
     type(mi20_control), intent(in) ::control
     type(mi20_info), intent(inout) :: info
     type(ma48_control), optional, intent(inout) :: ma48_cntrl
     info%flag = GALAHAD_unavailable_option
     return
     end subroutine mi20_finalize

   end module hsl_mi20_double
