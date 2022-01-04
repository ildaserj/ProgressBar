//
// Created by serja on 04/01/2022.
//
#include "doctest.h"
#include "../FileManager.h"
#include "../ProgressBar.h"

TEST_CASE("FileMAnagerTest Costructor"){
FileManager f;
CHECK( f.getFileCaricati() == 0);
CHECK(f.getBitCaricati() == 0);
CHECK(f.getObserver().size() == 0);
}

//test attach detach
TEST_CASE("FileManager"){
FileManager f;
    ProgressBar *b1;
    ProgressBar *b2;
    ProgressBar *b3;
    ProgressBar *b4;
    ProgressBar *b5;
    ProgressBar *b6;
    ProgressBar *b7;
    ProgressBar *b8;

    SUBCASE("Filemanger Attach") {

        f.attach(b1);
        f.attach(b2);
        f.attach(b3);
        f.attach(b4);
        f.attach(b5);
        f.attach(b6);
        f.attach(b7);
        f.attach(b8);
        CHECK(f.getObserver().size() == 8);
    }
    SUBCASE("FileManager Detach") {
        f.detach(b1);
        f.detach(b2);
        f.detach(b3);
        f.detach(b4);
        f.detach(b5);
        f.detach(b6);
        f.detach(b7);
        f.detach(b8);
        CHECK(f.getObserver().size() == 0);
    }
    SUBCASE("Attach Detach") {
        f.attach(b1);
        f.attach(b2);
        f.detach(b2);
        CHECK(f.getObserver().size() == 1);
    }
}
