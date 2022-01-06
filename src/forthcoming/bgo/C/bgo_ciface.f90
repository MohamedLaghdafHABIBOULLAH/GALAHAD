! THIS VERSION: GALAHAD 4.0 - 2022-01-06 AT 09:00 GMT.

!-*-*-*-*-*-*-*-*-  G A L A H A D _ B G O   C   I N T E R F A C E  -*-*-*-*-*-*-

!  Copyright reserved, Gould/Orban/Toint, for GALAHAD productions
!  Principal authors: Jaroslav Fowkes & Nick Gould

!  History -
!    originally released GALAHAD Version 3.3. August 3rd 2021

!  For full documentation, see
!   http://galahad.rl.ac.uk/galahad-www/specs.html

  MODULE GALAHAD_BGO_double_ciface
    USE iso_c_binding
    USE GALAHAD_common_ciface
    USE GALAHAD_BGO_double, ONLY:                                              &
        f_bgo_time_type                 => BGO_time_type,                      &
        f_bgo_inform_type               => BGO_inform_type,                    &
        f_bgo_control_type              => BGO_control_type,                   &
        f_bgo_full_data_type            => BGO_full_data_type,                 &
        f_bgo_initialize                => BGO_initialize,                     &
        f_bgo_read_specfile             => BGO_read_specfile,                  &
        f_bgo_import                    => BGO_import,                         &
        f_bgo_reset_control             => BGO_reset_control,                  &
        f_bgo_solve_with_mat            => BGO_solve_with_mat,                 &
        f_bgo_solve_without_mat         => BGO_solve_without_mat,              &
        f_bgo_solve_reverse_with_mat    => BGO_solve_reverse_with_mat,         &
        f_bgo_solve_reverse_without_mat => BGO_solve_reverse_without_mat,      &
        f_bgo_information               => BGO_information,                    &
        f_bgo_terminate                 => BGO_terminate

    USE GALAHAD_NLPT_double, ONLY:                                             &
        f_nlpt_userdata_type          => NLPT_userdata_type

    USE GALAHAD_TRB_double_ciface, ONLY:                                       &
        trb_inform_type,                                                       &
        trb_control_type,                                                      &
        copy_trb_inform_in            => copy_inform_in,                       &
        copy_trb_inform_out           => copy_inform_out,                      &
        copy_trb_control_in           => copy_control_in,                      &
        copy_trb_control_out          => copy_control_out

    USE GALAHAD_UGO_double_ciface, ONLY:                                       &
        ugo_inform_type,                                                       &
        ugo_control_type,                                                      &
        copy_ugo_inform_in            => copy_inform_in,                       &
        copy_ugo_inform_out           => copy_inform_out,                      &
        copy_ugo_control_in           => copy_control_in,                      &
        copy_ugo_control_out          => copy_control_out
    USE GALAHAD_LHS_double_ciface, ONLY:                                       &
        lhs_inform_type,                                                       &
        lhs_control_type,                                                      &
        copy_lhs_inform_in            => copy_inform_in,                       &
        copy_lhs_inform_out           => copy_inform_out,                      &
        copy_lhs_control_in           => copy_control_in,                      &
        copy_lhs_control_out          => copy_control_out

    IMPLICIT NONE

!--------------------
!   P r e c i s i o n
!--------------------

    INTEGER, PARAMETER :: wp = C_DOUBLE ! double precision
    INTEGER, PARAMETER :: sp = C_FLOAT  ! single precision

!-------------------------------------------------
!  D e r i v e d   t y p e   d e f i n i t i o n s
!-------------------------------------------------

    TYPE, BIND( C ) :: bgo_control_type
      LOGICAL ( KIND = C_BOOL ) :: f_indexing
      INTEGER ( KIND = C_INT ) :: error
      INTEGER ( KIND = C_INT ) :: out
      INTEGER ( KIND = C_INT ) :: print_level
      INTEGER ( KIND = C_INT ) :: attempts_max
      INTEGER ( KIND = C_INT ) :: max_evals
      INTEGER ( KIND = C_INT ) :: sampling_strategy
      INTEGER ( KIND = C_INT ) :: hypercube_discretization
      INTEGER ( KIND = C_INT ) :: alive_unit 
      CHARACTER ( KIND = C_CHAR ), DIMENSION( 31 ) :: alive_file
      REAL ( KIND = wp ) :: infinity
      REAL ( KIND = wp ) :: obj_unbounded
      REAL ( KIND = wp ) :: cpu_time_limit 
      REAL ( KIND = wp ) :: clock_time_limit 
      LOGICAL ( KIND = C_BOOL ) :: random_multistart
      LOGICAL ( KIND = C_BOOL ) :: hessian_available
      LOGICAL ( KIND = C_BOOL ) :: space_critical
      LOGICAL ( KIND = C_BOOL ) :: deallocate_error_fatal
      CHARACTER ( KIND = C_CHAR ), DIMENSION( 31 ) :: prefix 
      TYPE ( trb_control_type ) :: trb_control
      TYPE ( ugo_control_type ) :: ugo_control
      TYPE ( lhs_control_type ) :: lhs_control
    END type bgo_control_type

    TYPE, BIND( C ) :: bgo_time_type
      REAL ( KIND = sp ) :: total
      REAL ( KIND = sp ) :: univariate_global
      REAL ( KIND = sp ) :: multivariate_local
      REAL ( KIND = wp ) :: clock_total
      REAL ( KIND = wp ) :: clock_univariate_global
      REAL ( KIND = wp ) :: clock_multivariate_local
    END TYPE bgo_time_type

    TYPE, BIND( C ) :: bgo_inform_type
      INTEGER ( KIND = C_INT ) :: status
      INTEGER ( KIND = C_INT ) :: alloc_status
      CHARACTER ( KIND = C_CHAR ), DIMENSION( 81 ) :: bad_alloc
      INTEGER ( KIND = C_INT ) :: f_eval
      INTEGER ( KIND = C_INT ) :: g_eval
      INTEGER ( KIND = C_INT ) :: h_eval
      REAL ( KIND = wp ) :: obj
      REAL ( KIND = wp ) :: norm_pg
      TYPE ( bgo_time_type ) :: time
      TYPE ( trb_inform_type ) :: trb_inform
      TYPE ( ugo_inform_type ) :: ugo_inform
      TYPE ( lhs_inform_type ) :: lhs_inform
    END TYPE bgo_inform_type

!----------------------
!   I n t e r f a c e s
!----------------------

    ABSTRACT INTERFACE
      FUNCTION eval_f( n, x, f, userdata ) RESULT( status ) BIND( C )
        USE iso_c_binding
        IMPORT :: wp
        INTEGER ( KIND = C_INT ), INTENT( IN ), value :: n
        REAL ( KIND = wp ), DIMENSION( n ), INTENT( IN ) :: x
        REAL ( KIND = wp ), INTENT( OUT ) :: f
        TYPE ( C_PTR ), INTENT( IN ), VALUE :: userdata
        INTEGER ( KIND = C_INT ) :: status
      END FUNCTION eval_f
    END INTERFACE

    ABSTRACT INTERFACE
      FUNCTION eval_g( n, x, g, userdata ) RESULT( status ) BIND( C )
        USE iso_c_binding
        IMPORT :: wp
        INTEGER ( KIND = C_INT ), INTENT( IN ), VALUE :: n
        REAL ( KIND = wp ), DIMENSION( n ), INTENT( IN ) :: x
        REAL ( KIND = wp ), DIMENSION( n ), INTENT( OUT ) :: g
        TYPE ( C_PTR ), INTENT( IN ), VALUE :: userdata
        INTEGER ( KIND = C_INT ) :: status
      END FUNCTION eval_g
    END INTERFACE

    ABSTRACT INTERFACE
      FUNCTION eval_h( n, ne, x, hval, userdata ) RESULT( status ) BIND( C )
        USE iso_c_binding
        IMPORT :: wp
        INTEGER ( KIND = C_INT ), INTENT( IN ), VALUE :: n
        INTEGER ( KIND = C_INT ), INTENT( IN ), VALUE :: ne
        REAL ( KIND = wp ), DIMENSION( n ), INTENT( IN ) :: x
        REAL ( KIND = wp ), DIMENSION( ne ), INTENT( OUT ) :: hval
        TYPE ( C_PTR ), INTENT( IN ), VALUE :: userdata
        INTEGER ( KIND = C_INT ) :: status
      END FUNCTION eval_h
    END INTERFACE

    ABSTRACT INTERFACE
      FUNCTION eval_hprod( n, x, u, v, got_h, userdata ) RESULT( status )      &
                                                         BIND( C )
        USE iso_c_binding
        IMPORT :: wp
        INTEGER ( KIND = C_INT ), INTENT( IN ), VALUE :: n
        REAL ( KIND = wp ), DIMENSION( n ), INTENT( IN ) :: x
        REAL ( KIND = wp ), DIMENSION( n ), INTENT( INOUT ) :: u
        REAL ( KIND = wp ), DIMENSION( n ), INTENT( IN ) :: v
        LOGICAL ( KIND = C_BOOL ), INTENT( IN ), VALUE :: got_h
        TYPE ( C_PTR ), INTENT( IN ), VALUE :: userdata
        INTEGER ( KIND = C_INT ) :: status
      END FUNCTION eval_hprod
    END INTERFACE

    ABSTRACT INTERFACE
      FUNCTION eval_shprod( n, x, nnz_v, index_nz_v, v, nnz_u, index_nz_u,     &
                            u, got_h, userdata ) RESULT( status ) BIND( C )
        USE iso_c_binding
        IMPORT :: wp
        INTEGER ( KIND = C_INT ), INTENT( IN ), VALUE :: n
        REAL ( KIND = wp ), DIMENSION( n ), INTENT( IN ) :: x
        INTEGER ( KIND = C_INT ), INTENT( IN ), VALUE :: nnz_v
        INTEGER ( KIND = C_INT ), DIMENSION( n ), INTENT( IN ) :: index_nz_v
        REAL ( KIND = wp ), DIMENSION( n ), INTENT( IN ) :: v
        INTEGER ( KIND = C_INT ), INTENT( OUT ) :: nnz_u 
        INTEGER ( KIND = C_INT ), DIMENSION( n ), INTENT( OUT ) :: index_nz_u
        REAL ( KIND = wp ), DIMENSION( n ), INTENT( OUT ) :: u
        LOGICAL( KIND = C_BOOL ), INTENT( IN ), VALUE :: got_h
        TYPE (C_PTR), INTENT( IN ), VALUE :: userdata
        INTEGER ( KIND = C_INT ) :: status
      END FUNCTION eval_shprod
    END INTERFACE

    ABSTRACT INTERFACE
      FUNCTION eval_prec( n, x, u, v, userdata ) RESULT( status ) BIND( C )
        USE iso_c_binding
        IMPORT :: wp
        INTEGER ( KIND = C_INT ), INTENT( IN ), VALUE :: n
        REAL ( KIND = wp ), DIMENSION( n ), INTENT( IN ) :: x
        REAL ( KIND = wp ), DIMENSION( n ), INTENT( OUT ) :: u
        REAL ( KIND = wp ), DIMENSION( n ), INTENT( IN ) :: v
        TYPE ( C_PTR ), INTENT( IN ), VALUE :: userdata
        INTEGER ( KIND = C_INT ) :: status
      END FUNCTION eval_prec
    END INTERFACE

!----------------------
!   P r o c e d u r e s
!----------------------

  CONTAINS

!  copy C control parameters to fortran

    SUBROUTINE copy_control_in(ccontrol, fcontrol, f_indexing) 
    TYPE ( bgo_control_type ), INTENT( IN ) :: ccontrol
    TYPE ( f_bgo_control_type ), INTENT( OUT ) :: fcontrol
    LOGICAL, optional, INTENT( OUT ) :: f_indexing
    INTEGER :: i
    
    ! C or Fortran sparse matrix indexing
    IF ( PRESENT( f_indexing ) )  f_indexing = ccontrol%f_indexing

    ! Integers
    fcontrol%error = ccontrol%error
    fcontrol%out = ccontrol%out
    fcontrol%print_level = ccontrol%print_level
    fcontrol%attempts_max = ccontrol%attempts_max
    fcontrol%max_evals = ccontrol%max_evals
    fcontrol%sampling_strategy = ccontrol%sampling_strategy
    fcontrol%hypercube_discretization = ccontrol%hypercube_discretization
    fcontrol%alive_unit = ccontrol%alive_unit

    ! Reals
    fcontrol%infinity = ccontrol%infinity
    fcontrol%obj_unbounded = ccontrol%obj_unbounded
    fcontrol%cpu_time_limit = ccontrol%cpu_time_limit
    fcontrol%clock_time_limit = ccontrol%clock_time_limit 

    ! Logicals
    fcontrol%random_multistart = ccontrol%random_multistart
    fcontrol%hessian_available = ccontrol%hessian_available
    fcontrol%space_critical = ccontrol%space_critical
    fcontrol%deallocate_error_fatal = ccontrol%deallocate_error_fatal

    ! Derived types
    CALL copy_trb_control_in(ccontrol%trb_control,fcontrol%trb_control)
    CALL copy_ugo_control_in(ccontrol%ugo_control,fcontrol%ugo_control)
    CALL copy_lhs_control_in(ccontrol%lhs_control,fcontrol%lhs_control)

    ! Strings
    DO i = 1, LEN( fcontrol%alive_file )
      IF ( ccontrol%alive_file( i ) == C_NULL_CHAR) EXIT
      fcontrol%alive_file( i : i ) = ccontrol%alive_file( i )
    END DO
    DO i = 1, LEN( fcontrol%prefix )
      IF ( ccontrol%prefix( i ) == C_NULL_CHAR) EXIT
      fcontrol%prefix( i : i ) = ccontrol%prefix( i )
    END DO
    RETURN

    END SUBROUTINE copy_control_in

!  copy fortran control parameters to C

    SUBROUTINE copy_control_out( fcontrol, ccontrol, f_indexing )
    TYPE ( f_bgo_control_type ), INTENT( IN ) :: fcontrol
    TYPE ( bgo_control_type ), INTENT( OUT ) :: ccontrol
    LOGICAL, optional, INTENT( IN ) :: f_indexing
    INTEGER :: i, l
    
    ! C or Fortran sparse matrix indexing
    IF ( PRESENT( f_indexing ) ) ccontrol%f_indexing = f_indexing

    ! Integers
    ccontrol%error = fcontrol%error
    ccontrol%out = fcontrol%out
    ccontrol%print_level = fcontrol%print_level
    ccontrol%attempts_max = fcontrol%attempts_max
    ccontrol%max_evals = fcontrol%max_evals
    ccontrol%sampling_strategy = fcontrol%sampling_strategy
    ccontrol%hypercube_discretization = fcontrol%hypercube_discretization
    ccontrol%alive_unit = fcontrol%alive_unit

    ! Reals
    ccontrol%infinity = fcontrol%infinity
    ccontrol%obj_unbounded = fcontrol%obj_unbounded
    ccontrol%cpu_time_limit = fcontrol%cpu_time_limit
    ccontrol%clock_time_limit = fcontrol%clock_time_limit 

    ! Logicals
    ccontrol%random_multistart = fcontrol%random_multistart
    ccontrol%hessian_available = fcontrol%hessian_available
    ccontrol%space_critical = fcontrol%space_critical
    ccontrol%deallocate_error_fatal = fcontrol%deallocate_error_fatal

    ! Derived types
    CALL copy_trb_control_out( fcontrol%trb_control, ccontrol%trb_control )
    CALL copy_ugo_control_out( fcontrol%ugo_control, ccontrol%ugo_control )
    CALL copy_lhs_control_out( fcontrol%lhs_control, ccontrol%lhs_control )

    ! Strings
    l = LEN( fcontrol%alive_file )
    DO i = 1, l
      ccontrol%alive_file( i ) = fcontrol%alive_file( i : i )
    END DO
    ccontrol%alive_file( l + 1 ) = C_NULL_CHAR
    l = LEN( fcontrol%prefix )
    DO i = 1, l
      ccontrol%prefix(i) = fcontrol%prefix( i : i )
    END DO
    ccontrol%prefix( l + 1 ) = C_NULL_CHAR
    RETURN

    END SUBROUTINE copy_control_out

!  copy C times to fortran

    SUBROUTINE copy_time_in(ctime, ftime) 
    TYPE ( bgo_time_type ), INTENT( IN ) :: ctime
    TYPE ( f_bgo_time_type ), INTENT( OUT ) :: ftime

    ftime%total = ctime%total
    ftime%univariate_global = ctime%univariate_global
    ftime%multivariate_local = ctime%multivariate_local
    ftime%clock_total = ctime%clock_total
    ftime%clock_univariate_global = ctime%clock_univariate_global
    ftime%clock_multivariate_local = ctime%clock_multivariate_local
    RETURN

    END SUBROUTINE copy_time_in

!  copy fortran times to C

    SUBROUTINE copy_time_out(ftime, ctime)
    TYPE ( f_bgo_time_type ), INTENT( IN ) :: ftime
    TYPE ( bgo_time_type ), INTENT( OUT ) :: ctime

    ctime%total = ftime%total
    ctime%univariate_global = ftime%univariate_global
    ctime%multivariate_local = ftime%multivariate_local
    ctime%clock_total = ftime%clock_total
    ctime%clock_univariate_global = ftime%clock_univariate_global
    ctime%clock_multivariate_local = ftime%clock_multivariate_local
    RETURN

    END SUBROUTINE copy_time_out

!  copy C information parameters to fortran

    SUBROUTINE copy_inform_in(cinform, finform) 
    TYPE ( bgo_inform_type ), INTENT( IN ) :: cinform
    TYPE ( f_bgo_inform_type ), INTENT( OUT ) :: finform
    INTEGER :: i

    ! Integers
    finform%status = cinform%status
    finform%alloc_status = cinform%alloc_status
    finform%f_eval = cinform%f_eval
    finform%g_eval = cinform%g_eval
    finform%h_eval = cinform%h_eval

    ! Reals
    finform%obj = cinform%obj
    finform%norm_pg = cinform%norm_pg

    ! Derived types
    CALL copy_time_in( cinform%time, finform%time )
    CALL copy_trb_inform_in( cinform%trb_inform, finform%trb_inform )
    CALL copy_ugo_inform_in( cinform%ugo_inform, finform%ugo_inform )
    CALL copy_lhs_inform_in( cinform%lhs_inform, finform%lhs_inform )

    ! Strings
    DO i = 1, LEN( finform%bad_alloc )
      IF ( cinform%bad_alloc( i ) == C_NULL_CHAR ) EXIT
      finform%bad_alloc( i : i ) = cinform%bad_alloc( i )
    END DO
    RETURN

    END SUBROUTINE copy_inform_in

!  copy fortran information parameters to C

    SUBROUTINE copy_inform_out( finform, cinform )
    TYPE ( f_bgo_inform_type ), INTENT( IN ) :: finform 
    TYPE ( bgo_inform_type ), INTENT( OUT ) :: cinform
    INTEGER :: i, l

    ! Integers
    cinform%status = finform%status
    cinform%alloc_status = finform%alloc_status
    cinform%f_eval = finform%f_eval
    cinform%g_eval = finform%g_eval
    cinform%h_eval = finform%h_eval

    ! Reals
    cinform%obj = finform%obj
    cinform%norm_pg = finform%norm_pg

    ! Derived types
    CALL copy_time_out( finform%time, cinform%time )
    CALL copy_trb_inform_out( finform%trb_inform, cinform%trb_inform )
    CALL copy_ugo_inform_out( finform%ugo_inform, cinform%ugo_inform )
    CALL copy_lhs_inform_out( finform%lhs_inform, cinform%lhs_inform )

    ! Strings
    l = LEN( finform%bad_alloc )
    DO i = 1, l
      cinform%bad_alloc( i ) = finform%bad_alloc( i : i )
    END DO
    cinform%bad_alloc( l + 1 ) = C_NULL_CHAR
    RETURN

    END SUBROUTINE copy_inform_out

  END MODULE GALAHAD_BGO_double_ciface

!  -------------------------------------
!  C interface to fortran bgo_initialize
!  -------------------------------------

  SUBROUTINE bgo_initialize( cdata, ccontrol, status ) BIND( C ) 
  USE GALAHAD_BGO_double_ciface
  IMPLICIT NONE

!  dummy arguments

  INTEGER ( KIND = C_INT ), INTENT( OUT ) :: status
  TYPE ( C_PTR ), INTENT( OUT ) :: cdata ! data is a black-box
  TYPE ( bgo_control_type ), INTENT( OUT ) :: ccontrol

!  local variables

  TYPE ( f_bgo_full_data_type ), POINTER :: fdata
  TYPE ( f_bgo_control_type ) :: fcontrol
  TYPE ( f_bgo_inform_type ) :: finform
  LOGICAL :: f_indexing 

!  allocate fdata

  ALLOCATE( fdata ); cdata = C_LOC( fdata )

!  initialize required fortran types

  CALL f_bgo_initialize( fdata, fcontrol, finform )
  status = finform%status

!  C sparse matrix indexing by default

  f_indexing = .FALSE.
  fdata%f_indexing = f_indexing

!  copy control out 

write(6,*) ' before copy'
  CALL copy_control_out( fcontrol, ccontrol, f_indexing )
write(6,*) ' after copy'
  RETURN

  END SUBROUTINE bgo_initialize

!  ----------------------------------------
!  C interface to fortran bgo_read_specfile
!  ----------------------------------------

  SUBROUTINE bgo_read_specfile( ccontrol, cspecfile ) BIND( C )
  USE GALAHAD_BGO_double_ciface
  IMPLICIT NONE

!  dummy arguments

  TYPE ( bgo_control_type ), INTENT( INOUT ) :: ccontrol
  TYPE ( C_PTR ), INTENT( IN ), VALUE :: cspecfile

!  local variables

  TYPE ( f_bgo_control_type ) :: fcontrol
  CHARACTER ( KIND = C_CHAR, LEN = strlen( cspecfile ) ) :: fspecfile
  LOGICAL :: f_indexing

!  device unit number for specfile

  INTEGER ( KIND = C_INT ), PARAMETER :: device = 10

!  convert C string to Fortran string

  fspecfile = cstr_to_fchar( cspecfile )

!  copy control in

  CALL copy_control_in( ccontrol, fcontrol, f_indexing )
  
!  open specfile for reading

  open( UNIT = device, FILE = fspecfile )
  
!  read control parameters from the specfile

  CALL f_bgo_read_specfile( fcontrol, device )

!  close specfile

  close( device )

!  copy control out

  CALL copy_control_out( fcontrol, ccontrol, f_indexing )
  RETURN

  END SUBROUTINE bgo_read_specfile

!  ---------------------------------
!  C interface to fortran bgo_inport
!  ---------------------------------

  SUBROUTINE bgo_import( ccontrol, cdata, status, n, xl, xu, ctype,            &
                         ne, row, col, ptr ) BIND( C )
  USE GALAHAD_BGO_double_ciface
  IMPLICIT NONE

!  dummy arguments

  INTEGER ( KIND = C_INT ), INTENT( IN ), VALUE :: n, ne
  INTEGER ( KIND = C_INT ), INTENT( OUT ) :: status
  INTEGER ( KIND = C_INT ), INTENT( IN ), DIMENSION( ne ), optional :: row, col
  INTEGER ( KIND = C_INT ), INTENT( IN ), DIMENSION( n + 1 ), optional :: ptr
  REAL ( KIND = wp ), INTENT( IN ), DIMENSION( n ) :: xl, xu
  TYPE ( C_PTR ), INTENT( IN ), VALUE :: ctype
  TYPE ( bgo_control_type ), INTENT( INOUT ) :: ccontrol
  TYPE ( C_PTR ), INTENT( INOUT ) :: cdata

!  local variables

  CHARACTER ( KIND = C_CHAR, LEN = opt_strlen( ctype ) ) :: ftype
  TYPE ( f_bgo_control_type ) :: fcontrol
  TYPE ( f_bgo_full_data_type ), POINTER :: fdata
  INTEGER, DIMENSION( : ), ALLOCATABLE :: row_find, col_find, ptr_find
  LOGICAL :: f_indexing

!  copy control and inform in

  CALL copy_control_in( ccontrol, fcontrol, f_indexing )

!  associate data pointer

  CALL C_F_POINTER( cdata, fdata )

!  convert C string to Fortran string

  ftype = cstr_to_fchar( ctype )

!  is fortran-style 1-based indexing used?

  fdata%f_indexing = f_indexing

!  handle C sparse matrix indexing

  IF ( .NOT. f_indexing ) THEN
    IF ( PRESENT( row ) ) THEN
      ALLOCATE( row_find( ne ) )
      row_find = row + 1
    END IF
    IF ( PRESENT( col ) ) THEN
      ALLOCATE( col_find(ne ) )
      col_find = col + 1
    END IF
    IF ( PRESENT( ptr ) ) THEN
      ALLOCATE( ptr_find( n + 1 ) )
      ptr_find = ptr + 1
    END IF

!  import the problem data into the required BGO structure

    CALL f_bgo_import( fcontrol, fdata, status, n, xl, xu, ftype, ne,          &
                       row_find, col_find, ptr_find )
    IF ( ALLOCATED( row_find ) ) DEALLOCATE( row_find )
    IF ( ALLOCATED( col_find ) ) DEALLOCATE( col_find )
    IF ( ALLOCATED( ptr_find ) ) DEALLOCATE( ptr_find )
  ELSE
    CALL f_bgo_import( fcontrol, fdata, status, n, xl, xu, ftype, ne,          &
                       row, col, ptr )
  END IF

!  copy control out

  CALL copy_control_out( fcontrol, ccontrol, f_indexing )
  RETURN

  END SUBROUTINE bgo_import

!  ----------------------------------------
!  C interface to fortran bgo_reset_control
!  ----------------------------------------

  SUBROUTINE bgo_reset_control( ccontrol, cdata, status ) BIND( C )
  USE GALAHAD_BGO_double_ciface
  IMPLICIT NONE

!  dummy arguments

  INTEGER ( KIND = C_INT ), INTENT( OUT ) :: status
  TYPE ( bgo_control_type ), INTENT( INOUT ) :: ccontrol
  TYPE ( C_PTR ), INTENT( INOUT ) :: cdata

!  local variables

  TYPE ( f_bgo_control_type ) :: fcontrol
  TYPE ( f_bgo_full_data_type ), POINTER :: fdata
  LOGICAL :: f_indexing

!  copy control in

  CALL copy_control_in( ccontrol, fcontrol, f_indexing )

!  associate data pointer

  CALL C_F_POINTER( cdata, fdata )

!  is fortran-style 1-based indexing used?

  fdata%f_indexing = f_indexing

!  import the control parameters into the required structure

  CALL f_bgo_reset_control( fcontrol, fdata, status )
  RETURN

  END SUBROUTINE bgo_reset_control

!  -----------------------------------------
!  C interface to fortran bgo_solve_with_mat
!  -----------------------------------------

  SUBROUTINE bgo_solve_with_mat( cdata, cuserdata, status, n, x, g, ne,        &
                                 ceval_f, ceval_g, ceval_h, ceval_hprod,       &
                                 ceval_prec ) BIND( C )
  USE GALAHAD_BGO_double_ciface
  IMPLICIT NONE

!  dummy arguments

  INTEGER ( KIND = C_INT ), INTENT( INOUT ) :: status
  INTEGER ( KIND = C_INT ), INTENT( IN ), VALUE :: n, ne
  REAL ( KIND = wp ), INTENT( INOUT ), DIMENSION( n ) :: x, g 
  TYPE ( C_PTR ), INTENT( INOUT ) :: cdata
  TYPE ( C_PTR ), INTENT( IN ), VALUE :: cuserdata
  TYPE ( C_FUNPTR ), INTENT( IN ), VALUE :: ceval_f, ceval_g
  TYPE ( C_FUNPTR ), INTENT( IN ), VALUE :: ceval_h, ceval_hprod, ceval_prec

!  local variables

  TYPE ( f_bgo_full_data_type ), POINTER :: fdata
  PROCEDURE( eval_f ), POINTER :: feval_f
  PROCEDURE( eval_g ), POINTER :: feval_g
  PROCEDURE( eval_h ), POINTER :: feval_h
  PROCEDURE( eval_hprod ), POINTER :: feval_hprod
  PROCEDURE( eval_prec ), POINTER :: feval_prec

!  ignore Fortran userdata type (not interoperable)

! TYPE ( f_nlpt_userdata_type ), POINTER :: fuserdata => NULL( )
  TYPE ( f_nlpt_userdata_type ) :: fuserdata

!  associate data pointer

  CALL C_F_POINTER( cdata, fdata )

!  associate procedure pointers

  CALL C_F_PROCPOINTER( ceval_f, feval_f )
  CALL C_F_PROCPOINTER( ceval_g, feval_g )
  CALL C_F_PROCPOINTER( ceval_h, feval_h )
  CALL C_F_PROCPOINTER( ceval_hprod, feval_hprod )
  IF ( C_ASSOCIATED( ceval_prec ) ) THEN 
    CALL C_F_PROCPOINTER( ceval_prec, feval_prec )
  ELSE
    NULLIFY( feval_prec )
  END IF

!  solve the problem when the Hessian is explicitly available

  CALL f_bgo_solve_with_mat( fdata, fuserdata, status, x, g, wrap_eval_f,      &
                              wrap_eval_g, wrap_eval_h, wrap_eval_hprod,       &
                              wrap_eval_prec )

  RETURN

!  wrappers

  CONTAINS

!  eval_F wrapper

    SUBROUTINE wrap_eval_f( status, x, userdata, f )
    INTEGER ( KIND = C_INT ), INTENT( OUT ) :: status
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( IN ) :: x
    TYPE ( f_nlpt_userdata_type ), INTENT( INOUT ) :: userdata
    REAL ( KIND = wp ), INTENT( OUT ) :: f

!  call C interoperable eval_f

    status = feval_f( n, x, f, cuserdata )
    RETURN

    END SUBROUTINE wrap_eval_f

!  eval_G wrapper

    SUBROUTINE wrap_eval_g( status, x, userdata, g )
    INTEGER ( KIND = C_INT ), INTENT( OUT ) :: status
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( IN ) :: x
    TYPE ( f_nlpt_userdata_type ), INTENT( INOUT ) :: userdata
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( OUT ) :: g

!  Call C interoperable eval_g
    status = feval_g( n, x, g, cuserdata )
    RETURN

    END SUBROUTINE wrap_eval_g

!  eval_H wrapper

    SUBROUTINE wrap_eval_h( status, x, userdata, hval )
    INTEGER ( KIND = C_INT ), INTENT( OUT ) :: status
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( IN ) :: x
    TYPE ( f_nlpt_userdata_type ), INTENT( INOUT ) :: userdata
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( OUT ) :: hval

!  Call C interoperable eval_h
    status = feval_h( n, ne, x, hval, cuserdata )
    RETURN

    END SUBROUTINE wrap_eval_h

! eval_HPROD wrapper    

    SUBROUTINE wrap_eval_hprod( status, x, userdata, u, v, fgot_h )
    INTEGER ( KIND = C_INT ), INTENT( OUT ) :: status
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( IN ) :: x
    TYPE ( f_nlpt_userdata_type ), INTENT( INOUT ) :: userdata
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( INOUT ) :: u
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( IN ) :: v
    LOGICAL, OPTIONAL, INTENT( IN ) :: fgot_h
    LOGICAL ( KIND = C_BOOL ) :: cgot_h

! Call C interoperable eval_hprod
    IF ( PRESENT( fgot_h ) ) THEN
      cgot_h = fgot_h
    ELSE
      cgot_h = .FALSE.
    END IF
    status = feval_hprod( n, x, u, v, cgot_h, cuserdata )
    RETURN

    END SUBROUTINE wrap_eval_hprod

!  eval_PREC wrapper

    SUBROUTINE wrap_eval_prec( status, x, userdata, u, v )
    INTEGER ( KIND = C_INT ), INTENT( OUT ) :: status
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( IN ) :: x
    TYPE ( f_nlpt_userdata_type ), INTENT( INOUT ) :: userdata
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( OUT ) :: u
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( IN ) :: v

!  call C interoperable eval_prec

    status = feval_prec( n, x, u, v, cuserdata )
    RETURN

    END SUBROUTINE wrap_eval_prec

  END SUBROUTINE bgo_solve_with_mat

!  --------------------------------------------
!  C interface to fortran bgo_solve_without_mat
!  --------------------------------------------

  SUBROUTINE bgo_solve_without_mat( cdata, cuserdata, status, n, x, g,         &
                                    ceval_f, ceval_g, ceval_hprod,             &
                                    ceval_shprod, ceval_prec ) BIND( C )
  USE GALAHAD_BGO_double_ciface
  IMPLICIT NONE

!  dummy arguments

  INTEGER ( KIND = C_INT ), INTENT( INOUT ) :: status
  INTEGER ( KIND = C_INT ), INTENT( IN ), VALUE :: n
  REAL ( KIND = wp ), INTENT( INOUT ), DIMENSION( n ) :: x, g 
  TYPE ( C_PTR ), INTENT( INOUT ) :: cdata
  TYPE ( C_PTR ), INTENT( IN ), VALUE :: cuserdata
  TYPE ( C_FUNPTR ), INTENT( IN ), VALUE :: ceval_f, ceval_g
  TYPE ( C_FUNPTR ), INTENT( IN ), VALUE :: ceval_hprod, ceval_shprod
  TYPE ( C_FUNPTR ), INTENT( IN ), VALUE :: ceval_prec

!  local variables

  TYPE ( f_bgo_full_data_type ), POINTER :: fdata
  PROCEDURE( eval_f ), POINTER :: feval_f
  PROCEDURE( eval_g ), POINTER :: feval_g
  PROCEDURE( eval_hprod ), POINTER :: feval_hprod
  PROCEDURE( eval_shprod ), POINTER :: feval_shprod
  PROCEDURE( eval_prec ), POINTER :: feval_prec
  LOGICAL :: f_indexing

!  ignore Fortran userdata type (not interoperable)

! TYPE ( f_nlpt_userdata_type ), POINTER :: fuserdata => NULL( )
  TYPE ( f_nlpt_userdata_type ) :: fuserdata

!  associate data pointer

  CALL C_F_POINTER( cdata, fdata )

!  is fortran-style 1-based indexing used?

  f_indexing = fdata%f_indexing

!  associate procedure pointers

  CALL C_F_PROCPOINTER( ceval_f, feval_f ) 
  CALL C_F_PROCPOINTER( ceval_g, feval_g )
  CALL C_F_PROCPOINTER( ceval_hprod, feval_hprod )
  CALL C_F_PROCPOINTER( ceval_shprod, feval_shprod )
  IF ( C_ASSOCIATED( ceval_prec ) ) THEN 
    CALL C_F_PROCPOINTER( ceval_prec, feval_prec )
  ELSE
    NULLIFY( feval_prec )
  END IF

!  solve the problem when the Hessian is only available via products

  CALL f_bgo_solve_without_mat( fdata, fuserdata, status, x, g, wrap_eval_f,   &
                                wrap_eval_g, wrap_eval_hprod,                  &
                                wrap_eval_shprod, wrap_eval_prec )

  RETURN

!  wrappers

  CONTAINS

!  eval_F wrapper

    SUBROUTINE wrap_eval_f( status, x, userdata, f )
    INTEGER ( KIND = C_INT ), INTENT( OUT ) :: status
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( IN ) :: x
    TYPE ( f_nlpt_userdata_type ), INTENT( INOUT ) :: userdata
    REAL ( KIND = wp ), INTENT( OUT ) :: f

!  call C interoperable eval_f

    status = feval_f( n, x, f, cuserdata )
    RETURN

    END SUBROUTINE wrap_eval_f

!  eval_G wrapper

    SUBROUTINE wrap_eval_g( status, x, userdata, g )
    INTEGER ( KIND = C_INT ), INTENT( OUT ) :: status
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( IN ) :: x
    TYPE ( f_nlpt_userdata_type ), INTENT( INOUT ) :: userdata
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( OUT ) :: g

!  call C interoperable eval_g

    status = feval_g( n, x, g, cuserdata )
    RETURN

    END SUBROUTINE wrap_eval_g

!  eval_HPROD wrapper

    SUBROUTINE wrap_eval_hprod( status, x, userdata, u, v, fgot_h )
    INTEGER ( KIND = C_INT ), INTENT( OUT ) :: status
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( IN ) :: x
    TYPE ( f_nlpt_userdata_type ), INTENT( INOUT ) :: userdata
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( INOUT ) :: u
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( IN ) :: v
    LOGICAL, OPTIONAL, INTENT( IN ) :: fgot_h
    LOGICAL ( KIND = C_BOOL ) :: cgot_h

!  call C interoperable eval_hprod

    IF ( PRESENT( fgot_h ) ) THEN
      cgot_h = fgot_h
    ELSE
      cgot_h = .false.
    END IF
    status = feval_hprod( n, x, u, v, cgot_h, cuserdata )
    RETURN

    END SUBROUTINE wrap_eval_hprod

!  eval_SHPROD wrapper

    SUBROUTINE wrap_eval_shprod( status, x, userdata, nnz_v, index_nz_v, v,    &
                                 nnz_u, index_nz_u, u, fgot_h )
    INTEGER ( KIND = C_INT ), INTENT( OUT ) :: status
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( IN ) :: x
    TYPE ( f_nlpt_userdata_type ), INTENT( INOUT ) :: userdata
    INTEGER ( KIND = C_INT ), INTENT( IN ) :: nnz_v
    INTEGER ( KIND = C_INT ), DIMENSION(:), INTENT( IN ) :: index_nz_v
    REAL ( KIND = wp ), dimension( : ), INTENT( IN ) :: v
    INTEGER ( KIND = C_INT ), INTENT( OUT ) :: nnz_u 
    INTEGER ( KIND = C_INT ), DIMENSION( : ), INTENT( OUT ) :: index_nz_u
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( OUT ) :: u
    LOGICAL, OPTIONAL, INTENT( IN ) :: fgot_h
    LOGICAL ( KIND = C_BOOL ) :: cgot_h

!  call C interoperable eval_shprod

    IF ( PRESENT( fgot_h ) ) THEN
      cgot_h = fgot_h 
    ELSE
      cgot_h = .false.
    END IF

    IF ( f_indexing ) then
      status = feval_shprod( n, x, nnz_v, index_nz_v, v, nnz_u, index_nz_u,    &
                             u, cgot_h, cuserdata )
    ELSE ! handle C sparse matrix indexing
      status = feval_shprod(n, x, nnz_v, index_nz_v - 1, v, nnz_u, index_nz_u, &
                             u, cgot_h, cuserdata )
      index_nz_u = index_nz_u + 1
    END IF
    RETURN

    END SUBROUTINE wrap_eval_shprod

!  eval_PREC wrapper

    SUBROUTINE wrap_eval_prec( status, x, userdata, u, v )
    INTEGER ( KIND = C_INT ), INTENT( OUT ) :: status
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( IN ) :: x
    TYPE ( f_nlpt_userdata_type ), INTENT( INOUT ) :: userdata
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( OUT ) :: u
    REAL ( KIND = wp ), DIMENSION( : ), INTENT( IN ) :: v

!  call C interoperable eval_prec

    status = feval_prec( n, x, u, v, cuserdata )
    RETURN

    END SUBROUTINE wrap_eval_prec

  END SUBROUTINE bgo_solve_without_mat

!  -------------------------------------------------
!  C interface to fortran bgo_solve_reverse_with_mat
!  -------------------------------------------------

  SUBROUTINE bgo_solve_reverse_with_mat( cdata, status, eval_status,           &
                                         n, x, f, g, ne, val, u, v ) BIND( C )
  USE GALAHAD_BGO_double_ciface
  IMPLICIT NONE

!  dummy arguments

  INTEGER ( KIND = C_INT ), INTENT( IN ), VALUE :: n, ne
  INTEGER ( KIND = C_INT ), INTENT( INOUT ) :: status, eval_status
  REAL ( KIND = wp ), INTENT( IN ), VALUE :: f
  REAL ( KIND = wp ), INTENT( INOUT ), DIMENSION( n ) :: x, g, u, v 
  REAL ( KIND = wp ), INTENT( INOUT ), DIMENSION( ne ) :: val
  TYPE ( C_PTR ), INTENT( INOUT ) :: cdata

!  local variables

  TYPE ( f_bgo_full_data_type ), POINTER :: fdata

!  associate data pointer

  CALL C_F_POINTER( cdata, fdata )

!  solve the problem when the Hessian is available by reverse communication

  CALL f_bgo_solve_reverse_with_mat( fdata, status, eval_status, x, f, g, val, &
                                      u, v )
  RETURN
    
  END SUBROUTINE bgo_solve_reverse_with_mat

!  ----------------------------------------------------
!  C interface to fortran bgo_solve_reverse_without_mat
!  ----------------------------------------------------

  SUBROUTINE bgo_solve_reverse_without_mat( cdata, status, eval_status, n,     &
                                            x, f, g, u, v, index_nz_v, nnz_v,  &
                                            index_nz_u, nnz_u ) BIND( C )
  USE GALAHAD_BGO_double_ciface
  IMPLICIT NONE

!  dummy arguments

  INTEGER ( KIND = C_INT ), INTENT( IN ), VALUE :: n, nnz_u
  INTEGER ( KIND = C_INT ), INTENT( INOUT ) :: status, eval_status
  INTEGER ( KIND = C_INT ), INTENT( OUT ) :: nnz_v
  REAL ( KIND = wp ), INTENT( IN ), VALUE :: f
  REAL ( KIND = wp ), INTENT( INOUT ), DIMENSION( n ) :: x, g, u, v
  INTEGER ( KIND = C_INT ), INTENT( IN ), DIMENSION( n ) :: index_nz_u
  INTEGER ( KIND = C_INT ), INTENT( OUT ), DIMENSION( n ) :: index_nz_v
  TYPE ( C_PTR ), INTENT( INOUT ) :: cdata

!  local variables

  TYPE ( f_bgo_full_data_type ), POINTER :: fdata
  LOGICAL :: f_indexing

!  associate data pointer

  CALL C_F_POINTER( cdata, fdata )

!  is fortran-style 1-based indexing used?

  f_indexing = fdata%f_indexing

!  solve the problem when Hessian products are available by reverse 
!  communication

  IF ( f_indexing ) THEN
    CALL f_bgo_solve_reverse_without_mat( fdata, status, eval_status, x, f, g, &
                                          u, v, index_nz_v, nnz_v,             &
                                          index_nz_u, nnz_u )
  ELSE
    CALL f_bgo_solve_reverse_without_mat( fdata, status, eval_status, x, f, g, &
                                          u, v, index_nz_v, nnz_v,             &
                                          index_nz_u + 1, nnz_u )

!  convert to C indexing if required

     IF ( status == 7 ) index_nz_v( : nnz_v ) = index_nz_v( : nnz_v ) - 1
  END IF

  RETURN

  END SUBROUTINE bgo_solve_reverse_without_mat

!  --------------------------------------
!  C interface to fortran bgo_information
!  --------------------------------------

  SUBROUTINE bgo_information( cdata, cinform, status ) BIND( C ) 
  USE GALAHAD_BGO_double_ciface
  IMPLICIT NONE

!  dummy arguments

  TYPE ( C_PTR ), INTENT( INOUT ) :: cdata
  TYPE ( bgo_inform_type ), INTENT( INOUT ) :: cinform
  INTEGER ( KIND = C_INT ), INTENT( OUT ) :: status

!  local variables

  TYPE ( f_bgo_full_data_type ), pointer :: fdata
  TYPE ( f_bgo_inform_type ) :: finform

!  associate data pointer

  CALL C_F_POINTER( cdata, fdata )

!  obtain BGO solution information

  CALL f_bgo_information( fdata, finform, status )

!  copy inform out

  CALL copy_inform_out( finform, cinform )
  RETURN

  END SUBROUTINE bgo_information

!  ------------------------------------
!  C interface to fortran bgo_terminate
!  ------------------------------------

  SUBROUTINE bgo_terminate( cdata, ccontrol, cinform ) BIND( C ) 
  USE GALAHAD_BGO_double_ciface
  IMPLICIT NONE

!  dummy arguments

  TYPE ( C_PTR ), INTENT( INOUT ) :: cdata
  TYPE ( bgo_control_type ), INTENT( IN ) :: ccontrol
  TYPE ( bgo_inform_type ), INTENT( INOUT ) :: cinform

!  local variables

  TYPE ( f_bgo_full_data_type ), pointer :: fdata
  TYPE ( f_bgo_control_type ) :: fcontrol
  TYPE ( f_bgo_inform_type ) :: finform
  LOGICAL :: f_indexing

!  copy control in

  CALL copy_control_in( ccontrol, fcontrol, f_indexing )

!  copy inform in

  CALL copy_inform_in( cinform, finform )

!  associate data pointer

  CALL C_F_POINTER( cdata, fdata )

!  deallocate workspace

  CALL f_bgo_terminate( fdata, fcontrol, finform )

!  copy inform out

  CALL copy_inform_out( finform, cinform )

!  deallocate data

  DEALLOCATE( fdata ); cdata = C_NULL_PTR 
  RETURN

  END SUBROUTINE bgo_terminate

