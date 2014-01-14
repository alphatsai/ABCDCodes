#!/bin/tcsh
echo "WRANGING: It will be produce 3 files for new TH2F varibles, continue(Y/N): "
set yn1=$<
while ( $yn1 != "N" && $yn1 != "n")
	if ( $yn1 == "Y" || $yn1 == "y") then
		break
	else
		echo "Are you sure to continue(Y/N)?"
		set yn1=$<
	endif
end
if ( $yn1 == "N" || $yn1 == "n") then
	exit
endif
rm -f log/write_tmp2
echo "******************************************" >> log/write_tmp2
echo "Name: TH2F_name" >> log/write_tmp2
echo "******************************************" >> log/write_tmp2
vi log/write_tmp2
echo "Are you sure to continue(Y/N/q)?"
set yn2=$<
while ( $yn2 != "q" && $yn2 != "Q")
	if ( $yn2 == "Y" || $yn2 == "y") then
		break
	else if ( $yn2 == "n" || $yn2 == "N" ) then
		vi log/write_tmp2
		echo "Are you sure to continue(Y/N/q)?"
		set yn2=$<
	else
		echo "Are you sure to continue(Y/N/q)?"
		set yn2=$<
	endif
end
if ( $yn2 == "q" || $yn2 == "Q") then
	exit
endif

set dirtime = `pwd | awk -F "/" '{print $9}'`

set th2name = `cat log/write_tmp2 | grep 'Name:' | sed 's/Name:\(.*\)/\1/g'`

set enumName = `echo $th2name | sed 's/\-/_/g' | sed 's/\./_/g' | sed 's/$/_/g'`
echo "$enumName,\t//$dirtime" >> log/enumTH2FNew
echo '{ "'$th2name'"',"\t\t"0, '"'title'"',"\t\t"'"'xtitle'"',"\t\t"'"'ytitle'"', '"'GeV/c'"', '"'GeV/c'"',xbin, xmin, xmax, ybin, ymin, ymax'}', //$dirtime >> log/th2infoNew
echo "{"0, xmax, 0, ymax "},\t"//$enumName "\t"//$dirtime >> log/other2infoNew
rm -f log/allNewTH2FVariable
echo "enum :" >> log/allNewTH2FVariable
echo "********************************************************************************************************************************">> log/allNewTH2FVariable
cat log/enumTH2FNew >> log/allNewTH2FVariable
echo "********************************************************************************************************************************">> log/allNewTH2FVariable
echo "">> log/allNewTH2FVariable
echo "th2Info :">> log/allNewTH2FVariable
echo "********************************************************************************************************************************">> log/allNewTH2FVariable
cat log/th2infoNew >> log/allNewTH2FVariable 
echo "********************************************************************************************************************************">> log/allNewTH2FVariable
echo "">> log/allNewTH2FVariable
echo "Other2Info : " >> log/allNewTH2FVariable
echo "*********************************************************************************************">> log/allNewTH2FVariable
cat log/other2infoNew >> log/allNewTH2FVariable 
echo "*********************************************************************************************">> log/allNewTH2FVariable

rm -f log/write_tmp2
cat log/allNewTH2FVariable
