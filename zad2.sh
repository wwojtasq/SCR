#!/usr/bin/env bash

set -exo pipefail

tytul="temacik"
tresc="/home/wojtek/SCR/Lab1/tresc.txt"

odbiorca="/home/wojtek/SCR/Lab1/adresy.txt"
while read line
do
mail -s "$tytul" -a spec1.pdf -a spec2.pdf  $line < $tresc
done<"$odbiorca"
