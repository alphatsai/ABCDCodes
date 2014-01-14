//#include "plotInfo.h"
class TH1FInfo{
	public: 
		//Detail info
		map<string, TH1F*> mapTH1;
		string name[total];
		int bin[total];
		float min[total];
		float max[total];

		//Fun. of initial TH1F
		//void  initial();
		TH1FInfo();
		TH1F* GetTH1F(string name_);
};
TH1FInfo::TH1FInfo(){
	for(int i=0; i<total; i++){ //Loop all kind of TH1F
		name[i] = detail[i].name;
		bin[i] = detail[i].bin;
		max[i] = detail[i].max;
		min[i] = detail[i].min;
		mapTH1[name[i]] = new TH1F(name[i].c_str(),"",bin[i], min[i], max[i]);
	}		
}
TH1F* TH1FInfo::GetTH1F(string name_){
	return mapTH1.find(name_)->second;
}
