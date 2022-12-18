
#include <string>
#include "ffp.h"


int main(){

    const auto FASTA_FILE_PATH =
            std::string{"../../../data/input.fasta"} ;
    const auto PROTEIN_CSV_FILENAME =
            std::string{ "../../../data/proteins.csv"} ;
    const auto PEPTIDE_CSV_FILENAME =
            std::string{ "../../../data/peptides.csv"};
    const auto MAPPINGS_CSV_FILENAME =
            std::string{ "../../../data/mappings.csv"};

    // open the fasta file, if the file was not found, the program will terminate
    auto fasta_file = FFP::FileIO::openFastaFile(FASTA_FILE_PATH);

    // convert all the protein sequences in fasta file to 'ProteinsSequence' objects and put them in a vector container
    auto all_seq = FFP::getProteinSequence(fasta_file);

    // close the original *.fasta file
    fasta_file.close();




    // creating protein csv file
    FFP::FileIO::writeProteinsCSV(PROTEIN_CSV_FILENAME, all_seq);

    // creating peptides csv file
    FFP::FileIO::writePeptidesCSV(PEPTIDE_CSV_FILENAME, all_seq);

    // creating mapping csv file
    FFP::FileIO::writeMappingsCSV(MAPPINGS_CSV_FILENAME, all_seq);




    return 0;
}