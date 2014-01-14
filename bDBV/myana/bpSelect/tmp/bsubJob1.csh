#!/bin/tcsh
source /afs/cern.ch/cms/caf/setup.csh
setenv VO_CMS_SW_DIR /afs/cern.ch/project/gd/apps/cms
source $VO_CMS_SW_DIR/cmsset_default.csh
/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src
set date="bDBV"
set type="sig"	
set name="NAME"
set CMSSW="CMSSW_5_3_2_patch5"
set MYDefaultPATH="/afs/cern.ch/work/j/jtsai"
set MYScriptPATH=`echo $MYDefaultPATH/myAna/bpTobH/mywk/$CMSSW/src/$date/myana/bpSelect/$type`
set MYVersionPATH=`echo $MYDefaultPATH/myAna/bpTobH/mywk/$CMSSW/src`
set MYOutputPATH=`echo $MYDefaultPATH/myAna/bpTobH/mywk/$CMSSW/src/$date/result`
set logFile=`echo $name'.log'`
set rootFile=`echo $name'.root'`

cd $MYVersionPATH
eval `scramv1 ru -csh`
cd -

cp $MYScriptPATH/$name.cc ./
#root $cfgFile >&! $logFile
root $cfgFile+ -l -b -q >&! $logFile

if ( $type == qcd || $type == tt || $type == bos ) then
	cp $rootFile $MYOutputPATH/root/mc/bg/
else
	cp $rootFile $MYOutputPATH/root/mc/sig/
endif

cp $logFile $MYOutputPATH/log

rm -f $rootFile
rm -f $logFile

#bsub -q 1nd -o /afs/cern.ch/user/j/jtsai/run_iter2_p1.log "/afs/cern.ch/user/j/jtsai/run_iter2_p1.sh"
