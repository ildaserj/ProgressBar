#include "gtest/gtest.h"
#include "../FileManager.h"
#include "../ProgressBar.h"
#include "../ResourceFile.h"
#include "vector"




//costructor
TEST(FileManagerTest, Costructor){
    std::vector<ResourceFile *> risorsa(0);
    FileManager f(risorsa);
    ASSERT_EQ(0, f.getFileCaricati());
    ASSERT_EQ(0, f.getByteCaricati());
    ASSERT_EQ(0, f.getObserver().size());
}
//getter
TEST(FileMmanagerTest, Getter){
    std::vector<ResourceFile *> risorsa(7);
    risorsa[0] = new ResourceFile("Risorsa_01", 4);
    risorsa[1] = new ResourceFile("Risorsa_02", 8);
    risorsa[2] = new ResourceFile("Risorsa_03", 16);
    risorsa[3] = new ResourceFile("Risorsa_04", 4);
    risorsa[4] = new ResourceFile("Risorsa_05", 4);
    risorsa[5] = new ResourceFile("Risorsa_06", 16);
    risorsa[6] = new ResourceFile("Risorsa_07", 8);
    FileManager f(risorsa);
    f.downloadFiles();
    ASSERT_EQ(7, f.getFileCaricati());
    ASSERT_EQ(60, f.getByteCaricati());
    ASSERT_TRUE(risorsa[0]->getFCaricato());
    ASSERT_TRUE(risorsa[2]->getFCaricato());
    ASSERT_TRUE(risorsa[5]->getFCaricato());
}

//test attach detach
TEST(FileManager, Attach){
    std::vector<ResourceFile *> risorsa(0);
    FileManager f(risorsa);
    ProgressBar *b1;
    ProgressBar *b2;
    ProgressBar *b3;
    ProgressBar *b4;
    ProgressBar *b5;
    ProgressBar *b6;
    ProgressBar *b7;
    ProgressBar *b8;
    f.attach(b1);
    f.attach(b2);
    f.attach(b3);
    f.attach(b4);
    f.attach(b5);
    f.attach(b6);
    f.attach(b7);
    f.attach(b8);
    ASSERT_EQ(8, f.getObserver().size());
    f.detach(b1);
    f.detach(b2);
    f.detach(b3);
    f.detach(b4);
    f.detach(b5);
    f.detach(b6);
    f.detach(b7);
    f.detach(b8);
    ASSERT_EQ(0, f.getObserver().size());
    f.attach(b1);
    f.attach(b2);
    f.detach(b2);
    ASSERT_EQ(1, f.getObserver().size());

}
