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
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/interface/sampleInfo.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/interface/plotsInfoABCD.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/interface/setTDRStyle.C"
using namespace std;
const int rebin = 100;
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
void drawExtraToD( TCanvas* c1, TH1F* hcut, TH1F* hB, TH1F* hD, string xt, string yt, string xu, string hs, string fs, string savePath, bool yLog=0){
	double A, B, C, D, dA, dB, dC, dD, CbyA;
	A = hcut->GetBinContent(1);
	B = hcut->GetBinContent(2);
	C = hcut->GetBinContent(3);
	D = hcut->GetBinContent(4);
	dA = hcut->GetBinError(1);
	dB = hcut->GetBinError(2);
	dC = hcut->GetBinError(3);
	dD = hcut->GetBinError(4);
	
	CbyA = C/A;

	double sigA = dA/A;
	double sigB = dB/B;
	double sigC = dC/C;
	double sigD = dD/D;

	string hDprime = hs+fs+"bDp";
	string hDerror = hs+fs+"error";
	TH1F* hDp = (TH1F*)hB->Clone(hDprime.c_str());
	TH1F* hDe = (TH1F*)hD->Clone(hDerror.c_str());
	hDp->Scale(CbyA);

	int hDmaxBin = hD->GetXaxis()->GetLast();;
	int hDminBin = 1;
	for( int i=hDminBin; i<=hDmaxBin; i++){
		double Bbin = hB->GetBinContent(i);
		double dBbin = hB->GetBinError(i);
		double sigBbin = dBbin/Bbin;
		double dDpbin;
		if( Bbin == 0 || A == 0 ){
			dDpbin = 0;
		}else{
			dDpbin = sqrt(sigC*sigC+sigBbin*sigBbin+sigA*sigA)*Bbin*(C/A);
		}
		//cout<<i<<" "<<Bbin<<" "<<dDpbin<<endl; 
		hDp->SetBinError(i, dDpbin);	
	}
	
	string hDprimeError = hs+fs+"bDpError";
	TH1F* hDpe = (TH1F*)hDp->Clone(hDprimeError.c_str());

	double max;	
	if( hDe->GetMaximum() >= hDpe->GetMaximum() ){
		max=hDe->GetMaximum();	
	}else{
		max=hDpe->GetMaximum();
	}

	if( yLog ){ 
		hDe->SetMaximum(max*10);
		gPad->SetLogy(1);
	}else{
		hDe->SetMaximum(max+max/10);
		gPad->SetLogy(0);
	}
	hDe->SetLineColor(46);
	hDe->SetFillColor(46);
	hDe->SetFillStyle(3345);	
	hDpe->SetLineColor(38);
	hDpe->SetFillColor(38);
	hDpe->SetFillStyle(3354);

	hD->SetLineColor(2);
	hD->SetLineWidth(3);
	hD->SetLineStyle(1);
	hDp->SetLineColor(4);
	hDp->SetLineWidth(3);
	hDp->SetLineStyle(1);

	TLegend* leg = new TLegend(0.7, 0.8, 0.95, 0.9);
       	leg->SetFillStyle(0);
        leg->SetBorderSize(0);
        leg->SetTextSize(0.042);
	leg->AddEntry(hD, "D region"); 
	leg->AddEntry(hDp, "D from B*C/A"); 
//	leg->AddEntry(hDe, "D error"); 
//	leg->AddEntry(hDpe, "B*C/A error");

	setXYTitle( hDe, xt, yt, xu);
	hDe->Draw("E2");	
	hDpe->Draw("E2 SAME");	
	hD->Draw("HIST SAME");	
	hDp->Draw("HIST SAME");
	leg->Draw("SAME");	
	string save = savePath+"/"+hs+"_ExtrapToD_"+fs+".png";
	c1->SaveAs(save.c_str());	

}

void abcdHTExtrap(){
	
	setTDRStyle();

	string loadPath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/result/root/abcd/HTNAME";
	string savePath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/result/png/abcd/HTNAME";
//	string loadPath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/result/root/abcd/HTNAME";
//	string savePath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/result/png/abcd/tmp";

	vector<string> h;
	vector<string> abcdFiles_Data;
	vector<string> abcdFiles_Bg;

	h.push_back("ABCD1.HT1");
	h.push_back("ABCD1.HT2");
	h.push_back("ABCD1.HT3");

	abcdFiles_Bg.push_back("abcd_OnlySumBg");
//	abcdFiles_Data.push_back("abcd_AllData");

	TFile* fileBg[abcdFiles_Bg.size()];
	TFile* fileData[abcdFiles_Data.size()];

	TH1F* hBgCut[h.size()][abcdFiles_Bg.size()];
	TH1F* hDataCut[h.size()][abcdFiles_Data.size()];
	TH1F* hBg_B[h.size()][abcdFiles_Bg.size()];
	TH1F* hData_B[h.size()][abcdFiles_Data.size()];
	TH1F* hBg_D[h.size()][abcdFiles_Bg.size()];
	TH1F* hData_D[h.size()][abcdFiles_Data.size()];


	//// Load files and histogram
	for( int i=0; i<abcdFiles_Data.size(); i++ ){
		string filePath=loadPath+"/"+abcdFiles_Data[i]+".root";
		cout<<"Load "<<filePath<<endl;
		fileData[i] = new TFile(filePath.c_str());
		for( int j=0; j<h.size(); j++){
			hDataCut[j][i] = (TH1F*)fileData[i]->Get((h[j]+".CutRegion").c_str());
			hData_B[j][i]  = (TH1F*)fileData[i]->Get((h[j]+".B").c_str());
			hData_D[j][i]  = (TH1F*)fileData[i]->Get((h[j]+".D").c_str());
			hData_B[j][i]->UseCurrentStyle();
			hData_D[j][i]->UseCurrentStyle();
			hData_B[j][i]->Rebin(rebin);
			hData_D[j][i]->Rebin(rebin);
		}
	}
	for( int i=0; i<abcdFiles_Bg.size(); i++ ){
		string filePath=loadPath+"/"+abcdFiles_Bg[i]+".root";
		cout<<"Load "<<filePath<<endl;
		fileBg[i] = new TFile(filePath.c_str());
		for( int j=0; j<h.size(); j++){
			hBgCut[j][i] = (TH1F*)fileBg[i]->Get((h[j]+".CutRegion").c_str());
			hBg_B[j][i]  = (TH1F*)fileBg[i]->Get((h[j]+".B").c_str());
			hBg_D[j][i]  = (TH1F*)fileBg[i]->Get((h[j]+".D").c_str());
			hBg_B[j][i]->UseCurrentStyle();
			hBg_D[j][i]->UseCurrentStyle();
			hBg_B[j][i]->Rebin(rebin);
			hBg_D[j][i]->Rebin(rebin);
		}
	}

	TCanvas* c1=new TCanvas("c1", "", 850, 700);
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	//// Count	
	for( int i=0; i<h.size(); i++){
//	for( int i=0; i<1; i++){
		cout<<"Star for "<<h[i]<<endl;
		for( int j=0; j<abcdFiles_Data.size(); j++){
			drawExtraToD( c1, hDataCut[i][j], hData_B[i][j], hData_D[i][j], "HT", "Events", "GeV", h[i], abcdFiles_Data[j], savePath, 1);
		}
		
		for( int j=0; j<abcdFiles_Bg.size(); j++ ){
//		for( int j=0; j<1; j++ ){
			drawExtraToD( c1, hBgCut[i][j], hBg_B[i][j], hBg_D[i][j], "HT", "Events", "GeV", h[i], abcdFiles_Bg[j], savePath);
		}
	}
}
