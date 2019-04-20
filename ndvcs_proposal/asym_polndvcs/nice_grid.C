// Fitting function
Double_t function(Double_t *x, Double_t *par) {
  return par[0] +TMath::Sqrt(2*par[1]*(1+par[1]))*par[2]*TMath::Cos(x[0]/180.*TMath::Pi())+par[1]*par[3]*TMath::Cos(2*x[0]/180.*TMath::Pi());
  //  return par[0] + par[1]*TMath::Cos(x[0]/180.*TMath::Pi()) + par[2]*TMath::Cos(2*x[0]/180.*TMath::Pi());
}

void nice_grid()
{
gSystem->Load("libPhysics");
gROOT->SetStyle("Plain");
gStyle->SetPalette(1);
gStyle->SetOptStat(0);
gStyle->SetOptFit(111);
gStyle->SetPadBorderMode(0);
gStyle->SetCanvasColor(kWhite);
 gStyle->SetFrameFillColor(kWhite);

//TFile *data = new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_BIGSTAT_resP5_NOUVEAU_BINNING3/ana.root");
TFile *data = new TFile("/projet/nucleon/silvia/baptiste_code_BIGSTAT_newRES_FT/ana_3_17_10_35.root");
 Int_t const NQ2=4, NXB=4, NT=4, NPHI=12; 

 Int_t qbin,xbin,tbin;

 Float_t q_vec[NQ2+1]={1.,2.,3.5,5.,10.};
 Float_t x_vec[NXB+1]={0.05,0.15,0.3,0.45,0.7};
 Float_t t_vec[NT+1]={0.00,0.2,0.5,0.8,1.2};
 Float_t phi_vec[NPHI+1]={0.,30,60,90,120,150,180,210,240,270,300,330,360};
 Float_t qlow,qhigh,xlow,xhigh,thigh,tlow,philow,phihigh;

 Float_t rangeQ=q_vec[NQ2]-q_vec[0];
 Float_t rangeXB=x_vec[NXB]-x_vec[0];
 Float_t posQ[NQ2+1];
 Float_t posXB[NXB+1];

 Float_t rel_err[NQ2][NXB][NT][NPHI];

 char type[20];
 char title[200];
 Int_t number;

 for(Int_t r=1;r<4;r++)
   {
     if(r==1)
       {
	 sprintf(type,"acc");
	 number = 5;
	 sprintf(title,"Acceptance");
       }
     if(r==2)
       {
	 sprintf(type,"counts");
	 number = 4;
	 sprintf(title,"Counts/bin");
       }
     if(r==3)
       {
	 sprintf(type,"cs");
	 number = 6;
	 sprintf(title,"d#sigma/dQ^{2}dx_{B}dtd#phi (nb/GeV^{4})");
       }     
     for(Int_t k=1;k<NT+1;k++)
       {
	 char canvas[2],psnamebig[200];
	 sprintf(canvas,"g%d_%s",k,type);
	 sprintf(psnamebig,"plot_%s_%d_newcuts.eps",type,k);
	 TCanvas *g= new TCanvas(canvas,canvas,1000,800);
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
	 
	 Int_t counter=0;
	 thigh=t_vec[k];
	 tlow=t_vec[k-1];
	 
	 char titolo[30];
	 TLatex t,t1;
	 //      t.DrawLatex(0.15,0.92," vs #phi");
	 sprintf(titolo,"%g<-t<%g GeV^{2}",tlow,thigh);
	 t.DrawLatex(0.6,0.92,titolo);
	 for(Int_t j=NQ2;j>0;j--)
	   {
	     for(Int_t i=1;i<NXB+1;i++)
	       {
		 g->cd();
		 char padname[10],cr_name[30];
		 padnb=k*10000+(NQ2+1-j)*100+i;
		 sprintf(padname,"pad_%d",padnb);
		 TPad *pad= new TPad(padname,padname,posXB[i-1],posQ[j-1],posXB[i],posQ[j]);
		 if(r>1)pad->SetLogy();
		 pad->Draw();		 
		 TH1F *data_hist;
		 TH1F *new_hist;
		 char data_name[30],new_name[30];
		 qlow=q_vec[j-1];
		 qhigh=q_vec[j];
		 xlow=x_vec[i-1];
		 xhigh=x_vec[i];
		 sprintf(data_name,"p%d_%d",j*100+i*10+k,number);
		 sprintf(new_name,"p%d_%s",j*100+i*10+k,type);
		 data->GetObject(data_name,data_hist);
		 new_hist = new TH1F(new_name,"",NPHI,0.,360.);
		 pad->cd();
		 if(data_hist->Integral()>0){
		   data_hist->SetTitle("");
		   data_hist->GetXaxis()->SetTitle("#phi^{o}");
		   data_hist->GetYaxis()->SetTitle(title);
		   if(r==2)
		     {
		       sprintf(cr_name,"counts_newcuts_poltar_%d.dat",j*100+i*10+k);
		       ofstream cr_file(cr_name);
		       for(Int_t m=1;m<NPHI+1;m++)
			 {
			   Float_t counts = data_hist->GetBinContent(m);
			   new_hist->SetBinContent(m,counts);
       			   new_hist->SetBinError(m,TMath::Sqrt(counts));
			   //			   cout<<counts<<endl;
			   cr_file << counts << endl;
			   //			   cout<< j <<" "<<i<<" "<<k<<" "<<m<<endl;
			   if(counts>0)rel_err[j-1][i-1][k-1][m-1]=1/TMath::Sqrt(counts);
			   else rel_err[j-1][i-1][k-1][m-1] = 1;
			   cout<<100*rel_err[j-1][i-1][k-1][m-1]<<endl;
			 }
		       new_hist->Draw("e");
		       cr_file.close();
		     }
		   if(r==3)
		     {
		       for(Int_t m=1;m<NPHI+1;m++)
			 {
			   Float_t cs = data_hist->GetBinContent(m);
       			   data_hist->SetBinError(m,cs*rel_err[j-1][i-1][k-1][m-1]);
			 }
		       data_hist->Draw("e");
		     }
		   else data_hist->Draw("e");
		 }
	       }
	   }
	 //g->Print(psnamebig); 
       }
   }
}









