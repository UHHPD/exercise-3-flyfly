#include<vector>
#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

double poisson(double mu, int k) {
    return pow(mu, k) * exp(-mu) / tgamma(k+1);
}
int main(){
  vector<int> zaehler(11, 0);

  ifstream datei("datensumme.txt");
  if(!datei) {
    cerr << "Fehler beim Öffnen der Datei" << endl;
    return 1;
  }

  int zahl;
  while(datei >> zahl){
      if(zahl >= 0 && zahl <= 10){
          zaehler[zahl]++;
      }
  }

  datei.close();

  for(unsigned int i = 0; i < zaehler.size(); ++i) {
      cout << i << ": " << zaehler[i] << endl;
  }

  ofstream hist("hist.txt");
  for (unsigned int i = 0; i < zaehler.size(); ++i) {
      hist << i << ": " << zaehler[i] << endl;
  }

  hist.close();

  double mu = 3.11538;
  int N = 234;
    
  ofstream histpoi("histpoi.txt");
  for(int i = 0; i <= 10; ++i) {
      double expected = N * poisson(mu, i);
      histpoi << i << " " << zaehler[i] << " " << expected << endl;
  }
  histpoi.close();
  return 0;
}