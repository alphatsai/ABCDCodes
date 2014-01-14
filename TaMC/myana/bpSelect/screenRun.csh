#!/bin/tcsh
cmsenv
date >! screenRun.log
echo $HOST >> screenRun.log
cd sig
#	screen -dmS sig ./screenRun.csh
	screen -dmS sig1 ./screenRun1.csh
	screen -dmS sig2 ./screenRun2.csh
cd -
cd qcd
	screen -dmS qcd1 ./screenRun1.csh
	screen -dmS qcd2 ./screenRun2.csh
cd -

cd tt
	screen -dmS tt ./screenRun.csh
#	screen -dmS tt1 ./screenRun1.csh
#	screen -dmS tt2 ./screenRun2.csh
cd -

#cd bos
#	screen -dmS bos1 ./screenRun1.csh
#	screen -dmS bos2 ./screenRun2.csh
#cd -
