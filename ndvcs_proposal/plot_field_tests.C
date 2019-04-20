void plot_field_tests()
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
  
  Float_t pos10[21]={0,100,110,120,130,140,150,160,170,180};
  Float_t pos21[21]={0,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290};

  Float_t th0_25[10]={400,400,400,360,320,300,200,100,40,7};
  Float_t th0_50[21]={400,400,400,400,400,400,400,360,320,280,260,200,160,130,90,50,32,15,5,4,3};

  Float_t th30_25[10]={400,400,400,380,340,300,230,200,80,30};
  Float_t th30_50[21]={400,400,400,400,400,400,400,360,340,320,300,250,160,120,80,40,20,8,5,5,5};
 
  g->cd();
  TGraph *l1,*l11;
  l1=new TGraph(21,pos21,th0_50);  
  l1->SetMarkerStyle(20);
  l1->SetMarkerSize(1.6);
  l1->SetMarkerColor(3);
  l1->SetMaximum(450);
  l1->SetMinimum(0);
  l11=new TGraph(21,pos21,th30_50);  
  l11->SetMarkerStyle(24);
  l11->SetMarkerSize(1.6);
  l11->SetMarkerColor(3);
  l11->SetMaximum(450);
  l11->SetMinimum(0);
  char title[400];
  sprintf(title,"");
  l1->SetTitle(title);
  l1->Draw("AP");
  l1->GetXaxis()->SetTitle("B(G)");
  l1->GetYaxis()->SetTitle("Amplitude (mV)");
  l11->Draw("EPsame");
  TGraph *l,*ll;
  l=new TGraph(10,pos10,th0_25); 
  l->SetMarkerStyle(22);
  l->SetMarkerSize(1.6);
  l->SetMarkerColor(2);
  l->Draw("EPsame");
  ll=new TGraph(10,pos10,th30_25); 
  ll->SetMarkerStyle(26);
  ll->SetMarkerSize(1.6);
  ll->SetMarkerColor(2);
  ll->Draw("EPsame");
  
  TLatex t;
  t.SetTextSize(0.025);
  t.SetTextColor(2);
  t.DrawLatex(220,400,"Shielding 2.5 mm");
  t.SetTextColor(3);
  t.DrawLatex(220,380,"Shielding 5 mm");
  t.SetTextColor(1);
  t.DrawLatex(220,360,"Full: #theta = 0^{o}");
  t.DrawLatex(220,340,"Empty: #theta = 30^{o} ");

  TArrow *a;
  a = new TArrow(215,50,215,120,0.01,"|>");
  a->SetLineColor(4);
  a->SetFillColor(4);
  a->SetLineWidth(3);
  a->SetFillStyle(1001);
  a->Draw();

  g->Print("field_tests_comparison.eps");

}
