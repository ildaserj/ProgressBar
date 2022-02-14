#include "gtest/gtest.h"
#include "../ResourceFile.h"
#include "vector"

TEST(RisorseTest, Test_Costructor){
    std::vector <ResourceFile *> r(2);
    r[0] = new ResourceFile("Risorsa_01", 4);
    ASSERT_EQ("Risorsa_01", r[0]->getFileName());
    ASSERT_EQ(4, r[0]->getByte());
    r[1] = new ResourceFile("Risorsa_02", 8);
    ASSERT_EQ("Risorsa_02", r[1]->getFileName());
    ASSERT_EQ(8 , r[1]->getByte());
    r[2] = new ResourceFile("Risorsa_03", 16);
    ASSERT_EQ("Risorsa_03", r[2]->getFileName());
    ASSERT_EQ(16 , r[2]->getByte());
}
