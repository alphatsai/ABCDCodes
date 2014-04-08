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
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/interface/selection.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/interface/sampleInfo.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/interface/plotsInfoABCD.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/interface/setTDRStyle.C"
using namespace std;
void setXYTitle(TH1F* h, string xt, string yt, string xu=""){
	float binwidth = 0;
	char  xtitle[100], ytitle[100];
	binwidth = h->GetBinWidth(1);
	if( xu.size()!=0 ){
		sprintf( xtitle, "%s [%s]", xt.c_str(), xu.c_str());
		if (binwidth<1){
			sprintf( ytitle, "%s / [%0.2f%s]", yt.c_str(), binwidth, xu.c_str());
		}else{
			sprintf( ytitle, "%s / [%1.0f%s]", yt.c_str(), binwidth, xu.c_str());
		}
			}else{
		sprintf( xtitle, "%s", xt.c_str());
		sprintf( ytitle, "%s", yt.c_str());
	}
	h->SetXTitle(xtitle);
	h->SetYTitle(ytitle);
}

void abcdHiggsMass(){
	
	//bool UseLogy=1;	
	//bool UseLogy=0;	
	int rebin=10;

	
	setTDRStyle();

	string loadPath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/result/root/abcd";
	string savePath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/result/png/abcd";
//	string loadPath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/result/root/abcd/HTNAME";
//	string savePath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/result/png/abcd/tmp";

	vector<string> h;
	vector<string> abcdFiles_Data;
	vector<string> abcdFiles_Sig;
	vector<string> abcdFiles_Bg;
	vector<string> abcdFiles_Sum;

	h.push_back("ABCDana_HiggsMass");
	h.push_back("ABCDana_HiggsMass_A");
	h.push_back("ABCDana_HiggsMass_B");
	h.push_back("ABCDana_HiggsMass_C");
	h.push_back("ABCDana_HiggsMass_D");
	h.push_back("ABCDval_HiggsMass");
	h.push_back("ABCDval_HiggsMass_A");
	h.push_back("ABCDval_HiggsMass_B");
	h.push_back("ABCDval_HiggsMass_C");
	h.push_back("ABCDval_HiggsMass_D");
	abcdFiles_Bg.push_back("abcd_OnlySumBg");
	abcdFiles_Data.push_back("abcd_AllData");

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

	TFile* fileSig[abcdFiles_Sig.size()];
	TFile* fileBg[abcdFiles_Bg.size()];
	TFile* fileData[abcdFiles_Data.size()];

	TH1F* hSig[h.size()][abcdFiles_Sig.size()];
	TH1F* hBg[h.size()][abcdFiles_Bg.size()];
	TH1F* hData[h.size()][abcdFiles_Data.size()];
	//TLegend* leg[h.size()][abcdFiles_Bg.size()][abcdFiles_Sig.size()];
	//TLegend* leg3Sig[h.size()];

	TCanvas* c1=new TCanvas("c1", "", 850, 700);
//	c1->SetGridx();
//	c1->SetGridy();
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);

	for( int i=0; i<abcdFiles_Data.size(); i++ ){
		string filePath=loadPath+"/"+abcdFiles_Data[i]+".root";
		cout<<"Load "<<filePath<<endl;
		fileData[i] = new TFile(filePath.c_str());
		for( int j=0; j<h.size(); j++){
			hData[j][i] = (TH1F*)fileData[i]->Get(h[j].c_str());
			hData[j][i]->UseCurrentStyle();	
		}
	}
	for( int i=0; i<abcdFiles_Bg.size(); i++ ){
		string filePath=loadPath+"/"+abcdFiles_Bg[i]+".root";
		cout<<"Load "<<filePath<<endl;
		fileBg[i] = new TFile(filePath.c_str());
		for( int j=0; j<h.size(); j++){
			hBg[j][i] = (TH1F*)fileBg[i]->Get(h[j].c_str());
			hBg[j][i]->UseCurrentStyle();	
		}
	}
	for( int i=0; i<abcdFiles_Sig.size(); i++){
		string filePath=loadPath+"/abcd_"+abcdFiles_Sig[i]+".root";
		cout<<"Load "<<filePath<<endl;
		fileSig[i] = new TFile(filePath.c_str());
		for( int j=0; j<h.size(); j++){
			hSig[j][i] = (TH1F*)fileSig[i]->Get(h[j].c_str());
			hSig[j][i]->UseCurrentStyle();	
		}
	}

	for( int i=0; i<h.size(); i++){
//	for( int i=4; i<5; i++){
		cout<<"Star for "<<h[i]<<endl;

		//// Draw plots ////===================================================================================================
		for( int j=0; j<abcdFiles_Data.size(); j++ ){
			hData[i][j]->Rebin(rebin);
			hData[i][j]->SetLineColor(4);
			hData[i][j]->SetLineWidth(3);
			hData[i][j]->SetLineStyle(1);

			setXYTitle(hData[i][j], "CA8 Mass", "Yields", "GeV/c^{2}");
			hData[i][j]->Draw("HIST");
			string save = savePath+"/"+h[i]+"_"+abcdFiles_Data[j]+".png";
			c1->SaveAs(save.c_str());
	
			setXYTitle(hData[i][j], "CA8 Mass", "PDF", "GeV/c^{2}");
			double nomal=1/(hData[i][j]->Integral());
			hData[i][j]->Scale(nomal);
			hData[i][j]->Draw("HIST");
			save = savePath+"/"+h[i]+"_Nomal_"+abcdFiles_Data[j]+".png";
			c1->SaveAs(save.c_str());	
		}
		for( int j=0; j<abcdFiles_Bg.size(); j++ ){
			hBg[i][j]->Rebin(rebin);
			hBg[i][j]->SetLineColor(4);
			hBg[i][j]->SetLineWidth(3);
			hBg[i][j]->SetLineStyle(1);
			
			setXYTitle(hBg[i][j], "CA8 Mass", "Yields", "GeV/c^{2}");
			hBg[i][j]->Draw("HIST");
			string save = savePath+"/"+h[i]+"_"+abcdFiles_Bg[j]+".png";
			c1->SaveAs(save.c_str());	

			setXYTitle(hBg[i][j], "CA8 Mass", "PDF", "GeV/c^{2}");
			double nomal=1/(hBg[i][j]->Integral());
			hBg[i][j]->Scale(nomal);
			hBg[i][j]->Draw("HIST");
			save = savePath+"/"+h[i]+"_Nomal_"+abcdFiles_Bg[j]+".png";
			c1->SaveAs(save.c_str());	
		}
		for( int k=0; k<abcdFiles_Sig.size(); k++){
			hSig[i][k]->Rebin(rebin);
			hSig[i][k]->SetLineColor(4);
			hSig[i][k]->SetLineWidth(3);
			hSig[i][k]->SetLineStyle(1);

			setXYTitle(hSig[i][k], "CA8 Mass", "Yields", "GeV/c^{2}");
			hSig[i][k]->Draw("HIST");
			string save = savePath+"/"+h[i]+"_"+abcdFiles_Sig[k]+".png";
			c1->SaveAs(save.c_str());	

			setXYTitle(hSig[i][k], "CA8 Mass", "PDF", "GeV/c^{2}");
			double nomal=1/(hSig[i][k]->Integral());
			hSig[i][k]->Scale(nomal);
			hSig[i][k]->Draw("HIST");
			save = savePath+"/"+h[i]+"_Nomal_"+abcdFiles_Sig[k]+".png";
			c1->SaveAs(save.c_str());	
		}
	}
}
