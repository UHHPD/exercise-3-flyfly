#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits>

double prob(const std::vector<int>& daten, double mu) {
    double likelihood = 1.0;
    for (int k : daten) {
        double term = pow(mu, k) * exp(-mu) / tgamma(k + 1); 
        likelihood *= term;
    }
    return likelihood;
}

double max_prob(const std::vector<int>& daten) {
    double likelihood = 1.0;
    for (int k : daten) {
        double term = pow(k, k) * exp(-k) / tgamma(k + 1); 
        likelihood *= term;
    }
    return likelihood;
}

int main() {
    std::vector<int> daten;
    std::ifstream infile("datensumme.txt");
    
    if (!infile) {
        std::cerr << "Error: Unable to open datensumme.txt" << std::endl;
        return 1;
    }
    
    int value;
    while (infile >> value) {
        daten.push_back(value);
    }
    infile.close();

    double mu_mean = 3.11538;
    double likelihood = prob(daten, mu_mean);

    double max_likelihood = max_prob(daten);

    double likelihood_ratio = likelihood / max_likelihood;

    double neg2lnLambda = -2.0 * log(likelihood_ratio);

    int ndof = daten.size() - 1; 
    double chi2_mean = ndof;
    double chi2_stddev = sqrt(2 * ndof);
    double z = (neg2lnLambda - chi2_mean) / chi2_stddev;
    
std::cout << "Likelihood Ratio (Λ): " << likelihood_ratio << std::endl;
    std::cout << "-2 ln Λ: " << neg2lnLambda << std::endl;
    std::cout << "Expected chi-squared mean: " << chi2_mean << std::endl;
    std::cout << "Expected chi-squared stddev: " << chi2_stddev << std::endl;
    std::cout << "Relative deviation (z): " << z << std::endl;

    return 0;
}
