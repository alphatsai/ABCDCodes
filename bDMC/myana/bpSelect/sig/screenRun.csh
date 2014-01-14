#!/bin/tcsh
if ( !( -e log ) ) then
	mkdir log
endif
rm -f log/ana.log
root ana.cc+ -l -b -q >&! log/ana.log
