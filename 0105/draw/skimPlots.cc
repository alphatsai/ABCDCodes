#include <fstream>
#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <cstdlib>
#include <vector>
#include "TChain.h"
#include "TPad.h"
#include "TMath.h"
#include "TFile.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TLorentzVector.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/0105/interface/sampleInfo.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/0105/interface/setTDRStyle.C"
using namespace std;
const int h_size=9;
struct hInfo{
	bool ylog;
	string name;
	string unit;
	string xtitle;
	string ytitle;
	int rebin;
};

struct hInfo hs[h_size] = {
	{1, "EvtInfo.CutFlow",			"",	 	"Cut Flow", 	"Yields",	1},
	{1, "AK5JetInfo.Num", 			"",		"N(AK5)",	"Yields",	1},
	{0, "AK5JetInfo.Pt", 			"GeV/c",	"pT(AK5)",	"Yields",	20},
	{1, "AK5JetInfo.CSV", 			"",		"CSV-dis.",	"Yields",	5},
	{1, "bJetInfo.Num", 			"",		"N(bJet)",	"Yields",	1},
	{0, "bJetInfo.Pt", 			"GeV/c",	"pT(bJet)",	"Yields",	20},
	{1, "bJetInfo.CSV", 			"",		"CSV-dis.",	"Yields",	5},
	{1, "bJetInfo.Num.Veto", 			"",		"N(bJet), bJetVeto", "Yields", 		1},
	{1, "bJetInfo.NumMatchToCA8.Veto",	"",		"N(bJet is CA8), bJetVeto", "Yields",	1},
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////// Analysis start //////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void skimPlots(){
	setTDRStyle();
	string Load_bg = "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/0105/result/root/mc/bg";
	string Load_data = "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/0105/result/root/data";
	string savePath = "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/0105/result/png/abcd";

	vector<string> BgPath;
	vector<double> BgXLumi;
	for( int i=0; i<QCDMC_TotalNum; i++){   //FullPart
		string path = Load_bg+"/"+QCDMC[i].name+".root";
		double xLumi = 1000*lumi*QCDMC[i].xsec;
		BgPath.push_back(path);
		BgXLumi.push_back(xLumi);
	}
	for( int i=0; i<TTMC_TotalNum; i++){   //FullPart
		string path = Load_bg+"/"+TTMC[i].name+".root";
		double xLumi = 1000*lumi*TTMC[i].xsec;
		BgPath.push_back(path);
		BgXLumi.push_back(xLumi);
	}
	const int bg_size = BgPath.size();

	TFile* f_bg[bg_size];
	TFile* f_data[Data_TotalNum];

	TH1D* h_data[h_size][Data_TotalNum];
	TH1D* h_datas[h_size];
	TH1D* h_bg[h_size][bg_size];
	TH1D* h_bgs[h_size];
	TH1D* h_bgsw[h_size];

	for( int i=0; i<Data_TotalNum; i++){   //FullPart
		string path = Load_data+"/"+Data[i].name+".root";
		f_data[i] = new TFile(path.c_str());
		for( int j=0; j<h_size; j++){
			string name="BprimebH/"+hs[j].name;
			h_data[j][i]=(TH1D*)f_data[i]->Get(name.c_str());
			h_data[j][i]->Sumw2();
			h_data[j][i]->Rebin(hs[j].rebin);
			if( i==0 ){
				h_datas[j]=(TH1D*)h_data[j][i]->Clone("clone_data");
			}else{
				h_datas[j]->Add(h_data[j][i]);
			}
		}
	}
	for( int i=0; i<bg_size; i++){
		f_bg[i] = new TFile(BgPath[i].c_str());	 	
		TH1D* h_evtNum = (TH1D*)f_bg[i]->Get("BprimebH/EvtInfo.Entries");
		double totalEvt = h_evtNum->GetEntries();
		for( int j=0; j<h_size; j++){
			string name="BprimebH/"+hs[j].name;
			h_bg[j][i]=(TH1D*)f_bg[i]->Get(name.c_str());
			h_bg[j][i]->Rebin(hs[j].rebin);
			if( i==0 ){
				h_bgs[j]=(TH1D*)h_bg[j][i]->Clone("clone_mc");
				h_bgs[j]->Scale(BgXLumi[i]/totalEvt);
			}else{
				h_bgs[j]->Add(h_bg[j][i],BgXLumi[i]/totalEvt);
			}
			
			h_bg[j][i]->Sumw2();
			if( i==0 ){
				h_bgsw[j]=(TH1D*)h_bg[j][i]->Clone("clone_mcw");
				h_bgsw[j]->Scale(BgXLumi[i]/totalEvt);
			}else{
				h_bgsw[j]->Add(h_bg[j][i],BgXLumi[i]/totalEvt);
			}
		} 
	}

	/////////// Draw ////////////////////
	TCanvas* c1 = new TCanvas("c1", "", 850, 700);
	//c1->Divide(1,2);
	for( int i=0; i<h_size; i++){
		char xtitle[100], ytitle[100];
                double binwidth = h_bgs[i]->GetBinWidth(1);
                if( hs[i].unit.size()!=0 ){
			sprintf( xtitle, "%s [%s]", hs[i].xtitle.c_str(),hs[i].unit.c_str());
                        if (binwidth<1){
				sprintf( ytitle, "%s / [%0.2f%s]", hs[i].ytitle.c_str(),binwidth,hs[i].unit.c_str());
			}else{
                                sprintf( ytitle, "%s / [%2.1f%s]", hs[i].ytitle.c_str(),binwidth,hs[i].unit.c_str());
                        }
                }else{
			sprintf( xtitle, "%s", hs[i].xtitle.c_str());
                        if (binwidth<1){
				sprintf( ytitle, "%s / [%0.2f]", hs[i].ytitle.c_str(),binwidth);
			}else{
                                sprintf( ytitle, "%s / [%2.1f]", hs[i].ytitle.c_str(),binwidth);
                        }
			//sprintf( ytitle, "%s", hs[i].ytitle.c_str());
                }
                h_bgsw[i]->SetXTitle(xtitle);
                h_bgs[i]->SetYTitle(ytitle);

		double yMaximum;
		if( h_datas[i]->GetMaximum()>h_bgs[i]->GetMaximum()){
			yMaximum = h_datas[i]->GetMaximum();
		}else{
			yMaximum = h_bgs[i]->GetMaximum();
		}
		//h_bgs[i]->SetMaximum(yMaximum+yMaximum/10);

		TLegend* lg = new TLegend(0.72,0.75,0.92,0.90);
		lg->SetBorderSize(0);
		lg->SetFillColor(0);
		lg->SetFillStyle(0);
		lg->SetNColumns(1);
		lg->SetTextSize(0.04);
		lg->SetTextSizePixels(25);	

		TH1D* dByM=(TH1D*)h_datas[i]->Clone("clone");
		
		//c1->cd(1);
		TPad *pad1 = new TPad("pad1","pad1",0,0.147,1,1);
		pad1->SetBottomMargin(0.05);
		pad1->SetTopMargin(0.06);
 	 	pad1->Draw();
  		pad1->cd();

		if( hs[i].ylog ){ 
			h_bgs[i]->SetMaximum(yMaximum*10);
			h_bgs[i]->SetMinimum(1);
			pad1->SetLogy(1);
		}else{
			h_bgs[i]->SetMaximum(yMaximum+yMaximum/10);
			pad1->SetLogy(0);
		}
		
			
		h_datas[i]->UseCurrentStyle();
		h_datas[i]->SetLineColor(1); 
		h_datas[i]->SetLineWidth(2); 
		h_datas[i]->SetMarkerStyle(8); 
		h_bgs[i]->UseCurrentStyle();
		h_bgs[i]->SetFillColor(46);
		h_bgs[i]->SetLineColor(0); 
		h_bgsw[i]->UseCurrentStyle();
		h_bgsw[i]->SetFillStyle(3244);	
		h_bgsw[i]->SetFillColor(9);	
		h_bgsw[i]->SetLineColor(0);	
		//h_bgs[i]->SetLineWidth(0); 
	
		lg->AddEntry(h_bgs[i],"Background","f");	
		lg->AddEntry(h_bgsw[i],"Error", "f");	
		lg->AddEntry(h_datas[i],"Data","pl");	
	
		h_bgs[i]->Draw("HIST");	
		h_bgsw[i]->Draw("E2 SAME");	
		h_datas[i]->Draw("ep SAME");
		lg->Draw("SAME");
	
		//c1->cd(2);
		c1->cd();
		TPad *pad2 = new TPad("pad2","pad2",0,0,1,0.19);
		pad2->SetTopMargin(0);
		pad2->SetBottomMargin(0.4);
		pad2->SetGrid();
		pad2->Draw();
		pad2->cd();
		dByM->Divide(h_bgsw[i]);
                dByM->SetXTitle(xtitle);
                dByM->SetYTitle("Data/MC");
    		dByM->GetYaxis()->SetLabelSize(0.055);
    		dByM->GetYaxis()->SetTitleOffset(1.2);
    		dByM->GetYaxis()->SetTitleSize(0.055);
    dByM->GetXaxis()->SetLabelSize(0.055);
    dByM->GetYaxis()->SetTitle("Data/MC");
    dByM->GetYaxis()->SetTitleOffset(0.23);
    dByM->GetYaxis()->SetTitleSize(0.22);
    dByM->GetYaxis()->SetRangeUser(0.0,2);
    dByM->GetXaxis()->SetTitleOffset(0.8);
    dByM->GetXaxis()->SetTitleSize(0.18);
    dByM->GetXaxis()->SetLabelSize(0.2);
    dByM->GetYaxis()->SetLabelSize(0.2);
    dByM->GetXaxis()->SetNdivisions(510);
    dByM->GetYaxis()->SetNdivisions(502);
		//gStyle->SetTitleSize(0.08,"XYZ");
		//dByM->UseCurrentStyle();
		dByM->GetYaxis()->SetRangeUser(0,2);
		dByM->SetLineColor(1); 
		dByM->SetLineWidth(2); 
		dByM->SetMarkerStyle(8); 
		dByM->Draw("ep");
		
		string save=savePath+"/skimPlots_"+hs[i].name+".png";	
		c1->SaveAs(save.c_str());
		c1->cd();
	}	
}
