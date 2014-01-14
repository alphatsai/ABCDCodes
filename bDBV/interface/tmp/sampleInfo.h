////// Total Sample category ///////===========================================================================================================================================
const double lumi = 19.6; // fb-1, sqrt(s)=8TeV
const int TotalNum = 4;  //1
const int Data_TotalNum = 4;  //1
const int SigMC_TotalNum = 11;  //0
const int QCDMC_TotalNum = 8;  //1
const int TTMC_TotalNum  = 1;  //2
//const int BosMC_TotalNum  = 4;  //3
struct Category_{
	string 	CategoryName;
	int	SampleSize;
	Color_t	StackColor;
};
struct Category_ Category[TotalNum] = {
	{"Data",		Data_TotalNum,	kViolet},
	{"Signal",		SigMC_TotalNum,	kViolet+2},
	{"QCD",			QCDMC_TotalNum,	kOrange+1},
	{"ttBar",		TTMC_TotalNum,	kSpring+9},
//	{"Boson(Z,W,...)",	BosMC_TotalNum,	kAzure+2}

};
//===============================================================================================================================================================
////// Date 8TeV ///////===========================================================================================================================================
//===============================================================================================================================================================
struct Data_{
	string sample;
	string name;
	double totalEvt;
	int numRootFiles;
};
struct Data_ Data[Data_TotalNum]={
	{"Jet_Run2012A", "Jet-2012A", 0, 224},	
	{"JetHT_Run2012B", "JetHT-2012B", 0, 265},	
	{"JetHT_Run2012C", "JetHT-2012C", 0, 274},	
	{"JetHT_Run2012D", "JetHT-2012D", 0, 274},	
};


//===============================================================================================================================================================
////// MC Sample ///////===========================================================================================================================================
//===============================================================================================================================================================
///// Signal MC ///////=======================================================================================================================================================
struct SigMC_{
	string  sample;
	string	name;
	double  xsec; //pb
	double  totalEvt;
	Color_t	StackColor;
	char	LegTitle[100];	//TLegend AddEntry title
	int	LineColor;
	int	LineStyle;
	int numRootFiles;
};
struct SigMC_ SigMC[SigMC_TotalNum] = {
	{"BprimeBprimeToBHBHinc_M-450_TuneZ2star_8TeV-madgraph",	"BH_450",    1.153,	101961,  	kOrange+1,	"b' 450(GeV)",	2, 1, 11},
	{"BprimeBprimeToBHBHinc_M-500_TuneZ2star_8TeV-madgraph",	"BH_500",    5.90e-1,	98029,  kOrange+1,	"b' 500(GeV)",	2, 1, 10},
	{"BprimeBprimeToBHBHinc_M-550_TuneZ2star_8TeV-madgraph",	"BH_550",    3.15e-1,	96483,  kOrange+1,	"b' 550(GeV)",	2, 1, 10},
	{"BprimeBprimeToBHBHinc_M-600_TuneZ2star_8TeV-madgraph",	"BH_600",    1.74e-1,   98952,  kOrange+1,	"b' 600(GeV)",	2, 1, 10},
	{"BprimeBprimeToBHBHinc_M-650_TuneZ2star_8TeV-madgraph",	"BH_650",    9.99e-2,	94491,  kOrange+1,	"b' 650(GeV)",	2, 1, 10},
	{"BprimeBprimeToBHBHinc_M-700_TuneZ2star_8TeV-madgraph",	"BH_700",    5.85e-2,  96602,  kOrange+1,	"b' 700(GeV)",	2, 1, 10},
	{"BprimeBprimeToBHBHinc_M-750_TuneZ2star_8TeV-madgraph",	"BH_750",    3.50e-2,  99487,  kOrange+1,	"b' 750(GeV)",	2, 1, 10},
	{"BprimeBprimeToBHBHinc_M-800_TuneZ2star_8TeV-madgraph",	"BH_800",    2.13e-2,  100835,  kOrange+1,	"b' 800(GeV)",	2, 1, 11},
//	{"BprimeBprimeToBHBHinc_M-900_TuneZ2star_8TeV-madgraph",	"BH_900",   8.28e-03, 76480,  kOrange+1, 	"b' 900(GeV)", 	2, 1, 10},
	{"BprimeBprimeToBHBHinc_M-1000_TuneZ2star_8TeV-madgraph",	"BH_1000",  3.28e-03, 94866,  kOrange+1, 	"b' 1000(GeV)",	2, 1, 10},
//	{"BprimeBprimeToBHBHinc_M-1100_TuneZ2star_8TeV-madgraph",	"BH_1100", 14.10e-04, 100963,  kOrange+1, 	"b' 1100(GeV)",	2, 1, 10},
	{"BprimeBprimeToBHBHinc_M-1200_TuneZ2star_8TeV-madgraph",	"BH_1200",  5.85e-04, 90131,  kOrange+1, 	"b' 1200(GeV)",	2, 1, 10},
//	{"BprimeBprimeToBHBHinc_M-1300_TuneZ2star_8TeV-madgraph",	"BH_1300",  2.61e-04, 90970,  kOrange+1, 	"b' 1300(GeV)",	2, 1, 10},
//	{"BprimeBprimeToBHBHinc_M-1400_TuneZ2star_8TeV-madgraph",	"BH_1400", 11.40e-05, 96052,  kOrange+1, 	"b' 1400(GeV)",	2, 1, 10},
	{"BprimeBprimeToBHBHinc_M-1500_TuneZ2star_8TeV-madgraph",	"BH_1500",  4.81e-05,  93639,  kOrange+1, 	"b' 1500(GeV)",	2, 1, 10},
};

///// Bg MC ///////===========================================================================================================================================================
struct BgMC_{
	string sample;
	string name;
	double xsec; //pb
	double totalEvt; 
	Color_t	StackColor;
	char	LegTitle[100];	//TLegend AddEntry title
	int numRootFiles;
};
struct BgMC_ QCDMC[QCDMC_TotalNum]={
	{"QCD_Pt-170to300_TuneZ2star_8TeV_pythia6",	"QCD_Pt-170to300",	34138.15,  5767018,  kMagenta-10, "QCD Pt-170~300", 582},
	{"QCD_Pt-300to470_TuneZ2star_8TeV_pythia6",	"QCD_Pt-300to470",	1759.549,  5908205, kMagenta-9, "QCD Pt-300~470", 596},
	{"QCD_Pt-470to600_TuneZ2star_8TeV_pythia6",	"QCD_Pt-470to600",	113.8791,  3919113, kMagenta-8, "QCD Pt-470~600", 398},
	{"QCD_Pt-600to800_TuneZ2star_8TeV_pythia6",	"QCD_Pt-600to800",	26.9921,	3902030, kMagenta-7, "QCD Pt-600~800", 392},
	{"QCD_Pt-800to1000_TuneZ2star_8TeV_pythia6",	"QCD_Pt-800to1000",	3.550063,	3881338, kMagenta-6, "QCD Pt-800~1000", 392},
	{"QCD_Pt-1000to1400_TuneZ2star_8TeV_pythia6",	"QCD_Pt-1000to1400",    0.737844,  	1875936, kMagenta-5, "QCD Pt-1000~1400", 190},
	{"QCD_Pt-1400to1800_TuneZ2star_8TeV_pythia6",	"QCD_Pt-1400to1800",    0.03352235,  1912782, kMagenta-4, "QCD Pt-1400~1800", 193},
	{"QCD_Pt-1800_TuneZ2star_8TeV_pythia6",		"QCD_Pt-1800",    	0.001829005,  918870, kMagenta-3, "QCD Pt-1800", 93},
};
struct BgMC_ TTMC[TTMC_TotalNum]={
	{"TTJets_HadronicMGDecays_8TeV-madgraph",				"TTJets",      112.3247008,  10485781, kBlue-10, "TTJets", 1058},  //top mass=172.5, but from wiki for 173.3 xsec=245.8*67.6*67.6/10000
//	{"TTJets_HadronicMGDecays_8TeV-madgraph",				"TTJets",      96.5363408556,  10534158, kBlue-10, "TTJets"},  //top mass=172.5, but from wiki for 173.3 xsec=245.8*67.6*67.6*(mass filter)/10000 (mass filter=85944/100000)
//	{"TT_Mtt-1000toInf_CT10_TuneZ2star_8TeV-powheg-tauola",	"TT_Mtt-1000toInf",   3.4412,  1246340, kBlue-9, "TT Mtt-1000"}, // xsec = 245.8*(filter eff) = 245.8*0.014 
//	{"TT_Mtt-700to1000_CT10_TuneZ2star_8TeV-powheg-tauola",	"TT_Mtt-700to1000",   18.1892,  3079071, kBlue-8, "TT Mtt-700~1000"}, // xsec = 245.8*(filter eff) = 245.8*0.074 
};
/*
struct BgMC_ BosMC[BosMC_TotalNum]={
	{"DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball",		"DY",    	3503.71, 30457855, kGreen+3, "Z/a"},
	{"WZ_TuneZ2star_8TeV_pythia6_tauola",				"WZ",    	33.21, 9998920, kGreen+3, "WZ"},
	{"WJetsToLNu_TuneZ2Star_8TeV-madgraph-tarball",			"WJet",    	37509.0, 57708466, kGreen+3, "WJet"},
	{"ZZ_TuneZ2star_8TeV_pythia6_tauola",				"ZZ",    	8.059, 9798448, kGreen+3, "ZZ"},

};
*/
