#!/bin/csh -f

set targetDir                   = ./patchNetmarbleNew
set PatchInfoFilename   = ./PatchInfo.inf
set Updater2Filename    = ./Updater2.exe
set PatcherFilename     = ./Patcher.exe

@ totalNum                      = 256
@ PatchInfoEndNum               = $totalNum - 1
@ Updater2EndNum                = 6
@ PatcherEndNum                 = 6

@ patchNum = 0

rm -rf $targetDir
mkdir $targetDir

while ( $patchNum <= $totalNum )
        if ( $patchNum < 10 ) then
                        set dirName = v0000$patchNum
        else if ( $patchNum < 100 ) then
                        set dirName = v000$patchNum
        else if ( $patchNum < 1000 ) then
                        set dirName = v00$patchNum
        endif

        echo $dirName
        rm -rf $targetDir/$dirName
        mkdir $targetDir/$dirName

        if ( $patchNum <= $PatchInfoEndNum ) cp $PatchInfoFilename $targetDir/$dirName
        if ( $patchNum <= $Updater2EndNum ) cp $Updater2Filename $targetDir/$dirName
        if ( $patchNum <= $PatcherEndNum ) cp $PatcherFilename $targetDir/$dirName

        @ patchNum += 1
end
