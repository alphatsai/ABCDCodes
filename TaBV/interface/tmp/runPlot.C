#include "ESAlign.C"

void runPlot()
{
 TChain * chn1 = new TChain("ESAlign","");


 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p1.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p10.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p100.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p11.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p12.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p13.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p14.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p15.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p16.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p17.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p18.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p19.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p2.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p20.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p21.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p22.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p23.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p24.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p25.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p26.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p27.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p28.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p29.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p3.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p30.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p31.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p32.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p33.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p34.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p35.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p36.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p37.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p38.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p39.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p4.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p40.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p41.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p42.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p43.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p44.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p45.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p46.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p47.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p48.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p49.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p5.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p50.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p51.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p52.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p53.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p54.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p55.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p56.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p57.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p58.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p59.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p6.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p60.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p61.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p62.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p63.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p64.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p65.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p66.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p67.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p68.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p69.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p7.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p70.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p71.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p72.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p73.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p74.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p75.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p76.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p77.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p78.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p79.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p8.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p80.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p81.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p82.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p83.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p84.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p85.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p86.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p87.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p88.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p89.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p9.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p90.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p91.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p92.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p93.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p94.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p95.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p96.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p97.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p98.root");
 chn1->Add("root://eoscms//eos/cms/store/group/alca_ecalcalib/ESalignment/Alpha/2011A_RAWRECO_Align2/AlignmentFile_iter2_p99.root");


 ESAlign a(chn1);
 a.iterN=1;
 //a.Loop();
 //a.Draw_4quad();
 //a.Draw_vsXY();
 a.Draw_4Corner();

}

