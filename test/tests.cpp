// Copyright 2021 NNTU-CS
#include <gtest/gtest.h>
#include <string>

#include "bst.h"
BST<std::string> makevetki(const char* filename);

TEST(lab9, test1_1) {
const char* filename = "/home/runner/work/ADS-9/ADS-9/build/test/war_peace.txt";
BST<std::string> tree = makevetki(filename);
int d = tree.d();
EXPECT_EQ(d, 35);
}
TEST(lab9, test1_2) {
const char* filename = "/home/runner/work/ADS-9/ADS-9/build/test/war_peace.txt";
BST<std::string> tree = makevetki(filename);
int d = tree.poisk("pierre");
EXPECT_EQ(d, 1963);
}
TEST(lab9, test1_3) {
const char* filename = "/home/runner/work/ADS-9/ADS-9/build/test/war_peace.txt";
BST<std::string> tree = makevetki(filename);
int d = tree.poisk("natasha");
EXPECT_EQ(d, 1212);
}
TEST(lab9, test1_4) {
const char* filename = "/home/runner/work/ADS-9/ADS-9/build/test/war_peace.txt";
BST<std::string> tree = makevetki(filename);
int d = tree.poisk("andrew");
EXPECT_EQ(d, 1143);
}}