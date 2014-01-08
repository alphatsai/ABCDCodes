#!/bin/tcsh
if ( $1 == "" ) then
	echo "Please give the folder name"
	exit
endif
set wklog="/afs/cern.ch/work/j/jtsai/myAna/bpTobH/mywk/CMSSW_5_3_11/src"
set exist=`grep $1 $wklog/log/wkdate | wc -l`
if ( $exist == 0 ) then
	echo "$1 is not exist, please check again"
	exit
endif
	set new=0
	echo "Star copy $1 files to here"
	if ( !( -e $1 ) ) then
		set new=1
		echo "Created $1"
		mkdir $1
	endif
	cd $wklog
		set cc_list=`find $1 -name '*.cc'`
		set h_list=`find $1 -name '*.h'`
		set C_list=`find $1 -name '*.C'`
		set csh_list=`find $1 -name '*.csh'`
	cd -
	echo "Start to copy *.cc ...."
	foreach ccli($cc_list)
		cd $wklog 
			set ccdir = `echo $ccli | sed "s/$1\/\(.*\)\(\/.*\.cc\)/\1/g"`
		cd -
		if ( !( -e $1/$ccdir ) )	then
			mkdir -p $1/$ccdir
		endif
		cp $wklog/$ccli $1/$ccdir                        #0510/draw/dRAll/tmp/dR05/checkeffQCD.cc 0521/draw/dRAll/tmp/dR05/
	end
	echo "Start to copy *.h ...."
	foreach hli($h_list) 
		cd $wklog 
			set hdir = `echo $hli | sed "s/$1\/\(.*\)\(\/.*\.h\)/\1/g"`
		cd -
		if ( !( -e $1/$hdir ) )	then
			mkdir -p $1/$hdir
		endif
		cp $wklog/$hli $1/$hdir
	end
	echo "Start to copy *.C ...."
	foreach Cli($C_list)
		cd $wklog 
			set Cdir = `echo $Cli | sed "s/$1\/\(.*\)\(\/.*\.C\)/\1/g"`
		cd -
		if ( !( -e $1/$Cdir ) )	then
			mkdir -p $1/$Cdir
		endif
		cp $wklog/$Cli $1/$Cdir
	end
	echo "Start to copy *.csh ...."
	foreach cshli($csh_list)
		cd $wklog 
			set cshdir = `echo $cshli | sed "s/$1\/\(.*\)\(\/.*\.csh\)/\1/g"`
		cd -
		if ( !( -e $1/$cshdir ) )	then
			mkdir -p $1/$cshdir
		endif
		cp $wklog/$cshli $1/$cshdir
	end
cp $wklog/log/wkdate log/
set exit_=0
#while ( $exit_ == 0 ) 
#	echo "Use git push(Y/N)"
#	set option=$<
#	if ( $option == "y" || $option == "Y" ) then
#		git commit -a -m "Update and sync. with $1"
#		git push
#		set exit_=1	
#	else if ( $option == "n" || $option == "N" ) then
#		set exit_=1	
#	endif	
#end

