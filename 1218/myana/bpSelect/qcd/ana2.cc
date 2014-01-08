#include <fstream>
#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <cstdlib>
#include <vector>
#include "TChain.h"
#include "TMath.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TLorentzVector.h"
//#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/function.C"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/myformat.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/selection.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/TriggerBooking.h"
//#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/jetSelection.C"
//#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/mttCut.C"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/sampleInfo.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/plotsInfo.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/histoInital.C" //th1Initial, th2Initial
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/chainRoot.C"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/reRegestJet.C"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////// Analysis start //////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//void ana1() 
void ana2() 
//void ana()
{
	//////////////////// Differents mass point ///////////////==================================================================================================
	//for( int iSample=0; iSample<int(Category[1].SampleSize/2); iSample++){  //TopPart
	//for( int iSample=0; iSample<1; iSample++){  
	for( int iSample=int(Category[1].SampleSize/2); iSample<Category[1].SampleSize; iSample++){ //BottomPart
	//for( int iSample=0; iSample<Category[1].SampleSize; iSample++){   //FullPart
		cout<<"For "<<QCDMC[iSample].sample<<endl;
		///////////////////// Create New Tree and Forder //////////////////////==============================================================================
		string LoadPath	 = "/afs/cern.ch/user/j/jtsai/eos/cms/store/user/devdatta/NtuplesBprimeTobH_v1/"+QCDMC[iSample].sample+"/*.root";
		string SavePath  = "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/result/root/mc/bg/"+QCDMC[iSample].name+".root";
		TChain* tree = new TChain("ntuple/tree");
		//chainRoot(tree, QCDMC[iSample].sample, QCDMC[iSample].numRootFiles);
		tree->Add( LoadPath.c_str());
		TFile* newfile = new TFile( SavePath.c_str() ,"recreate");
		TTree* newtree = new TTree("tree","I am a new tree");
		cout <<"Folder and Tree Created"<<endl;

		/////////////////////// Connect the Tree, Branch, leaf ////////////////=============================================================================
		EvtInfoBranches EvtInfo;
		VertexInfoBranches VertexInfo;
		GenInfoBranches GenInfo;
		JetInfoBranches CA8JetInfo;
		JetInfoBranches AK5JetInfo;
		JetInfoBranches SubJetInfo;
		EvtInfo.Register(tree);
		VertexInfo.Register(tree);
		GenInfo.Register(tree);	
		CA8JetInfo.Register(tree,"FatJetInfo");
		AK5JetInfo.Register(tree,"JetInfo");
		SubJetInfo.Register(tree,"SubJetInfo");
		cout <<"Branch Registed"<<endl;
	
		JetInfoBranches NewCA8JetInfo;
		JetInfoBranches NewAK5JetInfo;
		JetInfoBranches NewSubJetInfo;
		NewCA8JetInfo.RegisterTree(newtree,"FatJetInfo");
		NewAK5JetInfo.RegisterTree(newtree,"JetInfo");
		NewSubJetInfo.RegisterTree(newtree,"SubJetInfo");
		cout <<"New Branch Registed"<<endl;

		////////////////////// Initialize the Histogram ///////////////////////=============================================================================
		th1Initial h1;   // Refer to plotInfo.h
		th2Initial h2;   // Refer to plotInfo.h
		h1.GetTH1F("Event.NumEvtCutFlow")->GetXaxis()->SetBinLabel(1,"AllEvents");
		h1.GetTH1F("Event.NumEvtCutFlow")->GetXaxis()->SetBinLabel(2,"TriggerSel");
		h1.GetTH1F("Event.NumEvtCutFlow")->GetXaxis()->SetBinLabel(3,"HiggsJetSel");
		h1.GetTH1F("Event.NumEvtCutFlow")->GetXaxis()->SetBinLabel(4,"BJetsSel");
		h1.GetTH1F("Event.NumEvtCutFlow")->GetXaxis()->SetBinLabel(5,"HTSel");
		
		///////////////////// Get by event to Analysis ////////////////////////=============================================================================
		for( int entry=0; entry<tree->GetEntries(); entry++ ){
			if( entry%100 == 0 )  cout<<".";
			if( entry%10000 == 0 ) cout<<entry;	//if( entry%10000 == 0 ) printf("%1.3f \%\r",(100.*entry/tree->GetEntries()));
			tree->GetEntry(entry);
			//bool isData_ = EvtInfo.McFlag ? 0 : 1; //if(EvtInfo.McFlag){ isData=0; } else { isData=1; } 
			
			//if( GenInfo.MttCut() )	continue; //Only for TTJet Hadron decay samples

			///////===================================================================================================================================
			/////// Selection Rest Event num ///////=====================================================================================================
			///////===================================================================================================================================
			vector<TLorentzVector>higgsJets;
			vector<TLorentzVector>jets; 
			vector<TLorentzVector>bJets; 
			vector<TLorentzVector>bprimes; 

			int	njets(0); 
			int	nCA8jets(0); 
			int	nGoodVtxs(0);
			double 	HT(0); 
			bool	bprimeEvt=false;

			// Select good vertices //===================================================================================================================
			for( int iVtx=0; iVtx < VertexInfo.Size; ++iVtx ){
				if( VertexInfo.Type[iVtx]==1 && VertexInfo.isFake[iVtx]==false && VertexInfo.Ndof[iVtx]>4 && VertexInfo.Rho[iVtx]<2. && VertexInfo.z[iVtx]<24.	){
					 ++nGoodVtxs; 
				}
			}
			if( nGoodVtxs<1 ){ 
				cout<<endl<<"Vtx!"<<endl; 
				continue; 
			}

			// Events information //========================================================================================================================
			h1.GetTH1F("Event.NumEvtCutFlow")->Fill("AllEvents",1);
			if( EvtInfo.TrgBook[3225]==1 || EvtInfo.TrgBook[4893]==1 ){
				h1.GetTH1F("Event.NumEvtCutFlow")->Fill("TriggerSel",1);
			}else{ 
				continue; 
			}

			// Generate information //========================================================================================================================
			TLorentzVector Higgs; 
			for( int i=0; i<GenInfo.Size; ++i ){
				//if( GenInfo.Status[i] == 3 && abs(GenInfo.PdgID[i])==25 && GenInfo.nDa[i] == 2 && abs(GenInfo.PdgID[GenInfo.Da1[i]])==5 && abs(GenInfo.PdgID[GenInfo.Da2[i]])==5 ){ 
				if( GenInfo.Status[i]==3 && abs(GenInfo.PdgID[i])==25 ){ 
					Higgs.SetPtEtaPhiM( GenInfo.Pt[i], GenInfo.Eta[i], GenInfo.Phi[i], GenInfo.Mass[i]); 
					h1.GetTH1F("Gen.Higgs.Pt")->Fill(Higgs.Pt()); 

					for( int j=0; j<CA8JetInfo.Size; ++j ){ 
						if( fabs(CA8JetInfo.Eta[j])>1.5 ) continue; 
						TLorentzVector FatJet;
						FatJet.SetPtEtaPhiM( CA8JetInfo.Pt[j], CA8JetInfo.Eta[j],CA8JetInfo.Phi[j], CA8JetInfo.Mass[j]);
						if( Higgs.DeltaR(FatJet)<0.5 ){
							h1.GetTH1F("Gen.MatchedHiggs.Pt")->Fill(Higgs.Pt()); 
							break;  //by Enili, I think this is not correct !
						}
					} //fat jets 
				} //Higgs 
			} //gen particles 

			// CA8 Jet and Higgs Jet //================================================================================================================
			for( int i=0; i < CA8JetInfo.Size; ++i ){
				//// CA8 jet selection
				if( CA8JetInfo.Pt[i]<CA8JetPt_Min || CA8JetInfo.Pt[i]>CA8JetPt_Max ) continue; //// apply jet pT cut
				if( fabs(CA8JetInfo.Eta[i])>CA8JetAbsEta ) continue; //// apply jet eta cut
				if( CA8JetInfo.JetIDLOOSE[i] == 0 ) continue; //// apply loose jet ID
				if( CA8JetInfo.MassPruned[i]<CA8JetPrunedMass_Min || CA8JetInfo.MassPruned[i]>CA8JetPrunedMass_Max ) continue; //// apply pruned jet mass cut 

				TLorentzVector FatJet;
				FatJet.SetPtEtaPhiM( CA8JetInfo.Pt[i], CA8JetInfo.Eta[i], CA8JetInfo.Phi[i], CA8JetInfo.Mass[i] );

				nCA8jets++;
				h1.GetTH1F("CA8Jet.SelectCA8.Pt")->Fill(FatJet.Pt());  
				h1.GetTH1F("CA8Jet.SelectCA8.Eta")->Fill(FatJet.Eta()); 
				h1.GetTH1F("CA8Jet.SelectCA8.Phi")->Fill(FatJet.Phi()); 
				h1.GetTH1F("CA8Jet.SelectCA8.Mass")->Fill(FatJet.Mag()); 
				h1.GetTH1F("CA8Jet.SelectCA8.MassPruned")->Fill(CA8JetInfo.MassPruned[i]); 
				h1.GetTH1F("CA8Jet.SelectCA8.Tau2ByTau1")->Fill(CA8JetInfo.tau2[i]/CA8JetInfo.tau1[i]); 
				h1.GetTH1F("CA8Jet.SelectCA8.Tau3ByTau2")->Fill(CA8JetInfo.tau3[i]/CA8JetInfo.tau2[i]); 
				h1.GetTH1F("CA8Jet.SelectCA8.Tau3ByTau1")->Fill(CA8JetInfo.tau3[i]/CA8JetInfo.tau1[i]); 
				h1.GetTH1F("CA8Jet.SelectCA8.CSV")->Fill(CA8JetInfo.CombinedSVBJetTags[i]); 

				//// Get subjets of fat jets 
				int iSub1 = CA8JetInfo.Jet_SubJet1Idx[i];
				int iSub2 = CA8JetInfo.Jet_SubJet2Idx[i];

				if( SubJetInfo.Pt[iSub1]==0. || SubJetInfo.Pt[iSub2]==0. ) continue; //// skip fat jets for which one of the subjets has pT=0

				TLorentzVector Subjet1, Subjet2;
				Subjet1.SetPtEtaPhiM(SubJetInfo.Pt[iSub1], SubJetInfo.Eta[iSub1], SubJetInfo.Phi[iSub1], SubJetInfo.Mass[iSub1]);
				Subjet2.SetPtEtaPhiM(SubJetInfo.Pt[iSub2], SubJetInfo.Eta[iSub2], SubJetInfo.Phi[iSub2], SubJetInfo.Mass[iSub2]);

				//double subjet_dR = Subjet1.DeltaR(Subjet2);
				double subjet_dy = Subjet1.Rapidity() - Subjet2.Rapidity();
				double subjet_dphi = Subjet1.DeltaPhi(Subjet2);;
				double subjet_dyphi = sqrt( subjet_dy*subjet_dy + subjet_dphi*subjet_dphi );

				if( subjet_dyphi <(CA8JetInfo.Mass[i]/CA8JetInfo.Pt[i]) ) continue; //// skip infrared unsafe configurations

				h1.GetTH1F("SubJet1.SelectCA8Sub.Pt")->Fill(Subjet1.Pt());  
				h1.GetTH1F("SubJet1.SelectCA8Sub.Eta")->Fill(Subjet1.Eta()); 
				h1.GetTH1F("SubJet1.SelectCA8Sub.Phi")->Fill(Subjet1.Phi()); 
				h1.GetTH1F("SubJet1.SelectCA8Sub.Mass")->Fill(Subjet1.Mag()); 
				h1.GetTH1F("SubJet1.SelectCA8Sub.CSV")->Fill(SubJetInfo.CombinedSVBJetTags[iSub1]); 

				h1.GetTH1F("SubJet2.SelectCA8Sub.Pt")->Fill(Subjet2.Pt());  
				h1.GetTH1F("SubJet2.SelectCA8Sub.Eta")->Fill(Subjet2.Eta()); 
				h1.GetTH1F("SubJet2.SelectCA8Sub.Phi")->Fill(Subjet2.Phi()); 
				h1.GetTH1F("SubJet2.SelectCA8Sub.Mass")->Fill(Subjet2.Mag()); 
				h1.GetTH1F("SubJet2.SelectCA8Sub.CSV")->Fill(SubJetInfo.CombinedSVBJetTags[iSub2]); 

				//// Higgs tagging
				if(	FatJet.Mag() > CA8JetMass_Min 
					&& FatJet.Mag() < CA8JetMass_Max 
					&& CA8JetInfo.tau2[i]/CA8JetInfo.tau1[i] < CA8JetTau2ByTau1_Max 
					&& SubJetInfo.CombinedSVBJetTags[iSub1] > Subjet1CSV_Min 
					&& SubJetInfo.CombinedSVBJetTags[iSub1] < Subjet1CSV_Max 
					&& SubJetInfo.CombinedSVBJetTags[iSub2] > Subjet2CSV_Min 
					&& SubJetInfo.CombinedSVBJetTags[iSub2] < Subjet2CSV_Max	){ 

					h1.GetTH1F("HiggsJet.Pt")-> Fill(FatJet.Pt()); 
					h1.GetTH1F("HiggsJet.Eta")-> Fill(FatJet.Eta());
					h1.GetTH1F("HiggsJet.Phi")-> Fill(FatJet.Phi());
					h1.GetTH1F("HiggsJet.Mass")-> Fill(FatJet.Mag());
					higgsJets.push_back(FatJet); 
				}// Higgs Jet
			} //// CA8 jets 
			h1.GetTH1F("Event.NumSelectCA8Jets")->Fill(nCA8jets); 
			h1.GetTH1F("Event.NumHiggsJets")->Fill(higgsJets.size()); 

			// AK5 Jet and b Jet //================================================================================================================
			for( int i=0; i<AK5JetInfo.Size; ++i){ 
				if( AK5JetInfo.Pt[i] < AK5JetPt_Min || AK5JetInfo.Pt[i] > AK5JetPt_Max ) continue; 
				if( fabs(AK5JetInfo.Eta[i]) > AK5JetAbsEta ) continue; 
				if( AK5JetInfo.JetIDTIGHT[i]==0 ) continue; 

				++njets; 
				h1.GetTH1F("Event.NumSelectAK5Jets")->Fill(njets); 

				TLorentzVector AK5;
				AK5.SetPtEtaPhiM(AK5JetInfo.Pt[i], AK5JetInfo.Eta[i], AK5JetInfo.Phi[i], AK5JetInfo.Mass[i]);
				h1.GetTH1F("AK5Jet.SelectAK5.Pt")->Fill(AK5.Pt());  
				h1.GetTH1F("AK5Jet.SelectAK5.Eta")->Fill(AK5.Eta()); 
				h1.GetTH1F("AK5Jet.SelectAK5.Phi")->Fill(AK5.Phi()); 
				h1.GetTH1F("AK5Jet.SelectAK5.Mass")->Fill(AK5.Mag()); 
				h1.GetTH1F("AK5Jet.SelectAK5.CSV")->Fill(AK5JetInfo.CombinedSVBJetTags[i]); 

				bool isJetNotHiggs(false); 
				for( vector<TLorentzVector>::const_iterator ihig = higgsJets.begin(); ihig != higgsJets.end(); ++ihig ){
					if(AK5.DeltaR(*ihig) < 1.2){
						isJetNotHiggs = false; 
						break; 
					}
					else {
						isJetNotHiggs = true; 
					} 
				} 
				if(!isJetNotHiggs) continue; //// Higgs-b jet disambiguation  
				jets.push_back(AK5); 

				if( AK5JetInfo.Pt[i] >= bJetPt_Min && AK5JetInfo.CombinedSVBJetTags[i] > 0.679){
					TLorentzVector bJet;
					bJet.SetPtEtaPhiM(AK5JetInfo.Pt[i], AK5JetInfo.Eta[i], AK5JetInfo.Phi[i], AK5JetInfo.Mass[i]);
					h1.GetTH1F("bJet.Pt")->Fill(bJet.Pt());  
					h1.GetTH1F("bJet.Eta")->Fill(bJet.Eta()); 
					h1.GetTH1F("bJet.Phi")->Fill(bJet.Phi()); 
					h1.GetTH1F("bJet.Mass")->Fill(bJet.Mag()); 
					h1.GetTH1F("bJet.CSV")->Fill(AK5JetInfo.CombinedSVBJetTags[i]); 
					bJets.push_back(bJet); 
				} // Select b-tagged AK5 jets 
			} // AK5 jets 
			h1.GetTH1F("Event.NumbJets")->Fill(bJets.size()); 

			// bprime Select //================================================================================================================
			if( higgsJets.size()>=1 ){
				h1.GetTH1F("Event.NumEvtCutFlow")->Fill("HiggsJetSel",1);
				if( bJets.size() >= 2 ){ 
					h1.GetTH1F("Event.NumEvtCutFlow")->Fill("BJetsSel",1);
					for( vector<TLorentzVector>::const_iterator ihig = higgsJets.begin(); ihig != higgsJets.end(); ++ihig){ 
						HT += ihig->Pt(); 
					}
					for( vector<TLorentzVector>::const_iterator ib = bJets.begin(); ib != bJets.end(); ++ib){ 
						HT += ib->Pt(); 
					}

					//h1.GetTH1F("Event.Before.Ht.bJets.HiggsJets")->Fill(HT);
					if( HT < Ht_Min || HT > Ht_Max ) continue; 
					h1.GetTH1F("Event.NumEvtCutFlow")->Fill("HTSel",1);
					h1.GetTH1F("Event.Ht.bJets.HiggsJets")->Fill(HT);

					for( vector<TLorentzVector>::const_iterator ihig = higgsJets.begin(); ihig != higgsJets.end(); ++ihig ){ 
						const TLorentzVector* closestBJet;
						double deltaR(TMath::Pi()); 
						for( vector<TLorentzVector>::const_iterator ib = bJets.begin(); ib != bJets.end(); ++ib ){ 
							if( ihig->DeltaR(*ib) < deltaR){
								deltaR = ihig->DeltaR(*ib); 
								closestBJet = &(*ib); 
							}
						}
						if( deltaR < TMath::Pi() ){
							TLorentzVector bprime = *ihig + *closestBJet;
							bprimes.push_back(bprime); 
							h1.GetTH1F("bprime.Pt")->Fill(bprime.Pt());  
							h1.GetTH1F("bprime.Eta")->Fill(bprime.Eta()); 
							h1.GetTH1F("bprime.Phi")->Fill(bprime.Phi()); 
							h1.GetTH1F("bprime.Mass")->Fill(bprime.Mag());
							bprimeEvt=true; 
						}
					} //get bprime
				} // If at least two b-jets 
			} // If at least one Higgs jet 

			///////===================================================================================================================================
			/////// Fill new tree for Event including bprime ///////============================================================================================================
			///////===================================================================================================================================
			if( !bprimeEvt ) continue;
			reRegestJet(AK5JetInfo,NewAK5JetInfo);	
			reRegestJet(CA8JetInfo,NewCA8JetInfo);	
			reRegestJet(SubJetInfo,NewSubJetInfo);	
			newtree->Fill();
		}//entry
		cout<<endl<<tree->GetEntries()<<endl<<"Finished ^____^"<<endl;
		/////////////////////// Save the root file ///////////////////////////===============================================================================
		newfile->Write();
		cout<<"Sample "<<QCDMC[iSample].name<<" End !!!"<<endl<<endl;
	}// masspoint
}
