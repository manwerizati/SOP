#!/bin/bash

echo "Podaj liczbę: "
read liczba

if [ $liczba -ge 1 -a $liczba -le 20 ]; then
	head -n $liczba lista.txt | tail -n 1
else
	echo "Niepoprawna liczba"
fi
