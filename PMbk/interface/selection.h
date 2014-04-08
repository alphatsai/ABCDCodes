#ifndef SELECTION_H
#define SELECTION_H

const bool buildTree=1;

const float ABCD1_yCut=90.;
const float ABCD1_yCutLow=80.;
const float ABCD1_xCut=1.;

const float HT_Min=900.;
const float HT_Max=1.E6;
const float AK5JetPt_Min=50.;
const float AK5JetPt_Max=1.E6;
const float AK5JetAbsEta=2.4;
const float CA8JetPt_Min=300.;
const float CA8JetPt_Max=1.E6;
const float CA8JetAbsEta=2.4;
const float CA8JetMass_Min=100.;
const float CA8JetMass_Max=150.;
const float CA8JetPrunedMass_Min=90.;
const float CA8JetPrunedMass_Max=140.;
const float CA8JetTau2ByTau1_Max=0.5;
const float SubjetdR_Min=0.4;
const float SubjetdR_Max=0.8;
const float Subjet1CSV_Min=0.679;
//const float Subjet1CSV_Min=0.244;
const float Subjet1CSV_Max=1.000;
const float Subjet2CSV_Min=0.679;
//const float Subjet2CSV_Min=0.244;
const float Subjet2CSV_Max=1.000;
const float bJetPt_Min=80.;

//const unsigned int num_bJets=2;
const unsigned int num_bJets=1;
const unsigned int num_HiggsJets=1;


#endif
