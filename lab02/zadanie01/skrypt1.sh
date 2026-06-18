#!/bin/bash

if echo "$1" | grep -E '^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$'
then
    echo "Poprawny adres e-mail"
else
    echo "Niepoprawny adres e-mail"
fi