#!/bin/tcsh
set txtsavepath="/home/hep/alpha78718/mywk/ntupleBprimeKit_Ana/CMSSW_5_3_2_patch5/src/mass/1209/resurlt/txt"
rm -f $txtsavepath/SelectionEff.txt
root CountCutEff.cc+ -q  | tee -a $txtsavepath/SelectionEff.txt
root StackPlots.cc+ -b -q
root Sig2D.cc+ -b -q
cat $txtsavepath/SelectionEff.txt | grep -A1000 -B1 'SIGNAL' >! $txtsavepath/SelectionEff_TotalBg_Signal.txt
cat $txtsavepath/SelectionEff.txt | grep -B1000 'SIGNAL' | grep -A1000 -B1 'Bos Back' | grep -v 'SIGNAL' >! $txtsavepath/SelectionEff_Boson.txt
cat $txtsavepath/SelectionEff.txt | grep -B1000 'SIGNAL' | grep -B1000 'Bos Back' | grep -A1000 -B1 'TT Back' | grep -v 'Bos Back' >! $txtsavepath/SelectionEff_TTBar.txt
cat $txtsavepath/SelectionEff.txt | grep -B1000 'SIGNAL' | grep -B1000 'Bos Back' | grep -B1000 'TT Back' | grep -A1000 -B1 'QCD Back' | grep -v 'TT Back' >! $txtsavepath/SelectionEff_QCD.txt
