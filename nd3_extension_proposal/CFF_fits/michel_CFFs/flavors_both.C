void flavors_both()
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

  gStyle -> SetLabelOffset(0.012, "y");
  gStyle -> SetLabelFont(62, "xy");
  gStyle -> SetLabelSize(0.045, "xy");
  gStyle -> SetTitleFont(132,"xy");
  gStyle -> SetTitleSize(0.05,"xy");
  
  TCanvas *g1= new TCanvas("c","c",1000,800);
  g1->Divide(2,2,0.001,0.001);

  Double_t t_vec[4]={0.1,0.35,0.65,1.0};
  Double_t t_vec2[4]={0.11,0.36,0.66,1.01};
  Double_t err_t[4]={0.,0.,0.,0.};
  Double_t h1_mick[4]={3.76332,1.79738,0.843363,0.418659};
  Double_t err_p_h1_mick[4]={0.0434852,0.0145534,0.0156967,0.0203703};
  Double_t err_m_h1_mick[4]={0.0433271,0.0144761,0.0156579,0.0204733};

  Double_t h1[4]={1.57672,0.875018,0.248256,0.0661223};
  Double_t err_p_h1[4]={0.1459,0.119957,0.182793,0.0895776};
  Double_t err_m_h1[4]={1.05783,0.168182,0.0961123,0.0686831};
  Double_t e1_mick[4]={0.954418,0.508232,0.308079,0.210962};
  Double_t err_p_e1_mick[4]={0.647512,0.0671212,0.0419191,0.0370238};
  Double_t err_m_e1_mick[4]={0.651638,0.0674094,0.0420888,0.0370188};

  Double_t e1[4]={2.32466,0.501634,0.309242,0.20448};
  Double_t err_p_e1[4]={0.20448,0.19647,0.108552,0.0708914};
  Double_t err_m_e1[4]={2.49619,0.440301,0.0992073,0.0647334};

  Double_t e2_mick[4]={0.482389,0.37057,0.223589,0.152264};
  Double_t err_p_e2_mick[4]={0.637367,0.250915,0.0957058,0.0734979};
  Double_t err_m_e2_mick[4]={0.69969,0.262439,0.0976499,0.0756056};

  Double_t e2[4]={0.0927325,-0.127472,0.0219723,0.0685282};
  Double_t err_p_e2[4]={2.89157,0.903718,0.315291,0.142642};
  Double_t err_m_e2[4]={4.36731,1.22139,0.0585541,0.219553};

  Double_t e1_d[4],e2_d[4],e1_u[4],e2_u[4];
  Double_t e_p_e1_d[4],e_p_e2_d[4],e_p_e1_u[4],e_p_e2_u[4];
  Double_t e_m_e1_d[4],e_m_e2_d[4],e_m_e1_u[4],e_m_e2_u[4];

  Double_t h2_mick[4]={1.5558,1.24619,0.784293,0.523831};
  Double_t err_p_h2_mick[4]={0.0375647,0.0255718,0.023106,0.0286174};
  Double_t err_m_h2_mick[4]={0.0371835,0.0253437,0.0226669,0.0277903};

  Double_t h2[4]={1.6068,, 0.887692,0.488806,0.488806};
  Double_t err_p_h2[4]={0.648313,0.219973,0.111345,0.0841763};
  Double_t err_m_h2[4]={1.2268,0.404246,0.190935,0.126487};

  Double_t h1_d[4],h2_d[4],h1_u[4],h2_u[4];
  Double_t e_p_h1_d[4],e_p_h2_d[4],e_p_h1_u[4],e_p_h2_u[4];
  Double_t e_m_h1_d[4],e_m_h2_d[4],e_m_h1_u[4],e_m_h2_u[4];
  for(Int_t i=0;i<4;i++)
    {
      e1_u[i]=9./15.*(4*e1_mick[i]-e1[i]);
      e1_d[i]=9./15.*(4*e1[i]-e1_mick[i]);
      e2_u[i]=9./15.*(4*e2_mick[i]-e2[i]);
      e2_d[i]=9./15.*(4*e2[i]-e2_mick[i]);
      e_p_e1_u[i]=TMath::Sqrt(4*err_p_e1_mick[i]*err_p_e1_mick[i]+err_p_e1[i]*err_p_e1[i]);
      e_p_e1_d[i]=TMath::Sqrt(err_p_e1_mick[i]*err_p_e1_mick[i]+4*err_p_e1[i]*err_p_e1[i]);
      e_m_e1_u[i]=TMath::Sqrt(4*err_m_e1_mick[i]*err_m_e1_mick[i]+err_m_e1[i]*err_m_e1[i]);
      e_m_e1_d[i]=TMath::Sqrt(err_m_e1_mick[i]*err_m_e1_mick[i]+4*err_m_e1[i]*err_m_e1[i]);
      e_p_e2_u[i]=TMath::Sqrt(4*err_p_e2_mick[i]*err_p_e2_mick[i]+err_p_e2[i]*err_p_e2[i]);
      e_p_e2_d[i]=TMath::Sqrt(err_p_e2_mick[i]*err_p_e2_mick[i]+4*err_p_e2[i]*err_p_e2[i]);
      e_m_e2_u[i]=TMath::Sqrt(4*err_m_e2_mick[i]*err_m_e2_mick[i]+err_m_e2[i]*err_m_e2[i]);
      e_m_e2_d[i]=TMath::Sqrt(err_m_e2_mick[i]*err_m_e2_mick[i]+4*err_m_e2[i]*err_m_e2[i]);

      h1_u[i]=9./15.*(4*h1_mick[i]-h1[i]);
      h1_d[i]=9./15.*(4*h1[i]-h1_mick[i]);
      h2_u[i]=9./15.*(4*h2_mick[i]-h2[i]);
      h2_d[i]=9./15.*(4*h2[i]-h2_mick[i]);
      e_p_h1_u[i]=TMath::Sqrt(4*err_p_h1_mick[i]*err_p_h1_mick[i]+err_p_h1[i]*err_p_h1[i]);
      e_p_h1_d[i]=TMath::Sqrt(err_p_h1_mick[i]*err_p_h1_mick[i]+4*err_p_h1[i]*err_p_h1[i]);
      e_m_h1_u[i]=TMath::Sqrt(4*err_m_h1_mick[i]*err_m_h1_mick[i]+err_m_h1[i]*err_m_h1[i]);
      e_m_h1_d[i]=TMath::Sqrt(err_m_h1_mick[i]*err_m_h1_mick[i]+4*err_m_h1[i]*err_m_h1[i]);
      e_p_h2_u[i]=TMath::Sqrt(4*err_p_h2_mick[i]*err_p_h2_mick[i]+err_p_h2[i]*err_p_h2[i]);
      e_p_h2_d[i]=TMath::Sqrt(err_p_h2_mick[i]*err_p_h2_mick[i]+4*err_p_h2[i]*err_p_h2[i]);
      e_m_h2_u[i]=TMath::Sqrt(4*err_m_h2_mick[i]*err_m_h2_mick[i]+err_m_h2[i]*err_m_h2[i]);
      e_m_h2_d[i]=TMath::Sqrt(err_m_h2_mick[i]*err_m_h2_mick[i]+4*err_m_h2[i]*err_m_h2[i]);

    }
  gr_h1_mick = new TGraphAsymmErrors(4,t_vec,h1_mick,err_t,err_t,err_p_h1_mick,err_m_h1_mick);
  
  gr_h2_mick = new TGraphAsymmErrors(4,t_vec,h2_mick,err_t,err_t,err_p_h2_mick,err_m_h2_mick);

  gr_h1 = new TGraphAsymmErrors(4,t_vec,h1,err_t,err_t,err_p_h1,err_m_h1);
  
  gr_h2 = new TGraphAsymmErrors(4,t_vec,h2,err_t,err_t,err_p_h2,err_m_h2);
  gr_e1_mick = new TGraphAsymmErrors(4,t_vec,e1_mick,err_t,err_t,err_p_e1_mick,err_m_e1_mick);
  
  gr_e2_mick = new TGraphAsymmErrors(4,t_vec,e2_mick,err_t,err_t,err_p_e2_mick,err_m_e2_mick);

  gr_e1 = new TGraphAsymmErrors(4,t_vec2,e1,err_t,err_t,err_p_e1,err_m_e1);
  
  gr_e2 = new TGraphAsymmErrors(4,t_vec2,e2,err_t,err_t,err_p_e2,err_m_e2);

  gr_u1_h = new TGraphAsymmErrors(4,t_vec,h1_u,err_t,err_t,e_p_h1_u,e_m_h1_u);
  
  gr_u2_h = new TGraphAsymmErrors(4,t_vec,h2_u,err_t,err_t,e_p_h2_u,e_m_h2_u);

  gr_d1_h = new TGraphAsymmErrors(4,t_vec,h1_d,err_t,err_t,e_p_h1_d,e_m_h1_d);
  
  gr_d2_h = new TGraphAsymmErrors(4,t_vec,h2_d,err_t,err_t,e_p_h2_d,e_m_h2_d);

  gr_u1 = new TGraphAsymmErrors(4,t_vec,e1_u,err_t,err_t,e_p_e1_u,e_m_e1_u);
  
  gr_u2 = new TGraphAsymmErrors(4,t_vec,e2_u,err_t,err_t,e_p_e2_u,e_m_e2_u);

  gr_d1 = new TGraphAsymmErrors(4,t_vec2,e1_d,err_t,err_t,e_p_e1_d,e_m_e1_d);
  
  gr_d2 = new TGraphAsymmErrors(4,t_vec2,e2_d,err_t,err_t,e_p_e2_d,e_m_e2_d);

  g1->cd(2);
  
  gr_e1_mick->SetMaximum(6);
  gr_e1_mick->SetMinimum(-1);
  gr_e1_mick->SetTitle();
  gr_e1_mick->SetMarkerStyle(20);
  gr_e1_mick->SetMarkerSize(0.5);
  gr_e1_mick->SetLineColor(1);
  gr_e1_mick->SetMarkerColor(1);
  gr_e1_mick->GetXaxis()->SetTitle("-t (GeV^{2})");
  gr_e1_mick->GetXaxis()->SetTitleFont(62);
  //  gr_e1_mick->GetXaxis()->SetTitleSize(0.04);
  //  gr_e1_mick->GetXaxis()->SetLabelSize(0.04);
  gr_e1_mick->GetYaxis()->SetTitle("E_{Im}(N)");
  gr_e1_mick->GetYaxis()->SetTitleFont(62);
  gr_e1_mick->GetYaxis()->SetLabelSize(0.035);
  gr_e1_mick->Draw("AP,same");
  gr_e1->SetMarkerStyle(20);
  gr_e1->SetMarkerSize(0.5);
  gr_e1->SetLineColor(2);
  gr_e1->SetMarkerColor(2);
  gr_e1->Draw("P,same");

 TLegend* leg = new TLegend(0.8, 0.8, 0.5, 0.5);
 leg->SetHeader("Q^{2}=2.6 GeV^{2}, x_{B}=0.23");
   leg->SetFillStyle(0);
 leg->SetTextSize(0.05);
 // leg->SetTextFont(132); 
 leg->SetLineColor(0);
 leg->AddEntry(gr_e1_mick,"E_{Im}(p)", "lep");
 leg->AddEntry(gr_e1,"E_{Im}(n)", "lep");
 leg->Draw();

  g1->cd(1);
  gr_h1_mick->SetMaximum(4);
  gr_h1_mick->SetMinimum(-1);
  gr_h1_mick->SetTitle();
  gr_h1_mick->SetMarkerStyle(20);
  gr_h1_mick->SetMarkerSize(0.5);
  gr_h1_mick->SetLineColor(1);
  gr_h1_mick->SetMarkerColor(1);
  gr_h1_mick->GetXaxis()->SetTitle("-t (GeV^{2})");
  gr_h1_mick->GetXaxis()->SetTitleFont(62);
  gr_h1_mick->GetYaxis()->SetTitle("H_{Im}(N)");
  gr_h1_mick->GetYaxis()->SetTitleFont(62);
  gr_h1_mick->Draw("AP,same");
  gr_h1->SetMarkerStyle(20);
  gr_h1->SetMarkerSize(0.5);
  gr_h1->SetLineColor(2);
  gr_h1->SetMarkerColor(2);
  gr_h1->Draw("P,same");
 TLegend* leg2 = new TLegend(0.8, 0.8, 0.5, 0.5);
 leg2->SetHeader("Q^{2}=2.6 GeV^{2}, x_{B}=0.23");
 leg2->SetFillStyle(0);
 leg2->SetTextSize(0.05);
 // leg->SetTextFont(132); 
 leg2->SetLineColor(0);
 leg2->AddEntry(gr_h1_mick,"H_{Im}(p)", "lep");
 leg2->AddEntry(gr_h1,"H_{Im}(n)", "lep");
 leg2->Draw();

  g1->cd(4);
  
  gr_d1->SetMaximum(12);
  gr_d1->SetMinimum(-1);
  gr_d1->SetTitle();
  gr_d1->SetMarkerStyle(22);
  gr_d1->SetMarkerSize(0.7);
  gr_d1->SetLineColor(2);
  gr_d1->SetMarkerColor(2);
  gr_d1->GetXaxis()->SetTitle("-t (GeV^{2})");
  gr_d1->GetXaxis()->SetTitleFont(62);
  gr_d1->GetYaxis()->SetTitle("E_{Im}(q)");
  gr_d1->GetYaxis()->SetTitleFont(62);  
  gr_d1->Draw("AP,same");
  gr_u1->SetMarkerStyle(22);
  gr_u1->SetMarkerSize(0.7);
  gr_u1->SetLineColor(1);
  gr_u1->SetMarkerColor(1);
  gr_u1->Draw("P,same");

  TLegend* leg3 = new TLegend(0.8, 0.8, 0.5, 0.5);
 leg3->SetHeader("Q^{2}=2.6 GeV^{2}, x_{B}=0.23");
 leg3->SetFillStyle(0);
 leg3->SetTextSize(0.05);
 // leg->SetTextFont(132); 
 leg3->SetLineColor(0);
 leg3->AddEntry(gr_d1,"E_{Im}(d)", "lep");
 leg3->AddEntry(gr_u1,"E_{Im}(u)", "lep");
 leg3->Draw();
  g1->cd(3);
  
  gr_d1_h->SetMaximum(10);
  gr_d1_h->SetMinimum(-1);
  gr_d1_h->SetTitle();
  gr_d1_h->SetMarkerStyle(22);
  gr_d1_h->SetMarkerSize(0.7);
  gr_d1_h->SetLineColor(2);
  gr_d1_h->SetMarkerColor(2);
  gr_d1_h->GetXaxis()->SetTitle("-t (GeV^{2})");
  gr_d1_h->GetXaxis()->SetTitleFont(62);
  gr_d1_h->GetYaxis()->SetTitle("H_{Im}(q)");
  gr_d1_h->GetYaxis()->SetTitleFont(62);
  gr_d1_h->Draw("AP,same");
  gr_u1_h->SetMarkerStyle(22);
  gr_u1_h->SetMarkerSize(0.7);
  gr_u1_h->SetLineColor(1);
  gr_u1_h->SetMarkerColor(1);
  gr_u1_h->Draw("P,same");
 
  TLegend* leg4 = new TLegend(0.8, 0.8, 0.5, 0.5);
 leg4->SetHeader("Q^{2}=2.6 GeV^{2}, x_{B}=0.23");
 leg4->SetFillStyle(0);
 leg4->SetTextSize(0.05);
 // leg->SetTextFont(132); 
 leg4->SetLineColor(0);
 leg4->AddEntry(gr_d1_h,"H_{Im}(d)", "lep");
 leg4->AddEntry(gr_u1_h,"H_{Im}(u)", "lep");
 leg4->Draw();

 g1->Print("flavors_both.eps");
}
