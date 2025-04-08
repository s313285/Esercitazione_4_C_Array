#include <iostream>
#include <fstream>
#include "Utils.hpp"

using namespace std;

int main()
{
	std::string inputFile = "data.txt";
    size_t n;
	double S;
    double *p_w = nullptr;
    double *p_r = nullptr;
	
    if(!ImportVectors(inputFile, n, S, p_w, p_r))
        return 1; // esecuzione del programma non terminata con successo
	
	
	double V = final_value(n,S,p_w,p_r);
	double r_tot = rate_of_return(S,V);
	
	
	std::string outputFile = "result.txt";
	
	if(!ExportResult(outputFile, n, S, p_w, p_r, V, r_tot))
        return 2; // esecuzione del programma non terminata con successo
	
    return 0;
}

