void CFF_H_Re_compare3()
{
  gSystem->Load("libPhysics");
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(111);
  gStyle->SetPadBorderMode(0);
  gStyle->SetCanvasColor(kWhite);
  gStyle->SetFrameFillColor(kWhite);
  gStyle->SetErrorX(0);
  
  char filename[300];
  
  Int_t const NQ2=4, NXB=4, NT=4; 
  
  Double_t q_vec[NQ2+1]={1.,2.,3.5,5.,10.};
  Double_t x_vec[NXB+1]={0.05,0.15,0.3,0.45,0.7};
  Double_t t_vec[NT]={0.1,0.35,0.65,1.0};
  Double_t t_vec_noft[NT]={0.13,0.38,0.68,1.03};
  Double_t t_vec_50[NT]={0.16,0.41,0.71,1.06};
  Double_t err_t[NT]={0.,0.,0.,0.};

  char out_h_im[300],out_ht_im[300],out_e_im[300],out_h_re[300],out_ht_re[300],out_e_re[300],out_et_re[300];
  char out_h_im_noft[300],out_ht_im_noft[300],out_e_im_noft[300],out_h_re_noft[300],out_ht_re_noft[300],out_e_re_noft[300],out_et_re_noft[300];
  char out_h_im_50[300],out_ht_im_50[300],out_e_im_50[300],out_h_re_50[300],out_ht_re_50[300],out_e_re_50[300],out_et_re_50[300];
  Double_t value[4][4][4],error[4][4][4];
  Double_t value_noft[4][4][4],error_noft[4][4][4];
  Double_t value_50[4][4][4],error_50[4][4][4];

  Double_t Rh_good[4][4][4],Erh_good[4][4][4],Erhm_good[4][4][4],Erhp_good[4][4][4],Re_good[4][4][4],Ere_good[4][4][4],Erem_good[4][4][4],Erep_good[4][4][4],Rht_good[4][4][4],Erht_good[4][4][4],Erhtm_good[4][4][4],Erhtp_good[4][4][4],Ret_good[4][4][4],Eret_good[4][4][4],Eretm_good[4][4][4],Eretp_good[4][4][4],Ih_good[4][4][4],Eih_good[4][4][4],Eihm_good[4][4][4],Eihp_good[4][4][4],Ie_good[4][4][4],Eie_good[4][4][4],Eiem_good[4][4][4],Eiep_good[4][4][4],Iht_good[4][4][4],Eiht_good[4][4][4],Eihtm_good[4][4][4],Eihtp_good[4][4][4];

  Double_t Rh_good_noft[4][4][4],Erh_good_noft[4][4][4],Erhm_good_noft[4][4][4],Erhp_good_noft[4][4][4],Re_good_noft[4][4][4],Ere_good_noft[4][4][4],Erem_good_noft[4][4][4],Erep_good_noft[4][4][4],Rht_good_noft[4][4][4],Erht_good_noft[4][4][4],Erhtm_good_noft[4][4][4],Erhtp_good_noft[4][4][4],Ret_good_noft[4][4][4],Eret_good_noft[4][4][4],Eretm_good_noft[4][4][4],Eretp_good_noft[4][4][4],Ih_good_noft[4][4][4],Eih_good_noft[4][4][4],Eihm_good_noft[4][4][4],Eihp_good_noft[4][4][4],Ie_good_noft[4][4][4],Eie_good_noft[4][4][4],Eiem_good_noft[4][4][4],Eiep_good_noft[4][4][4],Iht_good_noft[4][4][4],Eiht_good_noft[4][4][4],Eihtm_good_noft[4][4][4],Eihtp_good_noft[4][4][4];

  Double_t Rh_good_50[4][4][4],Erh_good_50[4][4][4],Erhm_good_50[4][4][4],Erhp_good_50[4][4][4],Re_good_50[4][4][4],Ere_good_50[4][4][4],Erem_good_50[4][4][4],Erep_good_50[4][4][4],Rht_good_50[4][4][4],Erht_good_50[4][4][4],Erhtm_good_50[4][4][4],Erhtp_good_50[4][4][4],Ret_good_50[4][4][4],Eret_good_50[4][4][4],Eretm_good_50[4][4][4],Eretp_good_50[4][4][4],Ih_good_50[4][4][4],Eih_good_50[4][4][4],Eihm_good_50[4][4][4],Eihp_good_50[4][4][4],Ie_good_50[4][4][4],Eie_good_50[4][4][4],Eiem_good_50[4][4][4],Eiep_good_50[4][4][4],Iht_good_50[4][4][4],Eiht_good_50[4][4][4],Eihtm_good_50[4][4][4],Eihtp_good_50[4][4][4];


  sprintf(out_h_im,"h_im.dat");
  sprintf(out_ht_im,"ht_im.dat");
  sprintf(out_e_im,"e_im.dat");
  sprintf(out_h_re,"h_re.dat");
  sprintf(out_ht_re,"ht_re.dat");
  sprintf(out_e_re,"e_re.dat");
  sprintf(out_et_re,"et_re.dat");

  sprintf(out_h_im_noft,"../comparison/h_im.dat");
  sprintf(out_ht_im_noft,"../comparison/ht_im.dat");
  sprintf(out_e_im_noft,"../comparison/e_im.dat");
  sprintf(out_h_re_noft,"../comparison/h_re.dat");
  sprintf(out_ht_re_noft,"../comparison/ht_re.dat");
  sprintf(out_e_re_noft,"../comparison/e_re.dat");
  sprintf(out_et_re_noft,"../comparison/et_re.dat");

  sprintf(out_h_im_50,"h_im_50.dat");
  sprintf(out_ht_im_50,"ht_im_50.dat");
  sprintf(out_e_im_50,"e_im_50.dat");
  sprintf(out_h_re_50,"h_re_50.dat");
  sprintf(out_ht_re_50,"ht_re_50.dat");
  sprintf(out_e_re_50,"e_re_50.dat");
  sprintf(out_et_re_50,"et_re_50.dat");

  char canvas1[2],canvas2[2],canvas3[2],canvas4[2],canvas5[2],canvas6[2],canvas7[2],psnamebig1[200],gifnamebig1[200],psnamebig2[200],gifnamebig2[200],psnamebig3[200],gifnamebig3[200],psnamebig4[200],gifnamebig4[200],psnamebig5[200],gifnamebig5[200],psnamebig6[200],gifnamebig6[200],psnamebig7[200],gifnamebig7[200];
  
  Float_t qlow,qhigh,xlow,xhigh,thigh,tlow,philow,phihigh;

  Double_t x,y,z;
  Int_t a,b,c;

  Float_t rangeQ=q_vec[NQ2]-q_vec[0];
  Float_t rangeXB=x_vec[NXB]-x_vec[0];
  Float_t posQ[NQ2+1];
  Float_t posXB[NXB+1];
  
  sprintf(canvas1,"g1");

  sprintf(gifnamebig1,"CFF_hre_compare3.pdf");

  TCanvas *g1= new TCanvas(canvas1,canvas1,1000,800);

  Int_t padnb;

  for(Int_t p2=0;p2<NQ2+1;p2++) {
    posQ[p2]=0.1+(q_vec[p2]-q_vec[0])*0.8/rangeQ;
  }
  for(Int_t p3=0;p3<NXB+1;p3++) {
    posXB[p3]=0.1+(x_vec[p3]-x_vec[0])*0.8/rangeXB;
  }
  
  TGaxis *axisQ = new TGaxis(0.09,0.09,0.09,0.95,q_vec[0],q_vec[NQ2],510);
  TGaxis *axisXB = new TGaxis(0.09,0.09,0.95,0.09,x_vec[0],x_vec[NXB],510);
  axisQ->SetTitle("Q^{2} (GeV^{2})");
  axisXB->SetTitle("x_{B}");
  axisQ->Draw();
  axisXB->Draw();
  
  char titolo[30];

  ifstream file = (out_h_re);
  while (1) {
    file >> a>>b>>c>>x>>y>>z;
    Ih_good[a-1][b-1][c-1]=x;
    Eihm_good[a-1][b-1][c-1]=y;
    Eihp_good[a-1][b-1][c-1]=z;
    error[a-1][b-1][c-1]=0.5*(y+z);
    value[a-1][b-1][c-1]= 0.5*(x+y+x-z);
    if(error[a-1][b-1][c-1]>5000.*TMath::Abs(value[a-1][b-1][c-1]))
      {
	value[a-1][b-1][c-1]=-100.;
	error[a-1][b-1][c-1]=0.;
      }
    if (!file.good()) break; 
  }
  file.close();

  ifstream file_noft = (out_h_re_noft);
  while (1) {
    file_noft >> a>>b>>c>>x>>y>>z;
    Ih_good_noft[a-1][b-1][c-1]=x;
    Eihm_good_noft[a-1][b-1][c-1]=y;
    Eihp_good_noft[a-1][b-1][c-1]=z;
    error_noft[a-1][b-1][c-1]=0.5*(y+z);
    value_noft[a-1][b-1][c-1]= 0.5*(x+y+x-z);
    if(error_noft[a-1][b-1][c-1]>5000.*TMath::Abs(value_noft[a-1][b-1][c-1]))
      {
	value_noft[a-1][b-1][c-1]=-100.;
	error_noft[a-1][b-1][c-1]=0.;
      }
    if (!file_noft.good()) break; 
  }
  file_noft.close();

  ifstream file_50 = (out_h_re_50);
  while (1) {
    file_50 >> a>>b>>c>>x>>y>>z;
    Ih_good_50[a-1][b-1][c-1]=x;
    Eihm_good_50[a-1][b-1][c-1]=y;
    Eihp_good_50[a-1][b-1][c-1]=z;
    error_50[a-1][b-1][c-1]=0.5*(y+z);
    value_50[a-1][b-1][c-1]= 0.5*(x+y+x-z);
    if(error_50[a-1][b-1][c-1]>5000.*TMath::Abs(value_50[a-1][b-1][c-1]))
      {
	value_50[a-1][b-1][c-1]=-100.;
	error_50[a-1][b-1][c-1]=0.;
      }
    if (!file_50.good()) break; 
  }
  file_50.close();

  for(Int_t j=NQ2;j>0;j--)
    {
      for(Int_t i=1;i<NXB+1;i++)
	{
	  g1->cd();
	  char padname[20];
	  padnb=(NQ2+1-j)*100+i;
	  sprintf(padname,"pad_%d",padnb);
	  TPad *pad= new TPad(padname,padname,posXB[i-1],posQ[j-1],posXB[i],posQ[j]);

	  for(Int_t k=1;k<NT+1;k++)
	    {	         
	      char titolo[30];
	      sprintf(titolo,"");
	    }
	  if(!(j==4 && i==1) && !(j==3 && i==1) && !(j==1 && i==4))
	    {	      
	      pad->Draw();	   
	      pad->cd();
	      gr1_good=new TGraphErrors(NT,t_vec,value[j-1][i-1],err_t,error[j-1][i-1]);
	      gr1_good_noft=new TGraphErrors(NT,t_vec_noft,value_noft[j-1][i-1],err_t,error_noft[j-1][i-1]);
	      gr1_good_50=new TGraphErrors(NT,t_vec_50,value_50[j-1][i-1],err_t,error_50[j-1][i-1]);	      

	      int n = gr1_good_50->GetN();
	      double* y1 = gr1_good_50->GetY();
	      int locmax = TMath::LocMax(n,y1);
	      double tmax = y1[locmax];
	      int locmin = TMath::LocMin(n,y1);
	      double tmin = y1[locmin];
	      double ymax = y1[locmax]+error_50[j-1][i-1][locmax]+1;
	      double ymin = y1[locmin]-error_50[j-1][i-1][locmin]-1;
	      if(tmin==-100) {ymin=-5;ymax=6;}
	      if(tmin==-100 && i==2 && j==1) {ymin=-2.5;ymax=1.5;}
	      if(tmin==-100 && i==2 && j==2) {ymin=-2.5;ymax=2.5;}
	      if(tmin==-100 && i==3) {ymin=-2.;ymax=2.;}
	      if(i==1 && j==1) {ymin=-6.;ymax=10.;}
	      if(i==1 && j==2) {ymin=-7.;ymax=8.;}
	      if(tmax>-100)
		{
		  gr1_good_50->SetTitle(titolo);
		  gr1_good_50->GetXaxis()->SetTitle("-t (GeV^{2})");
		  gr1_good_50->GetXaxis()->SetLabelOffset(0.001);
		  gr1_good_50->GetYaxis()->SetTitle("H_{Re}(n)");
		  gr1_good_50->SetMaximum(ymax);
		  gr1_good_50->SetMinimum(ymin);
		  gr1_good->SetMarkerColor(4);
		  gr1_good->SetLineColor(4);
		  gr1_good->SetMarkerStyle(21);
		  gr1_good->SetMarkerSize(0.5);
		  gr1_good_noft->SetMarkerColor(1);
		  gr1_good_noft->SetLineColor(1);
		  gr1_good_noft->SetMarkerStyle(21);
		  gr1_good_noft->SetMarkerSize(0.5);
		  TLine *l1;
		  l1=new TLine(0.,0.,1.1,0.);
		  l1->SetLineStyle(2); 
		  l1->Draw("same");
		  gr1_good_50->SetMarkerColor(2);
		  gr1_good_50->SetLineColor(2);
		  gr1_good_50->SetMarkerSize(0.5);
		  gr1_good_50->SetMarkerStyle(21);
		  gr1_good_50->Draw("AP,same");
		  gr1_good->Draw("P,same");
		  gr1_good_noft->Draw("P,same");
		}
	    }
	}
    }
  g1-> Print(gifnamebig1);
}
