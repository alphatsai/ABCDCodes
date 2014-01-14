#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include "TFile.h"
#include "TH1.h"
#include "TH1F.h"
#include "TH2F.h"
#include "THStack.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TROOT.h"
using namespace std;
void checkABCD2D(){
	string load="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/11AA/result/root/abcd";
	string path="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/11AA/result/png/abcd";
	vector<string> f;
	f.push_back("OnlySumBg");
	f.push_back("BH_500");
	f.push_back("BH_800");
	f.push_back("BH_1000");
	vector<string> h2;
	h2.push_back("h2_CA8CSV2Sub");	
	h2.push_back("h2_LeadCA8Ht1");
	h2.push_back("h2_LeadCA8LeadCSV1");
	h2.push_back("h2_dRCA8LeadCSV1");
	h2.push_back("h2_HbbdRLeadCA8LeadCSV1");
	h2.push_back("h2_LeadCA8HbbdR");
	h2.push_back("h2_HOthdRLeadCA8LeadCSV1");
	h2.push_back("h2_LeadCA8HOthdR");
	TFile* f_[f.size()];
	TH2F* h[f.size()][h2.size()];
	TCanvas* c1 = new TCanvas("c1", "", 850, 700);
	gStyle->SetOptStat(0);
	c1->SetLogz();
	for(int i=0; i<f.size(); i++){
		string fload=load+"/abcd_"+f[i]+".root";
		f_[i] = new TFile(fload.c_str());	
		for(int j=0; j<h2.size(); j++){
			string save=path+"/Check_"+f[i]+"_"+h2[j]+".png";
			h[i][j]=(TH2F*)f_[i]->Get(h2[j].c_str());
			h[i][j]->RebinX(5);
			h[i][j]->RebinY(10);
			h[i][j]->Draw("COLZ");
			c1->SaveAs(save.c_str());	
		}	
	}
}
