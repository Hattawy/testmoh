void flavors_compare3()
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
  gStyle->SetTitleX(0.5);
gStyle->SetTitleAlign(23); 
  TCanvas *g1= new TCanvas("c","c",1000,800);
  g1->Divide(4,3,0.002,0.002);

  Double_t t_vec[4]={0.1,0.35,0.65,1.0};
  Double_t t_vec1[4]={0.12,0.37,0.67,1.02};
  Double_t t_vec2[4]={0.14,0.39,0.69,1.04};
  Double_t t_vec3[4]={0.16,0.41,0.71,1.06};
  // Double_t t_vec4[4]={0.14,0.39,0.69,1.04};
  Double_t err_t[4]={0.,0.,0.,0.};

  Double_t h1_mick[4]={3.76332,1.79738,0.843363,0.418659};
  Double_t err_h1_mick[4]={0.0434852,0.0145534,0.0156967,0.0203703};

  Double_t h2_mick[4]={1.5558,1.24619,0.784293,0.523831};
  Double_t err_h2_mick[4]={0.0375647,0.0255718,0.023106,0.0286174};

  Double_t h3_mick[4]={5.20594,2.03088,0.84337,0.381802};
  Double_t err_h3_mick[4]={0.02765,0.015555,0.01664,0.019965};

  Double_t h4_mick[4]={2.86555,1.58862,0.840616,0.473966};
  Double_t err_h4_mick[4]={0.125299,0.0172127,0.0183742,0.0238699};

  Double_t h1_100FT[4]={0.925045,0.768806,0.334462,0.0985426};
  Double_t err_h1_100FT[4]={0.858505,0.161133,0.228041,0.112992};

  Double_t h2_100FT[4]={1.43704,0.797029,0.431539,0.205527};
  Double_t err_h2_100FT[4]={1.05725,0.413126,0.211977,0.159201};

  Double_t h3_100FT[4]={4.46856,1.41283,0.869192,0.178527};
  Double_t err_h3_100FT[4]={0.733582,0.594909,0.660655,0.277898};

  Double_t h4_100FT[4]={2.25588,1.19928,0.41582,0.127154};
  Double_t err_h4_100FT[4]={0.567913,0.266762,0.32191,0.283449};

  Double_t h1_50[4]={0.686462,0.690832,0.403781,0.0994456};
  Double_t err_h1_50[4]={1.13763,0.193847,0.334429,0.152076};

  Double_t h2_50[4]={1.80547,0.749646,0.404022,0.244037};
  Double_t err_h2_50[4]={1.18383,0.524993,0.274998,0.263736};

  Double_t h3_50[4]={2.75495,1.58172,0.812347,0.195342};
  Double_t err_h3_50[4]={4.11844,1.04152,0.733361,0.295652};

  Double_t h4_50[4]={2.28583,1.10684,-100,-100.};
  Double_t err_h4_50[4]={0.855089,0.384736,0.,0.};

  Double_t h1_d_100FT[4],h2_d_100FT[4],h3_d_100FT[4],h4_d_100FT[4];
  Double_t h1_u_100FT[4],h2_u_100FT[4],h3_u_100FT[4],h4_u_100FT[4];
  Double_t e_h1_d_100FT[4],e_h2_d_100FT[4],e_h3_d_100FT[4],e_h4_d_100FT[4];
  Double_t e_h1_u_100FT[4],e_h2_u_100FT[4],e_h3_u_100FT[4],e_h4_u_100FT[4];

  Double_t h1_d_50[4],h2_d_50[4],h3_d_50[4],h4_d_50[4];
  Double_t h1_u_50[4],h2_u_50[4],h3_u_50[4],h4_u_50[4];
  Double_t e_h1_d_50[4],e_h2_d_50[4],e_h3_d_50[4],e_h4_d_50[4];
  Double_t e_h1_u_50[4],e_h2_u_50[4],e_h3_u_50[4],e_h4_u_50[4];

  for(Int_t i=0;i<4;i++)
    {
      h1_u_100FT[i]=9./15.*(4*h1_mick[i]-h1_100FT[i]);
      h1_d_100FT[i]=9./15.*(4*h1_100FT[i]-h1_mick[i]);
      h2_u_100FT[i]=9./15.*(4*h2_mick[i]-h2_100FT[i]);
      h2_d_100FT[i]=9./15.*(4*h2_100FT[i]-h2_mick[i]);
      h3_u_100FT[i]=9./15.*(4*h3_mick[i]-h3_100FT[i]);
      h3_d_100FT[i]=9./15.*(4*h3_100FT[i]-h3_mick[i]);
      h4_u_100FT[i]=9./15.*(4*h4_mick[i]-h4_100FT[i]);
      h4_d_100FT[i]=9./15.*(4*h4_100FT[i]-h4_mick[i]);
      e_h1_u_100FT[i]=9./15.*TMath::Sqrt(4*err_h1_mick[i]*err_h1_mick[i]+err_h1_100FT[i]*err_h1_100FT[i]);
      e_h1_d_100FT[i]=9./15.*TMath::Sqrt(err_h1_mick[i]*err_h1_mick[i]+4*err_h1_100FT[i]*err_h1_100FT[i]);
      e_h2_u_100FT[i]=9./15.*TMath::Sqrt(4*err_h2_mick[i]*err_h2_mick[i]+err_h2_100FT[i]*err_h2_100FT[i]);
      e_h2_d_100FT[i]=9./15.*TMath::Sqrt(err_h2_mick[i]*err_h2_mick[i]+4*err_h2_100FT[i]*err_h2_100FT[i]);
      e_h3_u_100FT[i]=9./15.*TMath::Sqrt(4*err_h3_mick[i]*err_h3_mick[i]+err_h3_100FT[i]*err_h3_100FT[i]);
      e_h3_d_100FT[i]=9./15.*TMath::Sqrt(err_h3_mick[i]*err_h3_mick[i]+4*err_h3_100FT[i]*err_h3_100FT[i]);
      e_h4_u_100FT[i]=9./15.*TMath::Sqrt(4*err_h4_mick[i]*err_h4_mick[i]+err_h4_100FT[i]*err_h4_100FT[i]);
      e_h4_d_100FT[i]=9./15.*TMath::Sqrt(err_h4_mick[i]*err_h4_mick[i]+4*err_h4_100FT[i]*err_h4_100FT[i]);

      h1_u_50[i]=9./15.*(4*h1_mick[i]-h1_50[i]);
      h1_d_50[i]=9./15.*(4*h1_50[i]-h1_mick[i]);
      h2_u_50[i]=9./15.*(4*h2_mick[i]-h2_50[i]);
      h2_d_50[i]=9./15.*(4*h2_50[i]-h2_mick[i]);
      h3_u_50[i]=9./15.*(4*h3_mick[i]-h3_50[i]);
      h3_d_50[i]=9./15.*(4*h3_50[i]-h3_mick[i]);
      h4_u_50[i]=9./15.*(4*h4_mick[i]-h4_50[i]);
      h4_d_50[i]=9./15.*(4*h4_50[i]-h4_mick[i]);
      e_h1_u_50[i]=9./15.*TMath::Sqrt(4*err_h1_mick[i]*err_h1_mick[i]+err_h1_50[i]*err_h1_50[i]);
      e_h1_d_50[i]=9./15.*TMath::Sqrt(err_h1_mick[i]*err_h1_mick[i]+4*err_h1_50[i]*err_h1_50[i]);
      e_h2_u_50[i]=9./15.*TMath::Sqrt(4*err_h2_mick[i]*err_h2_mick[i]+err_h2_50[i]*err_h2_50[i]);
      e_h2_d_50[i]=9./15.*TMath::Sqrt(err_h2_mick[i]*err_h2_mick[i]+4*err_h2_50[i]*err_h2_50[i]);
      e_h3_u_50[i]=9./15.*TMath::Sqrt(4*err_h3_mick[i]*err_h3_mick[i]+err_h3_50[i]*err_h3_50[i]);
      e_h3_d_50[i]=9./15.*TMath::Sqrt(err_h3_mick[i]*err_h3_mick[i]+4*err_h3_50[i]*err_h3_50[i]);
      e_h4_u_50[i]=9./15.*TMath::Sqrt(4*err_h4_mick[i]*err_h4_mick[i]+err_h4_50[i]*err_h4_50[i]);
      e_h4_d_50[i]=9./15.*TMath::Sqrt(err_h4_mick[i]*err_h4_mick[i]+4*err_h4_50[i]*err_h4_50[i]);

    }

  gr_h1_mick = new TGraphErrors(4,t_vec,h1_mick,err_t,err_h1_mick);
  gr_h2_mick = new TGraphErrors(4,t_vec,h2_mick,err_t,err_h2_mick);
  gr_h3_mick = new TGraphErrors(4,t_vec,h3_mick,err_t,err_h3_mick);
  gr_h4_mick = new TGraphErrors(4,t_vec,h4_mick,err_t,err_h4_mick);

  gr_h1_100FT = new TGraphErrors(4,t_vec1,h1_100FT,err_t,err_h1_100FT);  
  gr_h2_100FT = new TGraphErrors(4,t_vec1,h2_100FT,err_t,err_h2_100FT);
  gr_h3_100FT = new TGraphErrors(4,t_vec1,h3_100FT,err_t,err_h3_100FT);  
  gr_h4_100FT = new TGraphErrors(4,t_vec1,h4_100FT,err_t,err_h4_100FT);

  gr_u1_100FT = new TGraphErrors(4,t_vec1,h1_u_100FT,err_t,e_h1_u_100FT);  
  gr_u2_100FT = new TGraphErrors(4,t_vec1,h2_u_100FT,err_t,e_h2_u_100FT);
  gr_u3_100FT = new TGraphErrors(4,t_vec1,h3_u_100FT,err_t,e_h3_u_100FT);  
  gr_u4_100FT = new TGraphErrors(4,t_vec1,h4_u_100FT,err_t,e_h4_u_100FT);
  gr_d1_100FT = new TGraphErrors(4,t_vec1,h1_d_100FT,err_t,e_h1_d_100FT);  
  gr_d2_100FT = new TGraphErrors(4,t_vec1,h2_d_100FT,err_t,e_h2_d_100FT);
  gr_d3_100FT = new TGraphErrors(4,t_vec1,h3_d_100FT,err_t,e_h3_d_100FT);  
  gr_d4_100FT = new TGraphErrors(4,t_vec1,h4_d_100FT,err_t,e_h4_d_100FT);

  gr_h1_50 = new TGraphErrors(4,t_vec3,h1_50,err_t,err_h1_50);  
  gr_h2_50 = new TGraphErrors(4,t_vec3,h2_50,err_t,err_h2_50);
  gr_h3_50 = new TGraphErrors(4,t_vec3,h3_50,err_t,err_h3_50);  
  gr_h4_50 = new TGraphErrors(4,t_vec3,h4_50,err_t,err_h4_50);
  gr_u1_50 = new TGraphErrors(4,t_vec3,h1_u_50,err_t,e_h1_u_50);  
  gr_u2_50 = new TGraphErrors(4,t_vec3,h2_u_50,err_t,e_h2_u_50);
  gr_u3_50 = new TGraphErrors(4,t_vec3,h3_u_50,err_t,e_h3_u_50);  
  gr_u4_50 = new TGraphErrors(4,t_vec3,h4_u_50,err_t,e_h4_u_50);
  gr_d1_50 = new TGraphErrors(4,t_vec3,h1_d_50,err_t,e_h1_d_50);  
  gr_d2_50 = new TGraphErrors(4,t_vec3,h2_d_50,err_t,e_h2_d_50);
  gr_d3_50 = new TGraphErrors(4,t_vec3,h3_d_50,err_t,e_h3_d_50);  
  gr_d4_50 = new TGraphErrors(4,t_vec3,h4_d_50,err_t,e_h4_d_50);

  g1->cd(1);
  
  gr_h1_mick->SetMaximum(4);
  gr_h1_mick->SetMinimum(-0.5);
  gr_h1_mick->SetTitle("Q^{2}=2.6 GeV^{2}, x_{B}=0.23");
  gr_h1_mick->SetMarkerStyle(20);
  gr_h1_mick->SetMarkerSize(0.6);
  gr_h1_mick->SetLineColor(6);
  gr_h1_mick->SetMarkerColor(6);
  gr_h1_mick->GetXaxis()->SetTitle("-t (GeV^{2})");
  gr_h1_mick->GetYaxis()->SetTitle("H_{Im}(N)");
  gr_h1_mick->Draw("AP,same");
  gr_h1_100FT->SetMarkerStyle(20);
  gr_h1_100FT->SetMarkerSize(0.6);
  gr_h1_100FT->SetLineColor(4);
  gr_h1_100FT->SetMarkerColor(4);
  gr_h1_100FT->Draw("P,same");
  gr_h1_50->SetMarkerStyle(24);
  gr_h1_50->SetMarkerSize(0.5);
  gr_h1_50->SetLineColor(2);
  gr_h1_50->SetMarkerColor(2);
  gr_h1_50->Draw("P,same");

 TLegend* leg = new TLegend(0.75, 0.85, 0.45, 0.5);
 // leg->SetHeader("Q^{2}=2.6 GeV^{2}, x_{B}=0.23");
 leg->SetFillStyle(0);
 leg->SetTextSize(0.035);
 // leg->SetTextFont(132); 
 leg->SetLineColor(0);
 leg->AddEntry(gr_h1_mick,"H_{Im}(p)", "lep");
 leg->AddEntry(gr_h1_100FT,"H_{Im}(n), Extended RG", "lep");
 leg->AddEntry(gr_h1_50,"H_{Im}(n), Present RG", "lep");
 leg->Draw();

  g1->cd(2);
  gr_h2_mick->SetMaximum(3.5);
  gr_h2_mick->SetMinimum(-0.5);
  gr_h2_mick->SetTitle("Q^{2}= 5.9 GeV^{2}, x_{B}= 0.35");
  gr_h2_mick->SetMarkerStyle(20);
  gr_h2_mick->SetMarkerSize(0.6);
  gr_h2_mick->SetLineColor(6);
  gr_h2_mick->SetMarkerColor(6);
  gr_h2_mick->GetXaxis()->SetTitle("-t (GeV^{2})");
  gr_h2_mick->GetYaxis()->SetTitle("H_{Im}(N)");
  gr_h2_mick->Draw("AP,same");
  gr_h2_100FT->SetMarkerStyle(20);
  gr_h2_100FT->SetMarkerSize(0.6);
  gr_h2_100FT->SetLineColor(4);
  gr_h2_100FT->SetMarkerColor(4);
  gr_h2_100FT->Draw("P,same");
  gr_h2_50->SetMarkerStyle(24);
  gr_h2_50->SetMarkerSize(0.5);
  gr_h2_50->SetLineColor(2);
  gr_h2_50->SetMarkerColor(2);
  gr_h2_50->Draw("P,same");

 // TLegend* leg2 = new TLegend(0.8, 0.8, 0.6, 0.6);
 // leg2->SetHeader("Q^{2}=5.9 GeV^{2}, x_{B}=0.35");
 // leg2->SetFillStyle(0);
 // leg2->SetTextSize(0.035);
 // leg->SetTextFont(132); 
 // leg2->SetLineColor(0);
 // leg2->AddEntry(gr_h2_mick,"H_{Im}(p)", "lep");
 // leg2->AddEntry(gr_h2_100FT,"H_{Im}(n), Extended RG", "lep");
 // leg2->AddEntry(gr_h2_100noFT,"H_{Im}(n), 100 days - no FT", "lep");
 // leg2->AddEntry(gr_h2_50,"H_{Im}(n), Present RG", "lep");
 // leg2->Draw();

  g1->cd(3);
  gr_h3_mick->SetMaximum(8);
  gr_h3_mick->SetMinimum(-2);
  gr_h3_mick->SetTitle("Q^{2}= 2.35 GeV^{2}, x_{B}= 0.13");
  gr_h3_mick->SetMarkerStyle(20);
  gr_h3_mick->SetMarkerSize(0.6);
  gr_h3_mick->SetLineColor(6);
  gr_h3_mick->SetMarkerColor(6);
  gr_h3_mick->GetXaxis()->SetTitle("-t (GeV^{2})");
  gr_h3_mick->GetYaxis()->SetTitle("H_{Im}(N)");
  gr_h3_mick->Draw("AP,same");
  gr_h3_100FT->SetMarkerStyle(20);
  gr_h3_100FT->SetMarkerSize(0.6);
  gr_h3_100FT->SetLineColor(4);
  gr_h3_100FT->SetMarkerColor(4);
  gr_h3_100FT->Draw("P,same");
  gr_h3_50->SetMarkerStyle(24);
  gr_h3_50->SetMarkerSize(0.5);
  gr_h3_50->SetLineColor(2);
  gr_h3_50->SetMarkerColor(2);
  gr_h3_50->Draw("P,same");

 // TLegend* leg3 = new TLegend(0.8, 0.8, 0.6, 0.6);
 // leg3->SetHeader("Q^{2}= GeV^{2}, x_{B}=");
 // leg3->SetFillStyle(0);
 // leg3->SetTextSize(0.035);
 // // leg->SetTextFont(132); 
 // leg3->SetLineColor(0);
 // leg3->AddEntry(gr_h3_mick,"H_{Im}(p)", "lep");
 // leg3->AddEntry(gr_h3_100FT,"H_{Im}(n), Extended RG", "lep");
 // leg3->AddEntry(gr_h3_100noFT,"H_{Im}(n), 100 days - no FT", "lep");
 // leg3->AddEntry(gr_h3_50,"H_{Im}(n), Present RG", "lep");
 // leg3->Draw();

  g1->cd(4);

  gr_h4_mick->SetMaximum(3.5);
  gr_h4_mick->SetMinimum(-1);
  gr_h4_mick->SetTitle("Q^{2}= 4.0 GeV^{2}, x_{B}= 0.25");
  gr_h4_mick->SetMarkerStyle(20);
  gr_h4_mick->SetMarkerSize(0.6);
  gr_h4_mick->SetLineColor(6);
  gr_h4_mick->SetMarkerColor(6);
  gr_h4_mick->GetXaxis()->SetTitle("-t (GeV^{2})");
  gr_h4_mick->GetYaxis()->SetTitle("H_{Im}(N)");
  gr_h4_mick->Draw("AP,same");
  gr_h4_100FT->SetMarkerStyle(20);
  gr_h4_100FT->SetMarkerSize(0.6);
  gr_h4_100FT->SetLineColor(4);
  gr_h4_100FT->SetMarkerColor(4);
  gr_h4_100FT->Draw("P,same");
  gr_h4_50->SetMarkerStyle(24);
  gr_h4_50->SetMarkerSize(0.5);
  gr_h4_50->SetLineColor(2);
  gr_h4_50->SetMarkerColor(2);
  gr_h4_50->Draw("P,same");

 // TLegend* leg4 = new TLegend(0.8, 0.8, 0.6, 0.6);
 // leg4->SetHeader("Q^{2}= GeV^{2}, x_{B}=");
 // leg4->SetFillStyle(0);
 // leg4->SetTextSize(0.035);
 // // leg->SetTextFont(132); 
 // leg4->SetLineColor(0);
 // leg4->AddEntry(gr_h4_mick,"H_{Im}(p)", "lep");
 // leg4->AddEntry(gr_h4_100FT,"H_{Im}(n), Extended RG", "lep");
 // leg4->AddEntry(gr_h4_100noFT,"H_{Im}(n), 100 days - no FT", "lep");
 // leg4->AddEntry(gr_h4_50,"H_{Im}(n), Present RG", "lep");
 // leg4->Draw();

 g1->cd(5);
 
 gr_d1_100FT->SetMaximum(4);
 gr_d1_100FT->SetMinimum(-2.5);
 gr_d1_100FT->SetTitle();
 gr_d1_100FT->SetMarkerStyle(23);
 gr_d1_100FT->SetMarkerSize(0.6);
 gr_d1_100FT->SetLineColor(4);
 gr_d1_100FT->SetMarkerColor(4);
 gr_d1_100FT->GetXaxis()->SetTitle("-t (GeV^{2})");
 gr_d1_100FT->GetYaxis()->SetTitle("H_{Im}(d)");
 gr_d1_100FT->Draw("AP,same");
 gr_d1_50->SetTitle();
 gr_d1_50->SetMarkerStyle(26);
 gr_d1_50->SetMarkerSize(0.5);
 gr_d1_50->SetLineColor(2);
 gr_d1_50->SetMarkerColor(2);
 gr_d1_50->Draw("P,same");

 TLegend* leg5 = new TLegend(0.75, 0.85, 0.45, 0.5);
 leg5->SetFillStyle(0);
 leg5->SetTextSize(0.035);
 leg5->SetLineColor(0);
 leg5->AddEntry(gr_d1_100FT,"H_{Im}(d), Extended RG", "lep");
 leg5->AddEntry(gr_d1_50,"H_{Im}(d), Present RG", "lep");
 leg5->Draw();

 g1->cd(6);
 
 gr_d2_100FT->SetMaximum(5.5);
 gr_d2_100FT->SetMinimum(-0.5);
 gr_d2_100FT->SetTitle();
 gr_d2_100FT->SetMarkerStyle(23);
 gr_d2_100FT->SetMarkerSize(0.6);
 gr_d2_100FT->SetLineColor(4);
 gr_d2_100FT->SetMarkerColor(4);
 gr_d2_100FT->GetXaxis()->SetTitle("-t (GeV^{2})");
 gr_d2_100FT->GetYaxis()->SetTitle("H_{Im}(d)");
 gr_d2_100FT->Draw("AP,same");
 gr_d2_50->SetMarkerStyle(26);
 gr_d2_50->SetMarkerSize(0.5);
 gr_d2_50->SetLineColor(2);
 gr_d2_50->SetMarkerColor(2);
 gr_d2_50->Draw("P,same");


 g1->cd(7);
 
 gr_d3_100FT->SetMaximum(10);
 gr_d3_100FT->SetMinimum(-2);
 gr_d3_100FT->SetTitle();
 gr_d3_100FT->SetMarkerStyle(23);
 gr_d3_100FT->SetMarkerSize(0.6);
 gr_d3_100FT->SetLineColor(4);
 gr_d3_100FT->SetMarkerColor(4);
 gr_d3_100FT->GetXaxis()->SetTitle("-t (GeV^{2})");
 gr_d3_100FT->GetYaxis()->SetTitle("H_{Im}(d)");
 gr_d3_100FT->Draw("AP,same");
 gr_d3_50->SetMarkerStyle(26);
 gr_d3_50->SetMarkerSize(0.5);
 gr_d3_50->SetLineColor(2);
 gr_d3_50->SetMarkerColor(2);
 gr_d3_50->Draw("P,same");

 g1->cd(8);
 
 gr_d4_100FT->SetMaximum(5);
 gr_d4_100FT->SetMinimum(-1);
 gr_d4_100FT->SetTitle();
 gr_d4_100FT->SetMarkerStyle(23);
 gr_d4_100FT->SetMarkerSize(0.6);
 gr_d4_100FT->SetLineColor(4);
 gr_d4_100FT->SetMarkerColor(4);
 gr_d4_100FT->GetXaxis()->SetTitle("-t (GeV^{2})");
 gr_d4_100FT->GetYaxis()->SetTitle("H_{Im}(d)");
 gr_d4_100FT->Draw("AP,same");
 gr_d4_50->SetMarkerStyle(26);
 gr_d4_50->SetMarkerSize(0.5);
 gr_d4_50->SetLineColor(2);
 gr_d4_50->SetMarkerColor(2);
 gr_d4_50->Draw("P,same");

 g1->cd(9);
 
 gr_u1_100FT->SetMaximum(10);
 gr_u1_100FT->SetMinimum(0);
 gr_u1_100FT->SetTitle();
 gr_u1_100FT->SetMarkerStyle(23);
 gr_u1_100FT->SetMarkerSize(0.6);
 gr_u1_100FT->SetLineColor(4);
 gr_u1_100FT->SetMarkerColor(4);
 gr_u1_100FT->GetXaxis()->SetTitle("-t (GeV^{2})");
 gr_u1_100FT->GetYaxis()->SetTitle("H_{Im}(u)");
 gr_u1_100FT->Draw("AP,same");
 gr_u1_50->SetTitle();
 gr_u1_50->SetMarkerStyle(26);
 gr_u1_50->SetMarkerSize(0.5);
 gr_u1_50->SetLineColor(2);
 gr_u1_50->SetMarkerColor(2);
 gr_u1_50->Draw("P,same");

 TLegend* leg5 = new TLegend(0.75, 0.85, 0.45, 0.5);
 leg5->SetFillStyle(0);
 leg5->SetTextSize(0.035);
 leg5->SetLineColor(0);
 leg5->AddEntry(gr_u1_100FT,"H_{Im}(u), Extended RG", "lep");
 leg5->AddEntry(gr_u1_50,"H_{Im}(u), Present RG", "lep");
 leg5->Draw();

 g1->cd(10);
 
 gr_u2_100FT->SetMaximum(4);
 gr_u2_100FT->SetMinimum(0.5);
 gr_u2_100FT->SetTitle();
 gr_u2_100FT->SetMarkerStyle(23);
 gr_u2_100FT->SetMarkerSize(0.6);
 gr_u2_100FT->SetLineColor(4);
 gr_u2_100FT->SetMarkerColor(4);
 gr_u2_100FT->GetXaxis()->SetTitle("-t (GeV^{2})");
 gr_u2_100FT->GetYaxis()->SetTitle("H_{Im}(u)");
 gr_u2_100FT->Draw("AP,same");
 gr_u2_50->SetMarkerStyle(26);
 gr_u2_50->SetMarkerSize(0.5);
 gr_u2_50->SetLineColor(2);
 gr_u2_50->SetMarkerColor(2);
 gr_u2_50->Draw("P,same");

 g1->cd(11);
 
 gr_u3_100FT->SetMaximum(14);
 gr_u3_100FT->SetMinimum(0);
 gr_u3_100FT->SetTitle();
 gr_u3_100FT->SetMarkerStyle(23);
 gr_u3_100FT->SetMarkerSize(0.6);
 gr_u3_100FT->SetLineColor(4);
 gr_u3_100FT->SetMarkerColor(4);
 gr_u3_100FT->GetXaxis()->SetTitle("-t (GeV^{2})");
 gr_u3_100FT->GetYaxis()->SetTitle("H_{Im}(u)");
 gr_u3_100FT->Draw("AP,same");
 gr_u3_50->SetMarkerStyle(26);
 gr_u3_50->SetMarkerSize(0.5);
 gr_u3_50->SetLineColor(2);
 gr_u3_50->SetMarkerColor(2);
 gr_u3_50->Draw("P,same");

 g1->cd(12);
 
 gr_u4_100FT->SetMaximum(7);
 gr_u4_100FT->SetMinimum(0);
 gr_u4_100FT->SetTitle();
 gr_u4_100FT->SetMarkerStyle(23);
 gr_u4_100FT->SetMarkerSize(0.6);
 gr_u4_100FT->SetLineColor(4);
 gr_u4_100FT->SetMarkerColor(4);
 gr_u4_100FT->GetXaxis()->SetTitle("-t (GeV^{2})");
 gr_u4_100FT->GetYaxis()->SetTitle("H_{Im}(u)");
 gr_u4_100FT->Draw("AP,same");
 gr_u4_50->SetMarkerStyle(26);
 gr_u4_50->SetMarkerSize(0.5);
 gr_u4_50->SetLineColor(2);
 gr_u4_50->SetMarkerColor(2);
 gr_u4_50->Draw("P,same");

 g1->Print("flavors_h_im_compare3.pdf");
 g1->Print("flavors_h_im_compare3.eps");
}
