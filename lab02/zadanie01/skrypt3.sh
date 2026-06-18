#!/bin/bash

if echo "$1" | grep -E '^[0-9]{2}-[0-9]{3}$'
then
    echo "Prawidlowy kod"
else
    echo "Nieprawidlowy kod"
fi