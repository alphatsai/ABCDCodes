#!/bin/tcsh
source sync.csh
set logPath="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/TaMC/result/log"
cmsenv
rm -f $logPath"/"abcd_sig.log $logPath"/"abcd_qcd.log $logPath"/"abcd_tt.log
root -l -b -q sig/abcd.cc+ | tee -a $logPath"/"abcd_sig.log
root -l -b -q qcd/abcd.cc+ | tee -a $logPath"/"abcd_qcd.log	
root -l -b -q tt/abcd.cc+  | tee -a $logPath"/"abcd_tt.log	
set sigs="450 500 550 600 650 700 750 800 1000 1200 1500"
set qcdRoots="abcd_QCD_Pt-300to470.root abcd_QCD_Pt-470to600.root abcd_QCD_Pt-600to800.root abcd_QCD_Pt-800to1000.root abcd_QCD_Pt-1000to1400.root abcd_QCD_Pt-1400to1800.root abcd_QCD_Pt-1800.root"
#set qcdRoots="abcd_QCD_Pt-170to300.root abcd_QCD_Pt-300to470.root abcd_QCD_Pt-470to600.root abcd_QCD_Pt-600to800.root abcd_QCD_Pt-800to1000.root abcd_QCD_Pt-1000to1400.root abcd_QCD_Pt-1400to1800.root abcd_QCD_Pt-1800.root"
set ttRoots="abcd_TTJets.root"
cd /afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src/TaMC/result/root/abcd
	foreach sig($sigs)
		set sigRoot=`echo abcd_BH_$sig.root`
		rm -f abcd_SumBg_BH_$sig.root 
		hadd abcd_SumBg_BH_$sig.root $sigRoot $qcdRoots $ttRoots
	end
	rm -f abcd_OnlySumBg.root
	hadd abcd_OnlySumBg.root $qcdRoots $ttRoots
cd -
