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
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1209/interface/selection.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1209/interface/myformat.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1209/interface/function.C"
//#include "//afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1209/interface/format.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1209/interface/sampleInfo.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1209/interface/plotsInfoABCD.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1209/interface/setTDRStyle_2d.C"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1209/interface/histoInital.C"
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
void abcd(){
	for( int iSample=0; iSample<Category[3].SampleSize; iSample++){   //FullPart
		cout<<"For "<<TTMC[iSample].sample<<endl;
		///////////////////// Create New Tree and Forder //////////////////////==============================================================================
		string LoadPath	 = "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1209/result/root/mc/bg/"+TTMC[iSample].name+".root";
		string SavePath  = "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/1209/result/root/abcd/abcd_"+TTMC[iSample].name+".root";
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
		setABCDcutRegion(h1.GetTH1F("ABCD3.LeadingSubCSV_HtAK5"));	
		setABCDcutRegion(h1.GetTH1F("ABCD4.BigestCSV12_HtAK5CA8"));	
		h1.GetTH1F("Event.NumEvtCutFlow")->GetXaxis()->SetBinLabel(1,"AllEvents");
		h1.GetTH1F("Event.NumEvtCutFlow")->GetXaxis()->SetBinLabel(2,"TriggerSel");
		h1.GetTH1F("Event.NumEvtCutFlow")->GetXaxis()->SetBinLabel(3,"HiggsJetSel");
		h1.GetTH1F("Event.NumEvtCutFlow")->GetXaxis()->SetBinLabel(4,"BJetsSel");
		h1.GetTH1F("Event.NumEvtCutFlow")->GetXaxis()->SetBinLabel(5,"HTSel");
		cout<<"New histo created"<<endl;
	
		TH1F* h1HbbOth = new TH1F("h1_HbbOth", "", 9,0,9);
		h1HbbOth->GetXaxis()->SetBinLabel(1,"bb0_Oth0");
		h1HbbOth->GetXaxis()->SetBinLabel(2,"bb0_Oth1");
		h1HbbOth->GetXaxis()->SetBinLabel(3,"bb0_Oth2");
		h1HbbOth->GetXaxis()->SetBinLabel(4,"bb1_Oth0");
		h1HbbOth->GetXaxis()->SetBinLabel(5,"bb1_Oth1");
		h1HbbOth->GetXaxis()->SetBinLabel(6,"bb1_Oth2");
		h1HbbOth->GetXaxis()->SetBinLabel(7,"bb2_Oth0");
		h1HbbOth->GetXaxis()->SetBinLabel(8,"bb2_Oth1");
		h1HbbOth->GetXaxis()->SetBinLabel(9,"bb2_Oth2");

		///////////////////// Get by event to Analysis ////////////////////////=============================================================================
		cout<<"Entries:" <<tree->GetEntries()<<" running..."<<endl;
		int evtPass=0;
		for( int entry=0; entry<tree->GetEntries(); entry++ ){
			tree->GetEntry(entry);
			if ( entry%10000==0 ) cout<<".";
			if ( entry%500000==0 ) cout<<entry;

			double weight=1;
			if( McFlag == 1 ){
				double weightSample = TTMC[iSample].xsec*lumi*1000/totalEvt;
				weight = puEvtw*weightSample;
			}

			int CA8NoTua=0;
			int numHiggsNoTua_1=0;
			int numCA8NoTua_1=0;
			int numbJet=0;
			float Ht_AK5=0;
			float Ht_CA8=0;
			float Ht_AK5CA8=0;
			float Ht_bJetCA8=0;
			float Ht_bJetCA8_new=0;
			float Ht_CA8AK5noHiggs=0;
			float Ht_CA8bJetnoHiggs=0;
			float Ht_bJetHiggs=0;
			
			int bJet1_1=0;
			int bJet2_1=0;
			int numbJetNoPt=0;

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
				Ht_CA8 = Ht_CA8 + CA8JetInfo.Pt[i];
				Ht_bJetCA8_new = Ht_bJetCA8_new + CA8JetInfo.Pt[i];
				
				if( CA8JetInfo.Pt[i]<CA8JetPt_Min || CA8JetInfo.Pt[i]>CA8JetPt_Max ) continue; //// apply jet pT cut
				Ht_CA8AK5noHiggs = Ht_CA8AK5noHiggs + CA8JetInfo.Pt[i];
				Ht_CA8bJetnoHiggs = Ht_CA8bJetnoHiggs + CA8JetInfo.Pt[i];
			
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

				TLorentzVector CA8Jet;
				CA8Jet.SetPtEtaPhiM(CA8JetInfo.Pt[i], CA8JetInfo.Eta[i], CA8JetInfo.Phi[i], CA8JetInfo.Mass[i]);
				if( subjet_dyphi <(CA8JetInfo.Mass[i]/CA8JetInfo.Pt[i]) ) continue; //// skip infrared unsafe configurations
				if( CA8JetInfo.MassPruned[i]<CA8JetPrunedMass_Min || CA8JetInfo.MassPruned[i]>CA8JetPrunedMass_Max ) continue; //// apply pruned jet mass cut 
				if( CA8JetInfo.Mass[i] <= CA8JetMass_Min || CA8JetInfo.Mass[i] >= CA8JetMass_Max) continue;
				if( SubJetInfo.CombinedSVBJetTags[iSub1]>0.244 && SubJetInfo.CombinedSVBJetTags[iSub2]>0.244){ //Select leading CA8 before Tua2/Tua1
					CA8Jets.push_back(CA8Jet);
					numCA8NoTua_1++;
					if( numCA8NoTua_1 == 1 ){
						CA8NoTua=i;
					}else if( numCA8NoTua_1 > 1 && CA8JetInfo.Pt[i]>CA8JetInfo.Pt[CA8NoTua]){
						CA8NoTua=i;
					}
				}

				if( SubJetInfo.CombinedSVBJetTags[iSub1]>0.244 && SubJetInfo.CombinedSVBJetTags[iSub2]>0.244){ //Count how many CA8-Jets pass without Tua2/Tua1
					Ht_bJetHiggs = Ht_bJetHiggs + CA8JetInfo.Pt[i];
					numHiggsNoTua_1++;
				}

				if( CA8JetInfo.tau2[i]/CA8JetInfo.tau1[i] >= CA8JetTau2ByTau1_Max) continue;
				Ht_AK5CA8  = Ht_AK5CA8  + CA8JetInfo.Pt[i];
				Ht_bJetCA8 = Ht_bJetCA8 + CA8JetInfo.Pt[i];

				h1.GetTH1F("CA8Jet.Pt")->Fill(CA8JetInfo.Pt[i],weight);
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

				Ht_AK5CA8 = Ht_AK5CA8 + AK5JetInfo.Pt[i];  
				Ht_CA8AK5noHiggs = Ht_CA8AK5noHiggs + AK5JetInfo.Pt[i];

				//if( AK5JetInfo.CombinedSVBJetTags[i]<=0.679 ) continue; 
				numbJetNoPt++;

				///// Choose the leading bJet and 2nd-leading b-Jet
				if( numbJetNoPt == 1){ 
					bJet1_1=i;  
				}else if( numbJetNoPt == 2 && AK5JetInfo.Pt[bJet1_1]>AK5JetInfo.Pt[i] ){
					bJet2_1 = i;
				}else if( numbJetNoPt >= 2 && AK5JetInfo.Pt[bJet1_1]<=AK5JetInfo.Pt[i] ){
					bJet2_1 = bJet1_1;
					bJet1_1 = i;
				}//


				if( AK5JetInfo.Pt[i] <= bJetPt_Min) continue; 

				Ht_bJetCA8 = Ht_bJetCA8 + AK5JetInfo.Pt[i];  
				Ht_CA8bJetnoHiggs = Ht_CA8bJetnoHiggs + AK5JetInfo.Pt[i];
				Ht_bJetCA8_new = Ht_bJetCA8_new + AK5JetInfo.Pt[i];
				Ht_bJetHiggs = Ht_bJetHiggs + AK5JetInfo.Pt[i];

				numbJet++;
				h1.GetTH1F("bJet.Pt")->Fill(AK5JetInfo.Pt[i],weight);

			}//AK5 end
		
			///// Fill evt and ABCD plots //==================================================================================================================================================	

			//if( numbJet>=2 ){ //constriant the evt 
			//if( numbJet>=2 && numHiggsNoTua_1>=1){ //constriant the evt 
			if( numHiggsNoTua_1>=1){ //constriant the evt 
				//float Ht=Ht_AK5CA8;
				//float Ht=Ht_AK5;
				float Ht=Ht_bJetHiggs;
				//float Ht=Ht_CA8;
				//float Ht=Ht_CA8AK5noHiggs;
				//float Ht=Ht_bJetCA8;
				//// ABCD 1 //==========================================================================
//				if( numCA8NoTua_1!=0 && GenHiggsbb.size()==2 && GenHiggsOther.size()==0 ){ //no_bg,  this line will be command by sync.csh
				if( numCA8NoTua_1!=0 ){ //no_signal, this line will be command by sync.csh
					h1.GetTH1F("Event.HtAK5CA8.ABCD1")->Fill(Ht,weight);
					h1.GetTH1F("Event.BigestCSV12.ABCD1")->Fill(CA8JetInfo.tau2[CA8NoTua]/CA8JetInfo.tau1[CA8NoTua],weight);
					h1.GetTH1F("CA8Jet.Leading.Pt.ABCD1")->Fill(CA8JetInfo.Pt[CA8NoTua],weight);
					//h1.GetTH1F("SubJet.Leading.Pt.ABCD1")->Fill(AK5JetInfo.Pt[bJet1_1],weight);
					//h1.GetTH1F("SubJet.Leading.CSV.ABCD1")->Fill(AK5JetInfo.CombinedSVBJetTags[bJet1_1],weight);
					//h1.GetTH1F("SubJet.SubLeading.Pt.ABCD1")->Fill(AK5JetInfo.Pt[bJet2_1],weight);
					//h1.GetTH1F("SubJet.SubLeading.CSV.ABCD1")->Fill(AK5JetInfo.CombinedSVBJetTags[bJet2_1],weight);
					h2.GetTH2F("Ht.SubjetPt")->Fill(Ht,CA8JetInfo.tau2[CA8NoTua]/CA8JetInfo.tau1[CA8NoTua],weight);
					fillABCDcutRegion<float, float, float>(h1.GetTH1F("ABCD1.SubjetPt_Ht"),Ht,1000,CA8JetInfo.tau2[CA8NoTua]/CA8JetInfo.tau1[CA8NoTua],0.5,weight);
					evtPass++;
				}/////===================================================================================
			}
		}//entries
		newfile->Write();
		cout<<endl<<"evtPass "<<evtPass<<"/"<<tree->GetEntries()<<endl;	
		cout<<"end"<<endl<<endl;
	}//sample
}
