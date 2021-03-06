#ifndef PLOTSINFOABCD_H
#define PLOTSINFOABCD_H

#include "selection.h"

/////// Set Struct of All variables(TH1F) //////====================================================================================
enum th1flist_{
	ABCD1_HT1_CutRegion_, 		//01-13
	ABCD1_HT2_CutRegion_, 		//01-13
	ABCD1_HT3_CutRegion_, 		//01-13
	ABCD2_HT1_CutRegion_, 		//01-13
	ABCD2_HT2_CutRegion_, 		//01-13
	ABCD2_HT3_CutRegion_, 		//01-13

	ABCD1_HT1_,  		//10-21
	ABCD1_HT2_,  		//10-21
	ABCD1_HT3_,  		//10-21
	ABCD1_LeadCA8_Pt_,  		//10-21
	ABCD1_LeadSub_Pt_,  		//10-21
	ABCD1_LeadSub_CSV_,  		//10-21
	ABCD1_SubLeadSub_Pt_,  		//10-21
	ABCD1_SubLeadSub_CSV_,  		//10-21
	ABCD2_HT1_,  		//10-21
	ABCD2_HT2_,  		//10-21
	ABCD2_HT3_,  		//10-21
	ABCD2_LeadCA8_Pt_,  		//10-21
	ABCD2_LeadSub_Pt_,  		//10-21
	ABCD2_LeadSub_CSV_,  		//10-21
	ABCD2_SubLeadSub_Pt_,  		//10-21
	ABCD2_SubLeadSub_CSV_,  		//10-21

	GenInfo_HiggsDaPdgID_,  	//11-06
	GenInfo_NumHiggsTobb_,  	//11-06
	GenInfo_NumHiggsToOther_,  	//11-06

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
	{ 0,	"ABCD1.HT1.CutRegion",			"",	"Cut Region", 			"Yields", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCD1.HT2.CutRegion",			"",	"Cut Region", 			"Yields", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCD1.HT3.CutRegion",			"",	"Cut Region", 			"Yields", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCD2.HT1.CutRegion",			"",	"Cut Region", 			"Yields", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCD2.HT2.CutRegion",			"",	"Cut Region", 			"Yields", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCD2.HT3.CutRegion",			"",	"Cut Region", 			"Yields", "", 		4, 0, 4}, 	//10-21

	{ 1,	"ABCD1.HT1", 				"",	"HT", 				"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 1,	"ABCD1.HT2", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 1,	"ABCD1.HT3", 				"",	"HT(4LeadAK5)", 		"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 1,	"ABCD1.LeadCA8.Pt", 			"",	"Leading CA8 Pt", 		"Yields", "", 		1500,  0, 1500}, 	//10-21
	{ 1,	"ABCD1.LeadSub.Pt", 			"",	"Leading subjet Pt", 		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-31
	{ 1,	"ABCD1.LeadSub.CSV", 			"",	"Leading subjet CSV", 		"Yields", "", 		110, 0, 1.1}, 	//10-21
	{ 1,	"ABCD1.SubLeadSub.Pt", 			"",	"Sub-Leading subjet Pt", 	"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-31
	{ 1,	"ABCD1.SubLeadSub.CSV", 		"",	"Sub-Leading subjet CSV", 	"Yields", "", 		110, 0, 1.1}, 	//10-21
	{ 1,	"ABCD2.HT1", 				"",	"HT", 				"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 1,	"ABCD2.HT2", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 1,	"ABCD2.HT3", 				"",	"HT(4LeadAK5)", 		"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 1,	"ABCD2.LeadCA8.Pt", 			"",	"Leading CA8 Pt", 		"Yields", "", 		1500,  0, 1500}, 	//10-21
	{ 1,	"ABCD2.LeadSub.Pt", 			"",	"Leading subjet Pt", 		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-31
	{ 1,	"ABCD2.LeadSub.CSV", 			"",	"Leading subjet CSV", 		"Yields", "", 		110, 0, 1.1}, 	//10-21
	{ 1,	"ABCD2.SubLeadSub.Pt", 			"",	"Sub-Leading subjet Pt", 	"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-31
	{ 1,	"ABCD2.SubLeadSub.CSV", 		"",	"Sub-Leading subjet CSV", 	"Yields", "", 		110, 0, 1.1}, 	//10-21

	{ 0,	"GenInfo.HiggsDaPdgID", 		"",	"PdgID", 			"Yields", "", 		52, -26, 26}, 	//11-06
	{ 0,	"GenInfo.NumHiggsTobb", 		"",	"Number", 			"Yields", "", 		3, 0, 3}, 	//11-06
	{ 0,	"GenInfo.NumHiggsToOther", 		"",	"Number", 			"Yields", "", 		3, 0, 3}, 	//11-06

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
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCD1_HT1_ 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCD1_HT2_ 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCD1_HT3_ 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCD2_HT1_ 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCD2_HT2_ 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCD2_HT3_ 	//10-21

	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCD1_HT1_		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCD1_HT2_		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCD1_HT3_		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCD1_LeadCA8_Pt_
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCD1_LeadSub_Pt_	//10-31
	{1,0.20,0.70,0.40,0.90,"l", 1.3, -1111,   0.01, -1111, -1111, 5},		//ABCD1_LeadSub_CSV_ 	//10-31
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCD1_SubLeadSub_Pt_	//10-31
	{1,0.20,0.70,0.40,0.90,"l", 1.3, -1111,   0.01, -1111, -1111, 5},		//ABCD1_SubLeadSub_CSV_ 	//10-31
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCD2_HT1_		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCD2_HT2_		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCD2_HT3_		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCD2_LeadCA8_Pt_
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCD2_LeadSub_Pt_	//10-31
	{1,0.20,0.70,0.40,0.90,"l", 1.3, -1111,   0.01, -1111, -1111, 5},		//ABCD2_LeadSub_CSV_ 	//10-31
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCD2_SubLeadSub_Pt_	//10-31
	{1,0.20,0.70,0.40,0.90,"l", 1.3, -1111,   0.01, -1111, -1111, 5},		//ABCD2_SubLeadSub_CSV_ 	//10-31

	{0,0.65,0.65,0.85,0.85,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//GenInfo_HiggsDaPdgID_ 	//11-06
	{0,0.65,0.65,0.85,0.85,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//GenInfo_NumHiggsTobb_ 	//11-06
	{0,0.65,0.65,0.85,0.85,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//GenInfo_NumHiggsToOther_ 	//11-06
};


/////// Set Struct of All variables(TH2F) //////=========================================================================================================================
enum th2flist_{
	ABCD1_HT1_2D_, 				//01-13
	ABCD1_HT2_2D_, 				//01-13
	ABCD1_HT3_2D_, 				//01-13
	ABCD2_HT1_2D_, 				//01-13
	ABCD2_HT2_2D_, 				//01-13
	ABCD2_HT3_2D_, 				//01-13
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
	{ 1, "ABCD1.2D.HT1",			"",	"HT",		"CSV of leading SubJet",	"GeV/c", "",	2000, 0, 2000, 105, 0, 1.05}, //06-06
	{ 1, "ABCD1.2D.HT2",			"",	"HT(AK5)",	"CSV of leading SubJet",	"GeV/c", "",	2000, 0, 2000, 105, 0, 1.05}, //06-06
	{ 1, "ABCD1.2D.HT3",			"",	"HT(4LeadAK5)",	"CSV of leading SubJet", 	"GeV/c", "",	2000, 0, 2000, 105, 0, 1.05}, //06-06
	{ 1, "ABCD2.2D.HT1",			"",	"HT",		"CSV of sub-leading SubJet",	"GeV/c", "",	2000, 0, 2000, 105, 0, 1.05}, //06-06
	{ 1, "ABCD2.2D.HT2",			"",	"HT(AK5)",	"CSV of sub-leading SubJet",	"GeV/c", "",	2000, 0, 2000, 105, 0, 1.05}, //06-06
	{ 1, "ABCD2.2D.HT3",			"",	"HT(4LeadAK5)",	"CSV of sub-leading SubJet", 	"GeV/c", "",	2000, 0, 2000, 105, 0, 1.05}, //06-06
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
	{0, 10, 5, ABCD1_xCut, ABCD1_yCut, 0, -1111, 0, -1111, 1, -1111},	//ABCD1_HT1_ 	//01-13
	{0, 10, 5, ABCD1_xCut, ABCD1_yCut, 0, -1111, 0, -1111, 1, -1111},	//ABCD1_HT2_ 	//01-13
	{0, 10, 5, ABCD1_xCut, ABCD1_yCut, 0, -1111, 0, -1111, 1, -1111},	//ABCD1_HT3_ 	//01-13
	{0, 10, 5, ABCD1_xCut, ABCD1_yCut, 0, -1111, 0, -1111, 1, -1111},	//ABCD2_HT1_ 	//01-13
	{0, 10, 5, ABCD1_xCut, ABCD1_yCut, 0, -1111, 0, -1111, 1, -1111},	//ABCD2_HT2_ 	//01-13
	{0, 10, 5, ABCD1_xCut, ABCD1_yCut, 0, -1111, 0, -1111, 1, -1111},	//ABCD2_HT3_ 	//01-13
};

#endif
