#include "Protein.h"

#include<fstream>
#include <utility>
#include <vector>
#include <string>
#include <regex>


using namespace std;

// "split_peptides" method is used to parse the protein sequence and split it to peptides objects and
// then pushed to peptides vector, the method uses regex to split the peptides
//the regex uses ECMAScript option to enable lazy or non-greedy repetition

//- The protein sequence is cut after every “K” or “R”.
//- The digestion can miss one of those cutting points.
//- The minimum length of a peptide sequence (x >= 7).
//- The maximum length of a peptide sequence(y =< 30).

void ProteinsSequence::split_peptides(){

    string pattern("([^RK]{7,29}?[KR])"), prefix;
    regex r(pattern, regex::ECMAScript);
    uint32_t start_index=0, end_index=0;

    for(sregex_iterator it(this->PROTEIN_SEQUENCE.begin(), this->PROTEIN_SEQUENCE.end(), r), end_it;
        it!= end_it; ++it){
        prefix= it->prefix().str();
        if(prefix.empty()||prefix[prefix.size()-1]=='R'||prefix[prefix.size()-1]=='K'){
            end_index=it->position()+it->str().size()-1;
            start_index = it->position();
            Peptide p{this->PROTEIN_ID,start_index,end_index,it->str(), };
            peptides.push_back(p);

        }


    }


}


