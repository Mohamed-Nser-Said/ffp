#pragma FILEIO_H

#include <vector>
#include <iostream>
#include <fstream>
#include <Protein.h>

using namespace std;

namespace FileIO {
/**
 * @brief FileIO handles the input and output files format including CSV FASTA files.
 *
 */


vector<ProteinsSequence> getProteinSequence(ifstream& fasta_file_stream);


ifstream openFastaFile(const string& file_path);

bool writeProteinsCSV(const string& filename, const vector<ProteinsSequence>& data);

bool writePeptidesCSV(const string& filename, const vector<ProteinsSequence>& data);

bool writeMappingsCSV(const string& filename, const vector<ProteinsSequence>& data);

}




