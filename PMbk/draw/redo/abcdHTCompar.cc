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
const int abcd = 4;
const int rebin= 100;

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
void drawPlots( TCanvas* c1, TH1F* h1, TH1F* h2, string n1, string n2, string xt, string yt, string xu, string savePath, string fs, string hs, bool nomal=0){
	if(nomal){
		double nomal1=1/(h1->Integral());
		double nomal2=1/(h2->Integral());
		h1->Scale(nomal1);
		h2->Scale(nomal2);
	}
	string error1 = "e1"+n1+n2+fs+hs;
	string error2 = "e2"+n1+n2+fs+hs;
	TH1F* e1 = (TH1F*)h1->Clone(error1.c_str());
	TH1F* e2 = (TH1F*)h2->Clone(error2.c_str());

	e1->SetLineColor(38);
	e1->SetFillColor(38);
	e1->SetFillStyle(3345);	
	e2->SetLineColor(46);
	e2->SetFillColor(46);
	e2->SetFillStyle(3354);	

	h1->SetLineColor(4);
	h1->SetLineWidth(3);
	h1->SetLineStyle(1);
	h2->SetLineColor(2);
	h2->SetLineWidth(3);
	h2->SetLineStyle(1);
	
	TLegend* leg = new TLegend(0.75, 0.7, 1, 0.9);
       	leg->SetFillStyle(0);
        leg->SetBorderSize(0);
        leg->SetTextSize(0.042);
	leg->AddEntry(h1, n1.c_str()); 
	leg->AddEntry(h2, n2.c_str()); 
//	leg->AddEntry(e1, (n1+" error").c_str()); 
//	leg->AddEntry(e2, (n2+" error").c_str()); 

	setXYTitle( e1, xt, yt, xu);
	e1->Draw("E2");	
	e2->Draw("E2 SAME");	
	h1->Draw("HIST SAME");	
	h2->Draw("HIST SAME");
	leg->Draw("SAME");	
	string save = savePath+"/"+hs+"_Compar_"+n1+n2+"_"+fs+".png";
	c1->SaveAs(save.c_str());	

}
void abcdHTCompar(){
	
	setTDRStyle();

	string loadPath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/result/root/abcd/HTNAME";
	string savePath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/result/png/abcd/HTNAME";
//	string loadPath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/result/root/abcd/HTNAME";
//	string savePath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/result/png/abcd/tmp";

	vector<string> h;
	vector<string> abcdFiles_Data;
	vector<string> abcdFiles_Sig;
	vector<string> abcdFiles_Bg;
	vector<string> abcdFiles_Sum;

	h.push_back("ABCD1.HT1");
	h.push_back("ABCD1.HT2");
	h.push_back("ABCD1.HT3");

	abcdFiles_Bg.push_back("abcd_OnlySumBg");
//	abcdFiles_Data.push_back("abcd_AllData");

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

	TH1F* hSig[h.size()][abcdFiles_Sig.size()][abcd];
	TH1F* hBg[h.size()][abcdFiles_Bg.size()][abcd];
	TH1F* hData[h.size()][abcdFiles_Data.size()][abcd];

	TCanvas* c1=new TCanvas("c1", "", 850, 700);
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);

	for( int i=0; i<abcdFiles_Data.size(); i++ ){
		string filePath=loadPath+"/"+abcdFiles_Data[i]+".root";
		cout<<"Load "<<filePath<<endl;
		fileData[i] = new TFile(filePath.c_str());
		for( int j=0; j<h.size(); j++){
			for( int k=0; k<abcd; k++){
				string name;
				if( k==0 ){	
					name = h[j]+".A";
				}else if( k==1 ){
					name = h[j]+".B";
				}else if( k==2 ){
					name = h[j]+".C";
				}else if( k==3 ){
					name = h[j]+".D";
				} 
				hData[j][i][k] = (TH1F*)fileData[i]->Get(name.c_str());
				hData[j][i][k]->Rebin(rebin) ;
				hData[j][i][k]->UseCurrentStyle();
			}
		}
	}
	for( int i=0; i<abcdFiles_Bg.size(); i++ ){
		string filePath=loadPath+"/"+abcdFiles_Bg[i]+".root";
		cout<<"Load "<<filePath<<endl;
		fileBg[i] = new TFile(filePath.c_str());
		for( int j=0; j<h.size(); j++){
			for( int k=0; k<abcd; k++){
				string name;
				if( k==0 ){	
					name = h[j]+".A";
				}else if( k==1 ){
					name = h[j]+".B";
				}else if( k==2 ){
					name = h[j]+".C";
				}else if( k==3 ){
					name = h[j]+".D";
				} 
				hBg[j][i][k] = (TH1F*)fileBg[i]->Get(name.c_str());
				hBg[j][i][k]->Rebin(rebin) ;
				hBg[j][i][k]->UseCurrentStyle();
			}
		}
	}
	for( int i=0; i<abcdFiles_Sig.size(); i++){
		string filePath=loadPath+"/abcd_"+abcdFiles_Sig[i]+".root";
		cout<<"Load "<<filePath<<endl;
		fileSig[i] = new TFile(filePath.c_str());
		for( int j=0; j<h.size(); j++){
			for( int k=0; k<abcd; k++){
				string name;
				if( k==0 ){	
					name = h[j]+".A";
				}else if( k==1 ){
					name = h[j]+".B";
				}else if( k==2 ){
					name = h[j]+".C";
				}else if( k==3 ){
					name = h[j]+".D";
				} 
				hSig[j][i][k] = (TH1F*)fileSig[i]->Get(name.c_str());
				hSig[j][i][k]->Rebin(rebin) ;
				hSig[j][i][k]->UseCurrentStyle();
			}
		}
	}

	for( int i=0; i<h.size(); i++){
//	for( int i=0; i<1; i++){
		cout<<"Star for "<<h[i]<<endl;

		//// Draw plots ////===================================================================================================
		for( int j=0; j<abcdFiles_Bg.size(); j++ ){
//		for( int j=0; j<1; j++ ){
			drawPlots( c1, hBg[i][j][0], hBg[i][j][2], "A region", "C region", "HT", "PDF", "GeV", savePath, abcdFiles_Bg[j], h[i], 1);
			drawPlots( c1, hBg[i][j][1], hBg[i][j][3], "B region", "D region", "HT", "PDF", "GeV", savePath, abcdFiles_Bg[j], h[i], 1);
		}
		for( int j=0; j<abcdFiles_Data.size(); j++ ){
			drawPlots( c1, hData[i][j][0], hData[i][j][2], "A region", "C region", "HT", "PDF", "GeV", savePath, abcdFiles_Data[j], h[i], 1);
			drawPlots( c1, hData[i][j][1], hData[i][j][3], "B region", "D region", "HT", "PDF", "GeV", savePath, abcdFiles_Data[j], h[i], 1);
		}
		for( int j=0; j<abcdFiles_Sig.size(); j++){
			drawPlots( c1, hSig[i][j][0], hSig[i][j][2], "A region", "C region", "HT", "", "GeV", savePath, abcdFiles_Sig[j], h[i], 1);
			drawPlots( c1, hSig[i][j][1], hSig[i][j][3], "B region", "D region", "HT", "", "GeV", savePath, abcdFiles_Sig[j], h[i], 1);
		}
	}
}
