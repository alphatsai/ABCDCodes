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
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TGraphAsymmErrors.h"
#include "TEfficiency.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TROOT.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/interface/setTDRStyle.C"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/interface/missVSeff.C"
using namespace std;
void StackPlots( TFile* f1, vector<string> hist, vector<string> leg, vector<Color_t> color, string xtitle_, string ytitle_, string xunit, string savePath, bool ylog=0, int rebin=1){
	int Bins = 0;
	int x1 = 0;
	int x2 = 0;
	int size = hist.size();
	float binwidth = 0;
	char title[100], xtitle[100], ytitle[100];
	TH1F* h1[size];
	for(int i=0; i<size; i++){
		h1[i] = (TH1F*)f1->Get(hist[i].c_str());
		h1[i]->UseCurrentStyle();
		h1[i]->Rebin(rebin); 
		if( Bins != 0 ){ if( h1[i]->GetXaxis()->GetLast() != Bins ) { cout<<"Error: Exist different bin size( plot: "<<i<<")"<<endl; }}
		Bins = h1[i]->GetXaxis()->GetLast();
		binwidth = h1[i]->GetBinWidth(1);
		x1 = h1[i]->GetXaxis()->GetBinLowEdge(1);
		x2 = h1[i]->GetXaxis()->GetBinUpEdge(Bins);

		h1[i]->SetLineWidth(1);
		h1[i]->SetLineColor(color[i]);
		h1[i]->SetFillColor(color[i]);
	}

	sprintf(xtitle,"%s [%s]",xtitle_.c_str(),xunit.c_str());
	sprintf(ytitle,"%s / [%3.0f%s]",ytitle_.c_str(),binwidth,xunit.c_str());
	sprintf(title,";%s;%s",xtitle,ytitle);
	cout<<Bins<<" "<<x1<<" "<<x2<<endl;
	TH1F* hs_stack = new TH1F("hs_stack",title,Bins,x1,x2);
        THStack *hs = new THStack("hs","");

	TLegend* leg_ = new TLegend(0.65,0.65,0.85,0.85);
	TCanvas* c1 = new TCanvas("c1", "", 850, 700);
        c1->SetGridx();
        c1->SetGridy();
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	hs_stack->UseCurrentStyle();
	hs->SetHistogram(hs_stack);	
	for(int i=0; i<size; i++){
		hs->Add(h1[i]);
		leg_->AddEntry(h1[i],leg[i].c_str(),"f");
	}
        leg_->SetFillStyle(0);
        leg_->SetBorderSize(0);
        leg_->SetTextSize(0.042);
	if( ylog ) gPad->SetLogy();
	hs->SetMinimum(1);
	hs->SetMaximum(1e+13);
	hs->Draw();
	leg_->Draw();
	c1->SaveAs(savePath.c_str());
}

void missVSeffAna(){
	
	//// Load file info ////
	vector<string> SigPath1;
	SigPath1.push_back("/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/resurlt/root/mc/sig/ExtraSVFdR_BH1500_MatchDR05.root");
	SigPath1.push_back("/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/resurlt/root/mc/sig/ExtraSVFdR_BH500_MatchDR05.root");
	vector<string> SigPath2;
	SigPath2.push_back("/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/resurlt/root/mc/sig/ExtraSVFdR_BH1500_GMdR05dRbCA8.root");
	SigPath2.push_back("/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/resurlt/root/mc/sig/ExtraSVFdR_BH500_GMdR05dRbCA8.root");
	vector<string> SigPath3;
	SigPath3.push_back("/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/resurlt/root/mc/sig/ExtraSVFdR_BH1500_GMdR05dRbCA8_Hmass.root");
	SigPath3.push_back("/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/resurlt/root/mc/sig/ExtraSVFdR_BH500_GMdR05dRbCA8_Hmass.root");
/*	vector<string> SigPath3;
	SigPath3.push_back("/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/resurlt/root/mc/sig/ExtraSVFdR_BH1500_GMdR05dRbCA8_tight005.root");
	SigPath3.push_back("/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/resurlt/root/mc/sig/ExtraSVFdR_BH500_GMdR05dRbCA8_tight005.root");
*/	
	string BGPath = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/resurlt/root/mc/bg/ExtraSVFdR_QCD15-3000.root";

	//// Save pdf info ////
	vector<string> leg;
	leg.push_back("b' 1500(GeV)");
	leg.push_back("b' 500 (GeV)");
	string pdf1 = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/resurlt/pdf/mc/bg/ExtraSVFdR_missVSeff_old.pdf";
	string pdf2 = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/resurlt/pdf/mc/bg/ExtraSVFdR_missVSeff.pdf";
	string pdf3 = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/resurlt/pdf/mc/bg/ExtraSVFdR_missVSeff_Hmass.pdf";
	//string pdf3 = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/resurlt/pdf/mc/bg/ExtraSVFdR_missVSeff_tight005.pdf";

	setTDRStyle();

	///////// Star to Load TFile, TH1F /////////
	missVSeff(SigPath1,"GMdR5-CA8JetInfo.2bTag.EffCA8PDoubleBtag","Double b-Tag Eff.", leg,
		  BGPath,  "QCD-CA8JetInfo.Select.2bTagMissTag.2bTag", "Double b-Tag Mistag Rate",
		  pdf1);
	missVSeff(SigPath2,"GMdR5dRbCA8-CA8JetInfo.2bTag.EffCA8PDoubleBtag","Double b-Tag Eff.", leg,
		  BGPath,  "QCD-CA8JetInfo.Select.2bTagMissTag.2bTag", "Double b-Tag Mistag Rate",
		  pdf2);
	missVSeff(SigPath3,"GMdR5dRbCA8-CA8JetInfo.2bTag.EffCA8PDoubleBtag","Double b-Tag Eff.", leg,
		  BGPath,  "QCD-CA8JetInfo.Select.2bTagMissTag.2bTag", "Double b-Tag Mistag Rate",
		  pdf3);

	//// Stack //// 
	TFile* input = new TFile(BGPath.c_str());
	string stackpdf1 = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/resurlt/pdf/mc/bg/ExtraSVFdR_QCD15-3000_flavor_CA8Pt.pdf";
	string stackpdf2 = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/resurlt/pdf/mc/bg/ExtraSVFdR_QCD15-3000_flavor_Select_2bTag_CA8Pt.pdf";
	string stackpdf3 = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0712/resurlt/pdf/mc/bg/ExtraSVFdR_QCD15-3000_flavor_Select_CA8Pt.pdf";

	vector<Color_t> color;
	vector<string> stackleg;

	vector<string> hist1;
	hist1.push_back("QCD-CA8JetInfo.Pt.flavorN.Nomalize");	color.push_back(kOrange+5); stackleg.push_back("Not Matched");
	hist1.push_back("QCD-CA8JetInfo.Pt.flavorG.Nomalize");	color.push_back(kOrange+1); stackleg.push_back("Gluon flavor");
	hist1.push_back("QCD-CA8JetInfo.Pt.flavorL.Nomalize");	color.push_back(kSpring+9); stackleg.push_back("Light flavor");
	hist1.push_back("QCD-CA8JetInfo.Pt.flavorC.Nomalize");	color.push_back(kAzure+2); stackleg.push_back("c flavor");
	hist1.push_back("QCD-CA8JetInfo.Pt.flavorB.Nomalize");	color.push_back(kViolet+2); stackleg.push_back("b flavor");
	
	vector<string> hist2;
	hist2.push_back("QCD-2bTagCA8JetInfo.Select.Pt.flavorN.Nomalize");			
	hist2.push_back("QCD-2bTagCA8JetInfo.Select.Pt.flavorG.Nomalize");			
	hist2.push_back("QCD-2bTagCA8JetInfo.Select.Pt.flavorL.Nomalize");	
	hist2.push_back("QCD-2bTagCA8JetInfo.Select.Pt.flavorC.Nomalize");	
	hist2.push_back("QCD-2bTagCA8JetInfo.Select.Pt.flavorB.Nomalize");	

	vector<string> hist3;
	hist3.push_back("QCD-CA8JetInfo.Select.Pt.flavorN.Nomalize");			
	hist3.push_back("QCD-CA8JetInfo.Select.Pt.flavorG.Nomalize");			
	hist3.push_back("QCD-CA8JetInfo.Select.Pt.flavorL.Nomalize");	
	hist3.push_back("QCD-CA8JetInfo.Select.Pt.flavorC.Nomalize");	
	hist3.push_back("QCD-CA8JetInfo.Select.Pt.flavorB.Nomalize");	

	StackPlots( input, hist1, stackleg, color, "CA8 Pt", "Yields", "GeV/c", stackpdf1, 1, 50);
	StackPlots( input, hist2, stackleg, color, "CA8 Pt", "Yields", "GeV/c", stackpdf2, 1, 50);
	StackPlots( input, hist3, stackleg, color, "CA8 Pt", "Yields", "GeV/c", stackpdf3, 1, 50);
}
	
