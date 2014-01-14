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
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/11AA/interface/sampleInfo.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/11AA/interface/plotsInfo.h"
//#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/11AA/interface/tmp/plotsInfo.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/11AA/interface/setTDRStyle_2d.C"
using namespace std;
void Sig2D(){

	
	////= Correct histogram Info.  =======================================================================
	TFile* sigf[SigMC_TotalNum];
	TH2F* sigH[th2_size_][SigMC_TotalNum];
	
	setTDRStyle();

	string SavePngPath = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/11AA/resurlt/png/2D";
	string SigRootPath = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/11AA/resurlt/root/mc/sig";

	for(int i=0; i<SigMC_TotalNum; i++){
		string path = SigRootPath+"/"+SigMC[i].name+".root";
		sigf[i] = new TFile(path.c_str());
	}

	TCanvas* c1 = new TCanvas( "dR_hPt_color", "", 850, 700);
        c1->SetGridx();
        c1->SetGridy();
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);

	////= Draw all histogram  =======================================================================
	for( int i=0; i<th2_size_; i++){
		if( TH2Info[i].output ){
			for( int j=0; j<SigMC_TotalNum; j++){
			//for( int j=0; j<1; j++){
				char xtitle[100], ytitle[100];
				////= For signal and title setting ====================================================
				sigH[i][j] = (TH2F*)sigf[j]->Get(TH2Info[i].name.c_str());
				sigH[i][j]->UseCurrentStyle();
				sigH[i][j]->RebinX(Other2Info[i].xrebin);
				sigH[i][j]->RebinY(Other2Info[i].yrebin);
				
				if( TH2Info[i].xunit.size()!=0 ){
					sprintf( xtitle, "%s [%s]", TH2Info[i].xtitle.c_str(),TH2Info[i].xunit.c_str());
				}else{
					sprintf( xtitle, "%s", TH2Info[i].xtitle.c_str());
				}
				if( TH2Info[i].yunit.size()!=0 ){
					sprintf( ytitle, "%s [%s]", TH2Info[i].ytitle.c_str(),TH2Info[i].yunit.c_str());
				}else{
					sprintf( ytitle, "%s", TH2Info[i].ytitle.c_str());
				}
				sigH[i][j]->SetXTitle(xtitle);
				sigH[i][j]->SetYTitle(ytitle);
				sigH[i][j]->GetXaxis()->SetRangeUser(Other2Info[i].SetXMin,Other2Info[i].SetXMax);
				sigH[i][j]->GetYaxis()->SetRangeUser(Other2Info[i].SetYMin,Other2Info[i].SetYMax);
				sigH[i][j]->GetZaxis()->SetRangeUser(Other2Info[i].SetZMin,Other2Info[i].SetZMax);
				
        			if( Other2Info[i].logZ ){ 
					c1->SetLogz(1); 
				} else { 
					c1->SetLogz(0);
				}
				sigH[i][j]->Draw();
				sigH[i][j]->Draw("COLZ");
				////= Save ============================================================
				string spath = SavePngPath+"/"+SigMC[j].name+"_2D_"+TH2Info[i].name+".png"; 
				c1->SaveAs(spath.c_str());
				cout<<"Save 2D Histogram \""<<TH2Info[i].name<<"\" for \""<<SigMC[j].LegTitle<<"\""<<endl;
			}	
		}
	}
}
