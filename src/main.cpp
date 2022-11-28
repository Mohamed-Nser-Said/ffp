#include<iostream>
#include<fstream>
#include <utility>
#include <vector>
#include <string>
#include <regex>
#include <cstdint>
#include "fileio.h"



int main(int argc, char** argv){
    if(argc> 1){
        for(int i=0; i<argc; i++)
            cout<<*argv++<<endl;
    }

    const string FASTA_FILE_PATH = "../data/input.fasta";
    const string PROTEIN_CSV_FILENAME = "../data/proteins.csv";
    const string PEPTIDE_CSV_FILENAME = "../data/peptides.csv";
    const string MAPPINGS_CSV_FILENAME = "../data/mappings.csv";

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