/////// Set Struct of All variables(TH1F) //////====================================================================================
enum th1flist_{
	Event_NumEvtCutFlow_, 	 	//10-21
	Event_NumSelectAK5Jets_,  	//10-21
	Event_NumSelectCA8Jets_,  	//10-21
	Event_NumbJets_,  		//10-21
	Event_NumHiggsJets_, 	 	//10-21
	Event_Ht_bJets_HiggsJets_,  	//10-21

	Gen_Higgs_Pt_,  		//10-21
	Gen_MatchedHiggs_Pt_,  		//10-21

	AK5Jet_SelectAK5_Pt_,	  	//10-21
	AK5Jet_SelectAK5_Eta_,  	//10-21
	AK5Jet_SelectAK5_Phi_,  	//10-21
	AK5Jet_SelectAK5_Mass_,  	//10-21
	AK5Jet_SelectAK5_CSV_,  	//10-21

	CA8Jet_SelectCA8_Pt_,  		//10-21
	CA8Jet_SelectCA8_Eta_,  	//10-21
	CA8Jet_SelectCA8_Phi_,  	//10-21
	CA8Jet_SelectCA8_Mass_,  	//10-21
	CA8Jet_SelectCA8_MassPruned_,  	//10-21
	CA8Jet_SelectCA8_CSV_,  	//10-21
	CA8Jet_SelectCA8_Tau2ByTau1_,  	//10-21
	CA8Jet_SelectCA8_Tau3ByTau2_,  	//10-21
	CA8Jet_SelectCA8_Tau3ByTau1_,  	//10-21

	SubJet1_SelectCA8Sub_Pt_,  	//10-21
	SubJet1_SelectCA8Sub_Eta_,  	//10-21
	SubJet1_SelectCA8Sub_Phi_,  	//10-21
	SubJet1_SelectCA8Sub_Mass_,  	//10-21
	SubJet1_SelectCA8Sub_CSV_,  	//10-21
	SubJet2_SelectCA8Sub_Pt_,  	//10-21
	SubJet2_SelectCA8Sub_Eta_,  	//10-21
	SubJet2_SelectCA8Sub_Phi_,  	//10-21
	SubJet2_SelectCA8Sub_Mass_,  	//10-21
	SubJet2_SelectCA8Sub_CSV_,  	//10-21

	bJet_Pt_,  			//10-21
	bJet_Eta_,  			//10-21
	bJet_Phi_, 		 	//10-21
	bJet_Mass_, 		 	//10-21
	bJet_CSV_, 		 	//10-21

	HiggsJet_Pt_, 		 	//10-21
	HiggsJet_Eta_,  		//10-21
	HiggsJet_Phi_,  		//10-21
	HiggsJet_Mass_,  		//10-21

	bprime_Pt_, 		 	//10-21
	bprime_Eta_,  			//10-21
	bprime_Phi_, 		 	//10-21
	bprime_Mass_, 		 	//10-21

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
	{ 1,	"Event.NumEvtCutFlow", 		"",	"Evt Select", 			"Events", "", 		5, 0, 5}, 	//10-21
	{ 0,	"Event.NumSelectAK5Jets", 	"",	"Number of Selected AK5",	"Events", "", 		15, 0, 15}, 	//10-21
	{ 0,	"Event.NumSelectCA8Jets", 	"",	"Number of Selected CA8",	"Events", "", 		15, 0, 15}, 	//10-21
	{ 0,	"Event.NumbJets", 		"",	"Number of bJet", 		"Events", "", 		15, 0, 15}, 	//10-21
	{ 0,	"Event.NumHiggsJets", 		"",	"Number of HiggsJets", 		"Events", "", 		15, 0, 15}, 	//10-21
	{ 1,	"Event.Ht.bJets.HiggsJets", 	"",	"Ht(b,Higgs)", 			"Yields", "GeV/c", 	4000, 0, 4000}, 	//10-21

	{ 0,	"Gen.Higgs.Pt", 		"",	"Pt", 				"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 0,	"Gen.MatchedHiggs.Pt", 		"",	"Pt", 				"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21

	{ 0,	"AK5Jet.SelectAK5.Pt", 		"",	"Pt", 				"Yields", "GeV", 	2000, 0, 2000}, 	//10-21
	{ 0,	"AK5Jet.SelectAK5.Eta", 	"",	"#eta", 			"Yields", "", 		100,  -5,  5}, 	//10-21
	{ 0,	"AK5Jet.SelectAK5.Phi", 	"",	"#phi", 			"Yields", "", 		80,   -4,  4}, 	//10-21
	{ 0,	"AK5Jet.SelectAK5.Mass", 	"",	"Mass", 			"Yields", "GeV/c^{2}", 	500,   0,  50}, 	//10-21
	{ 0,	"AK5Jet.SelectAK5.CSV", 	"",	"CSV discriminator", 		"Yields", "", 		100,   0,  1}, 	//10-21

	{ 0,	"CA8Jet.SelectCA8.Pt", 		"",	"Pt",				"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 0,	"CA8Jet.SelectCA8.Eta", 	"",	"#eta", 			"Yields", "", 		100,  -5,  5}, 	//10-21
	{ 0,	"CA8Jet.SelectCA8.Phi", 	"",	"#phi", 			"Yields", "", 		80,   -4,  4}, 	//10-21
	{ 0,	"CA8Jet.SelectCA8.Mass", 	"",	"Mass", 			"Yields", "GeV/c^{2}", 	2000,  0, 200}, 	//10-21
	{ 0,	"CA8Jet.SelectCA8.MassPruned", 	"",	"Mass", 			"Yields", "GeV/c^{2}", 	2000,  0, 200}, 	//10-21
	{ 0,	"CA8Jet.SelectCA8.CSV", 	"",	"CSV discriminator", 		"Yields", "", 		100,   0,  1}, 	//10-21
	{ 0,	"CA8Jet.SelectCA8.Tau2ByTau1", 	"",	"#tau2/#tau1", 			"Yields", "", 		20,    0.,1.}, 	//10-21
	{ 0,	"CA8Jet.SelectCA8.Tau3ByTau2", 	"",	"#tau3/#tau2", 			"Yields", "", 		20,	0.,1.}, 	//10-21
	{ 0,	"CA8Jet.SelectCA8.Tau3ByTau1", 	"",	"#tau3/#tau1", 			"Yields", "", 		20,	0.,1.}, 	//10-21

	{ 0,	"SubJet1.SelectCA8Sub.Pt", 	"",	"Pt", 				"Yields", "GeV/c", 	1000, 0, 1000}, 	//10-21
	{ 0,	"SubJet1.SelectCA8Sub.Eta", 	"",	"#eta", 			"Yields", "", 		100,  -5,  5}, 	//10-21
	{ 0,	"SubJet1.SelectCA8Sub.Phi", 	"",	"#phi", 			"Yields", "", 		80,   -4,  4}, 	//10-21
	{ 0,	"SubJet1.SelectCA8Sub.Mass", 	"",	"Mass", 			"Yields", "GeV/c^{2}", 2000,  0, 200}, 	//10-21
	{ 0,	"SubJet1.SelectCA8Sub.CSV", 	"",	"CSV discriminator", 		"Yields", "", 		100,   0,  1}, 	//10-21
	{ 0,	"SubJet2.SelectCA8Sub.Pt", 	"",	"Pt", 				"Yields", "GeV/c", 	1000, 0, 1000}, 	//10-21
	{ 0,	"SubJet2.SelectCA8Sub.Eta", 	"",	"#eta", 			"Yields", "", 		100,  -5,  5}, 	//10-21
	{ 0,	"SubJet2.SelectCA8Sub.Phi", 	"",	"#phi", 			"Yields", "", 		80,   -4,  4}, 	//10-21
	{ 0,	"SubJet2.SelectCA8Sub.Mass", 	"",	"Mass", 			"Yields", "GeV/c^{2}", 2000,  0, 200}, 	//10-21
	{ 0,	"SubJet2.SelectCA8Sub.CSV", 	"",	"CSV discriminator", 		"Yields", "", 		100,   0,  1}, 	//10-21

	{ 1,	"bJet.Pt", 			"",	"Pt", 				"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 1,	"bJet.Eta", 			"",	"#eta", 			"Yields", "", 		100,  -5,  5}, 	//10-21
	{ 1,	"bJet.Phi", 			"",	"#phi", 			"Yields", "", 		80,   -4,  4}, 	//10-21
	{ 1,	"bJet.Mass", 			"",	"Mass", 			"Yields", "GeV/c^{2}", 500,   0,  50}, 	//10-21
	{ 1,	"bJet.CSV", 			"",	"CSV discriminator", 		"Yields", "", 		100,   0,  1}, 	//10-21

	{ 1,	"HiggsJet.Pt", 			"",	"Pt", 				"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 1,	"HiggsJet.Eta", 		"",	"#eta", 			"Yields", "", 		100,  -5,  5}, 	//10-21
	{ 1,	"HiggsJet.Phi", 		"",	"#phi", 			"Yields", "", 		80,   -4,  4}, 	//10-21
	{ 1,	"HiggsJet.Mass", 		"",	"Mass", 			"Yields", "GeV/c^{2}", 2000,  0, 200}, 	//10-21

	{ 1,	"bprime.Pt", 			"",	"Pt", 				"Yields", "GeV/c", 	2000, 0, 2000}, 	//10-21
	{ 1,	"bprime.Eta", 			"",	"#eta", 			"Yields", "", 		100,  -5,  5}, 	//10-21
	{ 1,	"bprime.Phi", 			"",	"#phi", 			"Yields", "", 		80,   -4,  4}, 	//10-21
	{ 1,	"bprime.Mass", 			"",	"Mass", 			"Yields", "GeV/c^{2}", 2000, 0, 2000}, 	//10-21
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
	{1,0.70,0.70,0.90,0.90,"l", 1.3, -1111,  0.01, -1111, -1111, 1},		//Event_NumEvtCutFlow_ 		//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//Event_NumSelectAK5Jets_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//Event_NumSelectCA8Jets_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//Event_NumbJets_ 		//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//Event_NumHiggsJets_ 		//10-21
	{1,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111,  500,  2000, 200},		//Event_Ht_bJets_HiggsJets_ 	//10-21
	
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//Gen_Higgs_Pt_ 		//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//Gen_MatchedHiggs_Pt_ 		//10-21

	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//AK5Jet_SelectAK5_Pt_ 		//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//AK5Jet_SelectAK5_Eta_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//AK5Jet_SelectAK5_Phi_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//AK5Jet_SelectAK5_Mass_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//AK5Jet_SelectAK5_CSV_ 	//10-21

	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Jet_SelectCA8_Pt_ 		//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Jet_SelectCA8_Eta_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Jet_SelectCA8_Phi_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Jet_SelectCA8_Mass_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Jet_SelectCA8_MassPruned_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Jet_SelectCA8_CSV_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Jet_SelectCA8_Tau2ByTau1_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Jet_SelectCA8_Tau3ByTau2_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Jet_SelectCA8_Tau3ByTau1_ 	//10-21

	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//SubJet1_SelectCA8Sub_Pt_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//SubJet1_SelectCA8Sub_Eta_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//SubJet1_SelectCA8Sub_Phi_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//SubJet1_SelectCA8Sub_Mass_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//SubJet1_SelectCA8Sub_CSV_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//SubJet2_SelectCA8Sub_Pt_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//SubJet2_SelectCA8Sub_Eta_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//SubJet2_SelectCA8Sub_Phi_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//SubJet2_SelectCA8Sub_Mass_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//SubJet2_SelectCA8Sub_CSV_ 	//10-21

	{1,0.70,0.70,0.90,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//bJet_Pt_ 		//10-21
	{1,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, 	3, -3, 5},			//bJet_Eta_ 		//10-21
	{1,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 5},		//bJet_Phi_ 		//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//bJet_Mass_ 		//10-21
	{1,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, 	0.5, 1},		//bJet_CSV_ 		//10-21

	{1,0.70,0.70,0.90,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//HiggsJet_Pt_	 	//10-21
	{1,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, 	3, 	-3, 5},			//HiggsJet_Eta_ 	//10-21
	{1,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 5},		//HiggsJet_Phi_ 	//10-21
	{1,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//HiggsJet_Mass_ 	//10-21

	{1,0.70,0.70,0.90,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//bprime_Pt_ 	//10-21
	{1,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, 	3, 	-3, 5},			//bprime_Eta_ 	//10-21
	{1,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 5},		//bprime_Phi_ 	//10-21
	{0,0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//bprime_Mass_ 	//10-21
};


/////// Set Struct of All variables(TH2F) //////=========================================================================================================================
enum th2flist_{
	EvtInfo_HtAK5_BpMass_, 				//06-06
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
	{ 0, "HtAK5CA8.LeadingSubCSV",	"",	"Ht","CSV-dis.", 	"GeV/c", "",	1500, 0, 1500, 100, 0, 1}, //06-06
};


struct Other2Info_{
	bool logZ;
	int xrebin;
	int yrebin;
	float SetXMin;	//SetXaxis min
	float SetXMax;	//SetXaxis max
	float SetYMin;	//SetYaxis min
	float SetYMax;	//SetYaxis max
	float SetZMin;	//SetZaxis max
	float SetZMax;	//SetZaxis max
};

struct Other2Info_ Other2Info[th2_size_] = {
	{0, 10, 10, 0, -1111, 0, -1111, 0, -1111},	//EvtInfo_HtAK5_BpMass_ 	//06-06
};

