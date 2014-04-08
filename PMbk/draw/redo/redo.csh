#!/bin/tcsh
cmsenv
#set name="HT800 HT850 HT900 HT950 HT1000"
set name="HT900"
source redo2DPlots.csh $name
source redoSelPlot.csh $name
source redoCoutPlot.csh $name
source redoTxt.csh $name
source redoHiggsM.csh $name
#source redoHiggsDa.csh $name
#source redoJetFlav.csh $name
#source redoHTCom.csh $name
#source redoHT.csh $name
#source redoHTEx.csh $name
