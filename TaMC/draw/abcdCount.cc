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
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/TaMC/interface/sampleInfo.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/TaMC/interface/plotsInfoABCD.h"
using namespace std;
void countAndStore(string name, fstream& f, TH1F* h, TH1F* bg){
	f<<"***************************************"<<endl;
	f<<"************* "<<name<<" **************"<<endl;
	f<<"***************************************"<<endl;
	float A, B, C, D, dA, dB, dC, dD;
	A = h->GetBinContent(1);
	B = h->GetBinContent(2);
	C = h->GetBinContent(3);
	D = h->GetBinContent(4);
	dA = h->GetBinError(1);
	dB = h->GetBinError(2);
	dC = h->GetBinError(3);
	dD = h->GetBinError(4);

	float Ab, Bb, Cb, Db;
	Ab = bg->GetBinContent(1);
	Bb = bg->GetBinContent(2);
	Cb = bg->GetBinContent(3);
	Db = bg->GetBinContent(4);
	
	float sigA=dA/A;
	float sigB=dB/B;
	float sigC=dC/C;
	float sigD=dD/D;
	float dBbyA = sqrt(sigA*sigA+sigB*sigB)*B/A;
	float dDbyC = sqrt(sigC*sigC+sigD*sigD)*D/C;
	float dBbyD = sqrt(sigB*sigB+sigD*sigD)*B/D;
	float dAbyC = sqrt(sigA*sigA+sigC*sigC)*A/C;
	float dADbyC = sqrt(sigA*sigA+sigC*sigC+sigD*sigD)*A*(D/C);	
	float dDAbyC = sqrt(sigA*sigA+sigC*sigC+sigD*sigD)*D*(A/C);	

	f<<"Region\t"<<"Num\t\t"<<"Error(+/-)"<<endl;
	f<<"A\t"<<A<<"\t\t"<<dA<<endl;
	f<<"B\t"<<B<<"\t\t"<<dB<<endl;
	f<<"C\t"<<C<<"\t\t"<<dC<<endl;
	f<<"D\t"<<D<<"\t\t"<<dD<<endl;
	f<<endl;
	f<<"Form\t"<<"Ratio\t\t"<<"Error(+/-)"<<endl;
	f<<"B/A\t"<<B/A<<"\t\t"<<dBbyA<<endl;
	f<<"D/C\t"<<D/C<<"\t\t"<<dDbyC<<endl;
	f<<"B/D\t"<<B/D<<"\t\t"<<dBbyD<<endl;
	f<<"A/C\t"<<A/C<<"\t\t"<<dAbyC<<endl;
	f<<endl;
	f<<"Form\t"<<"Yields\t\t"<<"Error(+/-)"<<endl;
	f<<"A(D/C)\t"<<A*(D/C)<<"\t\t"<<dADbyC<<endl;
	f<<"D(A/C)\t"<<D*(A/C)<<"\t\t"<<dDAbyC<<endl;
	f<<endl;
	f<<"In control regin(A,B,C): "<<(A+B+C)/(A+B+C+D)*100<<"%"<<endl;
	f<<"Consider background: "<<(A+B+C)/(A+B+C+D+Ab+Bb+Cb+Db)*100<<"%"<<endl;
	f<<endl;
}

void abcdCount(){
	
	string loadPath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/TaMC/result/root/abcd";
	string savePath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/TaMC/result/txt/abcd";

	vector<string> h;
	vector<string> abcdFiles_Sig;
	vector<string> abcdFiles_Bg;
	vector<string> abcdFiles_Sum;

	h.push_back("ABCD1.HT1.CutRegion");
	h.push_back("ABCD1.HT2.CutRegion");
	h.push_back("ABCD1.HT3.CutRegion");

	abcdFiles_Bg.push_back("abcd_OnlySumBg");

	abcdFiles_Sum.push_back("SumBg_BH_450");
	abcdFiles_Sum.push_back("SumBg_BH_500");
	abcdFiles_Sum.push_back("SumBg_BH_550");
	abcdFiles_Sum.push_back("SumBg_BH_600");
	abcdFiles_Sum.push_back("SumBg_BH_650");
	abcdFiles_Sum.push_back("SumBg_BH_700");
	abcdFiles_Sum.push_back("SumBg_BH_750");
	abcdFiles_Sum.push_back("SumBg_BH_800");
	abcdFiles_Sum.push_back("SumBg_BH_1000");
	abcdFiles_Sum.push_back("SumBg_BH_1200");
	abcdFiles_Sum.push_back("SumBg_BH_1500");

	abcdFiles_Sig.push_back("BH_450");
	abcdFiles_Sig.push_back("BH_500");
	abcdFiles_Sig.push_back("BH_550");
	abcdFiles_Sig.push_back("BH_600");
	abcdFiles_Sig.push_back("BH_650");
	abcdFiles_Sig.push_back("BH_700");
	abcdFiles_Sig.push_back("BH_750");
	abcdFiles_Sig.push_back("BH_800");
	abcdFiles_Sig.push_back("BH_1000");
	abcdFiles_Sig.push_back("BH_1200");
	abcdFiles_Sig.push_back("BH_1500");

	TFile* fileSum[abcdFiles_Sum.size()];
	TFile* fileSig[abcdFiles_Sig.size()];
	TFile* fileBg[abcdFiles_Bg.size()];

	TH1F* hSum[h.size()][abcdFiles_Sum.size()];
	TH1F* hSig[h.size()][abcdFiles_Sig.size()];
	TH1F* hBg[h.size()][abcdFiles_Bg.size()];

	fstream h_txt[h.size()];
	//// Load files and histogram	
	for( int i=0; i<abcdFiles_Bg.size(); i++ ){
		string filePath=loadPath+"/"+abcdFiles_Bg[i]+".root";
		cout<<"Load "<<filePath<<endl;
		fileBg[i] = new TFile(filePath.c_str());
		for( int j=0; j<h.size(); j++){
			hBg[j][i] = (TH1F*)fileBg[i]->Get(h[j].c_str());
		}
	}
	for( int i=0; i<abcdFiles_Sig.size(); i++){
		string filePath=loadPath+"/abcd_"+abcdFiles_Sig[i]+".root";
		cout<<"Load "<<filePath<<endl;
		fileSig[i] = new TFile(filePath.c_str());
		for( int j=0; j<h.size(); j++){
			hSig[j][i] = (TH1F*)fileSig[i]->Get(h[j].c_str());
		}
	}
	for( int i=0; i<abcdFiles_Sum.size(); i++ ){
		string filePath=loadPath+"/abcd_"+abcdFiles_Sum[i]+".root";
		cout<<"Load "<<filePath<<endl;
		fileSum[i] = new TFile(filePath.c_str());
		for( int j=0; j<h.size(); j++){
			hSum[j][i] = (TH1F*)fileSum[i]->Get(h[j].c_str());
		}
	}
	//// Count	
	for( int i=0; i<h.size(); i++){
		cout<<"Star for "<<h[i]<<endl;
		string save=savePath+"/ABCD_Count_"+h[i]+".txt";
		h_txt[i].open(save.c_str(),ios_base::out);
		
		for( int j=0; j<abcdFiles_Bg.size(); j++ ){
			countAndStore("Background", h_txt[i], hBg[i][j], hBg[i][j]);
			for( int k=0; k<abcdFiles_Sig.size(); k++){
				countAndStore(abcdFiles_Sig[k], h_txt[i],hSig[i][k], hBg[i][j]);
			}
		}
		for( int k=0; k<abcdFiles_Sum.size(); k++){
			countAndStore(abcdFiles_Sum[k], h_txt[i],hSum[i][k], hSum[i][k]);
		}
		h_txt[i].close();
	}
}
