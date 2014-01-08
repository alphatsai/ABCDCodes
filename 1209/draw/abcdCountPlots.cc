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
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1209/interface/selection.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1209/interface/sampleInfo.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1209/interface/plotsInfoABCD.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1209/interface/setTDRStyle.C"
using namespace std;

void abcdCountPlots(){
	
	//bool UseLogy=false;	
	//bool UseLogy=1;	
	bool UseLogy=0;	
	//const int One=1;
	const int One=0;
	const int Two=7;
	const int Three=9;
	
	setTDRStyle();

	string loadPath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1209/result/root/abcd";
	string savePath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1209/result/png/abcd";

	vector<string> h;
	vector<string> abcdFiles_Sig;
	vector<string> abcdFiles_Bg;
	vector<string> abcdFiles_Sum;

	h.push_back("ABCD1.SubjetPt_Ht");
	h.push_back("ABCD2.SubLeadingSubCSV_HtAK5CA8");
	h.push_back("ABCD3.LeadingSubCSV_HtAK5");
	h.push_back("ABCD4.BigestCSV12_HtAK5CA8");

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
	abcdFiles_Sig.push_back("AllData");
/*	abcdFiles_Sig.push_back("BH_450");
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
*/
//	TFile* fileSum[abcdFiles_Sum.size()];
	TFile* fileSig[abcdFiles_Sig.size()];
	TFile* fileBg[abcdFiles_Bg.size()];

//	TH1F* hSum[h.size()][abcdFiles_Sum.size()];
	TH1F* hSig[h.size()][abcdFiles_Sig.size()];
	TH1F* hBg[h.size()][abcdFiles_Bg.size()];
	TLegend* leg[h.size()][abcdFiles_Bg.size()][abcdFiles_Sig.size()];
	TLegend* leg3Sig[h.size()];

	TCanvas* c1=new TCanvas("c1", "", 850, 700);
	c1->SetGridx();
	c1->SetGridy();
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	
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
		cout<<"Star for "<<h[i]<<endl;

		//// Draw plots ////===================================================================================================
		for( int j=0; j<abcdFiles_Bg.size(); j++ ){
			//hBg[i][j]->SetLineColor(kOrange+1);
			hBg[i][j]->SetLineColor(2);
			hBg[i][j]->SetLineWidth(3);
			hBg[i][j]->SetLineStyle(1);
			hBg[i][j]->GetYaxis()->SetRangeUser(850,4000);
			hBg[i][j]->SetXTitle("Cut Region");
			hBg[i][j]->SetYTitle("Yields");

			// signal compare with background
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
			
				if( UseLogy ){
					gPad->SetLogy(1);
				}else{
					gPad->SetLogy(0);
				}	
				hBg[i][j]->Draw("");
				hBg[i][j]->Draw("TEXT0 SAME ");
				hSig[i][k]->Draw("SAME ");
				hSig[i][k]->Draw("TEXT0 SAME ");
				leg[i][j][k]->Draw();
				string save=savePath+"/"+h[i]+"_CompareBgAnd"+abcdFiles_Sig[k]+".png";
				c1->SaveAs(save.c_str());	
			}

			// 3 signal compare with background
			hBg[i][j]->Draw();
			hBg[i][j]->Draw("TEXT0 SAME");
			leg3Sig[i]= new TLegend(0.75, 0.8, 1., 1.);
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
			
				if( UseLogy ){
					gPad->SetLogy(1);
				}else{
					gPad->SetLogy(0);
				}	
				hSig[i][k]->Draw("SAME");
				hSig[i][k]->Draw("TEXT0 SAME");
			}
        		leg3Sig[i]->SetFillStyle(0);
		        leg3Sig[i]->SetBorderSize(0);
		        leg3Sig[i]->SetTextSize(0.042);
			leg3Sig[i]->Draw();
			string save=savePath+"/"+h[i]+"_CompareBgAnd_3Sig.png";
			c1->SaveAs(save.c_str());	
		}
	}
}
