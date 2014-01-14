#!/bin/tcsh
cp abcd.cc sig/abcd.cc
cp abcd.cc tt/abcd.cc
cp abcd.cc qcd/abcd.cc

sed -i 's/sample_/sig/g' sig/abcd.cc
sed -i 's/sample_/bg/g' tt/abcd.cc
sed -i 's/sample_/bg/g' qcd/abcd.cc

###########################################################
sed -i 's/categoryNum/0/g' sig/abcd.cc
sed -i 's/SampleChoise/SigMC/g' sig/abcd.cc
#sed -i 's/\(.*no_signal\)/\/\/\1/g' sig/abcd.cc


sed -i 's/categoryNum/2/g' tt/abcd.cc
sed -i 's/SampleChoise/TTMC/g' tt/abcd.cc
#sed -i 's/\(.*no_bg\)/\/\/\1/g' tt/abcd.cc

sed -i 's/categoryNum/1/g' qcd/abcd.cc
sed -i 's/SampleChoise/QCDMC/g' qcd/abcd.cc
#sed -i 's/\(.*no_bg\)/\/\/\1/g' qcd/abcd.cc
