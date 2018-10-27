#!/bin/bash

TEST_DIR=tests
OUTPUT_DIR=output

if [ ! -d ${OUTPUT_DIR} ]; then
    mkdir -p ${OUTPUT_DIR};
fi


# 3x3 tests
THREE_DIR=${TEST_DIR}/3x3

for i in $(seq 0 5)
do
    echo "Solving 3x3 $i"
    FILE=${THREE_DIR}/test$i.txt
    OUTPUT=${OUTPUT_DIR}/3x3_$i.txt
    valgrind ./solver $FILE $OUTPUT
done

# 4x4 tests
FOUR_DIR=${TEST_DIR}/4x4

for i in $(seq 0 5)
do
    echo "Solving 4x4 $i"
    FILE=${FOUR_DIR}/test$i.txt
    OUTPUT=${OUTPUT_DIR}/4x4_$i.txt
    valgrind ./solver $FILE $OUTPUT
done

# lunatic tests
LUNATIC_DIR=${TEST_DIR}/lunatic

for i in $(seq 0 5)
do
    echo "Solving lunatic $i"
    FILE=${LUNATIC_DIR}/test$i.txt
    OUTPUT=${OUTPUT_DIR}/lun_$i.txt
    valgrind ./solver $FILE $OUTPUT
done