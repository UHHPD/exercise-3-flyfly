#include <iostream>
#include <fstream>
#include <vector>


using namespace std;
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

  return 0;
}