void plot_field_nice()
{
  gSystem->Load("libPhysics");
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(111);

  TCanvas *g= new TCanvas("c","c",1000,800);
  TCanvas *c= new TCanvas("g","g",1000,800);
  TCanvas *g1= new TCanvas("c1","c1",1000,800);
  TCanvas *c1= new TCanvas("g1","g1",1000,800);

  Float_t z1[3]={1.480,1.534,1.588};
  Float_t x1[3]={1.193,1.121,1.048};

  outfile = new TFile("field.root");

  outfile->cd();
  h1 = new TH2D("h1","Absolute value of the field (T);z (m); r(m)",300,0,3,300,0,3);
  h2 = new TH2D("h2","#theta;z (m); r(m)",300,0,3,300,0,3);
  g1->cd();
  Field->Draw("B>>h3","x>1.048 && x<1.193 && z>1.48 && z<1.588"); 
  c1->cd();
  Field->Draw("theta>>h4","x>1.048 && x<1.193 && z>1.48 && z<1.588"); 
  h3->Fit("gaus");
  h4->Fit("gaus");
  g1->Print("field_cut.eps");
  c1->Print("theta_cut.eps");

  g->cd();
  //  gStyle->SetOptLogz(1);
  h1->SetMinimum(1e-6);
  //  h1->SetMaximum(10);
  Field->Draw("x:z>>h1","B"); 
  Field->Draw("x:z>>h2","theta"); 
  h1->Draw("colz");
  TGraph *l1;
  l1=new TGraph(3,z1,x1);
  l1->SetMarkerStyle(22);
  l1->SetMarkerSize(2);
  l1->SetMarkerColor(10);
  l1->Draw("Psame");

  c->cd();
  gStyle->SetOptLogz(0);
  h2->SetMinimum(-90);
  h2->SetMaximum(90);
  h2->Draw("colz");
  l1->Draw("Psame");
  g->Print("field.eps");
  c->Print("theta.eps");


}
