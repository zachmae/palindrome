#!/usr/bin/env bash
##
## EPITECH PROJECT, 2021
## Untitled (Workspace)
## File description:
## test
##

cyanclair='\e[1;36m'
vertclair='\e[1;32m'
vertfonce='\e[0;32m'
rougeclair='\e[1;31m'
rougefonce='\e[0;31m'
violetclair='\e[1;35m'
rose='\e[1;31m'
bleufonce='\e[0;34m'
bleuclair='\e[1;34m'
grisclair='\e[0;37m'
jaune='\e[1;33m'
blanc='\e[1;37m'

testoutput()
{
    ./palindrome $1 &> data
    if [[ $? == $2 ]]
    then
        echo -e "${vertfonce} \t\tTest output $3 \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "${rougefonce} \t\tTest output $3 (expected $2) \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data
}

testdisplay()
{
    ./palindrome $1 &> data
    diff -q data $2 &>/dev/null
    if [[ $? == $3 ]]
    then
        echo -e "\E[0;32m \t\tTest display $4 \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m \t\tTest display $4 \e[0m \e[41mNOT PASSED\E[0m"
        echo -e "${violetclair}\t\tDo you want to see diff? (y/n)${blanc}"
        read answer
        if [ $answer = "y" ]
        then
            diff data $2
        fi
    fi
    rm -f data
}

testrequirement()
{
    gcc -o requirement tests/test.c requirement.c
    ./requirement $1 &> data
    diff -q data $2 &>/dev/null
    if [[ $? == $3 ]]
    then
        echo -e "\E[0;32m \t\tTest Requirement $1 \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m \t\tTest Requirement $1 \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data
    rm -f requirement
}

echo -e "\E[0m \e[90m\e[1m TEST REQUIREMENT \e\e[0m"
testrequirement "squareroot" "tests/output/squareroot" "0"
testrequirement "factorial" "tests/output/factorial" "0"
echo -e "\E[0m \e[90m\e[1m PALINDROME, FUNCTIONAL TESTS \e\e[0m"
echo -e "\E[0m \e[90m\e[1m \tERROR HANDLING \e\e[0m"
testoutput "-h" "0" "usage"
echo -e "\E[0m \e[90m\e[1m \tSUBJECT TEST (output) \e\e[0m"
testoutput "-n 4782 -b 10" "0" "subject test 1 (basic palindrome n flag)"
testoutput "-n 64 -b 2" "0" "subject test 2 (base 2 test n flag)"
testoutput "-n 4782 toto" "84" "subject test 3 (error handling text)"
testoutput "-p 363 -b 10" "0" "subject test 4 (basic palindrome p flag)"
testoutput "-p 363 -b 10 -imax 2" "0" "subject test 5 (max occurence at 2)"
testoutput "-p 363 -b 10 -imin 6" "0" "subject test 6 (min occurence at 6)"
testoutput "-p 363 -b 10 -imin 7" "0" "subject test 7 (no solution)"
echo -e "\E[0m \e[90m\e[1m \tSUBJECT TEST (display) \e\e[0m"
testdisplay "-n 4782 -b 10" "tests/output/subject_1" "0" "subject test 1 (basic palindrome n flag)"
testdisplay "-n 64 -b 2" "tests/output/subject_2" "0" "subject test 2 (base 2 test n flag)"
testdisplay "-n 4782 toto" "tests/output/subject_3" "0" "subject test 3 (error handling text)"
testdisplay "-p 363 -b 10" "tests/output/subject_4" "0" "subject test 4 (basic palindrome p flag)"
testdisplay "-p 363 -b 10 -imax 2" "tests/output/subject_5" "0" "subject test 5 (max occurence at 2)"
testdisplay "-p 363 -b 10 -imin 6" "tests/output/subject_6" "0" "subject test 6 (min occurence at 6)"
testdisplay "-p 363 -b 10 -imin 7" "tests/output/subject_7" "0" "subject test 7 (no solution)"
echo -e "\E[0m \e[90m\e[1m \tERROR HANDLING \e\e[0m"
testoutput "" "84" "error handling no arguments"
testoutput "-n 555 -p 555" "84" "error handling n and p flag"
testoutput "-b 6" "84" "error handling no n or p flag"
testoutput "-n yikes -b 10" "84" "error handling flag has a non number argument"
testoutput "-n 555 -f 10" "84" "error handling flag does not exist"
testoutput "-n 555 -b 11" "84" "error handling base 11"
testoutput "-n 555 -b 1" "84" "error handling base 1"
testoutput "-n 555 -imin 3 -imax 2" "84" "error handling imax < imin"
testoutput "-n 555 -imin -1" "84" "error handling imin is negative"
testoutput "-p -55" "84" "error handling p flag negative"
testoutput "-n -55" "84" "error handling n flag negative"
echo -e "\E[0m \e[90m\e[1m \tFLAG N \e\e[0m"
testdisplay "-n 2344" "tests/output/flagnnobase" "0" "test flag n no base"
testdisplay "-n 347 -b 10" "tests/output/flagnb10" "0" "test flag n base 10"
testdisplay "-n 1983" "tests/output/flagnnobase2" "0" "test flag n no base 2nd test"
testdisplay "-n 1983 -b 2" "tests/output/flagnbase2" "0" "test flag n base 2"
testdisplay "-n 347 -b 2" "tests/output/flagnbase2_2" "0" "test flag n base 2 (2nd try)"
testdisplay "-n 16 -b 5" "tests/output/flagnbase5" "0" "test flag n base 5"
testdisplay "-n 347 -b 5" "tests/output/flagnbase5_2" "0" "test flag n base 5 (2nd try)"
echo -e "\E[0m \e[90m\e[1m \tFLAG P \e\e[0m"
testdisplay "-p 2344 -b 7" "tests/output/flagpb7" "0" "test flag p base 7"
testoutput "-p 1101" "84" "test not a palindrome base 10"
testoutput "-p 11 -b 2" "84" "test not a palindrome base 2"