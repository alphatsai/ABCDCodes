/////// Set Struct of All variables(TH1F) //////====================================================================================
enum th1flist_{
	EvtInfo_NumRestEvt_Ht_,  	//08-20
	EvtInfo_NumRestEvt_Ht_GAK5_,  	//08-29
	EvtInfo_NumRestEvt_Ht_GbAK5_,  	//08-20
	EvtInfo_NumRestEvt_Ht_GbAK5_GCA8_,  	//08-29
	EvtInfo_NumRestEvt_Ht_GbAK5_G2bCA8_,  	//08-20
	EvtInfo_NumRestEvt_Ht_GbAK5_G2bCA8_dR_,  	//08-20
	EvtInfo_NumAK5_,  			//06-06
	EvtInfo_NumAK5_b_, 	 		//06-06
	EvtInfo_NumAK5_Select_, 	 	//06-06
	EvtInfo_NumAK5_Select_b_,  		//06-06
	EvtInfo_NumCA8_,  			//06-06
	EvtInfo_NumCA8_2b_,  			//06-06
	EvtInfo_NumCA8_Select_,  		//06-06
	EvtInfo_NumCA8_Select_2b_,  		//06-06
	EvtInfo_HtAK5_,  	//06-06
	EvtInfo_HtAK5_b_,  	//06-06
	EvtInfo_HtAK5_Select_,  	//06-06
	EvtInfo_HtAK5_Select_b_,  	//06-06
	EvtInfo_dR_AK5CA8_,  			//06-06
	EvtInfo_dR_AK5CA8_BpSelect_,  	//06-06
	EvtInfo_dPhi_AK5CA8_,  	//08-29
	EvtInfo_dPhi_AK5CA8_BpSelect_,  	//08-29
	EvtInfo_BpMass_, 	 		//06-06
	EvtInfo_BpMass_BpSelect_,  	//06-06

	AK5Info_bTag_,  	//06-06
	AK5Info_Pt_, 	 			//06-06
	AK5Info_Eta_,	  			//06-06
	AK5Info_Phi_,  				//06-06
	AK5Info_Mass_,	  			//06-06
	AK5Info_b_bTag_,  	//06-06
	AK5Info_b_Pt_,		  		//06-06
	AK5Info_b_Eta_, 		 	//06-06
	AK5Info_b_Phi_, 	 		//06-06
	AK5Info_b_Mass_,		  	//06-06
	AK5Info_Select_bTag_,  	//06-06
	AK5Info_Select_Pt_, 		 	//06-06
	AK5Info_Select_Eta_,	  	//06-06
	AK5Info_Select_Phi_,  		//06-06
	AK5Info_Select_Mass_,	  	//06-06
	AK5Info_Select_b_bTag_,  	//06-06
	AK5Info_Select_b_Pt_,  		//06-06
	AK5Info_Select_b_Eta_,  	//06-06
	AK5Info_Select_b_Phi_,  	//06-06
	AK5Info_Select_b_Mass_,  	//06-06
	AK5Info_BpSelect_bTag_,  	//06-06
	AK5Info_BpSelect_Pt_,  	//06-06
	AK5Info_BpSelect_Eta_,  	//06-06
	AK5Info_BpSelect_Phi_,  	//06-06
	AK5Info_BpSelect_Mass_,  	//06-06

	CA8Info_2bTag_,  	//06-06
	CA8Info_Pt_,		  	//06-06
	CA8Info_Eta_,  			//06-06
	CA8Info_Phi_,  			//06-06
	CA8Info_Mass_,  		//06-06
	CA8Info_2b_2bTag_,  	//06-06
	CA8Info_2b_Pt_,  		//06-06
	CA8Info_2b_Eta_,  		//06-06
	CA8Info_2b_Phi_,  		//06-06
	CA8Info_2b_Mass_,  		//06-06
	CA8Info_Select_2bTag_,  	//06-06
	CA8Info_Select_Pt_,  		//06-06
	CA8Info_Select_Eta_,	  	//06-06
	CA8Info_Select_Phi_,  		//06-06
	CA8Info_Select_Mass_, 	 	//06-06
	CA8Info_Select_2b_2bTag_,  	//06-06
	CA8Info_Select_2b_Pt_,  	//06-06
	CA8Info_Select_2b_Eta_,  	//06-06
	CA8Info_Select_2b_Phi_,  	//06-06
	CA8Info_Select_2b_Mass_,  	//06-06
	CA8Info_BpSelect_2bTag_,  	//06-06
	CA8Info_BpSelect_Pt_,  	//06-06
	CA8Info_BpSelect_Eta_,  	//06-06
	CA8Info_BpSelect_Phi_,  	//06-06
	CA8Info_BpSelect_Mass_,  	//06-06
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
	{ 0,	"EvtInfo.NumRestEvt.Ht", 		"",	"Pass(F/T)", 	"Events", 	"",	 2, 0, 2}, 	//08-20
	{ 0,	"EvtInfo.NumRestEvt.Ht.GAK5", 		"",	"Pass(F/T)", 	"Events", 	"",	 2, 0, 2}, 	//08-29
	{ 0,	"EvtInfo.NumRestEvt.Ht.GbAK5", 		"",	"Pass(F/T)", 	"Events", 	"",	 2, 0, 2}, 	//08-20
	{ 0,	"EvtInfo.NumRestEvt.Ht.GbAK5.GCA8",	"",	"Pass(F/T)", 	"Events", 	"",	 2, 0, 2}, 	//08-29
	{ 0,	"EvtInfo.NumRestEvt.Ht.GbAK5.G2bCA8",	"",	"Pass(F/T)", 	"Events", 	"",	 2, 0, 2}, 	//08-20
	{ 0,	"EvtInfo.NumRestEvt.Ht.GbAK5.G2bCA8.dR","",	"Pass(F/T)", 	"Events", 	"",	 2, 0, 2}, 	//08-20
	{ 0,	"EvtInfo.NumAK5", 			"",	"Number of AK5", "Events", 	"",	15, 0, 15}, 	//06-06
	{ 0,	"EvtInfo.NumAK5.b", 			"",	"Number of AK5", "Events", 	"",	15, 0, 15}, 	//06-06
	{ 0,	"EvtInfo.NumAK5.Select", 		"",	"Number of AK5", "Events", 	"", 	15, 0, 15}, 	//06-06
	{ 1,	"EvtInfo.NumAK5.Select.b", 		"",	"Number of AK5", "Events", 	"", 	15, 0, 15}, 	//06-06
	{ 0,	"EvtInfo.NumCA8", 			"",	"Number of CA8", "Events", 	"", 	15, 0, 15}, 	//06-06
	{ 0,	"EvtInfo.NumCA8.2b", 			"",	"Number of CA8", "Events", 	"", 	15, 0, 15}, 	//06-06
	{ 0,	"EvtInfo.NumCA8.Select", 		"",	"Number of CA8", "Events", 	"", 	15, 0, 15}, 	//06-06
	{ 1,	"EvtInfo.NumCA8.Select.2b", 		"",	"Number of CA8", "Events", 	"", 	15, 0, 15}, 	//06-06
	{ 0,	"EvtInfo.HtAK5", 			"",	"Ht", 		 "Yields", "GeV/c", 	4000, 0, 4000}, 	//06-06
	{ 0,	"EvtInfo.HtAK5.b", 			"",	"Ht", 		 "Yields", "GeV/c", 	4000, 0, 4000}, 	//06-06
	{ 0,	"EvtInfo.HtAK5.Select", 		"",	"Ht", 		 "Yields", "GeV/c", 	4000, 0, 4000}, 	//06-06
	{ 0,	"EvtInfo.HtAK5.Select.b", 		"",	"Ht", 		 "Yields", "GeV/c", 	4000, 0, 4000}, 	//06-06
	{ 0,	"EvtInfo.dR.AK5CA8", 			"",	"dR(CA8,AK5)",   "Yields", 	"", 	30, 0, 3}, 	//06-06
	{ 1,	"EvtInfo.dR.AK5CA8.BpSelect",		"",	"dR(CA8,AK5)",   "Yields", 	"", 	30, 0, 3}, 	//06-06
	{ 0,	"EvtInfo.dPhi.AK5CA8", 			"",	"dPhi(CA8,AK5)", "Yields", 	"",  	35, 0, 3.5}, 	//08-29
	{ 0,	"EvtInfo.dPhi.AK5CA8.BpSelect", 	"",	"dPhi(CA8,AK5)", "Yields", 	"",  	35, 0, 3.5}, 	//08-29
	{ 0,	"EvtInfo.BpMass", 			"",	"Inv. Mass",  "Yields", "GeV/c^{2}", 2000, 0, 2000}, 	//06-06
	{ 1,	"EvtInfo.BpMass.BpSelect", 		"",	"Inv. Mass",  "Yields", "GeV/c^{2}", 2000, 0, 2000}, 	//06-06

	{ 0,	"AK5Info.bTag",		 		"",	"CSV b-Tagger", "Yields", "", 		100, 	0, 	1}, 	//06-06
	{ 0,	"AK5Info.Pt", 				"",	"Pt", 		"Yields", "GeV/c", 	2000, 	0,	2000}, 	//06-06
	{ 0,	"AK5Info.Eta", 				"",	"Eta", 		"Yields", "", 		100,	-5, 	5}, 	//06-06
	{ 0,	"AK5Info.Phi", 				"",	"Phi", 		"Yields", "", 		80,	-4,	4}, 	//06-06
	{ 0,	"AK5Info.Mass", 			"",	"Inv. Mass", 	"Yields", "GeV/c^{2}", 	500, 	0, 	50}, 	//06-06
	{ 0,	"AK5Info.b.bTag",	 		"",	"CSV b-Tagger", "Yields", "", 		100, 	0, 	1}, 	//06-06
	{ 0,	"AK5Info.b.Pt",		 		"",	"Pt", 		"Yields", "GeV/c", 	2000, 	0, 	2000}, 	//06-06
	{ 0,	"AK5Info.b.Eta", 			"",	"Eta", 		"Yields", "", 		100, 	-5, 	5}, 	//06-06
	{ 0,	"AK5Info.b.Phi", 			"",	"Phi", 		"Yields", "", 		80, 	-4, 	4}, 	//06-06
	{ 0,	"AK5Info.b.Mass", 			"",	"Inv. Mass", 	"Yields", "GeV/c^{2}", 	500, 	0, 	50}, 	//06-06
	{ 0,	"AK5Info.Select.bTag",	 		"",	"CSV b-Tagger", "Yields", "", 		100, 	0, 	1}, 	//06-06
	{ 0,	"AK5Info.Select.Pt", 			"",	"Pt", 		"Yields", "GeV/c", 	2000, 	0, 	2000}, 	//06-06
	{ 0,	"AK5Info.Select.Eta", 			"",	"Eta", 		"Yields", "", 		100, 	-5, 	5}, 	//06-06
	{ 0,	"AK5Info.Select.Phi", 			"",	"Phi", 		"Yields", "", 		80, 	-4, 	4}, 	//06-06
	{ 0,	"AK5Info.Select.Mass", 			"",	"Inv. Mass", 	"Yields", "GeV/c^{2}", 	500, 	0, 	50}, 	//06-06
	{ 0,	"AK5Info.Select.b.bTag", 		"",	"CSV b-Tagger", "Yields", "", 		100, 	0, 	1}, 	//06-06
	{ 0,	"AK5Info.Select.b.Pt", 			"",	"Pt", 		"Yields", "GeV/c", 	2000, 	0, 	2000}, 	//06-06
	{ 0,	"AK5Info.Select.b.Eta", 		"",	"Eta", 		"Yields", "",	 	100, 	-5, 	5}, 	//06-06
	{ 0,	"AK5Info.Select.b.Phi", 		"",	"Phi", 		"Yields", "", 		80, 	-4, 	4}, 	//06-06	
	{ 0,	"AK5Info.Select.b.Mass",		"",	"Inv. Mass", 	"Yields", "GeV/c^{2}", 	500, 	0, 	50}, 	//06-06
	{ 1,	"AK5Info.BpSelect.bTag", 		"",	"CSV b-Tagger", "Yields", "", 		100, 	0, 	1}, 	//06-06
	{ 1,	"AK5Info.BpSelect.Pt", 			"",	"Pt", 		"Yields", "GeV/c", 	2000, 	0, 	2000}, 	//06-06
	{ 1,	"AK5Info.BpSelect.Eta", 		"",	"Eta", 		"Yields", "", 		100, 	-5, 	5}, 	//06-06
	{ 1,	"AK5Info.BpSelect.Phi", 		"",	"Phi", 		"Yields", "", 		80, 	-4, 	4}, 	//06-06
	{ 1,	"AK5Info.BpSelect.Mass", 		"",	"Inv. Mass", 	"Yields", "GeV/c^{2}", 	500, 	0, 	50}, 	//06-06

	{ 0,	"CA8Info.2bTag", 			"",	"Double b-Tagger",	"Yields", "", 		100, 	-2, 	8}, 	//06-06	 
	{ 0,	"CA8Info.Pt", 				"",	"Pt", 			"Yields", "GeV/c", 	2000, 	0,	2000}, 	//06-06	
	{ 0,	"CA8Info.Eta", 				"",	"Eta", 			"Yields", "", 		100, 	-5, 	5}, 	//06-06
	{ 0,	"CA8Info.Phi",				"",	"Phi", 			"Yields", "", 		80, 	-4, 	4}, 	//06-06
	{ 0,	"CA8Info.Mass", 			"",	"Inv. Mass", 		"Yields", "GeV/c^{2}", 	2000, 	0, 	200}, 	//06-06
	{ 0,	"CA8Info.2b.2bTag", 			"",	"Double b-Tagger",	"Yields", "", 		100, 	-2, 	8}, 	//06-06	 
	{ 0,	"CA8Info.2b.Pt", 			"",	"Pt", 			"Yields", "GeV/c", 	2000, 	0,	2000}, 	//06-06	
	{ 0,	"CA8Info.2b.Eta", 			"",	"Eta", 			"Yields", "", 		100, 	-5, 	5}, 	//06-06
	{ 0,	"CA8Info.2b.Phi", 			"",	"Phi", 			"Yields", "", 		80, 	-4, 	4}, 	//06-06
	{ 0,	"CA8Info.2b.Mass", 			"",	"Inv. Mass", 		"Yields", "GeV/c^{2}", 	2000, 	0, 	200}, 	//06-06
	{ 0,	"CA8Info.Select.2bTag", 		"",	"Double b-Tagger",	"Yields", "", 		100, 	-2, 	8}, 	//06-06	
	{ 0,	"CA8Info.Select.Pt", 			"",	"Pt", 			"Yields", "GeV/c", 	2000, 	0,	2000}, 	//06-06	
	{ 0,	"CA8Info.Select.Eta",	 		"",	"Eta", 			"Yields", "", 		100, 	-5, 	5}, 	//06-06
	{ 0,	"CA8Info.Select.Phi", 			"",	"Phi", 			"Yields", "", 		80, 	-4, 	4}, 	//06-06
	{ 0,	"CA8Info.Select.Mass", 			"",	"Inv. Mass", 		"Yields", "GeV/c^{2}", 	2000, 	0, 	200}, 	//06-06	
	{ 0,	"CA8Info.Select.2b.2bTag", 		"",	"Double b-Tagger",	"Yields", "", 		100, 	-2, 	8}, 	//06-06
	{ 0,	"CA8Info.Select.2b.Pt", 		"",	"Pt", 			"Yields", "GeV/c", 	2000, 	0,	2000}, 	//06-06	
	{ 0,	"CA8Info.Select.2b.Eta",	 	"",	"Eta", 			"Yields", "", 		100, 	-5, 	5}, 	//06-06
	{ 0,	"CA8Info.Select.2b.Phi", 		"",	"Phi", 			"Yields", "", 		80, 	-4, 	4}, 	//06-06
	{ 0,	"CA8Info.Select.2b.Mass", 		"",	"Inv. Mass", 		"Yields", "GeV/c^{2}", 	2000, 	0, 	200}, 	//06-06
	{ 1,	"CA8Info.BpSelect.2bTag", 		"",	"Double b-Tagger",	"Yields", "", 		100, 	-2, 	8}, 	//06-06	
	{ 1,	"CA8Info.BpSelect.Pt", 			"",	"Pt", 			"Yields", "GeV/c", 	2000, 	0,	2000}, 	//06-06	
	{ 1,	"CA8Info.BpSelect.Eta",	 		"",	"Eta", 			"Yields", "", 		100, 	-5, 	5}, 	//06-06
	{ 1,	"CA8Info.BpSelect.Phi", 		"",	"Phi", 			"Yields", "", 		80, 	-4, 	4}, 	//06-06
	{ 1,	"CA8Info.BpSelect.Mass", 		"",	"Inv. Mass", 		"Yields", "GeV/c^{2}", 	2000, 	0, 	200}, 	//06-06	
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
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_NumRestEvt_Ht_ 	//08-20
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_NumRestEvt_Ht_GAK5_ 	//08-29
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_NumRestEvt_Ht_GbAK5_ 	//08-20
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_NumRestEvt_Ht_GbAK5_GCA8_ 	//08-29
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_NumRestEvt_Ht_GbAK5_G2bCA8_ 	//08-20
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_NumRestEvt_Ht_GbAK5_G2bCA8_dR_ 	//08-20
	{1, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_NumAK5_ 			//06-06
	{1, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_NumAK5_b_ 			//06-06
	{1, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_NumAK5_Select_	 	//06-06
	{1, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_NumAK5_Select_b_	 	//06-06
	{1, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_NumCA8_ 			//06-06
	{1, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_NumCA8_2b_ 			//06-06
	{1, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_NumCA8_Select_ 		//06-06
	{1, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_NumCA8_Select_2b_ 		//06-06
	{1, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_HtAK5_ 			//06-06
	{1, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_HtAK5_b_ 			//06-06
	{1, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_HtAK5_Select_ 		//06-06
	{1, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_HtAK5_Select_b_ 		//06-06
	{1, 0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_dR_AK5CA8_ 			//06-06
	{1, 0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_dR_AK5CA8_BpSelect_ 		//06-06
	{1, 0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_dPhi_AK5CA8_ 		//08-29
	{1, 0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//EvtInfo_dPhi_AK5CA8_BpSelect_ 		//08-29
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//EvtInfo_BpMass_ 			//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//EvtInfo_BpMass_BpSelect_ 	//06-06

	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//AK5Info_bTag_ 	//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//AK5Info_Pt_ 			//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//AK5Info_Eta_ 			//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//AK5Info_Phi_ 			//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//AK5Info_Mass_ 		//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//AK5Info_b_bTag_ 	//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//AK5Info_b_Pt_ 		//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//AK5Info_b_Eta_ 		//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//AK5Info_b_Phi_ 		//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//AK5Info_b_Mass_ 		//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//AK5Info_Select_bTag_ 	//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//AK5Info_Select_Pt_ 		//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//AK5Info_Select_Eta_ 		//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//AK5Info_Select_Phi_ 		//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//AK5Info_Select_Mass_ 		//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//AK5Info_Select_b_bTag_ 	//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//AK5Info_Select_b_Pt_ 		//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//AK5Info_Select_b_Eta_ 	//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//AK5Info_Select_b_Phi_ 	//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//AK5Info_Select_b_Mass_ 	//06-06
	{1, 0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111,   0.5, 1},		//AK5Info_BpSelect_bTag_ 	//06-06
	{1, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//AK5Info_BpSelect_Pt_ 	//06-06
	{1, 0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111,	3,	-3, 1},			//AK5Info_BpSelect_Eta_ 	//06-06
	{1, 0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//AK5Info_BpSelect_Phi_ 	//06-06
	{0, 0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//AK5Info_BpSelect_Mass_ 	//06-06

	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Info_2bTag_ 	//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//CA8Info_Pt_ 			//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Info_Eta_ 			//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Info_Phi_ 			//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//CA8Info_Mass_ 		//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Info_2b_2bTag_ 	//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//CA8Info_2b_Pt_ 		//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Info_2b_Eta_ 		//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Info_2b_Phi_	 	//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//CA8Info_2b_Mass_ 		//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Info_Select_2bTag_ 	//06-06
	{0, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//CA8Info_Select_Pt_ 		//06-06
	{0, 0.60,0.50,0.95,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Info_Select_Eta_ 		//06-06
	{0, 0.60,0.50,0.95,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Info_Select_Phi_ 		//06-06
	{0, 0.60,0.50,0.95,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//CA8Info_Select_Mass_ 		//06-06
	{0, 0.60,0.50,0.95,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Info_Select_2b_2bTag_ 	//06-06
	{0, 0.60,0.50,0.95,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//CA8Info_Select_2b_Pt_ 	//06-06
	{0, 0.60,0.50,0.95,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Info_Select_2b_Eta_ 	//06-06
	{0, 0.60,0.50,0.95,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Info_Select_2b_Phi_ 	//06-06
	{0, 0.60,0.50,0.95,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//CA8Info_Select_2b_Mass_ 	//06-06
	{1, 0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111,     6,     0, 1},		//CA8Info_BpSelect_2bTag_ 	//06-06
	{1, 0.65,0.70,0.85,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//CA8Info_BpSelect_Pt_ 	//06-06
	{1, 0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111,	    3,	  -3, 1},		//CA8Info_BpSelect_Eta_ 	//06-06
	{1, 0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 1},		//CA8Info_BpSelect_Phi_ 	//06-06
	{0, 0.20,0.70,0.40,0.90,"l", 1.3, -1111, -1111, -1111, -1111, 100},		//CA8Info_BpSelect_Mass_ 	//06-06
};


/////// Set Struct of All variables(TH2F) //////=========================================================================================================================
enum th2flist_{
	EvtInfo_HtAK5_BpMass_, 				//06-06
	EvtInfo_HtAK5_BpMass_BpSelect_, 		//06-06
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
	{ 0, "EvtInfo.HtAK5.BpMass",			"",	"Inv. Mass",	"Ht", "GeV/c^{2}", "GeV/c",2000, 0, 2000, 4000, 0, 4000}, //06-06
	{ 0, "EvtInfo.HtAK5.BpMass.BpSelect",		"",	"Inv. Mass",	"Ht", "GeV/c^{2}", "GeV/c",2000, 0, 2000, 4000, 0, 4000}, //06-06
};


struct Other2Info_{
	float SetXMin;	//SetXaxis min
	float SetXMax;	//SetXaxis max
	float SetYMin;	//SetYaxis min
	float SetYMax;	//SetYaxis max
	float SetZMin;	//SetZaxis max
	float SetZMax;	//SetZaxis max
};

struct Other2Info_ Other2Info[th2_size_] = {
	{0, 2000, 0, 4000, 0, -1111},	//EvtInfo_HtAK5_BpMass_ 	//06-06
	{0, 2000, 0, 4000, 0, -1111},	//EvtInfo_HtAK5_BpMass_BpSelect_ 	//06-06
};

