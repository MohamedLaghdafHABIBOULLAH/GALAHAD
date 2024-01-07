! THIS VERSION: GALAHAD 4.3 - 2024-01-05 AT 13:10 GMT.

!-*-*-*-*-*  L A N C E L O T  -B-  DUMMY AD02_FORWARD  M O D U L E S *-*-*-*

!  Nick Gould, for GALAHAD productions
!  Copyright reserved
!  June 28th 1996

MODULE HSL_AD02_FORWARD_SINGLE
      USE GALAHAD_KINDS
      IMPLICIT NONE
      PRIVATE
      PUBLIC :: AD02_INITIALIZE
    
!  Dummy HSL_AD02_FORWARD_SINGLE module

      TYPE, PUBLIC :: AD02_REAL
        PRIVATE
        INTEGER ( KIND = ip_ ) :: p
      END TYPE AD02_REAL

      TYPE, PUBLIC :: AD02_DATA
        PRIVATE
        INTEGER ( KIND = ip_ ) :: level
      END TYPE AD02_DATA

CONTAINS

      SUBROUTINE AD02_INITIALIZE(DEGREE,A,VALUE,DATA,FULL_THRESHOLD)
        INTEGER ( KIND = ip_ ), INTENT (IN) :: DEGREE
!       TYPE (AD02_REAL), INTENT (OUT) :: A
        TYPE (AD02_REAL) :: A
        INTEGER ( KIND = ip_ ), OPTIONAL, INTENT (IN) :: FULL_THRESHOLD
        TYPE (AD02_DATA), POINTER :: DATA
        REAL ( KIND = sp_ ), INTENT (IN) :: VALUE
    
!  Dummy subroutine available with LANCELOT

        WRITE ( 6, 2000 )
        STOP

!  Non-executable statements

 2000    FORMAT( /, ' We regret that the solution options that you have ', /, &
                    ' chosen are not all freely available with LANCELOT.', //,&
                    ' If you have HSL (formerly the Harwell Subroutine',      &
                    ' Library), this ', /,                                    &
                    ' option may be enabled by replacing the dummy ', /,      &
                    ' module HSL_AD02_FORWARD_SINGLE with its H...', /,       &
                    ' namesake and dependencies. See', /,                     &
                    '   $GALAHAD/src/makedefs/packages for details.', //,     &
                    ' *** EXECUTION TERMINATING *** ', / )

      END SUBROUTINE AD02_INITIALIZE

END MODULE HSL_AD02_FORWARD_SINGLE

!-*-*-*-*-*  L A N C E L O T  -B-  DUMMY AD02_BACKWARD  M O D U L E S *-*-*-*

!  Nick Gould, for GALAHAD productions
!  Copyright reserved
!  June 28th 1996

MODULE HSL_AD02_BACKWARD_SINGLE
      USE GALAHAD_KINDS_single
      IMPLICIT NONE
      PRIVATE
      PUBLIC :: AD02_INITIALIZE
    
!  Dummy HSL_AD02_BACKWARD_SINGLE module

      TYPE, PUBLIC :: AD02_REAL
        PRIVATE
        INTEGER ( KIND = ip_ ) :: p
      END TYPE AD02_REAL

      TYPE, PUBLIC :: AD02_DATA
        PRIVATE
        INTEGER ( KIND = ip_ ) :: level
      END TYPE AD02_DATA

CONTAINS

      SUBROUTINE AD02_INITIALIZE(DEGREE,A,VALUE,DATA,FULL_THRESHOLD)
        INTEGER ( KIND = ip_ ), INTENT (IN) :: DEGREE
!       TYPE (AD02_REAL), INTENT (OUT) :: A
        TYPE (AD02_REAL) :: A
        INTEGER ( KIND = ip_ ), OPTIONAL, INTENT (IN) :: FULL_THRESHOLD
        TYPE (AD02_DATA), POINTER :: DATA
        REAL ( KIND = sp_ ), INTENT (IN) :: VALUE
    
!  Dummy subroutine available with LANCELOT

        WRITE ( 6, 2000 )
        STOP

!  Non-executable statements

 2000    FORMAT( /, ' We regret that the solution options that you have ', /, &
                    ' chosen are not all freely available with LANCELOT.', //,&
                    ' If you have HSL (formerly the Harwell Subroutine',      &
                    ' Library), this ', /,                                    &
                    ' option may be enabled by replacing the dummy ', /,      &
                    ' module HSL_AD02_BACKWARD_SINGLE with its HSL ',/,       &
                    ' namesake and dependencies. See', /,                     &
                    '   $GALAHAD/src/makedefs/packages for details.', //,     &
                    ' *** EXECUTION TERMINATING *** ', / )

      END SUBROUTINE AD02_INITIALIZE

END MODULE HSL_AD02_BACKWARD_SINGLE
