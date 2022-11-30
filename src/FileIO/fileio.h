#pragma FILEIO_H

#include <vector>
#include <iostream>
#include <fstream>
#include <Protein.h>

using namespace std;

class FileIO{
/**
 * @brief FileIO handles the input and output files format including CSV FASTA files.
 *
 */
public:
    static vector<ProteinsSequence> getProteinSequence(ifstream& fasta_file_stream);

    static ifstream openFastaFile(const string& file_path);

    static bool writeProteinsCSV(const string& filename, const vector<ProteinsSequence>& data);

    static bool writePeptidesCSV(const string& filename, const vector<ProteinsSequence>& data);

    static bool writeMappingsCSV(const string& filename, const vector<ProteinsSequence>& data);

};



