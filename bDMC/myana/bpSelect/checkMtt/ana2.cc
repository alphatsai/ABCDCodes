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
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/bDMC/interface/myformat.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////// Functions ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//////// Files Info Function ///////////
double dPhi(double p1,double p2){ //dPhi
	double dp = p1 - p2;
	if (fabs(dp+3.14159265358979323846*2.) < fabs(dp)) dp += 3.14159265358979323846*2.;
	else
		if (fabs(dp-3.14159265358979323846*2.) < fabs(dp)) dp -= 3.14159265358979323846*2.;
	return fabs(dp);
}
double dR (double e1, double e2, double p1, double p2){ //dR
	return sqrt(pow(e1-e2,2)+pow(dPhi(p1,p2),2));
}
double lorentzPairMass (double pt1, double eta1, double phi1, double mass1,
			double pt2, double eta2, double phi2, double mass2){
	TLorentzVector v1; v1.SetPtEtaPhiM(pt1,eta1,phi1,mass1);
	TLorentzVector v2; v2.SetPtEtaPhiM(pt2,eta2,phi2,mass2);
	TLorentzVector v3 = v1 + v2;
	return v3.M();
} 
///////////////////////////////////////////////////////////////////////////////
///////////////////////////// Analysis start //////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void ana2() 
{
	///////////////////// Create New Tree and Forder //////////////////////==============================================================================
	string sample = "TT_Mtt-700to1000_CT10_TuneZ2star_8TeV-powheg-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1";
	string LoadPath  = "/home/hep/alpha78718/mywk/store/bpToBH_Ntuple/dR08/"+sample+"/*.root";
	TChain* newtree = new TChain("bprimeKit/root");
	newtree->Add( LoadPath.c_str() );
	cout <<"Tree bulid: "<<LoadPath<<endl;
	TFile* newfile = new TFile( "TT700to1000_Mtt.root","recreate");
	cout <<"Folder create"<<endl;

	/////////////////////// Connect the Tree, Branch, leaf ////////////////=============================================================================
	GenInfoBranches GenInfo;
	GenInfo.Register(newtree);	
	cout <<"Branch bulid"<<endl;

	////////////////////// Initialize the Histogram ///////////////////////=============================================================================
	TH1F* Mtt = new TH1F("Mtt","",100, 0,2000);	
	TH1F* Moth1Top = new TH1F("Moth1","",3000, 0,3000);	
	TH1F* Moth2Top = new TH1F("Moth2","",3000, 0,3000);	

	///////////////////// Get by event to Analysis ////////////////////////=============================================================================
	for( int entry=0; entry<newtree->GetEntries(); entry++ ){
	//for( int entry=0; entry<100; entry++ ){
		if( entry%10 == 0 )  cout<<".";
		if( entry%10000 == 0 ) cout<<entry;
		newtree->GetEntry(entry);
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
		
					}
				}
			}

		}
	}//entry
	cout<<endl<<newtree->GetEntries()<<endl<<"Finished ^____^"<<endl;
	/////////////////////// Save the root file ///////////////////////////===============================================================================
	newfile->Write();
}
