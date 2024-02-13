#!/bin/sh

for x in $(ls contents/ | egrep '^[a-z]' | cut -b 1 | sort | uniq)
do
    printf ">>> generating ^%s sections ...\n\n" ${x}     > /dev/null
    printf "= 頭文字が %s のコマンド\n\n" ${x}  > contents/50-cmd-${x}.re
    cat contents/${x}*.re                      >> contents/50-cmd-${x}.re
    printf "\n"                                           > /dev/null
done

exit 0
