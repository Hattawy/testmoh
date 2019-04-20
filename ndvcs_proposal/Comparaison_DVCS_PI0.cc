

void Comparaison_DVCS_PI0(){
	
	gSystem->Load("libPhysics");
	gROOT->SetStyle("Plain");
	gStyle->SetPalette(1);
	gStyle->SetOptStat(0);
	gStyle->SetOptFit(111);
	gStyle->SetPadBorderMode(0);


  TCanvas *Missing_Mass = new TCanvas("Missing_Mass","Missing_Mass",1000,800); 
  Missing_Mass->Divide(3,4);
  //TFile *f= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code/ana_SAVE_comparaison_DVCS_PI0.root");
  //TFile *h= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0/ana_SAVE_comparaison_DVCS_PI0.root");
	 //TFile *f= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code/ana.root");
  	 //TFile *h= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0/ana.root");

		TFile *f= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code/ana_Comparaison_dvcs_pi0_last_FT_resolution.root");
  	 	TFile *h= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0/ana.root");
		
		//TFile *f= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code/ana_Comparaison_dvcs_pi0_IC_resolution.root");
		//TFile *h= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0_pourRESO_IC_normal/ana.root");


	double xmin= 0.;
	//double xmax= 1.025;
	double xmax= 1.15;
	//double xmax= 1.2;
	double xmax2= 2.5;

  for(Int_t k=1;k<=12;k++){
    Missing_Mass->cd(k);
    char nome_MM[30],nome_MM2[30];
    TH1F *histo_MM,*histo_MM2;
    sprintf(nome_MM,"MM%d_Bin",k);
    sprintf(nome_MM2,"MM%d_Bin",k);
    f->GetObject(nome_MM,histo_MM);
    h->GetObject(nome_MM2,histo_MM2);

    histo_MM-> SetLineColor(kRed);
    histo_MM-> Draw("");
    histo_MM->GetXaxis()->SetTitle("Mm(ed->en #gamma[X])(GeV)");
    int bmin = histo_MM->GetXaxis()->FindBin(xmin); 
    int bmax = histo_MM->GetXaxis()->FindBin(xmax);
    int bmax2 = histo_MM->GetXaxis()->FindBin(xmax2);
    double integral1 = histo_MM->Integral(bmin,bmax);
    double integral3 = histo_MM->Integral(bmin,bmax2);	
	double Valeur_max1 = (histo_MM->GetMaximum())*0.8; //Utile pour ajuster le print du label latex aprés
	double Valeur_max2 = (histo_MM->GetMaximum())*0.7;
   
    histo_MM2-> SetLineColor(kBlack);
    histo_MM2-> Draw("sames");
    int bmin = histo_MM2->GetXaxis()->FindBin(xmin); 
    int bmax = histo_MM2->GetXaxis()->FindBin(xmax); 
    double integral2 = histo_MM2->Integral(bmin,bmax);
	 
    double rapport=(integral2/integral1)*100.;
    double rapport2=(integral1/integral3)*100.;

    char text[100];
    sprintf(text,"Pi0 contamination=%d",rapport);
    TLatex *l5 = new TLatex(2.5,Valeur_max2,text);
    l5->SetTextSize(0.05);
    l5->SetTextFont(72);
    l5->SetTextColor(kBlack);
    l5->Draw("sames");

    sprintf(text,"DVCS Signal=%d",rapport2);
    TLatex *l6 = new TLatex(2.5,Valeur_max1,text);
    l6->SetTextSize(0.05);
    l6->SetTextFont(72);
    l6->SetTextColor(kBlack);
    l6->Draw("sames");
    
  }
Missing_Mass->Print("Comparaison_DVCS_Pi0.eps");


	TCanvas *Missing_Mass_integreted = new TCanvas("Missing_Mass_integreted","Missing_Mass_integreted",1); 
       	Missing_Mass_integreted->cd();

//	f= TFile::Open("/projet/nucleon/Baptiste/genepi/baptiste_code/ana_SAVE_comparaison_DVCS_PI0.root");
// TFile *f= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code/ana.root");
	//TFile *f= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code/ana_Comparaison_dvcs_pi0_last_FT_resolution.root");
	TFile *f= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code/ana_Comparaison_dvcs_pi0_IC_resolution.root");

	MissingMass_SmearClas12_CLAS12_CUTS_2-> SetLineColor(kRed);
	MissingMass_SmearClas12_CLAS12_CUTS_2-> Draw("");
	MissingMass_SmearClas12_CLAS12_CUTS_2->GetXaxis()->SetTitle("Mm^{2}(GeV^{2})");
  	 int bmin = MissingMass_SmearClas12_CLAS12_CUTS_2->GetXaxis()->FindBin(xmin); 
 	 int bmax = MissingMass_SmearClas12_CLAS12_CUTS_2->GetXaxis()->FindBin(xmax); 
 	int bmax2 = MissingMass_SmearClas12_CLAS12_CUTS_2->GetXaxis()->FindBin(xmax2);
 	 double integral1 = MissingMass_SmearClas12_CLAS12_CUTS_2->Integral(bmin,bmax);	
	double integral3 = MissingMass_SmearClas12_CLAS12_CUTS_2->Integral(bmin,bmax2);	
	double Valeur_max1 = (MissingMass_SmearClas12_CLAS12_CUTS_2->GetMaximum())*0.8; //Utile pour ajuster le print du label latex aprés
	double Valeur_max2 = (MissingMass_SmearClas12_CLAS12_CUTS_2->GetMaximum())*0.7;

//	TFile *g= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0/ana_SAVE_comparaison_DVCS_PI0.root");
	//TFile *g= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0/ana.root");
	//TFile *g= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0/ana.root");
	TFile *g= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0_pourRESO_IC_normal/ana.root");

	MissingMass_SmearClas12_CLAS12_CUTS_2-> SetLineColor(kBlack);
	MissingMass_SmearClas12_CLAS12_CUTS_2-> Draw("sames");
 	 int bmin = MissingMass_SmearClas12_CLAS12_CUTS_2->GetXaxis()->FindBin(xmin); 
 	 int bmax = MissingMass_SmearClas12_CLAS12_CUTS_2->GetXaxis()->FindBin(xmax); 
 	 double integral2 = MissingMass_SmearClas12_CLAS12_CUTS_2->Integral(bmin,bmax);
	
	double rapport=	(integral2/integral1)*100.;
	double rapport2=(integral1/integral3)*100.;
	
 	 char text[100];
  	sprintf(text,"Pi0 contamination=%d ",rapport);
  	TLatex *l5 = new TLatex(2.5,Valeur_max2,text);
 	l5->SetTextSize(0.05);
  	l5->SetTextFont(72);
  	l5->SetTextColor(kBlack);
  	l5->Draw("sames");

	sprintf(text,"DVCS Signal=%d",rapport2);
   	TLatex *l6 = new TLatex(2.5,Valeur_max1,text);
   	l6->SetTextSize(0.05);
   	l6->SetTextFont(72);
   	l6->SetTextColor(kBlack);
    	l6->Draw("sames");
 
	  sprintf(text,"Mm^{2}(ed->en #gamma[X])");
	  TLatex *l5 = new TLatex(0,1,text);
	  l5->SetTextSize(0.05);
	  l5->SetTextFont(72);
	  l5->SetTextColor(kRed);
	  l5->Draw("sames");


	  sprintf(text,"Mm^{2}(ed->en #gamma_{1}[X])");
	  TLatex *l6 = new TLatex(0,0,text);
	  l6->SetTextSize(0.05);
	  l6->SetTextFont(72);
	  l6->SetTextColor(kBlack);
	  l6->Draw("sames");



Missing_Mass_integreted->Print("Comparaison_DVCS_Pi0_integrated.eps");


  TCanvas *Missing_Mass_NORMALIZED = new TCanvas("Missing_Mass_NORMALIZED","Missing_Mass_NORMALIZED",1001,800); 
  Missing_Mass_NORMALIZED->Divide(3,4);

 for(Int_t m=1;m<=12;m++){
	Missing_Mass_NORMALIZED->cd(m);
    char nome_MM_NORMALIZED[30],nome_MM2_NORMALIZED[30];
    TH1F *histo_MM_NORMALIZED,*histo_MM2_NORMALIZED;
    sprintf(nome_MM_NORMALIZED,"MM%d_Bin",m);
    sprintf(nome_MM2_NORMALIZED,"MM%d_Bin",m);    


    TH1F *histo_MM_NoXsec_rapport;    f->GetObject(nome_MM_NORMALIZED,histo_MM_NoXsec_rapport); 
double Entries1 = histo_MM_NoXsec_rapport->GetEntries();  //Pour Normalisation  cou
    histo_MM_NoXsec_rapport-> SetLineColor(kRed);
    //histo_MM_NoXsec_rapport-> Scale(Entries1_N);
    histo_MM_NoXsec_rapport-> Draw("");	
cout<<"Entries1="<<Entries1<<endl;
 histo_MM_NoXsec_rapport->GetXaxis()->SetTitle("Mm(ed->en #gamma[X])(GeV)");
    int bmin =  histo_MM_NoXsec_rapport->GetXaxis()->FindBin(xmin); 
    int bmax =  histo_MM_NoXsec_rapport->GetXaxis()->FindBin(xmax);
    int bmax2 =  histo_MM_NoXsec_rapport->GetXaxis()->FindBin(xmax2);
    double integral1 =  histo_MM_NoXsec_rapport->Integral(bmin,bmax);
    double integral3 =  histo_MM_NoXsec_rapport->Integral(bmin,bmax2);	
	double Valeur_max1 = ( histo_MM_NoXsec_rapport->GetMaximum())*0.8; //Utile pour ajuster le print du label latex aprés
	double Valeur_max2 = ( histo_MM_NoXsec_rapport->GetMaximum())*0.7;    



    TH1F *histo_MM_NoXsec_rapport2;    h->GetObject(nome_MM_NORMALIZED,histo_MM_NoXsec_rapport2);   
double Entries2 = histo_MM_NoXsec_rapport2->GetEntries();  //Pour Normalisation
    histo_MM_NoXsec_rapport2-> SetLineColor(kBlack);
cout<<"Entries2="<<Entries2<<endl;
	double ratio=Entries1/Entries2; cout<<"ratio="<<ratio<<endl;
    histo_MM_NoXsec_rapport2-> Scale(ratio);
    histo_MM_NoXsec_rapport2-> Draw("sames");
	
int bmin = histo_MM_NoXsec_rapport2->GetXaxis()->FindBin(xmin); 
    int bmax = histo_MM_NoXsec_rapport2->GetXaxis()->FindBin(xmax); 
    double integral2 = histo_MM_NoXsec_rapport2->Integral(bmin,bmax);
	 
    double rapport=(integral2/integral1)*100.;
    double rapport2=(integral1/integral3)*100.;

    char text[100];
    sprintf(text,"Pi0 contamination=%d",rapport);
    TLatex *l5 = new TLatex(2.5,Valeur_max2,text);
    l5->SetTextSize(0.05);
    l5->SetTextFont(72);
    l5->SetTextColor(kBlack);
    l5->Draw("sames");

    sprintf(text,"DVCS Signal=%d",rapport2);
    TLatex *l6 = new TLatex(2.5,Valeur_max1,text);
    l6->SetTextSize(0.05);
    l6->SetTextFont(72);
    l6->SetTextColor(kBlack);
    l6->Draw("sames");
}
Missing_Mass_NORMALIZED->Print("Comparaison_DVCS_Pi0_renormalized.eps");






/*
  TCanvas *Missing_Mass_NEW = new TCanvas("Missing_Mass_NEW","Missing_Mass_NEW",1000,800); 
  Missing_Mass_NEW->Divide(3,4);

 	TH1F *hist_Mon_Divide_histo;
	  for(Int_t j=1;j<=12;j++)
	    {
	      char name_Mon_Divide_histo[30];
	      sprintf(name_Mon_Divide_histo,"Mon_Divide_histo%d_Bin",j);
	      hist_Mon_Divide_histo = new TH1F(name_Mon_Divide_histo,"MM",100,0.,4.);
	    }

 	TH1F *hist_Mon_Divide_histo2;
	  for(Int_t j=1;j<=12;j++)
	    {
	      char name_Mon_Divide_histo2[30];
	      sprintf(name_Mon_Divide_histo2,"Mon_Divide_histo2%d_Bin",j);
	      hist_Mon_Divide_histo2 = new TH1F(name_Mon_Divide_histo2,"MM",100,0.,4.);
	    }

  for(Int_t k=1;k<=12;k++){
    Missing_Mass_NEW->cd(k);
    char nome_MM[30],nome_MM2[30],nome_MM_NoXsec[30],nome_MM2_NoXsec[30];
    TH1F *histo_MM,*histo_MM2,*histo_MM_NoXsec,*histo_MM2_NoXsec;
    sprintf(nome_MM,"MM%d_Bin",k);
    sprintf(nome_MM2,"MM%d_Bin",k);
    sprintf(nome_MM_NoXsec,"MM_NoXsec%d_Bin",k);
    sprintf(nome_MM2_NoXsec,"MM_NoXsec%d_Bin",k);

    f->GetObject(nome_MM,histo_MM);
    h->GetObject(nome_MM2,histo_MM2);
    f->GetObject(nome_MM_NoXsec,histo_MM_NoXsec);
    h->GetObject(nome_MM2_NoXsec,histo_MM2_NoXsec);

    char name_phi5[30]; sprintf(name_phi5,"Mon_Divide_histo%d_Bin",k);
    TH1F *Divide_histo;
    Divide_histo->GetObject(name_phi5);    Divide_histo->Sumw2();
    //Divide_histo-> Divide(histo_MM,histo_MM_NoXsec,1.,1.);
    Divide_histo-> Divide(histo_MM,histo_MM_NoXsec,1.,1.);

    Divide_histo-> SetLineColor(kRed);
    Divide_histo-> Draw("");
    Divide_histo->GetXaxis()->SetTitle("Mm(ed->en #gamma[X])(GeV)");
    int bmin = Divide_histo->GetXaxis()->FindBin(xmin); 
    int bmax = Divide_histo->GetXaxis()->FindBin(xmax);
    int bmax2 = Divide_histo->GetXaxis()->FindBin(xmax2);
    double integral1 = Divide_histo->Integral(bmin,bmax);
    double integral3 = Divide_histo->Integral(bmin,bmax2);	
	double Valeur_max1 = (Divide_histo->GetMaximum())-2.; //Utile pour ajuster le print du label latex aprés
	double Valeur_max2 = (Divide_histo->GetMaximum())-7.;

    char name_phi6[30]; sprintf(name_phi6,"Mon_Divide_histo2%d_Bin",k);
    TH1F *Divide_histo2;
    Divide_histo2=(TH1F *)gDirectory->FindObject(name_phi6);    Divide_histo2->Sumw2();
    Divide_histo2-> Divide(histo_MM2,histo_MM2_NoXsec,1.,1.);


    Divide_histo2-> SetLineColor(kBlack);
    Divide_histo2-> Draw("sames");
    int bmin = Divide_histo2->GetXaxis()->FindBin(xmin); 
    int bmax = Divide_histo2->GetXaxis()->FindBin(xmax); 
    double integral2 = Divide_histo2->Integral(bmin,bmax);
	
    double rapport=(integral2/integral1)*100.;
    double rapport2=(integral1/integral3)*100.;

    char text[100];
    sprintf(text,"Pi0 contamination=%d",rapport);
    TLatex *l5 = new TLatex(2.5,Valeur_max2,text);
    l5->SetTextSize(0.05);
    l5->SetTextFont(72);
    l5->SetTextColor(kBlack);
    l5->Draw("sames");

    sprintf(text,"DVCS Signal=%d",rapport2);
    TLatex *l6 = new TLatex(2.5,Valeur_max1,text);
    l6->SetTextSize(0.05);
    l6->SetTextFont(72);
    l6->SetTextColor(kBlack);
    l6->Draw("sames");


  }
*/

/*
	double xmin= 0.;
	double xmax= 1.1;


//--------------------------------------------------------------------
//--------------------------------------------------------------------
	TCanvas *Missing_Mass_integreted = new TCanvas("Missing_Mass_integreted","Missing_Mass_integreted",1); 
       	Missing_Mass_integreted->cd();

	f= TFile::Open("/projet/nucleon/Baptiste/genepi/baptiste_code/ana_SAVE_comparaison_DVCS_PI0.root");
	MissingMass_SmearClas12_CLAS12_CUTS_2-> SetLineColor(kRed);
	MissingMass_SmearClas12_CLAS12_CUTS_2-> Draw("");
	MissingMass_SmearClas12_CLAS12_CUTS_2->GetXaxis()->SetTitle("Mm(ed->en #gamma[X])(GeV)");
  	 int bmin = MissingMass_SmearClas12_CLAS12_CUTS_2->GetXaxis()->FindBin(xmin); 
 	 int bmax = MissingMass_SmearClas12_CLAS12_CUTS_2->GetXaxis()->FindBin(xmax); 
 	 double integral1 = MissingMass_SmearClas12_CLAS12_CUTS_2->Integral(bmin,bmax);	
	TFile *g= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0/ana_SAVE_comparaison_DVCS_PI0.root");
	MissingMass_SmearClas12_CLAS12_CUTS_2-> SetLineColor(kBlack);
	MissingMass_SmearClas12_CLAS12_CUTS_2-> Draw("sames");
 	 int bmin = MissingMass_SmearClas12_CLAS12_CUTS_2->GetXaxis()->FindBin(xmin); 
 	 int bmax = MissingMass_SmearClas12_CLAS12_CUTS_2->GetXaxis()->FindBin(xmax); 
 	 double integral2 = MissingMass_SmearClas12_CLAS12_CUTS_2->Integral(bmin,bmax);
	double rapport=	(integral2/integral1)*100.;

 	 char text[100];
  	sprintf(text,"Pi0 contamination=%d ",rapport);
  	TLatex *l5 = new TLatex(2.5,5,text);
 	l5->SetTextSize(0.05);
  	l5->SetTextFont(72);
  	l5->SetTextColor(kBlack);
  	l5->Draw("sames");
//--------------------------------------------------------------------
//--------------------------------------------------------------------




	TCanvas *Missing_Mass = new TCanvas("Missing_Mass","Missing_Mass",1); 
       	Missing_Mass->Divide(3,4);
	//--------------------------------------------------------------------
	Missing_Mass->cd(1);
	f= TFile::Open("/projet/nucleon/Baptiste/genepi/baptiste_code/ana_SAVE_comparaison_DVCS_PI0.root");
	MM1_Bin-> SetLineColor(kRed);
	MM1_Bin-> Draw("");
	MM1_Bin->GetXaxis()->SetTitle("Mm(ed->en #gamma[X])(GeV)");
  	 int bmin = MM1_Bin->GetXaxis()->FindBin(xmin); cout<<"bmin="<<bmin<<endl;
 	 int bmax = MM1_Bin->GetXaxis()->FindBin(xmax); cout<<"bmax="<<bmax<<endl;
 	 double integral1 = MM1_Bin->Integral(bmin,bmax);	
	TFile *g= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0/ana_SAVE_comparaison_DVCS_PI0.root");
	MM1_Bin-> SetLineColor(kBlack);
	MM1_Bin-> Draw("sames");
 	 int bmin = MM1_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM1_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral2 = MM1_Bin->Integral(bmin,bmax);
	double rapport=	(integral2/integral1)*100.;

 	 char text[100];
  	sprintf(text,"Pi0 contamination=%d \%",rapport);
  	TLatex *l5 = new TLatex(2.5,5,text);
 	l5->SetTextSize(0.05);
  	l5->SetTextFont(72);
  	l5->SetTextColor(kBlack);
  	l5->Draw("sames");
    	
//--------------------------------------------------------------------
	Missing_Mass->cd(2);
	f= TFile::Open("/projet/nucleon/Baptiste/genepi/baptiste_code/ana_SAVE_comparaison_DVCS_PI0.root");
	MM2_Bin-> SetLineColor(kRed);
	MM2_Bin-> Draw("");
	MM2_Bin->GetXaxis()->SetTitle("Mm(ed->en #gamma[X])(GeV)");	
  	 int bmin = MM2_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM2_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral1 = MM2_Bin->Integral(bmin,bmax);
	TFile *g= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0/ana_SAVE_comparaison_DVCS_PI0.root");
	MM2_Bin-> SetLineColor(kBlack);
	MM2_Bin-> Draw("sames");
	int bmin = MM2_Bin->GetXaxis()->FindBin(xmin); 
 	int bmax = MM2_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral2 = MM2_Bin->Integral(bmin,bmax);	
	double rapport=	(integral2/integral1)*100.;

 	 char text[100];
  	sprintf(text,"Pi0 contamination=%d ",rapport);
  	TLatex *l5 = new TLatex(2.5,5,text);
 	l5->SetTextSize(0.05);
  	l5->SetTextFont(72);
  	l5->SetTextColor(kBlack);
  	l5->Draw("sames");
//--------------------------------------------------------------------
	Missing_Mass->cd(3);
	f= TFile::Open("/projet/nucleon/Baptiste/genepi/baptiste_code/ana_SAVE_comparaison_DVCS_PI0.root");
	MM3_Bin-> SetLineColor(kRed);
	MM3_Bin-> Draw("");
	MM3_Bin->GetXaxis()->SetTitle("Mm(ed->en #gamma[X])(GeV)");
 	int bmin = MM3_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM3_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral1 = MM3_Bin->Integral(bmin,bmax);	
	TFile *g= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0/ana_SAVE_comparaison_DVCS_PI0.root");
	MM3_Bin-> SetLineColor(kBlack);
	MM3_Bin-> Draw("sames");
	 int bmin = MM3_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM3_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral2 = MM3_Bin->Integral(bmin,bmax);
	double rapport=	(integral2/integral1)*100.;

 	 char text[100];
  	sprintf(text,"Pi0 contamination=%d ",rapport);
  	TLatex *l5 = new TLatex(2.5,5,text);
 	l5->SetTextSize(0.05);
  	l5->SetTextFont(72);
  	l5->SetTextColor(kBlack);
  	l5->Draw("sames");
//--------------------------------------------------------------------
	Missing_Mass->cd(4);
	f= TFile::Open("/projet/nucleon/Baptiste/genepi/baptiste_code/ana_SAVE_comparaison_DVCS_PI0.root");
	MM4_Bin-> SetLineColor(kRed);
	MM4_Bin-> Draw("");
	MM4_Bin->GetXaxis()->SetTitle("Mm(ed->en #gamma[X])(GeV)");
	 int bmin = MM4_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM4_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral1 = MM4_Bin->Integral(bmin,bmax);	
	TFile *g= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0/ana_SAVE_comparaison_DVCS_PI0.root");
	MM4_Bin-> SetLineColor(kBlack);
	MM4_Bin-> Draw("sames");
	 int bmin = MM4_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM4_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral2 = MM4_Bin->Integral(bmin,bmax);
	double rapport=	(integral2/integral1)*100.;

 	 char text[100];
  	sprintf(text,"Pi0 contamination=%d ",rapport);
  	TLatex *l5 = new TLatex(2.5,5,text);
 	l5->SetTextSize(0.05);
  	l5->SetTextFont(72);
  	l5->SetTextColor(kBlack);
  	l5->Draw("sames");
//--------------------------------------------------------------------
	Missing_Mass->cd(5);
	f= TFile::Open("/projet/nucleon/Baptiste/genepi/baptiste_code/ana_SAVE_comparaison_DVCS_PI0.root");
	MM5_Bin-> SetLineColor(kRed);
	MM5_Bin-> Draw("");
	MM5_Bin->GetXaxis()->SetTitle("Mm(ed->en #gamma[X])(GeV)");
	int bmin = MM5_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM5_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral1 = MM5_Bin->Integral(bmin,bmax);	
	TFile *g= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0/ana_SAVE_comparaison_DVCS_PI0.root");
	MM5_Bin-> SetLineColor(kBlack);
	MM5_Bin-> Draw("sames");
	 int bmin = MM5_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM5_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral2 = MM5_Bin->Integral(bmin,bmax);
	double rapport=	(integral2/integral1)*100.;

 	 char text[100];
  	sprintf(text,"Pi0 contamination=%d ",rapport);
  	TLatex *l5 = new TLatex(2.5,5,text);
 	l5->SetTextSize(0.05);
  	l5->SetTextFont(72);
  	l5->SetTextColor(kBlack);
  	l5->Draw("sames");
//--------------------------------------------------------------------
	Missing_Mass->cd(6);
	f= TFile::Open("/projet/nucleon/Baptiste/genepi/baptiste_code/ana_SAVE_comparaison_DVCS_PI0.root");
	MM6_Bin-> SetLineColor(kRed);
	MM6_Bin-> Draw("");
	MM6_Bin->GetXaxis()->SetTitle("Mm(ed->en #gamma[X])(GeV)");
	int bmin = MM6_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM6_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral1 = MM6_Bin->Integral(bmin,bmax);	
	TFile *g= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0/ana_SAVE_comparaison_DVCS_PI0.root");
	MM6_Bin-> SetLineColor(kBlack);
	MM6_Bin-> Draw("sames");
	int bmin = MM6_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM6_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral2 = MM6_Bin->Integral(bmin,bmax);
	double rapport=	(integral2/integral1)*100.;

 	 char text[100];
  	sprintf(text,"Pi0 contamination=%d ",rapport);
  	TLatex *l5 = new TLatex(2.5,5,text);
 	l5->SetTextSize(0.05);
  	l5->SetTextFont(72);
  	l5->SetTextColor(kBlack);
  	l5->Draw("sames");
//--------------------------------------------------------------------
	Missing_Mass->cd(7);
	f= TFile::Open("/projet/nucleon/Baptiste/genepi/baptiste_code/ana_SAVE_comparaison_DVCS_PI0.root");
	MM7_Bin-> SetLineColor(kRed);
	MM7_Bin-> Draw("");
	MM7_Bin->GetXaxis()->SetTitle("Mm(ed->en #gamma[X])(GeV)");	
	int bmin = MM7_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM7_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral1 = MM7_Bin->Integral(bmin,bmax);
	TFile *g= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0/ana_SAVE_comparaison_DVCS_PI0.root");
	MM7_Bin-> SetLineColor(kBlack);
	MM7_Bin-> Draw("sames");
	int bmin = MM7_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM7_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral2 = MM7_Bin->Integral(bmin,bmax);
	double rapport=	(integral2/integral1)*100.;

 	 char text[100];
  	sprintf(text,"Pi0 contamination=%d ",rapport);
  	TLatex *l5 = new TLatex(2.5,5,text);
 	l5->SetTextSize(0.05);
  	l5->SetTextFont(72);
  	l5->SetTextColor(kBlack);
  	l5->Draw("sames");
//--------------------------------------------------------------------
	Missing_Mass->cd(8);
	f= TFile::Open("/projet/nucleon/Baptiste/genepi/baptiste_code/ana_SAVE_comparaison_DVCS_PI0.root");
	MM8_Bin-> SetLineColor(kRed);
	MM8_Bin-> Draw("");
	MM8_Bin->GetXaxis()->SetTitle("Mm(ed->en #gamma[X])(GeV)");
	int bmin = MM8_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM8_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral1 = MM8_Bin->Integral(bmin,bmax);	
	TFile *g= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0/ana_SAVE_comparaison_DVCS_PI0.root");
	MM8_Bin-> SetLineColor(kBlack);
	MM8_Bin-> Draw("sames");
	int bmin = MM8_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM8_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral2 = MM8_Bin->Integral(bmin,bmax);
	double rapport=	(integral2/integral1)*100.;

 	 char text[100];
  	sprintf(text,"Pi0 contamination=%d ",rapport);
  	TLatex *l5 = new TLatex(2.5,5,text);
 	l5->SetTextSize(0.05);
  	l5->SetTextFont(72);
  	l5->SetTextColor(kBlack);
  	l5->Draw("sames");
//--------------------------------------------------------------------
	Missing_Mass->cd(9);
	f= TFile::Open("/projet/nucleon/Baptiste/genepi/baptiste_code/ana_SAVE_comparaison_DVCS_PI0.root");
	MM9_Bin-> SetLineColor(kRed);
	MM9_Bin-> Draw("");
	MM9_Bin->GetXaxis()->SetTitle("Mm(ed->en #gamma[X])(GeV)");
	int bmin = MM9_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM9_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral1 = MM9_Bin->Integral(bmin,bmax);	
	TFile *g= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0/ana_SAVE_comparaison_DVCS_PI0.root");
	MM9_Bin-> SetLineColor(kBlack);
	MM9_Bin-> Draw("sames");
	int bmin = MM9_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM9_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral2 = MM9_Bin->Integral(bmin,bmax);
	double rapport=	(integral2/integral1)*100.;

 	 char text[100];
  	sprintf(text,"Pi0 contamination=%d ",rapport);
  	TLatex *l5 = new TLatex(2.5,5,text);
 	l5->SetTextSize(0.05);
  	l5->SetTextFont(72);
  	l5->SetTextColor(kBlack);
  	l5->Draw("sames");
//--------------------------------------------------------------------
	Missing_Mass->cd(10);
	f= TFile::Open("/projet/nucleon/Baptiste/genepi/baptiste_code/ana_SAVE_comparaison_DVCS_PI0.root");
	MM10_Bin-> SetLineColor(kRed);
	MM10_Bin-> Draw("");
	MM10_Bin->GetXaxis()->SetTitle("Mm(ed->en #gamma[X])(GeV)");
	int bmin = MM10_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM10_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral1 = MM10_Bin->Integral(bmin,bmax);	
	TFile *g= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0/ana_SAVE_comparaison_DVCS_PI0.root");
	MM10_Bin-> SetLineColor(kBlack);
	MM10_Bin-> Draw("sames");
	int bmin = MM10_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM10_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral2 = MM10_Bin->Integral(bmin,bmax);
	double rapport=	(integral2/integral1)*100.;

 	 char text[100];
  	sprintf(text,"Pi0 contamination=%d ",rapport);
  	TLatex *l5 = new TLatex(2.5,5,text);
 	l5->SetTextSize(0.05);
  	l5->SetTextFont(72);
  	l5->SetTextColor(kBlack);
  	l5->Draw("sames");
//--------------------------------------------------------------------
	Missing_Mass->cd(11);
	f= TFile::Open("/projet/nucleon/Baptiste/genepi/baptiste_code/ana_SAVE_comparaison_DVCS_PI0.root");
	MM11_Bin-> SetLineColor(kRed);
	MM11_Bin-> Draw("");
	MM11_Bin->GetXaxis()->SetTitle("Mm(ed->en #gamma[X])(GeV)");
	int bmin = MM11_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM11_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral1 = MM11_Bin->Integral(bmin,bmax);		
	TFile *g= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0/ana_SAVE_comparaison_DVCS_PI0.root");
	MM11_Bin-> SetLineColor(kBlack);
	MM11_Bin-> Draw("sames");
	int bmin = MM11_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM11_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral2 = MM11_Bin->Integral(bmin,bmax);
	double rapport=	(integral2/integral1)*100.;

 	 char text[100];
  	sprintf(text,"Pi0 contamination=%d ",rapport);
  	TLatex *l5 = new TLatex(2.5,5,text);
 	l5->SetTextSize(0.05);
  	l5->SetTextFont(72);
  	l5->SetTextColor(kBlack);
  	l5->Draw("sames");
//--------------------------------------------------------------------
	Missing_Mass->cd(12);
	f= TFile::Open("/projet/nucleon/Baptiste/genepi/baptiste_code/ana_SAVE_comparaison_DVCS_PI0.root");
	MM12_Bin-> SetLineColor(kRed);
	MM12_Bin-> Draw("");
	MM12_Bin->GetXaxis()->SetTitle("Mm(ed->en #gamma[X])(GeV)");	
	int bmin = MM12_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM12_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral1 = MM12_Bin->Integral(bmin,bmax);	
	TFile *g= new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_pour_Pi0/ana_SAVE_comparaison_DVCS_PI0.root");
	MM12_Bin-> SetLineColor(kBlack);
	MM12_Bin-> Draw("sames");
	int bmin = MM12_Bin->GetXaxis()->FindBin(xmin); 
 	 int bmax = MM12_Bin->GetXaxis()->FindBin(xmax); 
 	 double integral2 = MM12_Bin->Integral(bmin,bmax);
	double rapport=	(integral2/integral1)*100.;

 	 char text[100];
  	sprintf(text,"Pi0 contamination=%d ",rapport);
  	TLatex *l5 = new TLatex(2.5,5,text);
 	l5->SetTextSize(0.05);
  	l5->SetTextFont(72);
  	l5->SetTextColor(kBlack);
  	l5->Draw("sames");

*/


//_____________________________________________________
/* 
  char text[100];
  sprintf(text,"Mm^{2}(ed->en #gamma[X])");
  TLatex *l5 = new TLatex(0,1,text);
  l5->SetTextSize(0.05);
  l5->SetTextFont(72);
  l5->SetTextColor(kBlack);
  l5->Draw("sames");


//  sprintf(text,"Mm^{2}(ed->en #gamma_{1}[X])");
//  TLatex *l6 = new TLatex(0,0,text);
//  l6->SetTextSize(0.05);
//  l6->SetTextFont(72);
//  l6->SetTextColor(kRed);
//  l6->Draw("sames");

  sprintf(text,"#Delta#theta_{N}=1.3#circ, #Delta#phi_{N}=3#circ, #frac{#DeltaP_{N}}{P_{N}}=4%");
  TLatex *l7 = new TLatex(0,1,text);
  l7->SetTextSize(0.04);
  l7->SetTextFont(72);
 l7->SetTextColor(kBlack);
 l7->Draw("sames");
*/


}
