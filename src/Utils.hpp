#pragma once
#include <iostream>

using namespace std;

// ImportVectors reads the input vectors, the total sum S and the n assets from a file 
// inputFilePath: path name of the input file
// w: fractions of S
// r: rate of return
// return the result of the reading, true is success, false is error
bool ImportVectors(const string& inputFilePath,
                   size_t& n,
				   double& S,
                   double*& w,
                   double*& r);


//Count the the final value of the portfolio
// n: number of assets
// S: total invested sum
double final_value(size_t& n,
                   double& S,
                   double*& w,
                   double*& r);

						
//Computes the total rate of return
// S: total invested sum	
// V: result of the final_value(...)
double rate_of_return (double& S,
					   double& V);


// ExportResult export the result obtained in file
// outputFilePath: path name of the output file
// r_tot: result of the rate_of_return (...)
// return the result of the export, true is success, false is error
bool ExportResult(const string& outputFilePath,
                  size_t& n,
				  double& S,
				  double*& w,
                  double*& r,
				  double& V,
				  double& r_tot);


// Export a vector in a string
// n: size of the vector
// v: vector
// return the resulting string
string ArrayToString(const size_t& n,
                     const double* const& v);
