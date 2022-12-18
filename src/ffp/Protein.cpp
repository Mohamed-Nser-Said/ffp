#include "ffp.h"

#include<fstream>
#include <utility>
#include <vector>
#include <string>
#include <regex>


using namespace std;


std::vector<FFP::Types::Protein> FFP::getProteinSequence(std::ifstream& fasta_file_stream) {

    std::vector<Types::Protein> vectorSeq;
    std::string line, protein_identifier, seq_string_buffer;


    while (getline(fasta_file_stream, line)) {

        if (line[0] == ';') continue;

        if (line[0] == '>') {
            std::replace(line.begin(), line.end(), ',', '-');

            if (!seq_string_buffer.empty()) {
                vectorSeq.emplace_back( protein_identifier, seq_string_buffer);
                seq_string_buffer.clear();
            }
            protein_identifier = line.substr(1);

        } else seq_string_buffer += line;

    }
    vectorSeq.emplace_back(protein_identifier, seq_string_buffer);
    return vectorSeq;

}


FFP::Types::Protein::Protein(std::string PROTEIN_IDENTIFIER, std::string PROTEIN_SEQUENCE):
    PROTEIN_IDENTIFIER(std::move(PROTEIN_IDENTIFIER)), PROTEIN_SEQUENCE(std::move(PROTEIN_SEQUENCE)),
    PROTEIN_ID(++Types::PROTEIN_ID)
    {

    this->splitPeptides();

    peptides_count = this->peptides.size();
}



void FFP::Types::Protein::splitPeptides(){

    std::string pattern("([^RK]{7,29}?[KR])"), prefix;
    std::regex r(pattern, regex::ECMAScript);
    sregex_iterator it(this->PROTEIN_SEQUENCE.begin(), this->PROTEIN_SEQUENCE.end(), r), end_it;
    uint32_t start_index=0, end_index=0;

    while(it!= end_it){
        prefix= it->prefix().str();
        if(prefix.empty()||prefix[prefix.size()-1]=='R'||prefix[prefix.size()-1]=='K'){
            end_index=it->position()+it->str().size()-1;
            start_index = it->position();

            this->peptides.emplace_back(Types::PROTEIN_ID, ++Types::PEPTIDE_ID,
                                        this->PROTEIN_SEQUENCE.substr(start_index, end_index-start_index),
                                        start_index, end_index);

        }

        ++it;
    }


}







