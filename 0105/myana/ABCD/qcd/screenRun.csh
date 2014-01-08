#!/bin/tcsh
if ( !( -e log ) ) then
	mkdir log
endif
rm -f log/ana.log
cmsenv
root abcd.cc+ -l -b -q >&! log/ana.log
