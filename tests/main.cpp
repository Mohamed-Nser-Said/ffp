#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <utility>
#include <vector>
#include <string>
#include <regex>

#include "fileio.h"
#include "Protein.h"


TEST_CASE( "ProteinsSequences are computed", "[ProteinsSequence]" ) {

    const string sequence1 = "MTEITAAMVKELRESTGAGMMDCKNALSETNGDFDKAVQLLREKGLGKAAKKADRLAAEG";
    const string sequence2 = "SATVSEINSETDFVAKNDQFIALTKDTTAHIQSNSLQSVEELHSSTINGVKFEEYLKSQI";

    ProteinsSequence protein_seq_1(1, "PROT1", sequence1);
    ProteinsSequence protein_seq_2(2, "PROT2", sequence2);

    REQUIRE( protein_seq_1.PROTEIN_ID == 1 );
    REQUIRE( protein_seq_1.PROTEIN_IDENTIFIER == "PROT1" );
    REQUIRE( protein_seq_1.peptides[0].PROTEIN_ID == 2 );

//     test peptide sequences in protein 1
    REQUIRE( protein_seq_1.peptides[0].PEPTIDE_SEQUENCE == "MTEITAAMVK");
    REQUIRE( protein_seq_1.peptides[1].PEPTIDE_SEQUENCE == "ESTGAGMMDCK");
    REQUIRE( protein_seq_1.peptides[2].PEPTIDE_SEQUENCE == "NALSETNGDFDK");




    REQUIRE( protein_seq_2.PROTEIN_ID == 2 );
    REQUIRE( protein_seq_2.PROTEIN_IDENTIFIER == "PROT2" );
    REQUIRE( protein_seq_2.peptides[0].PROTEIN_ID == 2 );


    //     test peptide sequences in protein 2
    REQUIRE( protein_seq_2.peptides[0].PEPTIDE_SEQUENCE == "SATVSEINSETDFVAK");
    REQUIRE( protein_seq_2.peptides[1].PEPTIDE_SEQUENCE == "NDQFIALTK");



}


