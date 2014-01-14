#!/bin/tcsh
#source sync.csh
source syncSap.csh
cmsenv
date >! screenRun.log
echo $HOST >> screenRun.log
#cd data
#	screen -dmS data ./screenRun.csh
#cd -

cd sig
	screen -dmS bDMC_sig ./screenRun.csh
cd -

cd qcd
#	screen -dmS qcd ./screenRun.csh
	screen -dmS bDMC_qcd1 ./screenRun1.csh
	screen -dmS bDMC_qcd2 ./screenRun2.csh
cd -

cd tt
	screen -dmS bDMC_tt ./screenRun.csh
cd -

#cd bos
#	screen -dmS bos1 ./screenRun1.csh
#	screen -dmS bos2 ./screenRun2.csh
#cd -

screen -ls
