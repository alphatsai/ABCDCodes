#!/bin/tcsh
cmsenv
if ( $1 == "" ) then
	echo "Please input HT Value"
	echo " EX: HT900"
	exit
endif
#set name="HT800 HT850 HT900 HT950 HT1000"
set name=$1
foreach HT($name)
	echo "========================= Run $HT =============================="
	set value=`echo $HT | sed 's/HT//g'`
	sed -i "s/HTNAME/$HT/g" abcdHiggsDa.cc
	root abcdHiggsDa.cc+ -l -b -q
	sed -i "s/$HT/HTNAME/g" abcdHiggsDa.cc
	echo ""
	echo ""
end
