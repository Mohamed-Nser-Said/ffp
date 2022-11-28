#ifndef FILEIO_H
#define FILEIO_H

#include <vector>
#include "Protein.h"
#include <iostream>
#include <fstream>

using namespace std;

class FileIO{
public:
    static vector<ProteinsSequence> getProteinSequence(ifstream& fasta_file_stream);

    static ifstream openFastaFile(const string& file_path);

    static bool writeProteinsCSV(const string& filename, const vector<ProteinsSequence>& data);

    static bool writePeptidesCSV(const string& filename, const vector<ProteinsSequence>& data);

    static bool writeMappingsCSV(const string& filename, const vector<ProteinsSequence>& data);

};




#endif //FILEIO_H
