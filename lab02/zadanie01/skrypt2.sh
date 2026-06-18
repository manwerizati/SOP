#!/bin/bash

if echo "$1" | grep -E '^[A-ZĄĆĘŁŃÓŚŹŻ][a-ząćęłńóśźż]+$'
then
    echo "Prawidlowe imie"
else
    echo "Nieprawidlowe imie"
fi