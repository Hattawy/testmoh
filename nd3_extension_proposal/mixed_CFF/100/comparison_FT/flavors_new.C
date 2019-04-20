void flavors_new()
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
  g1->Divide(2,2,0.002,0.002);

  Double_t t_vec[4]={0.1,0.35,0.65,1.0};
  Double_t t_vec2[4]={0.11,0.36,0.66,1.01};
  Double_t err_t[4]={0.,0.,0.,0.};

  Double_t h1_mick[4]={3.76332,1.79738,0.843363,0.418659};
  Double_t h1_mick_value[4];
  Double_t err_p_h1_mick[4]={0.0434852,0.0145534,0.0156967,0.0203703};
  Double_t err_m_h1_mick[4]={0.0433271,0.0144761,0.0156579,0.0204733};
  Double_t err_h1_mick[4];

  //Double_t h1[4]={1.57672,0.875018,0.248256,0.0661223};
  // Double_t err_p_h1[4]={0.1459,0.119957,0.182793,0.0895776};
  // Double_t err_m_h1[4]={1.05783,0.168182,0.0961123,0.0686831};
  Double_t h1[4]={1.56197,0.817644,0.258368,0.0909438};
  Double_t h1_value[4];
  Double_t err_p_h1[4]={0.213983,0.136453,0.202112,0.102538};
  Double_t err_m_h1[4]={1.48614,0.16542,0.109055,0.062999};
  Double_t err_h1[4];

  Double_t h2_mick[4]={1.5558,1.24619,0.784293,0.523831};
  Double_t h2_mick_value[4];
  Double_t err_p_h2_mick[4]={0.0375647,0.0255718,0.023106,0.0286174};
  Double_t err_m_h2_mick[4]={0.0371835,0.0253437,0.0226669,0.0277903};
  Double_t err_h2_mick[4];

  // Double_t h2[4]={1.6068,, 0.887692,0.488806,0.488806};
  // Double_t err_p_h2[4]={0.648313,0.219973,0.111345,0.0841763};
  // Double_t err_m_h2[4]={1.2268,0.404246,0.190935,0.126487};
  Double_t h2[4]={1.65191,0.88923,0.474789,0.232988};
  Double_t h2_value[4];
  Double_t err_p_h2[4]={0.776127,0.314993,0.152864,0.200129};
  Double_t err_m_h2[4]={1.26496,0.477751,0.217982,0.137044};
  Double_t err_h2[4];

  Double_t h1_d[4],h2_d[4],h1_u[4],h2_u[4];
  Double_t e_p_h1_d[4],e_p_h2_d[4],e_p_h1_u[4],e_p_h2_u[4];
  Double_t e_m_h1_d[4],e_m_h2_d[4],e_m_h1_u[4],e_m_h2_u[4];
  Double_t e_h1_d[4],e_h2_d[4],e_h1_u[4],e_h2_u[4];

  for(Int_t j=0;j<4;j++)
    {
      h1_mick_value[j]=0.5*(2*h1_mick[j]+err_m_h1_mick[j]-err_p_h1_mick[j]);
      err_h1_mick[j]=0.5*(err_m_h1_mick[j]+err_p_h1_mick[j]);
      h2_mick_value[j]=0.5*(2*h2_mick[j]+err_m_h2_mick[j]-err_p_h2_mick[j]);
      err_h2_mick[j]=0.5*(err_m_h2_mick[j]+err_p_h2_mick[j]);
      h1_value[j]=0.5*(2*h1[j]+err_m_h1[j]-err_p_h1[j]);
      err_h1[j]=0.5*(err_m_h1[j]+err_p_h1[j]);
      h2_value[j]=0.5*(2*h2[j]+err_m_h2[j]-err_p_h2[j]);
      err_h2[j]=0.5*(err_m_h2[j]+err_p_h2[j]);
    }
  for(Int_t i=0;i<4;i++)
    {
      h1_u[i]=9./15.*(4*h1_mick_value[i]-h1_value[i]);
      h1_d[i]=9./15.*(4*h1_value[i]-h1_mick_value[i]);
      h2_u[i]=9./15.*(4*h2_mick_value[i]-h2_value[i]);
      h2_d[i]=9./15.*(4*h2_value[i]-h2_mick_value[i]);
      e_h1_u[i]=9./15.*TMath::Sqrt(4*err_h1_mick[i]*err_h1_mick[i]+err_h1[i]*err_h1[i]);
      e_h1_d[i]=9./15.*TMath::Sqrt(err_h1_mick[i]*err_h1_mick[i]+4*err_h1[i]*err_h1[i]);
      e_h2_u[i]=9./15.*TMath::Sqrt(4*err_h2_mick[i]*err_h2_mick[i]+err_h2[i]*err_h2[i]);
      e_h2_d[i]=9./15.*TMath::Sqrt(err_h2_mick[i]*err_h2_mick[i]+4*err_h2[i]*err_h2[i]);

    }

  gr_h1_mick = new TGraphErrors(4,t_vec,h1_mick_value,err_t,err_h1_mick);
  
  gr_h2_mick = new TGraphErrors(4,t_vec,h2_mick_value,err_t,err_h2_mick);

  gr_h1 = new TGraphErrors(4,t_vec2,h1,err_t,err_h1);
  
  gr_h2 = new TGraphErrors(4,t_vec2,h2,err_t,err_h2);

  gr_u1 = new TGraphErrors(4,t_vec,h1_u,err_t,e_h1_u);
  
  gr_u2 = new TGraphErrors(4,t_vec,h2_u,err_t,e_h2_u);

  gr_d1 = new TGraphErrors(4,t_vec2,h1_d,err_t,e_h1_d);
  
  gr_d2 = new TGraphErrors(4,t_vec2,h2_d,err_t,e_h2_d);

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

 TLegend* leg = new TLegend(0.8, 0.8, 0.6, 0.6);
 leg->SetHeader("Q^{2}=2.6 GeV^{2}, x_{B}=0.23");
   leg->SetFillStyle(0);
 leg->SetTextSize(0.04);
 // leg->SetTextFont(132); 
 leg->SetLineColor(0);
 leg->AddEntry(gr_h1_mick,"H_{Im}(p)", "lep");
 leg->AddEntry(gr_h1,"H_{Im}(n)", "lep");
 leg->Draw();

  g1->cd(2);
  gr_h2_mick->SetMaximum(5);
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

 TLegend* leg2 = new TLegend(0.8, 0.8, 0.6, 0.6);
 leg2->SetHeader("Q^{2}=5.9 GeV^{2}, x_{B}=0.35");
 leg2->SetFillStyle(0);
 leg2->SetTextSize(0.04);
 // leg->SetTextFont(132); 
 leg2->SetLineColor(0);
 leg2->AddEntry(gr_h1_mick,"H_{Im}(p)", "lep");
 leg2->AddEntry(gr_h1,"H_{Im}(n)", "lep");
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

  TLegend* leg3 = new TLegend(0.8, 0.8, 0.6, 0.6);
 leg3->SetHeader("Q^{2}=2.6 GeV^{2}, x_{B}=0.23");
 leg3->SetFillStyle(0);
 leg3->SetTextSize(0.04);
 // leg->SetTextFont(132); 
 leg3->SetLineColor(0);
 leg3->AddEntry(gr_d1,"H_{Im}(d)", "lep");
 leg3->AddEntry(gr_u1,"H_{Im}(u)", "lep");
 leg3->Draw();
  g1->cd(4);
  
  gr_d2->SetMaximum(10);
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
 
  TLegend* leg4 = new TLegend(0.8, 0.8, 0.6, 0.6);
 leg4->SetHeader("Q^{2}=5.9 GeV^{2}, x_{B}=0.35");
 leg4->SetFillStyle(0);
 leg4->SetTextSize(0.04);
 // leg->SetTextFont(132); 
 leg4->SetLineColor(0);
 leg4->AddEntry(gr_d2,"H_{Im}(d)", "lep");
 leg4->AddEntry(gr_u2,"H_{Im}(u)", "lep");
 leg4->Draw();

 g1->Print("flavors_h_im_new.pdf");
}
