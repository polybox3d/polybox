#!/bin/sh

echo " > Runing Tests..."
./run_tests.sh
echo " > Finished !"
RESULT=$?

[ $RESULT -ne 0 ] && exit 1
exit 0
