void StackPlots( TFile* f1, vector<string> hist, vector<string> leg, vector<Color_t> color, string xtitle_, string ytitle_, string xunit, string savePath, bool ylog=0, int rebin=1){
	int Bins = 0;
	int x1 = 0;
	int x2 = 0;
	int size = hist.size();
	float binwidth = 0;
	char title[100], xtitle[100], ytitle[100];
	TH1F* h1[size];
	for(int i=0; i<size; i++){
		h1[i] = (TH1F*)f1->Get(hist[i].c_str());
		h1[i]->UseCurrentStyle();
		h1[i]->Rebin(rebin); 
		if( Bins != 0 ){ if( h1[i]->GetXaxis()->GetLast() != Bins ) { cout<<"Error: Exist different bin size( plot: "<<i<<")"<<endl; }}
		Bins = h1[i]->GetXaxis()->GetLast();
		binwidth = h1[i]->GetBinWidth(1);
		x1 = h1[i]->GetXaxis()->GetBinLowEdge(1);
		x2 = h1[i]->GetXaxis()->GetBinUpEdge(Bins);

		h1[i]->SetLineWidth(1);
		h1[i]->SetLineColor(color[i]);
		h1[i]->SetFillColor(color[i]);
	}

	sprintf(xtitle,"%s [%s]",xtitle_.c_str(),xunit.c_str());
	sprintf(ytitle,"%s / [%3.0f%s]",ytitle_.c_str(),binwidth,xunit.c_str());
	sprintf(title,";%s;%s",xtitle,ytitle);
	cout<<Bins<<" "<<x1<<" "<<x2<<endl;
	TH1F* hs_stack = new TH1F("hs_stack",title,Bins,x1,x2);
        THStack *hs = new THStack("hs","");

	TLegend* leg_ = new TLegend(0.65,0.65,0.85,0.85);
	TCanvas* c1 = new TCanvas("c1", "", 850, 700);
        c1->SetGridx();
        c1->SetGridy();
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	hs_stack->UseCurrentStyle();
	hs->SetHistogram(hs_stack);	
	for(int i=0; i<size; i++){
		hs->Add(h1[i]);
		leg_->AddEntry(h1[i],leg[i].c_str(),"f");
	}
        leg_->SetFillStyle(0);
        leg_->SetBorderSize(0);
        leg_->SetTextSize(0.042);
	if( ylog ) gPad->SetLogy();
	hs->SetMinimum(1);
	hs->SetMaximum(1e+13);
	hs->Draw();
	leg_->Draw();
	c1->SaveAs(savePath.c_str());
}

