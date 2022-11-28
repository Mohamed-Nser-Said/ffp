
#ifndef PROTEIN_H
#define PROTEIN_H
#include <string>
#include <vector>

using namespace std;


struct Peptide{
    // Peptide struct meant to represent the peptide inside the protein,
    // where it holds the indexes relative to protein string,
    // it gives flexible way to access the information during processing

    const uint32_t PROTEIN_ID;
    const uint32_t START_IDX;
    const uint32_t END_IDX;
    const string PEPTIDE_SEQUENCE;
};


class ProteinsSequence{
public:
    const uint32_t PROTEIN_ID;
    const string  PROTEIN_IDENTIFIER;
    const string PROTEIN_SEQUENCE;
    vector<Peptide> peptides; //    peptides vector contains the peptides represented as "Peptide Object"


    ProteinsSequence(const uint32_t& PROTEIN_ID,string PROTEIN_IDENTIFIER, string PROTEIN_SEQUENCE):
            PROTEIN_ID(PROTEIN_ID),
            PROTEIN_IDENTIFIER(std::move((PROTEIN_IDENTIFIER))),
            PROTEIN_SEQUENCE(std::move(PROTEIN_SEQUENCE)){
        this->split_peptides();

    }

    void split_peptides();

};

#endif //PROTEIN_H
