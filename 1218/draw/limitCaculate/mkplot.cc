#include "/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/1218/interface/setTDRStyle.C"
void get_limits(TString filename, double* limits)
{
    TFile *fin = new TFile(filename);

    TTree *limit_tree = (TTree*)fin->Get("limit");
    double _limit;
    limit_tree->SetBranchAddress("limit",&_limit);

    for(int i=0;i<6;i++) {
        limit_tree->GetEntry(i);
        limits[i] = _limit;
    }

    delete fin;
}

//#define NPOINTS 5
#define NPOINTS 6 

void mkplot()
{
    setTDRStyle();
    double limits[NPOINTS][6];
    double min = +1E10, max = -1E10;

    for(int idx=0; idx<NPOINTS; idx++) {

        get_limits(TString::Format("/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/1218/resurlt/LimitLog/root/higgsCombineTest.Asymptotic.mH%d.root",idx*100+500),limits[idx]);

        if (limits[idx][0]<min) min = limits[idx][0];
        if (limits[idx][4]>max) max = limits[idx][4];
        if (limits[idx][5]<min) min = limits[idx][5];
        if (limits[idx][5]>max) max = limits[idx][5];

    }

    TCanvas *c1 = new TCanvas("c1","c1",850,700);
    //TCanvas *c1 = new TCanvas("c1","c1",700,500);
   // TH2F *frame = new TH2F("frame","frame",10,400,1100,10,0.5,max*2);
    TH2F *frame = new TH2F("frame","frame",10,400,1100,10,min/2,max*2);
	cout<<min/2<<endl;

    frame->UseCurrentStyle();		
    frame->SetStats(kFALSE);
    frame->SetTitle("");
    frame->SetYTitle("#sigma_{expected} / #sigma_{theory}");
    frame->SetXTitle("b' Mass Point");
    frame->Draw();

    c1->SetLogy();
    c1->SetGridx();
    c1->SetGridy();

    TPolyLine *pl_2s = new TPolyLine(NPOINTS*2);
    TPolyLine *pl_1s = new TPolyLine(NPOINTS*2);

    TGraph *pl_med = new TGraph(NPOINTS);
    TGraph *pl_obs = new TGraph(NPOINTS);

    for(int idx=0; idx<NPOINTS; idx++) {
        pl_2s->SetNextPoint(500+idx*100,limits[idx][0]);
        pl_1s->SetNextPoint(500+idx*100,limits[idx][1]);

        pl_med->SetPoint(idx,500+idx*100,limits[idx][2]);
        pl_obs->SetPoint(idx,500+idx*100,limits[idx][5]);

    }
    for(int idx=NPOINTS-1; idx>=0; idx--) {
        pl_1s->SetNextPoint(500+idx*100,limits[idx][3]);
        pl_2s->SetNextPoint(500+idx*100,limits[idx][4]);
    }

    pl_2s->SetFillColor(kYellow);
    pl_2s->Draw("f");
    pl_1s->SetFillColor(kGreen);
    pl_1s->Draw("f");
    pl_med->SetLineStyle(7);
    pl_med->SetLineWidth(2);
    pl_med->Draw("l");

    TLine *l1 = new TLine(400,1.,1100,1.);	
	l1->SetLineColor(2);	
    l1->Draw();

	c1->SaveAs("/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/1218/resurlt/png/limit/limit.png");	
    //pl_obs->SetLineWidth(2);
    //pl_obs->Draw("l");
}
