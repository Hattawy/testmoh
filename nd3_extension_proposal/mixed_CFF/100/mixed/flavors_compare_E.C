void flavors_compare_E()
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
  Double_t t_vec2[4]={0.13,0.37,0.67,1.02};
  Double_t t_vec_50[4]={0.12,0.36,0.66,1.01};
  Double_t t_vec2_50[4]={0.14,0.38,0.68,1.03};
  Double_t err_t[4]={0.,0.,0.,0.};

  Double_t e1_mick[4]={0.954418,0.508232,0.308079,0.210962};
  Double_t e1_mick_value[4];
  Double_t err_p_e1_mick[4]={0.647512,0.0671212,0.0419191,0.0370238};
  Double_t err_m_e1_mick[4]={0.651638,0.0674094,0.0420888,0.0370188};
  Double_t err_e1_mick[4];

  //Double_t e1[4]={1.57672,0.875018,0.248256,0.0661223};
  // Double_t err_p_e1[4]={0.1459,0.119957,0.182793,0.0895776};
  // Double_t err_m_e1[4]={1.05783,0.168182,0.0961123,0.0686831};
  Double_t e1[4]={2.37377,0.478129,0.295145,0.17587};
  Double_t e1_value[4];
  Double_t err_p_e1[4]={0.937975,0.233394,0.115609,0.0594441};
  Double_t err_m_e1[4]={3.17054,0.340723,0.0996864,0.0523891};
  Double_t err_e1[4];

  Double_t e1_50[4]={2.48027,0.538207,0.304689,0.191858};
  Double_t e1_value_50[4];
  Double_t err_p_e1_50[4]={1.29021,0.319031,0.238313,0.117692};
  Double_t err_m_e1_50[4]={3.87255,0.380553,0.203518,0.104256};
  Double_t err_e1_50[4];

  Double_t e2_mick[4]={0.482389,0.37057,0.223589,0.152264};
  Double_t e2_mick_value[4];
  Double_t err_p_e2_mick[4]={0.637367,0.250915,0.0957058,0.0734979};
  Double_t err_m_e2_mick[4]={0.69969,0.262439,0.0976499,0.0756056};
  Double_t err_e2_mick[4];

  // Double_t e2[4]={1.6068,, 0.887692,0.488806,0.488806};
  // Double_t err_p_e2[4]={0.648313,0.219973,0.111345,0.0841763};
  // Double_t err_m_e2[4]={1.2268,0.404246,0.190935,0.126487};

  Double_t e2[4]={-0.157842,-0.114014,0.0507252,0.0805734};
  Double_t e2_value[4];
  Double_t err_p_e2[4]={3.15686,1.17687,0.418882,0.171971};
  Double_t err_m_e2[4]={4.13698,1.24806,0.541759,0.229113};
  Double_t err_e2[4];

  Double_t e2_50[4]={-1.3449,-0.0955546,0.0810341,0.102607};
  Double_t e2_value_50[4];
  Double_t err_p_e2_50[4]={4.35155,1.18148,0.464836,0.25594};
  Double_t err_m_e2_50[4]={2.97425,1.29875,0.589908,0.276298};
  Double_t err_e2_50[4];

  Double_t e1_d[4],e2_d[4],e1_u[4],e2_u[4];
  Double_t e_p_e1_d[4],e_p_e2_d[4],e_p_e1_u[4],e_p_e2_u[4];
  Double_t e_m_e1_d[4],e_m_e2_d[4],e_m_e1_u[4],e_m_e2_u[4];
  Double_t e_e1_d[4],e_e2_d[4],e_e1_u[4],e_e2_u[4];

  Double_t e1_d_50[4],e2_d_50[4],e1_u_50[4],e2_u_50[4];
  Double_t e_p_e1_d_50[4],e_p_e2_d_50[4],e_p_e1_u_50[4],e_p_e2_u_50[4];
  Double_t e_m_e1_d_50[4],e_m_e2_d_50[4],e_m_e1_u_50[4],e_m_e2_u_50[4];
  Double_t e_e1_d_50[4],e_e2_d_50[4],e_e1_u_50[4],e_e2_u_50[4];

  for(Int_t j=0;j<4;j++)
    {
      e1_mick_value[j]=0.5*(2*e1_mick[j]+err_m_e1_mick[j]-err_p_e1_mick[j]);
      err_e1_mick[j]=0.5*(err_m_e1_mick[j]+err_p_e1_mick[j]);
      e2_mick_value[j]=0.5*(2*e2_mick[j]+err_m_e2_mick[j]-err_p_e2_mick[j]);
      err_e2_mick[j]=0.5*(err_m_e2_mick[j]+err_p_e2_mick[j]);
      e1_value[j]=0.5*(2*e1[j]+err_m_e1[j]-err_p_e1[j]);
      err_e1[j]=0.5*(err_m_e1[j]+err_p_e1[j]);
      e2_value[j]=0.5*(2*e2[j]+err_m_e2[j]-err_p_e2[j]);
      err_e2[j]=0.5*(err_m_e2[j]+err_p_e2[j]);

      e1_mick_value[j]=0.5*(2*e1_mick[j]+err_m_e1_mick[j]-err_p_e1_mick[j]);
      err_e1_mick[j]=0.5*(err_m_e1_mick[j]+err_p_e1_mick[j]);
      e2_mick_value[j]=0.5*(2*e2_mick[j]+err_m_e2_mick[j]-err_p_e2_mick[j]);
      err_e2_mick[j]=0.5*(err_m_e2_mick[j]+err_p_e2_mick[j]);
      e1_value_50[j]=0.5*(2*e1_50[j]+err_m_e1_50[j]-err_p_e1_50[j]);
      err_e1_50[j]=0.5*(err_m_e1_50[j]+err_p_e1_50[j]);
      e2_value_50[j]=0.5*(2*e2_50[j]+err_m_e2_50[j]-err_p_e2_50[j]);
      err_e2_50[j]=0.5*(err_m_e2_50[j]+err_p_e2_50[j]);
    }
  for(Int_t i=0;i<4;i++)
    {
      e1_u[i]=9./15.*(4*e1_mick_value[i]-e1_value[i]);
      e1_d[i]=9./15.*(4*e1_value[i]-e1_mick_value[i]);
      e2_u[i]=9./15.*(4*e2_mick_value[i]-e2_value[i]);
      e2_d[i]=9./15.*(4*e2_value[i]-e2_mick_value[i]);
      e_e1_u[i]=9./15.*TMath::Sqrt(4*err_e1_mick[i]*err_e1_mick[i]+err_e1[i]*err_e1[i]);
      e_e1_d[i]=9./15.*TMath::Sqrt(err_e1_mick[i]*err_e1_mick[i]+4*err_e1[i]*err_e1[i]);
      e_e2_u[i]=9./15.*TMath::Sqrt(4*err_e2_mick[i]*err_e2_mick[i]+err_e2[i]*err_e2[i]);
      e_e2_d[i]=9./15.*TMath::Sqrt(err_e2_mick[i]*err_e2_mick[i]+4*err_e2[i]*err_e2[i]);

      e1_u_50[i]=9./15.*(4*e1_mick_value[i]-e1_value_50[i]);
      e1_d_50[i]=9./15.*(4*e1_value_50[i]-e1_mick_value[i]);
      e2_u_50[i]=9./15.*(4*e2_mick_value[i]-e2_value_50[i]);
      e2_d_50[i]=9./15.*(4*e2_value_50[i]-e2_mick_value[i]);
      e_e1_u_50[i]=9./15.*TMath::Sqrt(4*err_e1_mick[i]*err_e1_mick[i]+err_e1_50[i]*err_e1_50[i]);
      e_e1_d_50[i]=9./15.*TMath::Sqrt(err_e1_mick[i]*err_e1_mick[i]+4*err_e1_50[i]*err_e1_50[i]);
      e_e2_u_50[i]=9./15.*TMath::Sqrt(4*err_e2_mick[i]*err_e2_mick[i]+err_e2_50[i]*err_e2_50[i]);
      e_e2_d_50[i]=9./15.*TMath::Sqrt(err_e2_mick[i]*err_e2_mick[i]+4*err_e2_50[i]*err_e2_50[i]);

    }

  gr_e1_mick = new TGraphErrors(4,t_vec,e1_mick_value,err_t,err_e1_mick);
  gr_e2_mick = new TGraphErrors(4,t_vec,e2_mick_value,err_t,err_e2_mick);
  gr_e1 = new TGraphErrors(4,t_vec2,e1,err_t,err_e1);  
  gr_e2 = new TGraphErrors(4,t_vec2,e2,err_t,err_e2);
  gr_u1 = new TGraphErrors(4,t_vec,e1_u,err_t,e_e1_u);  
  gr_u2 = new TGraphErrors(4,t_vec,e2_u,err_t,e_e2_u);
  gr_d1 = new TGraphErrors(4,t_vec2,e1_d,err_t,e_e1_d);  
  gr_d2 = new TGraphErrors(4,t_vec2,e2_d,err_t,e_e2_d);

  gr_e1_mick = new TGraphErrors(4,t_vec_50,e1_mick_value,err_t,err_e1_mick);
  gr_e2_mick = new TGraphErrors(4,t_vec_50,e2_mick_value,err_t,err_e2_mick);
  gr_e1_50 = new TGraphErrors(4,t_vec2_50,e1_50,err_t,err_e1_50);  
  gr_e2_50 = new TGraphErrors(4,t_vec2_50,e2_50,err_t,err_e2_50);
  gr_u1_50 = new TGraphErrors(4,t_vec_50,e1_u_50,err_t,e_e1_u_50);  
  gr_u2_50 = new TGraphErrors(4,t_vec_50,e2_u_50,err_t,e_e2_u_50);
  gr_d1_50 = new TGraphErrors(4,t_vec2_50,e1_d_50,err_t,e_e1_d_50);  
  gr_d2_50 = new TGraphErrors(4,t_vec2_50,e2_d_50,err_t,e_e2_d_50);

  g1->cd(1);
  
  gr_e1_mick->SetMaximum(6);
  gr_e1_mick->SetMinimum(-1);
  gr_e1_mick->SetTitle();
  gr_e1_mick->SetMarkerStyle(20);
  gr_e1_mick->SetMarkerSize(0.6);
  gr_e1_mick->SetLineColor(1);
  gr_e1_mick->SetMarkerColor(1);
  gr_e1_mick->GetXaxis()->SetTitle("-t (GeV^{2})");
  gr_e1_mick->GetYaxis()->SetTitle("E_{Im}(N)");
  gr_e1_mick->Draw("AP,same");
  gr_e1->SetMarkerStyle(20);
  gr_e1->SetMarkerSize(0.6);
  gr_e1->SetLineColor(2);
  gr_e1->SetMarkerColor(2);
  gr_e1->Draw("P,same");
  gr_e1_50->SetMarkerStyle(24);
  gr_e1_50->SetMarkerSize(0.5);
  gr_e1_50->SetLineColor(2);
  gr_e1_50->SetMarkerColor(2);
  gr_e1_50->Draw("P,same");

 TLegend* leg = new TLegend(0.8, 0.8, 0.6, 0.6);
 leg->SetHeader("Q^{2}=2.6 GeV^{2}, x_{B}=0.23");
 leg->SetFillStyle(0);
 leg->SetTextSize(0.035);
 // leg->SetTextFont(132); 
 leg->SetLineColor(0);
 leg->AddEntry(gr_e1_mick,"E_{Im}(p)", "lep");
 leg->AddEntry(gr_e1,"E_{Im}(n), 100 days", "lep");
 leg->AddEntry(gr_e1_50,"E_{Im}(n), 50 days", "lep");
 leg->Draw();

  g1->cd(2);
  gr_e2_mick->SetMaximum(4);
  gr_e2_mick->SetMinimum(-6);
  gr_e2_mick->SetTitle();
  gr_e2_mick->SetMarkerStyle(20);
  gr_e2_mick->SetMarkerSize(0.6);
  gr_e2_mick->SetLineColor(1);
  gr_e2_mick->SetMarkerColor(1);
  gr_e2_mick->GetXaxis()->SetTitle("-t (GeV^{2})");
  gr_e2_mick->GetYaxis()->SetTitle("E_{Im}(N)");
  gr_e2_mick->Draw("AP,same");
  gr_e2->SetMarkerStyle(20);
  gr_e2->SetMarkerSize(0.6);
  gr_e2->SetLineColor(2);
  gr_e2->SetMarkerColor(2);
  gr_e2->Draw("P,same");
  gr_e2_50->SetMarkerStyle(24);
  gr_e2_50->SetMarkerSize(0.5);
  gr_e2_50->SetLineColor(2);
  gr_e2_50->SetMarkerColor(2);
  gr_e2_50->Draw("P,same");

 TLegend* leg2 = new TLegend(0.8, 0.8, 0.6, 0.6);
 leg2->SetHeader("Q^{2}=5.9 GeV^{2}, x_{B}=0.35");
 leg2->SetFillStyle(0);
 leg2->SetTextSize(0.035);
 // leg->SetTextFont(132); 
 leg2->SetLineColor(0);
 leg2->AddEntry(gr_e1_mick,"E_{Im}(p)", "lep");
 leg2->AddEntry(gr_e1,"E_{Im}(n), 100 days", "lep");
 leg2->AddEntry(gr_e1_50,"E_{Im}(n), 50 days", "lep");
 leg2->Draw();

  g1->cd(3);
  
  gr_d1->SetMaximum(12);
  gr_d1->SetMinimum(-2);
  gr_d1->SetTitle();
  gr_d1->SetMarkerStyle(23);
  gr_d1->SetMarkerSize(0.6);
  gr_d1->SetLineColor(2);
  gr_d1->SetMarkerColor(2);
  gr_d1->GetXaxis()->SetTitle("-t (GeV^{2})");
  gr_d1->GetYaxis()->SetTitle("E_{Im}(q)");
  gr_d1->Draw("AP,same");
  gr_u1->SetMarkerStyle(23);
  gr_u1->SetMarkerSize(0.6);
  gr_u1->SetLineColor(1);
  gr_u1->SetMarkerColor(1);
  gr_u1->Draw("P,same");
  gr_d1_50->SetTitle();
  gr_d1_50->SetMarkerStyle(26);
  gr_d1_50->SetMarkerSize(0.5);
  gr_d1_50->SetLineColor(2);
  gr_d1_50->SetMarkerColor(2);
  gr_d1_50->Draw("P,same");
  gr_u1_50->SetMarkerStyle(26);
  gr_u1_50->SetMarkerSize(0.5);
  gr_u1_50->SetLineColor(1);
  gr_u1_50->SetMarkerColor(1);
  gr_u1_50->Draw("P,same");

  TLegend* leg3 = new TLegend(0.8, 0.8, 0.6, 0.6);
 leg3->SetHeader("Q^{2}=2.6 GeV^{2}, x_{B}=0.23");
 leg3->SetFillStyle(0);
 leg3->SetTextSize(0.035);
 // leg->SetTextFont(132); 
 leg3->SetLineColor(0);
 leg3->AddEntry(gr_d1,"E_{Im}(d), 100 days", "lep");
 leg3->AddEntry(gr_u1,"E_{Im}(u), 100 days", "lep");
 leg3->AddEntry(gr_d1_50,"E_{Im}(d), 50 days", "lep");
 leg3->AddEntry(gr_u1_50,"E_{Im}(u), 50 days", "lep");
 leg3->Draw();
  g1->cd(4);
  
  gr_d2->SetMaximum(8);
  gr_d2->SetMinimum(-10);
  gr_d2->SetTitle();
  gr_d2->SetMarkerStyle(23);
  gr_d2->SetMarkerSize(0.6);
  gr_d2->SetLineColor(2);
  gr_d2->SetMarkerColor(2);
  gr_d2->GetXaxis()->SetTitle("-t (GeV^{2})");
  gr_d2->GetYaxis()->SetTitle("E_{Im}(q)");
  gr_d2->Draw("AP,same");
  gr_u2->SetMarkerStyle(23);
  gr_u2->SetMarkerSize(0.6);
  gr_u2->SetLineColor(1);
  gr_u2->SetMarkerColor(1);
  gr_u2->Draw("P,same");
  gr_d2_50->SetMarkerStyle(26);
  gr_d2_50->SetMarkerSize(0.5);
  gr_d2_50->SetLineColor(2);
  gr_d2_50->SetMarkerColor(2);
  gr_d2_50->GetXaxis()->SetTitle("-t (GeV^{2})");
  gr_d2_50->GetYaxis()->SetTitle("E_{Im}(q)");
  gr_d2_50->Draw("P,same");
  gr_u2_50->SetMarkerStyle(26);
  gr_u2_50->SetMarkerSize(0.5);
  gr_u2_50->SetLineColor(1);
  gr_u2_50->SetMarkerColor(1);
  gr_u2_50->Draw("P,same");
  TLegend* leg4 = new TLegend(0.8, 0.8, 0.6, 0.6);
 leg4->SetHeader("Q^{2}=5.9 GeV^{2}, x_{B}=0.35");
 leg4->SetFillStyle(0);
 leg4->SetTextSize(0.035);
 // leg->SetTextFont(132); 
 leg4->SetLineColor(0);
 leg4->AddEntry(gr_d2,"E_{Im}(d), 100 days", "lep");
 leg4->AddEntry(gr_u2,"E_{Im}(u), 100 days", "lep");
 leg4->AddEntry(gr_d2_50,"E_{Im}(d), 50 days", "lep");
 leg4->AddEntry(gr_u2_50,"E_{Im}(u), 50 days", "lep");
 leg4->Draw();

 g1->Print("flavors_e_im_compare.pdf");
}
