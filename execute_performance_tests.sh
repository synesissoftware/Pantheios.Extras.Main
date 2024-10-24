#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=${SIS_CMAKE_BUILD_DIR:-$Dir/_build}
MakeCmd=${SIS_CMAKE_COMMAND:-make}

ExpandWidth=0
ListOnly=0
RunMake=1


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  case $1 in
    -l|--list-only)

      ListOnly=1
      ;;
    --expand-width)

      shift
      ExpandWidth=$1
      ;;
    -M|--no-make)

      RunMake=0
      ;;
    --help)

      cat << EOF
Pantheios.Extras.Main is a small, header-only C and C++ library that supplements Pantheios by providing automatic initialisation via main and handles elegantly initialisation and program failure
Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
Copyright (c) 2010-2019, Matthew Wilson and Synesis Software
Runs all (matching) performance-test programs

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:

    --expand-width <expand-width>
        subjects each performance test program's output to expand with the
        given <expand-width>

    -l
    --list-only
        lists the target programs but does not execute them

    -M
    --no-make
        does not execute CMake and make before running tests


    standard flags:

    --help
        displays this help and terminates

EOF

      exit 0
      ;;
    *)

      >&2 echo "$ScriptPath: unrecognised argument '$1'; use --help for usage"

      exit 1
      ;;
  esac

  shift
done


# ##########################################################
# main()

status=0

if [ $RunMake -ne 0 ]; then

  if [ $ListOnly -eq 0 ]; then
    echo "Executing make and then running all performance test programs"

    mkdir -p $CMakeDir || exit 1

    cd $CMakeDir

    $MakeCmd
    status=$?

    cd ->/dev/null
  fi
else

  if [ ! -d "$CMakeDir" ] || [ ! -f "$CMakeDir/CMakeCache.txt" ] || [ ! -d "$CMakeDir/CMakeFiles" ]; then

    >&2 echo "$ScriptPath: cannot run in '--no-make' mode without a previous successful build step"
  fi
fi

if [ $status -eq 0 ]; then

  if [ $ListOnly -ne 0 ]; then

    echo "Listing all performance test programs"
  else

    echo "Running all performance test programs"
  fi

  for f in $(find $CMakeDir -type f '(' -name 'test_performance*' -o -name 'test.performance.*' ')' -exec test -x {} \; -print)
  do

    if [ $ListOnly -ne 0 ]; then

      echo "would execute $f:"

      continue
    fi

    echo
    echo "executing $f:"

    if [ $ExpandWidth -ne 0 ]; then

      $f | expand -t $ExpandWidth
    else

      $f
    fi

    if [ $? -eq 0 ]; then

      :
    else

      status=$?

      break 1
    fi
  done
else

  status=$?
fi

exit $status


# ############################## end of file ############################# #

