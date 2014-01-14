#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include "TFile.h"
#include "TLine.h"
#include "TH1.h"
#include "TH1F.h"
#include "TH2F.h"
#include "THStack.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TROOT.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/selection.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/sampleInfo.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/plotsInfoABCD.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/setTDRStyle_2d.C"
//#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/setTDRStyle.C"
using namespace std;

void abcdPlots(){

	setTDRStyle();

	string loadPath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/result/root/abcd";
	string savePath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/result/png/abcd";
	vector<string> abcdFiles;
	abcdFiles.push_back("abcd_AllData");
	abcdFiles.push_back("abcd_OnlySumBg");
/*	abcdFiles.push_back("abcd_SumBg_BH_450");
	abcdFiles.push_back("abcd_SumBg_BH_500");
	abcdFiles.push_back("abcd_SumBg_BH_550");
	abcdFiles.push_back("abcd_SumBg_BH_600");
	abcdFiles.push_back("abcd_SumBg_BH_650");
	abcdFiles.push_back("abcd_SumBg_BH_700");
	abcdFiles.push_back("abcd_SumBg_BH_750");
	abcdFiles.push_back("abcd_SumBg_BH_800");
	abcdFiles.push_back("abcd_SumBg_BH_1000");
	abcdFiles.push_back("abcd_SumBg_BH_1200");
	abcdFiles.push_back("abcd_SumBg_BH_1500");
	abcdFiles.push_back("abcd_BH_450");
	abcdFiles.push_back("abcd_BH_500");
	abcdFiles.push_back("abcd_BH_550");
	abcdFiles.push_back("abcd_BH_600");
	abcdFiles.push_back("abcd_BH_650");
	abcdFiles.push_back("abcd_BH_700");
	abcdFiles.push_back("abcd_BH_750");
	abcdFiles.push_back("abcd_BH_800");
	abcdFiles.push_back("abcd_BH_1000");
	abcdFiles.push_back("abcd_BH_1200");
	abcdFiles.push_back("abcd_BH_1500");*/
	TFile* file[abcdFiles.size()];
	TLine* lx[abcdFiles.size()][th2_size_];
	TLine* ly[abcdFiles.size()][th2_size_];
	TH2F* h[abcdFiles.size()][th2_size_];
	TCanvas* c1=new TCanvas("c1", "", 960, 700);
        //c1->SetGridx();
        //c1->SetGridy();
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	for( int i=0; i<abcdFiles.size(); i++ ){
	//for( int i=0; i<1; i++ ){
		string filePath=loadPath+"/"+abcdFiles[i]+".root";
		cout<<"Load "<<filePath<<endl;
		file[i] = new TFile(filePath.c_str());
		for( int j=0; j<th2_size_; j++){
			if( !TH2Info[j].output ) continue;
			string fileSave=savePath+"/"+abcdFiles[i]+"_"+TH2Info[j].name+".png";
			h[i][j]=(TH2F*)file[i]->Get(TH2Info[j].name.c_str());
			h[i][j]->UseCurrentStyle();
			h[i][j]->RebinX(Other2Info[j].xrebin);
			h[i][j]->RebinY(Other2Info[j].yrebin);
			//h[i][j]->SetMarkerStyle(6);
			double integralZ=h[i][j]->Integral();
			float binwidthX=0;
			float binwidthY=0;
			char xtitle[100], ytitle[100];
			binwidthX = h[i][j]->GetXaxis()->GetBinWidth(1);
			binwidthY = h[i][j]->GetYaxis()->GetBinWidth(1);
			if( TH2Info[j].xunit.size()!=0 ){
				if (binwidthX<1){
					sprintf( xtitle, "%s / [%0.2f%s]", TH2Info[j].xtitle.c_str(),binwidthX,TH2Info[j].xunit.c_str());
				}else{
					sprintf( xtitle, "%s / [%2.1f%s]", TH2Info[j].xtitle.c_str(),binwidthX,TH2Info[j].xunit.c_str());
				}
			}else{
				if (binwidthX<1){
					sprintf( xtitle, "%s / [%0.2f]", TH2Info[j].xtitle.c_str(),binwidthX);
				}else{
					sprintf( xtitle, "%s / [%2.1f]", TH2Info[j].xtitle.c_str(),binwidthX);
				}
			}
			if( TH2Info[j].yunit.size()!=0 ){
				if (binwidthY<1){
					sprintf( ytitle, "%s / [%0.2f%s]", TH2Info[j].ytitle.c_str(),binwidthY,TH2Info[j].yunit.c_str());
				}else{
					sprintf( ytitle, "%s / [%2.1f%s]", TH2Info[j].ytitle.c_str(),binwidthY,TH2Info[j].yunit.c_str());
				}
			}else{
				if (binwidthY<1){
					sprintf( ytitle, "%s / [%0.2f]", TH2Info[j].ytitle.c_str(),binwidthY);
				}else{
					sprintf( ytitle, "%s / [%2.1f]", TH2Info[j].ytitle.c_str(),binwidthY);
				}
			}
			h[i][j]->SetXTitle(xtitle);
			h[i][j]->SetYTitle(ytitle);

			h[i][j]->Scale(1/integralZ);
			h[i][j]->GetXaxis()->SetRangeUser(Other2Info[j].SetXMin,Other2Info[j].SetXMax);
			h[i][j]->GetYaxis()->SetRangeUser(Other2Info[j].SetYMin,Other2Info[j].SetYMax);
			//h[i][j]->GetZaxis()->SetRangeUser(Other2Info[j].SetZMin,Other2Info[j].SetZMax);
			//h[i][j]->GetZaxis()->SetRangeUser(0,1);

			float xMax, xMin, yMax, yMin;
			xMax = h[i][j]->GetXaxis()->GetBinUpEdge(h[i][j]->GetXaxis()->GetLast());
			xMin = h[i][j]->GetXaxis()->GetBinLowEdge(h[i][j]->GetXaxis()->GetFirst());
			yMax = h[i][j]->GetYaxis()->GetBinUpEdge(h[i][j]->GetXaxis()->GetLast());
			yMin = h[i][j]->GetYaxis()->GetBinLowEdge(h[i][j]->GetXaxis()->GetFirst());
			lx[i][j] = new TLine(Other2Info[j].xCut,yMin,Other2Info[j].xCut,yMax);	
			ly[i][j] = new TLine(xMin,Other2Info[j].yCut,xMax,Other2Info[j].yCut);
			lx[i][j]->SetLineStyle(8);	
			lx[i][j]->SetLineWidth(5);	
			ly[i][j]->SetLineStyle(8);	
			ly[i][j]->SetLineWidth(5);
	
		/*	if( Other2Info[j].logZ ){
				gPad->SetLogz(1);
			}else{
				gPad->SetLogz(0);
			} */
			//h[i][j]->Smooth(1,"k5a");
			h[i][j]->Draw("COLZ");
			//h[i][j]->Draw("COLZ TEXT0");
			//h[i][j]->Draw();
			lx[i][j]->Draw("SAME");
			ly[i][j]->Draw("SAME");
			c1->SaveAs(fileSave.c_str());
		}	
	}
}
