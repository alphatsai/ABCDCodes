#!/bin/tcsh
set bg_='QCD TT Bos'
cat 1_initial.C >! ../CountCutEff.cc
foreach bg($bg_)
	sed "s/BGS/$bg/g" 2_bgTitle.C >> ../CountCutEff.cc
	sed "s/BGS/$bg/g" 3_SampleSelect.C >> ../CountCutEff.cc
	cat 7_CountEff.C >> ../CountCutEff.cc
	sed "s/BGS/$bg/g" 4_bgSumNumEvt.C >> ../CountCutEff.cc
end
cat 5_SignalTitle.C >> ../CountCutEff.cc
sed "s/BGS/Sig/g" 3_SampleSelect.C | sed 's/Bg/Sig/g' >> ../CountCutEff.cc
cat 7_CountEff.C >> ../CountCutEff.cc
echo "\t}" >> ../CountCutEff.cc
echo "" >> ../CountCutEff.cc
cat 6_TotalBg.C >> ../CountCutEff.cc
