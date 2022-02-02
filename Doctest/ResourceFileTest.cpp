//
// Created by serja on 04/01/2022.
//
#define  DOCTEST_CONFIG_DISABLE
#include "doctest.h"


#include "../ResourceFile.h"
#include "vector"

TEST_CASE("ResourceFile test Costructor"){
std::vector <ResourceFile *> r(2);
r[0] = new ResourceFile("Risorsa_01", 4);
CHECK("Risorsa_01" == r[0]->getFileName());
CHECK(4 ==  r[0]->getBit());
r[1] = new ResourceFile("Risorsa_02", 8);
CHECK("Risorsa_02" == r[1]->getFileName());
CHECK(8 == r[1]->getBit());
r[2] = new ResourceFile("Risorsa_03", 16);
CHECK("Risorsa_03" == r[1]->getFileName());
CHECK(16 == r[2]->getBit());
}

