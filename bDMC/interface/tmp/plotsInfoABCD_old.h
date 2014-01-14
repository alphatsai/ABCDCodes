/////// Set Struct of All variables(TH1F) //////====================================================================================
enum th1flist_{
	ABCD1_LeadingSubCSV_HtAK5CA8_, 		//10-21
	ABCD2_SubLeadingSubCSV_HtAK5CA8_, 	//10-21
	ABCD3_LeadingSubCSV_HtAK5_, 		//10-21
	ABCD4_BigestCSV12_HtAK5CA8_, 		//10-21

	Event_NumEvtCutFlow_, 	 	//10-21
	Event_HtAK5CA8_ABCD1_,  		//10-21
	Event_HtAK5CA8_ABCD2_,  		//10-21
	Event_HtAK5CA8_ABCD3_,  		//10-21
	Event_HtAK5CA8_ABCD4_,  		//10-21
	Event_Leadingb1b2b3_ABCD3_,  		//10-21
	Event_BigestCSV12pT_ABCD4_,  		//10-21
	Event_BigestCSV12_ABCD1_,  		//10-21
	Event_BigestCSV12_ABCD4_,  		//10-21

	GenInfo_HiggsDaPdgID_,  	//11-06
	GenInfo_NumHiggsTobb_,  	//11-06
	GenInfo_NumHiggsToOther_,  	//11-06

	CA8Jet_Pt_,  			//10-31
	CA8Jet_Leading_Pt_ABCD1_, 	 	//10-31
	CA8Jet_Leading_Pt_ABCD2_, 	 	//10-31
	CA8Jet_Leading_Pt_ABCD3_, 	 	//10-31

	AK5Jet_Pt_,  			//10-31

	bJet_Pt_,  			//10-31
	bJet_Leading_Pt_, 	 	//10-31

	SubJet_Leading_Pt_ABCD1_,  	//10-31
	SubJet_Leading_CSV_ABCD1_,  	//10-21
	SubJet_SubLeading_Pt_ABCD1_,  	//10-31
	SubJet_SubLeading_CSV_ABCD1_,  	//10-31
	SubJet_Leading_Pt_ABCD2_,  	//10-31
	SubJet_Leading_CSV_ABCD2_,  	//10-21
	SubJet_SubLeading_Pt_ABCD2_,  	//10-31
	SubJet_SubLeading_CSV_ABCD2_,  	//10-31
	SubJet_Leading_Pt_ABCD3_,  	//10-31
	SubJet_Leading_CSV_ABCD3_,  	//10-21
	SubJet_SubLeading_Pt_ABCD3_,  	//10-31
	SubJet_SubLeading_CSV_ABCD3_,  	//10-31
	SubJet_Leading_Pt_ABCD4_,  	//10-31
	SubJet_Leading_CSV_ABCD4_,  	//10-21
	SubJet_SubLeading_Pt_ABCD4_,  	//10-31
	SubJet_SubLeading_CSV_ABCD4_,  	//10-31
        th1_size_
};

struct TH1Info_{
	bool 	output;
	string	name;
	string	title;
	string  xtitle;
	string 	ytitle;
	string  xunit;
	int  	bin;
	double  min;
	double  max;
};

struct TH1Info_ TH1Info[th1_size_] = {
	{ 0,	"ABCD1.SubjetPt_Ht",		"",	"Cut Region", 			"Yields", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCD2.SubLeadingSubCSV_HtAK5CA8", 	"",	"Cut Region", 			"Yields", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCD3.LeadingSubCSV_HtAK5",		"",	"Cut Region", 			"Yields", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCD4.BigestCSV12_HtAK5CA8",		"",	"Cut Region", 			"Yields", "", 		4, 0, 4}, 	//10-21

	{ 1,	"Event.NumEvtCutFlow", 			"",	"Evt Select", 			"Events", "", 		5, 0, 5}, 	//10-21
	{ 1,	"Event.HtAK5CA8.ABCD1", 		"",	"Ht(AK5,CA8)", 			"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 1,	"Event.HtAK5CA8.ABCD2", 		"",	"Ht(AK5,CA8)", 			"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 1,	"Event.HtAK5CA8.ABCD3", 		"",	"HT", 			"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 1,	"Event.HtAK5CA8.ABCD4", 		"",	"Ht(AK5,CA8)", 			"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 1,	"Event.Leadingb1b2b3.ABCD3", 		"",	"Muti-CSV", 			"Yields", "", 		110, 0, 1.1}, 	//10-21
	{ 1,	"Event.BigestCSV12pT.ABCD4", 		"",	"CA8 Pt", 			"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-21
	{ 1,	"Event.BigestCSV12.ABCD1", 		"",	"Tau2/Tau1", 			"Yields", "", 		100,  0, 1}, 	//10-21
	{ 1,	"Event.BigestCSV12.ABCD4", 		"",	"Bigest CSV", 			"Yields", "", 		110,  0, 1.1}, 	//10-21

	{ 0,	"GenInfo.HiggsDaPdgID", 		"",	"PdgID", 			"Yields", "", 		52, -26, 26}, 	//11-06
	{ 0,	"GenInfo.NumHiggsTobb", 		"",	"Number", 			"Yields", "", 		3, 0, 3}, 	//11-06
	{ 0,	"GenInfo.NumHiggsToOther", 		"",	"Number", 			"Yields", "", 		3, 0, 3}, 	//11-06

	{ 1,	"CA8Jet.Pt", 				"",	"CA8 Pt", 			"Yields", "GeV/c",	1500, 0, 1500}, 	//10-31
	{ 1,	"CA8Jet.Leading.Pt.ABCD1", 		"",	"Leading CA8 Pt", 		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-31
	{ 1,	"CA8Jet.Leading.Pt.ABCD2", 		"",	"Leading CA8 Pt", 		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-31
	{ 1,	"CA8Jet.Leading.Pt.ABCD3", 		"",	"Leading CA8 Pt", 		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-31

	{ 1,	"AK5Jet.Pt", 				"",	"AK5 Pt", 			"Yields", "GeV/c",	1500, 0, 1500}, 	//10-31

	{ 1,	"bJet.Pt", 				"",	"bJet Pt", 			"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-31
	{ 1,	"bJet.Leading.Pt", 			"",	"Leading bJet Pt", 		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-31

	{ 1,	"SubJet.Leading.Pt.ABCD1", 		"",	"Lead bJet Pt", 		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-31
	{ 1,	"SubJet.Leading.CSV.ABCD1", 		"",	"Lead bJet CSV", 		"Yields", "", 		110, 0, 1.1}, 	//10-21
	{ 1,	"SubJet.SubLeading.Pt.ABCD1", 		"",	"next-Lead bJet Pt", 		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-31
	{ 1,	"SubJet.SubLeading.CSV.ABCD1", 		"",	"next-Lead bJet CSV", 		"Yields", "", 		110, 0, 1.1}, 	//10-31
	{ 1,	"SubJet.Leading.Pt.ABCD2", 		"",	"Leading SubJet Pt", 		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-31
	{ 1,	"SubJet.Leading.CSV.ABCD2", 		"",	"Leading SubJet CSV", 		"Yields", "", 		110, 0, 1.1}, 	//10-21
	{ 1,	"SubJet.SubLeading.Pt.ABCD2", 		"",	"Sub-Leading SubJet Pt", 	"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-31
	{ 1,	"SubJet.SubLeading.CSV.ABCD2", 		"",	"Sub-Leading SubJet CSV", 	"Yields", "", 		110, 0, 1.1}, 	//10-31
	{ 1,	"SubJet.Leading.Pt.ABCD3", 		"",	"Leading SubJet Pt", 		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-31
	{ 1,	"SubJet.Leading.CSV.ABCD3", 		"",	"Leading SubJet CSV", 		"Yields", "", 		110, 0, 1.1}, 	//10-21
	{ 1,	"SubJet.SubLeading.Pt.ABCD3", 		"",	"Sub-Leading SubJet Pt", 	"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-31
	{ 1,	"SubJet.SubLeading.CSV.ABCD3", 		"",	"Sub-Leading SubJet CSV", 	"Yields", "", 		110, 0, 1.1}, 	//10-31
	{ 1,	"SubJet.Leading.Pt.ABCD4", 		"",	"Bigest CSV SubJet Pt",		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-31
	{ 1,	"SubJet.Leading.CSV.ABCD4", 		"",	"Bigest CSV ", 			"Yields", "", 		110, 0, 1.1}, 	//10-21
	{ 1,	"SubJet.SubLeading.Pt.ABCD4", 		"",	"Low CSV SubJet Pt", 		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-31
	{ 1,	"SubJet.SubLeading.CSV.ABCD4", 		"",	"Low CSV", 			"Yields", "", 		110, 0, 1.1}, 	//10-31
};

struct OtherInfo_{
	bool  yLog;
	float LegLBX;		//LeftBottomX
	float LegLBY;		//LeftBottomY;
	float LegRTX;		//RightTopX
	float LegRTY;		//RightTopY
	char  LegOption[10];	//AddEntry option
	float SetYtileOffset;    //SetYtileoffset
	float SetYMaximum; 	//SetYMaximun
	float SetYMinimum;	//SetYMinimum
	float SetXMaximum; 	//SetXMaximun
	float SetXMinimum;	//SetXMinimum
	int   rebin;		//rebin
};

struct OtherInfo_ OtherInfo[th1_size_] = {
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCD1_LeadingSubCSV_HtAK5CA8_ 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCD2_SubLeadingSubCSV_HtAK5CA8_ 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCD3_LeadingSubCSV_HtAK5_ 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCD4_BigestCSV12pT_HtAK5CA8_ 	//10-2

	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//Event_NumEvtCutFlow			//10-21
	{1,0.65,0.30,0.85,0.50,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//Event_HtAK5CA8_ABCD1_		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//Event_HtAK5CA8_ABCD2_		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, 0.001, -1111, -1111, 10},		//Event_HtAK5CA8_ABCD3_		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//Event_HtAK5CA8_ABCD4_		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 5},		//Event_Leadingb1b2b3_ABCD3_		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//Event_BigestSCV12pT_ABCD4_		 	//10-21
	{1,0.30,0.30,0.50,0.50,"l", 1.3, -1111,  0.01, -1111, -1111,  5},		//Event_BigestSCV12_ABCD1_		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111,  0.01, -1111, -1111,  5},		//Event_BigestSCV12_ABCD4_		 	//10-21

	{0,0.65,0.65,0.85,0.85,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//GenInfo_HiggsDaPdgID_ 	//11-06
	{0,0.65,0.65,0.85,0.85,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//GenInfo_NumHiggsTobb_ 	//11-06
	{0,0.65,0.65,0.85,0.85,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//GenInfo_NumHiggsToOther_ 	//11-06

	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//CA8Jet_Pt_			 	//10-31
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//CA8Jet_Leading_Pt_ABCD1_ 		//10-31
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//CA8Jet_Leading_Pt_ABCD2_ 		//10-31
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//CA8Jet_Leading_Pt_ABCD3_ 		//10-31

	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//CA8Jet_Pt_			 	//10-31

	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//bJet_Pt_ 				//10-31
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//bJet_Leading_Pt_ 		//10-31

	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//SubJet_Leading_Pt_ABCD1_ 	//10-31
	{1,0.35,0.75,0.55,0.95,"l", 1.3, -1111,   0.01, -1111, -1111, 5},		//SubJet_Leading_CSV_ABCD1_ 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//SubJet_SubLeading_Pt_ABCD1_ 	//10-31
	{1,0.20,0.70,0.40,0.90,"l", 1.3, -1111,   0.01, -1111, -1111, 5},		//SubJet_SubLeading_CSV_ABCD1_ 	//10-31
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//SubJet_Leading_Pt_ABCD2_ 	//10-31
	{1,0.35,0.75,0.55,0.95,"l", 1.3, -1111,   0.01, -1111, -1111, 5},		//SubJet_Leading_CSV_ABCD2_ 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//SubJet_SubLeading_Pt_ABCD2_ 	//10-31
	{1,0.20,0.70,0.40,0.90,"l", 1.3, -1111,   0.01, -1111, -1111, 5},		//SubJet_SubLeading_CSV_ABCD2_ 	//10-31
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//SubJet_Leading_Pt_ABCD3_ 	//10-31
	{1,0.35,0.75,0.55,0.95,"l", 1.3, -1111, 0.001, -1111, -1111, 5},		//SubJet_Leading_CSV_ABCD3_ 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//SubJet_SubLeading_Pt_ABCD3_ 	//10-31
	{1,0.20,0.70,0.40,0.90,"l", 1.3, -1111, 0.001, -1111, -1111, 5},		//SubJet_SubLeading_CSV_ABCD3_ 	//10-31
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//SubJet_Leading_Pt_ABCD4_ 	//10-31
	{1,0.35,0.75,0.55,0.95,"l", 1.3, -1111,   0.01, -1111, -1111, 5},		//SubJet_Leading_CSV_ABCD4_ 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//SubJet_SubLeading_Pt_ABCD4_ 	//10-31
	{1,0.20,0.70,0.40,0.90,"l", 1.3, -1111,   0.01, -1111, -1111, 5},		//SubJet_SubLeading_CSV_ABCD4_ 	//10-31
};


/////// Set Struct of All variables(TH2F) //////=========================================================================================================================
enum th2flist_{
	Ht_SubjetPt, 				//06-06
	HtAK5CA8_SubLeadingSubCSV, 				//06-06
	HtAK5_LeadingSubCSV, 				//06-06
	HtAK5CA8_BigestCSV, 				//06-06
	th2_size_
};

struct TH2Info_{
	bool output;
	string name;
	string title;
	string xtitle;
	string ytitle;
	string xunit;
	string yunit;
	int xbin;
	double xmin;
	double xmax;
	int ybin;
	double ymin;
	double ymax;	
};

struct TH2Info_ TH2Info[th2_size_]={
	{ 1, "HtAK5CA8.LeadingSubCSV",		"",	"HT",	"CSV of leading SubJet", 	"GeV/c", "",	2000, 0, 2000, 105, 0, 1.05}, //06-06
	{ 1, "HtAK5CA8.SubLeadingSubCSV",	"",	"HT",	"CSV of Sub-leading SubJet", 	"GeV/c", "",	2000, 0, 2000, 105, 0, 1.05}, //06-06
	{ 1, "HtAK5.LeadingSubCSV",		"",	"Ht",	"CSV dicriminator of subjet", 	"GeV/c", "",	2000, 0, 2000, 105, 0, 1.05}, //06-06
	{ 1, "HtAK5CA8.BigestCSV",		"",	"Ht(AK5,CA8)",	"CSV of largest CSV SubJet",	"GeV/c", "",	2000, 0, 2000, 105, 0, 1.05}, //06-06
};


struct Other2Info_{
	bool logZ;
	int xrebin;
	int yrebin;
	float xCut;	//SetXaxis min
	float yCut;	//SetXaxis max
	float SetXMin;	//SetXaxis min
	float SetXMax;	//SetXaxis max
	float SetYMin;	//SetYaxis min
	float SetYMax;	//SetYaxis max
	float SetZMin;	//SetZaxis max
	float SetZMax;	//SetZaxis max
};

struct Other2Info_ Other2Info[th2_size_] = {
	{0, 10, 5, 1000, 0.244, 0, -1111, 0, -1111, 1, -1111},	//Ht_SubjetPt 	//06-06
	{0, 10, 5, 1000, 0.244, 0, -1111, 0, -1111, 1, -1111},	//HtAK5CA8_SubLeadingSubCSV 	//06-06
	{0, 10, 5, 1000, 0.679, 0, -1111, 0, -1111, 1, -1111},	//HtAK5_LeadingSubCSV 	//06-06
	{0, 10, 5, 900, 0.679, 0, -1111, 0, -1111, 1, -1111},	//HtAK5CA8_BigestCSVpT 	//06-06
};

