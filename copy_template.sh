#!/bin/bash

set -e

SRC=Ex00-Template
DEST=$1
echo D=$DEST

if [[ -z ${DEST} ]]; then
  echo "Usage: ${0} Ex01_MyProject"
  exit 1
fi

cp -rv ${SRC} ${DEST}
rm -rf ${DEST}/{IAR,MDK}/*-{Debug,Release}
/usr/bin/find ${DEST} -type f | while read FILE ; do
    target=$(echo ${FILE} |sed -e "s/${SRC}/${DEST}/")
    mv ${FILE} ${target}
    sed -e "s/${SRC}/${DEST}/g" -i ${target}
    unix2dos ${target}
done
