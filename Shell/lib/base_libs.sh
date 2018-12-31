#!/bin/bash

. $PWD/../lib/colormap.sh 2>&1

function success() {
	printf "${BGreen}$* Success!\n${Color_Off}"
	return 0
}

function fail() {
	printf "${BRed}$* Fail!\n${Color_Off}"
	return 1
}

function highlight_words() {
	printf "${URed} $*${Color_Off}"
	return 1
}

function log() {
	printf "${Color_Off}$*${Color_Off}"
	return 0
}

function die() {
	exit -1
}
