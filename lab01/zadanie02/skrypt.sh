#!/bin/bash

curl https://mhyla.com/repo/cars.txt | sort -r | nl | head -n 20 > lista.txt
