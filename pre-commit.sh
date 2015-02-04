#!/bin/sh
#We want to run test on commited source, and not current source.
#So we stash them
git stash -q --keep-index

echo " > Runing Tests..."
./run_tests.sh
echo " > Finished !"
RESULT=$?

#Set previous stash source.
git stash pop -q

[ $RESULT -ne 0 ] && exit 1
exit 0
