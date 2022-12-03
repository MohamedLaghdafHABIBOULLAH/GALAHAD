! THIS VERSION: GALAHAD 4.1 - 2022-12-01 AT 13:00 GMT.

      TYPE DMUMPS_STRUC( long )
      INTEGER, KIND :: long

!  This dummy structure contains a subset of the parameters for the
!  interface to the user, plus internal information from the MUMPS solver.

!  Extracted from package-provided dmumps_struc.h

        INTEGER :: COMM
        INTEGER :: SYM, PAR
        INTEGER :: JOB
        INTEGER :: MYID
        INTEGER :: N
        INTEGER :: NZ
        INTEGER :: NRHS
        INTEGER :: LRHS
        INTEGER( KIND = long ) :: NNZ
        DOUBLE PRECISION, DIMENSION( : ), POINTER :: A
        INTEGER, DIMENSION( : ), POINTER :: IRN, JCN
        DOUBLE PRECISION, DIMENSION( : ), POINTER :: RHS
        INTEGER, DIMENSION( : ), POINTER :: PERM_IN
        DOUBLE PRECISION, DIMENSION( : ), POINTER :: COLSCA, ROWSCA
        INTEGER, DIMENSION( : ), POINTER :: SYM_PERM, UNS_PERM
        INTEGER, DIMENSION( 60 ) ::  ICNTL
        DOUBLE PRECISION, DIMENSION( 15 ) :: CNTL
        INTEGER, DIMENSION( 80 ) :: INFOG
        DOUBLE PRECISION, DIMENSION( 40 ) ::  RINFOG
      END TYPE DMUMPS_STRUC
