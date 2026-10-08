#!/usr/bin/bash
GIT="/mingw64/bin/git"
CMDOPTIONS="xdf"

while getopts "n" OPT
do
    case $OPT in
        n)
            CMDOPTIONS+=n
            ;;
        \?)
            CMDOPTIONS+=
            ;;
    esac
done
EXCLUDE_PATTERNS=(
    "*.log"
    "test/**/*.log"
)

PROGNAME=$(basename "$0")
EXCLUDE_PATTERNS+=("$PROGNAME")

EXCLUDES=()
for pattern in "${EXCLUDE_PATTERNS[@]}"; do
    EXCLUDES+=("-e" "$pattern")
done

set -x
"$GIT" clean -"$CMDOPTIONS" "${EXCLUDES[@]}"
