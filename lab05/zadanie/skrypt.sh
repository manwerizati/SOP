#!/bin/bash

CURRENCY=${1:-USD}
START=${2:-2024-01-01}
END=${3:-2024-12-31}

URL="https://api.nbp.pl/api/exchangerates/rates/A/$CURRENCY/$START/$END/?format=json"

curl -s "$URL" | jq -r '.rates[] | "\(.effectiveDate) \(.mid)"' > data.txt

gnuplot << EOF
set terminal png size 1000,600
set output "wykres_${CURRENCY}.png"
set xdata time
set timefmt "%Y-%m-%d"
set format x "%m-%Y"
set title "Kurs $CURRENCY/PLN ($START - $END)"
set grid
plot "data.txt" using 1:2 with lines title "$CURRENCY"
EOF