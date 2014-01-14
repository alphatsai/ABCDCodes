//#include "plotInfo.h"
////== TH1 Historgram /////======================================================================
class th1Initial{
	public: 
		//Detail info
		map<string, TH1F*> mapTH1;
		string	name[th1_size_];
		int	bin[th1_size_];
		float	min[th1_size_];
		float	max[th1_size_];

		//Fun. of initial TH1F
		th1Initial();
		TH1F* GetTH1F(string name_);
};

// Define function 
th1Initial::th1Initial(){
	for(int i=0; i<th1_size_; i++){ //Loop all kind of TH1F
		name[i]   = TH1Info[i].name;
		bin[i]	= TH1Info[i].bin;
		max[i]	= TH1Info[i].max;
		min[i]	= TH1Info[i].min;
		mapTH1[name[i]] = new TH1F(name[i].c_str(),"",bin[i], min[i], max[i]);
	}		
	
}
TH1F* th1Initial::GetTH1F(string name_){
	return mapTH1.find(name_)->second;
}


////== TH2 Historgram /////======================================================================
class th2Initial{
	public: 
		//Detail info
		map<string, TH2F*> mapTH2;
		string	name[th2_size_];
		int	xbin[th2_size_];
		float	xmin[th2_size_];
		float	xmax[th2_size_];
		int	ybin[th2_size_];
		float	ymin[th2_size_];
		float	ymax[th2_size_];

		//Fun. of initial TH1F
		th2Initial();
		TH2F* GetTH2F(string name_);
};

// Define function 
th2Initial::th2Initial(){
	for(int i=0; i<th2_size_; i++){ //Loop all kind of TH1F
		name[i]   = TH2Info[i].name;
		xbin[i]	= TH2Info[i].xbin;
		xmax[i]	= TH2Info[i].xmax;
		xmin[i]	= TH2Info[i].xmin;
		ybin[i]	= TH2Info[i].ybin;
		ymax[i]	= TH2Info[i].ymax;
		ymin[i]	= TH2Info[i].ymin;
		mapTH2[name[i]] = new TH2F(name[i].c_str(),"",xbin[i], xmin[i], xmax[i],ybin[i], ymin[i], ymax[i]);
	}		
}
TH2F* th2Initial::GetTH2F(string name_){
	return mapTH2.find(name_)->second;
}

