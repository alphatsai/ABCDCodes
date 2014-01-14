#!/bin/tcsh
if ( !( -e log ) ) then
	mkdir log
endif
rm -f log/ana1.log
cmsenv
root -l -b -q ana1.cc+ | tee -a log/ana1.log
