#!/bin/tcsh
echo "WRANGING: It will be produce 3 files for new variblesi, continue(Y/N): "
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
rm -f log/write_tmp
#rm -f allNewTH1FVariable
echo "******************************************" >> log/write_tmp
echo "Name: TH1F_name" >> log/write_tmp
echo "******************************************" >> log/write_tmp
vi log/write_tmp
echo "Are you sure to continue(Y/N/q)?"
set yn2=$<
while ( $yn2 != "q" && $yn2 != "Q")
	if ( $yn2 == "Y" || $yn2 == "y") then
		break
	else if ( $yn2 == "n" || $yn2 == "N" ) then
		vi write_tmp
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


set dirtime = `pwd | awk -F "/" '{print $10}' | sed 's/\(..\)\(..\)/\1-\2/g'`
set th1name = `cat log/write_tmp | grep 'Name:' | sed 's/Name:\(.*\)/\1/g'`

set enumName = `echo $th1name | sed 's/\-/_/g' | sed 's/\./_/g' | sed 's/$/_/g'`
echo "$enumName,  \t//$dirtime" >> log/enumNew
echo '{' 0,"\t"'"'$th1name'"', '"'title'"',"\t\t"'"'xtitle'"',  '"'Yields'"', '"'GeV'"', bin, x,  y'}',    "\t"//$dirtime >> log/th1infoNew
echo "{"0.65,0.65,0.85,0.85,'"'l'"',  1.3, '-1111', '-1111', '-1111', '-1111', 1"},\t\t"//$enumName "\t"//$dirtime >> log/otherinfoNew
rm -f log/allNewTH1FVariable
echo "enum :" >> log/allNewTH1FVariable
echo "*******************************************************************************************************">> log/allNewTH1FVariable
cat log/enumNew >> log/allNewTH1FVariable
echo "*******************************************************************************************************">> log/allNewTH1FVariable
echo "">> log/allNewTH1FVariable
echo "th1Info :">> log/allNewTH1FVariable
echo "*******************************************************************************************************">> log/allNewTH1FVariable
cat log/th1infoNew >> log/allNewTH1FVariable 
echo "*******************************************************************************************************">> log/allNewTH1FVariable
echo "">> log/allNewTH1FVariable
echo "OtherInfo : " >> log/allNewTH1FVariable
echo "*********************************************************************************************">> log/allNewTH1FVariable
cat log/otherinfoNew >> log/allNewTH1FVariable 
echo "*********************************************************************************************">> log/allNewTH1FVariable
rm -f log/write_tmp
cat log/allNewTH1FVariable
