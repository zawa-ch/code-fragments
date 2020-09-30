#! /bin/bash

readex()
{
    declare READEX_RESULT
    read -r READEX_RESULT
    if [ "${READEX_RESULT}" != "" ]; then
        eval "$1"'=${READEX_RESULT}'
    fi
}

readex HOGE
echo "$HOGE"
