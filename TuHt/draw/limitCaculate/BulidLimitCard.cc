#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include "TFile.h"
#include "TH1F.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/TuHt/interface/sampleInfo.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/TuHt/interface/plotsInfo.h"
#define Lumi_MeasureUnc 1.026
#define QCD_MeasureUnc 0.30 
#define TT_MeasureUnc 0.0389

using namespace std;
void BulidLimitCard(){

	////= Correct histogram Info.  =======================================================================
	TFile* Sigf[SigMC_TotalNum];
	TFile* QCDf[QCDMC_TotalNum];	
	TFile* TTf[TTMC_TotalNum];  	
	TFile* Bosf[BosMC_TotalNum];

	TH1F* h1_Sig[SigMC_TotalNum];
	TH1F* h1_QCD[QCDMC_TotalNum];
	TH1F* h1_TT[TTMC_TotalNum];
	TH1F* h1_Bos[BosMC_TotalNum];
	
	fstream limitCard;

	string SigRootPath = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/TuHt/resurlt/root/mc/sig";
	string QCDRootPath = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/TuHt/resurlt/root/mc/bg";
	string TTRootPath  = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/TuHt/resurlt/root/mc/bg";
	string BosRootPath = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/TuHt/resurlt/root/mc/bg";

	double Sig_TotalYield[SigMC_TotalNum];
	double QCD_TotalYield = 0.;
	double TT_TotalYield = 0.;
	double Bos_TotalYield = 0.;

	double QCD_Entries[QCDMC_TotalNum];
	double TT_Entries[TTMC_TotalNum];
	double Bos_Entries[BosMC_TotalNum];

	double QCD_Weight[QCDMC_TotalNum];
	double TT_Weight[TTMC_TotalNum];
	double Bos_Weight[BosMC_TotalNum];

	double Bg_TotalYield = 0.;
	double Bg_DeltaYield = 0.;
	double Bg_MeasurementError = 0.;
	double Bg_MeasurementError_lnN = 0.; //lnN = 1+dY/Y
	double Bg_StatisticError_sqr = 0.;
	double Bg_StatisticError = 0.;
	double Bg_StatisticError_lnN = 0.; //lnN = 1+dY/Y


//	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
//	cout<<"/////////////////////== QCD Background MC ==//////////////////////"<<endl;
//	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	for(int i=0; i<QCDMC_TotalNum; i++){

		double scale = 1000*lumi*QCDMC[i].xsec/QCDMC[i].totalEvt;
		QCD_Weight[i] = scale;
		string path = QCDRootPath+"/"+QCDMC[i].name+".root";
		QCDf[i] = new TFile(path.c_str());
	//	h1_QCD[i] = (TH1F*)QCDf[i]->Get("EvtInfo.BpYields.BpSelect");
	//	QCD_Entries[i]= h1_QCD[i]->GetEntries();
		h1_QCD[i] = (TH1F*)QCDf[i]->Get("EvtInfo.NumRestEvt.12345");
		QCD_Entries[i]= h1_QCD[i]->GetBinContent(2);
		Bg_StatisticError_sqr = Bg_StatisticError_sqr + QCD_Entries[i]*QCD_Weight[i]*QCD_Weight[i];
		h1_QCD[i] -> Scale(scale);
		QCD_TotalYield = QCD_TotalYield + h1_QCD[i]->GetBinContent(2);

	}

//	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
//	cout<<"/////////////////////== TT Background MC ==//////////////////////"<<endl;
//	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	for(int i=0; i<TTMC_TotalNum; i++){

		double scale = 1000*lumi*TTMC[i].xsec/TTMC[i].totalEvt;
		TT_Weight[i] = scale;
		string path = TTRootPath+"/"+TTMC[i].name+".root";
		TTf[i] = new TFile(path.c_str());
//		h1_TT[i] = (TH1F*)TTf[i]->Get("EvtInfo.BpYields.BpSelect");
//		TT_Entries[i]= h1_TT[i]->GetEntries();
		h1_TT[i] = (TH1F*)TTf[i]->Get("EvtInfo.NumRestEvt.12345");
		TT_Entries[i]= h1_TT[i]->GetBinContent(2);
		Bg_StatisticError_sqr = Bg_StatisticError_sqr + TT_Entries[i]*TT_Weight[i]*TT_Weight[i];
		h1_TT[i] -> Scale(scale);
		TT_TotalYield 	= TT_TotalYield + h1_TT[i]->GetBinContent(2);
	}

//	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
//	cout<<"/////////////////////== Bos Background MC ==//////////////////////"<<endl;
//	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	for(int i=0; i<BosMC_TotalNum; i++){

		double scale = 1000*lumi*BosMC[i].xsec/BosMC[i].totalEvt;
		Bos_Weight[i] = scale;
		string path = BosRootPath+"/"+BosMC[i].name+".root";
		Bosf[i] = new TFile(path.c_str());
//		h1_Bos[i] = (TH1F*)Bosf[i]->Get("EvtInfo.BpYields.BpSelect");
//		Bos_Entries[i]= h1_Bos[i]->GetEntries();
		h1_Bos[i] = (TH1F*)Bosf[i]->Get("EvtInfo.NumRestEvt.12345");
		Bos_Entries[i]= h1_Bos[i]->GetBinContent(2);
		Bg_StatisticError_sqr = Bg_StatisticError_sqr + Bos_Entries[i]*Bos_Weight[i]*Bos_Weight[i];
		h1_Bos[i] -> Scale(scale);
		Bos_TotalYield = Bos_TotalYield + h1_Bos[i]->GetBinContent(2);
	}

	Bg_TotalYield = QCD_TotalYield + TT_TotalYield + Bos_TotalYield;
	Bg_DeltaYield = QCD_TotalYield*QCD_MeasureUnc + TT_TotalYield*TT_MeasureUnc;
	Bg_MeasurementError = Bg_DeltaYield/Bg_TotalYield;
	Bg_MeasurementError_lnN = 1+Bg_MeasurementError;

	Bg_StatisticError = sqrt(Bg_StatisticError_sqr)/Bg_TotalYield;
	Bg_StatisticError_lnN = 1+Bg_StatisticError;

//	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
//	cout<<"/////////////////////////== SIGNAL MC ==//////////////////////////"<<endl;
//	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	for(int i=0; i<SigMC_TotalNum; i++){
		
		string cardSave = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/TuHt/resurlt/txt/limitCard/limitCard_" + SigMC[i].name + ".txt";		
		limitCard.open(cardSave.c_str(),ios_base::out);  

		double scale = 1000*lumi*SigMC[i].xsec/SigMC[i].totalEvt;
		string path = SigRootPath+"/"+SigMC[i].name+".root";
		Sigf[i] = new TFile(path.c_str());
		//h1_Sig[i] = (TH1F*)Sigf[i]->Get("EvtInfo.BpYields.BpSelect");	
		h1_Sig[i] = (TH1F*)Sigf[i]->Get("EvtInfo.NumRestEvt.12345");	
		h1_Sig[i] -> Scale(scale);
		Sig_TotalYield[i] =  h1_Sig[i]->GetBinContent(2);

		limitCard<<"#//////////////////////////////////////////////////////////////////"<<endl;
		limitCard<<"#/////////////////////////== "<<SigMC[i].name<<" ==//////////////////////////"<<endl;
		limitCard<<"#//////////////////////////////////////////////////////////////////"<<endl;
		limitCard<<"imax 1  number of channels"<<endl;
		limitCard<<"jmax 1  number of backgrounds"<<endl;
		limitCard<<"kmax 3  number of nuisance parameters (sources of systematical uncertainties)"<<endl;
		limitCard<<"------------"<<endl;
		limitCard<<"# we have just one channel, in which we observe 0 events"<<endl;
		limitCard<<"bin 1"<<endl;
		limitCard<<"observation "<<int(Bg_TotalYield)<<endl;
		limitCard<<"------------"<<endl;
		limitCard<<"# now we list the expected events for signal and all backgrounds in that bin"<<endl;
		limitCard<<"# the second 'process' line must have a positive number for backgrounds, and 0 for signal"<<endl;
		limitCard<<"# then we list the independent sources of uncertainties, and give their effect (syst. error)"<<endl;
		limitCard<<"# on each process and bin"<<endl;
		limitCard<<"bin\t\t1\t1"<<endl;
		limitCard<<"process\t\t"<<SigMC[i].name<<"\tBg"<<endl;
		limitCard<<"process\t\t0\t1"<<endl;
		limitCard<<"rate\t\t"<<Sig_TotalYield[i]<<"\t"<<Bg_TotalYield<<endl;
		limitCard<<"------------"<<endl;
		limitCard<<"lumi\tlnN\t"<<Lumi_MeasureUnc<<"\t"<<Lumi_MeasureUnc<<""<<endl;
		limitCard<<"BgXSEr\tlnN\t-\t"<<Bg_MeasurementError_lnN<<endl;
		limitCard<<"BgStEr\tlnN\t-\t"<<Bg_StatisticError_lnN<<endl;
		limitCard.close();
		
		cout<<"#//////////////////////////////////////////////////////////////////"<<endl;
		cout<<"#/////////////////////////== "<<SigMC[i].name<<" ==//////////////////////////"<<endl;
		cout<<"#//////////////////////////////////////////////////////////////////"<<endl;
		cout<<"imax 1  number of channels"<<endl;
		cout<<"jmax 1  number of backgrounds"<<endl;
		cout<<"kmax 3  number of nuisance parameters (sources of systematical uncertainties)"<<endl;
		cout<<"------------"<<endl;
		cout<<"# we have just one channel, in which we observe 0 events"<<endl;
		cout<<"bin 1"<<endl;
		cout<<"observation "<<int(Bg_TotalYield)<<endl;
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
		cout<<"lumi\tlnN\t"<<Lumi_MeasureUnc<<"\t"<<Lumi_MeasureUnc<<""<<endl;
		cout<<"BgXSEr\tlnN\t-\t"<<Bg_MeasurementError_lnN<<endl;
		cout<<"BgStEr\tlnN\t-\t"<<Bg_StatisticError_lnN<<endl;
		cout<<endl;
		cout<<endl;

	}

//	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
//	cout<<"/////////////////////== Result for Sig & BG ==////////////////////"<<endl;
//	cout<<"//////////////////////////////////////////////////////////////////"<<endl;



}
