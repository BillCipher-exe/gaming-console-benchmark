// benchmark_suite.h
#ifndef BENCHMARK_SUITE_H
#define BENCHMARK_SUITE_H

#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <nds.h>

// Macro Definitions
#define MATRIX_SIZE 384
#define NUM_PRIME_LIMIT 30000000
#define ARRAY_SIZE 1000000
#define PI_limit 10000000
#define DFT_limit 256

// Helper function prototypes
double get_time_in_seconds();
void print_result(const char* label, double duration);

// Benchmark function prototypes
void benchmark_fp32_matrix_mult();
void benchmark_bit_sieve();
void quicksort(int *arr, int left, int right);
void benchmark_sorting(int size);
void benchmark_monte_carlo_pi(int size);
int run_bench();
void benchmark_dft(int size); 

#endif // BENCHMARK_SUITE_H
