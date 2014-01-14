	for(int i=0; i<BGSMC_TotalNum; i++){
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

		double scale = 1000*lumi*BGSMC[i].xsec/BGSMC[i].totalEvt;
		string path = BGSRootPath+"/"+BGSMC[i].name+".root";
		BGSf[i] = new TFile(path.c_str());
		h1_BGS[i]	=(TH1F*)BGSf[i]->Get("EvtInfo.NumRestEvt.1");		h1_BGS[i]->Scale(scale);
		h12_BGS[i]	=(TH1F*)BGSf[i]->Get("EvtInfo.NumRestEvt.12");		h12_BGS[i]->Scale(scale);
		h123_BGS[i]	=(TH1F*)BGSf[i]->Get("EvtInfo.NumRestEvt.123");		h123_BGS[i]->Scale(scale);
		h1234_BGS[i]	=(TH1F*)BGSf[i]->Get("EvtInfo.NumRestEvt.1234");	h1234_BGS[i]->Scale(scale);
		h12345_BGS[i]	=(TH1F*)BGSf[i]->Get("EvtInfo.NumRestEvt.12345");	h12345_BGS[i]->Scale(scale);
	//	h123456_BGS[i]	=(TH1F*)BGSf[i]->Get("EvtInfo.NumRestEvt.123456");	h123456_BGS[i]->Scale(scale);
		
		n1_RestNum 	= h1_BGS[i]->GetBinContent(2);
		n12_RestNum 	= h12_BGS[i]->GetBinContent(2);
		n123_RestNum 	= h123_BGS[i]->GetBinContent(2);
		n1234_RestNum 	= h1234_BGS[i]->GetBinContent(2);
		n12345_RestNum 	= h12345_BGS[i]->GetBinContent(2);
	//	n123456_RestNum = h123456_BGS[i]->GetBinContent(2);

		n1_Eff	    	= n1_RestNum/(BGSMC[i].totalEvt*scale);
		n12_Eff     	= n12_RestNum/n1_RestNum;
		n123_Eff    	= n123_RestNum/n12_RestNum;
		n1234_Eff   	= n1234_RestNum/n123_RestNum;
		n12345_Eff   	= n12345_RestNum/n1234_RestNum;
	//	n123456_Eff 	= n123456_RestNum/n12345_RestNum;
	//	Total_Eff	= n123456_RestNum/(BGSMC[i].totalEvt*scale);
		Total_Eff	= n12345_RestNum/(BGSMC[i].totalEvt*scale);

		cout<<"============= "<<BGSMC[i].name<<" =============="<<endl;		
