void plot_giulia_comp()
{
  gSystem->Load("libPhysics");
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(111);
  gStyle->SetFrameFillColor(0);

  char canvas[30];
  sprintf(canvas,"g1");
  TCanvas *g= new TCanvas(canvas,canvas,1000,800);
  
  Float_t pos[5]={-2,-1,0,1,2};

  Float_t sig_r[5]={135.8,135.0,120.0,107.1,104.5};
  Float_t sig_r2[5]={155,153.9,131.1,120.4,113.8};

  Float_t sig_l[5]={194.3,205.9,204.3,260.5,261.9};
  Float_t sig_l2[5]={204.7,211.4,224.7,258.5,280.8};
 
  g->cd();
  TGraph *l1,*l11;
  l1=new TGraph(5,pos,sig_r);  
  l1->SetMarkerStyle(20);
  l1->SetMarkerSize(1.6);
  l1->SetMarkerColor(3);
  l1->SetMaximum(300);
  l1->SetMinimum(0);
  l11=new TGraph(5,pos,sig_r2);  
  l11->SetMarkerStyle(24);
  l11->SetMarkerSize(1.6);
  l11->SetMarkerColor(3);
  l11->SetMaximum(300);
  l11->SetMinimum(0);
  char title[400];
  sprintf(title,"One-layer prototype, cosmic rays");
  l1->SetTitle(title);
  l1->Draw("AP");
  l1->GetXaxis()->SetTitle("Position");
  l1->GetYaxis()->SetTitle("#\sigma_{t}");
  l11->Draw("EPsame");
  TGraph *l,*ll;
  l=new TGraph(5,pos,sig_l); 
  l->SetMarkerStyle(22);
  l->SetMarkerSize(1.6);
  l->SetMarkerColor(2);
  l->Draw("EPsame");
  ll=new TGraph(5,pos,sig_l2); 
  ll->SetMarkerStyle(26);
  ll->SetMarkerSize(1.6);
  ll->SetMarkerColor(2);
  ll->Draw("EPsame");
  
  TLatex t;
  t.SetTextSize(0.03);
  t.SetTextColor(2);
  t.DrawLatex(-2,60,"'Neighbor' PMT");
  t.SetTextColor(3);
  t.DrawLatex(-2,30,"'Direct' PMT");
  t.SetTextColor(1);
  t.DrawLatex(1,60,"Full: R2083");
  t.DrawLatex(1,30,"Empty: R9779");

  g->Print("time_res_comparison.jpg");

}
