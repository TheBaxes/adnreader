#include <string>
#include <vector>
#include <iostream>
#include "gen.h"
#include <algorithm>


using namespace std;

Gen::Gen():numgenes(0){}

void Gen::leergenes(string str){
  bool flag = false;
  string gen = "";
  for(int i = 0; i < str.length()-3; ++i){
    string codon = str.substr(i,3);
    if(codon == "ATG" or codon == "ATA" or codon == "atg" or codon == "ata"){
      gen += codon;
      flag = true;
    }
    if(flag){
      gen = gen + codon;
    }
    if(flag and (codon == "TAA" or codon == "AGA" or codon == "TAG"
	or codon == "AGG" or codon == "taa" or codon == "aga" or codon == "tag" or codon == "agg")){
      flag = false;
      gen += codon;
      std::vector<string>::iterator it;
      
      it = find (genes.begin(), genes.end(), gen);
      if (gen.size() > 200 && it == genes.end()) {
	cout << gen << endl;
	genes.push_back(gen);
      }
      gen = "";
    }
  }
}
