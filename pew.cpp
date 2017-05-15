#include <string>
#include <iostream>

using namespace std;

Gen::Gen():numgenes(0){}

void Gen::leergenes(string str){
  bool flag = false;
  string gen = "";
  for(int i = 0; i < str.length()-2; ++i){
    string codon = res.substr(i,i+3);
    if(codon == "ATG" or codon == "ATA"){
      flag = true;
    }
    if(flag){
      gen = gen + codon;
    }
    if((codon == "TAA" or codon == "AGA" or codon == "TAG"
	or codon == "AGG") and flag){
      flag = false;
      cout << gen << endl;
      genes.push_back(gen);
      gen = "";
    }
  }
}
