#define CLAS12

#define M_PROT  0.93827
#define M_NEUT  0.93957
#define M_PION  0.13957
#define M_KAON  0.49368
#define M_ELEC  0.5e-03
#define M_PHOT  0.0

#define M_PROT2  M_PROT*M_PROT
#define M_NEUT2  M_NEUT*M_NEUT
#define M_PION2  M_PION*M_PION
#define M_KAON2  M_KAON*M_KAON
#define M_ELEC2  M_ELEC*M_ELEC
#define M_PHOT2  M_PHOT*M_PHOT

#define ELEC_ID   11
#define PION_ID  211
#define PI0_ID   111
#define KAON_ID  321
#define KA0_ID   310
#define PROT_ID 2212
#define NEUT_ID 2112
#define PHOT_ID   22

#define PI       3.14159265
#define TORAD    0.01745
#define TODEG   57.299578
#define DAYTOSEC 86400

#define ALPHA    1./137.0359998
#define ALPHA3   ALPHA*ALPHA*ALPHA

#define HBARC    0.1973269602
#define HBARC2   HBARC*HBARC

#define TINY     1e-15

#ifdef CLAS6
#define MAXT    9
#define MAXQ2X 10
#define MAXQ2   6
#endif

#ifdef CLAS12
#define MAXT    6
#define MAXQ2X 12
#define MAXQ2   7
#endif

#define MAXX    8
#define MAXFE  12
#define MAXFG  12
#define MAXTH  29
#define MAXTH2  7
#define MAXPHI 12

#define CM2TONB       1e-33   //cm^-2 to nb^-1      
