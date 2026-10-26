#include "MovingObject.h"

void write(){
    TFile f("tree_file.root", "RECREATE");
    TTree *T = new TTree("tree", "tree");
    MovingObject *object = new MovingObject();
    T->Branch("object", &object);

    gRandom->SetSeed(12345);

    Int_t nEvents{10000};
    for (Int_t i{0}; i<nEvents; i++){
        Double_t vx = gRandom->Gaus(0.0, 0.30);
        Double_t vy = gRandom->Gaus(0.0, 0.30);
        Double_t vz = gRandom->Gaus(0.0, 0.30);
        object->SetVelocity(vx, vy, vz);
        T->Fill();
    }
    T->Write();
    f.Close();
    delete object;
}