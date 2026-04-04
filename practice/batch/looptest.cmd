@echo off

rem /L スイッチで (初期値、増分、終了値) のループができる
for /L %%a in (1,1,10) do (
	echo %%a
)

exit /b