#ifndef BPRIMETOBH_INTERFACE_JET_H
#define BPRIMETOBH_INTERFACE_JET_H

#include "TLorentzVector.h"
#include "/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/brch/interface/format.h"

class Jet {

  public:

    Jet (const Jet& jet) { 

      index_ = jet.Index();
      Et_ = jet.Et() ;
      Pt_ = jet.Pt() ;
      Unc_ = jet.Unc() ;
      Eta_ = jet.Eta() ;
      Phi_ = jet.Phi() ;

      Energy_ = jet.Energy() ; 
      Px_ = jet.Px() ;     
      Py_ = jet.Py() ;     
      Pz_ = jet.Pz() ;     
      Mass_ = jet.Mass() ;
      Area_ = jet.Area() ;

      EtPruned_ = jet.EtPruned() ;            
      PtPruned_ = jet.PtPruned() ;            
      UncPruned_ = jet.UncPruned() ;            
      EtaPruned_ = jet.EtaPruned() ;            
      PhiPruned_ = jet.PhiPruned() ;             

      EnergyPruned_ = jet.EnergyPruned() ; 
      PxPruned_ = jet.PxPruned() ; 
      PyPruned_ = jet.PyPruned() ; 
      PzPruned_ = jet.PzPruned() ; 
      MassPruned_ = jet.MassPruned() ; 
      AreaPruned_ = jet.AreaPruned() ; 

      tau1_ = jet.tau1() ; 
      tau2_ = jet.tau2() ; 
      tau3_ = jet.tau3() ; 

      GenJetPt_ = jet.GenJetPt() ;
      GenJetEta_ = jet.GenJetEta() ;
      GenJetPhi_ = jet.GenJetPhi() ;
      GenPt_ = jet.GenPt() ;
      GenEta_ = jet.GenEta() ;
      GenPhi_ = jet.GenPhi() ;
      GenPdgID_ = jet.GenPdgID() ;
      GenFlavor_ = jet.GenFlavor() ;
      GenMCTag_ = jet.GenMCTag() ; 

      JetIDLOOSE_ = jet.JetIDLOOSE() ; 
      JetIDTIGHT_ = jet.JetIDTIGHT() ; 
      JetCharge_ = jet.JetCharge() ;
      QGTagsMLP_ = jet.QGTagsMLP() ;
      QGTagsLikelihood_ = jet.QGTagsLikelihood() ;
      NConstituents_ = jet.NConstituents() ;
      NTracks_ = jet.NTracks() ;
      NCH_ = jet.NCH() ;
      CEF_ = jet.CEF() ;
      NHF_ = jet.NHF() ;
      NEF_ = jet.NEF() ;
      CHF_ = jet.CHF() ;

      PtCorrRaw_ = jet.PtCorrRaw() ;  
      PtCorrL2_ = jet.PtCorrL2() ;  
      PtCorrL3_ = jet.PtCorrL3() ;  
      PtCorrL7g_ = jet.PtCorrL7g() ;
      PtCorrL7uds_ = jet.PtCorrL7uds() ;
      PtCorrL7c_ = jet.PtCorrL7c() ;  
      PtCorrL7b_ = jet.PtCorrL7b() ;  

      JetBProbBJetTags_ = jet.JetBProbBJetTags() ;
      JetProbBJetTags_ = jet.JetProbBJetTags() ;
      TrackCountHiPurBJetTags_ = jet.TrackCountHiPurBJetTags() ;  
      CombinedSVBJetTags_ = jet.CombinedSVBJetTags() ;
      CombinedSVMVABJetTags_ = jet.CombinedSVMVABJetTags() ;
      SoftElecByIP3dBJetTags_ = jet.SoftElecByIP3dBJetTags() ;
      SoftElecByPtBJetTags_ = jet.SoftElecByPtBJetTags() ;  
      SoftMuonBJetTags_ = jet.SoftMuonBJetTags() ;      
      SoftMuonByIP3dBJetTags_ = jet.SoftMuonByIP3dBJetTags() ;
      SoftMuonByPtBJetTags_ = jet.SoftMuonByPtBJetTags() ;  
      DoubleSVHighEffBJetTags_ = jet.DoubleSVHighEffBJetTags() ; 

      Jet_FatJetIdx_ = jet.Jet_FatJetIdx() ;
      Jet_SubJet1Idx_ = jet.Jet_SubJet1Idx() ;
      Jet_SubJet2Idx_ = jet.Jet_SubJet2Idx() ;

      IsBtaggedCSVL_ = false ;  
      IsBtaggedCSVM_ = false ;  
      IsBtaggedCSVT_ = false ;  
    } 

    Jet(JetInfoBranches& JetInfo, int& JetIndex) { 
      index_ = JetIndex;

      Et_ = JetInfo.Et[JetIndex];
      Pt_ = JetInfo.Pt[JetIndex];
      Unc_ = JetInfo.Unc[JetIndex];
      Eta_ = JetInfo.Eta[JetIndex];
      Phi_ = JetInfo.Phi[JetIndex];

      Energy_ = JetInfo.Energy[JetIndex]; 
      Px_ = JetInfo.Px[JetIndex];     
      Py_ = JetInfo.Py[JetIndex];     
      Pz_ = JetInfo.Pz[JetIndex];     
      Mass_ = JetInfo.Mass[JetIndex];
      Area_ = JetInfo.Area[JetIndex];

      EtPruned_ = JetInfo.EtPruned[JetIndex];            
      PtPruned_ = JetInfo.PtPruned[JetIndex];            
      UncPruned_ = JetInfo.UncPruned[JetIndex];            
      EtaPruned_ = JetInfo.EtaPruned[JetIndex];            
      PhiPruned_ = JetInfo.PhiPruned[JetIndex];             

      EnergyPruned_ = JetInfo.EnergyPruned[JetIndex]; 
      PxPruned_ = JetInfo.PxPruned[JetIndex]; 
      PyPruned_ = JetInfo.PyPruned[JetIndex]; 
      PzPruned_ = JetInfo.PzPruned[JetIndex]; 
      MassPruned_ = JetInfo.MassPruned[JetIndex]; 
      AreaPruned_ = JetInfo.AreaPruned[JetIndex]; 

      tau1_ = JetInfo.tau1[JetIndex]; 
      tau2_ = JetInfo.tau2[JetIndex]; 
      tau3_ = JetInfo.tau3[JetIndex]; 

      GenJetPt_ = JetInfo.GenJetPt[JetIndex];
      GenJetEta_ = JetInfo.GenJetEta[JetIndex];
      GenJetPhi_ = JetInfo.GenJetPhi[JetIndex];
      GenPt_ = JetInfo.GenPt[JetIndex];
      GenEta_ = JetInfo.GenEta[JetIndex];
      GenPhi_ = JetInfo.GenPhi[JetIndex];
      GenPdgID_ = JetInfo.GenPdgID[JetIndex];
      GenFlavor_ = JetInfo.GenFlavor[JetIndex];
      GenMCTag_ = JetInfo.GenMCTag[JetIndex]; 

      JetIDLOOSE_ = JetInfo.JetIDLOOSE[JetIndex]; 
      JetIDTIGHT_ = JetInfo.JetIDTIGHT[JetIndex]; 
      JetCharge_ = JetInfo.JetCharge[JetIndex];
      QGTagsMLP_ = JetInfo.QGTagsMLP[JetIndex];
      QGTagsLikelihood_ = JetInfo.QGTagsLikelihood[JetIndex];
      NConstituents_ = JetInfo.NConstituents[JetIndex];
      NTracks_ = JetInfo.NTracks[JetIndex];
      NCH_ = JetInfo.NCH[JetIndex];
      CEF_ = JetInfo.CEF[JetIndex];
      NHF_ = JetInfo.NHF[JetIndex];
      NEF_ = JetInfo.NEF[JetIndex];
      CHF_ = JetInfo.CHF[JetIndex];

      PtCorrRaw_ = JetInfo.PtCorrRaw[JetIndex];  
      PtCorrL2_ = JetInfo.PtCorrL2[JetIndex];  
      PtCorrL3_ = JetInfo.PtCorrL3[JetIndex];  
      PtCorrL7g_ = JetInfo.PtCorrL7g[JetIndex];
      PtCorrL7uds_ = JetInfo.PtCorrL7uds[JetIndex];
      PtCorrL7c_ = JetInfo.PtCorrL7c[JetIndex];  
      PtCorrL7b_ = JetInfo.PtCorrL7b[JetIndex];  

      JetBProbBJetTags_ = JetInfo.JetBProbBJetTags[JetIndex];
      JetProbBJetTags_ = JetInfo.JetProbBJetTags[JetIndex];
      TrackCountHiPurBJetTags_ = JetInfo.TrackCountHiPurBJetTags[JetIndex];  
      CombinedSVBJetTags_ = JetInfo.CombinedSVBJetTags[JetIndex];
      CombinedSVMVABJetTags_ = JetInfo.CombinedSVMVABJetTags[JetIndex];
      SoftElecByIP3dBJetTags_ = JetInfo.SoftElecByIP3dBJetTags[JetIndex];
      SoftElecByPtBJetTags_ = JetInfo.SoftElecByPtBJetTags[JetIndex];  
      SoftMuonBJetTags_ = JetInfo.SoftMuonBJetTags[JetIndex];      
      SoftMuonByIP3dBJetTags_ = JetInfo.SoftMuonByIP3dBJetTags[JetIndex];
      SoftMuonByPtBJetTags_ = JetInfo.SoftMuonByPtBJetTags[JetIndex];  
      DoubleSVHighEffBJetTags_ = JetInfo.DoubleSVHighEffBJetTags[JetIndex]; 

      Jet_FatJetIdx_ = JetInfo.Jet_FatJetIdx[JetIndex];
      Jet_SubJet1Idx_ = JetInfo.Jet_SubJet1Idx[JetIndex];
      Jet_SubJet2Idx_ = JetInfo.Jet_SubJet2Idx[JetIndex];

      IsBtaggedCSVL_ = false ;  
      IsBtaggedCSVM_ = false ;  
      IsBtaggedCSVT_ = false ;  
    }

    ~Jet () {} ;

    int Index() const { return index_; }
	
    float Et() const { return Et_ ; } 
    float Pt() const { return Pt_ ; } 
    float Unc() const { return Unc_ ; } 
    float Eta() const { return Eta_ ; } 
    float Phi() const { return Phi_ ; } 

    float Energy() const { return Energy_ ; }  
    float Px() const { return Px_ ; }      
    float Py() const { return Py_ ; }      
    float Pz() const { return Pz_ ; }      
    float Mass() const { return Mass_ ; } 
    float Area() const { return Area_ ; } 

    float EtPruned() const { return EtPruned_ ; }             
    float PtPruned() const { return PtPruned_ ; }             
    float UncPruned() const { return UncPruned_ ; }             
    float EtaPruned() const { return EtaPruned_ ; }             
    float PhiPruned() const { return PhiPruned_ ; }              

    float EnergyPruned() const { return EnergyPruned_ ; }  
    float PxPruned() const { return PxPruned_ ; }  
    float PyPruned() const { return PyPruned_ ; }  
    float PzPruned() const { return PzPruned_ ; }  
    float MassPruned() const { return MassPruned_ ; }  
    float AreaPruned() const { return AreaPruned_ ; }  

    float tau1() const { return tau1_ ; }  
    float tau2() const { return tau2_ ; }  
    float tau3() const { return tau3_ ; }  

    float GenJetPt() const { return GenJetPt_ ; } 
    float GenJetEta() const { return GenJetEta_ ; } 
    float GenJetPhi() const { return GenJetPhi_ ; } 
    float GenPt() const { return GenPt_ ; } 
    float GenEta() const { return GenEta_ ; } 
    float GenPhi() const { return GenPhi_ ; } 
    int   GenPdgID() const { return   GenPdgID_ ; } 
    int   GenFlavor() const { return   GenFlavor_ ; } 
    int   GenMCTag() const { return   GenMCTag_ ; }  

    bool  JetIDLOOSE() const { return  JetIDLOOSE_ ; }  
    bool  JetIDTIGHT() const { return  JetIDTIGHT_ ; }  
    float JetCharge() const { return JetCharge_ ; } 
    float QGTagsMLP() const { return QGTagsMLP_ ; } 
    float QGTagsLikelihood() const { return QGTagsLikelihood_ ; } 
    int   NConstituents() const { return   NConstituents_ ; } 
    int   NTracks() const { return   NTracks_ ; } 
    int   NCH() const { return   NCH_ ; } 
    float CEF() const { return CEF_ ; } 
    float NHF() const { return NHF_ ; } 
    float NEF() const { return NEF_ ; } 
    float CHF() const { return CHF_ ; } 

    float PtCorrRaw() const { return PtCorrRaw_ ; }   
    float PtCorrL2() const { return PtCorrL2_ ; }   
    float PtCorrL3() const { return PtCorrL3_ ; }   
    float PtCorrL7g() const { return PtCorrL7g_ ; } 
    float PtCorrL7uds() const { return PtCorrL7uds_ ; } 
    float PtCorrL7c() const { return PtCorrL7c_ ; }   
    float PtCorrL7b() const { return PtCorrL7b_ ; }   

    float JetBProbBJetTags() const { return JetBProbBJetTags_ ; } 
    float JetProbBJetTags() const { return JetProbBJetTags_ ; } 
    float TrackCountHiPurBJetTags() const { return TrackCountHiPurBJetTags_ ; }   
    float CombinedSVBJetTags() const { return CombinedSVBJetTags_ ; } 
    float CombinedSVMVABJetTags() const { return CombinedSVMVABJetTags_ ; } 
    float SoftElecByIP3dBJetTags() const { return SoftElecByIP3dBJetTags_ ; } 
    float SoftElecByPtBJetTags() const { return SoftElecByPtBJetTags_ ; }   
    float SoftMuonBJetTags() const { return SoftMuonBJetTags_ ; }       
    float SoftMuonByIP3dBJetTags() const { return SoftMuonByIP3dBJetTags_ ; } 
    float SoftMuonByPtBJetTags() const { return SoftMuonByPtBJetTags_ ; }   
    float DoubleSVHighEffBJetTags() const { return DoubleSVHighEffBJetTags_ ; }  

    int Jet_FatJetIdx() const { return Jet_FatJetIdx_ ; } 
    int Jet_SubJet1Idx() const { return Jet_SubJet1Idx_ ; } 
    int Jet_SubJet2Idx() const { return Jet_SubJet2Idx_ ; } 

    bool IsBtaggedCSVL() const { return IsBtaggedCSVL_ ; }  
    bool IsBtaggedCSVM() const { return IsBtaggedCSVM_ ; }  
    bool IsBtaggedCSVT() const { return IsBtaggedCSVT_ ; }  

    double DeltaR(const Jet Jet2) const{	
	TLorentzVector p4_Jet1, p4_Jet2;
	p4_Jet1.SetPtEtaPhiM( this->Pt(), this->Eta(), this->Phi(), this->Mass());
	p4_Jet2.SetPtEtaPhiM( Jet2.Pt(), Jet2.Eta(), Jet2.Phi(), Jet2.Mass());
	double dR_ = p4_Jet1.DeltaR(p4_Jet2);
	
	return dR_;
    }
    double DeltaR(const TLorentzVector p4_Jet2) const{	
	TLorentzVector p4_Jet1;
	p4_Jet1.SetPtEtaPhiM( this->Pt(), this->Eta(), this->Phi(), this->Mass());
	double dR_ = p4_Jet1.DeltaR(p4_Jet2);
	
	return dR_;
    }
  private:

    int index_;

    float Et_ ;
    float Pt_ ;
    float Unc_ ;
    float Eta_ ;
    float Phi_ ;

    float Energy_ ; 
    float Px_ ;     
    float Py_ ;     
    float Pz_ ;     
    float Mass_ ;
    float Area_ ;

    float EtPruned_ ;            
    float PtPruned_ ;            
    float UncPruned_ ;            
    float EtaPruned_ ;            
    float PhiPruned_ ;             

    float EnergyPruned_ ; 
    float PxPruned_ ; 
    float PyPruned_ ; 
    float PzPruned_ ; 
    float MassPruned_ ; 
    float AreaPruned_ ; 

    float tau1_ ; 
    float tau2_ ; 
    float tau3_ ; 

    float GenJetPt_ ;
    float GenJetEta_ ;
    float GenJetPhi_ ;
    float GenPt_ ;
    float GenEta_ ;
    float GenPhi_ ;
    int   GenPdgID_ ;
    int   GenFlavor_ ;
    int   GenMCTag_ ; 

    bool  JetIDLOOSE_ ; 
    bool  JetIDTIGHT_ ; 
    float JetCharge_ ;
    float QGTagsMLP_ ;
    float QGTagsLikelihood_ ;
    int   NConstituents_ ;
    int   NTracks_ ;
    int   NCH_ ;
    float CEF_ ;
    float NHF_ ;
    float NEF_ ;
    float CHF_ ;

    float PtCorrRaw_ ;  
    float PtCorrL2_ ;  
    float PtCorrL3_ ;  
    float PtCorrL7g_ ;
    float PtCorrL7uds_ ;
    float PtCorrL7c_ ;  
    float PtCorrL7b_ ;  

    float JetBProbBJetTags_ ;
    float JetProbBJetTags_ ;
    float TrackCountHiPurBJetTags_ ;  
    float CombinedSVBJetTags_ ;
    float CombinedSVMVABJetTags_ ;
    float SoftElecByIP3dBJetTags_ ;
    float SoftElecByPtBJetTags_ ;  
    float SoftMuonBJetTags_ ;      
    float SoftMuonByIP3dBJetTags_ ;
    float SoftMuonByPtBJetTags_ ;  
    float DoubleSVHighEffBJetTags_ ; 

    int Jet_FatJetIdx_ ;
    int Jet_SubJet1Idx_ ;
    int Jet_SubJet2Idx_ ;

    bool IsBtaggedCSVL_ ;  
    bool IsBtaggedCSVM_ ;  
    bool IsBtaggedCSVT_ ;  

};

#endif 
