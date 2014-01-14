#!/bin/tcsh
if ( !( -e log ) ) then
	mkdir log
endif
rm -f log/ana1.log
root ana1.cc+ -l -b -q | tee -a log/ana1.log
