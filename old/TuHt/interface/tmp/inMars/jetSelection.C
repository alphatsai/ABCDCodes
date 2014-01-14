//#include "myformat.h"
/////////////// CA8 Info Function ///////////
bool JetInfoBranches::is2bCA8(int i){
	bool keep = 1;
	bool bad  = 0;
	if( DoubleSVHighEffBJetTags[i]<0 ) return bad;
	return keep;
}

bool JetInfoBranches::isGoodCA8(int i){
	bool keep = 1;
	bool bad  = 0;
	if( Pt[i]<=300 ) return bad;
	if( Eta[i]<=-2.4 || Eta[i]>=2.4) return bad;
	if( Mass[i]<=75 || Mass[i]>=175  ) return bad;
	return keep;
}

bool JetInfoBranches::isGood2bCA8(int i){
	bool keep = 1;
	bool bad  = 0;
	if( Pt[i]<=300 ) return bad;
	if( Eta[i]<=-2.4 || Eta[i]>=2.4) return bad;
	if( Mass[i]<=75 || Mass[i]>=175  ) return bad;
	if( DoubleSVHighEffBJetTags[i]<0 ) return bad;
	return keep;
}


///////////////  AK5 Info Function //////////
//b tag loss : 0.244
//	mid  : 0.679
//	tight: 0.898

bool JetInfoBranches::isbAK5(int i){
	bool keep = 1;
	bool bad  = 0;
	if( CombinedSVBJetTags[i]<=0.679) return bad; 
	//if( CombinedSVBJetTags[i]<=0.244) return bad; 
	return keep;
}

bool JetInfoBranches::isGoodAK5(int i){
	bool keep = 1;
	bool bad  = 0;
	if( JetIDLOOSE[i] == 0 ) return bad;
	if( NHF[i]>=0.90 ) return bad;  //Tight JetID
	if( NEF[i]>=0.90 ) return bad;  //Tight JetID
	if( Pt[i]<=100 ) return bad; 
	if( Eta[i]<=-2.4 || Eta[i]>=2.4) return bad;
	return keep;

}

bool JetInfoBranches::isGoodbAK5(int i){
	bool keep = 1;
	bool bad  = 0;
	if( JetIDLOOSE[i] == 0 ) return bad;
	if( NHF[i]>=0.90 ) return bad;  //Tight JetID
	if( NEF[i]>=0.90 ) return bad;  //Tight JetID
	if( Pt[i]<=100 ) return bad; 
	if( Eta[i]<=-2.4 || Eta[i]>=2.4) return bad;
	if( CombinedSVBJetTags[i]<=0.679) return bad; 
	//if( CombinedSVBJetTags[i]<=0.244) return bad;
	return keep;
}
