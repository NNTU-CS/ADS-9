// Copyright 2021 NNTU-CS
#include <gtest/gtest.h>
#include <string>

#include "bst.h"
BST<std::string> makeTree(const char* filename);

TEST(lab9, test1_1) {
    const char* filename = "/home/runner/work/ADS-9/ADS-9/build/test/war_peace.txt";
    BST<std::string> tree = makeTree(filename);
    int depth = tree.depth();
    EXPECT_EQ(depth, 35);
}
TEST(lab9, test1_2) {
    const char* filename = "/home/runner/work/ADS-9/ADS-9/build/test/war_peace.txt";
    BST<std::string> tree = makeTree(filename);
    int depth = tree.search("pierre");
    EXPECT_EQ(depth, 1963);
}
TEST(lab9, test1_3) {
    const char* filename = "/home/runner/work/ADS-9/ADS-9/build/test/war_peace.txt";
    BST<std::string> tree = makeTree(filename);
    int depth = tree.search("natasha");
    EXPECT_EQ(depth, 1212);
}
TEST(lab9, test1_4) {
    const char* filename = "/home/runner/work/ADS-9/ADS-9/build/test/war_peace.txt";
    BST<std::string> tree = makeTree(filename);
    int depth = tree.search("andrew");
    EXPECT_EQ(depth, 1143);
}
