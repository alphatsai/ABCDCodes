#include <fstream>
#include <iostream>
#include <sstream>
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
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/interface/selection.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/interface/function.C"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/interface/format.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/interface/sampleInfo.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/interface/plotsInfoABCD.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/interface/setTDRStyle_2d.C"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/interface/histoInital.C"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/interface/Jet.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/interface/JetCollection.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/interface/reRegistJet.C"

using namespace std;
string float2str(float i){
	string s;
	stringstream ss(s);
	ss << i;
	return ss.str();
}
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
template <typename vType, typename xType, typename yType, typename wType>
void fillABCDvar(TH1F* ha, TH1F* hb, TH1F* hc, TH1F* hd, vType value, xType xVar, xType xCut, yType yVar, yType yCut, wType weight){
	if ( xVar<=xCut && yVar>yCut){
		ha->Fill( value, weight);
	}else if( xVar>xCut && yVar>yCut){
		hb->Fill( value, weight);
	}else if( xVar<=xCut && yVar<=yCut){
		hc->Fill( value, weight);
	}else if( xVar>xCut && yVar<=yCut){
		hd->Fill( value, weight);
	}
}
int CloseJetIndex( JetCollection jets_, const Jet myJet_ ){
	int min_index(-1);
	for( JetCollection::const_iterator ijet = jets_.begin(); ijet != jets_.end(); ++ijet ){
		float DR_min = 100.;
		if( myJet_.DeltaR(*ijet) < DR_min){
			DR_min = myJet_.DeltaR(*ijet);
			min_index = ijet->Index();   
			//cout<<min_index<<" "<<ijet->Index()<<endl;	 
		}
	}
	return min_index;
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////// Analysis start //////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void abcd(){
	for( int iSample=0; iSample<Category[3].SampleSize; iSample++){   //FullPart

		cout<<"For "<<TTMC[iSample].sample<<endl;

		///////////////////// Create New Tree and Forder //////////////////////==============================================================================
		string LoadPath	 = "/raid1/w/jtsai/bpTobH/skimGeneral/CA8_Pt150_1/"+TTMC[iSample].name+".root";
		string SavePath  = "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/PMbk/result/root/abcd/abcd_"+TTMC[iSample].name+".root";
		TFile* file = new TFile(LoadPath.c_str());
		TTree* tree = (TTree*)file->Get("BprimebH/tree");
		TFile* newfile = new TFile( SavePath.c_str() ,"recreate");
		TTree* newtree_ana;
		if( buildTree ){
			newfile->mkdir("Analysis");
			newfile->cd("Analysis");
				newtree_ana = new TTree("tree", "");
			newfile->cd();
		}
		cout <<"Folder Created"<<endl;

		/////////////////////// Connect the Tree, Branch, leaf ////////////////=============================================================================
		int runNo;
		int GenEvt_;
		Long64_t evtNo;
		int lumiNo;
		bool McFlag, McFlagana;
		double xsec_;
		double PU, PUana;
		double evtWt, evtWtana;
		double HTak5, HThiggsbjet;
		tree->SetBranchAddress("EvtInfo.RunNo",&runNo);
		tree->SetBranchAddress("EvtInfo.EvtNo",&evtNo);
		tree->SetBranchAddress("EvtInfo.LumiNo",&lumiNo);
		tree->SetBranchAddress("EvtInfo.McFlag",&McFlag);
		tree->SetBranchAddress("EvtInfo.PU",&PU);
		tree->SetBranchAddress("EvtInfo.WeightEvt",&evtWt);

		GenInfoBranches GenInfo;
		JetInfoBranches CA8JetInfo, HiggsJetInfoAna, AntiHiggsJetInfoAna;
		JetInfoBranches AK5JetInfo, bJetInfoAna, Final_bJetInfoAna;
		JetInfoBranches SubJetInfo, HiggsSubJet1InfoAna, HiggsSubJet2InfoAna, AntiHiggsSubJet1InfoAna, AntiHiggsSubJet2InfoAna;

		GenInfo.Register(tree);
		CA8JetInfo.Register(tree,"FatJetInfo");
		AK5JetInfo.Register(tree,"JetInfo");
		SubJetInfo.Register(tree,"SubJetInfo");
		
		if( buildTree ){
			newtree_ana->Branch("EvtInfo.GenEvents",	&GenEvt_, 	"EvtInfo.GenEvents/I"); 
			newtree_ana->Branch("EvtInfo.McFlag", 		&McFlagana, 	"EvtInfo.McFlag/O"); 
			newtree_ana->Branch("EvtInfo.XSec", 		&xsec_, 	"EvtInfo.XSec/D"); 
			newtree_ana->Branch("EvtInfo.PU", 		&PUana, 	"EvtInfo.PU/D"); // store weight of evt and pu for each event
			newtree_ana->Branch("EvtInfo.WeightEvt",	&evtWtana, 	"EvtInfo.WeightEvt/D"); 	
			newtree_ana->Branch("EvtInfo.HT_AK5",		&HTak5, 	"EvtInfo.HT_AK5/D"); 	
			newtree_ana->Branch("EvtInfo.HT_HiggsbJets",	&HThiggsbjet, 	"EvtInfo.HT_HiggsbJets/D"); 	
			HiggsJetInfoAna.RegisterTree(newtree_ana,"HiggsJetInfo");
			AntiHiggsJetInfoAna.RegisterTree(newtree_ana,"AntiHiggsJetInfo");
			bJetInfoAna.RegisterTree(newtree_ana,"bJetInfo");
			Final_bJetInfoAna.RegisterTree(newtree_ana,"FinalbJetInfo");
			HiggsSubJet1InfoAna.RegisterTree(newtree_ana,"HiggsSubJet1Info");
			HiggsSubJet2InfoAna.RegisterTree(newtree_ana,"HiggsSubJet2Info");
			AntiHiggsSubJet1InfoAna.RegisterTree(newtree_ana,"AntiHiggsSubJet1Info");
			AntiHiggsSubJet2InfoAna.RegisterTree(newtree_ana,"AntiHiggsSubJet2Info");
		}
		cout <<"Branch Registed"<<endl;
		
		////////////////////// Initialize the Histogram ///////////////////////=============================================================================
		th1Initial h1;
		th2Initial h2;
		h1.Sumw2();
		h2.Initial();
		setABCDcutRegion(h1.GetTH1F("ABCDana_CutRegion"));	
		setABCDcutRegion(h1.GetTH1F("ABCDval_CutRegion"));	
		
		h1.GetTH1F("ABCDana_CutFlow")->GetXaxis()->SetBinLabel(1,"Original");
		h1.GetTH1F("ABCDana_CutFlow")->GetXaxis()->SetBinLabel(2,"HiggsSel");
		h1.GetTH1F("ABCDana_CutFlow")->GetXaxis()->SetBinLabel(3,"bJetsSel");
		h1.GetTH1F("ABCDana_CutFlow")->GetXaxis()->SetBinLabel(4,"ABCDsel");
		h1.GetTH1F("ABCDval_CutFlow")->GetXaxis()->SetBinLabel(1,"Original");
		h1.GetTH1F("ABCDval_CutFlow")->GetXaxis()->SetBinLabel(2,"HiggsSel");
		h1.GetTH1F("ABCDval_CutFlow")->GetXaxis()->SetBinLabel(3,"bJetsSel");
		h1.GetTH1F("ABCDval_CutFlow")->GetXaxis()->SetBinLabel(4,"ABCDsel");

		h2.GetTH2F("ABCDana_2D")->GetXaxis()->SetBinLabel(1,"Anti-Higgs#geq1");
		h2.GetTH2F("ABCDana_2D")->GetXaxis()->SetBinLabel(2,"Higgs#geq1");
		h2.GetTH2F("ABCDval_2D")->GetXaxis()->SetBinLabel(1,"Anti-Higgs#geq1");
		h2.GetTH2F("ABCDval_2D")->GetXaxis()->SetBinLabel(2,"Higgs#geq1");

		TH1F* ca8Num_ana	= new TH1F("ana_CA8Num", "", 5, 0, 5);
		TH1F* ca8Num_val 	= new TH1F("val_CA8Num", "", 5, 0, 5);

		cout<<"New histo created"<<endl;
	
		TH1F* h_evtNum=(TH1F*)file->Get("BprimebH/EvtInfo.Entries");  //call the original events
		int totalEvt = h_evtNum->GetEntries();
		cout<<"Generate evt: "<<totalEvt<<endl;
		cout<<"Evt weight: "<<TTMC[iSample].xsec*lumi*1000/totalEvt<<endl;

		///////////////////// Get by event to Analysis ////////////////////////=============================================================================
		cout<<"Running..."<<endl;
		int evtPass_ana=0;
		int evtPass_val=0;
		double sumw2_a, sumw2_b, sumw2_c, sumw2_d, sumw2_av, sumw2_bv, sumw2_cv, sumw2_dv;
		sumw2_a = sumw2_b = sumw2_c = sumw2_d = sumw2_av= sumw2_bv= sumw2_cv= sumw2_dv = 0.;
		for( int entry=0; entry<tree->GetEntries(); entry++ ){
			tree->GetEntry(entry);

			double weight=1;
			if( McFlag == 1 ){
				double weightSample = TTMC[iSample].xsec*lumi*1000/totalEvt;
				weight = weightSample * PU * evtWt;
			}

			double HT_AK5=0.;
			double HT_HiggsBJets=0.;
			
			h1.GetTH1F("ABCDana_CutFlow")->Fill("Original", weight);
			h1.GetTH1F("ABCDval_CutFlow")->Fill("Original", weight);
			
			vector<int> HiggsIndx;	
			vector<TLorentzVector> GenHiggsbb;
			vector<TLorentzVector> GenHiggsOther;
			for( int i=0; i<GenInfo.Size; i++){
				//if( GenInfo.PdgID[i] == 25 ) cout<<GenInfo.Da0PdgID[i]<<" "<<GenInfo.Da1PdgID[i]<<endl;
				if( GenInfo.PdgID[i]!=25 || GenInfo.nDa[i]<2) continue;
					HiggsIndx.push_back(i);
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
			
			// CA8 Jet //================================================================================================================
			JetCollection HiggsJets;
			JetCollection AntiHiggsJets;
			JetCollection HiggsLikeJets;
			JetCollection AntiHiggsLikeJets;
			for( int i=0; i < CA8JetInfo.Size; ++i ){
				if( fabs(CA8JetInfo.Eta[i])>CA8JetAbsEta ) continue; //// apply jet eta cut
				if( CA8JetInfo.NHF[i]>=0.99 || CA8JetInfo.NEF[i]>=0.99 || CA8JetInfo.NConstituents[i]<=1 || fabs(CA8JetInfo.Eta[i]) >=2.4 || CA8JetInfo.CHF[i]<=0 || CA8JetInfo.CEF[i]>=0.99 ||  CA8JetInfo.NCH[i]<=0 ) continue; //// apply loose jet ID
				if( CA8JetInfo.Pt[i]<CA8JetPt_Min || CA8JetInfo.Pt[i]>CA8JetPt_Max ) continue; //// apply jet pT cut
			
				//// Get subjets of fat jets
				int iSub1 = CA8JetInfo.Jet_SubJet1Idx[i];
				int iSub2 = CA8JetInfo.Jet_SubJet2Idx[i];

				if( iSub1 > 25 || iSub2 > 25) continue; //// skip fat jets for which one of the subjets has pT=0
				if( SubJetInfo.Pt[iSub1]==0. || SubJetInfo.Pt[iSub2]==0. ) continue; //// skip fat jets for which one of the subjets has pT=0

				TLorentzVector Subjet1, Subjet2;
				Subjet1.SetPtEtaPhiM(SubJetInfo.Pt[iSub1], SubJetInfo.Eta[iSub1], SubJetInfo.Phi[iSub1], SubJetInfo.Mass[iSub1]);
				Subjet2.SetPtEtaPhiM(SubJetInfo.Pt[iSub2], SubJetInfo.Eta[iSub2], SubJetInfo.Phi[iSub2], SubJetInfo.Mass[iSub2]);

				double subjet_dy = Subjet1.Rapidity() - Subjet2.Rapidity();
				double subjet_dphi = Subjet1.DeltaPhi(Subjet2);
				double subjet_dyphi = sqrt( subjet_dy*subjet_dy + subjet_dphi*subjet_dphi );

				if( subjet_dyphi <(CA8JetInfo.Mass[i]/CA8JetInfo.Pt[i]) ) continue; //// skip infrared unsafe configurations
				if( CA8JetInfo.tau2[i]/CA8JetInfo.tau1[i] > CA8JetTau2ByTau1_Max) continue;
				if( SubJetInfo.CombinedSVBJetTags[iSub1]<0.244 || SubJetInfo.CombinedSVBJetTags[iSub2]<0.244 )  continue;

				if( SubJetInfo.CombinedSVBJetTags[iSub1]<Subjet1CSV_Min && SubJetInfo.CombinedSVBJetTags[iSub2]<Subjet2CSV_Min){ //Anti-Higgs
	
					Jet CA8Jet(CA8JetInfo, i);
					AntiHiggsLikeJets.push_back(CA8Jet);

					if( 	CA8JetInfo.MassPruned[i]>CA8JetPrunedMass_Min && CA8JetInfo.MassPruned[i]<CA8JetPrunedMass_Max ){  //// apply pruned jet mass cut 
						AntiHiggsJets.push_back(CA8Jet);

					}
				}else if( SubJetInfo.CombinedSVBJetTags[iSub1]>=Subjet1CSV_Min && SubJetInfo.CombinedSVBJetTags[iSub2]>=Subjet2CSV_Min ){ //Higgs

					Jet CA8Jet(CA8JetInfo, i);
					HiggsLikeJets.push_back(CA8Jet);

					if( 	CA8JetInfo.MassPruned[i]>CA8JetPrunedMass_Min && CA8JetInfo.MassPruned[i]<CA8JetPrunedMass_Max ){
						HiggsJets.push_back(CA8Jet);
						HT_HiggsBJets = HT_HiggsBJets + CA8JetInfo.Pt[i]; 
					}
				}

			}//CA8

			// AK5 Jet and b Jet //================================================================================================================
			JetCollection bJets;
			JetCollection bJets_Veto;
			for( int i=0; i<AK5JetInfo.Size; ++i){ 
				if( fabs(AK5JetInfo.Eta[i]) > AK5JetAbsEta ) continue; 
				if( AK5JetInfo.NHF[i]>=0.90 || AK5JetInfo.NEF[i]>=0.90 || AK5JetInfo.NConstituents[i]<=1 || fabs(AK5JetInfo.Eta[i]) >=2.4 || AK5JetInfo.CHF[i]<=0 || AK5JetInfo.CEF[i]>=0.99 ||  AK5JetInfo.NCH[i]<=0 ) continue; //// apply loose jet ID
				if( AK5JetInfo.Pt[i] < AK5JetPt_Min || AK5JetInfo.Pt[i] > AK5JetPt_Max ) continue; 

					HT_AK5 = HT_AK5 + AK5JetInfo.Pt[i];

				if( AK5JetInfo.CombinedSVBJetTags[i] <= 0.679 ) continue;
				if( AK5JetInfo.Pt[i] <= bJetPt_Min ) continue;

					Jet bJet(AK5JetInfo, i);
					bJets.push_back(bJet);
			}//bJet end
			for( int i=0; i<AK5JetInfo.Size; ++i){ 
				if( fabs(AK5JetInfo.Eta[i]) > AK5JetAbsEta ) continue; 
				if( AK5JetInfo.NHF[i]>=0.90 || AK5JetInfo.NEF[i]>=0.90 || AK5JetInfo.NConstituents[i]<=1 || fabs(AK5JetInfo.Eta[i]) >=2.4 || AK5JetInfo.CHF[i]<=0 || AK5JetInfo.CEF[i]>=0.99 ||  AK5JetInfo.NCH[i]<=0 ) continue; //// apply loose jet ID
				if( AK5JetInfo.Pt[i] < 30. ) continue; 
				if( AK5JetInfo.CombinedSVBJetTags[i] <= 0.244 ) continue;

					Jet bJet(AK5JetInfo, i);
					bJets_Veto.push_back(bJet);
			}//bVeto's bJet selection end

			// dR(b, H)>1.2 to Isolate bJet and HJet //================================================================================================================
			JetCollection bJetsNotHiggs;
			JetCollection bJetsNotHiggsLike;
			JetCollection bJetsNotHiggsLikeAntiHiggsLike;
			JetCollection bJetsNotHiggsLike_Veto;
			JetCollection bJetsNotHiggsLikeAntiHiggsLike_Veto;
			// bJets candidate isolation with Higgs, for HT(Higgs, bJet)
			for( JetCollection::const_iterator AK5 = bJets.begin(); AK5 != bJets.end(); ++AK5 ){
				bool isHiggs(false); 
				for( JetCollection::const_iterator _H = HiggsJets.begin(); _H != HiggsJets.end(); ++_H ){
					if( _H->DeltaR(*AK5) < 1.2){
						isHiggs = true; 
						break; 
					}else {
						isHiggs = false; 
					} 
				}
				if( !isHiggs ){
					bJetsNotHiggs.push_back(*AK5);
					HT_HiggsBJets = HT_HiggsBJets + AK5->Pt();
				} 
			}
			// bJets candidate isolation with Higgs+HiggsLike
			for( JetCollection::const_iterator AK5 = bJets.begin(); AK5 != bJets.end(); ++AK5 ){
				bool isHiggs(false); 
				for( JetCollection::const_iterator _H = HiggsLikeJets.begin(); _H != HiggsLikeJets.end(); ++_H ){
					if( _H->DeltaR(*AK5) < 1.2){
						isHiggs = true; 
						break; 
					}else {
						isHiggs = false; 
					} 
				}
				if( !isHiggs ){
					bJetsNotHiggsLike.push_back(*AK5);
				} 
			}
			// bJets candidate isolate with Higgs+HiggsLike+AntiHiggs+AntiHiggsLike
			for( JetCollection::const_iterator AK5 = bJetsNotHiggsLike.begin(); AK5 != bJetsNotHiggsLike.end(); ++AK5 ){
				bool isHiggs(false); 
				for( JetCollection::const_iterator _H = AntiHiggsLikeJets.begin(); _H != AntiHiggsLikeJets.end(); ++_H ){
					if( _H->DeltaR(*AK5) < 1.2){
						isHiggs = true; 
						break; 
					}else {
						isHiggs = false; 
					} 
				}
				if( !isHiggs ){
					bJetsNotHiggsLikeAntiHiggsLike.push_back(*AK5);
				} 
			}

			// Veto: bJets candidate isolation with Higgs+HiggsLike
			for( JetCollection::const_iterator AK5 = bJets_Veto.begin(); AK5 != bJets_Veto.end(); ++AK5 ){
				bool isHiggs(false); 
				for( JetCollection::const_iterator _H = HiggsLikeJets.begin(); _H != HiggsLikeJets.end(); ++_H ){
					if( _H->DeltaR(*AK5) < 1.2){
						isHiggs = true; 
						break; 
					}else {
						isHiggs = false; 
					} 
				}
				if( !isHiggs ){
					bJetsNotHiggsLike_Veto.push_back(*AK5);
				} 
			}
			// Veto: bJets candidate isolate with Higgs+HiggsLike+AntiHiggs+AntiHiggsLike
			for( JetCollection::const_iterator AK5 = bJetsNotHiggsLike_Veto.begin(); AK5 != bJetsNotHiggsLike_Veto.end(); ++AK5 ){
				bool isHiggs(false); 
				for( JetCollection::const_iterator _H = AntiHiggsLikeJets.begin(); _H != AntiHiggsLikeJets.end(); ++_H ){
					if( _H->DeltaR(*AK5) < 1.2){
						isHiggs = true; 
						break; 
					}else {
						isHiggs = false; 
					} 
				}
				if( !isHiggs ){
					bJetsNotHiggsLikeAntiHiggsLike_Veto.push_back(*AK5);
				} 
			}

			///// Fill evt and ABCD plots //==================================================================================================================================================	
			int A=0, Av=0;
			int B=0, Bv=0;
			int C=0, Cv=0;
			int D=0, Dv=0;

			if( HT_AK5 <= HT_Min ) continue;

			JetCollection Final_bJets_ABCD;
			JetCollection HiggsJets_ABCD, HiggsSubJet1_ABCD, HiggsSubJet2_ABCD;
			JetCollection AntiHiggsJets_ABCD, AntiHiggsSubJet1_ABCD, AntiHiggsSubJet2_ABCD;
			//// Higgs region
			for( JetCollection::const_iterator H = HiggsLikeJets.begin(); H != HiggsLikeJets.end(); H++ ){
				int iSub1, iSub2;
				if( SubJetInfo.Pt[H->Jet_SubJet1Idx()] > SubJetInfo.Pt[H->Jet_SubJet2Idx()] ){
					iSub1 = H->Jet_SubJet1Idx();
					iSub2 = H->Jet_SubJet2Idx();
				}else{
					iSub1 = H->Jet_SubJet2Idx();
					iSub2 = H->Jet_SubJet1Idx();
				}
				TLorentzVector Subjet1, Subjet2;
				Subjet1.SetPtEtaPhiM(SubJetInfo.Pt[iSub1], SubJetInfo.Eta[iSub1], SubJetInfo.Phi[iSub1], SubJetInfo.Mass[iSub1]);
				Subjet2.SetPtEtaPhiM(SubJetInfo.Pt[iSub2], SubJetInfo.Eta[iSub2], SubJetInfo.Phi[iSub2], SubJetInfo.Mass[iSub2]);
				double subjet_dy = Subjet1.Rapidity() - Subjet2.Rapidity();
				double subjet_dphi = Subjet1.DeltaPhi(Subjet2);
				double subjet_dyphi = sqrt( subjet_dy*subjet_dy + subjet_dphi*subjet_dphi );
				
				Jet SubJet1(SubJetInfo, iSub1);
				Jet SubJet2(SubJetInfo, iSub2);
				
				//// B region 
				if( H->MassPruned() > CA8JetPrunedMass_Min && H->MassPruned() < CA8JetPrunedMass_Max ){
					if ( bJetsNotHiggsLikeAntiHiggsLike.size() >= num_bJets ){
						B++; 
						HiggsJets_ABCD.push_back(*H);
						HiggsSubJet1_ABCD.push_back(SubJet1);
						HiggsSubJet2_ABCD.push_back(SubJet2);
						int bmin_index = CloseJetIndex(bJetsNotHiggsLikeAntiHiggsLike, *H);
						Jet bJetMin(AK5JetInfo, bmin_index);
						Final_bJets_ABCD.push_back(bJetMin);
						h1.GetTH1F("ABCDana_HiggsMass")->Fill( H->MassPruned(), weight);
						h1.GetTH1F("ABCDana_HiggsMass_B")->Fill( H->MassPruned(), weight);
						h1.GetTH1F("ABCDana_CA8Pt")->Fill( H->Pt(), weight);
						h1.GetTH1F("ABCDana_CA8Pt_B")->Fill( H->Pt(), weight);
						h1.GetTH1F("ABCDana_dRSubJets_B")->Fill( subjet_dyphi, weight);
						h1.GetTH1F("ABCDana_Tau2ByTau1_B")->Fill( H->tau2()/H->tau1(), weight);
						h1.GetTH1F("ABCDana_Sub1Mass_B")->Fill( SubJetInfo.Mass[iSub1], weight);
						h1.GetTH1F("ABCDana_Sub2Mass_B")->Fill( SubJetInfo.Mass[iSub2], weight);
						h1.GetTH1F("ABCDana_Sub1Pt_B")->Fill( SubJetInfo.Pt[iSub1], weight);
						h1.GetTH1F("ABCDana_Sub2Pt_B")->Fill( SubJetInfo.Pt[iSub2], weight);
						h1.GetTH1F("ABCDana_Sub1CSV_B")->Fill( SubJetInfo.CombinedSVBJetTags[iSub1], weight);
						h1.GetTH1F("ABCDana_Sub2CSV_B")->Fill( SubJetInfo.CombinedSVBJetTags[iSub2], weight);
						h2.GetTH2F("ABCDana_2D")->Fill( 1., H->MassPruned(), weight);
					}
					if ( bJetsNotHiggsLikeAntiHiggsLike_Veto.size() == 0 ){ //b-Veto
						Bv++; 
						h1.GetTH1F("ABCDval_HiggsMass")->Fill( H->MassPruned(), weight);
						h1.GetTH1F("ABCDval_HiggsMass_B")->Fill( H->MassPruned(), weight);
						h1.GetTH1F("ABCDval_CA8Pt")->Fill( H->Pt(), weight);
						h1.GetTH1F("ABCDval_CA8Pt_B")->Fill( H->Pt(), weight);
						h1.GetTH1F("ABCDval_dRSubJets_B")->Fill( subjet_dyphi, weight);
						h1.GetTH1F("ABCDval_Tau2ByTau1_B")->Fill( H->tau2()/H->tau1(), weight);
						h1.GetTH1F("ABCDval_Sub1Mass_B")->Fill( SubJetInfo.Mass[iSub1], weight);
						h1.GetTH1F("ABCDval_Sub2Mass_B")->Fill( SubJetInfo.Mass[iSub2], weight);
						h1.GetTH1F("ABCDval_Sub1Pt_B")->Fill( SubJetInfo.Pt[iSub1], weight);
						h1.GetTH1F("ABCDval_Sub2Pt_B")->Fill( SubJetInfo.Pt[iSub2], weight);
						h1.GetTH1F("ABCDval_Sub1CSV_B")->Fill( SubJetInfo.CombinedSVBJetTags[iSub1], weight);
						h1.GetTH1F("ABCDval_Sub2CSV_B")->Fill( SubJetInfo.CombinedSVBJetTags[iSub2], weight);
						h2.GetTH2F("ABCDval_2D")->Fill( 1., H->MassPruned(), weight);
					}
				}
				//// D region 
				if( H->MassPruned() <= CA8JetPrunedMass_Min || H->MassPruned() >= CA8JetPrunedMass_Max ){
					if ( bJetsNotHiggsLikeAntiHiggsLike.size() >= num_bJets ){
						if( H->MassPruned() <= ABCD1_yCutLow ){ 
							D++; 
							HiggsJets_ABCD.push_back(*H);
							HiggsSubJet1_ABCD.push_back(SubJet1);
							HiggsSubJet2_ABCD.push_back(SubJet2);
							int bmin_index = CloseJetIndex(bJetsNotHiggsLikeAntiHiggsLike, *H);
							Jet bJetMin(AK5JetInfo, bmin_index);
							Final_bJets_ABCD.push_back(bJetMin);
						} 
						h1.GetTH1F("ABCDana_HiggsMass")->Fill( H->MassPruned(), weight);
						h1.GetTH1F("ABCDana_HiggsMass_D")->Fill( H->MassPruned(), weight);
						h1.GetTH1F("ABCDana_CA8Pt")->Fill( H->Pt(), weight);
						h1.GetTH1F("ABCDana_CA8Pt_D")->Fill( H->Pt(), weight);
						h1.GetTH1F("ABCDana_dRSubJets_D")->Fill( subjet_dyphi, weight);
						h1.GetTH1F("ABCDana_Tau2ByTau1_D")->Fill( H->tau2()/H->tau1(), weight);
						h1.GetTH1F("ABCDana_Sub1Mass_D")->Fill( SubJetInfo.Mass[iSub1], weight);
						h1.GetTH1F("ABCDana_Sub2Mass_D")->Fill( SubJetInfo.Mass[iSub2], weight);
						h1.GetTH1F("ABCDana_Sub1Pt_D")->Fill( SubJetInfo.Pt[iSub1], weight);
						h1.GetTH1F("ABCDana_Sub2Pt_D")->Fill( SubJetInfo.Pt[iSub2], weight);
						h1.GetTH1F("ABCDana_Sub1CSV_D")->Fill( SubJetInfo.CombinedSVBJetTags[iSub1], weight);
						h1.GetTH1F("ABCDana_Sub2CSV_D")->Fill( SubJetInfo.CombinedSVBJetTags[iSub2], weight);
						h2.GetTH2F("ABCDana_2D")->Fill( 1., H->MassPruned(), weight);
					}
					if ( bJetsNotHiggsLikeAntiHiggsLike_Veto.size() == 0 ){ //b-Veto
						if( H->MassPruned() <= ABCD1_yCutLow ){ 
							Dv++; 
						} 
						h1.GetTH1F("ABCDval_HiggsMass")->Fill( H->MassPruned(), weight);
						h1.GetTH1F("ABCDval_HiggsMass_D")->Fill( H->MassPruned(), weight);
						h1.GetTH1F("ABCDval_CA8Pt")->Fill( H->Pt(), weight);
						h1.GetTH1F("ABCDval_CA8Pt_D")->Fill( H->Pt(), weight);
						h1.GetTH1F("ABCDval_dRSubJets_D")->Fill( subjet_dyphi, weight);
						h1.GetTH1F("ABCDval_Tau2ByTau1_D")->Fill( H->tau2()/H->tau1(), weight);
						h1.GetTH1F("ABCDval_Sub1Mass_D")->Fill( SubJetInfo.Mass[iSub1], weight);
						h1.GetTH1F("ABCDval_Sub2Mass_D")->Fill( SubJetInfo.Mass[iSub2], weight);
						h1.GetTH1F("ABCDval_Sub1Pt_D")->Fill( SubJetInfo.Pt[iSub1], weight);
						h1.GetTH1F("ABCDval_Sub2Pt_D")->Fill( SubJetInfo.Pt[iSub2], weight);
						h1.GetTH1F("ABCDval_Sub1CSV_D")->Fill( SubJetInfo.CombinedSVBJetTags[iSub1], weight);
						h1.GetTH1F("ABCDval_Sub2CSV_D")->Fill( SubJetInfo.CombinedSVBJetTags[iSub2], weight);
						h2.GetTH2F("ABCDval_2D")->Fill( 1., H->MassPruned(), weight);
					}
				}
			}

			//// AntiHiggs region 
			for( JetCollection::const_iterator H = AntiHiggsLikeJets.begin(); H != AntiHiggsLikeJets.end(); H++ ){
				int iSub1, iSub2;
				if( SubJetInfo.Pt[H->Jet_SubJet1Idx()] > SubJetInfo.Pt[H->Jet_SubJet2Idx()] ){
					iSub1 = H->Jet_SubJet1Idx();
					iSub2 = H->Jet_SubJet2Idx();
				}else{
					iSub1 = H->Jet_SubJet2Idx();
					iSub2 = H->Jet_SubJet1Idx();
				}
				TLorentzVector Subjet1, Subjet2;
				Subjet1.SetPtEtaPhiM(SubJetInfo.Pt[iSub1], SubJetInfo.Eta[iSub1], SubJetInfo.Phi[iSub1], SubJetInfo.Mass[iSub1]);
				Subjet2.SetPtEtaPhiM(SubJetInfo.Pt[iSub2], SubJetInfo.Eta[iSub2], SubJetInfo.Phi[iSub2], SubJetInfo.Mass[iSub2]);
				double subjet_dy = Subjet1.Rapidity() - Subjet2.Rapidity();
				double subjet_dphi = Subjet1.DeltaPhi(Subjet2);
				double subjet_dyphi = sqrt( subjet_dy*subjet_dy + subjet_dphi*subjet_dphi );

				Jet SubJet1(SubJetInfo, iSub1);
				Jet SubJet2(SubJetInfo, iSub2);

				//// A region	
				if( H->MassPruned() > CA8JetPrunedMass_Min && H->MassPruned() < CA8JetPrunedMass_Max ){
					if ( bJetsNotHiggsLikeAntiHiggsLike.size()>= num_bJets ){
						A++;
						AntiHiggsJets_ABCD.push_back(*H); 
						AntiHiggsSubJet1_ABCD.push_back(SubJet1);
						AntiHiggsSubJet2_ABCD.push_back(SubJet2);
						int bmin_index = CloseJetIndex(bJetsNotHiggsLikeAntiHiggsLike, *H);
						Jet bJetMin(AK5JetInfo, bmin_index);
						Final_bJets_ABCD.push_back(bJetMin);
						h1.GetTH1F("ABCDana_HiggsMass")->Fill( H->MassPruned(), weight);
						h1.GetTH1F("ABCDana_HiggsMass_A")->Fill( H->MassPruned(), weight);
						h1.GetTH1F("ABCDana_CA8Pt")->Fill( H->Pt(), weight);
						h1.GetTH1F("ABCDana_CA8Pt_A")->Fill( H->Pt(), weight);
						h1.GetTH1F("ABCDana_dRSubJets_A")->Fill( subjet_dyphi, weight);
						h1.GetTH1F("ABCDana_Tau2ByTau1_A")->Fill( H->tau2()/H->tau1(), weight);
						h1.GetTH1F("ABCDana_Sub1Mass_A")->Fill( SubJetInfo.Mass[iSub1], weight);
						h1.GetTH1F("ABCDana_Sub2Mass_A")->Fill( SubJetInfo.Mass[iSub2], weight);
						h1.GetTH1F("ABCDana_Sub1Pt_A")->Fill( SubJetInfo.Pt[iSub1], weight);
						h1.GetTH1F("ABCDana_Sub2Pt_A")->Fill( SubJetInfo.Pt[iSub2], weight);
						h1.GetTH1F("ABCDana_Sub1CSV_A")->Fill( SubJetInfo.CombinedSVBJetTags[iSub1], weight);
						h1.GetTH1F("ABCDana_Sub2CSV_A")->Fill( SubJetInfo.CombinedSVBJetTags[iSub2], weight);
						h2.GetTH2F("ABCDana_2D")->Fill( 0., H->MassPruned(), weight);
					}
					if ( bJetsNotHiggsLikeAntiHiggsLike_Veto.size() == 0 ){
						Av++; 
						h1.GetTH1F("ABCDval_HiggsMass")->Fill( H->MassPruned(), weight);
						h1.GetTH1F("ABCDval_HiggsMass_A")->Fill( H->MassPruned(), weight);
						h1.GetTH1F("ABCDval_CA8Pt")->Fill( H->Pt(), weight);
						h1.GetTH1F("ABCDval_CA8Pt_A")->Fill( H->Pt(), weight);
						h1.GetTH1F("ABCDval_dRSubJets_A")->Fill( subjet_dyphi, weight);
						h1.GetTH1F("ABCDval_Tau2ByTau1_A")->Fill( H->tau2()/H->tau1(), weight);
						h1.GetTH1F("ABCDval_Sub1Mass_A")->Fill( SubJetInfo.Mass[iSub1], weight);
						h1.GetTH1F("ABCDval_Sub2Mass_A")->Fill( SubJetInfo.Mass[iSub2], weight);
						h1.GetTH1F("ABCDval_Sub1Pt_A")->Fill( SubJetInfo.Pt[iSub1], weight);
						h1.GetTH1F("ABCDval_Sub2Pt_A")->Fill( SubJetInfo.Pt[iSub2], weight);
						h1.GetTH1F("ABCDval_Sub1CSV_A")->Fill( SubJetInfo.CombinedSVBJetTags[iSub1], weight);
						h1.GetTH1F("ABCDval_Sub2CSV_A")->Fill( SubJetInfo.CombinedSVBJetTags[iSub2], weight);
						h2.GetTH2F("ABCDval_2D")->Fill( 0., H->MassPruned(), weight);
					}
				}
				//// C region
				if( H->MassPruned() <= CA8JetPrunedMass_Min || H->MassPruned() >= CA8JetPrunedMass_Max ){
					if ( bJetsNotHiggsLikeAntiHiggsLike.size() >= num_bJets){
						if( H->MassPruned() <= ABCD1_yCutLow ){ 
							C++; 
							AntiHiggsJets_ABCD.push_back(*H); 
							AntiHiggsSubJet1_ABCD.push_back(SubJet1);
							AntiHiggsSubJet2_ABCD.push_back(SubJet2);
							int bmin_index = CloseJetIndex(bJetsNotHiggsLikeAntiHiggsLike, *H);
							Jet bJetMin(AK5JetInfo, bmin_index);
							Final_bJets_ABCD.push_back(bJetMin);
						} 
						h1.GetTH1F("ABCDana_HiggsMass")->Fill( H->MassPruned(), weight);
						h1.GetTH1F("ABCDana_HiggsMass_C")->Fill( H->MassPruned(), weight);
						h1.GetTH1F("ABCDana_CA8Pt")->Fill( H->Pt(), weight);
						h1.GetTH1F("ABCDana_CA8Pt_C")->Fill( H->Pt(), weight);
						h1.GetTH1F("ABCDana_dRSubJets_C")->Fill( subjet_dyphi, weight);
						h1.GetTH1F("ABCDana_Tau2ByTau1_C")->Fill( H->tau2()/H->tau1(), weight);
						h1.GetTH1F("ABCDana_Sub1Mass_C")->Fill( SubJetInfo.Mass[iSub1], weight);
						h1.GetTH1F("ABCDana_Sub2Mass_C")->Fill( SubJetInfo.Mass[iSub2], weight);
						h1.GetTH1F("ABCDana_Sub1Pt_C")->Fill( SubJetInfo.Pt[iSub1], weight);
						h1.GetTH1F("ABCDana_Sub2Pt_C")->Fill( SubJetInfo.Pt[iSub2], weight);
						h1.GetTH1F("ABCDana_Sub1CSV_C")->Fill( SubJetInfo.CombinedSVBJetTags[iSub1], weight);
						h1.GetTH1F("ABCDana_Sub2CSV_C")->Fill( SubJetInfo.CombinedSVBJetTags[iSub2], weight);
						h2.GetTH2F("ABCDana_2D")->Fill( 0., H->MassPruned(), weight);
					}
					if ( bJetsNotHiggsLikeAntiHiggsLike_Veto.size() == 0){ // b-Veto
						if( H->MassPruned() <= ABCD1_yCutLow ){ 
							Cv++; 
						} 
						h1.GetTH1F("ABCDval_HiggsMass")->Fill( H->MassPruned(), weight);
						h1.GetTH1F("ABCDval_HiggsMass_C")->Fill( H->MassPruned(), weight);
						h1.GetTH1F("ABCDval_CA8Pt")->Fill( H->Pt(), weight);
						h1.GetTH1F("ABCDval_CA8Pt_C")->Fill( H->Pt(), weight);
						h1.GetTH1F("ABCDval_dRSubJets_C")->Fill( subjet_dyphi, weight);
						h1.GetTH1F("ABCDval_Tau2ByTau1_C")->Fill( H->tau2()/H->tau1(), weight);
						h1.GetTH1F("ABCDval_Sub1Mass_C")->Fill( SubJetInfo.Mass[iSub1], weight);
						h1.GetTH1F("ABCDval_Sub2Mass_C")->Fill( SubJetInfo.Mass[iSub2], weight);
						h1.GetTH1F("ABCDval_Sub1Pt_C")->Fill( SubJetInfo.Pt[iSub1], weight);
						h1.GetTH1F("ABCDval_Sub2Pt_C")->Fill( SubJetInfo.Pt[iSub2], weight);
						h1.GetTH1F("ABCDval_Sub1CSV_C")->Fill( SubJetInfo.CombinedSVBJetTags[iSub1], weight);
						h1.GetTH1F("ABCDval_Sub2CSV_C")->Fill( SubJetInfo.CombinedSVBJetTags[iSub2], weight);
						h2.GetTH2F("ABCDval_2D")->Fill( 0., H->MassPruned(), weight);
					}
				}
				///////===================================================================================
			}

			h1.GetTH1F("ABCDana_NumCA8_A")->Fill(A);
			h1.GetTH1F("ABCDana_NumCA8_B")->Fill(B);
			h1.GetTH1F("ABCDana_NumCA8_C")->Fill(C);
			h1.GetTH1F("ABCDana_NumCA8_D")->Fill(D);
			h1.GetTH1F("ABCDval_NumCA8_A")->Fill(Av);
			h1.GetTH1F("ABCDval_NumCA8_B")->Fill(Bv);
			h1.GetTH1F("ABCDval_NumCA8_C")->Fill(Cv);
			h1.GetTH1F("ABCDval_NumCA8_D")->Fill(Dv);

			double w2_ = weight*weight;

			if( B > 0 ){
				h1.GetTH1F("ABCDana_CutRegion")->Fill("B", weight); evtPass_ana++;
				h1.GetTH1F("ABCDana_HT_B")->Fill( HT_AK5, weight);
				h1.GetTH1F("ABCDana_HT")->Fill( HT_AK5, weight);
				sumw2_b += w2_;
			}else if( D > 0 ){ 
				h1.GetTH1F("ABCDana_CutRegion")->Fill("D", weight);
				h1.GetTH1F("ABCDana_HT_D")->Fill( HT_AK5, weight);
				h1.GetTH1F("ABCDana_HT")->Fill( HT_AK5, weight);
				sumw2_d += w2_;
			}else if( A > 0 ){
				h1.GetTH1F("ABCDana_CutRegion")->Fill("A", weight);
				h1.GetTH1F("ABCDana_HT_A")->Fill( HT_AK5, weight);
				h1.GetTH1F("ABCDana_HT")->Fill( HT_AK5, weight);
				sumw2_a += w2_;
			}else if( C > 0 ){
				h1.GetTH1F("ABCDana_CutRegion")->Fill("C", weight);
				h1.GetTH1F("ABCDana_HT_C")->Fill( HT_AK5, weight);
				h1.GetTH1F("ABCDana_HT")->Fill( HT_AK5, weight);
				sumw2_c += w2_;
			}

			if( Bv > 0 ){
				h1.GetTH1F("ABCDval_CutRegion")->Fill("B", weight); evtPass_val++;
				h1.GetTH1F("ABCDval_HT_B")->Fill( HT_AK5, weight);
				h1.GetTH1F("ABCDval_HT")->Fill( HT_AK5, weight);
				sumw2_bv += w2_;
			}else if( Dv > 0 ){ 
				h1.GetTH1F("ABCDval_CutRegion")->Fill("D", weight);
				h1.GetTH1F("ABCDval_HT_D")->Fill( HT_AK5, weight);
				h1.GetTH1F("ABCDval_HT")->Fill( HT_AK5, weight);
				sumw2_dv += w2_;
			}else if( Av > 0 ){
				h1.GetTH1F("ABCDval_CutRegion")->Fill("A", weight);
				h1.GetTH1F("ABCDval_HT_A")->Fill( HT_AK5, weight);
				h1.GetTH1F("ABCDval_HT")->Fill( HT_AK5, weight);
				sumw2_av += w2_;
			}else if( Cv > 0 ){
				h1.GetTH1F("ABCDval_CutRegion")->Fill("C", weight);
				h1.GetTH1F("ABCDval_HT_C")->Fill( HT_AK5, weight);
				h1.GetTH1F("ABCDval_HT")->Fill( HT_AK5, weight);
				sumw2_cv += w2_;
			}
			ca8Num_ana->Fill(A+B+C+D, weight);
			ca8Num_val->Fill(Av+Bv+Cv+Dv, weight);
			if( B != 0 ) h1.GetTH1F("ABCDana_CutFlow")->Fill("ABCDsel", weight);
			if( Bv != 0 ) h1.GetTH1F("ABCDval_CutFlow")->Fill("ABCDsel", weight);

			if( buildTree ){
				if( A+B+C+D > 0 ){ 
					if( McFlag ) xsec_ = TTMC[iSample].xsec;
					else xsec_ = 1.;
					GenEvt_ = totalEvt;
					McFlagana = McFlag;
					PUana = PU;
					evtWtana = evtWt;
					HTak5 = HT_AK5;
					HThiggsbjet = HT_HiggsBJets;
					reRegistJet(HiggsJets_ABCD, HiggsJetInfoAna);	
					reRegistJet(AntiHiggsJets_ABCD, AntiHiggsJetInfoAna);	
					reRegistJet(HiggsSubJet1_ABCD, HiggsSubJet1InfoAna);	
					reRegistJet(HiggsSubJet2_ABCD, HiggsSubJet2InfoAna);	
					reRegistJet(AntiHiggsSubJet1_ABCD, AntiHiggsSubJet1InfoAna);	
					reRegistJet(AntiHiggsSubJet2_ABCD, AntiHiggsSubJet2InfoAna);	
					reRegistJet(bJetsNotHiggsLikeAntiHiggsLike, bJetInfoAna);
					reRegistJet(Final_bJets_ABCD, Final_bJetInfoAna);			
					newtree_ana->Fill();	
				//	cout<<"A "<<A<<", B "<<B<<", C "<<C<<", D "<<D<<endl;
				//	cout<<"Higgs "<<HiggsJets_ABCD.size()<<", AntiHiggs "<<AntiHiggsJets_ABCD.size()<<endl;
				//	cout<<"HiggsSub12 "<<HiggsSubJet1_ABCD.size()<<", "<<HiggsSubJet2_ABCD.size()<<", AntiHiggsSub12 "<<AntiHiggsSubJet1_ABCD.size()<<", "<<AntiHiggsSubJet2_ABCD.size()<<endl;
				//	cout<<"========================================"<<endl;
				}
				//if( Av+Bv+Cv+Dv > 0 ) 	newtree_val->Fill();	
			}
		}//entries

		h1.GetTH1F("ABCDana_Sumw2_A")->Fill( 0., sumw2_a);
		h1.GetTH1F("ABCDana_Sumw2_B")->Fill( 0., sumw2_b);
		h1.GetTH1F("ABCDana_Sumw2_C")->Fill( 0., sumw2_c);
		h1.GetTH1F("ABCDana_Sumw2_D")->Fill( 0., sumw2_d);
		h1.GetTH1F("ABCDval_Sumw2_A")->Fill( 0., sumw2_a);
		h1.GetTH1F("ABCDval_Sumw2_B")->Fill( 0., sumw2_b);
		h1.GetTH1F("ABCDval_Sumw2_C")->Fill( 0., sumw2_c);
		h1.GetTH1F("ABCDval_Sumw2_D")->Fill( 0., sumw2_d);

		newfile->Write();
		cout<<"evtPass_ana "<<evtPass_ana<<"/"<<tree->GetEntries()<<endl;	
		cout<<"evtPass_val "<<evtPass_val<<"/"<<tree->GetEntries()<<endl;	
		cout<<"end"<<endl<<endl;
	}//sample
}
