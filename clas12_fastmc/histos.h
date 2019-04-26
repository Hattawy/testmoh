#include"root.h"

TObjArray Hlist(0);

//ACCEP

//1D plots (24)
//scat. e- ===========================================================
TH1D *hkp_acc       = new TH1D("hkp_acc",       "", 100,  0.0,  10.0);
TH1D *hThetakkp_acc = new TH1D("hThetakkp_acc", "", 100,  3.0,  50.0);
TH1D *hPhikkp_acc   = new TH1D("hPhikkp_acc",   "", 100, -5.0, 365.0);

//qp(real photon) wrt incident electron ==============================
TH1D *hqp_acc       = new TH1D("hqp_acc",       "", 100,  0.5,  12.0);
TH1D *hThetakqp_acc = new TH1D("hThetakqp_acc", "", 100, -0.5,  25.0);
TH1D *hPhikqp_acc   = new TH1D("hPhikqp_acc",   "", 100, -5.0, 365.0);

//qp(real photon) wrt virtual photon =================================
TH1D *hThetaqqp_acc = new TH1D("hThetaqqp_acc", "", 100, -0.5,  25.0);
TH1D *hPhiqqp_acc   = new TH1D("hPhiqqp_acc",   "", 100, -5.0, 365.0);

//recoil proton P'(E'p,P') wrt incident electron =====================
TH1D *hPp_acc       = new TH1D("hPp_acc",       "", 100, -0.1,   1.5);
TH1D *hThetakPp_acc = new TH1D("hThetakPp_acc", "", 100, -3.0,  80.0);
TH1D *hPhikPp_acc   = new TH1D("hPhikPp_acc",   "", 100, -5.0, 365.0);

//recoil proton P'(E'p,P') wrt virtual photon ========================
TH1D *hThetaqPp_acc = new TH1D("hThetaqPp_acc", "", 100, -3.0,  80.0);
TH1D *hPhiqPp_acc   = new TH1D("hPhiqPp_acc",   "", 100, -5.0, 365.0);

//angle between real photon and scattered electron ===================
TH1D *hThetakpqp_acc = new TH1D("hThetakpqp_acc", "", 100,  -2.5,  180.0);

//kinematics =========================================================
TH1D *hQ2_acc  = new TH1D("hQ2_acc",  "", 100,  0.00,  8.00);
TH1D *hW2_acc  = new TH1D("hW2_acc",  "", 100,  3.00, 21.00);
TH1D *hnu_acc  = new TH1D("hnu_acc",  "", 100,  1.00, 12.00);
TH1D *hXbj_acc = new TH1D("hXbj_acc", "", 100,  0.02,  0.60);
TH1D *hY_acc   = new TH1D("hY_acc",   "", 100,  0.15,  1.05);
TH1D *ht_acc   = new TH1D("ht_acc",   "", 100, -1.40,  0.10);

//xsection
TH1D *hBHxsec_acc   = new TH1D("hBHxsec_acc",   "", 100,  -8.0, 3.0);
TH1D *hDVCSxsec_acc = new TH1D("hDVCSxsec_acc", "", 100,  -8.0, 3.0);
TH1D *hINTxsec_acc  = new TH1D("hINTxsec_acc",  "", 100, -10.0, 3.0);
TH1D *hTOTxsec_acc  = new TH1D("hTOTxsec_acc",  "", 100,  -8.0, 3.0);


//2D plots (16)
TH2D *hQ2_xbj_acc = new TH2D("hQ2_xbj_acc", "", 300, 0.0,  0.8, 300,  0.2, 14.0);
TH2D *ht_Q2_acc   = new TH2D("ht_Q2_acc",   "", 300, 0.2, 14.0, 300, -1.4,  0.1);
TH2D *ht_xbj_acc  = new TH2D("ht_xbj_acc",  "", 300, 0.0,  0.8, 300, -1.4,  0.1);

TH2D *hkp_thetkkp_acc = new TH2D("hkp_thetkkp_acc", "", 300, 3.0, 50.0, 300, -0.15, 10.0);

TH2D *hqp_thetkqp_acc = new TH2D("hqp_thetkqp_acc", "", 300, -1.0, 45.0, 300,  0.5, 11.5);
TH2D *hqp_thetqqp_acc = new TH2D("hqp_thetqqp_acc", "", 300, -1.0, 30.0, 300,  0.5, 11.5);

TH2D *hPp_thetkPp_acc = new TH2D("hPp_thetkPp_acc", "", 300, -2.0, 75.0, 300, -0.1,  1.5);
TH2D *hPp_thetqPp_acc = new TH2D("hPp_thetqPp_acc", "", 300, -2.0, 75.0, 300, -0.1,  1.5);

TH2D *ht_thetkkp_acc  = new TH2D("ht_thetkkp_acc",  "", 300, -1.0, 45.0, 300, -1.4,  0.1);
TH2D *ht_kp_acc       = new TH2D("ht_kp_acc",       "", 300,  0.5, 11.5, 300, -1.4,  0.1);

TH2D *ht_thetkqp_acc  = new TH2D("ht_thetkqp_acc",  "", 300, -1.0, 45.0, 300, -1.4,  0.1);
TH2D *ht_thetqqp_acc  = new TH2D("ht_thetqqp_acc",  "", 300, -2.0, 80.0, 300, -1.4,  0.1);
TH2D *ht_qp_acc       = new TH2D("ht_qp_acc",       "", 300,  0.5, 11.5, 300, -1.4,  0.1);

TH2D *ht_thetkPp_acc  = new TH2D("ht_thetkPp_acc",  "", 300, -2.0, 75.0, 300, -1.4,  0.1);
TH2D *ht_thetqPp_acc  = new TH2D("ht_thetqPp_acc",  "", 300, -2.0, 75.0, 300, -1.4,  0.1);
TH2D *ht_Pp_acc       = new TH2D("ht_Pp_acc",       "", 300, -0.1,  1.5, 300, -1.4,  0.1);
