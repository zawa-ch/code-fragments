#! /bin/bash

declare -i argc=0
declare -a argv=()

analyzeopts()
{

    while (( $# > 0 ))
    do
        case $1 in
            --long-n)
                nflag='-longn'
                shift
                ;;
            --)
                shift
                break
                ;;
            -*)
                if [[ "$1" =~ 'n' ]]; then
                    nflag='-n'
                fi
                if [[ "$1" =~ 'l' ]]; then
                    lflag='-l'
                fi
                if [[ "$1" =~ 'p' ]]; then
                    pflag='-p'
                fi
                shift
                ;;
            *)
                ((++argc))
                argv=("${argv[@]}" "$1")
                shift
                ;;
        esac
    done
    while (( $# > 0 ))
    do
        ((++argc))
        argv=("${argv[@]}" "$1")
        shift
    done
}

analyzeopts "$@"

if [ "$nflag" != "" ]; then
    echo "used $nflag"
fi
if [ "$lflag" != "" ]; then
    echo "used $lflag"
fi
if [ "$pflag" != "" ]; then
    echo "used $pflag"
fi
echo "$argc item(s)"
for item in "${argv[@]}"
do
    echo "$item"
done
