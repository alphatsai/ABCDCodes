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
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/selection.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/myformat.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/function.C"
//#include "//afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/format.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/sampleInfo.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/plotsInfoABCD.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/setTDRStyle_2d.C"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/interface/histoInital.C"
using namespace std;
void setABCDcutRegion(TH1F* h1){
	h1->GetXaxis()->SetBinLabel(1,"A");
	h1->GetXaxis()->SetBinLabel(2,"B");
	h1->GetXaxis()->SetBinLabel(3,"C");
	h1->GetXaxis()->SetBinLabel(4,"D");
}
template <typename xType, typename yType, typename wType>
void fillABCDcutRegion(TH1F* h1, xType xVar, xType xCut, yType yVar, yType yCut, wType weight){
	if ( xVar<=xCut && yVar>yCut){
		h1->Fill("A",weight);
	}else if( xVar>xCut && yVar>yCut){
		h1->Fill("B",weight);
	}else if( xVar<=xCut && yVar<=yCut){
		h1->Fill("C",weight);
	}else if( xVar>xCut && yVar<=yCut){
		h1->Fill("D",weight);
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////// Analysis start //////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void abcd2(){
	for( int iSample=(Category[2].SampleSize)/2; iSample<Category[2].SampleSize; iSample++){   //FullPart
		cout<<"For "<<QCDMC[iSample].sample<<endl;
		///////////////////// Create New Tree and Forder //////////////////////==============================================================================
		string LoadPath	 = "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1209/result/root/mc/bg/"+QCDMC[iSample].name+".root";
		string SavePath  = "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1218/result/root/abcd/abcd_"+QCDMC[iSample].name+".root";
		TFile* file = new TFile(LoadPath.c_str());
		TTree* tree = (TTree*)file->Get("BprimebH/tree");
		TFile* newfile = new TFile( SavePath.c_str() ,"recreate");
		cout <<"Folder Created"<<endl;

		/////////////////////// Connect the Tree, Branch, leaf ////////////////=============================================================================
		bool McFlag;
		double puEvtw;
		tree->SetBranchAddress("EvtInfo.WeightEvtPU",&puEvtw);
		tree->SetBranchAddress("EvtInfo.McFlag",&McFlag);

		GenInfoBranches GenInfo;
		JetInfoBranches CA8JetInfo;
		JetInfoBranches AK5JetInfo;
		JetInfoBranches SubJetInfo;

		GenInfo.Register(tree);
		CA8JetInfo.Register(tree,"FatJetInfo");
		AK5JetInfo.Register(tree,"JetInfo");
		SubJetInfo.Register(tree,"SubJetInfo");
		cout <<"Branch Registed"<<endl;
		
		TH1F* h_evtNum=(TH1F*)file->Get("BprimebH/EvtInfo.Entries");  //call the original events
		int totalEvt = h_evtNum->GetEntries();
		//TH1F* h_evtNum=(TH1F*)file->Get("BprimebH/EvtInfo.CutFlow");  //call the original events
		//int totalEvt = h_evtNum->GetBinContent(1);


        	TH1F* bJetVeto_pt = new TH1F("bJetInfo.Pt.Veto",        "", 1500, 0, 1500);
        	TH1F* bJetVeto_eta = new TH1F("bJetInfo.Eta.Veto",        "", 600, -3, 3);
        	TH1F* bJetVeto_CSV =  new TH1F("bJetInfo.CSV.Veto",         "", 100,  0, 1.);

		////////////////////// Initialize the Histogram ///////////////////////=============================================================================
		th1Initial h1;
		th2Initial h2;
		h1.Sumw2();
		h2.Initial();
		setABCDcutRegion(h1.GetTH1F("ABCD1.SubjetPt_Ht"));	
		setABCDcutRegion(h1.GetTH1F("ABCD2.SubLeadingSubCSV_HtAK5CA8"));	
		cout<<"New histo created"<<endl;

		///////////////////// Get by event to Analysis ////////////////////////=============================================================================
		cout<<"Entries:" <<tree->GetEntries()<<" running..."<<endl;
		int evtPass=0;
		for( int entry=0; entry<tree->GetEntries(); entry++ ){
			tree->GetEntry(entry);
			if ( entry%10000==0 ) cout<<".";
			if ( entry%500000==0 ) cout<<entry;

			double weight=1;
			if( McFlag == 1 ){
				double weightSample = QCDMC[iSample].xsec*lumi*1000/totalEvt;
				weight = puEvtw*weightSample;
			}
			int numLeadingSubJet_1=0;
			float Pt_leadingSubJet_1=0;
			float Pt_SubleadingSubJet_1=0;
			float CSV_leadingSubJet_1=0;
			float CSV_SubleadingSubJet_1=0;
			float dR_leadingSubJet_1=0;

			int numLeadingSubJet_2=0;
			float Pt_leadingSubJet_2=0;
			float Pt_SubleadingSubJet_2=0;
			float CSV_leadingSubJet_2=0;
			float CSV_SubleadingSubJet_2=0;

			int CA8NoTua=0;
			int numHiggsNoTua_1=0;
			int numCA8NoTua_1=0;
			int numbJet=0;
			float Ht_AK5=0;
			float Ht_bJetHiggs=0;
			
			int numbJetNoPt=0;
			int Pt_leadingCA8=-1;

			vector<TLorentzVector> GenHiggsbb;
			vector<TLorentzVector> GenHiggsOther;
			for( int i=0; i<GenInfo.Size && McFlag == 1; i++){
				if( GenInfo.PdgID[i]!=25 || GenInfo.nDa[i]<2) continue;
					h1.GetTH1F("GenInfo.HiggsDaPdgID")->Fill(GenInfo.Da0PdgID[i]);	
					h1.GetTH1F("GenInfo.HiggsDaPdgID")->Fill(GenInfo.Da1PdgID[i]);	
				if( abs(GenInfo.Da0PdgID[i])==5 && (GenInfo.Da0PdgID[i]/GenInfo.Da1PdgID[i])==-1){
					TLorentzVector Hbb;
					Hbb.SetPtEtaPhiM(GenInfo.Pt[i], GenInfo.Eta[i], GenInfo.Phi[i], GenInfo.Mass[i]);		
					GenHiggsbb.push_back(Hbb);
				}else{
					TLorentzVector Hother;
					Hother.SetPtEtaPhiM(GenInfo.Pt[i], GenInfo.Eta[i], GenInfo.Phi[i], GenInfo.Mass[i]);
					GenHiggsOther.push_back(Hother);
				}
			}
			h1.GetTH1F("GenInfo.NumHiggsTobb")->Fill(GenHiggsbb.size());	
			h1.GetTH1F("GenInfo.NumHiggsToOther")->Fill(GenHiggsOther.size());	
			
			vector<TLorentzVector> CA8Jets;
			// CA8 Jet //================================================================================================================
			for( int i=0; i < CA8JetInfo.Size; ++i ){
				if( fabs(CA8JetInfo.Eta[i])>CA8JetAbsEta ) continue; //// apply jet eta cut
				if( CA8JetInfo.NHF[i]>=0.99 || CA8JetInfo.NEF[i]>=0.99 || CA8JetInfo.NConstituents[i]<=1 || fabs(CA8JetInfo.Eta[i]) >=2.4 || CA8JetInfo.CHF[i]<=0 || CA8JetInfo.CEF[i]>=0.99 ||  CA8JetInfo.NCH[i]<=0 ) continue; //// apply loose jet ID

				if( CA8JetInfo.Pt[i]<50 ) continue;
				if( CA8JetInfo.Pt[i]<CA8JetPt_Min || CA8JetInfo.Pt[i]>CA8JetPt_Max ) continue; //// apply jet pT cut
			
				//// Get subjets of fat jets
				int iSub1 = CA8JetInfo.Jet_SubJet1Idx[i];
				int iSub2 = CA8JetInfo.Jet_SubJet2Idx[i];

				if( SubJetInfo.Pt[iSub1]==0. || SubJetInfo.Pt[iSub2]==0. ) continue; //// skip fat jets for which one of the subjets has pT=0

				TLorentzVector Subjet1, Subjet2;
				Subjet1.SetPtEtaPhiM(SubJetInfo.Pt[iSub1], SubJetInfo.Eta[iSub1], SubJetInfo.Phi[iSub1], SubJetInfo.Mass[iSub1]);
				Subjet2.SetPtEtaPhiM(SubJetInfo.Pt[iSub2], SubJetInfo.Eta[iSub2], SubJetInfo.Phi[iSub2], SubJetInfo.Mass[iSub2]);

				double subjet_dy = Subjet1.Rapidity() - Subjet2.Rapidity();
				double subjet_dphi = Subjet1.DeltaPhi(Subjet2);
				double subjet_dyphi = sqrt( subjet_dy*subjet_dy + subjet_dphi*subjet_dphi );

				if( subjet_dyphi <(CA8JetInfo.Mass[i]/CA8JetInfo.Pt[i]) ) continue; //// skip infrared unsafe configurations
				if( CA8JetInfo.MassPruned[i]<CA8JetPrunedMass_Min || CA8JetInfo.MassPruned[i]>CA8JetPrunedMass_Max ) continue; //// apply pruned jet mass cut 
				if( CA8JetInfo.Mass[i] <= CA8JetMass_Min || CA8JetInfo.Mass[i] >= CA8JetMass_Max) continue;

				if( CA8JetInfo.tau2[i]/CA8JetInfo.tau1[i] >= CA8JetTau2ByTau1_Max) continue;

				numHiggsNoTua_1++;
				TLorentzVector CA8Jet;
				CA8Jet.SetPtEtaPhiM(CA8JetInfo.Pt[i], CA8JetInfo.Eta[i], CA8JetInfo.Phi[i], CA8JetInfo.Mass[i]);
				CA8Jets.push_back(CA8Jet);
				Ht_bJetHiggs = Ht_bJetHiggs + CA8JetInfo.Pt[i];

				h1.GetTH1F("CA8Jet.Pt")->Fill(CA8JetInfo.Pt[i],weight);
				
				if( Pt_leadingCA8 < CA8JetInfo.Pt[i] ){ // choose leading CA8
					Pt_leadingCA8=CA8JetInfo.Pt[i];
					////////////// Pt comparation //////////////////////////////////////////////////////////////////////////////	
					if( Subjet1.Pt() >= Subjet2.Pt() ){ ///// Pt Sub1>Sub2
						// Constrain leading SubJet CSVM
						if( SubJetInfo.CombinedSVBJetTags[iSub1] > 0.244){
						//if( SubJetInfo.CombinedSVBJetTags[iSub1] > 0.679){
						//if( SubJetInfo.CombinedSVBJetTags[iSub1] > 0.679 && SubJetInfo.CombinedSVBJetTags[iSub2]>0.244){
							CSV_leadingSubJet_2	=SubJetInfo.CombinedSVBJetTags[iSub1];
							CSV_SubleadingSubJet_2	=SubJetInfo.CombinedSVBJetTags[iSub2];
							Pt_leadingSubJet_2	=SubJetInfo.Pt[iSub1];
							Pt_SubleadingSubJet_2	=SubJetInfo.Pt[iSub2];
							numLeadingSubJet_2++;
						}
						// Constrain Sub-leading SubJet CSVM
						if( SubJetInfo.CombinedSVBJetTags[iSub2] > 0.244 ){
						//if( SubJetInfo.CombinedSVBJetTags[iSub2] > 0.679 ){
						//if( SubJetInfo.CombinedSVBJetTags[iSub2] > 0.679 && SubJetInfo.CombinedSVBJetTags[iSub1]>0.244){
							CSV_leadingSubJet_1	=SubJetInfo.CombinedSVBJetTags[iSub1];
							CSV_SubleadingSubJet_1	=SubJetInfo.CombinedSVBJetTags[iSub2];
							Pt_leadingSubJet_1	=SubJetInfo.Pt[iSub1];
							Pt_SubleadingSubJet_1	=SubJetInfo.Pt[iSub2];
							dR_leadingSubJet_1	=dR(SubJetInfo.Eta[iSub1],CA8JetInfo.Eta[i],SubJetInfo.Phi[iSub1],CA8JetInfo.Phi[i]);
							numLeadingSubJet_1++;
						}
					}else{ ////// Pt Sub2>Sub1
						// Constrain leading SubJet CSVM
						if( SubJetInfo.CombinedSVBJetTags[iSub2] > 0.244){
						//if( SubJetInfo.CombinedSVBJetTags[iSub2] > 0.679){
						//if( SubJetInfo.CombinedSVBJetTags[iSub2] > 0.679 && SubJetInfo.CombinedSVBJetTags[iSub1]>0.244){
							CSV_leadingSubJet_2	=SubJetInfo.CombinedSVBJetTags[iSub2];
							CSV_SubleadingSubJet_2	=SubJetInfo.CombinedSVBJetTags[iSub1];
							Pt_leadingSubJet_2	=SubJetInfo.Pt[iSub2];
							Pt_SubleadingSubJet_2	=SubJetInfo.Pt[iSub1];
							numLeadingSubJet_2++;
						}
						// Constrain Sub-leading SubJet CSVM
						if( SubJetInfo.CombinedSVBJetTags[iSub1] > 0.244){
						//if( SubJetInfo.CombinedSVBJetTags[iSub1] > 0.679){
						//if( SubJetInfo.CombinedSVBJetTags[iSub1] > 0.679 && SubJetInfo.CombinedSVBJetTags[iSub2]>0.244){
							CSV_leadingSubJet_1	=SubJetInfo.CombinedSVBJetTags[iSub2];
							CSV_SubleadingSubJet_1	=SubJetInfo.CombinedSVBJetTags[iSub1];
							Pt_leadingSubJet_1	=SubJetInfo.Pt[iSub2];
							Pt_SubleadingSubJet_1	=SubJetInfo.Pt[iSub1];
							dR_leadingSubJet_1	=dR(SubJetInfo.Eta[iSub2],CA8JetInfo.Eta[i],SubJetInfo.Phi[iSub2],CA8JetInfo.Phi[i]);
							numLeadingSubJet_1++;
						}
					}

				}

			}//CA8

			// AK5 Jet and b Jet //================================================================================================================
			for( int i=0; i<AK5JetInfo.Size; ++i){
				bJetVeto_pt->Fill(AK5JetInfo.Pt[i],weight);
				bJetVeto_eta->Fill(AK5JetInfo.Eta[i],weight);
				bJetVeto_CSV->Fill(AK5JetInfo.CombinedSVBJetTags[i],weight);			
	
				if( fabs(AK5JetInfo.Eta[i]) > AK5JetAbsEta ) continue; 
				if ( AK5JetInfo.NHF[i]>=0.90 || AK5JetInfo.NEF[i]>=0.90 || AK5JetInfo.NConstituents[i]<=1 || fabs(AK5JetInfo.Eta[i]) >=2.4 || AK5JetInfo.CHF[i]<=0 || AK5JetInfo.CEF[i]>=0.99 ||  AK5JetInfo.NCH[i]<=0 ) continue; //// apply loose jet ID

				if( AK5JetInfo.Pt[i] >= 30 ){ 
					Ht_AK5 = Ht_AK5 + AK5JetInfo.Pt[i];
					h1.GetTH1F("AK5Jet.Pt")->Fill(AK5JetInfo.Pt[i],weight);
				}

				if( AK5JetInfo.Pt[i] < AK5JetPt_Min || AK5JetInfo.Pt[i] > AK5JetPt_Max ) continue; 
				TLorentzVector AK5;
				AK5.SetPtEtaPhiM(AK5JetInfo.Pt[i], AK5JetInfo.Eta[i], AK5JetInfo.Phi[i], AK5JetInfo.Mass[i]);

				bool isNotCA8(false); 
				for( vector<TLorentzVector>::const_iterator j = CA8Jets.begin(); j != CA8Jets.end(); ++j ){
					if(AK5.DeltaR(*j) < 1.2){
						isNotCA8 = false; 
						break; 
					}else {
						isNotCA8 = true; 
					} 
				}
				if(!isNotCA8) continue;

				if( AK5JetInfo.CombinedSVBJetTags[i]<=0.679 ) continue; 


				if( AK5JetInfo.Pt[i] <= bJetPt_Min) continue; 

				Ht_bJetHiggs = Ht_bJetHiggs + AK5JetInfo.Pt[i];

				numbJet++;
				h1.GetTH1F("bJet.Pt")->Fill(AK5JetInfo.Pt[i],weight);

			}//AK5 end
		
			///// Fill evt and ABCD plots //==================================================================================================================================================	

			//if( numbJet>=2 && numHiggsNoTua_1>=1){ //constriant the evt 
			if( numHiggsNoTua_1>=1){ //constriant the evt 
				//float Ht=Ht_AK5;
				float Ht=Ht_bJetHiggs;
				//// ABCD 1 //==========================================================================
//				if( numLeadingSubJet_1!=0 && GenHiggsbb.size()==2 && GenHiggsOther.size()==0 ){ //no_bg,  this line will be command by sync.csh
				if( numLeadingSubJet_1!=0 ){ //no_signal, this line will be command by sync.csh
					h1.GetTH1F("Event.HtAK5CA8.ABCD1")->Fill(Ht,weight);
					h1.GetTH1F("CA8Jet.Leading.Pt.ABCD1")->Fill(Pt_leadingCA8,weight);
					h1.GetTH1F("SubJet.Leading.Pt.ABCD1")->Fill(Pt_leadingSubJet_1,weight);
					//h1.GetTH1F("SubJet.Leading.CSV.ABCD1")->Fill(CSV_leadingSubJet_1,weight);
					h1.GetTH1F("SubJet.Leading.CSV.ABCD1")->Fill(CSV_leadingSubJet_1);
					h1.GetTH1F("SubJet.SubLeading.Pt.ABCD1")->Fill(Pt_SubleadingSubJet_1,weight);
					h1.GetTH1F("SubJet.SubLeading.CSV.ABCD1")->Fill(CSV_SubleadingSubJet_1,weight);
					h2.GetTH2F("HtAK5CA8.LeadingSubCSV")->Fill(Ht,CSV_leadingSubJet_1,weight);
					fillABCDcutRegion<float, float, float>(h1.GetTH1F("ABCD1.SubjetPt_Ht"),Ht,1000,CSV_leadingSubJet_1,0.244,weight);
				}
//				if( numLeadingSubJet_2!=0 && GenHiggsbb.size()==2 && GenHiggsOther.size()==0 ){ //no_bg,  this line will be command by sync.csh
				if( numLeadingSubJet_2!=0 ){ //no_signal, this line will be command by sync.csh
					h1.GetTH1F("Event.HtAK5CA8.ABCD2")->Fill(Ht,weight);
					h1.GetTH1F("CA8Jet.Leading.Pt.ABCD2")->Fill(Pt_leadingCA8,weight);
					h1.GetTH1F("SubJet.Leading.Pt.ABCD2")->Fill(Pt_leadingSubJet_2,weight);
					h1.GetTH1F("SubJet.Leading.CSV.ABCD2")->Fill(CSV_leadingSubJet_2,weight);
					h1.GetTH1F("SubJet.SubLeading.Pt.ABCD2")->Fill(Pt_SubleadingSubJet_2,weight);
					h1.GetTH1F("SubJet.SubLeading.CSV.ABCD2")->Fill(CSV_SubleadingSubJet_2,weight);
					h2.GetTH2F("HtAK5CA8.SubLeadingSubCSV")->Fill(Ht,CSV_SubleadingSubJet_2,weight);
					fillABCDcutRegion<float, float, float>(h1.GetTH1F("ABCD2.SubLeadingSubCSV_HtAK5CA8"),Ht,1000,CSV_SubleadingSubJet_2,0.244,weight);

					evtPass++;
				}/////===================================================================================
			}
		}//entries
		newfile->Write();
		cout<<endl<<"evtPass "<<evtPass<<"/"<<tree->GetEntries()<<endl;	
		cout<<"end"<<endl<<endl;
	}//sample
}
