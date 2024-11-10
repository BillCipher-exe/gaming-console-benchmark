#include "include/benchmark.h"
#include <psptypes.h>
#include <pspkernel.h>
#include <pspdebug.h>
#include <psputils.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define printf	pspDebugScreenPrintf

// Timer helper function
double get_time_in_seconds() {
    clock_t tick = sceKernelLibcClock();
    return (tick / 1000000.0);
}

// Print helper function
void print_result(const char* label, double duration) {
    printf("%s: %.6f seconds\n", label, duration);
}

// FP32 Benchmark - Matrix Multiplication
void benchmark_fp32_matrix_mult() {
    float **A = (float**)malloc(MATRIX_SIZE * sizeof(float*));
    float **B = (float**)malloc(MATRIX_SIZE * sizeof(float*));
    float **C = (float**)malloc(MATRIX_SIZE * sizeof(float*));

    // Initialize matrices
    for (int i = 0; i < MATRIX_SIZE; i++) {
        A[i] = (float*)malloc(MATRIX_SIZE * sizeof(float));
        B[i] = (float*)malloc(MATRIX_SIZE * sizeof(float));
        C[i] = (float*)malloc(MATRIX_SIZE * sizeof(float));
        for (int j = 0; j < MATRIX_SIZE; j++) {
            A[i][j] = (float)(i + j);
            B[i][j] = (float)(i - j);
            C[i][j] = 0.0f;
        }
    }

    double start_time = get_time_in_seconds();
    // Matrix multiplication C = A * B
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            for (int k = 0; k < MATRIX_SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    double end_time = get_time_in_seconds();

    print_result("FP32 Matrix Multiplication", end_time - start_time);

    // Free memory
    for (int i = 0; i < MATRIX_SIZE; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
}

// Int32 Benchmark - bit Sieve primes
#define SET_BIT(arr, n) (arr[(n) / 32] |= (1U << ((n) % 32)))
#define CLEAR_BIT(arr, n) (arr[(n) / 32] &= ~(1U << ((n) % 32)))
#define GET_BIT(arr, n) ((arr[(n) / 32] & (1U << ((n) % 32))) != 0)

void benchmark_bit_sieve() {
    int *sieve = (int*)malloc((NUM_PRIME_LIMIT / 32 + 1) * sizeof(int));
    for (int i = 0; i < (NUM_PRIME_LIMIT / 32 + 1); i++) {
        sieve[i] = ~0;  // Set all bits to 1
    }

    double start_time = get_time_in_seconds();
    for (int p = 2; p * p < NUM_PRIME_LIMIT; p++) {
        if (GET_BIT(sieve, p)) {
            for (int i = p * p; i < NUM_PRIME_LIMIT; i += p) {
                CLEAR_BIT(sieve, i);
            }
        }
    }
    double end_time = get_time_in_seconds();

    print_result("Bitwise Prime Sieve", end_time - start_time);
    free(sieve);
}

// Sorting Benchmark (Unchanged from previous example)
void quicksort(int *arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    int temp;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) quicksort(arr, left, j);
    if (i < right) quicksort(arr, i, right);
}

// Sorting Benchmark
void benchmark_sorting(int size) {
    int *arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Fill array with random integers
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;
    }

    double start_time = get_time_in_seconds();
    quicksort(arr, 0, size - 1);
    double end_time = get_time_in_seconds();

    print_result("quick Sort Benchmark", end_time - start_time);
    free(arr);
}

void benchmark_monte_carlo_pi(int num_points) {
    int points_inside_circle = 0;

    double start_time = get_time_in_seconds();
    for (int i = 0; i < num_points; i++) {
        double x = (double)rand() / RAND_MAX;  // Random x between 0 and 1
        double y = (double)rand() / RAND_MAX;  // Random y between 0 and 1

        // Check if the point (x, y) is inside the unit circle
        if (x * x + y * y <= 1.0) {
            points_inside_circle++;
        }
    }
    double end_time = get_time_in_seconds();

    // Pi is approximately 4 * (points inside circle / total points)
    double pi_estimate = 4.0 * (double)points_inside_circle / num_points;
    print_result("Monte Carlo PI: ", end_time - start_time);
}

void benchmark_dft(int size) {
    float *real = (float*)malloc(size * sizeof(float));
    float *imag = (float*)malloc(size * sizeof(float));
    float *output_real = (float*)malloc(size * sizeof(float));
    float *output_imag = (float*)malloc(size * sizeof(float));
    
    // Initialize the input arrays with random values
    for (int i = 0; i < size; i++) {
        real[i] = (float)(rand() % 1000) / 1000.0f;
        imag[i] = 0.0f;  // Imaginary part starts as zero
    }

    double start_time = get_time_in_seconds();
    
    // Perform DFT
    for (int k = 0; k < size; k++) {
        output_real[k] = 0.0f;
        output_imag[k] = 0.0f;
        for (int n = 0; n < size; n++) {
            float angle = 2.0f * M_PI * k * n / size;
            output_real[k] += real[n] * cos(angle) + imag[n] * sin(angle);
            output_imag[k] += imag[n] * cos(angle) - real[n] * sin(angle);
        }
    }

    double end_time = get_time_in_seconds();

    print_result("DFT Benchmark", end_time - start_time);

    free(real);
    free(imag);
    free(output_real);
    free(output_imag);
}

int run_bench() {

    // Run benchmarks
    benchmark_fp32_matrix_mult();
    benchmark_bit_sieve();
    benchmark_sorting(ARRAY_SIZE);
    benchmark_monte_carlo_pi(PI_limit);
    benchmark_dft(DFT_limit);

    return 0;
}