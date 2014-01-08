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

using namespace std;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////// Analysis start //////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void ana3() 
{
	///////////////////// Create New Tree and Forder //////////////////////==============================================================================
	TFile* newfile1 = new TFile( "TT700to1000_Mtt.root");
	TFile* newfile2 = new TFile( "TT1000_Mtt.root");
	TFile* newfile3 = new TFile( "Weight_TT700_Mtt.root", "recreate");
	cout <<"Folder create"<<endl;


	////////////////////// Initialize the Histogram ///////////////////////=============================================================================
	TH1F* Mtt1 = (TH1F*)newfile1->Get("Mtt");	
	TH1F* Mtt2 = (TH1F*)newfile2->Get("Mtt");	
	TH1F* Mtt = new TH1F("Mtt","",100, 0,2000);	

	///////////////////// Get by event to Analysis ////////////////////////=============================================================================
	Mtt1->Scale(19.6*1000*18.1892/3079071);
	Mtt2->Scale(19.6*1000*3.4412/1246340);
	Mtt->Add(Mtt1,Mtt2);
	newfile3->Write();
}
