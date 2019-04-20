void plots_nice()
{
gSystem->Load("libPhysics");
gROOT->SetStyle("Plain");
gStyle->SetPalette(1);
gStyle->SetOptStat(0);
 gStyle->SetOptFit(111);
 gStyle->SetCanvasColor(kWhite);
 gStyle->SetFrameFillColor(kWhite);


 TCanvas *g= new TCanvas("c1","c",1000,800);
 g->Divide(1,3,0.001,0.001);

 TFile *data = new TFile("/projet/nucleon/Baptiste/genepi/baptiste_code_BIGSTAT_newRES_FT/ana.root");


 TH1F *new_hist;
 char new_name[30];
 Float_t rel_err[12];
 new_hist = new TH1F(new_name,";#phi (degrees);Counts/bin",12,0.,360.);
 for(Int_t m=1;m<12+1;m++)
   {
     Float_t counts = p222_4->GetBinContent(m);
     new_hist->SetBinContent(m,counts);
     new_hist->SetBinError(m,TMath::Sqrt(counts));
     //			   new_hist->SetTitle("");
     rel_err[m]=1/TMath::Sqrt(counts);
     Float_t err_cs = rel_err[m]*p222_6->GetBinContent(m);
     p222_6->SetBinError(m,err_cs);
   }
 g->cd(1);
 gPad->SetLogy();
 p222_6->GetXaxis()->SetTitle("#phi (degrees)");
 p222_6->GetYaxis()->SetTitle("d#sigma/dQ^{2}dtdx_{B}d#phi (nb/GeV^{4})");
 p222_6->SetTitle("");
 p222_6->Draw("e");

 g->cd(2);
 p222_5->GetXaxis()->SetTitle("#phi (degrees)");
 p222_5->GetYaxis()->SetTitle("Acceptance");
 p222_5->SetTitle("");
 p222_5->Draw("e");

 g->cd(3);
 gPad->SetLogy();

 new_hist->Draw("e");

 // p222_4->GetXaxis()->SetTitle("#phi (degrees)");
 //p222_4->GetYaxis()->SetTitle("Counts/bin");
 //p222_4->Draw("e");

 g->Print("results_cr_test.eps"); 

 Float_t integral = Neutron_Momemtum_TOT_Before_CUTs->Integral();
 // cout<<integral<<endl;
 Float_t integral_cut = Neutron_Momemtum_TOT_Before_CUTs->Integral(63,69);
 cout<<integral_cut/integral<<endl;
 

}










