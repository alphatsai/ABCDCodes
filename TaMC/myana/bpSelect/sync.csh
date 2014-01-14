#!/bin/tcsh
cp ana.cc sig/ana1.cc
cp ana.cc sig/ana2.cc
cp ana.cc tt/ana.cc
#cp ana.cc tt/ana1.cc
#cp ana.cc tt/ana2.cc
cp ana.cc bos/ana1.cc
cp ana.cc bos/ana2.cc
cp ana.cc qcd/ana1.cc
cp ana.cc qcd/ana2.cc
cp runAll.csh tt/
cp runAll.csh bos/
cp runAll.csh qcd/

sed -i 's/sample_/sig/g' sig/ana1.cc
sed -i 's/sample_/sig/g' sig/ana2.cc
sed -i 's/sample_/bg/g' tt/ana.cc
#sed -i 's/sample_/bg/g' tt/ana1.cc
#sed -i 's/sample_/bg/g' tt/ana2.cc
sed -i 's/sample_/bg/g' bos/ana1.cc
sed -i 's/sample_/bg/g' bos/ana2.cc
sed -i 's/sample_/bg/g' qcd/ana1.cc
sed -i 's/sample_/bg/g' qcd/ana2.cc

###########################################################
#sed -i 's/SampleChoise/SigMC/g' sig/ana.cc
#sed -i 's/categoryNum/0/g' sig/ana.cc
sed -i 's/categoryNum/0/g' sig/ana1.cc
sed -i 's/categoryNum/0/g' sig/ana2.cc
sed -i 's/SampleChoise/SigMC/g' sig/ana1.cc
sed -i 's/SampleChoise/SigMC/g' sig/ana2.cc
sed -i 's/\/\/\(.*TopPart\)/\1/g' sig/ana1.cc
sed -i 's/\/\/\(.*BottomPart\)/\1/g' sig/ana2.cc
sed -i 's/\(for.*FullPart\)/\/\/\1/g' sig/ana1.cc
sed -i 's/\(for.*FullPart\)/\/\/\1/g' sig/ana2.cc
sed -i 's/^\(.*ana().*\)/\/\/\1/g' sig/ana1.cc
sed -i 's/^\(.*ana().*\)/\/\/\1/g' sig/ana2.cc
sed -i 's/\/\/\(.*ana1().*\)/\1/g' sig/ana1.cc
sed -i 's/\/\/\(.*ana2().*\)/\1/g' sig/ana2.cc

sed -i 's/categoryNum/2/g' tt/ana.cc
sed -i 's/SampleChoise/TTMC/g' tt/ana.cc
#sed -i 's/categoryNum/2/g' tt/ana1.cc
#sed -i 's/categoryNum/2/g' tt/ana2.cc
#sed -i 's/SampleChoise/TTMC/g' tt/ana1.cc
#sed -i 's/SampleChoise/TTMC/g' tt/ana2.cc
#sed -i 's/\/\/\(.*TopPart\)/\1/g' tt/ana1.cc
#sed -i 's/\/\/\(.*BottomPart\)/\1/g' tt/ana2.cc
#sed -i 's/\(for.*FullPart\)/\/\/\1/g' tt/ana1.cc
#sed -i 's/\(for.*FullPart\)/\/\/\1/g' tt/ana2.cc
#sed -i 's/^\(.*ana().*\)/\/\/\1/g' tt/ana1.cc
#sed -i 's/^\(.*ana().*\)/\/\/\1/g' tt/ana2.cc
#sed -i 's/\/\/\(.*ana1().*\)/\1/g' tt/ana1.cc
#sed -i 's/\/\/\(.*ana2().*\)/\1/g' tt/ana2.cc
#sed -i 's/\/\/\(if.*Hadron.*\)/\1/g' tt/ana1.cc

sed -i 's/categoryNum/3/g' bos/ana1.cc
sed -i 's/categoryNum/3/g' bos/ana2.cc
sed -i 's/SampleChoise/BosMC/g' bos/ana1.cc
sed -i 's/SampleChoise/BosMC/g' bos/ana2.cc
sed -i 's/\/\/\(.*TopPart\)/\1/g' bos/ana1.cc
sed -i 's/\/\/\(.*BottomPart\)/\1/g' bos/ana2.cc
sed -i 's/\(for.*FullPart\)/\/\/\1/g' bos/ana1.cc
sed -i 's/\(for.*FullPart\)/\/\/\1/g' bos/ana2.cc
sed -i 's/^\(.*ana().*\)/\/\/\1/g' bos/ana1.cc
sed -i 's/^\(.*ana().*\)/\/\/\1/g' bos/ana2.cc
sed -i 's/\/\/\(.*ana1().*\)/\1/g' bos/ana1.cc
sed -i 's/\/\/\(.*ana2().*\)/\1/g' bos/ana2.cc

sed -i 's/categoryNum/1/g' qcd/ana1.cc
sed -i 's/categoryNum/1/g' qcd/ana2.cc
sed -i 's/SampleChoise/QCDMC/g' qcd/ana1.cc
sed -i 's/SampleChoise/QCDMC/g' qcd/ana2.cc
sed -i 's/\/\/\(.*TopPart\)/\1/g' qcd/ana1.cc
sed -i 's/\/\/\(.*BottomPart\)/\1/g' qcd/ana2.cc
sed -i 's/\(for.*FullPart\)/\/\/\1/g' qcd/ana1.cc
sed -i 's/\(for.*FullPart\)/\/\/\1/g' qcd/ana2.cc
sed -i 's/^\(.*ana().*\)/\/\/\1/g' qcd/ana1.cc
sed -i 's/^\(.*ana().*\)/\/\/\1/g' qcd/ana2.cc
sed -i 's/\/\/\(.*ana1().*\)/\1/g' qcd/ana1.cc
sed -i 's/\/\/\(.*ana2().*\)/\1/g' qcd/ana2.cc
