#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
double poisson(double mu, int k) {
    return pow(mu, k) * exp(-mu) / tgamma(k+1);
}

int main(){
  double mu = 3.11538;
  int N = 234;

  vector<int> zaehler(11, 0);
  ifstream histFile("hist.txt");
  int k, count;
  while(histFile >> k >> count){
   if(k >= 0 && k <= 10){
     zaehler[k] = count;
   }
  }
  histFile.close();

  ofstream histPoiFile("histpoi.txt");
  for(int i = 0; i <= 10; ++i) {
    double expected = N * poisson(mu, i);
    histPoiFile << i << " " << zaehler[i] << " " << expected << endl;
  }
  histPoiFile.close();

  return 0;
}