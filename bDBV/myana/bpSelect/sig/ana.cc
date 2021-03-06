#include <fstream>
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
//#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/bDBV/interface/function.C"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/bDBV/interface/myformat.h"
//#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/bDBV/interface/jetSelection.C"
//#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/bDBV/interface/mttCut.C"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/bDBV/interface/sampleInfo.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/bDBV/interface/plotsInfo.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/bDBV/interface/histoInital.C" //th1Initial, th2Initial
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/bDBV/interface/chainRoot.C"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////// Analysis start //////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//void ana1() 
//void ana2() 
void ana()
{
	//////////////////// Differents mass point ///////////////==================================================================================================
	//for( int iSample=0; iSample<int(Category[0].SampleSize/2); iSample++){  //TopPart
	//for( int iSample=int(Category[0].SampleSize/2); iSample<Category[0].SampleSize; iSample++){ //BottomPart
	for( int iSample=0; iSample<Category[0].SampleSize; iSample++){   //FullPart
		///////////////////// Create New Tree and Forder //////////////////////==============================================================================
		string SavePath  = "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/bDBV/result/root/mc/sig/"+SigMC[iSample].name+".root";
		TChain* tree = new TChain("ntuple/tree");
		chainRoot(tree, SigMC[iSample].sample, SigMC[iSample].numRootFiles);
		TFile* newfile = new TFile( SavePath.c_str() ,"recreate");
		TTree* newtree = new TTree("tree","I am a new tree");
		cout <<"Folder and Tree Created"<<endl;

		/////////////////////// Connect the Tree, Branch, leaf ////////////////=============================================================================
		GenInfoBranches GenInfo;
		JetInfoBranches CA8JetInfo;
		JetInfoBranches AK5JetInfo;
		JetInfoBranches SubJetInfo;
		GenInfo.Register(tree);	
		CA8JetInfo.Register(tree,"FatJetInfo");
		AK5JetInfo.Register(tree,"JetInfo");
		SubJetInfo.Register(tree,"SubJetInfo");
		cout <<"Branch Registed"<<endl;
	
		GenInfoBranches NewGenInfo;
		JetInfoBranches NewCA8JetInfo;
		JetInfoBranches NewAK5JetInfo;
		JetInfoBranches NewSubJetInfo;
		NewGenInfo.RegisterTree(newtree);	
		NewCA8JetInfo.RegisterTree(newtree,"FatJetInfo");
		NewAK5JetInfo.RegisterTree(newtree,"JetInfo");
		NewSubJetInfo.RegisterTree(newtree,"SubJetInfo");
		cout <<"Branch Registed"<<endl;

		////////////////////// Initialize the Histogram ///////////////////////=============================================================================
		th1Initial h1;   // Refer to plotInfo.h
		th2Initial h2;   // Refer to plotInfo.h
		
		///////////////////// Get by event to Analysis ////////////////////////=============================================================================
		for( int entry=0; entry<tree->GetEntries(); entry++ ){
			if( entry%10 == 0 )  cout<<".";
			if( entry%10000 == 0 ) cout<<entry;
			//if( entry%10000 == 0 ) printf("%1.3f \%\r",(100.*entry/tree->GetEntries()));
			tree->GetEntry(entry);
			
			//if( GenInfo.MttCut() )	continue; //Only for TTJet Hadron decay samples

			/////// Selection Rest Event num ///////=====================================================================================================
			int numRestEvt_1=0;
			int numRestEvt_12=0;
			int numRestEvt_123=0;
			int numRestEvt_1234=0;
			int numRestEvt_12345=0;
			int numRestEvt_123456=0;
			float HtSelectbAK5Plus2bCA8=0;

			/////// CA8 Jet Info ///////=================================================================================================================
			int Num2bCA8 = 0;
			int NumSelectCA8 = 0;
			int NumSelect2bCA8 = 0;

			h1.GetTH1F("EvtInfo.NumCA8")->Fill(CA8JetInfo.Size);	
			for( int i=0; i<CA8JetInfo.Size; i++){
				h1.GetTH1F("CA8Info.Pt")->Fill(CA8JetInfo.Pt[i]);
				h1.GetTH1F("CA8Info.Eta")->Fill(CA8JetInfo.Eta[i]);
				h1.GetTH1F("CA8Info.Phi")->Fill(CA8JetInfo.Phi[i]);
				h1.GetTH1F("CA8Info.Mass")->Fill(CA8JetInfo.Mass[i]);
				h1.GetTH1F("CA8Info.2bTag")->Fill(CA8JetInfo.DoubleSVHighEffBJetTags[i]);
				if( CA8JetInfo.is2bCA8(i) ){ // is double-Tagged CA8Jet 
					Num2bCA8++;	
					h1.GetTH1F("CA8Info.2b.Pt")->Fill(CA8JetInfo.Pt[i]);
					h1.GetTH1F("CA8Info.2b.Eta")->Fill(CA8JetInfo.Eta[i]);
					h1.GetTH1F("CA8Info.2b.Phi")->Fill(CA8JetInfo.Phi[i]);
					h1.GetTH1F("CA8Info.2b.Mass")->Fill(CA8JetInfo.Mass[i]);
					h1.GetTH1F("CA8Info.2b.2bTag")->Fill(CA8JetInfo.DoubleSVHighEffBJetTags[i]);
				}
				if( CA8JetInfo.isGoodCA8(i) ){ // is Selected CA8Jet 
					NumSelectCA8++;	
					h1.GetTH1F("CA8Info.Select.Pt")->Fill(CA8JetInfo.Pt[i]);
					h1.GetTH1F("CA8Info.Select.Eta")->Fill(CA8JetInfo.Eta[i]);
					h1.GetTH1F("CA8Info.Select.Phi")->Fill(CA8JetInfo.Phi[i]);
					h1.GetTH1F("CA8Info.Select.Mass")->Fill(CA8JetInfo.Mass[i]);
					h1.GetTH1F("CA8Info.Select.2bTag")->Fill(CA8JetInfo.DoubleSVHighEffBJetTags[i]);
				}
				if( CA8JetInfo.isGood2bCA8(i) ){ // is Selected double-Tagged CA8Jet 
					NumSelect2bCA8++;
					HtSelectbAK5Plus2bCA8=HtSelectbAK5Plus2bCA8+CA8JetInfo.Pt[i];		
					h1.GetTH1F("CA8Info.Select.2b.Pt")->Fill(CA8JetInfo.Pt[i]);
					h1.GetTH1F("CA8Info.Select.2b.Eta")->Fill(CA8JetInfo.Eta[i]);
					h1.GetTH1F("CA8Info.Select.2b.Phi")->Fill(CA8JetInfo.Phi[i]);
					h1.GetTH1F("CA8Info.Select.2b.Mass")->Fill(CA8JetInfo.Mass[i]);
					h1.GetTH1F("CA8Info.Select.2b.2bTag")->Fill(CA8JetInfo.DoubleSVHighEffBJetTags[i]);
				}
			}// CA8
			h1.GetTH1F("EvtInfo.NumCA8.2b")->Fill(Num2bCA8);	
			h1.GetTH1F("EvtInfo.NumCA8.Select")->Fill(NumSelectCA8);	
			h1.GetTH1F("EvtInfo.NumCA8.Select.2b")->Fill(NumSelect2bCA8);	

			////// AK5 Jet Info //////=====================================================================================================================
			int NumbAK5 = 0;
			int NumSelectAK5 = 0;
			int NumSelectbAK5 = 0;
			float HtAK5 = 0;
			float HtbAK5 = 0;
			float HtSelectAK5 = 0;
			float HtSelectbAK5 = 0;

			h1.GetTH1F("EvtInfo.NumAK5")->Fill(AK5JetInfo.Size);	
			for( int i=0; i<AK5JetInfo.Size; i++){
				int saperateWith2bCA8=0;
				for( int j=0; j<CA8JetInfo.Size; j++){
					if(!CA8JetInfo.isGood2bCA8(j))	continue;
					if(dR(CA8JetInfo.Eta[j],AK5JetInfo.Eta[i],CA8JetInfo.Phi[j],AK5JetInfo.Phi[i])<=0.8)
						saperateWith2bCA8++; 	
				}
				h1.GetTH1F("AK5Info.Pt")->Fill(AK5JetInfo.Pt[i]);
				h1.GetTH1F("AK5Info.Eta")->Fill(AK5JetInfo.Eta[i]);
				h1.GetTH1F("AK5Info.Phi")->Fill(AK5JetInfo.Phi[i]);
				h1.GetTH1F("AK5Info.Mass")->Fill(AK5JetInfo.Mass[i]);
				h1.GetTH1F("AK5Info.bTag")->Fill(AK5JetInfo.CombinedSVBJetTags[i]);
				HtAK5 = HtAK5 + AK5JetInfo.Pt[i];
				if( AK5JetInfo.isbAK5(i)&& saperateWith2bCA8==0 ){ // is double-Tagged AK5Jet 
					NumbAK5++;	
					h1.GetTH1F("AK5Info.b.Pt")->Fill(AK5JetInfo.Pt[i]);
					h1.GetTH1F("AK5Info.b.Eta")->Fill(AK5JetInfo.Eta[i]);
					h1.GetTH1F("AK5Info.b.Phi")->Fill(AK5JetInfo.Phi[i]);
					h1.GetTH1F("AK5Info.b.Mass")->Fill(AK5JetInfo.Mass[i]);
					h1.GetTH1F("AK5Info.b.bTag")->Fill(AK5JetInfo.CombinedSVBJetTags[i]);
					HtbAK5 = HtbAK5 + AK5JetInfo.Pt[i];
				}
				if( AK5JetInfo.isGoodAK5(i) && saperateWith2bCA8==0 ){ // is Selected AK5Jet 
					NumSelectAK5++;	
					h1.GetTH1F("AK5Info.Select.Pt")->Fill(AK5JetInfo.Pt[i]);
					h1.GetTH1F("AK5Info.Select.Eta")->Fill(AK5JetInfo.Eta[i]);
					h1.GetTH1F("AK5Info.Select.Phi")->Fill(AK5JetInfo.Phi[i]);
					h1.GetTH1F("AK5Info.Select.Mass")->Fill(AK5JetInfo.Mass[i]);
					h1.GetTH1F("AK5Info.Select.bTag")->Fill(AK5JetInfo.CombinedSVBJetTags[i]);
					HtSelectAK5 = HtSelectAK5 + AK5JetInfo.Pt[i];
				}
				if( AK5JetInfo.isGoodbAK5(i) && saperateWith2bCA8==0 ){ // is Selected double-Tagged AK5Jet 
					NumSelectbAK5++;
					HtSelectbAK5Plus2bCA8=HtSelectbAK5Plus2bCA8+AK5JetInfo.Pt[i];	
					h1.GetTH1F("AK5Info.Select.b.Pt")->Fill(AK5JetInfo.Pt[i]);
					h1.GetTH1F("AK5Info.Select.b.Eta")->Fill(AK5JetInfo.Eta[i]);
					h1.GetTH1F("AK5Info.Select.b.Phi")->Fill(AK5JetInfo.Phi[i]);
					h1.GetTH1F("AK5Info.Select.b.Mass")->Fill(AK5JetInfo.Mass[i]);
					h1.GetTH1F("AK5Info.Select.b.bTag")->Fill(AK5JetInfo.CombinedSVBJetTags[i]);
					HtSelectbAK5 = HtSelectbAK5 + AK5JetInfo.Pt[i];
				}
			}// AK5
			h1.GetTH1F("EvtInfo.NumAK5.b")->Fill(NumbAK5);	
			h1.GetTH1F("EvtInfo.NumAK5.Select")->Fill(NumSelectAK5);	
			h1.GetTH1F("EvtInfo.NumAK5.Select.b")->Fill(NumSelectbAK5);	
			h1.GetTH1F("EvtInfo.HtAK5")->Fill(HtAK5);	
			h1.GetTH1F("EvtInfo.HtAK5.b")->Fill(HtbAK5);	
			h1.GetTH1F("EvtInfo.HtAK5.Select")->Fill(HtSelectAK5);	
			h1.GetTH1F("EvtInfo.HtAK5.Select.b")->Fill(HtSelectbAK5);	
			h1.GetTH1F("EvtInfo.HtAK5CA8.Select.b.2b")->Fill(HtSelectbAK5Plus2bCA8);	
	
			//////// Bprime Mass ///////============================================================================================================================

			bool CA8_BpSelect2bbDR[CA8JetInfo.Size];
			bool AK5_BpSelect2bbDR[CA8JetInfo.Size];
			for( int i=0; i<CA8JetInfo.Size; i++){ 	CA8_BpSelect2bbDR[i]=0; } 
			for( int i=0; i<AK5JetInfo.Size; i++){ 	AK5_BpSelect2bbDR[i]=0; } 

			for( int i=0; i<CA8JetInfo.Size; i++){
				for( int j=0; j<AK5JetInfo.Size;j++){
					double BpMass = lorentzPairMass(CA8JetInfo.Pt[i],CA8JetInfo.Eta[i],CA8JetInfo.Phi[i],CA8JetInfo.Mass[i],
									AK5JetInfo.Pt[j],AK5JetInfo.Eta[j],AK5JetInfo.Phi[j],AK5JetInfo.Mass[j]);
					double dRCA8AK5 = dR(CA8JetInfo.Eta[i],AK5JetInfo.Eta[j],CA8JetInfo.Phi[i],AK5JetInfo.Phi[j]);
					double dPhiCA8AK5 = dPhi(CA8JetInfo.Phi[i],AK5JetInfo.Phi[j]);
					///// No Selection, b, 2b //////
					h1.GetTH1F("EvtInfo.BpMass")->Fill(BpMass);
					h1.GetTH1F("EvtInfo.dR.AK5CA8")->Fill(dRCA8AK5);
					h1.GetTH1F("EvtInfo.dPhi.AK5CA8")->Fill(dPhiCA8AK5);
					h2.GetTH2F("EvtInfo.HtAK5.BpMass")->Fill(BpMass,HtAK5);
					h2.GetTH2F("EvtInfo.dR-AK5CA8.BpMass")->Fill(BpMass,dRCA8AK5);
					h2.GetTH2F("EvtInfo.dPhi-AK5CA8.BpMass")->Fill(BpMass,dPhiCA8AK5);

					///// Selection //////
					//Num good CA8 event cut
					if( NumSelectCA8<1 ){	continue; 
					} else { numRestEvt_1=1; }
					//Num good 2b CA8 event cut
					if( NumSelect2bCA8<1 ){	continue; 
					} else { numRestEvt_12=1;}
					// Num good AK5 EVENT CUT
					if( NumSelectAK5<2 ){	continue; 
					} else { numRestEvt_123=1;}
					// Num good b AK5 EVENT CUT
					if( NumSelectbAK5<2 ){	continue; 
					} else { numRestEvt_1234=1; } 
					// Ht(GoodbAK5+Good2bCA8) event cut 
					if( HtSelectbAK5Plus2bCA8<=1000 ){	continue;
					} else { numRestEvt_12345=1; } 
					//} else { numRestEvt_123456=1; }
					//Comebine AK5 and CA8 	
					if( !CA8JetInfo.isGood2bCA8(i) || !AK5JetInfo.isGoodbAK5(j)) continue;
					if( dRCA8AK5>0.8) {
						//numRestEvt_123456=1;
						CA8_BpSelect2bbDR[i]=1;
						AK5_BpSelect2bbDR[j]=1;
						h1.GetTH1F("EvtInfo.BpYields.BpSelect")->Fill(1);
						h1.GetTH1F("EvtInfo.BpMass.BpSelect")->Fill(BpMass);
						h1.GetTH1F("EvtInfo.dR.AK5CA8.BpSelect")->Fill(dRCA8AK5);
						h1.GetTH1F("EvtInfo.dPhi.AK5CA8.BpSelect")->Fill(dPhiCA8AK5);
						h2.GetTH2F("EvtInfo.HtAK5.BpMass.BpSelect")->Fill(BpMass,HtAK5);
						h2.GetTH2F("EvtInfo.dR-AK5CA8.BpMass.BpSelect")->Fill(BpMass,dRCA8AK5);
						h2.GetTH2F("EvtInfo.dPhi-AK5CA8.BpMass.BpSelect")->Fill(BpMass,dPhiCA8AK5);
					}
				}//AK5 for b'
			}//CA8 for  b'	
			h1.GetTH1F("EvtInfo.NumRestEvt.1")->Fill(numRestEvt_1);
			h1.GetTH1F("EvtInfo.NumRestEvt.12")->Fill(numRestEvt_12);
			h1.GetTH1F("EvtInfo.NumRestEvt.123")->Fill(numRestEvt_123);
			h1.GetTH1F("EvtInfo.NumRestEvt.1234")->Fill(numRestEvt_1234);
			h1.GetTH1F("EvtInfo.NumRestEvt.12345")->Fill(numRestEvt_12345);
			h1.GetTH1F("EvtInfo.NumRestEvt.123456")->Fill(numRestEvt_123456);
			
			/////// Fill the topology of CA8 and AK5 after bprime Selection ///////========================================================================
			for( int i=0; i<CA8JetInfo.Size; i++){ //For CA8	
				if( CA8_BpSelect2bbDR[i] ){
					h1.GetTH1F("CA8Info.BpSelect.2bTag")->Fill(CA8JetInfo.DoubleSVHighEffBJetTags[i]);				
					h1.GetTH1F("CA8Info.BpSelect.Pt")->Fill(CA8JetInfo.Pt[i]);				
					h1.GetTH1F("CA8Info.BpSelect.Eta")->Fill(CA8JetInfo.Eta[i]);				
					h1.GetTH1F("CA8Info.BpSelect.Phi")->Fill(CA8JetInfo.Phi[i]);				
					h1.GetTH1F("CA8Info.BpSelect.Mass")->Fill(CA8JetInfo.Mass[i]);				
				}  
			}
 
			for( int i=0; i<AK5JetInfo.Size; i++){ 	//For AK5
				if( AK5_BpSelect2bbDR[i] ){
					h1.GetTH1F("AK5Info.BpSelect.bTag")->Fill(AK5JetInfo.CombinedSVBJetTags[i]);				
					h1.GetTH1F("AK5Info.BpSelect.Pt")->Fill(AK5JetInfo.Pt[i]);				
					h1.GetTH1F("AK5Info.BpSelect.Eta")->Fill(AK5JetInfo.Eta[i]);				
					h1.GetTH1F("AK5Info.BpSelect.Phi")->Fill(AK5JetInfo.Phi[i]);				
					h1.GetTH1F("AK5Info.BpSelect.Mass")->Fill(AK5JetInfo.Mass[i]);				
				}  
			}
 
		}//entry
		cout<<endl<<tree->GetEntries()<<endl<<"Finished ^____^"<<endl;
		/////////////////////// Save the root file ///////////////////////////===============================================================================
		newfile->Write();
		cout<<"Sample "<<SigMC[iSample].name<<" End !!!"<<endl;
	}// masspoint
}
