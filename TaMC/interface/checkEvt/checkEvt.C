#include <iostream>
#include <fstream>
#include "TFile.h"
#include "TChain.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/TaMC/interface/sampleInfo.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/TaMC/interface/chainRoot.C"
using namespace std;
void checkEvt(){
	//TChain* newtree = new TChain("ntuple/tree");
	//newtree->Add("root://eoscms//eos/cms/store/user/devdatta/NtuplesBprimeTobH_v1/Jet_Run2012A/BprimeTobH_v1_9_1_m0H.root");
	//cout<<newtree->GetEntries()<<endl;
	for( int i=0; i<Data_TotalNum; i++){
	//for( int i=0; i<1; i++){
		TChain* newtree = new TChain("ntuple/tree");
		cout<<Data[i].sample<<endl;
		chainRoot(newtree, Data[i].sample, Data[i].numRootFiles);
	}
	for( int i=0; i<SigMC_TotalNum; i++){
	//for( int i=0; i<1; i++){
		TChain* newtree = new TChain("ntuple/tree");
		cout<<SigMC[i].sample<<endl;
		chainRoot(newtree, SigMC[i].sample, SigMC[i].numRootFiles);
	}
	for( int i=0; i<QCDMC_TotalNum; i++){
	//for( int i=QCDMC_TotalNum-1; i<QCDMC_TotalNum; i++){
		TChain* newtree = new TChain("ntuple/tree");
		cout<<QCDMC[i].sample<<endl;
		chainRoot(newtree, QCDMC[i].sample, QCDMC[i].numRootFiles);
	}
	for( int i=0; i<TTMC_TotalNum; i++){
		TChain* newtree = new TChain("ntuple/tree");
		cout<<TTMC[i].sample<<endl;
		chainRoot(newtree, TTMC[i].sample, TTMC[i].numRootFiles);
		cout<<newtree->GetEntries()<<endl;
	}
} 
