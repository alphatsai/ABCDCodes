#include <string>
#include <vector>

void plot(){
	vector<string> hName;
	hName.push_back("HiggsMass");
	hName.push_back("CA8Pt");
	hName.push_back("HT");
	
	vector<int> rebin_;
	rebin_.push_back(5);	
	rebin_.push_back(10);	
	rebin_.push_back(50);	
	
	vector<float> max_;
	max_.push_back(0.08);	
	max_.push_back(0.065);	
	max_.push_back(0.3);
	
	//TFile* f = new TFile("abcd_AllData.root");
	TFile* f = new TFile("abcd_OnlySumBg.root");
	const int size_ = hName.size();
	TH1F* h[size_][4]; 
	for( int i=0; i<size_; i++){
		TCanvas* c1 = new TCanvas("c1","", 850, 850);
		h[i][0] = (TH1F*)f->Get(("ABCD1."+hName[i]+".A").c_str());		
		h[i][1] = (TH1F*)f->Get(("ABCD1."+hName[i]+".B").c_str());		
		h[i][2] = (TH1F*)f->Get(("ABCD1."+hName[i]+".C").c_str());		
		h[i][3] = (TH1F*)f->Get(("ABCD1."+hName[i]+".D").c_str());		


		h[i][0]->Add(h[i][2]);
		h[i][1]->Add(h[i][3]);

		double ac_ = h[i][0]->Integral();
		double bd_ = h[i][1]->Integral();
		
		h[i][0]->Scale(1/ac_);
		h[i][1]->Scale(1/bd_);

		h[i][0]->SetLineWidth(2);
		h[i][1]->SetLineWidth(2);

		h[i][0]->SetLineColor(2);
		h[i][1]->SetLineColor(4);
	
		h[i][0]->Rebin(rebin_[i]);
		h[i][1]->Rebin(rebin_[i]);
			
		h[i][0]->GetXaxis()->SetTitle(hName[i].c_str());	
		h[i][0]->GetYaxis()->SetRangeUser(0, max_[i]);	
	
		h[i][0]->Draw("HIST");
		h[i][1]->Draw("HIST SAME");

	//	h[i][0]->GetXaxis()->SetTitle("Anti-Higgs");	
	//	h[i][1]->GetXaxis()->SetTitle("Higgs");	
	//	c1->Divide(1,2);
	//	c1->cd(1);
	//	h[i][0]->Draw("HIST");
	//	c1->cd(2);
	//	h[i][1]->Draw("HIST");
		c1->SaveAs((hName[i]+".png").c_str());
		delete c1;
	}
	

}
