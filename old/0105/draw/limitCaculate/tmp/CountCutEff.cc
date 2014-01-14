#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include "TFile.h"
#include "TH1F.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/0105/interface/sampleInfo.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/0105/interface/plotsInfo.h"
#define QCD_MeasureUnc 1.
#define TT_MeasureUnc 0.114

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

	string SigRootPath = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/0105/resurlt/root/tmp/mc/sig";
	string QCDRootPath = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/0105/resurlt/root/tmp/mc/bg";
	string TTRootPath  = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/0105/resurlt/root/tmp/mc/bg";
	string BosRootPath = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/0105/resurlt/root/tmp/mc/bg";

	double Sig_TotalYield[SigMC_TotalNum];
	double QCD_TotalYield = 0.;
	double TT_TotalYield = 0.;
	double Bos_TotalYield = 0.;

	double Bg_TotalYield = 0.;
	double Bg_DeltaYield = 0.;
	double Bg_MeasurementError = 0.;
	double Bg_MeasurementError_lnN = 0.; //lnN = 1+dY/Y


//	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
//	cout<<"/////////////////////== QCD Background MC ==//////////////////////"<<endl;
//	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	for(int i=0; i<QCDMC_TotalNum; i++){

		double scale = 1000*lumi*QCDMC[i].xsec/QCDMC[i].totalEvt;
		string path = QCDRootPath+"/"+QCDMC[i].name+".root";
		QCDf[i] = new TFile(path.c_str());
		h1_QCD[i] = (TH1F*)QCDf[i]->Get("EvtInfo.BpYields.BpSelect");
		h1_QCD[i] -> Scale(scale);
		QCD_TotalYield = QCD_TotalYield + h1_QCD[i]->GetBinContent(2);

	}

//	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
//	cout<<"/////////////////////== TT Background MC ==//////////////////////"<<endl;
//	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	for(int i=0; i<TTMC_TotalNum; i++){

		double scale = 1000*lumi*TTMC[i].xsec/TTMC[i].totalEvt;
		string path = TTRootPath+"/"+TTMC[i].name+".root";
		TTf[i] = new TFile(path.c_str());
		h1_TT[i] = (TH1F*)TTf[i]->Get("EvtInfo.BpYields.BpSelect");
		h1_TT[i] -> Scale(scale);
		TT_TotalYield 	= TT_TotalYield + h1_TT[i]->GetBinContent(2);
	}

//	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
//	cout<<"/////////////////////== Bos Background MC ==//////////////////////"<<endl;
//	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	for(int i=0; i<BosMC_TotalNum; i++){

		double scale = 1000*lumi*BosMC[i].xsec/BosMC[i].totalEvt;
		string path = BosRootPath+"/"+BosMC[i].name+".root";
		Bosf[i] = new TFile(path.c_str());
		h1_Bos[i] = (TH1F*)Bosf[i]->Get("EvtInfo.BpYields.BpSelect");
		h1_Bos[i] -> Scale(scale);
		Bos_TotalYield = Bos_TotalYield + h1_Bos[i]->GetBinContent(2);
	}

	Bg_TotalYield = QCD_TotalYield + TT_TotalYield + Bos_TotalYield;
	Bg_DeltaYield = QCD_TotalYield*QCD_MeasureUnc + TT_TotalYield*TT_MeasureUnc;
	Bg_MeasurementError = Bg_DeltaYield/Bg_TotalYield;
	Bg_MeasurementError_lnN = 1+Bg_MeasurementError;

//	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
//	cout<<"/////////////////////////== SIGNAL MC ==//////////////////////////"<<endl;
//	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	for(int i=0; i<SigMC_TotalNum; i++){

		double scale = 1000*lumi*SigMC[i].xsec/SigMC[i].totalEvt;
		string path = SigRootPath+"/"+SigMC[i].name+".root";
		Sigf[i] = new TFile(path.c_str());
		h1_Sig[i] = (TH1F*)Sigf[i]->Get("EvtInfo.BpYields.BpSelect");	
		h1_Sig[i] -> Scale(scale);
		Sig_TotalYield[i] =  h1_Sig[i]->GetBinContent(2);

		cout<<"#//////////////////////////////////////////////////////////////////"<<endl;
		cout<<"#/////////////////////////== "<<SigMC[i].name<<" ==//////////////////////////"<<endl;
		cout<<"#//////////////////////////////////////////////////////////////////"<<endl;
		cout<<"imax 1  number of channels"<<endl;
		cout<<"jmax 1  number of backgrounds"<<endl;
		cout<<"kmax 2  number of nuisance parameters (sources of systematical uncertainties)"<<endl;
		cout<<"------------"<<endl;
		cout<<"# we have just one channel, in which we observe 0 events"<<endl;
		cout<<"bin 1"<<endl;
		cout<<"observation 0"<<endl;
		cout<<"------------"<<endl;
		cout<<"# now we list the expected events for signal and all backgrounds in that bin"<<endl;
		cout<<"# the second 'process' line must have a positive number for backgrounds, and 0 for signal"<<endl;
		cout<<"# then we list the independent sources of uncertainties, and give their effect (syst. error)"<<endl;
		cout<<"# on each process and bin"<<endl;
		cout<<"bin\t\t1\t1"<<endl;
		cout<<"process\t\t"<<SigMC[i].name<<"\tBg"<<endl;
		cout<<"process\t\t0\t1"<<endl;
		cout<<"rate\t\t"<<Sig_TotalYield[i]<<"\t"<<Bg_TotalYield<<endl;
		cout<<"------------"<<endl;
		cout<<"lumi\tlnN\t1.044\t1.044"<<endl;
		cout<<"XSecEr\tlnN\t-\t"<<Bg_MeasurementError_lnN<<endl;
		cout<<endl;
		cout<<endl;

	}

//	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
//	cout<<"/////////////////////== Result for Sig & BG ==////////////////////"<<endl;
//	cout<<"//////////////////////////////////////////////////////////////////"<<endl;



}
