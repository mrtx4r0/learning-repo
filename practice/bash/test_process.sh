#!/usr/bin/bash
if [[ "${BASH_SOURCE[0]}" != "$0" ]]; then
	printf 'now in same process.\n$0=%s, ${BASH_SOURCE[0]}=%s, $$=%d, SHELL=%s\n' \
	$0 ${BASH_SOURCE[0]} $$ $SHELL
else
	printf 'now in child process.\n$0=%s, ${BASH_SOURCE[0]}=%s,  PPID=%d, $$=%d,  SHELL=%s\n' \
	$0 ${BASH_SOURCE[0]} $PPID $$ $SHELL
fi
