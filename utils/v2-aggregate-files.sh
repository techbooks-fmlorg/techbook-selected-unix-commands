#!/bin/sh

dst=contents/20-selected-commands.re

cd $(dirname $0)/.. || exit 1

pwd

# obsolete (< v2.0.0-alpha.1)
# list=$(awk '{print "contents/" $2}' etc/list.v2)
# for f in $list; do .... ; done

# >= v2.0.0-alpha.2 (after $cmd.re relocation)
cat contents/v1/10-selected.re > $dst
for f in contents/[a-z]*.re
do
  (
    perl -nple 'if (/^=/) { $count = 2 }; print "\n\n" if $count-- > 0' $f
    printf "\n\n\n"
  )                      >> $dst    
done

exit 0

