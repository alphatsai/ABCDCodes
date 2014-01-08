#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include "TFile.h"
#include "TH1.h"
#include "TH1F.h"
#include "TH2F.h"
#include "THStack.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TROOT.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/1209/interface/sampleInfo.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/1209/interface/plotsInfo.h"
#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/1209/interface/setTDRStyle.C"
using namespace std;

void plot(TCanvas* c2, TH1F* h1, Color_t color, string save){
        c2->SetGridx();
        c2->SetGridy();
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	h1->SetLineColor(color); 
	h1->SetLineWidth(5); 
	h1->Draw();
	c2->SaveAs(save.c_str());
}

void StackPlots(){

	setTDRStyle();
	
	bool outputUnScalePlot = 0;
	bool outputScaledPlot = 0;

//	bool outputUnScalePlot = 1;
//	bool outputScaledPlot = 1;
	
	////= Correct histogram Info.  =======================================================================
	TFile* sigf[SigMC_TotalNum];
	TFile* qcdf[QCDMC_TotalNum];	
	TFile* ttf[TTMC_TotalNum];  	
	TFile* bosf[BosMC_TotalNum];	
	
	string SavePngPath = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/1209/resurlt/png/stack";
	string SavePngPaths = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/1209/resurlt/png/mc/sig";
	string SavePngPathbq = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/1209/resurlt/png/mc/bg";
	string SigRootPath = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/1209/resurlt/root/mc/sig";
	string BgRootPath  = "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/1209/resurlt/root/mc/bg";

	vector<double> 	scale_QCD, scale_TT, scale_Bos;
	
	for(int i=0; i<SigMC_TotalNum; i++){
		string path = SigRootPath+"/"+SigMC[i].name+".root";
		sigf[i] = new TFile(path.c_str());
	}
	for(int i=0; i<QCDMC_TotalNum; i++){
		string path = BgRootPath+"/"+QCDMC[i].name+".root";
		qcdf[i] = new TFile(path.c_str());
		cout<<QCDMC[i].name<<" "<<1000*lumi*QCDMC[i].xsec/QCDMC[i].totalEvt<<endl;
	}
	for(int i=0; i<TTMC_TotalNum; i++){
		string path = BgRootPath+"/"+TTMC[i].name+".root";
		ttf[i] = new TFile(path.c_str());
		cout<<TTMC[i].name<<" "<<1000*lumi*TTMC[i].xsec/TTMC[i].totalEvt<<endl;
	}
	for(int i=0; i<BosMC_TotalNum; i++){
		string path = BgRootPath+"/"+BosMC[i].name+".root";
		bosf[i] = new TFile(path.c_str());
		cout<<BosMC[i].name<<" "<<1000*lumi*BosMC[i].xsec/BosMC[i].totalEvt<<endl;
	}

	TH1F* sigH[th1_size_][SigMC_TotalNum];	
	TH1F* qcdH[th1_size_][SigMC_TotalNum][QCDMC_TotalNum];	
	TH1F* ttH[th1_size_][SigMC_TotalNum][TTMC_TotalNum];	
	TH1F* bosH[th1_size_][SigMC_TotalNum][BosMC_TotalNum];	
	TH1F* hs_stack[th1_size_][SigMC_TotalNum];		
	THStack* hs[th1_size_][SigMC_TotalNum];	
	TLegend* leg_[th1_size_][SigMC_TotalNum]; 

	TCanvas* c1 = new TCanvas( "dR_hPt_color", "", 850, 700);
        c1->SetGridx();
        c1->SetGridy();
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);

	////= Draw all histogram  =======================================================================
	for( int i=0; i<th1_size_; i++){
		//if(i!=19) continue;
		if( TH1Info[i].output ){
			//for( int j=0; j<SigMC_TotalNum; j++){
			for( int j=0; j<1; j++){
				string buffer="hs_stack"+j;
				int Bins = 0;
				int x1 = 0;
				int x2 = 0;
				float binwidth = 0;
				char title[100], xtitle[100], ytitle[100];
				////= For signal and title setting ====================================================
				string spathsig1 = SavePngPaths+"/"+SigMC[j].name+"_"+TH1Info[i].name+".png"; 
				string spathsig2 = SavePngPaths+"/"+SigMC[j].name+"_scaled_"+TH1Info[i].name+".png"; 
				sigH[i][j] = (TH1F*)sigf[j]->Get(TH1Info[i].name.c_str());
				sigH[i][j]->UseCurrentStyle();
				sigH[i][j]->Rebin(OtherInfo[i].rebin); 
				sigH[i][j]->SetLineWidth(5); 
				sigH[i][j]->SetLineStyle(1); 
				
				Bins = sigH[i][j]->GetXaxis()->GetLast();
				binwidth = sigH[i][j]->GetBinWidth(1);
				x1 = sigH[i][j]->GetXaxis()->GetBinLowEdge(1);
				x2 = sigH[i][j]->GetXaxis()->GetBinUpEdge(Bins);
				if( TH1Info[i].xunit.size()!=0 ){
					sprintf( xtitle, "%s [%s]", TH1Info[i].xtitle.c_str(),TH1Info[i].xunit.c_str());
					if (binwidth<1){
						sprintf( ytitle, "%s / [%0.2f%s]", TH1Info[i].ytitle.c_str(),binwidth,TH1Info[i].xunit.c_str());
					}else{
						sprintf( ytitle, "%s / [%2.1f%s]", TH1Info[i].ytitle.c_str(),binwidth,TH1Info[i].xunit.c_str());
					}
				}else{
					sprintf( xtitle, "%s", TH1Info[i].xtitle.c_str());
					sprintf( ytitle, "%s", TH1Info[i].ytitle.c_str());
				}
				sprintf(title,";%s;%s",xtitle,ytitle);
				sigH[i][j]->SetXTitle(xtitle);
				sigH[i][j]->SetYTitle(ytitle);

				if ( outputUnScalePlot ){
					 plot( c1, sigH[i][j], 2, spathsig1 ); 
				}

				sigH[i][j]->Scale(1000*lumi*SigMC[j].xsec/SigMC[j].totalEvt);
 
				if ( outputScaledPlot ){
					 plot( c1, sigH[i][j], 4, spathsig2 ); 
				}

				sigH[i][j]->SetLineWidth(3); 
				sigH[i][j]->SetLineColor(Category[0].StackColor); 
				sigH[i][j]->SetLineStyle(1); 
				////= For Stack =====================================================
				hs_stack[i][j] = new TH1F(buffer.c_str(),title,Bins,x1,x2); //cout<<title<<" "<<Bins<<" "<<x1<<" "<<x2<<endl;
				hs[i][j] = new THStack("hs", ""); 
				hs_stack[i][j]->UseCurrentStyle();
				hs[i][j]->SetHistogram(hs_stack[i][j]);

				////= For Bground( QCD,tt, boson ), Setting, stack ==============================================
				for(int k=0; k<QCDMC_TotalNum; k++ ){ //For QCD
					qcdH[i][j][k] = (TH1F*)qcdf[k]->Get(TH1Info[i].name.c_str()); 			
					string spath1 = SavePngPathbq+"/"+QCDMC[k].name+"_"+TH1Info[i].name+".png"; 
					string spath2 = SavePngPathbq+"/"+QCDMC[k].name+"_scaled_"+TH1Info[i].name+".png"; 
					qcdH[i][j][k]->UseCurrentStyle();
					qcdH[i][j][k]->Rebin(OtherInfo[i].rebin); 
					qcdH[i][j][k]->SetXTitle(xtitle);
					qcdH[i][j][k]->SetYTitle(ytitle);
					if ( j==0 && outputUnScalePlot ){
				 		plot( c1, qcdH[i][j][k], 2, spath1 ); 
					}
					qcdH[i][j][k]->Scale(1000*lumi*QCDMC[k].xsec/QCDMC[k].totalEvt);
					if ( j==0 && outputScaledPlot ){
				 		plot( c1, qcdH[i][j][k], 4, spath2 ); 
					} 
					qcdH[i][j][k]->SetLineWidth(1); 
					qcdH[i][j][k]->SetLineColor(Category[1].StackColor); 
					qcdH[i][j][k]->SetFillColor(Category[1].StackColor);
					hs[i][j]->Add(qcdH[i][j][k]);	
				}//QCD End

				for(int k=0; k<TTMC_TotalNum; k++ ){ //For ttBar
					ttH[i][j][k] = (TH1F*)ttf[k]->Get(TH1Info[i].name.c_str()); 			
					string spath1 = SavePngPathbq+"/"+TTMC[k].name+"_"+TH1Info[i].name+".png"; 
					string spath2 = SavePngPathbq+"/"+TTMC[k].name+"_scaled_"+TH1Info[i].name+".png"; 
					ttH[i][j][k]->UseCurrentStyle();
					ttH[i][j][k]->Rebin(OtherInfo[i].rebin); 
					ttH[i][j][k]->SetXTitle(xtitle);
					ttH[i][j][k]->SetYTitle(ytitle);
					if ( j==0 && outputUnScalePlot ){
				 		plot( c1, ttH[i][j][k], 2, spath1 ); 
					}
					ttH[i][j][k]->Scale(1000*lumi*TTMC[k].xsec/TTMC[k].totalEvt);
					if ( j==0 && outputScaledPlot ){
				 		plot( c1, ttH[i][j][k], 4, spath2 ); 
					} 
					ttH[i][j][k]->SetLineWidth(1); 
					ttH[i][j][k]->SetLineColor(Category[2].StackColor); 
					ttH[i][j][k]->SetFillColor(Category[2].StackColor);
					hs[i][j]->Add(ttH[i][j][k]);	
				}//ttBar End

				for(int k=0; k<BosMC_TotalNum; k++ ){ //For Boson z/a ZZ WZ WJet WW
					bosH[i][j][k] = (TH1F*)bosf[k]->Get(TH1Info[i].name.c_str()); 			
					string spath1 = SavePngPathbq+"/"+BosMC[k].name+"_"+TH1Info[i].name+".png"; 
					string spath2 = SavePngPathbq+"/"+BosMC[k].name+"_scaled_"+TH1Info[i].name+".png"; 
					bosH[i][j][k]->UseCurrentStyle();
					bosH[i][j][k]->Rebin(OtherInfo[i].rebin); 
					bosH[i][j][k]->SetXTitle(xtitle);
					bosH[i][j][k]->SetYTitle(ytitle);
					if ( j==0 && outputUnScalePlot ){
				 		plot( c1, bosH[i][j][k], 2, spath1 ); 
					}
					bosH[i][j][k]->Scale(1000*lumi*BosMC[k].xsec/BosMC[k].totalEvt);
					if ( j==0 && outputScaledPlot ){
				 		plot( c1, bosH[i][j][k], 4, spath2 ); 
					} 
					bosH[i][j][k]->SetLineWidth(1); 
					bosH[i][j][k]->SetLineColor(Category[3].StackColor); 
					bosH[i][j][k]->SetFillColor(Category[3].StackColor);
					hs[i][j]->Add(bosH[i][j][k]);	
				}//Boson End


				////= For Legend ======================================================
				leg_[i][j]= new TLegend(OtherInfo[i].LegLBX, OtherInfo[i].LegLBY, OtherInfo[i].LegRTX, OtherInfo[i].LegRTY);
				leg_[i][j]->AddEntry(sigH[i][j],SigMC[j].LegTitle,"l");
				leg_[i][j]->AddEntry(bosH[i][j][1],Category[3].CategoryName.c_str(),"f");
				leg_[i][j]->AddEntry(ttH[i][j][1],Category[2].CategoryName.c_str(),"f");
				leg_[i][j]->AddEntry(qcdH[i][j][1],Category[1].CategoryName.c_str(),"f");
        			leg_[i][j]->SetFillStyle(0);
			        leg_[i][j]->SetBorderSize(0);
			        leg_[i][j]->SetTextSize(0.042);

				////= Draw ============================================================
				hs[i][j]->Draw();
				sigH[i][j]->Draw("same"); 
				leg_[i][j]->Draw();
				//gPad->SetLogy();

				////= Save ============================================================
				string spath = SavePngPath+"/"+SigMC[j].name+"_Stack_"+TH1Info[i].name+".png"; 
				c1->SaveAs(spath.c_str());
				cout<<"Save Stack Histogram \""<<TH1Info[i].name<<"\" for \""<<SigMC[j].LegTitle<<"\""<<endl;
			}	
		}
	}
}
