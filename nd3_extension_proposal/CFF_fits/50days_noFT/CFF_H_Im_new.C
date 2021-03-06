void CFF_H_Im_new()
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
  //  Double_t t_vec[NT+1]={0.00,0.2,0.5,0.8,1.2};
  Double_t t_vec[NT]={0.1,0.35,0.65,1.0};
  Double_t err_t[NT]={0.,0.,0.,0.};

  char out_h_im[300],out_ht_im[300],out_e_im[300],out_h_re[300],out_ht_re[300],out_e_re[300],out_et_re[300];

  Double_t Rh[4][4][4],Erh[4][4][4],Erhm[4][4][4],Erhp[4][4][4],Re[4][4][4],Ere[4][4][4],Erem[4][4][4],Erep[4][4][4],Rht[4][4][4],Erht[4][4][4],Erhtm[4][4][4],Erhtp[4][4][4],Ret[4][4][4],Eret[4][4][4],Eretm[4][4][4],Eretp[4][4][4],Ih[4][4][4],Eih[4][4][4],Eihm[4][4][4],Eihp[4][4][4],Ie[4][4][4],Eie[4][4][4],Eiem[4][4][4],Eiep[4][4][4],Iht[4][4][4],Eiht[4][4][4],Eihtm[4][4][4],Eihtp[4][4][4],Chi2[4][4][4],Himvgg2[4][4][4],Htimvgg2[4][4][4],Xb[4][4][4],Mt[4][4][4],Hrevgg[4][4][4],Erevgg[4][4][4],Htrevgg[4][4][4],Etrevgg[4][4][4],Himvgg[4][4][4],Eimvgg[4][4][4],Htimvgg[4][4][4];
  
  Double_t Rh_good[4][4][4],Erh_good[4][4][4],Erhm_good[4][4][4],Erhp_good[4][4][4],Re_good[4][4][4],Ere_good[4][4][4],Erem_good[4][4][4],Erep_good[4][4][4],Rht_good[4][4][4],Erht_good[4][4][4],Erhtm_good[4][4][4],Erhtp_good[4][4][4],Ret_good[4][4][4],Eret_good[4][4][4],Eretm_good[4][4][4],Eretp_good[4][4][4],Ih_good[4][4][4],Eih_good[4][4][4],Eihm_good[4][4][4],Eihp_good[4][4][4],Ie_good[4][4][4],Eie_good[4][4][4],Eiem_good[4][4][4],Eiep_good[4][4][4],Iht_good[4][4][4],Eiht_good[4][4][4],Eihtm_good[4][4][4],Eihtp_good[4][4][4],Chi2_good[4][4][4],Himvgg2_good[4][4][4],Htimvgg2_good[4][4][4],Xb_good[4][4][4],Mt_good[4][4][4],Hrevgg_good[4][4][4],Erevgg_good[4][4][4],Htrevgg_good[4][4][4],Etrevgg_good[4][4][4],Himvgg_good[4][4][4],Eimvgg_good[4][4][4],Htimvgg_good[4][4][4];
  sprintf(out_h_im,"h_im.dat");
  sprintf(out_ht_im,"ht_im.dat");
  sprintf(out_e_im,"e_im.dat");
  sprintf(out_h_re,"h_re.dat");
  sprintf(out_ht_re,"ht_re.dat");
  sprintf(out_e_re,"e_re.dat");
  sprintf(out_et_re,"et_re.dat");
  char canvas1[2],canvas2[2],canvas3[2],canvas4[2],psnamebig1[200],gifnamebig1[200],psnamebig2[200],gifnamebig2[200],psnamebig3[200],gifnamebig3[200],psnamebig4[200],gifnamebig4[200];
  
  Float_t qlow,qhigh,xlow,xhigh,thigh,tlow,philow,phihigh;
  
  Float_t rangeQ=q_vec[NQ2]-q_vec[0];
  Float_t rangeXB=x_vec[NXB]-x_vec[0];
  Float_t posQ[NQ2+1];
  Float_t posXB[NXB+1];
  
  sprintf(canvas1,"g1");
  
  sprintf(psnamebig1,"CFF_him.eps");
  sprintf(gifnamebig1,"CFF_him.pdf");
  
  TCanvas *g1= new TCanvas(canvas1,canvas1,1000,800);

  Int_t padnb;
  ofstream outfile_h_im(out_h_im);
  ofstream outfile_ht_im(out_ht_im);
  ofstream outfile_e_im(out_e_im);
  ofstream outfile_h_re(out_h_re);
  ofstream outfile_ht_re(out_ht_re);
  ofstream outfile_e_re(out_e_re);
  ofstream outfile_et_re(out_et_re);
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
	      Int_t s;
	      Double_t rh,erh,erhm,erhp,re,ere,erem,erep,rht,erht,erhtm,erhtp,ret,eret,eretm,eretp,ih,eih,eihm,eihp,ie,eie,eiem,eiep,iht,eiht,eihtm,eihtp,chi2,himvgg2,htimvgg2,xb,mt,hrevgg,erevgg,htrevgg,etrevgg,himvgg,eimvgg,htimvgg;
	      char titolo[30];
	      sprintf(filename,"fiteg1_%d_%d_%d.dat",j,i,k);
	      sprintf(titolo,"");
	      s=0;
	      ifstream file = (filename);
	      while (1) {
		file >>rh>>erh>>erhm>>erhp>>re>>ere>>erem>>erep>>rht>>erht>>erhtm>>erhtp>>ret>>eret>>eretm>>eretp>>ih>>eih>>eihm>>eihp>>ie>>eie>>eiem>>eiep>>iht>>eiht>>eihtm>>eihtp>>chi2>>himvgg2>>htimvgg2>>xb>>hrevgg>>erevgg>>htrevgg>>etrevgg>>himvgg>>eimvgg>>htimvgg;
		
		Rh[j-1][i-1][k-1]=rh*hrevgg;
		Erhm[j-1][i-1][k-1]=TMath::Abs(erhm*hrevgg);
		Erhp[j-1][i-1][k-1]=TMath::Abs(erhp*hrevgg);
		Hrevgg[j-1][i-1][k-1]=hrevgg;
		Rh_good[j-1][i-1][k-1]=-100.;
		Erhm_good[j-1][i-1][k-1]=0.;
		Erhp_good[j-1][i-1][k-1]=0.;
		if(erhm!=0 && erhp!=0 && rh!=0)
		  {
		    Rh_good[j-1][i-1][k-1]=rh*hrevgg;
		    Erhm_good[j-1][i-1][k-1]=TMath::Abs(erhm*hrevgg);
		    Erhp_good[j-1][i-1][k-1]=TMath::Abs(erhp*hrevgg);
		  }
		Re[j-1][i-1][k-1]=re*erevgg;
		Erem[j-1][i-1][k-1]=TMath::Abs(erem*erevgg);
		Erep[j-1][i-1][k-1]=TMath::Abs(erep*erevgg);
		Erevgg[j-1][i-1][k-1]=hrevgg;
		Re_good[j-1][i-1][k-1]=-100.;
		Erem_good[j-1][i-1][k-1]=0.;
		Erep_good[j-1][i-1][k-1]=0.;
		if(erem!=0 && erep!=0 && re!=0)
		  {
		    Re_good[j-1][i-1][k-1]=re*erevgg;
		    Erem_good[j-1][i-1][k-1]=TMath::Abs(erem*erevgg);
		    Erep_good[j-1][i-1][k-1]=TMath::Abs(erep*erevgg);
		  }
		Rht[j-1][i-1][k-1]=rht*htrevgg;
		Erhtm[j-1][i-1][k-1]=TMath::Abs(erhtm*htrevgg);
		Erhtp[j-1][i-1][k-1]=TMath::Abs(erhtp*htrevgg);
		Htrevgg[j-1][i-1][k-1]=htrevgg;
		Rht_good[j-1][i-1][k-1]=-100.;
		Erhtm_good[j-1][i-1][k-1]=0.;
		Erhtp_good[j-1][i-1][k-1]=0.;
		if(erhtm!=0 && erhtp!=0 && rht!=0)
		  {
		    Rht_good[j-1][i-1][k-1]=rht*htrevgg;
		    Erhtm_good[j-1][i-1][k-1]=TMath::Abs(erhtm*htrevgg);
		    Erhtp_good[j-1][i-1][k-1]=TMath::Abs(erhtp*htrevgg);
		  }
		Ret[j-1][i-1][k-1]=ret*etrevgg;
		Eretm[j-1][i-1][k-1]=TMath::Abs(eretm*etrevgg);
		Eretp[j-1][i-1][k-1]=TMath::Abs(eretp*etrevgg);
		Etrevgg[j-1][i-1][k-1]=etrevgg;
		Ret_good[j-1][i-1][k-1]=-100.;
		Eretm_good[j-1][i-1][k-1]=0.;
		Eretp_good[j-1][i-1][k-1]=0.;
		if(eretm!=0 && eretp!=0 && ret!=0)
		  {
		    Ret_good[j-1][i-1][k-1]=ret*etrevgg;
		    Eretm_good[j-1][i-1][k-1]=TMath::Abs(eretm*etrevgg);
		    Eretp_good[j-1][i-1][k-1]=TMath::Abs(eretp*etrevgg);
		  }
		Ih[j-1][i-1][k-1]=-ih*himvgg/TMath::Pi();
		Eihm[j-1][i-1][k-1]=TMath::Abs(eihm*himvgg/TMath::Pi());
		Eihp[j-1][i-1][k-1]=TMath::Abs(eihp*himvgg/TMath::Pi());
		Himvgg[j-1][i-1][k-1]=-himvgg/TMath::Pi();
		Ih_good[j-1][i-1][k-1]=-100.;
		Eihm_good[j-1][i-1][k-1]=0.;
		Eihp_good[j-1][i-1][k-1]=0.;
		if(Eihm[j-1][i-1][k-1]!=0 && Eihp[j-1][i-1][k-1]!=0 && TMath::IsNaN(Ih[j-1][i-1][k-1])!=1)
		  {
		    Ih_good[j-1][i-1][k-1]=-ih*himvgg/TMath::Pi();
		    Eihm_good[j-1][i-1][k-1]=TMath::Abs(eihm*himvgg/TMath::Pi());
		    Eihp_good[j-1][i-1][k-1]=TMath::Abs(eihp*himvgg/TMath::Pi());
		  }
		Ie[j-1][i-1][k-1]=-ie*eimvgg/TMath::Pi();
		Eiem[j-1][i-1][k-1]=TMath::Abs(eiem*eimvgg/TMath::Pi());
		Eiep[j-1][i-1][k-1]=TMath::Abs(eiep*eimvgg/TMath::Pi());
		Eimvgg[j-1][i-1][k-1]=-eimvgg/TMath::Pi();
		Ie_good[j-1][i-1][k-1]=-100.;
		Eiem_good[j-1][i-1][k-1]=0.;
		Eiep_good[j-1][i-1][k-1]=0.;
		if(eiem!=0 && eiep!=0 && ie!=0)
		  {
		    Ie_good[j-1][i-1][k-1]=-ie*eimvgg/TMath::Pi();
		    Eiem_good[j-1][i-1][k-1]=TMath::Abs(eiem*eimvgg/TMath::Pi());
		    Eiep_good[j-1][i-1][k-1]=TMath::Abs(eiep*eimvgg/TMath::Pi());
		  }
		//	     if(eihtm!=0 && eihtp!=0 && iht!=0)
		Iht[j-1][i-1][k-1]=-iht*htimvgg/TMath::Pi();;
		Eihtm[j-1][i-1][k-1]=TMath::Abs(eihtm*htimvgg/TMath::Pi());
		Eihtp[j-1][i-1][k-1]=TMath::Abs(eihtp*htimvgg/TMath::Pi());
		Htimvgg[j-1][i-1][k-1]=-htimvgg/TMath::Pi();
		Iht_good[j-1][i-1][k-1]=-100.;
		Eihtm_good[j-1][i-1][k-1]=0.;
		Eihtp_good[j-1][i-1][k-1]=0.;
		if(eihtm!=0 && eihtp!=0 && iht!=0)
		  {
		    Iht_good[j-1][i-1][k-1]=-iht*htimvgg/TMath::Pi();
		    Eihtm_good[j-1][i-1][k-1]=TMath::Abs(eihtm*htimvgg/TMath::Pi());
		    Eihtp_good[j-1][i-1][k-1]=TMath::Abs(eihtp*htimvgg/TMath::Pi());
		  }		
		if(i==4 && k==1)
		  {
		    Iht[j-1][i-1][k-1]=-100.;
		    Ih[j-1][i-1][k-1]=-100.;
		    Ie[j-1][i-1][k-1]=-100.;
		    Rht[j-1][i-1][k-1]=-100.;
		    Rh[j-1][i-1][k-1]=-100.;
		    Re[j-1][i-1][k-1]=-100.;
		    Ret[j-1][i-1][k-1]=-100.;
		    Iht_good[j-1][i-1][k-1]=-100.;
		    Ih_good[j-1][i-1][k-1]=-100.;
		    Ie_good[j-1][i-1][k-1]=-100.;
		    Rht_good[j-1][i-1][k-1]=-100.;
		    Rh_good[j-1][i-1][k-1]=-100.;
		    Re_good[j-1][i-1][k-1]=-100.;
		    Ret_good[j-1][i-1][k-1]=-100.;
		    Hrevgg[j-1][i-1][k-1]=-100.;
		    Himvgg[j-1][i-1][k-1]=-100.;
		    Htrevgg[j-1][i-1][k-1]=-100.;
		    Htimvgg[j-1][i-1][k-1]=-100.;
		    Erevgg[j-1][i-1][k-1]=-100.;
		    Eimvgg[j-1][i-1][k-1]=-100.;
		    Etrevgg[j-1][i-1][k-1]=-100.;
		  }
		if (!file.good()) break; 
	      }
	      file.close();


	      //	      if((j==2 && i==2)||(j==4 && i==3) || (j==3 && i==2)){	 
	      outfile_h_im<<j<<" "<<i<<" "<<k<<" "<<Ih_good[j-1][i-1][k-1]<<" "<<Eihm_good[j-1][i-1][k-1]<<" "<<Eihp_good[j-1][i-1][k-1]<<" "<<endl;
	    outfile_ht_im<<j<<" "<<i<<" "<<k<<" "<<Iht_good[j-1][i-1][k-1]<<" "<<Eihtm_good[j-1][i-1][k-1]<<" "<<Eihtp_good[j-1][i-1][k-1]<<" "<<endl;
	    outfile_e_im<<j<<" "<<i<<" "<<k<<" "<<Ie_good[j-1][i-1][k-1]<<" "<<Eiem_good[j-1][i-1][k-1]<<" "<<Eiep_good[j-1][i-1][k-1]<<" "<<endl;
	    outfile_h_re<<j<<" "<<i<<" "<<k<<" "<<Rh_good[j-1][i-1][k-1]<<" "<<Erhm_good[j-1][i-1][k-1]<<" "<<Erhp_good[j-1][i-1][k-1]<<" "<<endl;
	    outfile_ht_re<<j<<" "<<i<<" "<<k<<" "<<Rht_good[j-1][i-1][k-1]<<" "<<Erhtm_good[j-1][i-1][k-1]<<" "<<Erhtp_good[j-1][i-1][k-1]<<" "<<endl;
	    outfile_e_re<<j<<" "<<i<<" "<<k<<" "<<Re_good[j-1][i-1][k-1]<<" "<<Erem_good[j-1][i-1][k-1]<<" "<<Erep_good[j-1][i-1][k-1]<<" "<<endl;
	    outfile_et_re<<j<<" "<<i<<" "<<k<<" "<<Ret_good[j-1][i-1][k-1]<<" "<<Eretm_good[j-1][i-1][k-1]<<" "<<Eretp_good[j-1][i-1][k-1]<<" "<<endl;
	    //	}
	    }
	  if(!(j==4 && i==1) && !(j==3 && i==1) && !(j==1 && i==4)){

//             pad->SetRightMargin(0.01);
  //           pad->SetTopMargin(0.01);
    //         pad->SetBottomMargin(0.08);
	//if(!(j==NQ2 && i==NXB)){
//      	      pad->SetLeftMargin(0.005);
  //           pad->SetRightMargin(0.01);
    //         pad->SetTopMargin(0.005);
      //       pad->SetBottomMargin(0.01);
//}
	  pad->Draw();	   
	  pad->cd();

	  gr2_good=new TGraphAsymmErrors(NT,t_vec,Ih_good[j-1][i-1],err_t,err_t,Eihm_good[j-1][i-1],Eihp_good[j-1][i-1]);
	  int n = gr2_good->GetN();
	  double* y = gr2_good->GetY();
	  int locmax = TMath::LocMax(n,y);
	  double tmax = y[locmax];
	  int locmin = TMath::LocMin(n,y);
	  double tmin = y[locmin];
	  if(tmax>-100)
	    {
	      gr2_good->SetTitle(titolo);
	      gr2_good->GetXaxis()->SetTitle("-t (GeV^{2})");
	      gr2_good->GetXaxis()->SetLabelOffset(0.001);
	      gr2_good->GetYaxis()->SetTitle("H_{Im}(n)");
	      gr2_good->SetMaximum(7);
	      gr2_good->SetMinimum(-4.);
	      gr2_good->SetMarkerColor(4);
	      gr2_good->SetLineColor(4);
	      gr2_good->SetMarkerStyle(21);
	      gr2_good->SetMarkerSize(0.5);
	      gr2_good->Draw("AP,same");
	      TLine *l1;
	      l1=new TLine(0.,0.,1.1,0.);
	      l1->SetLineStyle(2); 
	      l1->Draw("same");
	    }
	  }}
    }
  g1-> Print(psnamebig1);
  g1-> Print(gifnamebig1);
  outfile_h_im.close();
  outfile_ht_im.close();
  outfile_e_im.close();
  outfile_h_re.close();
  outfile_ht_re.close();
  outfile_e_re.close();
  outfile_et_re.close();
}
