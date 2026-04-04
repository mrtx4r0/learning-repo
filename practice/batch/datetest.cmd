@echo off

echo %date%
set today=%date%

set yyyy=%today:~0,4%
set mm=%today:~5,2%
set dd=%today:~8,2%

echo 今日は%yyyy%年%mm%月%dd%日

set CurrentTime=%TIME%
echo 現在時刻は%CurrentTime:~0,8%

exit /b 0