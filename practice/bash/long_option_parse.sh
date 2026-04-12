#!/bin/bash

DEBUG=${DEBUG:-0}

function usage ()
{
	echo "Usage: $0 [option ...] [arg ...]"
	cat << "EOM"
Options:
	-h, --help: Show this help
	-n count, --lines=count: Print count lines of each of the specified files
EOM
	exit 1
}

function echo_non_option_args ()
{
	if [ $# -eq 0 ]; then
		echo "no non-optional-arguments specified"
		exit 1
	fi

    echo "==> non-optional-arguments <=="
	for ((i=1; i <= $#; i++)) {
		# Use ${!i} to indirectly reference positional params like $1, $2, $3, ...
		echo "\$$i: ${!i}"
	}
}

function debug_print ()
{
	if [ $DEBUG -eq 1 ]; then
		i=1
		for arg in "$@"; do
			echo "[DEBUG] \$$i: $arg"
			i=$((i+1)) 
		done
	fi
}

function debug_print2 ()
{
  [ $DEBUG -eq 1 ] && echo "[DEBUG] after shift \$@: $@"
}

for arg in "$@"; do
  case "$arg" in
   --help)
	     set -- "$@" -h
		 debug_print "$@"
  		 ;;
   --lines)
  		  set -- "$@" -n 
		  debug_print "$@"
  		  ;;
  --lines=*)
		  set -- "$@" -n ${arg#*=}
		  debug_print "$@"
		  ;;
        *)
	      set -- "$@" "$arg"
		  ;;
  esac
  shift
  debug_print2 "$@"
done

while getopts ":hn:" OPT; do  
	# Prefix the getopts option string with ':' to suppress its default error messages.
	case $OPT in
	  h)
		 usage
		 ;;
	  n)
		 echo "-n option is used (OPTIND: $OPTIND)"
		 item=$OPTARG
		 ;;
	  # invalid option
	  \?)
		 echo "$0: unrecognized option -- -$OPTARG"
		 usage
		 ;;
	  # missing arguments
	  :)
		echo "$0: option requires argument -- -$OPTARG"
		usage
	esac
done

# Remove the option arguments from the positional parameters
shift $((OPTIND-1))

echo "Optional argument: $item"
echo_non_option_args "$@" 
