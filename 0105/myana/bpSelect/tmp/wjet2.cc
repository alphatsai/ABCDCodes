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
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0531/interface/plotsInfo.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0531/interface/myformat.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////// Functions ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//////// Files Info Function ///////////
TH1F* anaTH1f( map<string,  TH1F*> mapth1, string name ){
	return mapth1.find(name)->second;
}

TH2F* anaTH2f( map<string,  TH2F*> mapth2, string name ){
	return mapth2.find(name)->second;
}

///////// Ana Info Function ////////////////
double dPhi(double p1,double p2){ //dPhi
	double dp = p1 - p2;
	if (fabs(dp+3.14159265358979323846*2.) < fabs(dp)) dp += 3.14159265358979323846*2.;
	else
		if (fabs(dp-3.14159265358979323846*2.) < fabs(dp)) dp -= 3.14159265358979323846*2.;
	return fabs(dp);
}
double dR  (double e1, double e2, double p1, double p2){ //dR
	return sqrt(pow(e1-e2,2)+pow(dPhi(p1,p2),2));
}
double dPtdivPt1 (double pt1, double pt2 ){ //dPt
	double dpt = pt1 - pt2;
	return fabs(dpt)/pt1;	
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
void wjet2()
{
	//////////////////// Differents mass point ///////////////
	map<string, TH1F*> mapTH1[SigMC_TotalNum];
	map<string, TH2F*> mapTH2[SigMC_TotalNum];
	for ( int mass_=0; mass_<SigMC_TotalNum; mass_++){
	//for ( int mass_=0; mass_<1; mass_++){
		cout<<"Star Run MassPoint "<<SigMC[mass_].massPoint<<"....."<<endl;
		///////////////////// Create New Tree and Forder //////////////////////
		string path1  = "/home/hep/alpha78718/mywk/store/bpToBH_Ntuple/ExtraSVFdR/BprimeBprimeToBHBHinc_M-";
		string path2c = "_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1/*.root";
		string path2a = "_TuneZ2star_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7A-v1/*.root";
		string path3  = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/2bTag/0531/resurlt/root/mc/sig/ExtraSVFdR_BH";
		string path4  = "_GMdR05dRbCA8.root";
		string path_s1; 
		if(atoi(SigMC[mass_].massPoint.c_str())>=900){ //atoi(char) transver char to inter
			path_s1 = path1 + SigMC[mass_].massPoint + path2c;
		}else{
			path_s1 = path1 + SigMC[mass_].massPoint + path2a;
		}  
		string path_s2 = path3 + SigMC[mass_].massPoint + path4; 
		TChain* newtree = new TChain("bprimeKit/root");
		newtree->Add( path_s1.c_str() );
		cout <<"tree bulid: "<<path_s1<<endl;
		TFile* newfile = new TFile( path_s2.c_str() ,"recreate");
		cout <<"folder create"<<endl;

		///////////////////// Create New TH1F, TH2F //////////////////////////
		for(int i=0; i<th1_size_; i++){
			mapTH1[mass_][TH1Info[i].name] = new TH1F( TH1Info[i].name.c_str(), "", TH1Info[i].bin, TH1Info[i].min, TH1Info[i].max ); 
		}
		for(int i=0; i<th2_size_; i++){
			mapTH2[mass_][TH2Info[i].name] = new TH2F( TH2Info[i].name.c_str(), "", TH2Info[i].xbin, TH2Info[i].xmin, TH2Info[i].xmax,
												TH2Info[i].ybin, TH2Info[i].ymin, TH2Info[i].ymax );
		}

		/////////////////////// Connect the Tree, Branch, leaf ////////////////
		GenInfoBranches GenInfo;
		JetInfoBranches WJetInfo;
		GenInfo.Register(newtree);	
		WJetInfo.Register(newtree,"WJetInfo");
		cout <<"brach bulid"<<endl;


		///////////////////// Get by event to Analysis ////////////////////////
		int MatchSameWJet=0;
		for( int entry=0; entry<newtree->GetEntries(); entry++ ){
		//for( int entry=0; entry<1; entry++ ){
			if( entry%10 == 0 )  cout<<".";
			if( entry%10000 == 0 ) cout<<entry;
			newtree->GetEntry(entry);

			int hbbCount = 0;
			int loseHiggs = 0;
			int hbbWJet_tmp = 0;
			int hbb[WJetInfo.Size]; // Save the position of methced h>bb with wjetand matrix size depend on hbbcount
			int hbbWJetMatch[WJetInfo.Size]; // Save the match postion of wjets and matrix size depend on hbbcount 
			int GenMatchPass[WJetInfo.Size]; // 0: no match, 1: only pass dR cut, 2: both pass dR & dPt/Pt cut but not the match one, 3: pass all cut and the only match one
			int GMdR05Count[WJetInfo.Size]; //Matrix size depend on hbbcount
			int GMdR05dRbCA8Count[WJetInfo.Size]; //Matrix size depend on hbbcount
			for( int i=0; i<WJetInfo.Size; i++ ){ hbb[i]=-1; hbbWJetMatch[i] = -1; GenMatchPass[i] = 0; GMdR05Count[i] = 0; GMdR05dRbCA8Count[i] = 0; }//initialize

			for( int particle=0; particle<GenInfo.Size; particle++ ){ //Match genParticle by Hiss->b bbar
				int da1 = GenInfo.Da1[particle];
				int da2 = GenInfo.Da2[particle];
				if( ( GenInfo.PdgID[particle] == 25 && GenInfo.PdgID[da1] == 5 && GenInfo.PdgID[da2] == -5) ||
						( GenInfo.PdgID[particle] == 25 && GenInfo.PdgID[da1] == -5 && GenInfo.PdgID[da2] == 5)){ //find Higgs->b bbar
					hbb[hbbCount] = particle;
					hbbWJet_tmp = hbbCount; //set the position for count matrix
					hbbCount++;
					float final_dR        = 0;
					float final_dPhi      = 0;
					float final_dPtdivPt1 = 0;
					float higgsbbPt  = GenInfo.Pt [particle];
					float higgsbbEta = GenInfo.Eta[particle];
					float higgsbbPhi = GenInfo.Phi[particle];
					float bbdR = dR(GenInfo.Eta[da1],GenInfo.Eta[da2],GenInfo.Phi[da1],GenInfo.Phi[da2]);
					anaTH1f(mapTH1[mass_],"UnM-HiggsInfo.Pt")->Fill(higgsbbPt);
					anaTH1f(mapTH1[mass_],"UnM-HiggsInfo.dR.bb")->Fill(bbdR);
					anaTH2f(mapTH2[mass_],"UnM-PtH.dRb1b2")->Fill(higgsbbPt,bbdR);
					for( int wjet_=0; wjet_<WJetInfo.Size; wjet_++ ){ // Tag the wjet pass the dR and dPt/Pt cut
						float dR_        = dR(higgsbbEta, WJetInfo.Eta[wjet_], higgsbbPhi, WJetInfo.Phi[wjet_]);
						float dPtdivPt1_ = dPtdivPt1(higgsbbPt, WJetInfo.Pt[wjet_]);
						float dR_b1CA8   = dR(GenInfo.Eta[da1], WJetInfo.Eta[wjet_], GenInfo.Phi[da1], WJetInfo.Phi[wjet_]);
						float dR_b2CA8   = dR(GenInfo.Eta[da2], WJetInfo.Eta[wjet_], GenInfo.Phi[da2], WJetInfo.Phi[wjet_]);
						anaTH1f(mapTH1[mass_],"UnM-dR")->Fill(dR_);
						anaTH1f(mapTH1[mass_],"UnM-dPtdivPt")->Fill(dPtdivPt1_);
						if( dR_ <= 0.5 ){ //pass cut dR 0.5;
							hbb[hbbWJet_tmp] = particle;
							GenMatchPass[wjet_] = 1; 
							GMdR05Count[hbbWJet_tmp]++;
							////////////////////////// Fill the histogram /////////////////////////
							anaTH1f(mapTH1[mass_],"GMdR5-dR")->Fill(dR_);
							anaTH1f(mapTH1[mass_],"GMdR5-dPtdivPt")->Fill(dPtdivPt1_);
							if( dR_b1CA8 < 0.8 && dR_b2CA8 < 0.8 ) { //pass cut b-quark and CA8 size
							//if(  dR_b1CA8 < 0.8 && dR_b2CA8 < 0.8 && dR_b1CA8 >=0.05 &&  dR_b2CA8 >=0.05) { //pass cut b-quark and CA8 size
								GenMatchPass[wjet_] = 2;
								GMdR05dRbCA8Count[hbbWJet_tmp]++;
								////////////////////////// Fill the histogram /////////////////////////
								anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-dR")->Fill(dR_);
								anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-dPtdivPt")->Fill(dPtdivPt1_);
							}	
						}
					}//statisics end 
					if( GMdR05dRbCA8Count[hbbWJet_tmp] == 0 ){ 	 // no wjet pass through the dR
						loseHiggs++;
						//cout<<endl<<"WARNING: The "<<entry<<" cut too tight !!!"<<endl;
					} else 
					if( GMdR05dRbCA8Count[hbbWJet_tmp] == 1 ){ 	 // Pefect match one WJet
						for( int pwjet=0; pwjet<WJetInfo.Size; pwjet++){
							if( GenMatchPass[pwjet] == 2 ){ // choose with dR
								GenMatchPass[pwjet] = 3;
								hbb[hbbWJet_tmp] = particle;
								hbbWJetMatch[hbbWJet_tmp] = pwjet;
								final_dR        = dR(higgsbbEta, WJetInfo.Eta[pwjet], higgsbbPhi, WJetInfo.Phi[pwjet]);
								final_dPhi      = dPhi(higgsbbPhi, WJetInfo.Phi[pwjet]);
								final_dPtdivPt1 = dPtdivPt1(higgsbbPt, WJetInfo.Pt[pwjet]); 
								////////////////////////// Fill the histogram /////////////////////////
								anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-HiggsInfo.Pt")->Fill(higgsbbPt);
								anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-final.dR")->Fill(final_dR);
								anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-final.dPhi")->Fill(final_dPhi);
								anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-final.dPtdivPt")->Fill(final_dPtdivPt1);
								anaTH2f(mapTH2[mass_],"GMdR5dRbCA8-dRHCA8.dPtdivPt")->Fill(final_dPtdivPt1, final_dR);//2D*/
								for( int i=0; i<WJetInfo.Size; i++ ){if( GenMatchPass[i] != 3) GenMatchPass[i] = 0;	} //initialize
								break;
							}
						}
					} else { // Match over one WJet
						int higgsbbwjet = 0;
						int wjet1 = 0;  //Use the cut to pick the only one match by bouble mathed
						for( int wjet2=1; wjet2<WJetInfo.Size; wjet2++ ){
							if ( GenMatchPass[wjet1] != 2 ) {	wjet1 = wjet2; continue;	} //choose with dR
							if ( GenMatchPass[wjet2] != 2 ) {	continue;			} //choose with dR
							float dR1=dR(higgsbbEta, WJetInfo.Eta[wjet1], higgsbbPhi, WJetInfo.Phi[wjet1]);
							float dR2=dR(higgsbbEta, WJetInfo.Eta[wjet2], higgsbbPhi, WJetInfo.Phi[wjet2]);
							float dPtdivPt1_1=dPtdivPt1(higgsbbPt, WJetInfo.Pt[wjet1]); 
							float dPtdivPt1_2=dPtdivPt1(higgsbbPt, WJetInfo.Pt[wjet2]); 
							if( dR1<dR2 ){ //compare with dR
								final_dR  	= dR1;
								final_dPtdivPt1 = dPtdivPt1_1;
								higgsbbwjet = wjet1;
							} else 
							if( dR1>dR2 ){
								final_dR  	= dR2;
								final_dPtdivPt1 = dPtdivPt1_2;
								higgsbbwjet = wjet2;
								wjet1 = wjet2;
								}
						} //bouble check end
							GenMatchPass[higgsbbwjet] = 3;
							hbb[hbbWJet_tmp] = particle;
							hbbWJetMatch[hbbWJet_tmp] = higgsbbwjet;
							final_dR        = dR(higgsbbEta, WJetInfo.Eta[higgsbbwjet], higgsbbPhi, WJetInfo.Phi[higgsbbwjet]);
							final_dPhi      = dPhi(higgsbbPhi, WJetInfo.Phi[higgsbbwjet]);
							final_dPtdivPt1 = dPtdivPt1(higgsbbPt, WJetInfo.Pt[higgsbbwjet]);
							////////////////////////// Fill the histogram /////////////////////////
							anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-HiggsInfo.Pt")->Fill(higgsbbPt);
							anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-final.dR")->Fill(final_dR);
							anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-final.dPhi")->Fill(final_dPhi);
							anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-final.dPtdivPt")->Fill(final_dPtdivPt1);
							anaTH2f(mapTH2[mass_],"GMdR5dRbCA8-dRHCA8.dPtdivPt")->Fill(final_dPtdivPt1, final_dR); //2D*/
							for( int i=0; i<WJetInfo.Size; i++ ){if( GenMatchPass[i] != 3) GenMatchPass[i] = 0;}//re-initialize except match one
						}
				} //higgs -> bbbar 
			}//genParticle 

			////////////////////////// Fill the histogram /////////////////////////
			//////// EventInfo for Match and UnMatched ////////
			if ( hbbCount != 0){
				int tmp_count1 = 0;
				int tmp_count2 = 0;
				int totaldR05  = 0;
				int totaldR05dRbCA8 = 0;
				for ( int hbb_=0; hbb_<hbbCount; hbb_++){
					totaldR05      = GMdR05Count[hbb_] + tmp_count1;
					totaldR05dRbCA8 = GMdR05dRbCA8Count[hbb_ ] + tmp_count2;
					tmp_count1 = GMdR05Count[hbb_];
					tmp_count2 = GMdR05dRbCA8Count[hbb_];
				}
				anaTH1f(mapTH1[mass_],"UnM-EventInfo.NumGenHbb")->Fill(hbbCount);
				anaTH1f(mapTH1[mass_],"GMdR5-EventInfo.NumCA8JetPerHiggs")->Fill(totaldR05/hbbCount);
				anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-EventInfo.NumHiggsLose")->Fill(loseHiggs);	
				anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-EventInfo.NumCA8JetPerHiggs")->Fill(totaldR05dRbCA8/hbbCount);	
			}
			if ( hbbCount == 2 ){
				if ( hbbWJetMatch[0]==hbbWJetMatch[1] &&  hbbWJetMatch[0]!=-1) { 
					MatchSameWJet++;
					anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-EventInfo.Num2HbbMatchSameCA8Jet")->Fill(1);
				}
			}
			///////// CA8 Jet Info ///////
			for( int wjet=0; wjet<WJetInfo.Size; wjet++ ){
				if ( WJetInfo.Pt[wjet] < 200 ) continue;
				if ( WJetInfo.Mass[wjet] > 175 || WJetInfo.Mass[wjet] < 75 ) continue;
				int b1_pdgID;
				int b2_pdgID;
				bool  match  = false;
				float hbb_pt = 0;
				float hbb_eta = 0;
				float hbb_phi = 0;
				float b1_eta;
				float b1_phi;
				float b2_eta;
				float b2_phi;
				float massD1 = WJetInfo.MassD1[wjet];
				float massD2 = WJetInfo.MassD2[wjet];
				float ptD1   = WJetInfo.PtD1[wjet];
				float ptD2   = WJetInfo.PtD2[wjet];
				float etaD1  = WJetInfo.EtaD1[wjet];
				float etaD2  = WJetInfo.EtaD2[wjet];
				float phiD1  = WJetInfo.PhiD1[wjet];
				float phiD2  = WJetInfo.PhiD2[wjet];
				float DmassSum_ = massD1 + massD2;
				float DmassInv_ = lorentzPairMass( ptD1, etaD1, phiD1, massD1, ptD2, etaD2, phiD2, massD2 );
				float dRHCA8 = 0;
				float dRD1H = 0;
				float dRD2H = 0;
				float dRb1CA8 = 0;
				float dRb2CA8 = 0;
				float dRb1b2  = 0;
				float ratio   = DmassInv_/WJetInfo.Mass[wjet];
				float ratioD1   = massD1/WJetInfo.Mass[wjet];
				float ratioD2   = massD2/WJetInfo.Mass[wjet];
				float dRD1CA8 = dR(etaD1,WJetInfo.Eta[wjet],phiD1,WJetInfo.Phi[wjet]);
				float dRD2CA8 = dR(etaD2,WJetInfo.Eta[wjet],phiD2,WJetInfo.Phi[wjet]);
				//////// Fill un-Matched info //////////
				anaTH1f(mapTH1[mass_],"UnM-Select-CA8JetInfo.GenPdgID")->Fill(WJetInfo.GenPdgID[wjet]);
				anaTH1f(mapTH1[mass_],"UnM-Select-CA8JetInfo.Pt")->Fill(WJetInfo.Pt[wjet]);
				anaTH1f(mapTH1[mass_],"UnM-Select-CA8JetInfo.Mass")->Fill(WJetInfo.Mass[wjet]);
				anaTH1f(mapTH1[mass_],"UnM-Select-CA8JetInfo.dR.SubJetCA8")->Fill(dRD1CA8);
				anaTH1f(mapTH1[mass_],"UnM-Select-CA8JetInfo.dR.SubJetCA8")->Fill(dRD2CA8);
				anaTH1f(mapTH1[mass_],"UnM-Select-CA8JetInfo.DPt")->Fill(ptD1);
				anaTH1f(mapTH1[mass_],"UnM-Select-CA8JetInfo.DPt")->Fill(ptD2);
				anaTH1f(mapTH1[mass_],"UnM-Select-CA8JetInfo.DMass")->Fill(massD1);
				anaTH1f(mapTH1[mass_],"UnM-Select-CA8JetInfo.DMass")->Fill(massD2);
				anaTH1f(mapTH1[mass_],"UnM-Select-CA8JetInfo.DMass.Ratio")->Fill(ratioD1);
				anaTH1f(mapTH1[mass_],"UnM-Select-CA8JetInfo.DMass.Ratio")->Fill(ratioD2);
				anaTH1f(mapTH1[mass_],"UnM-Select-CA8JetInfo.DMassSum")->Fill(DmassSum_);
				anaTH1f(mapTH1[mass_],"UnM-Select-CA8JetInfo.DMassLorentzSum")->Fill(DmassInv_);
				anaTH1f(mapTH1[mass_],"UnM-Select-CA8JetInfo.DMassLorentzSum_Ratio")->Fill(ratio);
				anaTH2f(mapTH2[mass_],"UnM-DMassRatio.CA8Mass")->Fill(WJetInfo.Mass[wjet],ratio);
				if( WJetInfo.DoubleSVHighEffBJetTags[wjet]>0 ){
					anaTH1f(mapTH1[mass_],"UnM-Select-CA8JetInfo.Pt.NumCA8PDoubleBTag")->Fill(WJetInfo.Pt[wjet]);
					anaTH1f(mapTH1[mass_],"UnM-Select-2BTagCA8JetInfo.Mass")->Fill(WJetInfo.Mass[wjet]);
					anaTH1f(mapTH1[mass_],"UnM-Select-2BTagCA8JetInfo.dR.SubJetCA8")->Fill(dRD1CA8);
					anaTH1f(mapTH1[mass_],"UnM-Select-2BTagCA8JetInfo.dR.SubJetCA8")->Fill(dRD2CA8);
					anaTH1f(mapTH1[mass_],"UnM-Select-2BTagCA8JetInfo.DPt")->Fill(ptD1);
					anaTH1f(mapTH1[mass_],"UnM-Select-2BTagCA8JetInfo.DPt")->Fill(ptD2);
					anaTH1f(mapTH1[mass_],"UnM-Select-2BTagCA8JetInfo.DMass")->Fill(massD1);
					anaTH1f(mapTH1[mass_],"UnM-Select-2BTagCA8JetInfo.DMass")->Fill(massD2);
					anaTH1f(mapTH1[mass_],"UnM-Select-2BTagCA8JetInfo.DMass.Ratio")->Fill(ratioD1);
					anaTH1f(mapTH1[mass_],"UnM-Select-2BTagCA8JetInfo.DMass.Ratio")->Fill(ratioD2);
					anaTH1f(mapTH1[mass_],"UnM-Select-2BTagCA8JetInfo.DMass.LorentzSum")->Fill(DmassInv_);
					anaTH1f(mapTH1[mass_],"UnM-Select-2BTagCA8JetInfo.DMass.LorentzSum.Ratio")->Fill(ratio);
				}
				///////  Fill Matched info /////////
				for ( int i=0; i<hbbCount; i++){  // Relation with H>bb
					if( wjet == hbbWJetMatch[i] ) { // Relation with b-quark and Matched CA8  
						match = true ;
						hbb_pt 	= GenInfo.Pt[hbb[i]];
						hbb_eta = GenInfo.Eta[hbb[i]];
						hbb_phi = GenInfo.Phi[hbb[i]];
						b1_pdgID= GenInfo.PdgID[GenInfo.Da1[hbb[i]]];
						b1_eta	= GenInfo.Eta[GenInfo.Da1[hbb[i]]];
						b1_phi	= GenInfo.Phi[GenInfo.Da1[hbb[i]]];
						b2_pdgID= GenInfo.PdgID[GenInfo.Da2[hbb[i]]];
						b2_eta	= GenInfo.Eta[GenInfo.Da2[hbb[i]]];
						b2_phi	= GenInfo.Phi[GenInfo.Da2[hbb[i]]];
						
						dRHCA8  = dR( hbb_eta, WJetInfo.Eta[wjet], hbb_phi, WJetInfo.Phi[wjet]);
						dRb1b2	= dR( b1_eta, b2_eta, b1_phi, b2_phi);
						dRb1CA8 = dR( b1_eta, WJetInfo.Eta[wjet], b1_phi, WJetInfo.Phi[wjet]);
						dRb2CA8 = dR( b2_eta, WJetInfo.Eta[wjet], b2_phi, WJetInfo.Phi[wjet]);
						dRD1H = dR( etaD1, hbb_eta, phiD1, hbb_phi);
						dRD2H = dR( etaD2, hbb_eta, phiD2, hbb_phi);
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.Genb1PdgID")->Fill(b1_pdgID);
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.Genb2PdgID")->Fill(b2_pdgID);
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.dR.bb")->Fill(dRb1b2);
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.dR.bCA8")->Fill(dRb1CA8);
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.dR.bCA8")->Fill(dRb2CA8);
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.dR.SubJetHbb")->Fill(dRD1H);
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.dR.SubJetHbb")->Fill(dRD2H);

						anaTH2f(mapTH2[mass_],"GMdR5dRbCA8-PtH.dRb1b2")->Fill(hbb_pt,dRb1b2);	
						anaTH2f(mapTH2[mass_],"GMdR5dRbCA8-PtH.bCA8")->Fill(hbb_pt,dRb1CA8);	
						anaTH2f(mapTH2[mass_],"GMdR5dRbCA8-PtH.bCA8")->Fill(hbb_pt,dRb2CA8);	
						anaTH2f(mapTH2[mass_],"GMdR5dRbCA8-MassCA8.dRb1b2")->Fill(WJetInfo.Mass[wjet],dRb1b2);
						anaTH2f(mapTH2[mass_],"GMdR5dRbCA8-MassCA8.dRbCA8")->Fill(WJetInfo.Mass[wjet],dRb1CA8);
						anaTH2f(mapTH2[mass_],"GMdR5dRbCA8-MassCA8.dRbCA8")->Fill(WJetInfo.Mass[wjet],dRb2CA8);
						anaTH2f(mapTH2[mass_],"GMdR5dRbCA8-dRb1b2.dRbCA8")->Fill(dRb1b2,dRb1CA8);
						anaTH2f(mapTH2[mass_],"GMdR5dRbCA8-dRb1b2.dRbCA8")->Fill(dRb1b2,dRb2CA8);
						if( WJetInfo.DoubleSVHighEffBJetTags[wjet]>0 ){
							anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-HiggsInfo.Pt.NumCA8PDoubleBTag")->Fill(hbb_pt);//no matter what there are two hbb be metched the same wjet
							anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-2BTagCA8JetInfo.dR.bb")->Fill(dRb1b2);
							anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-2BTagCA8JetInfo.dR.bCA8")->Fill(dRb1CA8);
							anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-2BTagCA8JetInfo.dR.bCA8")->Fill(dRb2CA8);
							anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-2BTagCA8JetInfo.dR.CA8Hbb")->Fill(dRHCA8);
							anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-2BTagCA8JetInfo.dR.SubJetHbb")->Fill(dRD1H);
							anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-2BTagCA8JetInfo.dR.SubJetHbb")->Fill(dRD2H);
						
							anaTH2f(mapTH2[mass_],"GMdR5dRbCA8-2bTag.PtH.dRb1b2")->Fill(hbb_pt,dRb1b2);	
							anaTH2f(mapTH2[mass_],"GMdR5dRbCA8-2bTag.PtH.bCA8")->Fill(hbb_pt,dRb1CA8);	
							anaTH2f(mapTH2[mass_],"GMdR5dRbCA8-2bTag.PtH.bCA8")->Fill(hbb_pt,dRb2CA8);	
							anaTH2f(mapTH2[mass_],"GMdR5dRbCA8-2bTag.MassCA8.dRb1b2")->Fill(WJetInfo.Mass[wjet],dRb1b2);
							anaTH2f(mapTH2[mass_],"GMdR5dRbCA8-2bTag.MassCA8.dRbCA8")->Fill(WJetInfo.Mass[wjet],dRb1CA8);
							anaTH2f(mapTH2[mass_],"GMdR5dRbCA8-2bTag.MassCA8.dRbCA8")->Fill(WJetInfo.Mass[wjet],dRb2CA8);
							anaTH2f(mapTH2[mass_],"GMdR5dRbCA8-2bTag.dRb1b2.dRbCA8")->Fill(dRb1b2,dRb1CA8);
							anaTH2f(mapTH2[mass_],"GMdR5dRbCA8-2bTag.dRb1b2.dRbCA8")->Fill(dRb1b2,dRb2CA8);
						}
					}
				}
				if( match == true ){ // Relation with SubJet and Matched Jet info.
					float DmassSum_matched_ = massD1 + massD2;
					float DmassInv_matched_ = lorentzPairMass( ptD1, etaD1, phiD1, massD1, ptD2, etaD2, phiD2, massD2 );
					float ratioMatched = DmassInv_matched_/WJetInfo.Mass[wjet];
					//float dRD1CA8 = dR( etaD1, WJetInfo.Eta[wjet], phiD1, WJetInfo.Phi[wjet]);
					//float dRD2CA8 = dR( etaD2, WJetInfo.Eta[wjet], phiD2, WJetInfo.Phi[wjet]);
					anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.GenPdgID")->Fill(WJetInfo.GenPdgID[wjet]);	
					anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.Pt")->Fill(WJetInfo.Pt[wjet]);
					anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.Mass")->Fill(WJetInfo.Mass[wjet]);
					anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.DPt")->Fill(ptD1);
					anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.DPt")->Fill(ptD2);
					anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.DMass")->Fill(WJetInfo.MassD1[wjet]);
					anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.DMass")->Fill(WJetInfo.MassD2[wjet]);
					anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.DMass.Ratio")->Fill(WJetInfo.MassD1[wjet]/WJetInfo.Mass[wjet]);
					anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.DMass.Ratio")->Fill(WJetInfo.MassD2[wjet]/WJetInfo.Mass[wjet]);
					anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.DMassSum")->Fill(DmassSum_matched_);
					anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.DMassLorentzSum")->Fill(DmassInv_matched_);
					anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.DMassLorentzSum.Ratio")->Fill(ratioMatched);
					anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.dR.SubJetCA8")->Fill(dRD1CA8);
					anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.dR.SubJetCA8")->Fill(dRD2CA8);

					anaTH2f(mapTH2[mass_],"GMdR5dRbCA8-DMassRatio.CA8Mass")->Fill(WJetInfo.Mass[wjet],ratioMatched);
					if( WJetInfo.DoubleSVHighEffBJetTags[wjet]>0 ){
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.PDoubleBTag")->Fill(WJetInfo.DoubleSVHighEffBJetTags[wjet]);
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.Pt.NumCA8PDoubleBTag")->Fill(WJetInfo.Pt[wjet]);
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-2BTagCA8JetInfo.Mass")->Fill(WJetInfo.Mass[wjet]);
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-2BTagCA8JetInfo.DPt")->Fill(ptD1);
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-2BTagCA8JetInfo.DPt")->Fill(ptD2);
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-2BTagCA8JetInfo.DMass")->Fill(WJetInfo.MassD1[wjet]);
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-2BTagCA8JetInfo.DMass")->Fill(WJetInfo.MassD2[wjet]);
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-2BTagCA8JetInfo.DMass.Ratio")->Fill(WJetInfo.MassD1[wjet]/WJetInfo.Mass[wjet]);
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-2BTagCA8JetInfo.DMass.Ratio")->Fill(WJetInfo.MassD2[wjet]/WJetInfo.Mass[wjet]);
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-2BTagCA8JetInfo.DMassLorentzSum")->Fill(DmassInv_matched_);
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-2BTagCA8JetInfo.DMassLorentzSum.Ratio")->Fill(ratioMatched);
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-2BTagCA8JetInfo.dR.SubJetCA8")->Fill(dRD1CA8);
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-2BTagCA8JetInfo.dR.SubJetCA8")->Fill(dRD2CA8);
					} else {
						anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.NDoubleBTag")->Fill(WJetInfo.DoubleSVHighEffBJetTags[wjet]);
					}
				} else { // Anti-Matched CA8Jet info
					if( WJetInfo.DoubleSVHighEffBJetTags[wjet]>0 ){
						anaTH1f(mapTH1[mass_],"AntiM-Select-CA8JetInfo.PDoubleBTag")->Fill(WJetInfo.DoubleSVHighEffBJetTags[wjet]);
					} else {
						anaTH1f(mapTH1[mass_],"AntiM-Select-CA8JetInfo.NDoubleBTag")->Fill(WJetInfo.DoubleSVHighEffBJetTags[wjet]);
					}
				}

			}//wjet
		}//entry
		cout<<endl<<newtree->GetEntries()<<endl<<"Finished ^____^"<<endl;
		cout<<"There are two higgsTobb Match to same WJet "<<MatchSameWJet<<" events"<<endl;

		TH1F* Rebin_Pt_Dbtag	= (TH1F*)anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-HiggsInfo.Pt.NumCA8PDoubleBTag")->Clone("Rebin_HbbPt_Dbtag_");
		TH1F* Rebin_Pt		= (TH1F*)anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-HiggsInfo.Pt")->Clone("Rebin_HbbPt_");
		TH1F* Rebin_Pt_noMatch	= (TH1F*)anaTH1f(mapTH1[mass_],"UnM-HiggsInfo.Pt")->Clone("Rebin_HbbPt_unMatch");
		Rebin_Pt_Dbtag->Rebin(10);
		Rebin_Pt->Rebin(10);
		Rebin_Pt_noMatch->Rebin(10);
		anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-HiggsInfo.Pt.EffCA8PDoubleBtag")->Divide( Rebin_Pt_Dbtag, Rebin_Pt, 1, 1); // Divide(h1,h2,c1,c2) = (c1*h1)/(c2*h2)
		anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-HiggsInfo.Pt.EffCA8PDoubleBtag")->SetMinimum(0);
		anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-HiggsInfo.Pt.EffGenMatching")->Divide( Rebin_Pt, Rebin_Pt_noMatch, 1, 1); // Divide(h1,h2,c1,c2) = (c1*h1)/(c2*h2)
		anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-HiggsInfo.Pt.EffGenMatching")->SetMinimum(0);
		cout<<"The PositiveDoubleBtag_Eff bin width is "<<anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-HiggsInfo.Pt.EffCA8PDoubleBtag")->GetBinWidth(5)<<endl;

		TH1F* Rebin_Pt_Dbtag_wjet	= (TH1F*)anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.Pt.NumCA8PDoubleBTag")->Clone("Rebin_Pt_Dbtag_CA8");
		TH1F* Rebin_Pt_wjet		= (TH1F*)anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.Pt")->Clone("Rebin_Pt_CA8");
		Rebin_Pt_Dbtag_wjet->Rebin(10);
		Rebin_Pt_wjet->Rebin(10);
		anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.Pt.EffCA8PDoubleBtag")->Divide( Rebin_Pt_Dbtag_wjet, Rebin_Pt_wjet, 1, 1); // Divide(h1,h2,c1,c2) = (c1*h1)/(c2*h2)
		anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.Pt.EffCA8PDoubleBtag")->SetMinimum(0);
		cout<<"The PositiveDoubleBtag_Eff_wjet bin width is "<<anaTH1f(mapTH1[mass_],"GMdR5dRbCA8-Select-CA8JetInfo.Pt.EffCA8PDoubleBtag")->GetBinWidth(5)<<endl;

		/////////////////////// Save the root file ///////////////////////////
		newfile->Write();
		cout<<"MassPoint "<<SigMC[mass_].massPoint<<" End !!!"<<endl;
	}// masspoint
}
