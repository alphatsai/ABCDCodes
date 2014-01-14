#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include "TFile.h"
#include "TH1F.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/bDBV/interface/sampleInfo.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/bDBV/interface/plotsInfo.h"
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
	
	string SigRootPath = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/bDBV/resurlt/root/mc/sig";
	string QCDRootPath = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/bDBV/resurlt/root/mc/bg";
	string TTRootPath  = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/bDBV/resurlt/root/mc/bg";
	string BosRootPath = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/bDBV/resurlt/root/mc/bg";

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


	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	cout<<"/////////////////////== QCD Background MC ==//////////////////////"<<endl;
	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	for(int i=0; i<QCDMC_TotalNum; i++){
		double n1_RestNum;
		double n12_RestNum;
		double n123_RestNum;
		double n1234_RestNum;
		double n12345_RestNum;
		double n123456_RestNum;
		double n1_Eff;
		double n12_Eff;
		double n123_Eff;
		double n1234_Eff;
		double n12345_Eff;
		double n123456_Eff;
		double Total_Eff;

		double scale = 1000*lumi*QCDMC[i].xsec/QCDMC[i].totalEvt;
		string path = QCDRootPath+"/"+QCDMC[i].name+".root";
		QCDf[i] = new TFile(path.c_str());
		h1_QCD[i]	=(TH1F*)QCDf[i]->Get("EvtInfo.NumRestEvt.1");		h1_QCD[i]->Scale(scale);
		h12_QCD[i]	=(TH1F*)QCDf[i]->Get("EvtInfo.NumRestEvt.12");		h12_QCD[i]->Scale(scale);
		h123_QCD[i]	=(TH1F*)QCDf[i]->Get("EvtInfo.NumRestEvt.123");		h123_QCD[i]->Scale(scale);
		h1234_QCD[i]	=(TH1F*)QCDf[i]->Get("EvtInfo.NumRestEvt.1234");	h1234_QCD[i]->Scale(scale);
		h12345_QCD[i]	=(TH1F*)QCDf[i]->Get("EvtInfo.NumRestEvt.12345");	h12345_QCD[i]->Scale(scale);
	//	h123456_QCD[i]	=(TH1F*)QCDf[i]->Get("EvtInfo.NumRestEvt.123456");	h123456_QCD[i]->Scale(scale);
		
		n1_RestNum 	= h1_QCD[i]->GetBinContent(2);
		n12_RestNum 	= h12_QCD[i]->GetBinContent(2);
		n123_RestNum 	= h123_QCD[i]->GetBinContent(2);
		n1234_RestNum 	= h1234_QCD[i]->GetBinContent(2);
		n12345_RestNum 	= h12345_QCD[i]->GetBinContent(2);
	//	n123456_RestNum = h123456_QCD[i]->GetBinContent(2);

		n1_Eff	    	= n1_RestNum/(QCDMC[i].totalEvt*scale);
		n12_Eff     	= n12_RestNum/n1_RestNum;
		n123_Eff    	= n123_RestNum/n12_RestNum;
		n1234_Eff   	= n1234_RestNum/n123_RestNum;
		n12345_Eff   	= n12345_RestNum/n1234_RestNum;
	//	n123456_Eff 	= n123456_RestNum/n12345_RestNum;
	//	Total_Eff	= n123456_RestNum/(QCDMC[i].totalEvt*scale);
		Total_Eff	= n12345_RestNum/(QCDMC[i].totalEvt*scale);

		cout<<"============= "<<QCDMC[i].name<<" =============="<<endl;		
		cout<<"Selection Cut\t\t"	<<"Efficiency"	<<endl;
		cout<<"Good CA8>=1\t\t"		<<n1_Eff	<<endl;
		cout<<"Good 2b CA8>=1\t\t"	<<n12_Eff	<<endl;
		cout<<"Good AK5>=2\t\t"		<<n123_Eff	<<endl;
		cout<<"Good CSVM AK5>=2\t"	<<n1234_Eff	<<endl;
		cout<<"Ht(AK5CA8)>1000\t\t"	<<n12345_Eff	<<endl;
		cout<<"Total\t\t\t"		<<Total_Eff	<<endl;
		cout<<endl;


		Bg_TotalEvt 		= Bg_TotalEvt		+ (QCDMC[i].totalEvt*scale);
		Bg_1_RestNum 		= Bg_1_RestNum		+ n1_RestNum;
		Bg_12_RestNum 		= Bg_12_RestNum		+ n12_RestNum;
		Bg_123_RestNum 		= Bg_123_RestNum	+ n123_RestNum;
		Bg_1234_RestNum	 	= Bg_1234_RestNum	+ n1234_RestNum; 
		Bg_12345_RestNum 	= Bg_12345_RestNum	+ n12345_RestNum; 
//		Bg_123456_RestNum 	= Bg_123456_RestNum	+ n123456_RestNum;
	}

	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	cout<<"/////////////////////== TT Background MC ==//////////////////////"<<endl;
	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	for(int i=0; i<TTMC_TotalNum; i++){
		double n1_RestNum;
		double n12_RestNum;
		double n123_RestNum;
		double n1234_RestNum;
		double n12345_RestNum;
		double n123456_RestNum;
		double n1_Eff;
		double n12_Eff;
		double n123_Eff;
		double n1234_Eff;
		double n12345_Eff;
		double n123456_Eff;
		double Total_Eff;

		double scale = 1000*lumi*TTMC[i].xsec/TTMC[i].totalEvt;
		string path = TTRootPath+"/"+TTMC[i].name+".root";
		TTf[i] = new TFile(path.c_str());
		h1_TT[i]	=(TH1F*)TTf[i]->Get("EvtInfo.NumRestEvt.1");		h1_TT[i]->Scale(scale);
		h12_TT[i]	=(TH1F*)TTf[i]->Get("EvtInfo.NumRestEvt.12");		h12_TT[i]->Scale(scale);
		h123_TT[i]	=(TH1F*)TTf[i]->Get("EvtInfo.NumRestEvt.123");		h123_TT[i]->Scale(scale);
		h1234_TT[i]	=(TH1F*)TTf[i]->Get("EvtInfo.NumRestEvt.1234");	h1234_TT[i]->Scale(scale);
		h12345_TT[i]	=(TH1F*)TTf[i]->Get("EvtInfo.NumRestEvt.12345");	h12345_TT[i]->Scale(scale);
	//	h123456_TT[i]	=(TH1F*)TTf[i]->Get("EvtInfo.NumRestEvt.123456");	h123456_TT[i]->Scale(scale);
		
		n1_RestNum 	= h1_TT[i]->GetBinContent(2);
		n12_RestNum 	= h12_TT[i]->GetBinContent(2);
		n123_RestNum 	= h123_TT[i]->GetBinContent(2);
		n1234_RestNum 	= h1234_TT[i]->GetBinContent(2);
		n12345_RestNum 	= h12345_TT[i]->GetBinContent(2);
	//	n123456_RestNum = h123456_TT[i]->GetBinContent(2);

		n1_Eff	    	= n1_RestNum/(TTMC[i].totalEvt*scale);
		n12_Eff     	= n12_RestNum/n1_RestNum;
		n123_Eff    	= n123_RestNum/n12_RestNum;
		n1234_Eff   	= n1234_RestNum/n123_RestNum;
		n12345_Eff   	= n12345_RestNum/n1234_RestNum;
	//	n123456_Eff 	= n123456_RestNum/n12345_RestNum;
	//	Total_Eff	= n123456_RestNum/(TTMC[i].totalEvt*scale);
		Total_Eff	= n12345_RestNum/(TTMC[i].totalEvt*scale);

		cout<<"============= "<<TTMC[i].name<<" =============="<<endl;		
		cout<<"Selection Cut\t\t"	<<"Efficiency"	<<endl;
		cout<<"Good CA8>=1\t\t"		<<n1_Eff	<<endl;
		cout<<"Good 2b CA8>=1\t\t"	<<n12_Eff	<<endl;
		cout<<"Good AK5>=2\t\t"		<<n123_Eff	<<endl;
		cout<<"Good CSVM AK5>=2\t"	<<n1234_Eff	<<endl;
		cout<<"Ht(AK5CA8)>1000\t\t"	<<n12345_Eff	<<endl;
		cout<<"Total\t\t\t"		<<Total_Eff	<<endl;
		cout<<endl;


		Bg_TotalEvt 		= Bg_TotalEvt		+ (TTMC[i].totalEvt*scale);
		Bg_1_RestNum 		= Bg_1_RestNum		+ n1_RestNum;
		Bg_12_RestNum 		= Bg_12_RestNum		+ n12_RestNum;
		Bg_123_RestNum 		= Bg_123_RestNum	+ n123_RestNum;
		Bg_1234_RestNum	 	= Bg_1234_RestNum	+ n1234_RestNum; 
		Bg_12345_RestNum 	= Bg_12345_RestNum	+ n12345_RestNum; 
//		Bg_123456_RestNum 	= Bg_123456_RestNum	+ n123456_RestNum;
	}

	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	cout<<"/////////////////////== Bos Background MC ==//////////////////////"<<endl;
	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	for(int i=0; i<BosMC_TotalNum; i++){
		double n1_RestNum;
		double n12_RestNum;
		double n123_RestNum;
		double n1234_RestNum;
		double n12345_RestNum;
		double n123456_RestNum;
		double n1_Eff;
		double n12_Eff;
		double n123_Eff;
		double n1234_Eff;
		double n12345_Eff;
		double n123456_Eff;
		double Total_Eff;

		double scale = 1000*lumi*BosMC[i].xsec/BosMC[i].totalEvt;
		string path = BosRootPath+"/"+BosMC[i].name+".root";
		Bosf[i] = new TFile(path.c_str());
		h1_Bos[i]	=(TH1F*)Bosf[i]->Get("EvtInfo.NumRestEvt.1");		h1_Bos[i]->Scale(scale);
		h12_Bos[i]	=(TH1F*)Bosf[i]->Get("EvtInfo.NumRestEvt.12");		h12_Bos[i]->Scale(scale);
		h123_Bos[i]	=(TH1F*)Bosf[i]->Get("EvtInfo.NumRestEvt.123");		h123_Bos[i]->Scale(scale);
		h1234_Bos[i]	=(TH1F*)Bosf[i]->Get("EvtInfo.NumRestEvt.1234");	h1234_Bos[i]->Scale(scale);
		h12345_Bos[i]	=(TH1F*)Bosf[i]->Get("EvtInfo.NumRestEvt.12345");	h12345_Bos[i]->Scale(scale);
	//	h123456_Bos[i]	=(TH1F*)Bosf[i]->Get("EvtInfo.NumRestEvt.123456");	h123456_Bos[i]->Scale(scale);
		
		n1_RestNum 	= h1_Bos[i]->GetBinContent(2);
		n12_RestNum 	= h12_Bos[i]->GetBinContent(2);
		n123_RestNum 	= h123_Bos[i]->GetBinContent(2);
		n1234_RestNum 	= h1234_Bos[i]->GetBinContent(2);
		n12345_RestNum 	= h12345_Bos[i]->GetBinContent(2);
	//	n123456_RestNum = h123456_Bos[i]->GetBinContent(2);

		n1_Eff	    	= n1_RestNum/(BosMC[i].totalEvt*scale);
		n12_Eff     	= n12_RestNum/n1_RestNum;
		n123_Eff    	= n123_RestNum/n12_RestNum;
		n1234_Eff   	= n1234_RestNum/n123_RestNum;
		n12345_Eff   	= n12345_RestNum/n1234_RestNum;
	//	n123456_Eff 	= n123456_RestNum/n12345_RestNum;
	//	Total_Eff	= n123456_RestNum/(BosMC[i].totalEvt*scale);
		Total_Eff	= n12345_RestNum/(BosMC[i].totalEvt*scale);

		cout<<"============= "<<BosMC[i].name<<" =============="<<endl;		
		cout<<"Selection Cut\t\t"	<<"Efficiency"	<<endl;
		cout<<"Good CA8>=1\t\t"		<<n1_Eff	<<endl;
		cout<<"Good 2b CA8>=1\t\t"	<<n12_Eff	<<endl;
		cout<<"Good AK5>=2\t\t"		<<n123_Eff	<<endl;
		cout<<"Good CSVM AK5>=2\t"	<<n1234_Eff	<<endl;
		cout<<"Ht(AK5CA8)>1000\t\t"	<<n12345_Eff	<<endl;
		cout<<"Total\t\t\t"		<<Total_Eff	<<endl;
		cout<<endl;


		Bg_TotalEvt 		= Bg_TotalEvt		+ (BosMC[i].totalEvt*scale);
		Bg_1_RestNum 		= Bg_1_RestNum		+ n1_RestNum;
		Bg_12_RestNum 		= Bg_12_RestNum		+ n12_RestNum;
		Bg_123_RestNum 		= Bg_123_RestNum	+ n123_RestNum;
		Bg_1234_RestNum	 	= Bg_1234_RestNum	+ n1234_RestNum; 
		Bg_12345_RestNum 	= Bg_12345_RestNum	+ n12345_RestNum; 
//		Bg_123456_RestNum 	= Bg_123456_RestNum	+ n123456_RestNum;
	}

	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	cout<<"/////////////////////////== SIGNAL MC ==//////////////////////////"<<endl;
	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	for(int i=0; i<SigMC_TotalNum; i++){
		double n1_RestNum;
		double n12_RestNum;
		double n123_RestNum;
		double n1234_RestNum;
		double n12345_RestNum;
		double n123456_RestNum;
		double n1_Eff;
		double n12_Eff;
		double n123_Eff;
		double n1234_Eff;
		double n12345_Eff;
		double n123456_Eff;
		double Total_Eff;

		double scale = 1000*lumi*SigMC[i].xsec/SigMC[i].totalEvt;
		string path = SigRootPath+"/"+SigMC[i].name+".root";
		Sigf[i] = new TFile(path.c_str());
		h1_Sig[i]	=(TH1F*)Sigf[i]->Get("EvtInfo.NumRestEvt.1");		h1_Sig[i]->Scale(scale);
		h12_Sig[i]	=(TH1F*)Sigf[i]->Get("EvtInfo.NumRestEvt.12");		h12_Sig[i]->Scale(scale);
		h123_Sig[i]	=(TH1F*)Sigf[i]->Get("EvtInfo.NumRestEvt.123");		h123_Sig[i]->Scale(scale);
		h1234_Sig[i]	=(TH1F*)Sigf[i]->Get("EvtInfo.NumRestEvt.1234");	h1234_Sig[i]->Scale(scale);
		h12345_Sig[i]	=(TH1F*)Sigf[i]->Get("EvtInfo.NumRestEvt.12345");	h12345_Sig[i]->Scale(scale);
	//	h123456_Sig[i]	=(TH1F*)Sigf[i]->Get("EvtInfo.NumRestEvt.123456");	h123456_Sig[i]->Scale(scale);
		
		n1_RestNum 	= h1_Sig[i]->GetBinContent(2);
		n12_RestNum 	= h12_Sig[i]->GetBinContent(2);
		n123_RestNum 	= h123_Sig[i]->GetBinContent(2);
		n1234_RestNum 	= h1234_Sig[i]->GetBinContent(2);
		n12345_RestNum 	= h12345_Sig[i]->GetBinContent(2);
	//	n123456_RestNum = h123456_Sig[i]->GetBinContent(2);

		n1_Eff	    	= n1_RestNum/(SigMC[i].totalEvt*scale);
		n12_Eff     	= n12_RestNum/n1_RestNum;
		n123_Eff    	= n123_RestNum/n12_RestNum;
		n1234_Eff   	= n1234_RestNum/n123_RestNum;
		n12345_Eff   	= n12345_RestNum/n1234_RestNum;
	//	n123456_Eff 	= n123456_RestNum/n12345_RestNum;
	//	Total_Eff	= n123456_RestNum/(SigMC[i].totalEvt*scale);
		Total_Eff	= n12345_RestNum/(SigMC[i].totalEvt*scale);

		cout<<"============= "<<SigMC[i].name<<" =============="<<endl;		
		cout<<"Selection Cut\t\t"	<<"Efficiency"	<<endl;
		cout<<"Good CA8>=1\t\t"		<<n1_Eff	<<endl;
		cout<<"Good 2b CA8>=1\t\t"	<<n12_Eff	<<endl;
		cout<<"Good AK5>=2\t\t"		<<n123_Eff	<<endl;
		cout<<"Good CSVM AK5>=2\t"	<<n1234_Eff	<<endl;
		cout<<"Ht(AK5CA8)>1000\t\t"	<<n12345_Eff	<<endl;
		cout<<"Total\t\t\t"		<<Total_Eff	<<endl;
		cout<<endl;

	}

	cout<<"//////////////////////////////////////////////////////////////////"<<endl;
	cout<<"/////////////////////== Total Background MC ==////////////////////"<<endl;
	cout<<"//////////////////////////////////////////////////////////////////"<<endl;

	Bg_1_Eff	= Bg_1_RestNum/Bg_TotalEvt;
	Bg_12_Eff   	= Bg_12_RestNum/Bg_1_RestNum;
	Bg_123_Eff     	= Bg_123_RestNum/Bg_12_RestNum;
	Bg_1234_Eff   	= Bg_1234_RestNum/Bg_123_RestNum;
	Bg_12345_Eff   	= Bg_12345_RestNum/Bg_1234_RestNum;
//	Bg_123456_Eff 	= Bg_123456_RestNum/Bg_12345_RestNum;
//	Bg_Total_Eff	= Bg_123456_RestNum/Bg_TotalEvt;
	Bg_Total_Eff	= Bg_12345_RestNum/Bg_TotalEvt;

	cout<<"Selection Cut\t\t"	<<"Efficiency"		<<endl;
	cout<<"Good CA8>=1\t\t"		<<Bg_1_Eff		<<endl;
	cout<<"Good 2b CA8>=1\t\t"	<<Bg_12_Eff		<<endl;
	cout<<"Good AK5>=2\t\t"		<<Bg_123_Eff		<<endl;
	cout<<"Good CSVM AK5>=2\t"	<<Bg_1234_Eff		<<endl;
	cout<<"Ht(AK5CA8)>1000\t\t"	<<Bg_12345_Eff		<<endl;
	cout<<"Total\t\t\t"		<<Bg_Total_Eff		<<endl;
	cout<<endl;

}
