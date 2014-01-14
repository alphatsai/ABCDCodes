//#include "myformat.h"
/////////////// Gen Info Function ///////////
bool GenInfoBranches::MttCut(){
	float mtt=0;
	bool ignoreEvt=0;
	for( int i=0; i<Size; i++){
		if  ( PdgID[i] == 6 || PdgID[i]== -6 ) {
			int pdgIDi = PdgID[i];
			for( int j=i+1; j<Size; j++){
				if (  PdgID[j] == pdgIDi ) continue;	
				mtt=lorentzPairMass(Pt[i],Eta[i],Phi[i],Mass[i],Pt[j],Eta[j],Phi[j],Mass[j]);
				if( mtt >=700 ){
					ignoreEvt=1;
				}
			}
		}
	}
	return ignoreEvt;
}
