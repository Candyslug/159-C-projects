#!/bin/bash

echo ----------------------
echo -n Test 1 [n = 1,000]...
time ./$1 "1000"

echo
echo -n Test 2 [n = 50,000]...
time ./$1 "50000"

echo
echo -n Test 3 [n = 100,000]...
time ./$1 "100000"

echo
echo -n Test 4 [n = 200,000]...
time ./$1 "200000"
echo ----------------------
