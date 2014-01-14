#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include "TFile.h"
#include "TH1.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TGraphAsymmErrors.h"
#include "TEfficiency.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TROOT.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/interface/plotsInfo.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/interface/countMatchingInfo.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/interface/saveEffPlot.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/interface/setTDRStyle.C"
using namespace std;

// The PlotsInfo and CountMatchingInfo in Interface
// Global Const. : int SigMC_TotalNum = 4 (900, 1100, 1300, 1500) default
//		   int th1_size       = 5	
// Struct Info.  : struct SigMC 	 [SigMC_TotalNum], Order: 1500, 1300, 1100, 900
//               : struct SigMC_OrderRev [SigMC_TotalNum], Order: 900, 1100, 1300, 1500
//               : struct TH1Info [th1_size_]
//	    	   Struct OtherInfo [th1_size_]	
// Function      : CountNum( string masspoint_, TFile* f1, fstream &outfile_)
//
// Date: 2012/03/17 Alpha
void checkEff(){
	TFile* 	infileRoot_[SigMC_TotalNum];
	TH1F*  	getTH1[SigMC_TotalNum][th1_size_];  
	fstream outfileTxt_;
	outfileTxt_.open("/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/resurlt/txt/ExtraSVFdR_MachingCount.txt", ios_base::out);

	setTDRStyle();

	///////// Star to Load TFile, TH1F, output .txt /////////
	for ( int i=0; i<SigMC_TotalNum; i++){
		//Load Root File		
		string path_s = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/resurlt/root/mc/sig/ExtraSVFdR_BH"+SigMC[i].massPoint+"_GMdR05dRbCA8.root";
		infileRoot_[i] = new TFile(path_s.c_str());
		cout<<"Already Open Root File : "<<path_s<<endl;
		CountNum(SigMC[i].massPoint, infileRoot_[i], outfileTxt_ );		
			
		//Load TH1F
		for(int j=0; j<th1_size_; j++){
			getTH1[i][j]=(TH1F*)infileRoot_[i]->Get(TH1Info[j].name.c_str());
			getTH1[i][j]->UseCurrentStyle();
		}
		cout<<"Aready load TH1F"<<endl;
	}

	//// Save Eff. ////
	SaveEffPlot("GMdR5dRbCA8-CA8JetInfo.Pt.NumCA8PDoubleBTag", "GMdR5dRbCA8-CA8JetInfo.Pt", infileRoot_, 1, 0.2, 0.35, 0.30, 0.45, 0, 0.6, 200, -1111,
		    "Eff. of Matched CA8 with +2Btag", "CA8-Jets Pt [GeV/c]",  "Eff.", "ExtraSVFdR_GMdR5dRbCA8-CA8JetInfo.Pt.EffCA8PDoubleBtag");
	SaveEffPlot("GMdR5dRbCA8-HiggsInfo.Pt", "UnM-HiggsInfo.Pt", infileRoot_, 1, 0.20, 0.7, 0.40, 0.85, 0, 1.5, 200, -1111, 
		    "Eff. of Gen-Matching", "H>bb Pt [GeV/c]", "Eff.", "ExtraSVFdR_GMdR5dRbCA8-HiggsInfo.Pt.EffGenMatching");
	SaveEffPlot("GMdR5dRbCA8-HiggsInfo.Pt.NumCA8PDoubleBTag", "GMdR5dRbCA8-HiggsInfo.Pt", infileRoot_, 1, 0.35, 0.7, 0.55, 0.85, 0, 0.6, 200, -1111,
		    "Eff. of selection, +2Btag", "H>bb Pt [GeV/c]",  "Eff.", "ExtraSVFdR_GMdR5dRbCA8-HiggsInfo.Pt.EffCA8PDoubleBtag");
	SaveEffPlot("GMdR5dRbCA8-HiggsInfo.Pt.NumCA8PDoubleBTag", "UnM-HiggsInfo.Pt", infileRoot_, 1, 0.35, 0.7, 0.55, 0.85, 0, 0.6, 200, -1111,
		    "Eff. of Gen-Matching and selection, +2Btag", "H>bb Pt [GeV/c]",  "Eff.", "ExtraSVFdR_GMdR5dRbCA8-HiggsInfo.Pt.EffGenMatchingDoubleBtag");

	//////////// Draw Mass point Comparation plots .pdf ///////////
	TCanvas* c1 = new TCanvas( "dR_hPt_color", "", 850, 700);
	//c1->SetGridx();
	//c1->SetGridy();
	gStyle->SetOptStat(0);

	//// Save TH1F ////	
	TLegend* leg[th1_size_];
	for(int j=0; j<th1_size_; j++){
		if( TH1Info[j].output ){
			string pdf_s="/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/resurlt/pdf/mc/sig/ExtraSVFdR/ExtraSVFdRAllmass_"+TH1Info[j].name+".pdf";

			// Set leg, th1: color, wirth...
			leg[j] = new TLegend(OtherInfo[j].LegLBX, OtherInfo[j].LegLBY, OtherInfo[j].LegRTX, OtherInfo[j].LegRTY);
			leg[j]->SetFillColor(0);
			leg[j]->SetTextSize(0.03);
			if( !TH1Info[j].mcOrderRev ) {
				for( int i=0; i<SigMC_TotalNum; i++ ){
					cout<<SigMC[i].massPoint<<" =>> ";
					getTH1[i][j]->Rebin(OtherInfo[j].rebin);
					///// set x/y title //////
					char ytitle[100];
					char xtitle[100];
					if( TH1Info[j].unit.size()!=0 ){
						sprintf( xtitle, "%s [%s]", TH1Info[j].xtitle.c_str(),TH1Info[j].unit.c_str());
						if (getTH1[i][j]->GetBinWidth(1)<1){
							sprintf( ytitle, "%s / [%0.2f%s]", TH1Info[j].ytitle.c_str(),getTH1[i][j]->GetBinWidth(1),TH1Info[j].unit.c_str());
						}else{
							sprintf( ytitle, "%s / [%2.1f%s]", TH1Info[j].ytitle.c_str(),getTH1[i][j]->GetBinWidth(1),TH1Info[j].unit.c_str());
						}
					}else{
						sprintf( xtitle, "%s", TH1Info[j].xtitle.c_str());
						sprintf( ytitle, "%s", TH1Info[j].ytitle.c_str());

					}
					//if(TH1Info[j].nomalized) getTH1[i][j]->Scale(1000*lumi*SigMC[i].xsec/SigMC[i].totalEvt);
					getTH1[i][j]->GetXaxis()->SetRangeUser(OtherInfo[j].SetXMinimum,OtherInfo[j].SetXMaximum);
					getTH1[i][j]->GetYaxis()->SetRangeUser(OtherInfo[j].SetYMinimum,OtherInfo[j].SetYMaximum);
					//getTH1[i][j]->SetTitle(TH1Info[j].title.c_str());
					getTH1[i][j]->SetXTitle(xtitle);
					getTH1[i][j]->SetYTitle(ytitle);
					getTH1[i][j]->SetTitleOffset(OtherInfo[j].SetYtileOffset,"Y");
					getTH1[i][j]->SetLineStyle(SigMC[i].LineStyle);
					getTH1[i][j]->SetLineColor(SigMC[i].LineColor);
					getTH1[i][j]->SetLineWidth(3);
					getTH1[i][j]->SetMarkerColor(0);
					if( i==0 ){
						getTH1[i][j]->Draw();
					}else{
						getTH1[i][j]->Draw("same");
					}
					leg[j]->AddEntry(getTH1[i][j], SigMC[i].LegTitle, OtherInfo[j].LegOption);
				}
			}else{
				for( int i=SigMC_TotalNum-1; i>=0; i--){ //Reverse the Order of MassPoint Sample (900, 1100, 1300, 1500...)
					cout<<SigMC[i].massPoint<<" =>> ";
					getTH1[i][j]->Rebin(OtherInfo[j].rebin);
					///// set x/y title //////
					char ytitle[100];
					char xtitle[100];
					if( TH1Info[j].unit.size()!=0 ){
						sprintf( xtitle, "%s [%s]", TH1Info[j].xtitle.c_str(),TH1Info[j].unit.c_str());
						if (getTH1[i][j]->GetBinWidth(1)<1){
							sprintf( ytitle, "%s / [%0.2f%s]", TH1Info[j].ytitle.c_str(),getTH1[i][j]->GetBinWidth(1),TH1Info[j].unit.c_str());
						}else{
							sprintf( ytitle, "%s / [%2.1f%s]", TH1Info[j].ytitle.c_str(),getTH1[i][j]->GetBinWidth(1),TH1Info[j].unit.c_str());
						}
					}else{
						sprintf( xtitle, "%s", TH1Info[j].xtitle.c_str());
						sprintf( ytitle, "%s", TH1Info[j].ytitle.c_str());

					}
					//if(TH1Info[j].nomalized) getTH1[i][j]->Scale(1000*lumi*SigMC[i].xsec/SigMC[i].totalEvt);
					getTH1[i][j]->GetXaxis()->SetRangeUser(OtherInfo[j].SetXMinimum,OtherInfo[j].SetXMaximum);
					getTH1[i][j]->GetYaxis()->SetRangeUser(OtherInfo[j].SetYMinimum,OtherInfo[j].SetYMaximum);
					//getTH1[i][j]->SetTitle(TH1Info[j].title.c_str());
					getTH1[i][j]->SetXTitle(xtitle);
					getTH1[i][j]->SetYTitle(ytitle);
					getTH1[i][j]->SetTitleOffset(OtherInfo[j].SetYtileOffset,"Y");
					getTH1[i][j]->SetLineStyle(SigMC[i].LineStyle);
					getTH1[i][j]->SetLineColor(SigMC[i].LineColor);
					getTH1[i][j]->SetLineWidth(3);
					getTH1[i][j]->SetMarkerColor(0);
					if( i==SigMC_TotalNum-1 ){
						getTH1[i][j]->Draw();
					}else{
						getTH1[i][j]->Draw("same");
					}
					leg[j]->AddEntry(getTH1[i][j], SigMC[i].LegTitle, OtherInfo[j].LegOption);
				}
			}
			cout<<" "<<TH1Info[j].name<<endl;
			leg[j]->SetTextSize(0.042);	
			leg[j]->SetBorderSize(0);	
			leg[j]->SetFillStyle(0);	
			leg[j]->Draw();
			c1->SaveAs(pdf_s.c_str());
			//c1->SaveAs(pdf_c);
		}
	}//end Save TH1F
	outfileTxt_.close();
}	
