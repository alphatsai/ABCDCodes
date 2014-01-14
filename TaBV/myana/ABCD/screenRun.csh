#!/bin/tcsh
#source sync.csh
source syncSap.csh
cmsenv
date >! screenRun.log
echo $HOST >> screenRun.log
cd data
	screen -dmS TaBV_data1 ./screenRun1.csh
	screen -dmS TaBV_data2 ./screenRun2.csh
cd -

#cd sig
#	screen -dmS sig ./screenRun.csh
#cd -

cd qcd
#	screen -dmS qcd ./screenRun.csh
	screen -dmS TaBV_qcd1 ./screenRun1.csh
	screen -dmS TaBV_qcd2 ./screenRun2.csh
cd -

cd tt
	screen -dmS TaBV_tt ./screenRun.csh
cd -

#cd bos
#	screen -dmS bos1 ./screenRun1.csh
#	screen -dmS bos2 ./screenRun2.csh
#cd -

screen -ls
