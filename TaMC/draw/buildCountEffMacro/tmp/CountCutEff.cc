#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include "TFile.h"
#include "TH1F.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/TaMC/interface/sampleInfo.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/TaMC/interface/plotsInfo.h"
using namespace std;
void CountCutEff(){

	////= Correct histogram Info.  =======================================================================
	TFile* sigf[SigMC_TotalNum];
	TFile* QCDf[QCDMC_TotalNum];	
	TFile* TTf[TTMC_TotalNum];  	
	TFile* Bosf[BosMC_TotalNum];

	TH1F* Ht_sig[SigMC_TotalNum], *Ht_QCD[QCDMC_TotalNum], *Ht_TT[TTMC_TotalNum], *Ht_Bos[BosMC_TotalNum];
	TH1F* HtGbAK5_sig[SigMC_TotalNum], *HtGbAK5_QCD[QCDMC_TotalNum], *HtGbAK5_TT[TTMC_TotalNum], *HtGbAK5_Bos[BosMC_TotalNum];
	TH1F* HtGbAK5G2bCA8_sig[SigMC_TotalNum], *HtGbAK5G2bCA8_QCD[QCDMC_TotalNum], *HtGbAK5G2bCA8_TT[TTMC_TotalNum], *HtGbAK5G2bCA8_Bos[BosMC_TotalNum];
	TH1F* HtGbAK5G2bCA8dR_sig[SigMC_TotalNum], *HtGbAK5G2bCA8dR_QCD[QCDMC_TotalNum], *HtGbAK5G2bCA8dR_TT[TTMC_TotalNum], *HtGbAK5G2bCA8dR_Bos[BosMC_TotalNum];
	
	string SigRootPath = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/TaMC/resurlt/root/mc/sig";
	string BgRootPath  = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/TaMC/resurlt/root/mc/bg";

	double Bg_TotalEvt = 0.;
	double Bg_Ht_RestNum = 0.;
	double Bg_HtGbAK5_RestNum = 0.;
	double Bg_HtGbAK5G2bCA8_RestNum = 0.; 
	double Bg_HtGbAK5G2bCA8dR_RestNum = 0.;
	double Bg_Ht_Eff = 0.;
	double Bg_HtGbAK5_Eff = 0.;
	double Bg_HtGbAK5G2bCA8_Eff = 0.;
	double Bg_HtGbAK5G2bCA8dR_Eff = 0.;
	double Bg_Total_Eff = 0.;

	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	cout<<"/////////////////////== QCD Background MC ==//////////////////////"<<endl;
	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	for(int i=0; i<QCDMC_TotalNum; i++){
		double Ht_RestNum;
		double HtGbAK5_RestNum;
		double HtGbAK5G2bCA8_RestNum;
		double HtGbAK5G2bCA8dR_RestNum;
		double Ht_Eff;
		double HtGbAK5_Eff;
		double HtGbAK5G2bCA8_Eff;
		double HtGbAK5G2bCA8dR_Eff;
		double Total_Eff;

		double scale = 1000*lumi*QCDMC[i].xsec/QCDMC[i].totalEvt;
		string path = BgRootPath+"/"+QCDMC[i].name+".root";
		QCDf[i] = new TFile(path.c_str());
		Ht_QCD[i]		=(TH1F*)QCDf[i]->Get("EvtInfo.NumRestEvt.Ht");			Ht_QCD[i]->Scale(scale);
		HtGbAK5_QCD[i]		=(TH1F*)QCDf[i]->Get("EvtInfo.NumRestEvt.Ht.GbAK5");		HtGbAK5_QCD[i]->Scale(scale);
		HtGbAK5G2bCA8_QCD[i]	=(TH1F*)QCDf[i]->Get("EvtInfo.NumRestEvt.Ht.GbAK5.G2bCA8");	HtGbAK5G2bCA8_QCD[i]->Scale(scale);
		HtGbAK5G2bCA8dR_QCD[i]	=(TH1F*)QCDf[i]->Get("EvtInfo.NumRestEvt.Ht.GbAK5.G2bCA8.dR");	HtGbAK5G2bCA8dR_QCD[i]->Scale(scale);
		
		Ht_RestNum 		= Ht_QCD[i]->GetBinContent(2);
		HtGbAK5_RestNum 	= HtGbAK5_QCD[i]->GetBinContent(2);
		HtGbAK5G2bCA8_RestNum 	= HtGbAK5G2bCA8_QCD[i]->GetBinContent(2);
		HtGbAK5G2bCA8dR_RestNum = HtGbAK5G2bCA8dR_QCD[i]->GetBinContent(2);

		Ht_Eff		    	= Ht_RestNum/(QCDMC[i].totalEvt*scale);
		HtGbAK5_Eff 	    	= HtGbAK5_RestNum/Ht_RestNum;
		HtGbAK5G2bCA8_Eff   	= HtGbAK5G2bCA8_RestNum/HtGbAK5_RestNum;
		HtGbAK5G2bCA8dR_Eff 	= HtGbAK5G2bCA8dR_RestNum/HtGbAK5G2bCA8_RestNum;
		Total_Eff		= HtGbAK5G2bCA8dR_RestNum/(QCDMC[i].totalEvt*scale);

		cout<<"============= "<<QCDMC[i].name<<" =============="<<endl;		
		cout<<"Selection Cut\t\t"	<<"Efficiency"		<<endl;
		cout<<"Ht>1000\t\t\t"		<<Ht_Eff		<<endl;
		cout<<"Good CSVM AK5>=3\t"	<<HtGbAK5_Eff		<<endl;
		cout<<"Good 2b CA8>=1\t\t"	<<HtGbAK5G2bCA8_Eff	<<endl;
		cout<<"dR(CA8,AK5)>0.8\t\t"	<<HtGbAK5G2bCA8dR_Eff	<<endl;
		cout<<"Total\t\t\t"		<<Total_Eff		<<endl;
		cout<<endl;

		Bg_TotalEvt 			= Bg_TotalEvt			+ (QCDMC[i].totalEvt*scale);
		Bg_Ht_RestNum 			= Bg_Ht_RestNum			+ Ht_RestNum;
		Bg_HtGbAK5_RestNum 		= Bg_HtGbAK5_RestNum		+ HtGbAK5_RestNum;
		Bg_HtGbAK5G2bCA8_RestNum 	= Bg_HtGbAK5G2bCA8_RestNum	+ HtGbAK5G2bCA8_RestNum; 
		Bg_HtGbAK5G2bCA8dR_RestNum 	= Bg_HtGbAK5G2bCA8dR_RestNum	+ HtGbAK5G2bCA8dR_RestNum;
	}

	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	cout<<"/////////////////////== TT Background MC ==//////////////////////"<<endl;
	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	for(int i=0; i<TTMC_TotalNum; i++){
		double Ht_RestNum;
		double HtGbAK5_RestNum;
		double HtGbAK5G2bCA8_RestNum;
		double HtGbAK5G2bCA8dR_RestNum;
		double Ht_Eff;
		double HtGbAK5_Eff;
		double HtGbAK5G2bCA8_Eff;
		double HtGbAK5G2bCA8dR_Eff;
		double Total_Eff;

		double scale = 1000*lumi*TTMC[i].xsec/TTMC[i].totalEvt;
		string path = BgRootPath+"/"+TTMC[i].name+".root";
		TTf[i] = new TFile(path.c_str());
		Ht_TT[i]		=(TH1F*)TTf[i]->Get("EvtInfo.NumRestEvt.Ht");			Ht_TT[i]->Scale(scale);
		HtGbAK5_TT[i]		=(TH1F*)TTf[i]->Get("EvtInfo.NumRestEvt.Ht.GbAK5");		HtGbAK5_TT[i]->Scale(scale);
		HtGbAK5G2bCA8_TT[i]	=(TH1F*)TTf[i]->Get("EvtInfo.NumRestEvt.Ht.GbAK5.G2bCA8");	HtGbAK5G2bCA8_TT[i]->Scale(scale);
		HtGbAK5G2bCA8dR_TT[i]	=(TH1F*)TTf[i]->Get("EvtInfo.NumRestEvt.Ht.GbAK5.G2bCA8.dR");	HtGbAK5G2bCA8dR_TT[i]->Scale(scale);
		
		Ht_RestNum 		= Ht_TT[i]->GetBinContent(2);
		HtGbAK5_RestNum 	= HtGbAK5_TT[i]->GetBinContent(2);
		HtGbAK5G2bCA8_RestNum 	= HtGbAK5G2bCA8_TT[i]->GetBinContent(2);
		HtGbAK5G2bCA8dR_RestNum = HtGbAK5G2bCA8dR_TT[i]->GetBinContent(2);

		Ht_Eff		    	= Ht_RestNum/(TTMC[i].totalEvt*scale);
		HtGbAK5_Eff 	    	= HtGbAK5_RestNum/Ht_RestNum;
		HtGbAK5G2bCA8_Eff   	= HtGbAK5G2bCA8_RestNum/HtGbAK5_RestNum;
		HtGbAK5G2bCA8dR_Eff 	= HtGbAK5G2bCA8dR_RestNum/HtGbAK5G2bCA8_RestNum;
		Total_Eff		= HtGbAK5G2bCA8dR_RestNum/(TTMC[i].totalEvt*scale);

		cout<<"============= "<<TTMC[i].name<<" =============="<<endl;		
		cout<<"Selection Cut\t\t"	<<"Efficiency"		<<endl;
		cout<<"Ht>1000\t\t\t"		<<Ht_Eff		<<endl;
		cout<<"Good CSVM AK5>=3\t"	<<HtGbAK5_Eff		<<endl;
		cout<<"Good 2b CA8>=1\t\t"	<<HtGbAK5G2bCA8_Eff	<<endl;
		cout<<"dR(CA8,AK5)>0.8\t\t"	<<HtGbAK5G2bCA8dR_Eff	<<endl;
		cout<<"Total\t\t\t"		<<Total_Eff		<<endl;
		cout<<endl;

		Bg_TotalEvt 			= Bg_TotalEvt			+ (TTMC[i].totalEvt*scale);
		Bg_Ht_RestNum 			= Bg_Ht_RestNum			+ Ht_RestNum;
		Bg_HtGbAK5_RestNum 		= Bg_HtGbAK5_RestNum		+ HtGbAK5_RestNum;
		Bg_HtGbAK5G2bCA8_RestNum 	= Bg_HtGbAK5G2bCA8_RestNum	+ HtGbAK5G2bCA8_RestNum; 
		Bg_HtGbAK5G2bCA8dR_RestNum 	= Bg_HtGbAK5G2bCA8dR_RestNum	+ HtGbAK5G2bCA8dR_RestNum;
	}
	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	cout<<"/////////////////////== Bos Background MC ==//////////////////////"<<endl;
	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	for(int i=0; i<BosMC_TotalNum; i++){
		double Ht_RestNum;
		double HtGbAK5_RestNum;
		double HtGbAK5G2bCA8_RestNum;
		double HtGbAK5G2bCA8dR_RestNum;
		double Ht_Eff;
		double HtGbAK5_Eff;
		double HtGbAK5G2bCA8_Eff;
		double HtGbAK5G2bCA8dR_Eff;
		double Total_Eff;

		double scale = 1000*lumi*BosMC[i].xsec/BosMC[i].totalEvt;
		string path = BgRootPath+"/"+BosMC[i].name+".root";
		Bosf[i] = new TFile(path.c_str());
		Ht_Bos[i]		=(TH1F*)Bosf[i]->Get("EvtInfo.NumRestEvt.Ht");			Ht_Bos[i]->Scale(scale);
		HtGbAK5_Bos[i]		=(TH1F*)Bosf[i]->Get("EvtInfo.NumRestEvt.Ht.GbAK5");		HtGbAK5_Bos[i]->Scale(scale);
		HtGbAK5G2bCA8_Bos[i]	=(TH1F*)Bosf[i]->Get("EvtInfo.NumRestEvt.Ht.GbAK5.G2bCA8");	HtGbAK5G2bCA8_Bos[i]->Scale(scale);
		HtGbAK5G2bCA8dR_Bos[i]	=(TH1F*)Bosf[i]->Get("EvtInfo.NumRestEvt.Ht.GbAK5.G2bCA8.dR");	HtGbAK5G2bCA8dR_Bos[i]->Scale(scale);
		
		Ht_RestNum 		= Ht_Bos[i]->GetBinContent(2);
		HtGbAK5_RestNum 	= HtGbAK5_Bos[i]->GetBinContent(2);
		HtGbAK5G2bCA8_RestNum 	= HtGbAK5G2bCA8_Bos[i]->GetBinContent(2);
		HtGbAK5G2bCA8dR_RestNum = HtGbAK5G2bCA8dR_Bos[i]->GetBinContent(2);

		Ht_Eff		    	= Ht_RestNum/(BosMC[i].totalEvt*scale);
		HtGbAK5_Eff 	    	= HtGbAK5_RestNum/Ht_RestNum;
		HtGbAK5G2bCA8_Eff   	= HtGbAK5G2bCA8_RestNum/HtGbAK5_RestNum;
		HtGbAK5G2bCA8dR_Eff 	= HtGbAK5G2bCA8dR_RestNum/HtGbAK5G2bCA8_RestNum;
		Total_Eff		= HtGbAK5G2bCA8dR_RestNum/(BosMC[i].totalEvt*scale);

		cout<<"============= "<<BosMC[i].name<<" =============="<<endl;		
		cout<<"Selection Cut\t\t"	<<"Efficiency"		<<endl;
		cout<<"Ht>1000\t\t\t"		<<Ht_Eff		<<endl;
		cout<<"Good CSVM AK5>=3\t"	<<HtGbAK5_Eff		<<endl;
		cout<<"Good 2b CA8>=1\t\t"	<<HtGbAK5G2bCA8_Eff	<<endl;
		cout<<"dR(CA8,AK5)>0.8\t\t"	<<HtGbAK5G2bCA8dR_Eff	<<endl;
		cout<<"Total\t\t\t"		<<Total_Eff		<<endl;
		cout<<endl;

		Bg_TotalEvt 			= Bg_TotalEvt			+ (BosMC[i].totalEvt*scale);
		Bg_Ht_RestNum 			= Bg_Ht_RestNum			+ Ht_RestNum;
		Bg_HtGbAK5_RestNum 		= Bg_HtGbAK5_RestNum		+ HtGbAK5_RestNum;
		Bg_HtGbAK5G2bCA8_RestNum 	= Bg_HtGbAK5G2bCA8_RestNum	+ HtGbAK5G2bCA8_RestNum; 
		Bg_HtGbAK5G2bCA8dR_RestNum 	= Bg_HtGbAK5G2bCA8dR_RestNum	+ HtGbAK5G2bCA8dR_RestNum;
	}


	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	cout<<"/////////////////////////== SIGNAL MC ==//////////////////////////"<<endl;
	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	for(int i=0; i<SigMC_TotalNum; i++){
		double Ht_RestNum;
		double HtGbAK5_RestNum;
		double HtGbAK5G2bCA8_RestNum;
		double HtGbAK5G2bCA8dR_RestNum;
		double Ht_Eff;
		double HtGbAK5_Eff;
		double HtGbAK5G2bCA8_Eff;
		double HtGbAK5G2bCA8dR_Eff;
		double Total_Eff;
	
		double scale 	= 1000*lumi*SigMC[i].xsec/SigMC[i].totalEvt;
		string path 	= SigRootPath+"/"+SigMC[i].name+".root";
		sigf[i] 	= new TFile(path.c_str());
		Ht_sig[i]		=(TH1F*)sigf[i]->Get("EvtInfo.NumRestEvt.Ht");			Ht_sig[i]->Scale(scale);
		HtGbAK5_sig[i]		=(TH1F*)sigf[i]->Get("EvtInfo.NumRestEvt.Ht.GbAK5");		HtGbAK5_sig[i]->Scale(scale);
		HtGbAK5G2bCA8_sig[i]	=(TH1F*)sigf[i]->Get("EvtInfo.NumRestEvt.Ht.GbAK5.G2bCA8");	HtGbAK5G2bCA8_sig[i]->Scale(scale);
		HtGbAK5G2bCA8dR_sig[i]	=(TH1F*)sigf[i]->Get("EvtInfo.NumRestEvt.Ht.GbAK5.G2bCA8.dR");	HtGbAK5G2bCA8dR_sig[i]->Scale(scale);
		
		Ht_RestNum 		= Ht_sig[i]->GetBinContent(2);
		HtGbAK5_RestNum 	= HtGbAK5_sig[i]->GetBinContent(2);
		HtGbAK5G2bCA8_RestNum 	= HtGbAK5G2bCA8_sig[i]->GetBinContent(2);
		HtGbAK5G2bCA8dR_RestNum = HtGbAK5G2bCA8dR_sig[i]->GetBinContent(2);

		Ht_Eff		    	= Ht_RestNum/(SigMC[i].totalEvt*scale);
		HtGbAK5_Eff 	    	= HtGbAK5_RestNum/Ht_RestNum;
		HtGbAK5G2bCA8_Eff   	= HtGbAK5G2bCA8_RestNum/HtGbAK5_RestNum;
		HtGbAK5G2bCA8dR_Eff 	= HtGbAK5G2bCA8dR_RestNum/HtGbAK5G2bCA8_RestNum;
		Total_Eff		= HtGbAK5G2bCA8dR_RestNum/(SigMC[i].totalEvt*scale);

		cout<<"============= "<<SigMC[i].name<<" =============="<<endl;		
		cout<<"Selection Cut\t\t"	<<"Efficiency"		<<endl;
		cout<<"Ht>1000\t\t\t"		<<Ht_Eff		<<endl;
		cout<<"Good CSVM AK5>=3\t"	<<HtGbAK5_Eff		<<endl;
		cout<<"Good 2b CA8>=1\t\t"	<<HtGbAK5G2bCA8_Eff	<<endl;
		cout<<"dR(CA8,AK5)>0.8\t\t"	<<HtGbAK5G2bCA8dR_Eff	<<endl;
		cout<<"Total\t\t\t"		<<Total_Eff		<<endl;
		cout<<endl;

	}


	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	cout<<"/////////////////////== Total Background MC ==////////////////////"<<endl;
	cout<<"//////////////////////////////////////////////////////////////////"<<endl;

	Bg_Ht_Eff		= Bg_Ht_RestNum/Bg_TotalEvt;
	Bg_HtGbAK5_Eff 	    	= Bg_HtGbAK5_RestNum/Bg_Ht_RestNum;
	Bg_HtGbAK5G2bCA8_Eff   	= Bg_HtGbAK5G2bCA8_RestNum/Bg_HtGbAK5_RestNum;
	Bg_HtGbAK5G2bCA8dR_Eff 	= Bg_HtGbAK5G2bCA8dR_RestNum/Bg_HtGbAK5G2bCA8_RestNum;
	Bg_Total_Eff		= Bg_HtGbAK5G2bCA8dR_RestNum/Bg_TotalEvt;

	cout<<"Selection Cut\t\t"	<<"Efficiency"		<<endl;
	cout<<"Ht>1000\t\t\t"		<<Bg_Ht_Eff		<<endl;
	cout<<"Good CSVM AK5>=3\t"	<<Bg_HtGbAK5_Eff		<<endl;
	cout<<"Good 2b CA8>=1\t\t"	<<Bg_HtGbAK5G2bCA8_Eff	<<endl;
	cout<<"dR(CA8,AK5)>0.8\t\t"	<<Bg_HtGbAK5G2bCA8dR_Eff	<<endl;
	cout<<"Total\t\t\t"		<<Bg_Total_Eff		<<endl;
	cout<<endl;

}
