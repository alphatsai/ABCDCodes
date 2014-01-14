#!/bin/tcsh
if ( !( -e log ) ) then
	mkdir log
endif
rm -f log/ana1.log
cmsenv
root abcd1.cc+ -l -b -q >&! log/ana1.log
