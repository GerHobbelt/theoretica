
///
/// @file logfit.cpp Logarithmic fit from file data.
/// This example may be compiled using 'make logfit'
///

#include "theoretica.h"
using namespace th;

#include <iostream>
#include <fstream>
#include <sstream>


int main(int argc, char const *argv[]) {
    
    if(argc < 2) {
        std::cout << "Usage: logfit <filename>" << std::endl;
        return 1;
    }


    // Input file name
    std::string filename = std::string(argv[1]);
    std::ifstream file(filename);

    if(!file.is_open()) {
        std::cout << "Unable to open file" << std::endl;
        return 2;
    }


    // Read X and Y data from the file and compute the logarithm
    std::string line;
    vec_buff X;
    vec_buff Y;

    while(std::getline(file, line)) {
        
        real x, y;
        std::stringstream s(line);

        s >> x; s >> y;

        X.push_back(th::ln(x));
        Y.push_back(th::ln(y));
    }


    // Compute the intercept and slope of the interpolating line
    real intercept = regression::ols_linear_intercept(X, Y);
    real slope = regression::ols_linear_slope(X, Y);

    std::cout << "Model: y = A + Bx" << std::endl;
    std::cout << "A = " << intercept << std::endl;
    std::cout << "B = " << slope << std::endl;
    std::cout << "Err. = " << regression::ols_linear_error(X, Y, intercept, slope) << std::endl;

    return 0;
}
