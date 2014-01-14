///////////////////////////////////////////////////////////////////////////////
///////////////////////////////// Functions ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//////// Files Info Function ///////////
double dPhi(double p1,double p2){ //dPhi
	double dp = p1 - p2;
	if (fabs(dp+3.14159265358979323846*2.) < fabs(dp)) dp += 3.14159265358979323846*2.;
	else
		if (fabs(dp-3.14159265358979323846*2.) < fabs(dp)) dp -= 3.14159265358979323846*2.;
	return fabs(dp);
}
double dR (double e1, double e2, double p1, double p2){ //dR
	return sqrt(pow(e1-e2,2)+pow(dPhi(p1,p2),2));
}
double lorentzPairMass (double pt1, double eta1, double phi1, double mass1,
			double pt2, double eta2, double phi2, double mass2){
	TLorentzVector v1; v1.SetPtEtaPhiM(pt1,eta1,phi1,mass1);
	TLorentzVector v2; v2.SetPtEtaPhiM(pt2,eta2,phi2,mass2);
	TLorentzVector v3 = v1 + v2;
	return v3.M();
}
