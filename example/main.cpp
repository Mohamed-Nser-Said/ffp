#include<iostream>
#include<fstream>
#include <utility>
#include <vector>
#include <string>
#include <cstdint>
#include "utils.h"


int main(){

    const auto FASTA_FILE_PATH = std::string{"C:/Users/abuai/Desktop/root/devnv/projects/ffp/data/input.fasta"} ;
    const auto PROTEIN_CSV_FILENAME = std::string{ "C:/Users/abuai/Desktop/root/devnv/projects/ffp/data/proteins.csv"} ;
    const auto PEPTIDE_CSV_FILENAME = std::string{ "C:/Users/abuai/Desktop/root/devnv/projects/ffp/data/peptides.csv"};
    const auto MAPPINGS_CSV_FILENAME = std::string{ "C:/Users/abuai/Desktop/root/devnv/projects/ffp/data/mappings.csv"};

    // open the fasta file, if the file was not found, the program will terminate
    ifstream fasta_file = FileIO::openFastaFile(FASTA_FILE_PATH);

    // convert all the protein sequences in fasta file to 'ProteinsSequence' objects and put them in a vector container
    vector<ProteinsSequence> all_seq = FileIO::getProteinSequence(fasta_file);

    // close the original *.fasta file
    fasta_file.close();

    


    // creating protein csv file
    FileIO::writeProteinsCSV(PROTEIN_CSV_FILENAME, all_seq);

    // creating peptides csv file
    FileIO::writePeptidesCSV(PEPTIDE_CSV_FILENAME, all_seq);

    // creating mapping csv file
    FileIO::writeMappingsCSV(MAPPINGS_CSV_FILENAME, all_seq);




    return 0;
}