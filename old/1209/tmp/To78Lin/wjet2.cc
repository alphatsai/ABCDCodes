#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include "TChain.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TLorentzVector.h"
#include "plotInfo.h"
#include "TH1FInfo2.C"
using namespace std;
///////////////////////////////////////////////////////////////////////////////
void wjet2(){
	TFile* f1 = new TFile("test.root", "recreate");
	TH1FInfo h1;
	
	cout<<h1.name[0]<<" "<<h1.bin[0]<<endl;
	cout<<h1.name[1]<<" "<<h1.bin[1]<<endl;
	for( int i=0; i<1000; i++){
		h1.GetTH1F("test.1")->Fill(i%30);
		h1.GetTH1F("test.2")->Fill(i%17);
	}
	f1->Write();
}
