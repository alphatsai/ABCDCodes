//#include "sampleInfo.h"
void chainRoot( TChain* t, string sample, int rootNum){
	int zero=0;	
	fstream rootList;
	string logPath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/listRootinEOS/listRoot/"+sample+".txt";
	string rootPath;
	rootList.open(logPath.c_str(),ios_base::in);
	cout<<"Start to run "<<sample<<endl;
	for( int i=0; i<rootNum;i++){
		int o_size=t->GetEntries();
		rootList>>rootPath;
		string root="root://eoscms/"+rootPath;
		t->Add(root.c_str());
		if( t->GetEntries() == o_size ){
			zero++;	
		}
	}
	cout<<"Tree builded"<<endl;
	cout<<"Total Entries: "<<t->GetEntries()<<", ZeroEvt: "<<zero<<"/"<<rootNum<<", fail: "<<float(zero)/float(rootNum)*100<<"%"<<endl;
}
