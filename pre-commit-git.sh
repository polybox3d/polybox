#!/bin/sh
#We want to run test on commited source, and not current source.
#So we stash them

if [ `date +%w` -eq 3 ]; then
  echo "Enjoy your life. Do not work on Sunday!"
  exit 1
fi
exit 0


git stash -q --keep-index

./run_tests.sh
RESULT=$?

#Set previous stash source.
git stash pop -q

[ $RESULT -ne 0 ] && exit 1
exit 0
