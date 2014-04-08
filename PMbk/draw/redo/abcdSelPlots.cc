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

void abcdSelPlots(){
	
	const int One=1;
	const int Two=7;
	const int Three=9;
	
	setTDRStyle();

	string loadPath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/result/root/abcd";
	string savePath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/result/png/abcd";

	vector<string> abcdFiles_Sig;
	vector<string> abcdFiles_Bg;
	vector<string> abcdFiles_Sum;

	abcdFiles_Bg.push_back("abcd_OnlySumBg");

/*	abcdFiles_Sum.push_back("abcd_SumBg_BH_450");
	abcdFiles_Sum.push_back("abcd_SumBg_BH_500");
	abcdFiles_Sum.push_back("abcd_SumBg_BH_550");
	abcdFiles_Sum.push_back("abcd_SumBg_BH_600");
	abcdFiles_Sum.push_back("abcd_SumBg_BH_650");
	abcdFiles_Sum.push_back("abcd_SumBg_BH_700");
	abcdFiles_Sum.push_back("abcd_SumBg_BH_750");
	abcdFiles_Sum.push_back("abcd_SumBg_BH_800");
	abcdFiles_Sum.push_back("abcd_SumBg_BH_1000");
	abcdFiles_Sum.push_back("abcd_SumBg_BH_1200");
	abcdFiles_Sum.push_back("abcd_SumBg_BH_1500");
*/
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

//	TFile* fileSum[abcdFiles_Sum.size()];
	TFile* fileSig[abcdFiles_Sig.size()];
	TFile* fileBg[abcdFiles_Bg.size()];

//	TH1F* hSum[th1_size_][abcdFiles_Sum.size()];
	TH1F* hSig[th1_size_][abcdFiles_Sig.size()];
	TH1F* hBg[th1_size_][abcdFiles_Bg.size()];
	TLegend* leg[th1_size_][abcdFiles_Bg.size()][abcdFiles_Sig.size()];
	TLegend* leg3Sig[th1_size_];

	TCanvas* c1=new TCanvas("c1", "", 850, 700);
//	c1->SetGridx();
//	c1->SetGridy();
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	
	for( int i=0; i<abcdFiles_Bg.size(); i++ ){
		string filePath=loadPath+"/"+abcdFiles_Bg[i]+".root";
		cout<<"Load "<<filePath<<endl;
		fileBg[i] = new TFile(filePath.c_str());
		for( int j=0; j<th1_size_; j++){
			hBg[j][i] = (TH1F*)fileBg[i]->Get(TH1Info[j].name.c_str());
			hBg[j][i]->UseCurrentStyle();	
			hBg[j][i]->Rebin(OtherInfo[j].rebin);	
		}
	}
	for( int i=0; i<abcdFiles_Sig.size(); i++){
		string filePath=loadPath+"/abcd_"+abcdFiles_Sig[i]+".root";
		cout<<"Load "<<filePath<<endl;
		fileSig[i] = new TFile(filePath.c_str());
		for( int j=0; j<th1_size_; j++){
			hSig[j][i] = (TH1F*)fileSig[i]->Get(TH1Info[j].name.c_str());
			hSig[j][i]->UseCurrentStyle();	
			hSig[j][i]->Rebin(OtherInfo[j].rebin);	
		}
	}

	for( int i=0; i<th1_size_; i++){
		if( !TH1Info[i].output ) continue;
		cout<<"Star for "<<TH1Info[i].name<<endl;

		for( int j=0; j<abcdFiles_Bg.size(); j++ ){
			float binwidth = 0;
			char title[100], xtitle[100], ytitle[100];

			binwidth = hBg[i][j]->GetBinWidth(1);
			if( TH1Info[i].xunit.size()!=0 ){
				sprintf( xtitle, "%s [%s]", TH1Info[i].xtitle.c_str(),TH1Info[i].xunit.c_str());
				if (binwidth<1){
					//sprintf( ytitle, "%s / [%0.2f%s]", TH1Info[i].ytitle.c_str(),binwidth,TH1Info[i].xunit.c_str());
					sprintf( ytitle, "%s / [%0.2f%s]", "PDF" ,binwidth,TH1Info[i].xunit.c_str());
				}else{
					//sprintf( ytitle, "%s / [%1.0f%s]", TH1Info[i].ytitle.c_str(),binwidth,TH1Info[i].xunit.c_str());
					sprintf( ytitle, "%s / [%1.0f%s]", "PDF" ,binwidth,TH1Info[i].xunit.c_str());
				}
			}else{
				sprintf( xtitle, "%s", TH1Info[i].xtitle.c_str());
				//sprintf( ytitle, "%s", TH1Info[i].ytitle.c_str());
				sprintf( ytitle, "%s", "PDF");
			}
			hBg[i][j]->SetXTitle(xtitle);
			hBg[i][j]->SetYTitle(ytitle);
			//hBg[i][j]->SetYTitle("PDF");

			//hBg[i][j]->SetLineColor(kOrange+1);
			hBg[i][j]->SetLineColor(2);
			hBg[i][j]->SetLineWidth(3);
			hBg[i][j]->SetLineStyle(1);
			hBg[i][j]->GetXaxis()->SetRangeUser(OtherInfo[i].SetXMinimum,OtherInfo[i].SetXMaximum);
			hBg[i][j]->GetYaxis()->SetRangeUser(OtherInfo[i].SetYMinimum,OtherInfo[i].SetYMaximum);

/*			// each signal compare with background
			for( int k=0; k<abcdFiles_Sig.size(); k++){
				hSig[i][k]->SetLineColor(kAzure+2);
				hSig[i][k]->SetLineWidth(3);
				hSig[i][k]->SetLineStyle(1);

				leg[i][j][k]= new TLegend(0.70, 0.70, 0.90, 0.90);
				leg[i][j][k]->AddEntry(hBg[i][j],"Background");
				leg[i][j][k]->AddEntry(hSig[i][k],abcdFiles_Sig[k].c_str());
        			leg[i][j][k]->SetFillStyle(0);
			        leg[i][j][k]->SetBorderSize(0);
			        leg[i][j][k]->SetTextSize(0.042);
			
				if( OtherInfo[i].yLog ){
					gPad->SetLogy(1);
				}else{
					gPad->SetLogy(0);
				}	
				hBg[i][j]->Draw();
				hSig[i][k]->Draw("SAME");
				leg[i][j][k]->Draw();
				string save=savePath+"/"+TH1Info[i].name+"_CompareBgAnd"+abcdFiles_Sig[k]+".png";
				c1->SaveAs(save.c_str());	
			}*/

			// 3 signal compare with background
			double nomal = 1/(hBg[i][j]->Integral());
			double nomal_1 = 1/(hSig[i][One]->Integral());
			double nomal_2 = 1/(hSig[i][Two]->Integral());
			double nomal_3 = 1/(hSig[i][Three]->Integral());
			hBg[i][j]->Scale(nomal);
			hSig[i][One]->Scale(nomal_1);
			hSig[i][Two]->Scale(nomal_2);
			hSig[i][Three]->Scale(nomal_3);

			double maxSig;
			if( hSig[i][One]->GetMaximum() > hSig[i][Three]->GetMaximum()){
				maxSig=hSig[i][One]->GetMaximum();
			}else{
				maxSig=hSig[i][Three]->GetMaximum();
			}
			if( hBg[i][j]->GetMaximum() < maxSig ) hBg[i][j]->SetMaximum(maxSig+maxSig/10);
			
			hBg[i][j]->Draw("HIST");
			leg3Sig[i]= new TLegend(OtherInfo[i].LegLBX, OtherInfo[i].LegLBY, OtherInfo[i].LegRTX, OtherInfo[i].LegRTY);
			leg3Sig[i]->AddEntry(hBg[i][j],"Background");
			for( int k=0; k<abcdFiles_Sig.size(); k++){
				if( k==One ){
					hSig[i][k]->SetLineColor(kAzure+2);
				}else if( k==Two ){
					hSig[i][k]->SetLineColor(kViolet+2);
				}else if( k==Three){
					hSig[i][k]->SetLineColor(kSpring+9);
				}else{
					continue;	
				} 
				hSig[i][k]->SetLineWidth(3);
				hSig[i][k]->SetLineStyle(1);

				leg3Sig[i]->AddEntry(hSig[i][k],abcdFiles_Sig[k].c_str());
			
				if( OtherInfo[i].yLog ){
					gPad->SetLogy(1);
				}else{
					gPad->SetLogy(0);
				}	
				hSig[i][k]->Draw("HIST SAME");
			}
        		leg3Sig[i]->SetFillStyle(0);
		        leg3Sig[i]->SetBorderSize(0);
		        leg3Sig[i]->SetTextSize(0.042);
			leg3Sig[i]->Draw("HIST");
			string save=savePath+"/ABCDSel_"+TH1Info[i].name+"_CompareBgAnd_3Sig.png";
			c1->SaveAs(save.c_str());	
		}
	}
}
