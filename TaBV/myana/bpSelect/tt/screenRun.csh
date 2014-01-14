#!/bin/tcsh
if ( !( -e log ) ) then
	mkdir log
endif
rm -f log/ana.log
cmsenv
root ana.cc+ -l -b -q | tee -a log/ana.log
