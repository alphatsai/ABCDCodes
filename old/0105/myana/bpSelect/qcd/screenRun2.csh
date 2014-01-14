#!/bin/tcsh
if ( !( -e log ) ) then
	mkdir log
endif
rm -f log/ana2.log
cmsenv
root ana2.cc+ -l -b -q | tee -a log/ana2.log
