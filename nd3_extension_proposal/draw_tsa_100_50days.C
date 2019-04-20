void draw_tsa_100_50days()
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
 Int_t const NQ2=4, NXB=4, NT=4, NPHI=12; 
 Int_t qbin,xbin,tbin;

 Float_t q_vec[NQ2+1]={1.,2.,3.5,5.,10.};
 Float_t x_vec[NXB+1]={0.05,0.15,0.3,0.45,0.7};
 Float_t t_vec[NT+1]={0.00,0.2,0.5,0.8,1.2};
 Float_t phi_vec[NPHI+1]={0.,30,60,90,130,150,180,210,240,270,300,330,360};

 Float_t qlow,qhigh,xlow,xhigh,thigh,tlow,philow,phihigh;

 Float_t rangeQ=q_vec[NQ2]-q_vec[0];
 Float_t rangeXB=x_vec[NXB]-x_vec[0];
 Float_t posQ[NQ2+1];
 Float_t posXB[NXB+10*NT+1];
 TFile *rootfile_noFT = new TFile("out_100days_noFT_newerr.root");
 TFile *rootfile_FT = new TFile("out_50days_noFT_newerr.root");

 char canvas[2],psnamebig[200],gifnamebig[200];
 sprintf(canvas,"g1");
 sprintf(psnamebig,"asym_polndvcs_tsa_newvgg_100_50days.pdf");
 sprintf(gifnamebig,"asym_polndvcs_tsa_newvgg_100_50days.jpg");
 TCanvas *g= new TCanvas(canvas,canvas,1000,800);
 Int_t padnb;
 
 for(Int_t p2=0;p2<NQ2+1;p2++) {
   posQ[p2]=0.092+(q_vec[p2]-q_vec[0])*0.85/rangeQ;	
 }
 for(Int_t p3=0;p3<NXB+1;p3++) 
   {
     for(Int_t t1=0;t1<NT+1;t1++)
       {
	 posXB[p3+10*t1]=0.092+0.85*(x_vec[p3]-x_vec[0])/(rangeXB)+0.85*t1*(x_vec[p3+1]-x_vec[p3])/(NT*rangeXB);
	 cout<<posXB[p3+10*t1]<<endl;
       }
   } 
 TGaxis *axisQ = new TGaxis(0.09,0.09,0.09,0.95,q_vec[0],q_vec[NQ2],510);
 TGaxis *axisXB = new TGaxis(0.09,0.09,0.95,0.09,x_vec[0],x_vec[NXB],510);
 axisQ->SetTitle("Q^{2} (GeV^{2})");
 axisXB->SetTitle("x_{B}");
 axisQ->Draw();
 axisXB->Draw();
 
 char titolo[30];
 TLatex t;

 // rootfile->cd();

 for(Int_t j=NQ2;j>0;j--)
   {
     for(Int_t i=1;i<NXB+1;i++)
       {
	 for(Int_t k=1;k<NT+1;k++)
	   {
	     g->cd();      
	     Int_t s,r,p,q;
	     char padname[20],histo_name[20];
	     TH1F *histo,*histo_noFT;
	     sprintf(histo_name,"p%d",j*100+i*10+k);
	     //	     histo = new TH1F(histo_name,"",NPHI,0.,360.);
	     cout<<histo_name<<endl;
	     padnb=k*10000+(NQ2+1-j)*100+i;
	     sprintf(padname,"pad_%d",padnb);
	     TPad *pad= new TPad(padname,padname,posXB[i-1+10*(k-1)],posQ[j-1],posXB[i-1+10*k],posQ[j]);
	     rootfile_noFT->GetObject(histo_name,histo_noFT);
	     rootfile_FT->GetObject(histo_name,histo);

	     cout<<histo->GetMaximum()<<endl;
	     pad->Draw();	      
	     pad->SetLeftMargin(0.05);
	     pad->SetRightMargin(0.05);
	     pad->SetTopMargin(0.01);
	     pad->SetBottomMargin(0.01);
	     pad->cd();

	     if(histo->GetMaximum()>0.000000001 && TMath::Abs(histo->GetBinContent(3))>0.0000000001)
	       {
		 cout<<"ARGHHHHH"<<endl;
		 histo->SetMaximum(1);
		 histo->SetMinimum(-1);
		 histo->SetTitleSize(0.1);
		 histo->SetMarkerStyle(8);
		 histo->SetMarkerColor(2);
		 histo->SetLineColor(2);
		 histo->SetMarkerSize(0.5);
		 histo->Draw("e");
		 histo_noFT->SetTitleSize(0.1);
		 histo_noFT->SetMarkerStyle(8);
		 histo_noFT->SetMarkerColor(1);
		 histo_noFT->SetMarkerSize(0.5);
		 histo_noFT->SetMarkerColor(1);
		 histo_noFT->SetLineColor(1);
		 if(histo_noFT->GetMaximum()>0.000000001 && TMath::Abs(histo_noFT->GetBinContent(3))>0.0000000001)histo_noFT->Draw("e,same");
	       }
	   }
       }
   }

 g-> Print(psnamebig);
 g-> Print(gifnamebig);
}
