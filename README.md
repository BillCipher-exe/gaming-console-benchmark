# Console Performance Benchmarking

This repository contains code and results from my attempt to benchmark various gaming consoles to test their performance across different workloads. The benchmarks are simple and focus solely on the main CPU core of each console, avoiding any SIMD or specialized processing extensions. This approach gives a straightforward comparison of raw core performance across different gaming platforms.

## Overview

Gaming consoles are typically optimized for real-time, graphics-intensive workloads, but CPU performance varies widely depending on the hardware generation and architecture. This project aims to measure CPU capabilities in isolation, excluding GPU, SIMD extensions, and other accelerators. 

The benchmarks focus on the following types of workloads:

1. **Integer Calculations**: Measures basic integer operations, useful for testing control logic or physics calculations.
2. **Floating-Point Calculations (FP32 & FP64)**: Tests floating-point performance, simulating scenarios like physics calculations or procedural content generation.
3. **Quicksort Algorithm**: Evaluates performance using the quicksort algorithm, a common task for sorting integers, which simulates workloads in data organization and game state management.
4. **Prime Number Sieve**: Uses the Sieve of Eratosthenes to measure integer processing capabilities in handling high-throughput, iterative tasks.
5. **Matrix Multiplication**: Tests FP32 matrix multiplications, which represent parts of linear algebra calculations used in physics or graphics.
6. **Discrete Fourier Transformation (DFT)**: Benchmarks CPU performance in handling signal processing tasks by transforming time-domain data into the frequency domain, which is useful for applications like audio processing and procedural generation.

## Limitations

- **No SIMD Extensions**: The benchmarks intentionally avoid SIMD extensions (e.g., NEON, AVX) to focus on the performance of a single main core. This restriction simplifies the code but limits comparison to raw core efficiency.
- **Single Core Only**: Each test is performed using a single CPU core to avoid the influence of multi-core scaling differences.
- **Basic Benchmarks**: These benchmarks do not attempt to mimic game-like scenarios. They are designed as synthetic workloads to isolate CPU characteristics in isolation.

## Getting Started

The code is designed to be as cross-platform as possible. To run the benchmarks on a console, you will need:
- A way to compile and run C code on your target console.
- A command line interface (CLI) or terminal access on the device, where possible.

### Running the Benchmarks

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/console-performance-benchmark
   cd console-performance-benchmark
