# Theoretica
<!-- Home -->
<!-- ======== -->

![GitHub last commit](https://img.shields.io/github/last-commit/chaotic-society/theoretica) ![GitHub Workflow Status](https://img.shields.io/github/actions/workflow/status/chaotic-society/theoretica/test-windows.yml) [![Codacy Badge](https://app.codacy.com/project/badge/Grade/0f4ae5dc6e1140ad855a3d6325d44b35)](https://app.codacy.com/gh/chaotic-society/theoretica/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=chaotic-society/theoretica&amp;utm_campaign=Badge_Grade)  [![Documentation](https://img.shields.io/badge/Doxygen-docs-blue?style=flat&cacheSeconds=https%3A%2F%2Fchaotic-society.github.io%2Ftheoretica%2F&link=https%3A%2F%2Fchaotic-society.github.io%2Ftheoretica%2F)](https://chaotic-society.github.io/theoretica)  [![License](https://img.shields.io/github/license/chaotic-society/theoretica)](https://choosealicense.com/licenses/lgpl-3.0/)

> A C++ math library for scientific computing with a simple and elegant interface.

Theoretica provides access to numerical methods with applications in science and engineering, is easy to setup and use, and is completely open source.  Applications include **scientific computing**, statistical analysis of data and numerical approximation. The library is tested using [Chebyshev](https://github.com/chaotic-society/chebyshev), a unit testing framework specifically developed for scientific and numerical software.

## A short example

The following code solves a differential equation, such as the Lorenz attractor, and writes the result to file:

```cpp
int main() {

    // Initial conditions
    vec3 x0 = {0.0, 0.1, 0.0};

    // Use Runge-Kutta between t=0 and t=50
    auto solution = ode::solve_rk4(f, x0, 0.0, 50.0);

    std::ofstream file ("solution.dat");
    file << solution;
}

```

## Features

Some features of the library include:

- Cross-platform with x86 and OpenMP enhancements
- Common real and complex functions
- Numerical Linear Algebra
- Complex numbers (algebraic & exponential form) and **quaternions**
- Numerical calculus, from integrals to ODEs
- Multivariate **Automatic Differentiation** with differential operators
- Univariate and multivariate optimization and root-finding
- Descriptive and inferential statistics and **Monte Carlo** methods
- Bezier curves and spline interpolation

Theoretica is constantly developed and improved with new ideas!

## Setup

Theoretica is a header-only library and has **no dependencies**, so you can include it in your projects straight-away! You can build all tests and example programs by running `make all` in the main folder, ensuring that it works on your machine. To use the library, you can include single headers or use `theoretica.h` which includes all modules, or alternatively include `theoretica_mini.h` which includes only common use modules.

### Quickstart

You can compile this simple code to check your setup:

```cpp
#include "theoretica.h"
using namespace th;

int main() {
    
    // Declare a 3D vector
    vec3 v = {1, 2, 3};

    // Create a 3x3 identity matrix
    mat3 A = mat3(1.0);

    // Transform v by A
    vec3 w = A * v;
}
```

## Examples

The `examples` folder contains simple programs that showcase usage of the library:

- [Statistics](https://github.com/chaotic-society/theoretica/blob/master/examples/statistics.cpp)
- [Chaotic Attractors](https://github.com/chaotic-society/theoretica/blob/master/examples/attractor.cpp)
- [Automatic differentiation](https://github.com/chaotic-society/theoretica/blob/master/examples/autodiff.cpp)
- [Sampling distributions](https://github.com/chaotic-society/theoretica/blob/master/examples/sampling.cpp)
- [Monte Carlo integration](https://github.com/chaotic-society/theoretica/blob/master/examples/montecarlo_integral.cpp)
- [Fitting data](https://github.com/chaotic-society/theoretica/blob/master/examples/logfit.cpp)
- [Automatic error propagation](https://github.com/chaotic-society/theoretica/blob/master/examples/error_propagation.cpp)
- [Histogram usage](https://github.com/chaotic-society/theoretica/blob/master/examples/histogram.cpp)


## Documentation

The documentation for the project is available at this [link](https://chaotic-society.github.io/theoretica). The documentation is written using Doxygen syntax alongside the source code and the website is automatically updated on each commit. The HTML documentation is also available for download in the `gh-pages` branch. The bibliography used during research for the library is listed in [BIBLIOGRAPHY.md](https://github.com/chaotic-society/theoretica/blob/master/BIBLIOGRAPHY.md). You may learn more about the design choices behind the library reading the [Software Specification](https://github.com/chaotic-society/Theoretica-Lab/blob/main/specification/Theoretica_Software_Structure_Specification.pdf).

## Build

The source distribution includes example programs, test units and benchmarks, which may be
compiled using different tools, but are not needed to use the library itself.

### Make
Using Make and GCC, you can run the following commands in the root directory of the project:

```
# Build all binaries
make all

# Build example programs
make examples

# Build and run test units
make test

# Build and run benchmarks
make benchmark
```

### CMake
Using CMake, run the following commands:

```
cd build
cmake ..

# Build all binaries
make all

# Run test units
make test
```

## Contributing

Contributions are welcome and appreciated! Have a look at the [Contributing Guide](https://github.com/chaotic-society/theoretica/blob/master/CONTRIBUTING.md) to learn more about how you can help. Contributions include writing code and documentation, testing and researching algorithms.

## Workflow

[![Test on Linux](https://github.com/chaotic-society/theoretica/actions/workflows/test-linux.yml/badge.svg)](https://github.com/chaotic-society/theoretica/actions/workflows/test-linux.yml) [![Test on Windows](https://github.com/chaotic-society/theoretica/actions/workflows/test-windows.yml/badge.svg)](https://github.com/chaotic-society/theoretica/actions/workflows/test-windows.yml) [![Test on MacOS](https://github.com/chaotic-society/theoretica/actions/workflows/test-macos.yml/badge.svg)](https://github.com/chaotic-society/theoretica/actions/workflows/test-macos.yml)

Theoretica uses automated workflows for recurring tasks. On each commit to `master`, tests are run on Linux, Windows and MacOS, benchmarks are launched and documentation is built and deployed to the online website. This ensures that the library works correctly and the documentation is always up-to-date.

## License

The project is currently under the [GNU Lesser General Public License 3.0](https://github.com/chaotic-society/theoretica/blob/master/LICENSE). You may learn more about it [here](https://choosealicense.com/licenses/lgpl-3.0/).
