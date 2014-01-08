#!/bin/tcsh
set list_data=`cat data.txt`
set list_sig=`cat signal.txt`
set list_bg=`cat bg.txt`
rm -f listRoot/rootNum.txt ; touch listRoot/rootNum.txt
echo "Data..."
foreach dataEOS_($list_data)
	set data=`echo $dataEOS_ | awk -F "/" '{print $8}'` 
	set dataEOS=`echo $dataEOS_ | sed 's/\//\\\//g'`
	eos ls $dataEOS_ | sed "s/^/$dataEOS\//" >! listRoot/$data.txt 
	cat listRoot/$data.txt | wc -l | sed "s/\(.*\)/$data \1/g" >> listRoot/rootNum.txt 
end
echo "Signal..."
foreach signalEOS_($list_sig)
	set signal=`echo $signalEOS_ | awk -F "/" '{print $8}'`
	set signalEOS=`echo $signalEOS_ | sed 's/\//\\\//g'`
	eos ls $signalEOS_ | sed "s/^/$signalEOS\//" >! listRoot/$signal.txt 
	cat listRoot/$signal.txt | wc -l | sed "s/\(.*\)/$signal \1/g" >> listRoot/rootNum.txt 
end
echo "Backgorund..."
foreach bgEOS_($list_bg)
	set bg=`echo $bgEOS_ | awk -F "/" '{print $8}'`
	set bgEOS=`echo $bgEOS_ | sed 's/\//\\\//g'`
	eos ls $bgEOS_ | sed "s/^/$bgEOS\//" >! listRoot/$bg.txt 
	cat listRoot/$bg.txt | wc -l | sed "s/\(.*\)/$bg \1/g" >> listRoot/rootNum.txt 
end
