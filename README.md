
# Assignment 7: Multi-Paradigm Problem Solving

This project calculates the mean, median, and mode of a
list of integers using three programming paradigms.

## Implementations

- C: Procedural programming
- OCaml: Functional programming
- Python: Object-oriented programming

## Dataset

4, 2, 7, 4, 9, 2, 4, 6, 2, 8

## Expected Results

Mean: 4.80
Median: 4.00
Mode: 2, 4

## Running the Programs

### C
cd c
gcc -std=c11 -Wall -Wextra -pedantic statistics.c -o statistics
./statistics

### OCaml
cd ocaml
ocaml statistics.ml

### Python
cd python
python3 statistics.py

## Screenshots

The screenshots folder contains source code and
sample output for all three languages.

## Paradigm Comparison

C uses procedures, arrays, manual memory management,
and explicit iteration.

OCaml uses immutable lists, higher-order functions,
and functional transformations.

Python uses a StatisticsCalculator class to encapsulate
data and calculation methods.
