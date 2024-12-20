#!/bin/bash
total=$2
test_steps=0
for ((i=1; i <= $2; i++))
do
    percentage=$((i * 100/ total))
    bar=""
    for ((j=0; j<percentage/2; j++))
    do
        bar="${bar}#"
    done
    printf "\r[%-50s] %d%%" "$bar" "$percentage"
    arg=$(shuf -i 0-$1 -n $1 | tr '\n' ' ')
    run=$(./push_swap $arg > tmp)
    steps=$(cat tmp | wc -l)
    result=$(cat tmp | ./checker $arg)
    if [ $steps -gt $test_steps ]; then
        nb=$i
        test_arg=$arg
        test_steps=$steps
        test_result=$result
    fi
    if [ $result != "OK" ]; then
        echo ""
        echo "## test $i ##"
        echo "test: [$arg]"
        echo "number of instructions: $steps"
        echo "checker result: $result"
        break
    fi
done

echo ""

echo "## test $nb ##"
echo "test: [$test_arg]"
echo "number of instructions: $test_steps"
echo "checker result: $test_result"

rm -f tmp