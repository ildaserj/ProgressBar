//
// Created by serja on 27/12/2021.
//

#include "gtest/gtest.h"
#include "../FileManager.h"
#include "../ProgressBar.h"


TEST(FileMAnagerTest, Costructor){
    FileManager f;
    ASSERT_EQ(0, f.getFileCaricati());
    ASSERT_EQ(0, f.getBitCaricati());
    ASSERT_EQ(0, f.getObserver().size());
}

//test attach detach
TEST(FileManager, Attach){
    FileManager f;
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
