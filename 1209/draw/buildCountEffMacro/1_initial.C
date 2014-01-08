#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include "TFile.h"
#include "TH1F.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/1209/interface/sampleInfo.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/1209/interface/plotsInfo.h"
using namespace std;
void CountCutEff(){

	////= Correct histogram Info.  =======================================================================
	TFile* Sigf[SigMC_TotalNum];
	TFile* QCDf[QCDMC_TotalNum];	
	TFile* TTf[TTMC_TotalNum];  	
	TFile* Bosf[BosMC_TotalNum];

	TH1F* h1_Sig[SigMC_TotalNum];
	TH1F* h1_QCD[QCDMC_TotalNum];
	TH1F* h1_TT[TTMC_TotalNum];
	TH1F* h1_Bos[BosMC_TotalNum];

	TH1F* h12_Sig[SigMC_TotalNum];
	TH1F* h12_QCD[QCDMC_TotalNum];
	TH1F* h12_TT[TTMC_TotalNum];
	TH1F* h12_Bos[BosMC_TotalNum];

	TH1F* h123_Sig[SigMC_TotalNum];
	TH1F* h123_QCD[QCDMC_TotalNum];
	TH1F* h123_TT[TTMC_TotalNum];
	TH1F* h123_Bos[BosMC_TotalNum];

	TH1F* h1234_Sig[SigMC_TotalNum];
	TH1F* h1234_QCD[QCDMC_TotalNum];
	TH1F* h1234_TT[TTMC_TotalNum];
	TH1F* h1234_Bos[BosMC_TotalNum];

	TH1F* h12345_Sig[SigMC_TotalNum];
	TH1F* h12345_QCD[QCDMC_TotalNum];
	TH1F* h12345_TT[TTMC_TotalNum];
	TH1F* h12345_Bos[BosMC_TotalNum];

//	TH1F* h123456_Sig[SigMC_TotalNum];
//	TH1F* h123456_QCD[QCDMC_TotalNum];
//	TH1F* h123456_TT[TTMC_TotalNum];
//	TH1F* h123456_Bos[BosMC_TotalNum];
	
	string SigRootPath = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/1209/resurlt/root/mc/sig";
	string QCDRootPath = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/1209/resurlt/root/mc/bg";
	string TTRootPath  = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/1209/resurlt/root/mc/bg";
	string BosRootPath = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/1209/resurlt/root/mc/bg";

	double Bg_TotalEvt = 0.;
	double Bg_1_RestNum = 0.;
	double Bg_12_RestNum = 0.;
	double Bg_123_RestNum = 0.;
	double Bg_1234_RestNum = 0.; 
	double Bg_12345_RestNum = 0.; 
//	double Bg_123456_RestNum = 0.;

	double Bg_1_Eff = 0.;
	double Bg_12_Eff = 0.;
	double Bg_123_Eff = 0.;
	double Bg_1234_Eff = 0.;
	double Bg_12345_Eff = 0.;
//	double Bg_123456_Eff = 0.;
	double Bg_Total_Eff = 0.;


