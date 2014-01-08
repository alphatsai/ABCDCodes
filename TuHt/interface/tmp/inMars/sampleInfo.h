const double lumi = 19.6; // fb-1, sqrt(s)=8TeV
const int TotalNum = 4;  //1
const int SigMC_TotalNum = 11;  //0
const int QCDMC_TotalNum = 8;  //1
const int TTMC_TotalNum  = 3;  //2
const int BosMC_TotalNum  = 4;  //3
////// Total Sample category ///////===========================================================================================================================================
struct Category_{
	string 	CategoryName;
	int	SampleSize;
	Color_t	StackColor;
};
struct Category_ Category[TotalNum] = {
	{"Signal",		SigMC_TotalNum,	kViolet+2},
	{"QCD",			QCDMC_TotalNum,	kOrange+1},
	{"ttBar",		TTMC_TotalNum,	kSpring+9},
	{"Boson(Z,W,...)",	BosMC_TotalNum,	kAzure+2}

};

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
};
struct SigMC_ SigMC[SigMC_TotalNum] = {
	{"BprimeBprimeToBHBHinc_M-500_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",	"BH_500",    5.90e-1,  99819,  kOrange+1,"b'  500(GeV)",	2, 1},
	{"BprimeBprimeToBHBHinc_M-600_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",	"BH_600",    17.40e-2, 101184,  kOrange+1,"b'  600(GeV)",	2, 1},
	{"BprimeBprimeToBHBHinc_M-700_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",	"BH_700",    5.85e-2,  99208,  kOrange+1,"b'  700(GeV)",	2, 1},
	{"BprimeBprimeToBHBHinc_M-800_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",	"BH_800",    2.13e-2,  104019,  kOrange+1,"b'  800(GeV)",	2, 1},
	{"BprimeBprimeToBHBHinc_M-900_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1",	"BH_900",   8.28e-03, 76480,  kOrange+1, "b' 900(GeV)", 	2, 1},
	{"BprimeBprimeToBHBHinc_M-1000_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1",	"BH_1000",  3.36e-03, 98675,  kOrange+1, "b' 1000(GeV)", 	2, 1},
	{"BprimeBprimeToBHBHinc_M-1100_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1",	"BH_1100", 14.10e-04, 100963,  kOrange+1, "b' 1100(GeV)", 	2, 1},
	{"BprimeBprimeToBHBHinc_M-1200_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1",	"BH_1200",  6.02e-04, 94263,  kOrange+1, "b' 1200(GeV)", 	2, 1},
	{"BprimeBprimeToBHBHinc_M-1300_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1",	"BH_1300",  2.61e-04, 90970,  kOrange+1, "b' 1300(GeV)", 	2, 1},
	{"BprimeBprimeToBHBHinc_M-1400_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1",	"BH_1400", 11.40e-05, 96052,  kOrange+1, "b' 1400(GeV)", 	2, 1},
	{"BprimeBprimeToBHBHinc_M-1500_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1",	"BH_1500",  4.99e-05,  98909,  kOrange+1, "b' 1500(GeV)",	2, 1},
};

///// Bg MC ///////===========================================================================================================================================================
struct BgMC_{
	string sample;
	string name;
	double xsec; //pb
	double totalEvt; 
	Color_t	StackColor;
	char	LegTitle[100];	//TLegend AddEntry title
};
struct BgMC_ QCDMC[QCDMC_TotalNum]={
	{"QCD_Pt-170to300_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v2",	"QCD_Pt-170to300",	34138.15,  5807697,  kMagenta-10, "QCD Pt-170~300"},
	{"QCD_Pt-300to470_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v2",	"QCD_Pt-300to470",	1759.55,  5948646, kMagenta-9, "QCD Pt-300~470"},
	{"QCD_Pt-470to600_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v2",	"QCD_Pt-470to600",	113.88,  3956647, kMagenta-8, "QCD Pt-470~600"},
	{"QCD_Pt-600to800_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v2",	"QCD_Pt-600to800",	27.0,	3947957, kMagenta-7, "QCD Pt-600~800"},
	{"QCD_Pt-800to1000_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v2",	"QCD_Pt-800to1000",	3.6,	3939466, kMagenta-6, "QCD Pt-800~1000"},
	{"QCD_Pt-1000to1400_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1",	"QCD_Pt-1000to1400",    0.74,  	1931583, kMagenta-5, "QCD Pt-1000~1400"},
	{"QCD_Pt-1400to1800_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1",	"QCD_Pt-1400to1800",    0.034,  1961718, kMagenta-4, "QCD Pt-1400~1800"},
	{"QCD_Pt-1800_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1",		"QCD_Pt-1800",    	0.0018,  955249, kMagenta-3, "QCD Pt-1800"},
};
struct BgMC_ TTMC[TTMC_TotalNum]={
	{"TTJets_HadronicMGDecays_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1",				"TTJets",      96.5363408556,  10534158, kBlue-10, "TTJets"},  //top mass=172.5, but from wiki for 173.3 xsec=245.8*67.6*67.6*(mass filter)/10000 (mass filter=85944/100000)
	{"TT_Mtt-1000toInf_CT10_TuneZ2star_8TeV-powheg-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",	"TT_Mtt-1000toInf",   3.4412,  1246340, kBlue-9, "TT Mtt-1000"}, // xsec = 245.8*(filter eff) = 245.8*0.014 
	{"TT_Mtt-700to1000_CT10_TuneZ2star_8TeV-powheg-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",	"TT_Mtt-700to1000",   18.1892,  3079071, kBlue-8, "TT Mtt-700~1000"}, // xsec = 245.8*(filter eff) = 245.8*0.074 
 
};
struct BgMC_ BosMC[BosMC_TotalNum]={
	{"DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_Summer12_DR53X-PU_S10_START53_V7A-v1",		"DY",    	3503.71, 30457855, kGreen+3, "Z/a"},
	{"WZ_TuneZ2star_8TeV_pythia6_tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",				"WZ",    	33.21, 9998920, kGreen+3, "WZ"},
	{"WJetsToLNu_TuneZ2Star_8TeV-madgraph-tarball_Summer12_DR53X-PU_S10_START53_V7A-v2",			"WJet",    	37509.0, 57708466, kGreen+3, "WJet"},
	{"ZZ_TuneZ2star_8TeV_pythia6_tauola_Summer12_DR53X-PU_S10_START53_V7A-v1",				"ZZ",    	8.059, 9798448, kGreen+3, "ZZ"},

};

