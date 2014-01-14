#!/bin/tcsh
if ( $1 == "" ) then 
	echo "ERROR : You should input the variable list"
	echo "####################################################################"
	echo "##########          Product the new work space          ############"
	echo "##########      Hint: sourece buildAllTH1F.csh [1]      ############"
	echo "##########            [1] : variable_list               ############"
	echo "####################################################################"
	exit
else
        echo "####################################################################"
        echo "##########          Product the new work space          ############"
	echo "##########      Hint: sourece buildAllTH1F.csh [1]      ############"
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

	touch log/enumNew log/th1infoNew log/otherinfoNew
		
	
	set dirtime = `pwd | awk -F "/" '{print $10}' | sed 's/\(..\)\(..\)/\1-\2/g'`
	set th1name_ = `cat $1`
	foreach th1name($th1name_)
		set enumName = `echo $th1name | sed 's/\-/_/g' | sed 's/\./_/g' | sed 's/$/_/g'`
		echo "$enumName,  \t//$dirtime" >> log/enumNew
		echo '{' 0,"\t"'"'$th1name'"', '"'title'"',"\t\t"'"'xtitle'"',  '"'Yields'"', '"'GeV'"', bin, x,  y'}',    "\t"//$dirtime >> log/th1infoNew
		echo "{"0.65,0.65,0.85,0.85,'"'l'"',  1.3, '-1111', '-1111', '-1111', '-1111', 1"},\t\t"//$enumName "\t"//$dirtime >> log/otherinfoNew
		rm -f log/allNewTH1FVariable
		touch log/allNewTH1FVariable
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
	end
endif
#rm -f write_tmp
cat log/allNewTH1FVariable
