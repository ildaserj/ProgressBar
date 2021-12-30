//
// Created by serja on 21/12/2021.
//


#include "gtest/gtest.h"
#include "../ResourceFile.h"

TEST(RisorseTest, Test_Costructor){
    ResourceFile *r[2];
    r[0] = new ResourceFile("Risorsa_01", 4);
    ASSERT_EQ("Risorsa_01", r[0]->getFileName());
    ASSERT_EQ(4, r[0]->getBit());
    r[1] = new ResourceFile("Risorsa_02", 8);
    ASSERT_EQ("Risorsa_02", r[1]->getFileName());
    ASSERT_EQ(8 , r[1]->getBit());
    r[2] = new ResourceFile("Risorsa_03", 16);
    ASSERT_EQ("Risorsa_03", r[1]->getFileName());
    ASSERT_EQ(16 , r[2]->getBit());
}
