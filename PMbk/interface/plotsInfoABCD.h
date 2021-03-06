#ifndef PLOTSINFOABCD_H
#define PLOTSINFOABCD_H

#include "selection.h"

/////// Set Struct of All variables(TH1F) //////====================================================================================
enum th1flist_{
	ABCDana_CutFlow_, 		//01-13
	ABCDval_CutFlow_, 		//01-13

	ABCDana_CutRegion_, 		//01-13
	ABCDval_CutRegion_, 		//01-13

	ABCDana_Sumw2_A,
	ABCDana_Sumw2_B,
	ABCDana_Sumw2_C,
	ABCDana_Sumw2_D,
	ABCDval_Sumw2_A,
	ABCDval_Sumw2_B,
	ABCDval_Sumw2_C,
	ABCDval_Sumw2_D,

	ABCDana_NumCA8_A,
	ABCDana_NumCA8_B,
	ABCDana_NumCA8_C,
	ABCDana_NumCA8_D,
	ABCDana_HT_,  		//10-21
	ABCDana_HT_A,  		//10-21
	ABCDana_HT_B,  		//10-21
	ABCDana_HT_C,  		//10-21
	ABCDana_HT_D,  		//10-21
	ABCDana_HiggsMass_A,  		//10-21
	ABCDana_HiggsMass_B,  		//10-21
	ABCDana_HiggsMass_C,  		//10-21
	ABCDana_HiggsMass_D,  		//10-21
	ABCDana_CA8Pt_A, 	//10-21
	ABCDana_CA8Pt_B, 	//10-21
	ABCDana_CA8Pt_C, 	//10-21
	ABCDana_CA8Pt_D, 	//10-21
	ABCDana_CA8PrMass_A, 	//10-21
	ABCDana_CA8PrMass_B, 	//10-21
	ABCDana_CA8PrMass_C, 	//10-21
	ABCDana_CA8PrMass_D, 	//10-21
	ABCDana_dRSubJets_A, 	//10-21
	ABCDana_dRSubJets_B, 	//10-21
	ABCDana_dRSubJets_C, 	//10-21
	ABCDana_dRSubJets_D, 	//10-21
	ABCDana_Tau2ByTau1_A, 	//10-21
	ABCDana_Tau2ByTau1_B, 	//10-21
	ABCDana_Tau2ByTau1_C, 	//10-21
	ABCDana_Tau2ByTau1_D, 	//10-21
	ABCDana_Sub1Pt_A, 	//10-21
	ABCDana_Sub1Pt_B, 	//10-21
	ABCDana_Sub1Pt_C, 	//10-21
	ABCDana_Sub1Pt_D, 	//10-21
	ABCDana_Sub2Pt_A, 	//10-21
	ABCDana_Sub2Pt_B, 	//10-21
	ABCDana_Sub2Pt_C, 	//10-21
	ABCDana_Sub2Pt_D, 	//10-21
	ABCDana_Sub1Mass_A, 	//10-21
	ABCDana_Sub1Mass_B, 	//10-21
	ABCDana_Sub1Mass_C, 	//10-21
	ABCDana_Sub1Mass_D, 	//10-21
	ABCDana_Sub2Mass_A, 	//10-21
	ABCDana_Sub2Mass_B, 	//10-21
	ABCDana_Sub2Mass_C, 	//10-21
	ABCDana_Sub2Mass_D, 	//10-21
	ABCDana_Sub1CSV_A, 	//10-21
	ABCDana_Sub1CSV_B, 	//10-21
	ABCDana_Sub1CSV_C, 	//10-21
	ABCDana_Sub1CSV_D, 	//10-21
	ABCDana_Sub2CSV_A, 	//10-21
	ABCDana_Sub2CSV_B, 	//10-21
	ABCDana_Sub2CSV_C, 	//10-21
	ABCDana_Sub2CSV_D, 	//10-21
	ABCDana_JetFlavor_A,  		//10-21
	ABCDana_JetFlavor_B,  		//10-21
	ABCDana_JetFlavor_C,  		//10-21
	ABCDana_JetFlavor_D,  		//10-21
	ABCDana_HiggsMass_,  		//10-21
	ABCDana_JetFlavor_,  		//10-21
	ABCDana_LeadCA8_Pt_,  		//10-21

	ABCDval_NumCA8_A,
	ABCDval_NumCA8_B,
	ABCDval_NumCA8_C,
	ABCDval_NumCA8_D,
	ABCDval_HT_,  		//10-21
	ABCDval_HT_A,  		//10-21
	ABCDval_HT_B,  		//10-21
	ABCDval_HT_C,  		//10-21
	ABCDval_HT_D,  		//10-21
	ABCDval_HiggsMass_A,  		//10-21
	ABCDval_HiggsMass_B,  		//10-21
	ABCDval_HiggsMass_C,  		//10-21
	ABCDval_HiggsMass_D,  		//10-21
	ABCDval_CA8Pt_A, 	//10-21
	ABCDval_CA8Pt_B, 	//10-21
	ABCDval_CA8Pt_C, 	//10-21
	ABCDval_CA8Pt_D, 	//10-21
	ABCDval_CA8PrMass_A, 	//10-21
	ABCDval_CA8PrMass_B, 	//10-21
	ABCDval_CA8PrMass_C, 	//10-21
	ABCDval_CA8PrMass_D, 	//10-21
	ABCDval_dRSubJets_A, 	//10-21
	ABCDval_dRSubJets_B, 	//10-21
	ABCDval_dRSubJets_C, 	//10-21
	ABCDval_dRSubJets_D, 	//10-21
	ABCDval_Tau2ByTau1_A, 	//10-21
	ABCDval_Tau2ByTau1_B, 	//10-21
	ABCDval_Tau2ByTau1_C, 	//10-21
	ABCDval_Tau2ByTau1_D, 	//10-21
	ABCDval_Sub1Pt_A, 	//10-21
	ABCDval_Sub1Pt_B, 	//10-21
	ABCDval_Sub1Pt_C, 	//10-21
	ABCDval_Sub1Pt_D, 	//10-21
	ABCDval_Sub2Pt_A, 	//10-21
	ABCDval_Sub2Pt_B, 	//10-21
	ABCDval_Sub2Pt_C, 	//10-21
	ABCDval_Sub2Pt_D, 	//10-21
	ABCDval_Sub1Mass_A, 	//10-21
	ABCDval_Sub1Mass_B, 	//10-21
	ABCDval_Sub1Mass_C, 	//10-21
	ABCDval_Sub1Mass_D, 	//10-21
	ABCDval_Sub2Mass_A, 	//10-21
	ABCDval_Sub2Mass_B, 	//10-21
	ABCDval_Sub2Mass_C, 	//10-21
	ABCDval_Sub2Mass_D, 	//10-21
	ABCDval_Sub1CSV_A, 	//10-21
	ABCDval_Sub1CSV_B, 	//10-21
	ABCDval_Sub1CSV_C, 	//10-21
	ABCDval_Sub1CSV_D, 	//10-21
	ABCDval_Sub2CSV_A, 	//10-21
	ABCDval_Sub2CSV_B, 	//10-21
	ABCDval_Sub2CSV_C, 	//10-21
	ABCDval_Sub2CSV_D, 	//10-21
	ABCDval_JetFlavor_A,  		//10-21
	ABCDval_JetFlavor_B,  		//10-21
	ABCDval_JetFlavor_C,  		//10-21
	ABCDval_JetFlavor_D,  		//10-21
	ABCDval_HiggsMass_,  		//10-21
	ABCDval_JetFlavor_,  		//10-21
	ABCDval_LeadCA8_Pt_,  		//10-21

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
	{ 0,	"ABCDana_CutFlow",			"",	"Cut flow", 			"Yields", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCDval_CutFlow",			"",	"Cut flow", 			"Yields", "", 		4, 0, 4}, 	//10-21
	
	{ 0,	"ABCDana_CutRegion",			"",	"Cut Region", 			"Yields", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCDval_CutRegion",			"",	"Cut Region", 			"Yields", "", 		4, 0, 4}, 	//10-21

	{ 0,	"ABCDana_Sumw2_A",			"",	"SumW2 for A", 			"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sumw2_B",			"",	"SumW2 for A", 			"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sumw2_C",			"",	"SumW2 for A", 			"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sumw2_D",			"",	"SumW2 for A", 			"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sumw2_A",			"",	"SumW2 for A", 			"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sumw2_B",			"",	"SumW2 for A", 			"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sumw2_C",			"",	"SumW2 for A", 			"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sumw2_D",			"",	"SumW2 for A", 			"Yields", "", 		1, 0, 1}, 	//10-21

	{ 0,	"ABCDana_NumCA8_A",			"",	"Num of CA8, A region", 	"Events", "", 		3, 1, 4}, 	//10-21
	{ 0,	"ABCDana_NumCA8_B",			"",	"Num of CA8, B region", 	"Events", "", 		3, 1, 4}, 	//10-21
	{ 0,	"ABCDana_NumCA8_C",			"",	"Num of CA8, C region", 	"Events", "", 		3, 1, 4}, 	//10-21
	{ 0,	"ABCDana_NumCA8_D",			"",	"Num of CA8, D region", 	"Events", "", 		3, 1, 4}, 	//10-21
	{ 0,	"ABCDana_HT", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDana_HT_A", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDana_HT_B", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDana_HT_C", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDana_HT_D", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDana_HiggsMass_A",		 	"",	"Pruned Mass(Higgs), A region",		"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_HiggsMass_B",	 		"",	"Pruned Mass(Higgs), B region",		"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_HiggsMass_C",		 	"",	"Pruned Mass(Higgs), C region",		"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_HiggsMass_D",	 		"",	"Pruned Mass(Higgs), D region",		"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_CA8Pt_A",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_CA8Pt_B",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_CA8Pt_C",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_CA8Pt_D",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_CA8PrMass_A",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_CA8PrMass_B",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_CA8PrMass_C",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_CA8PrMass_D",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_dRSubJets_A",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_dRSubJets_B",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_dRSubJets_C",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_dRSubJets_D",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Tau2ByTau1_A",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Tau2ByTau1_B",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Tau2ByTau1_C",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Tau2ByTau1_D",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sub1Pt_A",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_Sub1Pt_B",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_Sub1Pt_C",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_Sub1Pt_D",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_Sub2Pt_A",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_Sub2Pt_B",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_Sub2Pt_C",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_Sub2Pt_D",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_Sub1Mass_A",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_Sub1Mass_B",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_Sub1Mass_C",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_Sub1Mass_D",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_Sub2Mass_A",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_Sub2Mass_B",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_Sub2Mass_C",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_Sub2Mass_D",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_Sub1CSV_A",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sub1CSV_B",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sub1CSV_C",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sub1CSV_D",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sub2CSV_A",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sub2CSV_B",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sub2CSV_C",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sub2CSV_D",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_JetFlavor_A",	 	"",	"Jet Flavor, A region",		"Yields", "", 		50, -25, 25}, 	//10-21
	{ 0,	"ABCDana_JetFlavor_B",	 	"",	"Jet Flavor, B region",		"Yields", "", 		50, -25, 25}, 	//10-21
	{ 0,	"ABCDana_JetFlavor_C",	 	"",	"Jet Flavor, C region",		"Yields", "", 		50, -25, 25}, 	//10-21
	{ 0,	"ABCDana_JetFlavor_D",	 	"",	"Jet Flavor, D region",		"Yields", "", 		50, -25, 25}, 	//10-21
	{ 0,	"ABCDana_HiggsMass", 		"",	"Pruned Mass(Higgs)", 			"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_JetFlavor",	 	"",	"Jet Flavor",			"Yields", "", 		50, -25, 25}, 	//10-21
	{ 0,	"ABCDana_CA8Pt", 			"",	"CA8 Pt", 		"Yields", "GeV/c", 	1500,  0, 1500}, 	//10-21

	{ 0,	"ABCDval_NumCA8_A",			"",	"Num of CA8, A region", 	"Events", "", 		3, 1, 4}, 	//10-21
	{ 0,	"ABCDval_NumCA8_B",			"",	"Num of CA8, B region", 	"Events", "", 		3, 1, 4}, 	//10-21
	{ 0,	"ABCDval_NumCA8_C",			"",	"Num of CA8, C region", 	"Events", "", 		3, 1, 4}, 	//10-21
	{ 0,	"ABCDval_NumCA8_D",			"",	"Num of CA8, D region", 	"Events", "", 		3, 1, 4}, 	//10-21
	{ 0,	"ABCDval_HT", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDval_HT_A", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDval_HT_B", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDval_HT_C", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDval_HT_D", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDval_HiggsMass_A",		 	"",	"Pruned Mass(Higgs), A region",		"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_HiggsMass_B",	 		"",	"Pruned Mass(Higgs), B region",		"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_HiggsMass_C",		 	"",	"Pruned Mass(Higgs), C region",		"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_HiggsMass_D",	 		"",	"Pruned Mass(Higgs), D region",		"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_CA8Pt_A",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_CA8Pt_B",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_CA8Pt_C",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_CA8Pt_D",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_CA8PrMass_A",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_CA8PrMass_B",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_CA8PrMass_C",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_CA8PrMass_D",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_dRSubJets_A",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_dRSubJets_B",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_dRSubJets_C",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_dRSubJets_D",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Tau2ByTau1_A",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Tau2ByTau1_B",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Tau2ByTau1_C",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Tau2ByTau1_D",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sub1Pt_A",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_Sub1Pt_B",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_Sub1Pt_C",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_Sub1Pt_D",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_Sub2Pt_A",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_Sub2Pt_B",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_Sub2Pt_C",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_Sub2Pt_D",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_Sub1Mass_A",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_Sub1Mass_B",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_Sub1Mass_C",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_Sub1Mass_D",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_Sub2Mass_A",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_Sub2Mass_B",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_Sub2Mass_C",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_Sub2Mass_D",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_Sub1CSV_A",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sub1CSV_B",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sub1CSV_C",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sub1CSV_D",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sub2CSV_A",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sub2CSV_B",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sub2CSV_C",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sub2CSV_D",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_JetFlavor_A",	 	"",	"Jet Flavor, A region",		"Yields", "", 		50, -25, 25}, 	//10-21
	{ 0,	"ABCDval_JetFlavor_B",	 	"",	"Jet Flavor, B region",		"Yields", "", 		50, -25, 25}, 	//10-21
	{ 0,	"ABCDval_JetFlavor_C",	 	"",	"Jet Flavor, C region",		"Yields", "", 		50, -25, 25}, 	//10-21
	{ 0,	"ABCDval_JetFlavor_D",	 	"",	"Jet Flavor, D region",		"Yields", "", 		50, -25, 25}, 	//10-21
	{ 0,	"ABCDval_HiggsMass", 		"",	"Pruned Mass(Higgs)", 			"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_JetFlavor",	 	"",	"Jet Flavor",			"Yields", "", 		50, -25, 25}, 	//10-21
	{ 0,	"ABCDval_CA8Pt", 			"",	"CA8 Pt", 		"Yields", "GeV/c", 	1500,  0, 1500}, 	//10-21

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
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_CutFlow_ 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_CutFlow_ 	//10-21

	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_CutRegio 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_CutRegio 	//10-21

	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_Sumw2 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_Sumw2 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_Sumw2 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_Sumw2 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_Sumw2 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_Sumw2 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_Sumw2 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_Sumw2 	//10-21

	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_NumCA8_A 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_NumCA8_B 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_NumCA8_C 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_NumCA8_D 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_JetFlavor_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_JetFlavor_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_JetFlavor_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_JetFlavor_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDana_HiggsMass_		 //10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDana_JetFlavor_		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//abcd1_LeadCA8_Pt_

	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDval_NumCA8_A 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDval_NumCA8_B 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDval_NumCA8_C 	//10-21
	{0,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDval_NumCA8_D 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDval_JetFlavor_A		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDval_JetFlavor_B		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDval_JetFlavor_C		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDval_JetFlavor_D		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//ABCDval_HiggsMass_		 //10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//ABCDval_JetFlavor_		 	//10-21
	{1,0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//abcd2_LeadCA8_Pt_

	{0,0.65,0.65,0.85,0.85,"l", 1.3, -1111, -1111, -1111, -1111, 10},		//GenInfo_HiggsDaPdgID_ 	//11-06
	{0,0.65,0.65,0.85,0.85,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//GenInfo_HiggsDaPdgID_ 	//11-06
	{0,0.65,0.65,0.85,0.85,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//GenInfo_NumHiggsTobb_ 	//11-06
	{0,0.65,0.65,0.85,0.85,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//GenInfo_NumHiggsToOther_ 	//11-06
};


/////// Set Struct of All variables(TH2F) //////=========================================================================================================================
enum th2flist_{
	ABCDana_2D_, 				//01-13
	ABCDval_2D_, 				//01-13
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
	{ 1, "ABCDana_2D",			"",	"",	"Pruned Mass(Higgs)", 		"", "GeV/c^{2}",	2, 0, 2, 151, 0, 151,}, //06-06
	{ 1, "ABCDval_2D",			"",	"",	"Pruned Mass(Higgs)", 		"", "GeV/c^{2}",	2, 0, 2, 151, 0, 151,}, //06-06
};


struct Other2Info_{
	bool logZ;
	int xrebin;
	int yrebin;
	float xCut;	//SetXaxis min
	float yCut;	//SetXaxis max
	float yCut2;	//SetXaxis max
	float SetXMin;	//SetXaxis min
	float SetXMax;	//SetXaxis max
	float SetYMin;	//SetYaxis min
	float SetYMax;	//SetYaxis max
	float SetZMin;	//SetZaxis max
	float SetZMax;	//SetZaxis max
};

struct Other2Info_ Other2Info[th2_size_] = {
	{0, 1, 2, ABCD1_xCut, ABCD1_yCut, ABCD1_yCutLow, 0, -1111, 0, 140, 1, -1111},	//ABCDana_HT_ 	//01-13
	{0, 1, 2, ABCD1_xCut, ABCD1_yCut, ABCD1_yCutLow, 0, -1111, 0, 140, 1, -1111},	//ABCDval_HT_ 	//01-13
};

#endif
