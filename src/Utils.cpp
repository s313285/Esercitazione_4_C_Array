#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

bool ImportVectors(const string& inputFilePath,
                   size_t& n,
				   double& S,
                   double*& w,
                   double*& r)
{
    ifstream fin(inputFilePath);

    if(fin.fail())
        return false;

    char tmp;
    fin.get(tmp);	// prendo S
	fin.get(tmp);   // prendo ;
	
    fin >> S; // leggo il valore di S
	
	fin.get(tmp);	// prendo \n
	fin.get(tmp);   // prendo n
	fin.get(tmp);   // prendo ;
	
	fin >> n;
	
	fin.get(tmp);	// prendo \n
	string tmp1;
	getline(fin, tmp1); // riga di intestazione che non mi serve
	
    // alloco dinamicamente i vettori 
    w = new double[n];
    r = new double[n];
	
	for(unsigned int i = 0; i < n; i++){
        fin >> w[i];
		fin.get(tmp);   // prendo ;
		fin >> r[i];
		fin.get(tmp);	// prendo \n
	}
    return true;
}


double final_value(size_t& n,
                   double& S,
                   double*& w,
                   double*& r)
{	
	double V = 0.0;
	for (unsigned int i = 0; i < n; i++)
		V = V + (1+r[i])*w[i]*S;
	return V;
	
}


double rate_of_return (double& S,
					   double& V)
{
	double r_tot = V/S-1;
	return r_tot;
}


bool ExportResult(const string& outputFilePath,
                  size_t& n,
				  double& S,
				  double*& w,
                  double*& r,
				  double& V,
				  double& r_tot)
{
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr << "file open failed" << endl;
        return false;
    }
	
	file << setprecision(2) << fixed;
	
	file << "S = " << S << ", n = " << n << endl;
	
	string w_str = ArrayToString(n, w);
	string r_str = ArrayToString(n, r);
	
    file << "w = " << w_str << endl;
    file << "r = " << r_str << endl;
	
	// transformation of r_tot into string
	ostringstream r_tot_s;
	r_tot_s << r_tot;
	string r_tot_str = r_tot_s.str();
	
    file << "Rate of return of the portfolio: " << r_tot_str << endl;
	
	file << "V: " << V << endl;
	
    file.close();

    return true;
}


string ArrayToString(const size_t& n,
                     const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i] << " ";
    toString << "]";

    return toString.str();
}
