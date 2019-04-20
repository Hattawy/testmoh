Double_t function(Double_t *x, Double_t *par) {
  return par[0]*TMath::Sin(x[0]/180.*TMath::Pi())/(1+par[1]*TMath::Cos(x[0]/180.*TMath::Pi())+par[2]*TMath::Cos(2*x[0]/180.*TMath::Pi()));
}
void taux()
{
gSystem->Load("libPhysics");
gROOT->SetStyle("Plain");
gStyle->SetPalette(1);
gStyle->SetOptStat(0);
gStyle->SetOptFit(111);
gStyle->SetPadBorderMode(0);
gStyle->SetCanvasColor(kWhite);
 gStyle->SetFrameFillColor(kWhite);

 char filename[300];
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
 TF1 *fitFcn = new TF1("fitFcn",function,0,360,3);
 fitFcn->SetLineColor(2);
 fitFcn->SetLineWidth(0.5);
 Float_t X1[4][4][4][12], UPUP1[4][4][4][12],UPDN1[4][4][4][12], DNUP1[4][4][4][12],DNDN1[4][4][4][12],TOT1[4][4][4][12],A1[4][4][4][12],err[4][4][4][12],COUNTS[4][4][4][12];
 
 Float_t pol = .85;
 TH1F *histave;
 histave = new TH1F("Media","Media",100,0,4);
 // TCanvas *c=new TCanvas("c","c",1000,800);

  for(Int_t k=1;k<NT+1;k++)
    {
      char canvas[2],psnamebig[200];
      sprintf(canvas,"g%d",k);
      sprintf(psnamebig,"asym_%d_newcuts.eps",k);
      TCanvas *g= new TCanvas(canvas,canvas,1000,800);
      //      g->Divide(NXB,NQ2,0.001,0.001);
      Int_t padnb;
      
      for(Int_t p2=0;p2<NQ2+1;p2++) {
	//posQ[p2]=0.1+(q_vec[p2]-q_vec[0])*0.8/rangeQ;
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
      t.DrawLatex(0.15,0.92,"BSA vs #phi");
      sprintf(titolo,"%g<-t<%g (GeV^{2})",tlow,thigh);
      t.DrawLatex(0.6,0.92,titolo);



      for(Int_t j=NQ2;j>0;j--)
	{
	  for(Int_t i=1;i<NXB+1;i++)
	    {
	      g->cd();      
	      Int_t s,r;
	      char padname[20],histo_name[20],cr_name[200];
	      TH1F *histo;
	      Float_t x1,upup1,updn1,dnup1,dndn1,tot1,a1,counts;
	      sprintf(histo_name,"p%d",j*100+i*10+k);
	      sprintf(cr_name,"/projet/nucleon/silvia/ndvcs_proposal/counts_newcuts_%d.dat",j*100+i*10+k);
	      histo = new TH1F(histo_name,"",NPHI,0.,360.);
	      padnb=k*10000+(NQ2+1-j)*100+i;
	      sprintf(padname,"pad_%d",padnb);
	      TPad *pad= new TPad(padname,padname,posXB[i-1],posQ[j-1],posXB[i],posQ[j]);
	      pad->Draw();	      
	      sprintf(filename,"results_michel/ndvcs_xbin%d_qbin%d_tbin%d.dat",i,j,k);
	      s=0;
	      r=0;
	      //	      cout<<filename<<endl;
	      ifstream file = (filename);
	      while (1) {
		file >> x1 >> upup1 >> updn1 >> dnup1 >> dndn1 >> tot1; 
		if((upup1+updn1+dnup1+dndn1)!=0){
		  a1 = (upup1+updn1-dnup1-dndn1)/(upup1+updn1+dnup1+dndn1);}
		else a1 = 0;
		//		X1[j-1][i-1][k-1][s]=x1;
		UPUP1[j-1][i-1][k-1][s]=upup1;
		UPDN1[j-1][i-1][k-1][s]=updn1;
		DNUP1[j-1][i-1][k-1][s]=dnup1;
		DNDN1[j-1][i-1][k-1][s]=dndn1;		
		A1[j-1][i-1][k-1][s]=a1;
		s++;		
		if (!file.good()) break; 
	      }
	      file.close();
// 	      X1[j-1][i-1][k-1][11]=-X1[j-1][i-1][k-1][0];
// 	      X1[j-1][i-1][k-1][10]=-X1[j-1][i-1][k-1][1];
// 	      X1[j-1][i-1][k-1][9]=-X1[j-1][i-1][k-1][2];
// 	      X1[j-1][i-1][k-1][8]=-X1[j-1][i-1][k-1][3];
// 	      X1[j-1][i-1][k-1][7]=-X1[j-1][i-1][k-1][4];
// 	      X1[j-1][i-1][k-1][6]=-X1[j-1][i-1][k-1][5];

	      A1[j-1][i-1][k-1][11]=-A1[j-1][i-1][k-1][0];
	      A1[j-1][i-1][k-1][10]=-A1[j-1][i-1][k-1][1];
	      A1[j-1][i-1][k-1][9]=-A1[j-1][i-1][k-1][2];
	      A1[j-1][i-1][k-1][8]=-A1[j-1][i-1][k-1][3];
	      A1[j-1][i-1][k-1][7]=-A1[j-1][i-1][k-1][4];
	      A1[j-1][i-1][k-1][6]=-A1[j-1][i-1][k-1][5];

	      pad->cd();

              ifstream cr_file = (cr_name);
              while (1) {
                cr_file >> counts;
                COUNTS[j-1][i-1][k-1][r]= counts;
		//cout<<COUNTS[j-1][i-1][k-1][r]<<endl;
		//cout<<counts<<endl;
		r++;
                if (!cr_file.good()) break;
              }

	      fitFcn->SetParameters(0.1,0.1,0.,0.);
	      fitFcn->SetParLimits(0,-1,1);
	      fitFcn->SetParLimits(1,-1,1);
	      fitFcn->SetParLimits(2,-1,1);

	      for(Int_t l=1;l<NPHI+1;l++)
		{
		  if(COUNTS[j-1][i-1][k-1][l-1]!=0)
		    {
		      err[j-1][i-1][k-1][l-1]=(1/pol)*TMath::Sqrt((1-(pol*A1[j-1][i-1][k-1][l-1])*(1-(pol*A1[j-1][i-1][k-1][l-1])))/COUNTS[j-1][i-1][k-1][l-1]);
		    }
 		  else if(COUNTS[j-1][i-1][k-1][l-1]==0)
 		    {
 		      err[j-1][i-1][k-1][l-1]=1;
 		      A1[j-1][i-1][k-1][l-1]=0;
 		    }
		  histo->SetBinContent(l, A1[j-1][i-1][k-1][l-1]);
		  histo->SetBinError(l, err[j-1][i-1][k-1][l-1]);	
		}
	      if(histo->GetMaximum()>0.0001){
		//if(k!=2)
		//{
		    histo->SetMaximum(0.15);
		    histo->SetMinimum(-0.15);
		    //}
		// if(k==2)
		//   {
		//     histo->SetMaximum(0.08);		    
		//     histo->SetMinimum(-0.08);
		//   }
		histo->SetTitleSize(0.1);
		histo->SetMarkerStyle(8);
		histo->SetMarkerSize(0.5);
		//histo->Fit("fitFcn","b");
		histo->Draw("e");
	      }
	    }  
	}
      g-> Print(psnamebig);
    }
}
