#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

double prob(const std::vector<int>& daten, double mu) {
    double likelihood = 1.0;
    for (int k : daten) {
        double term = pow(mu, k) * exp(-mu) / tgamma(k + 1); 
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

    double mu = 3.11538;
    double likelihood = prob(daten, mu);

    std::cout << "Likelihood for mu = " << mu << " is " << likelihood << std::endl;

    return 0;
}
