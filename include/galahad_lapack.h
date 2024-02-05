#include "galahad_blas.h"

#ifdef INTEGER_64
#define GALAHAD_LAPACK_interface GALAHAD_LAPACK_interface_64
#endif

#ifdef GALAHAD_LAPACK
#ifdef INTEGER_64
#define DISNAN GALAHAD_DISNAN_64
#define DLADIV GALAHAD_DLADIV_64
#define DLAISN GALAHAD_DLAISN_64
#define DLAMCH GALAHAD_DLAMCH_64
#define DLAMC3 GALAHAD_DLAMC3_64
#define DLANGE GALAHAD_DLANGE_64
#define DLANST GALAHAD_DLANST_64
#define DLANSY GALAHAD_DLANSY_64
#define DLAPY2 GALAHAD_DLAPY2_64
#define DLAPY3 GALAHAD_DLAPY3_64
#define ILADLC GALAHAD_ILADLC_64
#define ILADLR GALAHAD_ILADLR_64
#define ILAENV GALAHAD_ILAENV_64
#define ILASLC GALAHAD_ILASLC_64
#define ILASLR GALAHAD_ILASLR_64
#define ILAZLC GALAHAD_ILAZLC_64
#define ILAZLR GALAHAD_ILAZLR_64
#define IPARMQ GALAHAD_IPARMQ_64
#define SISNAN GALAHAD_SISNAN_64
#define SLAISN GALAHAD_SLAISN_64
#define SLAMCH GALAHAD_SLAMCH_64
#define SLAMC3 GALAHAD_SLAMC3_64
#define SLANGE GALAHAD_SLANGE_64
#define SLANST GALAHAD_SLANST_64
#define SLANSY GALAHAD_SLANSY_64
#define SLAPY2 GALAHAD_SLAPY2_64
#define DBDSQR GALAHAD_DBDSQR_64
#define DCOMBS GALAHAD_DCOMBS_64
#define DGEBD2 GALAHAD_DGEBD2_64
#define DGEBRD GALAHAD_DGEBRD_64
#define DGEHD2 GALAHAD_DGEHD2_64
#define DGEHRD GALAHAD_DGEHRD_64
#define DGELQ2 GALAHAD_DGELQ2_64
#define DGELQF GALAHAD_DGELQF_64
#define DGELS  GALAHAD_DGELS_64
#define DGELSD GALAHAD_DGELSD_64
#define DGELSS GALAHAD_DGELSS_64
#define DGELSY GALAHAD_DGELSY_64
#define DGEQP3 GALAHAD_DGEQP3_64
#define DGEQR2 GALAHAD_DGEQR2_64
#define DGEQRF GALAHAD_DGEQRF_64
#define DGESVD GALAHAD_DGESVD_64
#define DGETF2 GALAHAD_DGETF2_64
#define DGETRF GALAHAD_DGETRF_64
#define DGETRF GALAHAD_DGETRF_64
#define DGETRS GALAHAD_DGETRS_64
#define DHSEQR GALAHAD_DHSEQR_64
#define DLABAD GALAHAD_DLABAD_64
#define DLABRD GALAHAD_DLABRD_64
#define DLACPY GALAHAD_DLACPY_64
#define DLADIV GALAHAD_DLADIV_64
#define DLADIV GALAHAD_DLADIV_64
#define DLAE2  GALAHAD_DLAE2_64
#define DLAED6 GALAHAD_DLAED6_64
#define DLAEV2 GALAHAD_DLAEV2_64
#define DLAEXC GALAHAD_DLAEXC_64
#define DLAHQR GALAHAD_DLAHQR_64
#define DLAHR2 GALAHAD_DLAHR2_64
#define DLAIC1 GALAHAD_DLAIC1_64
#define DLALS0 GALAHAD_DLALS0_64
#define DLALSA GALAHAD_DLALSA_64
#define DLALSD GALAHAD_DLALSD_64
#define DLAMRG GALAHAD_DLAMRG_64
#define DLANV2 GALAHAD_DLANV2_64
#define DLAQP2 GALAHAD_DLAQP2_64
#define DLAQPS GALAHAD_DLAQPS_64
#define DLAQR0 GALAHAD_DLAQR0_64
#define DLAQR1 GALAHAD_DLAQR1_64
#define DLAQR2 GALAHAD_DLAQR2_64
#define DLAQR3 GALAHAD_DLAQR3_64
#define DLAQR4 GALAHAD_DLAQR4_64
#define DLAQR5 GALAHAD_DLAQR5_64
#define DLARF  GALAHAD_DLARF_64
#define DLARFB GALAHAD_DLARFB_64
#define DLARFG GALAHAD_DLARFG_64
#define DLARFT GALAHAD_DLARFT_64
#define DLARFX GALAHAD_DLARFX_64
#define DLARTG GALAHAD_DLARTG_64
#define DLARZ  GALAHAD_DLARZ_64
#define DLARZB GALAHAD_DLARZB_64
#define DLARZT GALAHAD_DLARZT_64
#define DLAS2  GALAHAD_DLAS2_64
#define DLASCL GALAHAD_DLASCL_64
#define DLASD4 GALAHAD_DLASD4_64
#define DLASD5 GALAHAD_DLASD5_64
#define DLASD6 GALAHAD_DLASD6_64
#define DLASD7 GALAHAD_DLASD7_64
#define DLASD8 GALAHAD_DLASD8_64
#define DLASDA GALAHAD_DLASDA_64
#define DLASDQ GALAHAD_DLASDQ_64
#define DLASDT GALAHAD_DLASDT_64
#define DLASET GALAHAD_DLASET_64
#define DLASQ1 GALAHAD_DLASQ1_64
#define DLASQ2 GALAHAD_DLASQ2_64
#define DLASQ3 GALAHAD_DLASQ3_64
#define DLASQ4 GALAHAD_DLASQ4_64
#define DLASQ5 GALAHAD_DLASQ5_64
#define DLASQ6 GALAHAD_DLASQ6_64
#define DLASR  GALAHAD_DLASR_64
#define DLASRT GALAHAD_DLASRT_64
#define DLASSQ GALAHAD_DLASSQ_64
#define DLASV2 GALAHAD_DLASV2_64
#define DLASWP GALAHAD_DLASWP_64
#define DLASY2 GALAHAD_DLASY2_64
#define DLASYF GALAHAD_DLASYF_64
#define DLATRD GALAHAD_DLATRD_64
#define DLATRZ GALAHAD_DLATRZ_64
#define DORG2L GALAHAD_DORG2L_64
#define DORG2R GALAHAD_DORG2R_64
#define DORGBR GALAHAD_DORGBR_64
#define DORGL2 GALAHAD_DORGL2_64
#define DORGLQ GALAHAD_DORGLQ_64
#define DORGQL GALAHAD_DORGQL_64
#define DORGQR GALAHAD_DORGQR_64
#define DORGTR GALAHAD_DORGTR_64
#define DORM2R GALAHAD_DORM2R_64
#define DORMBR GALAHAD_DORMBR_64
#define DORMHR GALAHAD_DORMHR_64
#define DORML2 GALAHAD_DORML2_64
#define DORMLQ GALAHAD_DORMLQ_64
#define DORMQR GALAHAD_DORMQR_64
#define DORMR3 GALAHAD_DORMR3_64
#define DORMRZ GALAHAD_DORMRZ_64
#define DPBTF2 GALAHAD_DPBTF2_64
#define DPBTRF GALAHAD_DPBTRF_64
#define DPBTRS GALAHAD_DPBTRS_64
#define DPOTF2 GALAHAD_DPOTF2_64
#define DPOTRF GALAHAD_DPOTRF_64
#define DPOTRF GALAHAD_DPOTRF_64
#define DPOTRS GALAHAD_DPOTRS_64
#define DPTTRF GALAHAD_DPTTRF_64
#define DPTTRS GALAHAD_DPTTRS_64
#define DPTTS2 GALAHAD_DPTTS2_64
#define DRSCL  GALAHAD_DRSCL_64
#define DSTEQR GALAHAD_DSTEQR_64
#define DSTERF GALAHAD_DSTERF_64
#define DSYEV  GALAHAD_DSYEV_64
#define DSYGS2 GALAHAD_DSYGS2_64
#define DSYGST GALAHAD_DSYGST_64
#define DSYGV  GALAHAD_DSYGV_64
#define DSYTD2 GALAHAD_DSYTD2_64
#define DSYTF2 GALAHAD_DSYTF2_64
#define DSYTRD GALAHAD_DSYTRD_64
#define DSYTRF GALAHAD_DSYTRF_64
#define DSYTRS GALAHAD_DSYTRS_64
#define DTREXC GALAHAD_DTREXC_64
#define DTRTRS GALAHAD_DTRTRS_64
#define DTZRZF GALAHAD_DTZRZF_64
#define SBDSQR GALAHAD_SBDSQR_64
#define SCOMBS GALAHAD_SCOMBS_64
#define SGEBD2 GALAHAD_SGEBD2_64
#define SGEBRD GALAHAD_SGEBRD_64
#define SGEHD2 GALAHAD_SGEHD2_64
#define SGEHRD GALAHAD_SGEHRD_64
#define SGELQ2 GALAHAD_SGELQ2_64
#define SGELQF GALAHAD_SGELQF_64
#define SGELS  GALAHAD_SGELS_64
#define SGELSD GALAHAD_SGELSD_64
#define SGELSS GALAHAD_SGELSS_64
#define SGELSY GALAHAD_SGELSY_64
#define SGEQP3 GALAHAD_SGEQP3_64
#define SGEQR2 GALAHAD_SGEQR2_64
#define SGEQRF GALAHAD_SGEQRF_64
#define SGESVD GALAHAD_SGESVD_64
#define SGETF2 GALAHAD_SGETF2_64
#define SGETRF GALAHAD_SGETRF_64
#define SGETRF GALAHAD_SGETRF_64
#define SGETRS GALAHAD_SGETRS_64
#define SHSEQR GALAHAD_SHSEQR_64
#define SLABAD GALAHAD_SLABAD_64
#define SLABRD GALAHAD_SLABRD_64
#define SLACPY GALAHAD_SLACPY_64
#define SLAE2  GALAHAD_SLAE2_64
#define SLAED6 GALAHAD_SLAED6_64
#define SLAEV2 GALAHAD_SLAEV2_64
#define SLAEXC GALAHAD_SLAEXC_64
#define SLAHQR GALAHAD_SLAHQR_64
#define SLAHR2 GALAHAD_SLAHR2_64
#define SLAIC1 GALAHAD_SLAIC1_64
#define SLALS0 GALAHAD_SLALS0_64
#define SLALSA GALAHAD_SLALSA_64
#define SLALSD GALAHAD_SLALSD_64
#define SLAMRG GALAHAD_SLAMRG_64
#define SLANV2 GALAHAD_SLANV2_64
#define SLAQP2 GALAHAD_SLAQP2_64
#define SLAQPS GALAHAD_SLAQPS_64
#define SLAQR0 GALAHAD_SLAQR0_64
#define SLAQR1 GALAHAD_SLAQR1_64
#define SLAQR2 GALAHAD_SLAQR2_64
#define SLAQR3 GALAHAD_SLAQR3_64
#define SLAQR4 GALAHAD_SLAQR4_64
#define SLAQR5 GALAHAD_SLAQR5_64
#define SLARF  GALAHAD_SLARF_64
#define SLARFB GALAHAD_SLARFB_64
#define SLARFG GALAHAD_SLARFG_64
#define SLARFT GALAHAD_SLARFT_64
#define SLARFX GALAHAD_SLARFX_64
#define SLARTG GALAHAD_SLARTG_64
#define SLARZ  GALAHAD_SLARZ_64
#define SLARZB GALAHAD_SLARZB_64
#define SLARZT GALAHAD_SLARZT_64
#define SLAS2  GALAHAD_SLAS2_64
#define SLASCL GALAHAD_SLASCL_64
#define SLASD4 GALAHAD_SLASD4_64
#define SLASD5 GALAHAD_SLASD5_64
#define SLASD6 GALAHAD_SLASD6_64
#define SLASD7 GALAHAD_SLASD7_64
#define SLASD8 GALAHAD_SLASD8_64
#define SLASDA GALAHAD_SLASDA_64
#define SLASDQ GALAHAD_SLASDQ_64
#define SLASDT GALAHAD_SLASDT_64
#define SLASET GALAHAD_SLASET_64
#define SLASQ1 GALAHAD_SLASQ1_64
#define SLASQ2 GALAHAD_SLASQ2_64
#define SLASQ3 GALAHAD_SLASQ3_64
#define SLASQ4 GALAHAD_SLASQ4_64
#define SLASQ5 GALAHAD_SLASQ5_64
#define SLASQ6 GALAHAD_SLASQ6_64
#define SLASR  GALAHAD_SLASR_64
#define SLASRT GALAHAD_SLASRT_64
#define SLASSQ GALAHAD_SLASSQ_64
#define SLASV2 GALAHAD_SLASV2_64
#define SLASWP GALAHAD_SLASWP_64
#define SLASY2 GALAHAD_SLASY2_64
#define SLASYF GALAHAD_SLASYF_64
#define SLATRD GALAHAD_SLATRD_64
#define SLATRZ GALAHAD_SLATRZ_64
#define SORG2L GALAHAD_SORG2L_64
#define SORG2R GALAHAD_SORG2R_64
#define SORGBR GALAHAD_SORGBR_64
#define SORGL2 GALAHAD_SORGL2_64
#define SORGLQ GALAHAD_SORGLQ_64
#define SORGQL GALAHAD_SORGQL_64
#define SORGQR GALAHAD_SORGQR_64
#define SORGTR GALAHAD_SORGTR_64
#define SORM2R GALAHAD_SORM2R_64
#define SORMBR GALAHAD_SORMBR_64
#define SORMHR GALAHAD_SORMHR_64
#define SORML2 GALAHAD_SORML2_64
#define SORMLQ GALAHAD_SORMLQ_64
#define SORMQR GALAHAD_SORMQR_64
#define SORMR3 GALAHAD_SORMR3_64
#define SORMRZ GALAHAD_SORMRZ_64
#define SPBTF2 GALAHAD_SPBTF2_64
#define SPBTRF GALAHAD_SPBTRF_64
#define SPBTRS GALAHAD_SPBTRS_64
#define SPOTF2 GALAHAD_SPOTF2_64
#define SPOTRF GALAHAD_SPOTRF_64
#define SPOTRF GALAHAD_SPOTRF_64
#define SPOTRS GALAHAD_SPOTRS_64
#define SPTTRF GALAHAD_SPTTRF_64
#define SPTTRS GALAHAD_SPTTRS_64
#define SPTTS2 GALAHAD_SPTTS2_64
#define SRSCL  GALAHAD_SRSCL_64
#define SSTEQR GALAHAD_SSTEQR_64
#define SSTERF GALAHAD_SSTERF_64
#define SSYEV  GALAHAD_SSYEV_64
#define SSYGS2 GALAHAD_SSYGS2_64
#define SSYGST GALAHAD_SSYGST_64
#define SSYGV  GALAHAD_SSYGV_64
#define SSYTD2 GALAHAD_SSYTD2_64
#define SSYTF2 GALAHAD_SSYTF2_64
#define SSYTRD GALAHAD_SSYTRD_64
#define SSYTRF GALAHAD_SSYTRF_64
#define SSYTRS GALAHAD_SSYTRS_64
#define STREXC GALAHAD_STREXC_64
#define STRTRS GALAHAD_STRTRS_64
#define STZRZF GALAHAD_STZRZF_64
#define ZLACGV GALAHAD_ZLACGV_64
#define ZLARF  GALAHAD_ZLARF_64
#define ZLARFB GALAHAD_ZLARFB_64
#define ZLARFG GALAHAD_ZLARFG_64
#define ZLARFT GALAHAD_ZLARFT_64
#else
#define DISNAN GALAHAD_DISNAN
#define DLADIV GALAHAD_DLADIV
#define DLAISN GALAHAD_DLAISN
#define DLAMCH GALAHAD_DLAMCH
#define DLAMC3 GALAHAD_DLAMC3
#define DLANGE GALAHAD_DLANGE
#define DLANST GALAHAD_DLANST
#define DLANSY GALAHAD_DLANSY
#define DLAPY2 GALAHAD_DLAPY2
#define DLAPY3 GALAHAD_DLAPY3
#define ILADLC GALAHAD_ILADLC
#define ILADLR GALAHAD_ILADLR
#define ILAENV GALAHAD_ILAENV
#define ILASLC GALAHAD_ILASLC
#define ILASLR GALAHAD_ILASLR
#define ILAZLC GALAHAD_ILAZLC
#define ILAZLR GALAHAD_ILAZLR
#define IPARMQ GALAHAD_IPARMQ
#define SISNAN GALAHAD_SISNAN
#define SLAISN GALAHAD_SLAISN
#define SLAMCH GALAHAD_SLAMCH
#define SLAMC3 GALAHAD_SLAMC3
#define SLANGE GALAHAD_SLANGE
#define SLANST GALAHAD_SLANST
#define SLANSY GALAHAD_SLANSY
#define SLAPY2 GALAHAD_SLAPY2
#define DBDSQR GALAHAD_DBDSQR
#define DCOMBS GALAHAD_DCOMBS
#define DGEBD2 GALAHAD_DGEBD2
#define DGEBRD GALAHAD_DGEBRD
#define DGEHD2 GALAHAD_DGEHD2
#define DGEHRD GALAHAD_DGEHRD
#define DGELQ2 GALAHAD_DGELQ2
#define DGELQF GALAHAD_DGELQF
#define DGELS  GALAHAD_DGELS
#define DGELSD GALAHAD_DGELSD
#define DGELSS GALAHAD_DGELSS
#define DGELSY GALAHAD_DGELSY
#define DGEQP3 GALAHAD_DGEQP3
#define DGEQR2 GALAHAD_DGEQR2
#define DGEQRF GALAHAD_DGEQRF
#define DGESVD GALAHAD_DGESVD
#define DGETF2 GALAHAD_DGETF2
#define DGETRF GALAHAD_DGETRF
#define DGETRF GALAHAD_DGETRF
#define DGETRS GALAHAD_DGETRS
#define DHSEQR GALAHAD_DHSEQR
#define DLABAD GALAHAD_DLABAD
#define DLABRD GALAHAD_DLABRD
#define DLACPY GALAHAD_DLACPY
#define DLADIV GALAHAD_DLADIV
#define DLADIV GALAHAD_DLADIV
#define DLAE2  GALAHAD_DLAE2
#define DLAED6 GALAHAD_DLAED6
#define DLAEV2 GALAHAD_DLAEV2
#define DLAEXC GALAHAD_DLAEXC
#define DLAHQR GALAHAD_DLAHQR
#define DLAHR2 GALAHAD_DLAHR2
#define DLAIC1 GALAHAD_DLAIC1
#define DLALS0 GALAHAD_DLALS0
#define DLALSA GALAHAD_DLALSA
#define DLALSD GALAHAD_DLALSD
#define DLAMRG GALAHAD_DLAMRG
#define DLANV2 GALAHAD_DLANV2
#define DLAQP2 GALAHAD_DLAQP2
#define DLAQPS GALAHAD_DLAQPS
#define DLAQR0 GALAHAD_DLAQR0
#define DLAQR1 GALAHAD_DLAQR1
#define DLAQR2 GALAHAD_DLAQR2
#define DLAQR3 GALAHAD_DLAQR3
#define DLAQR4 GALAHAD_DLAQR4
#define DLAQR5 GALAHAD_DLAQR5
#define DLARF  GALAHAD_DLARF
#define DLARFB GALAHAD_DLARFB
#define DLARFG GALAHAD_DLARFG
#define DLARFT GALAHAD_DLARFT
#define DLARFX GALAHAD_DLARFX
#define DLARTG GALAHAD_DLARTG
#define DLARZ  GALAHAD_DLARZ
#define DLARZB GALAHAD_DLARZB
#define DLARZT GALAHAD_DLARZT
#define DLAS2  GALAHAD_DLAS2
#define DLASCL GALAHAD_DLASCL
#define DLASD4 GALAHAD_DLASD4
#define DLASD5 GALAHAD_DLASD5
#define DLASD6 GALAHAD_DLASD6
#define DLASD7 GALAHAD_DLASD7
#define DLASD8 GALAHAD_DLASD8
#define DLASDA GALAHAD_DLASDA
#define DLASDQ GALAHAD_DLASDQ
#define DLASDT GALAHAD_DLASDT
#define DLASET GALAHAD_DLASET
#define DLASQ1 GALAHAD_DLASQ1
#define DLASQ2 GALAHAD_DLASQ2
#define DLASQ3 GALAHAD_DLASQ3
#define DLASQ4 GALAHAD_DLASQ4
#define DLASQ5 GALAHAD_DLASQ5
#define DLASQ6 GALAHAD_DLASQ6
#define DLASR  GALAHAD_DLASR
#define DLASRT GALAHAD_DLASRT
#define DLASSQ GALAHAD_DLASSQ
#define DLASV2 GALAHAD_DLASV2
#define DLASWP GALAHAD_DLASWP
#define DLASY2 GALAHAD_DLASY2
#define DLASYF GALAHAD_DLASYF
#define DLATRD GALAHAD_DLATRD
#define DLATRZ GALAHAD_DLATRZ
#define DORG2L GALAHAD_DORG2L
#define DORG2R GALAHAD_DORG2R
#define DORGBR GALAHAD_DORGBR
#define DORGL2 GALAHAD_DORGL2
#define DORGLQ GALAHAD_DORGLQ
#define DORGQL GALAHAD_DORGQL
#define DORGQR GALAHAD_DORGQR
#define DORGTR GALAHAD_DORGTR
#define DORM2R GALAHAD_DORM2R
#define DORMBR GALAHAD_DORMBR
#define DORMHR GALAHAD_DORMHR
#define DORML2 GALAHAD_DORML2
#define DORMLQ GALAHAD_DORMLQ
#define DORMQR GALAHAD_DORMQR
#define DORMR3 GALAHAD_DORMR3
#define DORMRZ GALAHAD_DORMRZ
#define DPBTF2 GALAHAD_DPBTF2
#define DPBTRF GALAHAD_DPBTRF
#define DPBTRS GALAHAD_DPBTRS
#define DPOTF2 GALAHAD_DPOTF2
#define DPOTRF GALAHAD_DPOTRF
#define DPOTRF GALAHAD_DPOTRF
#define DPOTRS GALAHAD_DPOTRS
#define DPTTRF GALAHAD_DPTTRF
#define DPTTRS GALAHAD_DPTTRS
#define DPTTS2 GALAHAD_DPTTS2
#define DRSCL  GALAHAD_DRSCL
#define DSTEQR GALAHAD_DSTEQR
#define DSTERF GALAHAD_DSTERF
#define DSYEV  GALAHAD_DSYEV
#define DSYGS2 GALAHAD_DSYGS2
#define DSYGST GALAHAD_DSYGST
#define DSYGV  GALAHAD_DSYGV
#define DSYTD2 GALAHAD_DSYTD2
#define DSYTF2 GALAHAD_DSYTF2
#define DSYTRD GALAHAD_DSYTRD
#define DSYTRF GALAHAD_DSYTRF
#define DSYTRS GALAHAD_DSYTRS
#define DTREXC GALAHAD_DTREXC
#define DTRTRS GALAHAD_DTRTRS
#define DTZRZF GALAHAD_DTZRZF
#define SBDSQR GALAHAD_SBDSQR
#define SCOMBS GALAHAD_SCOMBS
#define SGEBD2 GALAHAD_SGEBD2
#define SGEBRD GALAHAD_SGEBRD
#define SGEHD2 GALAHAD_SGEHD2
#define SGEHRD GALAHAD_SGEHRD
#define SGELQ2 GALAHAD_SGELQ2
#define SGELQF GALAHAD_SGELQF
#define SGELS  GALAHAD_SGELS
#define SGELSD GALAHAD_SGELSD
#define SGELSS GALAHAD_SGELSS
#define SGELSY GALAHAD_SGELSY
#define SGEQP3 GALAHAD_SGEQP3
#define SGEQR2 GALAHAD_SGEQR2
#define SGEQRF GALAHAD_SGEQRF
#define SGESVD GALAHAD_SGESVD
#define SGETF2 GALAHAD_SGETF2
#define SGETRF GALAHAD_SGETRF
#define SGETRF GALAHAD_SGETRF
#define SGETRS GALAHAD_SGETRS
#define SHSEQR GALAHAD_SHSEQR
#define SLABAD GALAHAD_SLABAD
#define SLABRD GALAHAD_SLABRD
#define SLACPY GALAHAD_SLACPY
#define SLAE2  GALAHAD_SLAE2
#define SLAED6 GALAHAD_SLAED6
#define SLAEV2 GALAHAD_SLAEV2
#define SLAEXC GALAHAD_SLAEXC
#define SLAHQR GALAHAD_SLAHQR
#define SLAHR2 GALAHAD_SLAHR2
#define SLAIC1 GALAHAD_SLAIC1
#define SLALS0 GALAHAD_SLALS0
#define SLALSA GALAHAD_SLALSA
#define SLALSD GALAHAD_SLALSD
#define SLAMRG GALAHAD_SLAMRG
#define SLANV2 GALAHAD_SLANV2
#define SLAQP2 GALAHAD_SLAQP2
#define SLAQPS GALAHAD_SLAQPS
#define SLAQR0 GALAHAD_SLAQR0
#define SLAQR1 GALAHAD_SLAQR1
#define SLAQR2 GALAHAD_SLAQR2
#define SLAQR3 GALAHAD_SLAQR3
#define SLAQR4 GALAHAD_SLAQR4
#define SLAQR5 GALAHAD_SLAQR5
#define SLARF  GALAHAD_SLARF
#define SLARFB GALAHAD_SLARFB
#define SLARFG GALAHAD_SLARFG
#define SLARFT GALAHAD_SLARFT
#define SLARFX GALAHAD_SLARFX
#define SLARTG GALAHAD_SLARTG
#define SLARZ  GALAHAD_SLARZ
#define SLARZB GALAHAD_SLARZB
#define SLARZT GALAHAD_SLARZT
#define SLAS2  GALAHAD_SLAS2
#define SLASCL GALAHAD_SLASCL
#define SLASD4 GALAHAD_SLASD4
#define SLASD5 GALAHAD_SLASD5
#define SLASD6 GALAHAD_SLASD6
#define SLASD7 GALAHAD_SLASD7
#define SLASD8 GALAHAD_SLASD8
#define SLASDA GALAHAD_SLASDA
#define SLASDQ GALAHAD_SLASDQ
#define SLASDT GALAHAD_SLASDT
#define SLASET GALAHAD_SLASET
#define SLASQ1 GALAHAD_SLASQ1
#define SLASQ2 GALAHAD_SLASQ2
#define SLASQ3 GALAHAD_SLASQ3
#define SLASQ4 GALAHAD_SLASQ4
#define SLASQ5 GALAHAD_SLASQ5
#define SLASQ6 GALAHAD_SLASQ6
#define SLASR  GALAHAD_SLASR
#define SLASRT GALAHAD_SLASRT
#define SLASSQ GALAHAD_SLASSQ
#define SLASV2 GALAHAD_SLASV2
#define SLASWP GALAHAD_SLASWP
#define SLASY2 GALAHAD_SLASY2
#define SLASYF GALAHAD_SLASYF
#define SLATRD GALAHAD_SLATRD
#define SLATRZ GALAHAD_SLATRZ
#define SORG2L GALAHAD_SORG2L
#define SORG2R GALAHAD_SORG2R
#define SORGBR GALAHAD_SORGBR
#define SORGL2 GALAHAD_SORGL2
#define SORGLQ GALAHAD_SORGLQ
#define SORGQL GALAHAD_SORGQL
#define SORGQR GALAHAD_SORGQR
#define SORGTR GALAHAD_SORGTR
#define SORM2R GALAHAD_SORM2R
#define SORMBR GALAHAD_SORMBR
#define SORMHR GALAHAD_SORMHR
#define SORML2 GALAHAD_SORML2
#define SORMLQ GALAHAD_SORMLQ
#define SORMQR GALAHAD_SORMQR
#define SORMR3 GALAHAD_SORMR3
#define SORMRZ GALAHAD_SORMRZ
#define SPBTF2 GALAHAD_SPBTF2
#define SPBTRF GALAHAD_SPBTRF
#define SPBTRS GALAHAD_SPBTRS
#define SPOTF2 GALAHAD_SPOTF2
#define SPOTRF GALAHAD_SPOTRF
#define SPOTRF GALAHAD_SPOTRF
#define SPOTRS GALAHAD_SPOTRS
#define SPTTRF GALAHAD_SPTTRF
#define SPTTRS GALAHAD_SPTTRS
#define SPTTS2 GALAHAD_SPTTS2
#define SRSCL  GALAHAD_SRSCL
#define SSTEQR GALAHAD_SSTEQR
#define SSTERF GALAHAD_SSTERF
#define SSYEV  GALAHAD_SSYEV
#define SSYGS2 GALAHAD_SSYGS2
#define SSYGST GALAHAD_SSYGST
#define SSYGV  GALAHAD_SSYGV
#define SSYTD2 GALAHAD_SSYTD2
#define SSYTF2 GALAHAD_SSYTF2
#define SSYTRD GALAHAD_SSYTRD
#define SSYTRF GALAHAD_SSYTRF
#define SSYTRS GALAHAD_SSYTRS
#define STREXC GALAHAD_STREXC
#define STRTRS GALAHAD_STRTRS
#define STZRZF GALAHAD_STZRZF
#define ZLACGV GALAHAD_ZLACGV
#define ZLARF  GALAHAD_ZLARF
#define ZLARFB GALAHAD_ZLARFB
#define ZLARFG GALAHAD_ZLARFG
#define ZLARFT GALAHAD_ZLARFT
#endif
#else
#ifdef INTEGER_64
#ifdef NO_UNDERSCORE_INTEGER_64
#define DISNAN DISNAN64
#define DLADIV DLADIV64
#define DLAISN DLAISN64
#define DLAMCH DLAMCH64
#define DLAMC3 DLAMC364
#define DLANGE DLANGE64
#define DLANST DLANST64
#define DLANSY DLANSY64
#define DLAPY2 DLAPY264
#define DLAPY3 DLAPY364
#define ILADLC ILADLC64
#define ILADLR ILADLR64
#define ILAENV ILAENV64
#define ILASLC ILASLC64
#define ILASLR ILASLR64
#define ILAZLC ILAZLC64
#define ILAZLR ILAZLR64
#define IPARMQ IPARMQ64
#define SISNAN SISNAN64
#define SLAISN SLAISN64
#define SLAMCH SLAMCH64
#define SLAMC3 SLAMC364
#define SLANGE SLANGE64
#define SLANST SLANST64
#define SLANSY SLANSY64
#define SLAPY2 SLAPY264
#define DBDSQR DBDSQR64
#define DCOMBS DCOMBS64
#define DGEBD2 DGEBD264
#define DGEBRD DGEBRD64
#define DGEHD2 DGEHD264
#define DGEHRD DGEHRD64
#define DGELQ2 DGELQ264
#define DGELQF DGELQF64
#define DGELS  DGELS64
#define DGELSD DGELSD64
#define DGELSS DGELSS64
#define DGELSY DGELSY64
#define DGEQP3 DGEQP364
#define DGEQR2 DGEQR264
#define DGEQRF DGEQRF64
#define DGESVD DGESVD64
#define DGETF2 DGETF264
#define DGETRF DGETRF64
#define DGETRF DGETRF64
#define DGETRS DGETRS64
#define DHSEQR DHSEQR64
#define DLABAD DLABAD64
#define DLABRD DLABRD64
#define DLACPY DLACPY64
#define DLADIV DLADIV64
#define DLADIV DLADIV64
#define DLAE2  DLAE264
#define DLAED6 DLAED664
#define DLAEV2 DLAEV264
#define DLAEXC DLAEXC64
#define DLAHQR DLAHQR64
#define DLAHR2 DLAHR264
#define DLAIC1 DLAIC164
#define DLALS0 DLALS064
#define DLALSA DLALSA64
#define DLALSD DLALSD64
#define DLAMRG DLAMRG64
#define DLANV2 DLANV264
#define DLAQP2 DLAQP264
#define DLAQPS DLAQPS64
#define DLAQR0 DLAQR064
#define DLAQR1 DLAQR164
#define DLAQR2 DLAQR264
#define DLAQR3 DLAQR364
#define DLAQR4 DLAQR464
#define DLAQR5 DLAQR564
#define DLARF  DLARF64
#define DLARFB DLARFB64
#define DLARFG DLARFG64
#define DLARFT DLARFT64
#define DLARFX DLARFX64
#define DLARTG DLARTG64
#define DLARZ  DLARZ64
#define DLARZB DLARZB64
#define DLARZT DLARZT64
#define DLAS2  DLAS264
#define DLASCL DLASCL64
#define DLASD4 DLASD464
#define DLASD5 DLASD564
#define DLASD6 DLASD664
#define DLASD7 DLASD764
#define DLASD8 DLASD864
#define DLASDA DLASDA64
#define DLASDQ DLASDQ64
#define DLASDT DLASDT64
#define DLASET DLASET64
#define DLASQ1 DLASQ164
#define DLASQ2 DLASQ264
#define DLASQ3 DLASQ364
#define DLASQ4 DLASQ464
#define DLASQ5 DLASQ564
#define DLASQ6 DLASQ664
#define DLASR  DLASR64
#define DLASRT DLASRT64
#define DLASSQ DLASSQ64
#define DLASV2 DLASV264
#define DLASWP DLASWP64
#define DLASY2 DLASY264
#define DLASYF DLASYF64
#define DLATRD DLATRD64
#define DLATRZ DLATRZ64
#define DORG2L DORG2L64
#define DORG2R DORG2R64
#define DORGBR DORGBR64
#define DORGL2 DORGL264
#define DORGLQ DORGLQ64
#define DORGQL DORGQL64
#define DORGQR DORGQR64
#define DORGTR DORGTR64
#define DORM2R DORM2R64
#define DORMBR DORMBR64
#define DORMHR DORMHR64
#define DORML2 DORML264
#define DORMLQ DORMLQ64
#define DORMQR DORMQR64
#define DORMR3 DORMR364
#define DORMRZ DORMRZ64
#define DPBTF2 DPBTF264
#define DPBTRF DPBTRF64
#define DPBTRS DPBTRS64
#define DPOTF2 DPOTF264
#define DPOTRF DPOTRF64
#define DPOTRF DPOTRF64
#define DPOTRS DPOTRS64
#define DPTTRF DPTTRF64
#define DPTTRS DPTTRS64
#define DPTTS2 DPTTS264
#define DRSCL  DRSCL64
#define DSTEQR DSTEQR64
#define DSTERF DSTERF64
#define DSYEV  DSYEV64
#define DSYGS2 DSYGS264
#define DSYGST DSYGST64
#define DSYGV  DSYGV64
#define DSYTD2 DSYTD264
#define DSYTF2 DSYTF264
#define DSYTRD DSYTRD64
#define DSYTRF DSYTRF64
#define DSYTRS DSYTRS64
#define DTREXC DTREXC64
#define DTRTRS DTRTRS64
#define DTZRZF DTZRZF64
#define SBDSQR SBDSQR64
#define SCOMBS SCOMBS64
#define SGEBD2 SGEBD264
#define SGEBRD SGEBRD64
#define SGEHD2 SGEHD264
#define SGEHRD SGEHRD64
#define SGELQ2 SGELQ264
#define SGELQF SGELQF64
#define SGELS  SGELS64
#define SGELSD SGELSD64
#define SGELSS SGELSS64
#define SGELSY SGELSY64
#define SGEQP3 SGEQP364
#define SGEQR2 SGEQR264
#define SGEQRF SGEQRF64
#define SGESVD SGESVD64
#define SGETF2 SGETF264
#define SGETRF SGETRF64
#define SGETRF SGETRF64
#define SGETRS SGETRS64
#define SHSEQR SHSEQR64
#define SLABAD SLABAD64
#define SLABRD SLABRD64
#define SLACPY SLACPY64
#define SLAE2  SLAE264
#define SLAED6 SLAED664
#define SLAEV2 SLAEV264
#define SLAEXC SLAEXC64
#define SLAHQR SLAHQR64
#define SLAHR2 SLAHR264
#define SLAIC1 SLAIC164
#define SLALS0 SLALS064
#define SLALSA SLALSA64
#define SLALSD SLALSD64
#define SLAMRG SLAMRG64
#define SLANV2 SLANV264
#define SLAQP2 SLAQP264
#define SLAQPS SLAQPS64
#define SLAQR0 SLAQR064
#define SLAQR1 SLAQR164
#define SLAQR2 SLAQR264
#define SLAQR3 SLAQR364
#define SLAQR4 SLAQR464
#define SLAQR5 SLAQR564
#define SLARF  SLARF64
#define SLARFB SLARFB64
#define SLARFG SLARFG64
#define SLARFT SLARFT64
#define SLARFX SLARFX64
#define SLARTG SLARTG64
#define SLARZ  SLARZ64
#define SLARZB SLARZB64
#define SLARZT SLARZT64
#define SLAS2  SLAS264
#define SLASCL SLASCL64
#define SLASD4 SLASD464
#define SLASD5 SLASD564
#define SLASD6 SLASD664
#define SLASD7 SLASD764
#define SLASD8 SLASD864
#define SLASDA SLASDA64
#define SLASDQ SLASDQ64
#define SLASDT SLASDT64
#define SLASET SLASET64
#define SLASQ1 SLASQ164
#define SLASQ2 SLASQ264
#define SLASQ3 SLASQ364
#define SLASQ4 SLASQ464
#define SLASQ5 SLASQ564
#define SLASQ6 SLASQ664
#define SLASR  SLASR64
#define SLASRT SLASRT64
#define SLASSQ SLASSQ64
#define SLASV2 SLASV264
#define SLASWP SLASWP64
#define SLASY2 SLASY264
#define SLASYF SLASYF64
#define SLATRD SLATRD64
#define SLATRZ SLATRZ64
#define SORG2L SORG2L64
#define SORG2R SORG2R64
#define SORGBR SORGBR64
#define SORGL2 SORGL264
#define SORGLQ SORGLQ64
#define SORGQL SORGQL64
#define SORGQR SORGQR64
#define SORGTR SORGTR64
#define SORM2R SORM2R64
#define SORMBR SORMBR64
#define SORMHR SORMHR64
#define SORML2 SORML264
#define SORMLQ SORMLQ64
#define SORMQR SORMQR64
#define SORMR3 SORMR364
#define SORMRZ SORMRZ64
#define SPBTF2 SPBTF264
#define SPBTRF SPBTRF64
#define SPBTRS SPBTRS64
#define SPOTF2 SPOTF264
#define SPOTRF SPOTRF64
#define SPOTRF SPOTRF64
#define SPOTRS SPOTRS64
#define SPTTRF SPTTRF64
#define SPTTRS SPTTRS64
#define SPTTS2 SPTTS264
#define SRSCL  SRSCL64
#define SSTEQR SSTEQR64
#define SSTERF SSTERF64
#define SSYEV  SSYEV64
#define SSYGS2 SSYGS264
#define SSYGST SSYGST64
#define SSYGV  SSYGV64
#define SSYTD2 SSYTD264
#define SSYTF2 SSYTF264
#define SSYTRD SSYTRD64
#define SSYTRF SSYTRF64
#define SSYTRS SSYTRS64
#define STREXC STREXC64
#define STRTRS STRTRS64
#define STZRZF STZRZF64
#define ZLACGV ZLACGV64
#define ZLARF  ZLARF64
#define ZLARFB ZLARFB64
#define ZLARFG ZLARFG64
#define ZLARFT ZLARFT64
#elif DOUBLE_UNDERSCORE_INTEGER_64
#define DISNAN DISNAN__64
#define DLADIV DLADIV__64
#define DLAISN DLAISN__64
#define DLAMCH DLAMCH__64
#define DLAMC3 DLAMC3__64
#define DLANGE DLANGE__64
#define DLANST DLANST__64
#define DLANSY DLANSY__64
#define DLAPY2 DLAPY2__64
#define DLAPY3 DLAPY3__64
#define ILADLC ILADLC__64
#define ILADLR ILADLR__64
#define ILAENV ILAENV__64
#define ILASLC ILASLC__64
#define ILASLR ILASLR__64
#define ILAZLC ILAZLC__64
#define ILAZLR ILAZLR__64
#define IPARMQ IPARMQ__64
#define SISNAN SISNAN__64
#define SLAISN SLAISN__64
#define SLAMCH SLAMCH__64
#define SLAMC3 SLAMC3__64
#define SLANGE SLANGE__64
#define SLANST SLANST__64
#define SLANSY SLANSY__64
#define SLAPY2 SLAPY2__64
#define DBDSQR DBDSQR__64
#define DCOMBS DCOMBS__64
#define DGEBD2 DGEBD2__64
#define DGEBRD DGEBRD__64
#define DGEHD2 DGEHD2__64
#define DGEHRD DGEHRD__64
#define DGELQ2 DGELQ2__64
#define DGELQF DGELQF__64
#define DGELS  DGELS__64
#define DGELSD DGELSD__64
#define DGELSS DGELSS__64
#define DGELSY DGELSY__64
#define DGEQP3 DGEQP3__64
#define DGEQR2 DGEQR2__64
#define DGEQRF DGEQRF__64
#define DGESVD DGESVD__64
#define DGETF2 DGETF2__64
#define DGETRF DGETRF__64
#define DGETRF DGETRF__64
#define DGETRS DGETRS__64
#define DHSEQR DHSEQR__64
#define DLABAD DLABAD__64
#define DLABRD DLABRD__64
#define DLACPY DLACPY__64
#define DLADIV DLADIV__64
#define DLADIV DLADIV__64
#define DLAE2  DLAE2__64
#define DLAED6 DLAED6__64
#define DLAEV2 DLAEV2__64
#define DLAEXC DLAEXC__64
#define DLAHQR DLAHQR__64
#define DLAHR2 DLAHR2__64
#define DLAIC1 DLAIC1__64
#define DLALS0 DLALS0__64
#define DLALSA DLALSA__64
#define DLALSD DLALSD__64
#define DLAMRG DLAMRG__64
#define DLANV2 DLANV2__64
#define DLAQP2 DLAQP2__64
#define DLAQPS DLAQPS__64
#define DLAQR0 DLAQR0__64
#define DLAQR1 DLAQR1__64
#define DLAQR2 DLAQR2__64
#define DLAQR3 DLAQR3__64
#define DLAQR4 DLAQR4__64
#define DLAQR5 DLAQR5__64
#define DLARF  DLARF__64
#define DLARFB DLARFB__64
#define DLARFG DLARFG__64
#define DLARFT DLARFT__64
#define DLARFX DLARFX__64
#define DLARTG DLARTG__64
#define DLARZ  DLARZ__64
#define DLARZB DLARZB__64
#define DLARZT DLARZT__64
#define DLAS2  DLAS2__64
#define DLASCL DLASCL__64
#define DLASD4 DLASD4__64
#define DLASD5 DLASD5__64
#define DLASD6 DLASD6__64
#define DLASD7 DLASD7__64
#define DLASD8 DLASD8__64
#define DLASDA DLASDA__64
#define DLASDQ DLASDQ__64
#define DLASDT DLASDT__64
#define DLASET DLASET__64
#define DLASQ1 DLASQ1__64
#define DLASQ2 DLASQ2__64
#define DLASQ3 DLASQ3__64
#define DLASQ4 DLASQ4__64
#define DLASQ5 DLASQ5__64
#define DLASQ6 DLASQ6__64
#define DLASR  DLASR__64
#define DLASRT DLASRT__64
#define DLASSQ DLASSQ__64
#define DLASV2 DLASV2__64
#define DLASWP DLASWP__64
#define DLASY2 DLASY2__64
#define DLASYF DLASYF__64
#define DLATRD DLATRD__64
#define DLATRZ DLATRZ__64
#define DORG2L DORG2L__64
#define DORG2R DORG2R__64
#define DORGBR DORGBR__64
#define DORGL2 DORGL2__64
#define DORGLQ DORGLQ__64
#define DORGQL DORGQL__64
#define DORGQR DORGQR__64
#define DORGTR DORGTR__64
#define DORM2R DORM2R__64
#define DORMBR DORMBR__64
#define DORMHR DORMHR__64
#define DORML2 DORML2__64
#define DORMLQ DORMLQ__64
#define DORMQR DORMQR__64
#define DORMR3 DORMR3__64
#define DORMRZ DORMRZ__64
#define DPBTF2 DPBTF2__64
#define DPBTRF DPBTRF__64
#define DPBTRS DPBTRS__64
#define DPOTF2 DPOTF2__64
#define DPOTRF DPOTRF__64
#define DPOTRF DPOTRF__64
#define DPOTRS DPOTRS__64
#define DPTTRF DPTTRF__64
#define DPTTRS DPTTRS__64
#define DPTTS2 DPTTS2__64
#define DRSCL  DRSCL__64
#define DSTEQR DSTEQR__64
#define DSTERF DSTERF__64
#define DSYEV  DSYEV__64
#define DSYGS2 DSYGS2__64
#define DSYGST DSYGST__64
#define DSYGV  DSYGV__64
#define DSYTD2 DSYTD2__64
#define DSYTF2 DSYTF2__64
#define DSYTRD DSYTRD__64
#define DSYTRF DSYTRF__64
#define DSYTRS DSYTRS__64
#define DTREXC DTREXC__64
#define DTRTRS DTRTRS__64
#define DTZRZF DTZRZF__64
#define SBDSQR SBDSQR__64
#define SCOMBS SCOMBS__64
#define SGEBD2 SGEBD2__64
#define SGEBRD SGEBRD__64
#define SGEHD2 SGEHD2__64
#define SGEHRD SGEHRD__64
#define SGELQ2 SGELQ2__64
#define SGELQF SGELQF__64
#define SGELS  SGELS__64
#define SGELSD SGELSD__64
#define SGELSS SGELSS__64
#define SGELSY SGELSY__64
#define SGEQP3 SGEQP3__64
#define SGEQR2 SGEQR2__64
#define SGEQRF SGEQRF__64
#define SGESVD SGESVD__64
#define SGETF2 SGETF2__64
#define SGETRF SGETRF__64
#define SGETRF SGETRF__64
#define SGETRS SGETRS__64
#define SHSEQR SHSEQR__64
#define SLABAD SLABAD__64
#define SLABRD SLABRD__64
#define SLACPY SLACPY__64
#define SLAE2  SLAE2__64
#define SLAED6 SLAED6__64
#define SLAEV2 SLAEV2__64
#define SLAEXC SLAEXC__64
#define SLAHQR SLAHQR__64
#define SLAHR2 SLAHR2__64
#define SLAIC1 SLAIC1__64
#define SLALS0 SLALS0__64
#define SLALSA SLALSA__64
#define SLALSD SLALSD__64
#define SLAMRG SLAMRG__64
#define SLANV2 SLANV2__64
#define SLAQP2 SLAQP2__64
#define SLAQPS SLAQPS__64
#define SLAQR0 SLAQR0__64
#define SLAQR1 SLAQR1__64
#define SLAQR2 SLAQR2__64
#define SLAQR3 SLAQR3__64
#define SLAQR4 SLAQR4__64
#define SLAQR5 SLAQR5__64
#define SLARF  SLARF__64
#define SLARFB SLARFB__64
#define SLARFG SLARFG__64
#define SLARFT SLARFT__64
#define SLARFX SLARFX__64
#define SLARTG SLARTG__64
#define SLARZ  SLARZ__64
#define SLARZB SLARZB__64
#define SLARZT SLARZT__64
#define SLAS2  SLAS2__64
#define SLASCL SLASCL__64
#define SLASD4 SLASD4__64
#define SLASD5 SLASD5__64
#define SLASD6 SLASD6__64
#define SLASD7 SLASD7__64
#define SLASD8 SLASD8__64
#define SLASDA SLASDA__64
#define SLASDQ SLASDQ__64
#define SLASDT SLASDT__64
#define SLASET SLASET__64
#define SLASQ1 SLASQ1__64
#define SLASQ2 SLASQ2__64
#define SLASQ3 SLASQ3__64
#define SLASQ4 SLASQ4__64
#define SLASQ5 SLASQ5__64
#define SLASQ6 SLASQ6__64
#define SLASR  SLASR__64
#define SLASRT SLASRT__64
#define SLASSQ SLASSQ__64
#define SLASV2 SLASV2__64
#define SLASWP SLASWP__64
#define SLASY2 SLASY2__64
#define SLASYF SLASYF__64
#define SLATRD SLATRD__64
#define SLATRZ SLATRZ__64
#define SORG2L SORG2L__64
#define SORG2R SORG2R__64
#define SORGBR SORGBR__64
#define SORGL2 SORGL2__64
#define SORGLQ SORGLQ__64
#define SORGQL SORGQL__64
#define SORGQR SORGQR__64
#define SORGTR SORGTR__64
#define SORM2R SORM2R__64
#define SORMBR SORMBR__64
#define SORMHR SORMHR__64
#define SORML2 SORML2__64
#define SORMLQ SORMLQ__64
#define SORMQR SORMQR__64
#define SORMR3 SORMR3__64
#define SORMRZ SORMRZ__64
#define SPBTF2 SPBTF2__64
#define SPBTRF SPBTRF__64
#define SPBTRS SPBTRS__64
#define SPOTF2 SPOTF2__64
#define SPOTRF SPOTRF__64
#define SPOTRF SPOTRF__64
#define SPOTRS SPOTRS__64
#define SPTTRF SPTTRF__64
#define SPTTRS SPTTRS__64
#define SPTTS2 SPTTS2__64
#define SRSCL  SRSCL__64
#define SSTEQR SSTEQR__64
#define SSTERF SSTERF__64
#define SSYEV  SSYEV__64
#define SSYGS2 SSYGS2__64
#define SSYGST SSYGST__64
#define SSYGV  SSYGV__64
#define SSYTD2 SSYTD2__64
#define SSYTF2 SSYTF2__64
#define SSYTRD SSYTRD__64
#define SSYTRF SSYTRF__64
#define SSYTRS SSYTRS__64
#define STREXC STREXC__64
#define STRTRS STRTRS__64
#define STZRZF STZRZF__64
#define ZLACGV ZLACGV__64
#define ZLARF  ZLARF__64
#define ZLARFB ZLARFB__64
#define ZLARFG ZLARFG__64
#define ZLARFT ZLARFT__64
#elif NO_SYMBOL_INTEGER_64
#else
#define DISNAN DISNAN_64
#define DLADIV DLADIV_64
#define DLAISN DLAISN_64
#define DLAMCH DLAMCH_64
#define DLAMC3 DLAMC3_64
#define DLANGE DLANGE_64
#define DLANST DLANST_64
#define DLANSY DLANSY_64
#define DLAPY2 DLAPY2_64
#define DLAPY3 DLAPY3_64
#define ILADLC ILADLC_64
#define ILADLR ILADLR_64
#define ILAENV ILAENV_64
#define ILASLC ILASLC_64
#define ILASLR ILASLR_64
#define ILAZLC ILAZLC_64
#define ILAZLR ILAZLR_64
#define IPARMQ IPARMQ_64
#define SISNAN SISNAN_64
#define SLAISN SLAISN_64
#define SLAMCH SLAMCH_64
#define SLAMC3 SLAMC3_64
#define SLANGE SLANGE_64
#define SLANST SLANST_64
#define SLANSY SLANSY_64
#define SLAPY2 SLAPY2_64
#define DBDSQR DBDSQR_64
#define DCOMBS DCOMBS_64
#define DGEBD2 DGEBD2_64
#define DGEBRD DGEBRD_64
#define DGEHD2 DGEHD2_64
#define DGEHRD DGEHRD_64
#define DGELQ2 DGELQ2_64
#define DGELQF DGELQF_64
#define DGELS  DGELS_64
#define DGELSD DGELSD_64
#define DGELSS DGELSS_64
#define DGELSY DGELSY_64
#define DGEQP3 DGEQP3_64
#define DGEQR2 DGEQR2_64
#define DGEQRF DGEQRF_64
#define DGESVD DGESVD_64
#define DGETF2 DGETF2_64
#define DGETRF DGETRF_64
#define DGETRF DGETRF_64
#define DGETRS DGETRS_64
#define DHSEQR DHSEQR_64
#define DLABAD DLABAD_64
#define DLABRD DLABRD_64
#define DLACPY DLACPY_64
#define DLADIV DLADIV_64
#define DLADIV DLADIV_64
#define DLAE2  DLAE2_64
#define DLAED6 DLAED6_64
#define DLAEV2 DLAEV2_64
#define DLAEXC DLAEXC_64
#define DLAHQR DLAHQR_64
#define DLAHR2 DLAHR2_64
#define DLAIC1 DLAIC1_64
#define DLALS0 DLALS0_64
#define DLALSA DLALSA_64
#define DLALSD DLALSD_64
#define DLAMRG DLAMRG_64
#define DLANV2 DLANV2_64
#define DLAQP2 DLAQP2_64
#define DLAQPS DLAQPS_64
#define DLAQR0 DLAQR0_64
#define DLAQR1 DLAQR1_64
#define DLAQR2 DLAQR2_64
#define DLAQR3 DLAQR3_64
#define DLAQR4 DLAQR4_64
#define DLAQR5 DLAQR5_64
#define DLARF  DLARF_64
#define DLARFB DLARFB_64
#define DLARFG DLARFG_64
#define DLARFT DLARFT_64
#define DLARFX DLARFX_64
#define DLARTG DLARTG_64
#define DLARZ  DLARZ_64
#define DLARZB DLARZB_64
#define DLARZT DLARZT_64
#define DLAS2  DLAS2_64
#define DLASCL DLASCL_64
#define DLASD4 DLASD4_64
#define DLASD5 DLASD5_64
#define DLASD6 DLASD6_64
#define DLASD7 DLASD7_64
#define DLASD8 DLASD8_64
#define DLASDA DLASDA_64
#define DLASDQ DLASDQ_64
#define DLASDT DLASDT_64
#define DLASET DLASET_64
#define DLASQ1 DLASQ1_64
#define DLASQ2 DLASQ2_64
#define DLASQ3 DLASQ3_64
#define DLASQ4 DLASQ4_64
#define DLASQ5 DLASQ5_64
#define DLASQ6 DLASQ6_64
#define DLASR  DLASR_64
#define DLASRT DLASRT_64
#define DLASSQ DLASSQ_64
#define DLASV2 DLASV2_64
#define DLASWP DLASWP_64
#define DLASY2 DLASY2_64
#define DLASYF DLASYF_64
#define DLATRD DLATRD_64
#define DLATRZ DLATRZ_64
#define DORG2L DORG2L_64
#define DORG2R DORG2R_64
#define DORGBR DORGBR_64
#define DORGL2 DORGL2_64
#define DORGLQ DORGLQ_64
#define DORGQL DORGQL_64
#define DORGQR DORGQR_64
#define DORGTR DORGTR_64
#define DORM2R DORM2R_64
#define DORMBR DORMBR_64
#define DORMHR DORMHR_64
#define DORML2 DORML2_64
#define DORMLQ DORMLQ_64
#define DORMQR DORMQR_64
#define DORMR3 DORMR3_64
#define DORMRZ DORMRZ_64
#define DPBTF2 DPBTF2_64
#define DPBTRF DPBTRF_64
#define DPBTRS DPBTRS_64
#define DPOTF2 DPOTF2_64
#define DPOTRF DPOTRF_64
#define DPOTRF DPOTRF_64
#define DPOTRS DPOTRS_64
#define DPTTRF DPTTRF_64
#define DPTTRS DPTTRS_64
#define DPTTS2 DPTTS2_64
#define DRSCL  DRSCL_64
#define DSTEQR DSTEQR_64
#define DSTERF DSTERF_64
#define DSYEV  DSYEV_64
#define DSYGS2 DSYGS2_64
#define DSYGST DSYGST_64
#define DSYGV  DSYGV_64
#define DSYTD2 DSYTD2_64
#define DSYTF2 DSYTF2_64
#define DSYTRD DSYTRD_64
#define DSYTRF DSYTRF_64
#define DSYTRS DSYTRS_64
#define DTREXC DTREXC_64
#define DTRTRS DTRTRS_64
#define DTZRZF DTZRZF_64
#define SBDSQR SBDSQR_64
#define SCOMBS SCOMBS_64
#define SGEBD2 SGEBD2_64
#define SGEBRD SGEBRD_64
#define SGEHD2 SGEHD2_64
#define SGEHRD SGEHRD_64
#define SGELQ2 SGELQ2_64
#define SGELQF SGELQF_64
#define SGELS  SGELS_64
#define SGELSD SGELSD_64
#define SGELSS SGELSS_64
#define SGELSY SGELSY_64
#define SGEQP3 SGEQP3_64
#define SGEQR2 SGEQR2_64
#define SGEQRF SGEQRF_64
#define SGESVD SGESVD_64
#define SGETF2 SGETF2_64
#define SGETRF SGETRF_64
#define SGETRF SGETRF_64
#define SGETRS SGETRS_64
#define SHSEQR SHSEQR_64
#define SLABAD SLABAD_64
#define SLABRD SLABRD_64
#define SLACPY SLACPY_64
#define SLAE2  SLAE2_64
#define SLAED6 SLAED6_64
#define SLAEV2 SLAEV2_64
#define SLAEXC SLAEXC_64
#define SLAHQR SLAHQR_64
#define SLAHR2 SLAHR2_64
#define SLAIC1 SLAIC1_64
#define SLALS0 SLALS0_64
#define SLALSA SLALSA_64
#define SLALSD SLALSD_64
#define SLAMRG SLAMRG_64
#define SLANV2 SLANV2_64
#define SLAQP2 SLAQP2_64
#define SLAQPS SLAQPS_64
#define SLAQR0 SLAQR0_64
#define SLAQR1 SLAQR1_64
#define SLAQR2 SLAQR2_64
#define SLAQR3 SLAQR3_64
#define SLAQR4 SLAQR4_64
#define SLAQR5 SLAQR5_64
#define SLARF  SLARF_64
#define SLARFB SLARFB_64
#define SLARFG SLARFG_64
#define SLARFT SLARFT_64
#define SLARFX SLARFX_64
#define SLARTG SLARTG_64
#define SLARZ  SLARZ_64
#define SLARZB SLARZB_64
#define SLARZT SLARZT_64
#define SLAS2  SLAS2_64
#define SLASCL SLASCL_64
#define SLASD4 SLASD4_64
#define SLASD5 SLASD5_64
#define SLASD6 SLASD6_64
#define SLASD7 SLASD7_64
#define SLASD8 SLASD8_64
#define SLASDA SLASDA_64
#define SLASDQ SLASDQ_64
#define SLASDT SLASDT_64
#define SLASET SLASET_64
#define SLASQ1 SLASQ1_64
#define SLASQ2 SLASQ2_64
#define SLASQ3 SLASQ3_64
#define SLASQ4 SLASQ4_64
#define SLASQ5 SLASQ5_64
#define SLASQ6 SLASQ6_64
#define SLASR  SLASR_64
#define SLASRT SLASRT_64
#define SLASSQ SLASSQ_64
#define SLASV2 SLASV2_64
#define SLASWP SLASWP_64
#define SLASY2 SLASY2_64
#define SLASYF SLASYF_64
#define SLATRD SLATRD_64
#define SLATRZ SLATRZ_64
#define SORG2L SORG2L_64
#define SORG2R SORG2R_64
#define SORGBR SORGBR_64
#define SORGL2 SORGL2_64
#define SORGLQ SORGLQ_64
#define SORGQL SORGQL_64
#define SORGQR SORGQR_64
#define SORGTR SORGTR_64
#define SORM2R SORM2R_64
#define SORMBR SORMBR_64
#define SORMHR SORMHR_64
#define SORML2 SORML2_64
#define SORMLQ SORMLQ_64
#define SORMQR SORMQR_64
#define SORMR3 SORMR3_64
#define SORMRZ SORMRZ_64
#define SPBTF2 SPBTF2_64
#define SPBTRF SPBTRF_64
#define SPBTRS SPBTRS_64
#define SPOTF2 SPOTF2_64
#define SPOTRF SPOTRF_64
#define SPOTRF SPOTRF_64
#define SPOTRS SPOTRS_64
#define SPTTRF SPTTRF_64
#define SPTTRS SPTTRS_64
#define SPTTS2 SPTTS2_64
#define SRSCL  SRSCL_64
#define SSTEQR SSTEQR_64
#define SSTERF SSTERF_64
#define SSYEV  SSYEV_64
#define SSYGS2 SSYGS2_64
#define SSYGST SSYGST_64
#define SSYGV  SSYGV_64
#define SSYTD2 SSYTD2_64
#define SSYTF2 SSYTF2_64
#define SSYTRD SSYTRD_64
#define SSYTRF SSYTRF_64
#define SSYTRS SSYTRS_64
#define STREXC STREXC_64
#define STRTRS STRTRS_64
#define STZRZF STZRZF_64
#define ZLACGV ZLACGV_64
#define ZLARF  ZLARF_64
#define ZLARFB ZLARFB_64
#define ZLARFG ZLARFG_64
#define ZLARFT ZLARFT_64
#endif
#endif
#endif
