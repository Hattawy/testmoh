void plot_shields()
{
  gSystem->Load("libPhysics");
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(111);

  TCanvas *g= new TCanvas("c","c",1000,800);

  Float_t current[21]={0,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290};
  Float_t theta_0_sh_2_5[10]={400,400,400,360,320,300,200,110,40,7};
  Float_t theta_30_sh_2_5[10]={400,400,400,380,340,300,230,200,80,30};
  Float_t theta_0_sh_5[21]={400,400,400,400,400,400,400,360,320,280,260,200,160,130,90,50,32,15,5,4,3};
  Float_t theta_30_sh_5[21]={400,400,400,400,400,400,400,360,340,320,300,250,160,120,80,40,20,8,5,5,5};

  TGraph *l1,*l2,*l3,*l4;
  l1=new TGraph(10,current,theta_0_sh_2_5);
  l2=new TGraph(10,current,theta_30_sh_2_5);
  l3=new TGraph(21,current,theta_0_sh_5);
  l4=new TGraph(21,current,theta_30_sh_5);
  l1->SetMarkerStyle(20);
  l1->SetMarkerSize(1);
  l1->SetMarkerColor(1);
  l2->SetMarkerStyle(21);
  l2->SetMarkerSize(1);
  l2->SetMarkerColor(2);
  l3->SetMarkerStyle(22);
  l3->SetMarkerSize(1);
  l3->SetMarkerColor(3);
  l4->SetMarkerStyle(23);
  l4->SetMarkerSize(1);
  l4->SetMarkerColor(4);
  l4->Draw("AP");
  l3->Draw("Psame");
  l2->Draw("Psame");
  l1->Draw("Psame");

  g->Print("shields.eps");

}
