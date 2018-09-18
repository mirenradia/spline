#!/bin/bash

./interpol > plot.csv
gnuplot plot.txt
