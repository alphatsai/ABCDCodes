#!/bin/tcsh
#cp abcd.cc data/abcd.cc
cp abcd.cc sig/abcd.cc
cp abcd.cc tt/abcd.cc
cp abcd.cc qcd/abcd1.cc
cp abcd.cc qcd/abcd2.cc

#sed -i 's/mc\/sample_/data/g' data/abcd.cc
sed -i 's/sample_/sig/g' sig/abcd.cc
sed -i 's/sample_/bg/g' tt/abcd.cc
sed -i 's/sample_/bg/g' qcd/abcd.cc
sed -i 's/sample_/bg/g' qcd/abcd1.cc
sed -i 's/sample_/bg/g' qcd/abcd2.cc

###########################################################
#sed -i 's/categoryNum/0/g' data/abcd.cc
#sed -i 's/SampleChoise/Data/g' data/abcd.cc
#sed -i 's/\(.*no_bg\)/\/\/\1/g' data/abcd.cc

sed -i 's/categoryNum/1/g' sig/abcd.cc
sed -i 's/SampleChoise/SigMC/g' sig/abcd.cc
#sed -i 's/\(.*no_signal\)/\/\/\1/g' sig/abcd.cc


sed -i 's/categoryNum/3/g' tt/abcd.cc
sed -i 's/SampleChoise/TTMC/g' tt/abcd.cc
#sed -i 's/\(.*no_bg\)/\/\/\1/g' tt/abcd.cc

sed -i 's/abcd()/abcd1()/g' qcd/abcd1.cc
sed -i 's/Category\[categoryNum\]\.SampleSize/(Category[categoryNum].SampleSize)\/2/g' qcd/abcd1.cc
sed -i 's/categoryNum/2/g' qcd/abcd1.cc
sed -i 's/SampleChoise/QCDMC/g' qcd/abcd1.cc
#sed -i 's/\(.*no_bg\)/\/\/\1/g' qcd/abcd1.cc

sed -i 's/abcd()/abcd2()/g' qcd/abcd2.cc
sed -i 's/int\ iSample=0/int iSample=(Category[categoryNum].SampleSize)\/2/g' qcd/abcd2.cc
sed -i 's/categoryNum/2/g' qcd/abcd2.cc
sed -i 's/SampleChoise/QCDMC/g' qcd/abcd2.cc
#sed -i 's/\(.*no_bg\)/\/\/\1/g' qcd/abcd2.cc
