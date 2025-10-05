#!/bin/bash

# E.g.: ./build.sh -d --sqlite

cc="g++"
options="-I. -m32 -fPIC -Wall -fvisibility=hidden -lpthread"

separator="-----------------"
list_item=" - "
wait_indicator="..."

while [[ $# -gt 0 ]]; do
    arg="$1"
    case $arg in
        -d | --debug)
            debug="-g -ggdb -O0" # debug build without optimization
            ;;
        -u | --unsafe)
            unsafe=true
            ;;
        *)
            unrecognized_arg=$arg
            break
            ;;
    esac
    shift
done

if [ -v unrecognized_arg ]; then
    echo "Unrecognized argument \"$unrecognized_arg\", aborting."
    exit 1
fi

echo $separator

echo -n "Debug:    "
if [ -v debug ]; then
    echo "ON"
else
    echo "OFF"
    debug=""
fi

echo -n "Unsafe:   "
if [ -v unsafe ]; then
    echo "ON"
    constants+=" -D ENABLE_UNSAFE=1"
else
    echo "OFF"
    constants+=" -D ENABLE_UNSAFE=0"
fi


echo $separator

mkdir -p ../bin
mkdir -p objects

echo "Compiling"

echo -n "$list_item"
echo -n "hooks.cpp"
echo $wait_indicator
$cc $debug $options $constants -c hooks.cpp -o objects/hooks.opp

echo -n "$list_item"
echo -n "libcodra.cpp"
echo $wait_indicator
$cc $debug $options $constants -c libcodra.cpp -o objects/libcod.opp

echo -n "$list_item"
echo -n "qvsnprintf.c"
echo $wait_indicator
$cc $debug $options $constants -c vendor/qvsnprintf.c -o objects/qvsnprintf.opp

echo -n "$list_item"
echo -n "gsc.cpp"
echo $wait_indicator
$cc $debug $options $constants -c gsc.cpp -o objects/gsc.opp

echo -n "$list_item"
echo -n "gsc_player.cpp"
echo $wait_indicator
$cc $debug $options $constants -c gsc_player.cpp -o objects/gsc_player.opp

echo -n "Linking libcodra.so"
echo $wait_indicator
objects="$(ls objects/*.opp)"
$cc -m32 -shared -L/lib32 -o ../../bin/libcodra.so -ldl $objects -lpthread

rm objects -r
