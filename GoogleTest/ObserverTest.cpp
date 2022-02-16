
#include "gtest/gtest.h"
#include "../ResourceFile.h"
#include "../FileManager.h"
#include "../ProgressBar.h"
#include "SFML/Graphics.hpp"

TEST (ProgressBarTest, notify){
    std::vector<ResourceFile *> risorsa(3);
    risorsa[0] = new ResourceFile("Risorsa_01", 4);
    risorsa[1] = new ResourceFile("Risorsa_02", 8);
    risorsa[2] = new ResourceFile("Risorsa_03", 16);
    FileManager f(risorsa);
    ProgressBar *pb;
    f.attach(pb);
    f.downloadFiles();

    ASSERT_EQ(2,pb->getNumNotify());


}


