#ifdef GALAHAD_64BIT_INTEGER
#define GALAHAD_LAPACK_interface GALAHAD_LAPACK_interface_64
#ifdef GALAHAD_NO_UNDERSCORE_64BIT_INTEGER
#define SGETRF SGETRF64
#define DGETRF DGETRF64
#define SGETRS SGETRS64
#define DGETRS DGETRS64
#define SGELS  SGELS64
#define DGELS  DGELS64
#define SGELSY SGELSY64
#define DGELSY DGELSY64
#define SGELSS SGELSS64
#define DGELSS DGELSS64
#define SGELSD SGELSD64
#define DGELSD DGELSD64
#define SGESVD SGESVD64
#define DGESVD DGESVD64
#define SPTTRF SPTTRF64
#define DPTTRF DPTTRF64
#define SPOTRF SPOTRF64
#define DPOTRF DPOTRF64
#define SPOTRS SPOTRS64
#define DPOTRS DPOTRS64
#define SSYTRF SSYTRF64
#define DSYTRF DSYTRF64
#define SSYTRS SSYTRS64
#define DSYTRS DSYTRS64
#define SPBTRF SPBTRF64
#define DPBTRF DPBTRF64
#define SPBTRS SPBTRS64
#define DPBTRS DPBTRS64
#define SSYEV  SSYEV64
#define DSYEV  DSYEV64
#define SSYGV  SSYGV64
#define DSYGV  DSYGV64
#define SHSEQR SHSEQR64
#define DHSEQR DHSEQR64
#define SSTERF SSTERF64
#define DSTERF DSTERF64
#define SLAEV2 SLAEV264
#define DLAEV2 DLAEV264
#elif GALAHAD_DOUBLE_UNDERSCORE_64BIT_INTEGER
#define SGETRF SGETRF__64
#define DGETRF DGETRF__64
#define SGETRS SGETRS__64
#define DGETRS DGETRS__64
#define SGELS  SGELS__64
#define DGELS  DGELS__64
#define SGELSY SGELSY__64
#define DGELSY DGELSY__64
#define SGELSS SGELSS__64
#define DGELSS DGELSS__64
#define SGELSD SGELSD__64
#define DGELSD DGELSD__64
#define SGESVD SGESVD__64
#define DGESVD DGESVD__64
#define SPTTRF SPTTRF__64
#define DPTTRF DPTTRF__64
#define SPOTRF SPOTRF__64
#define DPOTRF DPOTRF__64
#define SPOTRS SPOTRS__64
#define DPOTRS DPOTRS__64
#define SSYTRF SSYTRF__64
#define DSYTRF DSYTRF__64
#define SSYTRS SSYTRS__64
#define DSYTRS DSYTRS__64
#define SPBTRF SPBTRF__64
#define DPBTRF DPBTRF__64
#define SPBTRS SPBTRS__64
#define DPBTRS DPBTRS__64
#define SSYEV  SSYEV__64
#define DSYEV  DSYEV__64
#define SSYGV  SSYGV__64
#define DSYGV  DSYGV__64
#define SHSEQR SHSEQR__64
#define DHSEQR DHSEQR__64
#define SSTERF SSTERF__64
#define DSTERF DSTERF__64
#define SLAEV2 SLAEV2__64
#define DLAEV2 DLAEV2__64
#elif GALAHAD_NO_SYMBOL_64BIT_INTEGER
#define SGETRF SGETRF
#define DGETRF DGETRF
#define SGETRS SGETRS
#define DGETRS DGETRS
#define SGELS  SGELS
#define DGELS  DGELS
#define SGELSY SGELSY
#define DGELSY DGELSY
#define SGELSS SGELSS
#define DGELSS DGELSS
#define SGELSD SGELSD
#define DGELSD DGELSD
#define SGESVD SGESVD
#define DGESVD DGESVD
#define SPTTRF SPTTRF
#define DPTTRF DPTTRF
#define SPOTRF SPOTRF
#define DPOTRF DPOTRF
#define SPOTRS SPOTRS
#define DPOTRS DPOTRS
#define SSYTRF SSYTRF
#define DSYTRF DSYTRF
#define SSYTRS SSYTRS
#define DSYTRS DSYTRS
#define SPBTRF SPBTRF
#define DPBTRF DPBTRF
#define SPBTRS SPBTRS
#define DPBTRS DPBTRS
#define SSYEV  SSYEV
#define DSYEV  DSYEV
#define SSYGV  SSYGV
#define DSYGV  DSYGV
#define SHSEQR SHSEQR
#define DHSEQR DHSEQR
#define SSTERF SSTERF
#define DSTERF DSTERF
#define SLAEV2 SLAEV2
#define DLAEV2 DLAEV2
#else
#define SGETRF SGETRF_64
#define DGETRF DGETRF_64
#define SGETRS SGETRS_64
#define DGETRS DGETRS_64
#define SGELS  SGELS_64
#define DGELS  DGELS_64
#define SGELSY SGELSY_64
#define DGELSY DGELSY_64
#define SGELSS SGELSS_64
#define DGELSS DGELSS_64
#define SGELSD SGELSD_64
#define DGELSD DGELSD_64
#define SGESVD SGESVD_64
#define DGESVD DGESVD_64
#define SPTTRF SPTTRF_64
#define DPTTRF DPTTRF_64
#define SPOTRF SPOTRF_64
#define DPOTRF DPOTRF_64
#define SPOTRS SPOTRS_64
#define DPOTRS DPOTRS_64
#define SSYTRF SSYTRF_64
#define DSYTRF DSYTRF_64
#define SSYTRS SSYTRS_64
#define DSYTRS DSYTRS_64
#define SPBTRF SPBTRF_64
#define DPBTRF DPBTRF_64
#define SPBTRS SPBTRS_64
#define DPBTRS DPBTRS_64
#define SSYEV  SSYEV_64
#define DSYEV  DSYEV_64
#define SSYGV  SSYGV_64
#define DSYGV  DSYGV_64
#define SHSEQR SHSEQR_64
#define DHSEQR DHSEQR_64
#define SSTERF SSTERF_64
#define DSTERF DSTERF_64
#define SLAEV2 SLAEV2_64
#define DLAEV2 DLAEV2_64
#endif
#endif
