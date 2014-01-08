#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <cstdlib>
#include "TChain.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TLorentzVector.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/0105/interface/function.C"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/0105/interface/myformat.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/0105/interface/mttCut.C"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////// Analysis start //////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//void ana1() 
//void ana2() 
void ana()
{
	///////////////////// Create New Tree and Forder //////////////////////==============================================================================
	string sample = "TTJets_HadronicMGDecays_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1";
	string LoadPath  = "/home/hep/alpha78718/mywk/store/bpToBH_Ntuple/dR08/"+sample+"/*.root";
	TChain* newtree = new TChain("bprimeKit/root");
	newtree->Add( LoadPath.c_str() );
	cout <<"Tree bulid: "<<LoadPath<<endl;
	TFile* newfile = new TFile( "TTJets_Mtt.root","recreate");
	cout <<"Folder create"<<endl;

	/////////////////////// Connect the Tree, Branch, leaf ////////////////=============================================================================
	GenInfoBranches GenInfo;
	GenInfo.Register(newtree);	
	cout <<"Branch bulid"<<endl;

	////////////////////// Initialize the Histogram ///////////////////////=============================================================================
	TH1F* evt = new TH1F("evt","",2, 0,2);	
	TH1F* tt = new TH1F("tt","",10, 0,10);	
	TH1F* Mtt = new TH1F("Mtt","",100, 0,2000);	
	TH1F* Moth1Top = new TH1F("Moth1","",3000, 0,3000);	
	TH1F* Moth2Top = new TH1F("Moth2","",3000, 0,3000);	

	///////////////////// Get by event to Analysis ////////////////////////=============================================================================
	//for( int entry=0; entry<newtree->GetEntries(); entry++ ){
	for( int entry=0; entry<100000; entry++ ){
		if( entry%10 == 0 )  cout<<".";
		if( entry%10000 == 0 ) cout<<entry;
		newtree->GetEntry(entry);
		if(GenInfo.MttCut()) continue;
		int ttnum=0;
		int evtnum=1;
		for( int i=0; i<GenInfo.Size; i++){
			if  ( GenInfo.PdgID[i] == 6 || GenInfo.PdgID[i]== -6 ) {
				int pdgIDi = GenInfo.PdgID[i];
				Moth1Top->Fill(GenInfo.PdgID[GenInfo.Mo1[i]]);
				Moth2Top->Fill(GenInfo.PdgID[GenInfo.Mo2[i]]);
				for( int j=i+1; j<GenInfo.Size; j++){
					if (  GenInfo.PdgID[j] == pdgIDi ) continue;	
					if (  GenInfo.PdgID[j] == 6 || GenInfo.PdgID[j]== -6 ) {
						Moth1Top->Fill(GenInfo.PdgID[GenInfo.Mo1[j]]);
						Moth2Top->Fill(GenInfo.PdgID[GenInfo.Mo2[j]]);
						Mtt->Fill(lorentzPairMass(GenInfo.Pt[i],GenInfo.Eta[i],GenInfo.Phi[i],GenInfo.Mass[i],
										GenInfo.Pt[j],GenInfo.Eta[j],GenInfo.Phi[j],GenInfo.Mass[j]));	
						ttnum++;	
					}
				}
			}

		}
		tt->Fill(ttnum);
		evt->Fill(evtnum);
	}//entry
	cout<<endl<<newtree->GetEntries()<<endl<<"Finished ^____^"<<endl;
	/////////////////////// Save the root file ///////////////////////////===============================================================================
	newfile->Write();
}
