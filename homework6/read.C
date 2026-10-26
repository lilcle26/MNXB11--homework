#include "MovingObject.h"

void read(){
    MovingObject *object{nullptr};

    TCanvas *c1 = new TCanvas("c1", "c1", 800, 600);
    TCanvas *c2 = new TCanvas("c2", "c2", 600, 400);


    auto file = TFile::Open("tree_file.root");
    if (!file || file->IsZombie()){
        std::cerr << "Error opening file" << std::endl;
        return;
    }
    TTree *T = static_cast<TTree*>(file->Get("tree"));
    if(!T){
        std::cerr << "Tree does not exist" << std::endl;
        file-> Close();
        return;
    }

    T->SetBranchAddress("object", &object);
    Long64_t N = T->GetEntries();

    TH2D *h1 = new TH2D("h1", "velocity v_x vs v_y; vx (m/s); vy (m/s)", 100, -1.5, 1.5, 100, -1.5, 1.5);
    for (Long64_t i=0; i<N; i++){
        T->GetEntry(i);
        h1->Fill(object->Vx(), object->Vy());
    }
    c1 -> cd();
    h1->Draw("COLZ");
    h1->GetXaxis()->CenterTitle(true);
    h1->GetYaxis()->CenterTitle(true);
    c1->SetLeftMargin(0.12);
    c1->SaveAs("velocity_components.png");

    c2->cd();
    T->Draw("sqrt(fVx*fVx + fVy*fVy ):fVz", 
        "sqrt(fVx*fVx + fVy*fVy + fVz*fVz ) > 0.50");

    TH2F *htemp = (TH2F*)gPad->GetPrimitive("htemp");
    htemp->SetTitle("v_z versus v_xy for speed v>0.5 m/s ; v_z (m/s) ; v_xy (m/s)");
    htemp->GetXaxis()->CenterTitle(true);
    htemp->GetYaxis()->CenterTitle(true);

    c2->SaveAs("scatter_velocities.png");
}