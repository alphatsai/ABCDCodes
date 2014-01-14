#!/bin/tcsh
if ( $1 == "" ) then 
	echo "ERROR : You should input the variable list"
	echo "####################################################################"
	echo "##########          Product the new work space          ############"
	echo "##########      Hint: sourece buildAllTH2F.csh [1]      ############"
	echo "##########            [1] : variable_list               ############"
	echo "####################################################################"
	exit
else
        echo "####################################################################"
        echo "##########          Product the new work space          ############"
	echo "##########      Hint: sourece buildAllTH2F.csh [1]      ############"
	echo "##########            [1] : variable_list               ############"
        echo "####################################################################"
	echo "Are you sure to continue (Y/N)?"
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


	set dirtime = `pwd | awk -F "/" '{print $10}' | sed 's/\(..\)\(..\)/\1-\2/g'`
	set th2name_ = `cat $1`
	foreach th2name($th2name_)
		set enumName = `echo $th2name | sed 's/\-/_/g' | sed 's/\./_/g' | sed 's/$/_/g'`
		echo "$enumName, \t//$dirtime" >> log/enumTH2FNew
		echo '{ 0, "'$th2name'"',"\t"'"'title'"',"\t\t"'"'xtitle'"',"\t\t"'"'ytitle'"', '"'GeV/c'"', '"'GeV/c'"',xbin, xmin, xmax, ybin, ymin, ymax'}', //$dirtime >> log/th2infoNew
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
	end
endif
cat log/allNewTH2FVariable
