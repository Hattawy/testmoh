void CFF_michel()
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
  char out_h_im[300],out_ht_im[300],out_e_im[300],out_h_re[300],out_ht_re[300],out_e_re[300],out_et_re[300];

  //  Double_t r_h[239],er_hm[239],er_hp[239],r_e[239],er_em[239],er_ep[239],r_ht[239],er_htm[239],er_htp[239],r_et[239],er_etm[239],er_etp[239],i_h[239],ei_hm[239],ei_hp[239],i_e[239],ei_em[239],ei_ep[239],i_ht[239],ei_htm[239],ei_htp[239],chi2[239],him_vgg[239],htim_vgg[239],x_b[239],mt[239],r_hr[239],r_er[239],r_htr[239],r_etr[239],i_hr[239],i_er[239],i_htr[239],qq[239];

  Double_t Rh[239],Erh[239],Erhm[239],Erhp[239],Re[239],Ere[239],Erem[239],Erep[239],Rht[239],Erht[239],Erhtm[239],Erhtp[239],Ret[239],Eret[239],Eretm[239],Eretp[239],Ih[239],Eih[239],Eihm[239],Eihp[239],Ie[239],Eie[239],Eiem[239],Eiep[239],Iht[239],Eiht[239],Eihtm[239],Eihtp[239],Chi2[239],Himvgg2[239],Htimvgg2[239],Xb[239],Mt[239],Hrevgg[239],Erevgg[239],Htrevgg[239],Etrevgg[239],Himvgg[239],Eimvgg[239],Htimvgg[239],T[239],Q2[239],XB[239];
  
  sprintf(out_h_im,"h_im.dat");
  sprintf(out_ht_im,"ht_im.dat");
  sprintf(out_e_im,"e_im.dat");
  sprintf(out_h_re,"h_re.dat");
  sprintf(out_ht_re,"ht_re.dat");
  sprintf(out_e_re,"e_re.dat");
  sprintf(out_et_re,"et_re.dat");

  ofstream outfile_h_im(out_h_im);
  ofstream outfile_ht_im(out_ht_im);
  ofstream outfile_e_im(out_e_im);
  ofstream outfile_h_re(out_h_re);
  ofstream outfile_ht_re(out_ht_re);
  ofstream outfile_e_re(out_e_re);
  ofstream outfile_et_re(out_et_re);

  for(Int_t i=1;i<239;i++)
    {      
      Int_t s;
      Double_t rh,erhm,erhp,re,erem,erep,rht,erhtm,erhtp,ret,eretm,eretp,ih,eihm,eihp,ie,eiem,eiep,iht,eihtm,eihtp,xi2,himvgg,htimvgg,xb,mint,rhr,rer,rhtr,retr,ihr,ier,ihtr,q2;
      char titolo[30];
      sprintf(filename,"clas12_fit_52_%d.out",i);
      cout<<filename<<endl;
      //      sprintf(titolo,"");
      s=0;
      ifstream file = (filename);
      while (1) {
	file >>rh>>erhm>>erhp>>re>>erem>>erep>>rht>>erhtm>>erhtp>>ret>>eretm>>eretp>>ih>>eihm>>eihp>>ie>>eiem>>eiep>>iht>>eihtm>>eihtp>>xi2>>himvgg>>htimvgg>>xb>>mint>>rhr>>rer>>rhtr>>retr>>ihr>>ier>>ihtr>>q2;
	
	Rh[i-1]=rh*rhr;
	Erhm[i-1]=TMath::Abs(erhm*rhr);
	Erhp[i-1]=TMath::Abs(erhp*rhr);		
	
	Re[i-1]=re*rer;
	Erem[i-1]=TMath::Abs(erem*rer);
	Erep[i-1]=TMath::Abs(erep*rer);
	
	Rht[i-1]=rht*rhtr;
	Erhtm[i-1]=TMath::Abs(erhtm*rhtr);
	Erhtp[i-1]=TMath::Abs(erhtp*rhtr);

	Ret[i-1]=ret*retr;
	Eretm[i-1]=TMath::Abs(eretm*retr);
	Eretp[i-1]=TMath::Abs(eretp*retr);

	Ih[i-1]=-ih*himvgg/TMath::Pi();
	Eihm[i-1]=TMath::Abs(eihm*himvgg/TMath::Pi());
	Eihp[i-1]=TMath::Abs(eihp*himvgg/TMath::Pi());
	
	Ie[i-1]=-ie*ier/TMath::Pi();
	Eiem[i-1]=TMath::Abs(eiem*ier/TMath::Pi());
	Eiep[i-1]=TMath::Abs(eiep*ier/TMath::Pi());
	
	Iht[i-1]=-iht*htimvgg/TMath::Pi();;
	Eihtm[i-1]=TMath::Abs(eihtm*htimvgg/TMath::Pi());
	Eihtp[i-1]=TMath::Abs(eihtp*htimvgg/TMath::Pi());
	
	T[i-1]=mint;
	XB[i-1]=xb;
	Q2[i-1]=q2;
      
	if (!file.good()) break; 
      }
      outfile_h_im<<i<<" "<<Ih[i-1]<<" "<<Eihm[i-1]<<" "<<Eihp[i-1]<<" "<<Q2[i-1]<<" "<<XB[i-1]<<" "<<T[i-1]<<endl;
      outfile_ht_im<<i<<" "<<Iht[i-1]<<" "<<Eihtm[i-1]<<" "<<Eihtp[i-1]<<" "<<Q2[i-1]<<" "<<XB[i-1]<<" "<<T[i-1]<<endl;
      outfile_e_im<<i<<" "<<Ie[i-1]<<" "<<Eiem[i-1]<<" "<<Eiep[i-1]<<" "<<Q2[i-1]<<" "<<XB[i-1]<<" "<<T[i-1]<<endl;
      outfile_h_re<<i<<" "<<Rh[i-1]<<" "<<Erhm[i-1]<<" "<<Erhp[i-1]<<" "<<Q2[i-1]<<" "<<XB[i-1]<<" "<<T[i-1]<<endl;
      outfile_ht_re<<i<<" "<<Rht[i-1]<<" "<<Erhtm[i-1]<<" "<<Erhtp[i-1]<<" "<<Q2[i-1]<<" "<<XB[i-1]<<" "<<T[i-1]<<endl;
      outfile_e_re<<i<<" "<<Re[i-1]<<" "<<Erem[i-1]<<" "<<Erep[i-1]<<" "<<Q2[i-1]<<" "<<XB[i-1]<<" "<<T[i-1]<<endl;
      outfile_et_re<<i<<" "<<Ret[i-1]<<" "<<Eretm[i-1]<<" "<<Eretp[i-1]<<" "<<Q2[i-1]<<" "<<XB[i-1]<<" "<<T[i-1]<<endl;
      file.close();
    }
  outfile_h_im.close();
  outfile_ht_im.close();
  outfile_e_im.close();
  outfile_h_re.close();
  outfile_ht_re.close();
  outfile_e_re.close();
  outfile_et_re.close();
  
}
