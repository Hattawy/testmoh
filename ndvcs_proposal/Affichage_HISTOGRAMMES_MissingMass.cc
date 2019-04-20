void Affichage_HISTOGRAMMES_MissingMass()
{
  gSystem->Load("libPhysics");
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(111);

  Float_t theta[5]={0.0017,0.0227,0.0872,0.1745,0.349};
  Float_t phi[5]={0.0017,0.0174,0.0523,0.1745,0.349};
  Float_t mom[5]={0.001,0.01,0.04,0.1,0.2};

  for(Int_t i=0;i<3;i++)
  {    
    Float_t sigma[5];
    Float_t sigma_err[5];
    Float_t x_err[5]={0.,0.,0.,0.,0.};
    char canvas[30];
    Float_t var[5];
    char filename[300],name[30];
    char title[30];
    char titlex[30];
    for(Int_t r=0;r<5;r++)
      {    
	if(i==0)
	  {
	    sprintf(filename,"ana_phi=%g_theta=%g_P=%g_newsmearIC.root",phi[2],theta[r],mom[2]);
	    var[r]=theta[r]*180./TMath::Pi();
	  }
	if(i==1)
	  {
	    sprintf(filename,"ana_phi=%g_theta=%g_P=%g_newsmearIC.root",phi[r],theta[1],mom[2]);
	    var[r]=phi[r]*180./TMath::Pi();
	  }
	if(i==2)
	  {
	    sprintf(filename,"ana_phi=%g_theta=%g_P=%g_newsmearIC.root",phi[2],theta[1],mom[r]);
	    var[r]=mom[r];
	  }
	TFile *f = new TFile(filename);
	f->cd();    	
	MissingMass_SmearClas12_CLAS12_CUTS_6-> Fit("gaus","0","");
	sigma[r] = gaus->GetParameter(2);    
	sigma_err[r] = gaus->GetParError(2);	
      }
    
    sprintf(canvas,"g%d",i);
    TCanvas *c= new TCanvas(canvas,canvas,1000,800);

    TGraphErrors *l;
    l=new TGraphErrors(5,var,sigma,x_err,sigma_err);
    sprintf(title,"");
    l->SetMarkerStyle(20);
    l->SetMarkerColor(1);
    l->SetTitle(title);
    l->SetMinimum(0);    
    Float_t max;
    max=0.03;
    if(i==2)max=0.1;
    l->SetMaximum(max);
    l->Draw("AP");    
    if(i==0)sprintf(titlex,"#Delta#theta (degrees)");
    if(i==1)sprintf(titlex,"#Delta#phi (degrees)");
    if(i==2)sprintf(titlex,"#Delta p/p");       
    l->GetYaxis()->SetTitleOffset(1.3);
    l->GetYaxis()->SetTitle("#sigma(MM) (GeV)");
    l->GetXaxis()->SetTitle(titlex);
    sprintf(name,"MM_res_%d.eps",i);
    c->Print(name);
  }
  
}


