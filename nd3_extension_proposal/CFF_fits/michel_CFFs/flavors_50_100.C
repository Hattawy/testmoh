void flavors_50_100()
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
  
  TCanvas *g1= new TCanvas("c","c",1000,800);
  g1->Divide(2,2,0.001,0.001);

  Double_t t_vec[4]={0.1,0.35,0.65,1.0};
  Double_t t_vec_50[4]={0.12,0.37,0.67,1.02};
  Double_t err_t[4]={0.,0.,0.,0.};
  Double_t t_vec2[4]={0.09,0.34,0.64,0.99};
  Double_t t_vec2_50[4]={0.11,0.36,0.66,1.01};

  Double_t h1_mick[4]={3.76332,1.79738,0.843363,0.418659};
  Double_t err_p_h1_mick[4]={0.0434852,0.0145534,0.0156967,0.0203703};
  Double_t err_m_h1_mick[4]={0.0433271,0.0144761,0.0156579,0.0204733};

  Double_t h1[4]={1.56181,0.775065,0.231237,0.0662225};
  Double_t err_p_h1[4]={0.222029,0.150055,0.386977,0.147102};
  Double_t err_m_h1[4]={1.52997,0.180008,0.133519,0.0996073};

  Double_t h1_50[4]={1.54094,0.70291,0.227732,0.0641366};
  Double_t err_p_h1_50[4]={0.283154,0.181769,0.510478,0.187385};
  Double_t err_m_h1_50[4]={1.99211,0.205925,0.158381,0.116767};

  Double_t h2_mick[4]={1.5558,1.24619,0.784293,0.523831};
  Double_t err_p_h2_mick[4]={0.0375647,0.0255718,0.023106,0.0286174};
  Double_t err_m_h2_mick[4]={0.0371835,0.0253437,0.0226669,0.0277903};

  Double_t h2[4]={1.67878,0.893826,0.468709,0.210496};
  Double_t err_p_h2[4]={0.836267,0.322954,0.179592,0.177177};
  Double_t err_m_h2[4]={1.3034,0.522636,0.260991,0.177355};

  Double_t h2_50[4]={1.86338,0.889969,0.444782,0.194157};
  Double_t err_p_h2_50[4]={1.12592,0.38467,0.234238,0.313616};
  Double_t err_m_h2_50[4]={1.24174,0.665316,0.315758,0.213857};


  Double_t h1_d[4],h2_d[4],h1_u[4],h2_u[4];
  Double_t e_p_h1_d[4],e_p_h2_d[4],e_p_h1_u[4],e_p_h2_u[4];
  Double_t e_m_h1_d[4],e_m_h2_d[4],e_m_h1_u[4],e_m_h2_u[4];

  Double_t h1_d_50[4],h2_d_50[4],h1_u_50[4],h2_u_50[4];
  Double_t e_p_h1_d_50[4],e_p_h2_d_50[4],e_p_h1_u_50[4],e_p_h2_u_50[4];
  Double_t e_m_h1_d_50[4],e_m_h2_d_50[4],e_m_h1_u_50[4],e_m_h2_u_50[4];


  for(Int_t i=0;i<4;i++)
    {
      h1_u[i]=9./15.*(4*h1_mick[i]-h1[i]);
      h1_d[i]=9./15.*(4*h1[i]-h1_mick[i]);
      h2_u[i]=9./15.*(4*h2_mick[i]-h2[i]);
      h2_d[i]=9./15.*(4*h2[i]-h2_mick[i]);
      e_p_h1_u[i]=9./15.*TMath::Sqrt(4*err_p_h1_mick[i]*err_p_h1_mick[i]+err_p_h1[i]*err_p_h1[i]);
      e_p_h1_d[i]=9./15.*TMath::Sqrt(err_p_h1_mick[i]*err_p_h1_mick[i]+4*err_p_h1[i]*err_p_h1[i]);
      e_m_h1_u[i]=9./15.*TMath::Sqrt(4*err_m_h1_mick[i]*err_m_h1_mick[i]+err_m_h1[i]*err_m_h1[i]);
      e_m_h1_d[i]=9./15.*TMath::Sqrt(err_m_h1_mick[i]*err_m_h1_mick[i]+4*err_m_h1[i]*err_m_h1[i]);
      e_p_h2_u[i]=9./15.*TMath::Sqrt(4*err_p_h2_mick[i]*err_p_h2_mick[i]+err_p_h2[i]*err_p_h2[i]);
      e_p_h2_d[i]=9./15.*TMath::Sqrt(err_p_h2_mick[i]*err_p_h2_mick[i]+4*err_p_h2[i]*err_p_h2[i]);
      e_m_h2_u[i]=9./15.*TMath::Sqrt(4*err_m_h2_mick[i]*err_m_h2_mick[i]+err_m_h2[i]*err_m_h2[i]);
      e_m_h2_d[i]=9./15.*TMath::Sqrt(err_m_h2_mick[i]*err_m_h2_mick[i]+4*err_m_h2[i]*err_m_h2[i]);

      h1_u_50[i]=9./15.*(4*h1_mick[i]-h1_50[i]);
      h1_d_50[i]=9./15.*(4*h1_50[i]-h1_mick[i]);
      h2_u_50[i]=9./15.*(4*h2_mick[i]-h2_50[i]);
      h2_d_50[i]=9./15.*(4*h2_50[i]-h2_mick[i]);
      e_p_h1_u_50[i]=9./15.*TMath::Sqrt(4*err_p_h1_mick[i]*err_p_h1_mick[i]+err_p_h1_50[i]*err_p_h1_50[i]);
      e_p_h1_d_50[i]=9./15.*TMath::Sqrt(err_p_h1_mick[i]*err_p_h1_mick[i]+4*err_p_h1_50[i]*err_p_h1_50[i]);
      e_m_h1_u_50[i]=9./15.*TMath::Sqrt(4*err_m_h1_mick[i]*err_m_h1_mick[i]+err_m_h1_50[i]*err_m_h1_50[i]);
      e_m_h1_d_50[i]=9./15.*TMath::Sqrt(err_m_h1_mick[i]*err_m_h1_mick[i]+4*err_m_h1_50[i]*err_m_h1_50[i]);
      e_p_h2_u_50[i]=9./15.*TMath::Sqrt(4*err_p_h2_mick[i]*err_p_h2_mick[i]+err_p_h2_50[i]*err_p_h2_50[i]);
      e_p_h2_d_50[i]=9./15.*TMath::Sqrt(err_p_h2_mick[i]*err_p_h2_mick[i]+4*err_p_h2_50[i]*err_p_h2_50[i]);
      e_m_h2_u_50[i]=9./15.*TMath::Sqrt(4*err_m_h2_mick[i]*err_m_h2_mick[i]+err_m_h2_50[i]*err_m_h2_50[i]);
      e_m_h2_d_50[i]=9./15.*TMath::Sqrt(err_m_h2_mick[i]*err_m_h2_mick[i]+4*err_m_h2_50[i]*err_m_h2_50[i]);


    }

  gr_h1_mick = new TGraphAsymmErrors(4,t_vec2,h1_mick,err_t,err_t,err_p_h1_mick,err_m_h1_mick);
  
  gr_h2_mick = new TGraphAsymmErrors(4,t_vec2,h2_mick,err_t,err_t,err_p_h2_mick,err_m_h2_mick);

  gr_h1 = new TGraphAsymmErrors(4,t_vec,h1,err_t,err_t,err_p_h1,err_m_h1);
  
  gr_h2 = new TGraphAsymmErrors(4,t_vec,h2,err_t,err_t,err_p_h2,err_m_h2);

  gr_u1 = new TGraphAsymmErrors(4,t_vec2,h1_u,err_t,err_t,e_p_h1_u,e_m_h1_u);
  
  gr_u2 = new TGraphAsymmErrors(4,t_vec2,h2_u,err_t,err_t,e_p_h2_u,e_m_h2_u);

  gr_d1 = new TGraphAsymmErrors(4,t_vec,h1_d,err_t,err_t,e_p_h1_d,e_m_h1_d);
  
  gr_d2 = new TGraphAsymmErrors(4,t_vec,h2_d,err_t,err_t,e_p_h2_d,e_m_h2_d);

  gr_h1_50 = new TGraphAsymmErrors(4,t_vec_50,h1_50,err_t,err_t,err_p_h1_50,err_m_h1_50);

  gr_h2_50 = new TGraphAsymmErrors(4,t_vec_50,h2_50,err_t,err_t,err_p_h2_50,err_m_h2_50);

  gr_u1_50 = new TGraphAsymmErrors(4,t_vec2_50,h1_u_50,err_t,err_t,e_p_h1_u_50,e_m_h1_u_50);

  gr_u2_50 = new TGraphAsymmErrors(4,t_vec2_50,h2_u_50,err_t,err_t,e_p_h2_u_50,e_m_h2_u_50);

  gr_d1_50 = new TGraphAsymmErrors(4,t_vec_50,h1_d_50,err_t,err_t,e_p_h1_d_50,e_m_h1_d_50);

  gr_d2_50 = new TGraphAsymmErrors(4,t_vec_50,h2_d_50,err_t,err_t,e_p_h2_d_50,e_m_h2_d_50);


  g1->cd(1);
  
  gr_h1_mick->SetMaximum(4);
  gr_h1_mick->SetMinimum(-1);
  gr_h1_mick->SetTitle();
  gr_h1_mick->SetMarkerStyle(20);
  gr_h1_mick->SetMarkerSize(0.5);
  gr_h1_mick->SetLineColor(1);
  gr_h1_mick->SetMarkerColor(1);
  gr_h1_mick->GetXaxis()->SetTitle("-t (GeV^{2})");
  gr_h1_mick->GetYaxis()->SetTitle("H_{Im}(N)");
  gr_h1_mick->Draw("AP,same");
  gr_h1->SetMarkerStyle(20);
  gr_h1->SetMarkerSize(0.5);
  gr_h1->SetLineColor(2);
  gr_h1->SetMarkerColor(2);
  gr_h1->Draw("P,same");
  gr_h1_50->SetMarkerStyle(24);
  gr_h1_50->SetMarkerSize(0.5);
  gr_h1_50->SetLineColor(2);
  gr_h1_50->SetMarkerColor(2);
  gr_h1_50->Draw("P,same");



 TLegend* leg = new TLegend(0.85, 0.85, 0.6, 0.6);
 leg->SetHeader("Q^{2}=2.6 GeV^{2}, x_{B}=0.23");
   leg->SetFillStyle(0);
 leg->SetTextSize(0.035);
 // leg->SetTextFont(132); 
 leg->SetLineColor(0);
 leg->AddEntry(gr_h1_mick,"H_{Im}(p)", "lep");
 leg->AddEntry(gr_h1,"H_{Im}(n) 100 days", "lep");
 leg->AddEntry(gr_h1_50,"H_{Im}(n) 50 days", "lep");
 leg->Draw();

  g1->cd(2);
  gr_h2_mick->SetMaximum(3.5);
  gr_h2_mick->SetMinimum(-1);
  gr_h2_mick->SetTitle();
  gr_h2_mick->SetMarkerStyle(20);
  gr_h2_mick->SetMarkerSize(0.5);
  gr_h2_mick->SetLineColor(1);
  gr_h2_mick->SetMarkerColor(1);
  gr_h2_mick->GetXaxis()->SetTitle("-t (GeV^{2})");
  gr_h2_mick->GetYaxis()->SetTitle("H_{Im}(N)");
  gr_h2_mick->Draw("AP,same");
  gr_h2->SetMarkerStyle(20);
  gr_h2->SetMarkerSize(0.5);
  gr_h2->SetLineColor(2);
  gr_h2->SetMarkerColor(2);
  gr_h2->Draw("P,same");
  gr_h2_50->SetMarkerStyle(24);
  gr_h2_50->SetMarkerSize(0.5);
  gr_h2_50->SetLineColor(2);
  gr_h2_50->SetMarkerColor(2);
  gr_h2_50->Draw("P,same");

 TLegend* leg2 = new TLegend(0.85, 0.85, 0.6, 0.6);
 leg2->SetHeader("Q^{2}=5.9 GeV^{2}, x_{B}=0.35");
 leg2->SetFillStyle(0);
 leg2->SetTextSize(0.035);
 // leg->SetTextFont(132); 
 leg2->SetLineColor(0);
 leg2->AddEntry(gr_h2_mick,"H_{Im}(p)", "lep");
 leg2->AddEntry(gr_h2,"H_{Im}(n) 100 days", "lep");
 leg2->AddEntry(gr_h2_50,"H_{Im}(n) 100 days", "lep");
 leg2->Draw();

  g1->cd(3);
  
  gr_d1->SetMaximum(10);
  gr_d1->SetMinimum(-1);
  gr_d1->SetTitle();
  gr_d1->SetMarkerStyle(22);
  gr_d1->SetMarkerSize(0.7);
  gr_d1->SetLineColor(2);
  gr_d1->SetMarkerColor(2);
  gr_d1->GetXaxis()->SetTitle("-t (GeV^{2})");
  gr_d1->GetYaxis()->SetTitle("H_{Im}(q)");
  gr_d1->Draw("AP,same");
  gr_u1->SetMarkerStyle(22);
  gr_u1->SetMarkerSize(0.7);
  gr_u1->SetLineColor(1);
  gr_u1->SetMarkerColor(1);
  gr_u1->Draw("P,same");
  gr_d1_50->SetMarkerStyle(26);
  gr_d1_50->SetMarkerSize(0.7);
  gr_d1_50->SetLineColor(2);
  gr_d1_50->SetMarkerColor(2);
  gr_d1_50->Draw("P,same");
  gr_u1_50->SetMarkerStyle(26);
  gr_u1_50->SetMarkerSize(0.7);
  gr_u1_50->SetLineColor(1);
  gr_u1_50->SetMarkerColor(1);
  gr_u1_50->Draw("P,same");



  TLegend* leg3 = new TLegend(0.85, 0.85, 0.6, 0.6);
 leg3->SetHeader("Q^{2}=2.6 GeV^{2}, x_{B}=0.23");
 leg3->SetFillStyle(0);
 leg3->SetTextSize(0.035);
 // leg->SetTextFont(132); 
 leg3->SetLineColor(0);
 leg3->AddEntry(gr_d1,"H_{Im}(d) 100 days", "lep");
 leg3->AddEntry(gr_u1,"H_{Im}(u) 100 days", "lep");
 leg3->AddEntry(gr_d1_50,"H_{Im}(d) 50 days", "lep");
 leg3->AddEntry(gr_u1_50,"H_{Im}(u) 50 days", "lep");
 leg3->Draw();
  g1->cd(4);
  
  gr_d2->SetMaximum(6);
  gr_d2->SetMinimum(-1);
  gr_d2->SetTitle();
  gr_d2->SetMarkerStyle(22);
  gr_d2->SetMarkerSize(0.7);
  gr_d2->SetLineColor(2);
  gr_d2->SetMarkerColor(2);
  gr_d2->GetXaxis()->SetTitle("-t (GeV^{2})");
  gr_d2->GetYaxis()->SetTitle("H_{Im}(q)");
  gr_d2->Draw("AP,same");
  gr_u2->SetMarkerStyle(22);
  gr_u2->SetMarkerSize(0.7);
  gr_u2->SetLineColor(1);
  gr_u2->SetMarkerColor(1);
  gr_u2->Draw("P,same");
  gr_d2_50->SetMarkerStyle(26);
  gr_d2_50->SetMarkerSize(0.7);
  gr_d2_50->SetLineColor(2);
  gr_d2_50->SetMarkerColor(2);
  gr_d2_50->Draw("P,same");
  gr_u2_50->SetMarkerStyle(26);
  gr_u2_50->SetMarkerSize(0.7);
  gr_u2_50->SetLineColor(1);
  gr_u2_50->SetMarkerColor(1);
  gr_u2_50->Draw("P,same");


 
  TLegend* leg4 = new TLegend(0.85, 0.85, 0.6, 0.6);
 leg4->SetHeader("Q^{2}=5.9 GeV^{2}, x_{B}=0.35");
 leg4->SetFillStyle(0);
 leg4->SetTextSize(0.035);
 // leg->SetTextFont(132); 
 leg4->SetLineColor(0);
 leg4->AddEntry(gr_d2,"H_{Im}(d) 100 days", "lep");
 leg4->AddEntry(gr_u2,"H_{Im}(u) 100 days", "lep");
 leg4->AddEntry(gr_d2_50,"H_{Im}(d) 50 days", "lep");
 leg4->AddEntry(gr_u2_50,"H_{Im}(u) 50 days", "lep");
 leg4->Draw();

 g1->Print("flavors_h_im_50_100.pdf");
}
