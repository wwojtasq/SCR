#!/bin/bash


dzien=`date +%u`
weekend=6
if [ $dzien -lt $weekend ]
then
  echo Dzisiaj pracujemy
else
   echo Dzisiaj opoczywamy
fi      
