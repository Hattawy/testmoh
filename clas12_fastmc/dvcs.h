//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Oct 20 10:47:21 2010 by ROOT version 5.21/04
// from TTree DVCS//dvcs_tree
// found on file: /projet/nucleon/Baptiste/genepi/neut_DVCS_Correct_ROOTFiles/ntup_neut_11.00gev_DVCS-Phi=0.0567-Theta=0.0186-P=0.0376.root
//////////////////////////////////////////////////////////

#ifndef dvcs_h
#define dvcs_h
#include <TH1.h>
#include <TH2.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

#include <string.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <math.h>
#include <limits>
#include <TVector3.h>
#include <TLorentzVector.h>

//°°°°°°°°°°°

#include "options.h" 

#include "constants.h"


#include "funcs.h"
#include "cpp.h"
#include "chain.h"

#include "conf.h" 
#include "root.h"

//°°°°°°°°°°°°°°°°°°°°
#include <stdio.h>
#include <TROOT.h>
#include <TChain.h>
#include <TTree.h>
#include <TVirtualIndex.h>
#include <TFile.h>
#include <TSelector.h>
#include <iostream>             // std::cout, std::endl
#include <fstream>              // std::ifstream
#include <sstream>
#include <TVector3.h>
#include <TLorentzVector.h>
#include <TSystem.h>
#include "TH2.h"
#include "TH3.h"
#include <TH1.h>


class dvcs : public TSelector {
public :
  TTree          *fChain;   //!pointer to the analyzed TTree or TChain
 TFile *outfile; 
   //Put here all definitions of constants, variables and output histograms

 TLorentzVector  VirtualPhoton,ElectronBeam, D_Target_Vec, N_Target_Vec,El_Vec, Neut_Vec, Ph1_Vec, Ph2_Vec, Ph_Vec; 

int    InBend, OutBend, Neutral, Fwd, Central;

int    fAcc; 
int    fWeight;
double fLumi;
double fTime;
int    fPlot;
int    fClas;

double fTheta_IC_min, fTheta_IC_max;
double fThkkpmin,     fThkkpmax;
double fThkPpmin,     fThkPpmax;  	// Changement: au lieu de [0;999], on met [12; 135] pour le detecteur de neutron BAPTISTE
double fThkqpmin,     fThkqpmax;
double fThkpqpmin,    fThkpqpmax;
double fQ2min,        fQ2max;
double fW2min,        fW2max;
double fTmin,         fTmax;
double fXbjmin,       fXbjmax;
double fYmin,         fYmax;
double fBHmin,        fBHmax;

int    fCnfg_num;
double fTTmax, fTor_Cur, fThf_lim;
double fThacc1, fThacc2,   fThacc3,   fThacc4;
double fThacc5,   fThacc6,   fThacc01;
double fThmom1,   fThmom2,   fThmom3,   fThmom4;
double fPhimom1,  fPhimom2,  fPhimom3,  fPhimom4,  fPhimom5;
double fFoMT1S1,  fFoMT1S2,  fFoMT1S3,  fFoMT2S1,  fFoMT2S2,  fFoMT2S3;
double fFoInMoS1, fFoInMoS2, fFoOuMoS1, fFoOuMoS2, fFoNeMoS1, fFoNeMoS2;
double fFoInThS1, fFoInThS2, fFoOuThS1, fFoOuThS2, fFoNeThS1, fFoNeThS2;
double fFoA0FiS1, fFoA1FiS1, fFoA2FiS1 , fFoA0FiS2, fFoA1FiS2, fFoA2FiS2;
double fFoNeFiS1, fFoNeFiS2, fCeInMoS1, fCeInMoS2, fCeOuMoS1, fCeOuMoS2;
double fCeNeMoS1, fCeNeMoS2, fCeA0ThS2, fCeA1ThS2, fCeA2ThS2, fCeInThS1;
double fCeInThS2, fCeOuThS1, fCeOuThS2, fCeNeThS1, fCeNeThS2, fCeInFiS1;
double fCeInFiS2, fCeOuFiS1, fCeOuFiS2, fCeNeFiS1, fCeNeFiS2;

int    Bin1_Nacc_evt, Bin2_Nacc_evt, Bin3_Nacc_evt, Bin4_Nacc_evt, Bin5_Nacc_evt, Bin6_Nacc_evt;
int    Bin7_Nacc_evt, Bin8_Nacc_evt, Bin9_Nacc_evt, Bin10_Nacc_evt, Bin11_Nacc_evt, Bin12_Nacc_evt;
double   Nacc_evt;
int    Nacc_evt_bin, Nacc_evt_bin_Other;
double    N_evt_tot;

int compteur;
int    Bin1_Nacc_evt_beforeAcc, Bin2_Nacc_evt_beforeAcc, Bin3_Nacc_evt_beforeAcc, Bin4_Nacc_evt_beforeAcc, Bin5_Nacc_evt_beforeAcc, Bin6_Nacc_evt_beforeAcc;
int    Bin7_Nacc_evt_beforeAcc, Bin8_Nacc_evt_beforeAcc, Bin9_Nacc_evt_beforeAcc, Bin10_Nacc_evt_beforeAcc, Bin11_Nacc_evt_beforeAcc, Bin12_Nacc_evt_beforeAcc;
int    Nacc_evt_bin_beforeAcc, Nacc_evt_bin_beforeAcc_Other;

double    Bin_xsec_beforeAcc[13];
double    Bin_xsec[13];

double wght;	

double Bin_Nacc_evt_beforeAcc[13];  
double Bin_Nacc_evt[13];

double Bin1_xsec_beforeAcc,	Bin2_xsec_beforeAcc, 	Bin3_xsec_beforeAcc, 	Bin4_xsec_beforeAcc, 	Bin5_xsec_beforeAcc, 	Bin6_xsec_beforeAcc;
double Bin7_xsec_beforeAcc, 	Bin8_xsec_beforeAcc, 	Bin9_xsec_beforeAcc, 	Bin10_xsec_beforeAcc, 	Bin11_xsec_beforeAcc, 	Bin12_xsec_beforeAcc;

double Bin1_xsec,	Bin2_xsec, 	Bin3_xsec, 	Bin4_xsec, 	Bin5_xsec, 	Bin6_xsec;
double Bin7_xsec, 	Bin8_xsec, 	Bin9_xsec, 	Bin10_xsec, 	Bin11_xsec, 	Bin12_xsec;

  Int_t NQ2,NXB,NT,NPHI;//Binning Silvia  
  Float_t q_vec[5];
  Float_t x_vec[5];
  Float_t t_vec[5];
/*
  Float_t q_vec[4];
  Float_t x_vec[4];
  Float_t t_vec[4];
*/
Float_t qmin,qmax,xmin,xmax,tmin,tmax,phimin,phimax;

  Float_t mm_ed_eng,mm_en_eng,miss_mom_ed_eng,miss_en_ed_eng,delta_theta,delta_phi,pperp;

  TH1D *h_mm_ed_eng;
  TH1D *h_mm_en_eng;
  TH1D *h_miss_mom_ed_eng;
  TH1D *h_miss_en_ed_eng;
  TH1D *h_delta_theta;
  TH1D *h_delta_phi;
  TH1D *h_pperp;

  TH1D *h_mm_ed_eng_now;
  TH1D *h_mm_en_eng_now;
  TH1D *h_miss_mom_ed_eng_now;
  TH1D *h_miss_en_ed_eng_now;
  TH1D *h_delta_theta_now;
  TH1D *h_delta_phi_now;
  TH1D *h_pperp_now;

double Xsec_integree;


   // example: TH1D *histo;
TH1D *H_Angle_e1_g;
TH1D *H_Angle_e2_g;
TH1D *Angle_plan_lep_had_Before_cut;

TH1D *Neutron_Momemtum_DVCS_Before_CUTs ;
TH1D *Neutron_Momemtum_BH_Before_CUTs;
TH1D *Neutron_Momemtum_TOT_Before_CUTs;

TH1D *Neutron_Momemtum_DVCS_After_CUTs;
TH1D *Neutron_Momemtum_BH_After_CUTs;
TH1D *Neutron_Momemtum_TOT_After_CUTs;

TH1D *H_ANGLE_Tan ;
TH1D *ANGLE_PHI ;
TH1D *ANGLE_PHI_LP ;
TH1D *h1;
TH1D *h12;

TH1D *Mon_Histo_avant_coupure;
TH1D *Mon_Histo_avant_coupure2;
TH1D *Mon_Histo_avant_coupure3;

TH1D *Mon_Histo_avant_coupure_SmearClas12;
TH1D *Mon_Histo_avant_coupure2_SmearClas12;
TH1D *Mon_Histo_avant_coupure3_SmearClas12;
TH1D *Mon_Histo_avant_coupure4_SmearClas12;
TH1D *Mon_Histo_avant_coupure5_SmearClas12;
TH1D *Mon_Histo_avant_coupure6_SmearClas12;
TH1D *Mon_Histo_avant_coupure7_SmearClas12;

TH1D *Mon_Histo_apres_coupure;
TH1D *Mon_Histo_apres_coupure2;
 TH1D *Mon_Histo_apres_coupure3;
 TH1D *Mon_Histo_apres_coupure4 ;
 TH1D *Mon_Histo_apres_coupure5;
 TH1D *Mon_Histo_apres_coupure6 ;
 TH1D *Mon_Histo_apres_coupure7;

TH1D *h13 ;
TH1D *h14 ;

TH2D *PhiVsThetaElec;
TH2D *PhiVsThetaPhot;
TH2D *PhiVsThetaNeut;

TH2D *PhiVsThetaElec_FastMCSmear;
TH2D *PhiVsThetaPhot_FastMCSmear;
TH2D *PhiVsThetaNeut_FastMCSmear;

TH2D *PhiVsThetaElec_PASClas12;
TH2D *PhiVsThetaPhot_PASClas12;
TH2D *PhiVsThetaNeut_PASClas12;


TH2D *Q2VsXbj;
TH2D *tVsXbj;
TH2D *tVsQ2;
TH2D *PeVsThetae;
 TH2D *PphotVsThetaphot;
TH2D *PneutVsThetaNeut;
TH2D *PneutVsThetaNeut_BHxsec;
TH2D *PneutVsThetaNeut_DVCSxsec;

TH1D *t_genere ;    
TH1D *t_reconstruit ;
 TH1D *Delta_t;
TH1D *Delta_t_now;


 TH1D *Delta_Q2 ;
TH1D *Delta_Xbj;
 TH1D *Delta_PHI;
TH1D *DeltaPP_elec_FastMC;
TH1D *DeltaTHETA_elec_FastMC;
TH1D *DeltaPHI_elec_FastMC;

TH1D *DeltaPP_phot_FastMC;
TH1D *DeltaTHETA_phot_FastMC;
TH1D *DeltaPHI_phot_FastMC;

TH1D *DeltaPP_Neut;
TH1D *DeltaTHETA_Neut ;
TH1D *DeltaPHI_Neut;

TH1D *MonH_DeltaPP_elec_FastMC ;
TH1D *MonH_DeltaTHETA_elec_FastMC ;
TH1D *MonH_DeltaPHI_elec_FastMC ;

TH1D *MonH_DeltaPP_phot_FastMC;
TH1D *MonH_DeltaTHETA_phot_FastMC;
TH1D *MonH_DeltaPHI_phot_FastMC;

TH1D *MonH_DeltaPP_Neut;
TH1D *MonH_DeltaTHETA_Neut;
TH1D *MonH_DeltaPHI_Neut;


TH1D *t_genere2 ;    
TH1D *t_reconstruit2 ;
TH1D *Delta_t2 ;
TH1D *Delta_t2_now ;                                                                                             
TH1D *H_Ps_e ;
TH1D *H_PsX_e;
TH1D *H_PsY_e ;
TH1D *H_PsZ_e;
TH1D *H_Thetas_e ;
TH1D *H_Phis_e;

TH1D *H_Ps_phot;
TH1D *H_PsX_phot;
TH1D *H_PsY_phot;
TH1D *H_PsZ_phot;
TH1D *H_Thetas_phot;
TH1D *H_Phis_phot;

TH1D *H_Ps_n;
TH1D *H_PsX_n;
TH1D *H_PsY_n ;
TH1D *H_PsZ_n ;
TH1D *H_Thetas_n;
TH1D *H_Phis_n;


TH1D *H_t ;
TH1D *H_W2;
TH1D *H_Q2 ;
TH1D *H_Xbj ;
TH1D *H_Y;

TH1D *MonH_t;
TH1D *MonH_W2;
TH1D *MonH_Q2 ;
TH1D *MonH_Xbj;
TH1D *MonH_Y ;

TH1D *MonH_Ps_e ;
TH1D *MonH_PsX_e;
TH1D *MonH_PsY_e;
TH1D *MonH_PsZ_e;
TH1D *MonH_Thetas_e;
TH1D *MonH_Phis_e;

TH1D *MonH_Ps_phot;
TH1D *MonH_PsX_phot ;
TH1D *MonH_PsY_phot ;
TH1D *MonH_PsZ_phot;
TH1D *MonH_Thetas_phot;
TH1D *MonH_Phis_phot;


TH1D *MonH_Ps_n;
TH1D *MonH_PsX_n;
TH1D *MonH_PsY_n;
TH1D *MonH_PsZ_n;
TH1D *MonH_Thetas_n;
TH1D *MonH_Phis_n ;

TH1D *SMEARING_Ps_n;
TH1D *SMEARING_PsX_n;
TH1D *SMEARING_PsY_n;
TH1D *SMEARING_PsZ_n;
TH1D *SMEARING_Thetas_n;
TH1D *SMEARING_Phis_n ;


TH1D *P_n_Bin;
TH1D *Thetas_n_Bin;
TH1D *Phis_n_Bin;

TH1D *P_phot_Bin;
TH1D *Thetas_phot_Bin;
TH1D *Phis_phot_Bin;

TH1D *P_e_Bin;
TH1D *Thetas_e_Bin;
TH1D *Phis_e_Bin;

TH1D *Acc_evt;
TH2D *Phig_Vs_Thetag;
TH1D *xsec_evt;
TH1D *Nb_evt;

TH1D *HBin_Nacc_evt;
TH1D *HBin_Nacc_evt_beforeAcc;

//Histos pour Nacc_evt:
  TH1F *hist_phi;
  TH1F *hist_q;
  TH1F *hist_x;
  TH1F *hist_t;
//Histos pour N_evt_tot:
  TH1F *hist_phi2;
  TH1F *hist_q2;
  TH1F *hist_x2;
  TH1F *hist_t2;
//Histos pour Xsec_integree:
  TH1F *hist_phi3;
  TH1F *hist_q3;
  TH1F *hist_x3;
  TH1F *hist_t3;
//Histos pour count_rate:
  TH1F *hist_phi4;
  TH1F *hist_q4;
  TH1F *hist_x4;
  TH1F *hist_t4;
//Histos pour Acceptance:
  TH1F *hist_phi5;
  TH1F *hist_q5;
  TH1F *hist_x5;
  TH1F *hist_t5;
//Histos pour Section efficace moyenne:
  TH1F *hist_phi6;
  TH1F *hist_q6;
  TH1F *hist_x6;
  TH1F *hist_t6;
//Histos pour Somme des nombres de coup:
  TH1F *hist_sum;
  TH1D *H_Phis_OUT;
//Histos pour missing mass:
 TH1F *hist_MM;

   // Declaration of leaf types
   Int_t           Evt_ID;
   Int_t           Ntracks;
   Double_t        Eb;
   Int_t           Bheli;
   Int_t           TarA;
   Int_t           TarZ;
   Int_t           Theli;
   Int_t           Struck_Nucl;
   Int_t           process;
   Int_t           ExcMS;
   Double_t        xbj;
   Double_t        y;
   Double_t        Q2;
	Double_t        PHI_LP;
   Double_t        W2;
   Double_t        nu;
   Double_t        t;
   Double_t        ycol;
   Double_t        bh_xsec;
   Double_t        dvcs_xsec;
   Double_t        int_xsec;
   Double_t        tot_xsec;
   Double_t        ms_xsec;
   Int_t           Type[7];   //[Ntracks]
   Int_t           Charge[7];   //[Ntracks]
   Double_t        Px[7];   //[Ntracks]
   Double_t        Py[7];   //[Ntracks]
   Double_t        Pz[7];   //[Ntracks]
   Double_t        P[7];   //[Ntracks]
   Double_t        E[7];   //[Ntracks]
   Double_t        Theta[7];   //[Ntracks]
   Double_t        Phi[7];   //[Ntracks]
   Double_t        Pex_er[7];   //[Ntracks]
   Double_t        Pey_er[7];   //[Ntracks]
   Double_t        Pez_er[7];   //[Ntracks]
   Double_t        Pgx_er[7];   //[Ntracks]
   Double_t        Pgy_er[7];   //[Ntracks]
   Double_t        Pgz_er[7];   //[Ntracks]
   Double_t        Pnx_er[7];   //[Ntracks]
   Double_t        Pny_er[7];   //[Ntracks]
   Double_t        Pnz_er[7];   //[Ntracks]
   Double_t        Eg_er[7];   //[Ntracks]
   Double_t        Ee_er[7];   //[Ntracks]
   Double_t        En_er[7];   //[Ntracks]
   Double_t        Theta_er[7];   //[Ntracks]
   Double_t        Phi_er[7];   //[Ntracks]
   Double_t        Pg_er[7];   //[Ntracks]
   Double_t        Pe_er[7];   //[Ntracks]
   Double_t        Pn_er[7];   //[Ntracks]

   // List of branches
   TBranch        *b_Evt_ID;   //!
   TBranch        *b_Ntracks;   //!
   TBranch        *b_Eb;   //!
   TBranch        *b_Bheli;   //!
   TBranch        *b_TarA;   //!
   TBranch        *b_TarZ;   //!
   TBranch        *b_Theli;   //!
   TBranch        *b_Struck_Nucl;   //!
   TBranch        *b_process;   //!
   TBranch        *b_ExcMS;   //!
   TBranch        *b_xbj;   //!
   TBranch        *b_y;   //!
	TBranch        *b_PHI_LP;   //!
   TBranch        *b_Q2;   //!
   TBranch        *b_W2;   //!
   TBranch        *b_nu;   //!
   TBranch        *b_t;   //!
   TBranch        *b_ycol;   //!
   TBranch        *b_bh_xsec;   //!
   TBranch        *b_dvcs_xsec;   //!
   TBranch        *b_int_xsec;   //!
   TBranch        *b_tot_xsec;   //!
   TBranch        *b_ms_xsec;   //!
   TBranch        *b_Type;   //!
   TBranch        *b_Charge;   //!
   TBranch        *b_Px;   //!
   TBranch        *b_Py;   //!
   TBranch        *b_Pz;   //!
   TBranch        *b_P;   //!
   TBranch        *b_E;   //!
   TBranch        *b_Theta;   //!
   TBranch        *b_Phi;   //!
   TBranch        *b_Pex_er;   //!
   TBranch        *b_Pey_er;   //!
   TBranch        *b_Pez_er;   //!
   TBranch        *b_Pgx_er;   //!
   TBranch        *b_Pgy_er;   //!
   TBranch        *b_Pgz_er;   //!
   TBranch        *b_Pnx_er;   //!
   TBranch        *b_Pny_er;   //!
   TBranch        *b_Pnz_er;   //!
   TBranch        *b_Eg_er;   //!
   TBranch        *b_Ee_er;   //!
   TBranch        *b_En_er;   //!
   TBranch        *b_Theta_er;   //!
   TBranch        *b_Phi_er;   //!
   TBranch        *b_Pg_er;   //!
   TBranch        *b_Pe_er;   //!
   TBranch        *b_Pn_er;   //!

   dvcs() { }
   ~dvcs() { }
   Int_t   Version() const { return 1; }
   void    Begin(TTree *tree);
   void    SlaveBegin(TTree *tree);
   void    Init(TTree *tree);
   Bool_t  Notify();
   Bool_t  Process(Long64_t entry);
   Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   void    SetOption(const char *option) { fOption = option; }
   void    SetObject(TObject *obj) { fObject = obj; }
   void    SetInputList(TList *input) { fInput = input; }
   TList  *GetOutputList() const { return fOutput; }
   void    SlaveTerminate();
   void    Terminate();

   //Definition of functions//

	int accep_func(int Id, double P, double Theta, double Phi0, double *out);
	void smear_fun(double Beta, double P, double Theta, double Phi, double *out);
	void Charge_Type(int Id, double *out);
	double findBdL(double P, double E, double Theta);
	void EC_XYZ_UVW(double x, double y, double z, double *out);
	void type(double Charge, double Theta, int *out);
	int clas12(int Id, double P, double Theta, double Phi0, double *out);
	Int_t GetBin(Float_t q2, Float_t xb, Float_t t,Float_t phi);
  // int accep_func(int Id, double P, double Theta, double Phi0, double *out);

   //etcetera

   ClassDef(dvcs,0);
};

#endif

#ifdef dvcs_cxx
void dvcs::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Evt_ID", &Evt_ID, &b_Evt_ID);
   fChain->SetBranchAddress("Ntracks", &Ntracks, &b_Ntracks);
   fChain->SetBranchAddress("Eb", &Eb, &b_Eb);
   fChain->SetBranchAddress("Bheli", &Bheli, &b_Bheli);
   fChain->SetBranchAddress("TarA", &TarA, &b_TarA);
   fChain->SetBranchAddress("TarZ", &TarZ, &b_TarZ);
   fChain->SetBranchAddress("Theli", &Theli, &b_Theli);
   fChain->SetBranchAddress("Struck_Nucl", &Struck_Nucl, &b_Struck_Nucl);
   fChain->SetBranchAddress("process", &process, &b_process);
   fChain->SetBranchAddress("ExcMS", &ExcMS, &b_ExcMS);
   fChain->SetBranchAddress("xbj", &xbj, &b_xbj);
   fChain->SetBranchAddress("y", &y, &b_y);
	fChain->SetBranchAddress("PHI_LP", &PHI_LP, &b_PHI_LP);
   fChain->SetBranchAddress("Q2", &Q2, &b_Q2);
   fChain->SetBranchAddress("W2", &W2, &b_W2);
   fChain->SetBranchAddress("nu", &nu, &b_nu);
   fChain->SetBranchAddress("t", &t, &b_t);
   fChain->SetBranchAddress("ycol", &ycol, &b_ycol);
   fChain->SetBranchAddress("bh_xsec", &bh_xsec, &b_bh_xsec);
   fChain->SetBranchAddress("dvcs_xsec", &dvcs_xsec, &b_dvcs_xsec);
   fChain->SetBranchAddress("int_xsec", &int_xsec, &b_int_xsec);
   fChain->SetBranchAddress("tot_xsec", &tot_xsec, &b_tot_xsec);
   fChain->SetBranchAddress("ms_xsec", &ms_xsec, &b_ms_xsec);
   fChain->SetBranchAddress("Type", Type, &b_Type);
   fChain->SetBranchAddress("Charge", Charge, &b_Charge);
   fChain->SetBranchAddress("Px", Px, &b_Px);
   fChain->SetBranchAddress("Py", Py, &b_Py);
   fChain->SetBranchAddress("Pz", Pz, &b_Pz);
   fChain->SetBranchAddress("P", P, &b_P);
   fChain->SetBranchAddress("E", E, &b_E);
   fChain->SetBranchAddress("Theta", Theta, &b_Theta);
   fChain->SetBranchAddress("Phi", Phi, &b_Phi);
   fChain->SetBranchAddress("Pex_er", Pex_er, &b_Pex_er);
   fChain->SetBranchAddress("Pey_er", Pey_er, &b_Pey_er);
   fChain->SetBranchAddress("Pez_er", Pez_er, &b_Pez_er);
   fChain->SetBranchAddress("Pgx_er", Pgx_er, &b_Pgx_er);
   fChain->SetBranchAddress("Pgy_er", Pgy_er, &b_Pgy_er);
   fChain->SetBranchAddress("Pgz_er", Pgz_er, &b_Pgz_er);
   fChain->SetBranchAddress("Pnx_er", Pnx_er, &b_Pnx_er);
   fChain->SetBranchAddress("Pny_er", Pny_er, &b_Pny_er);
   fChain->SetBranchAddress("Pnz_er", Pnz_er, &b_Pnz_er);
   fChain->SetBranchAddress("Eg_er", Eg_er, &b_Eg_er);
   fChain->SetBranchAddress("Ee_er", Ee_er, &b_Ee_er);
   fChain->SetBranchAddress("En_er", En_er, &b_En_er);
   fChain->SetBranchAddress("Theta_er", Theta_er, &b_Theta_er);
   fChain->SetBranchAddress("Phi_er", Phi_er, &b_Phi_er);
   fChain->SetBranchAddress("Pg_er", Pg_er, &b_Pg_er);
   fChain->SetBranchAddress("Pe_er", Pe_er, &b_Pe_er);
   fChain->SetBranchAddress("Pn_er", Pn_er, &b_Pn_er);
}

Bool_t dvcs::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef dvcs_cxx
