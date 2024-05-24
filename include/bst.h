// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include  <iostream>
#include <string>

using namespace std;

    template <typename type>
    class BST {
  
        public:
        struct tnode {                // узел дерева
            type word;                  // указатель на строку (слово)
            int count;                   // число вхождений
            tnode* left;          // левый потомок
            tnode* right;         // правый потомок
        };
        tnode* root;
        BST() {
            root = NULL;
        }
        tnode* addtree(tnode* p, type& w) {
            int cond;
            if (p == NULL) {
                p = new tnode();
                p->word =w;
                p->count = 1;
                p->left = p->right = NULL;
            } else if (w == p->word) {
                p->count++;
            } else if (w.length() < p->word.length()) {
                p->left = addtree(p->left, w);
            } else {
                p->right = addtree(p->right, w);
            }
            return p;
        }
  
        int search(type& word) {
            tnode* p = root;
            return search(p, word);
        }

        int search(tnode* p, type& w) {
            if (p == NULL) {
            return 0;
            } else if (w == p->word) {
                return p->count;
            } else if (w.length() < p->word.length()) {
                return search(p->left, w);
            } else {
                return search(p->right, w);
            }
        }

        void print() {
        tnode* p = root;
        treeprint(p);
        }

        void treeprint(tnode* p) {
            if (p != NULL) {
                treeprint(p->left);
                cout << p->count <<" " << p->word << endl;
                treeprint(p->right);
            }
        }

        void add(type& word) {
            root = addtree(root, word);
        }

        int heightOfTree(tnode* node) {
            if (node == NULL)
            return 0;
            int left, right;
            if (node->left != NULL) {
                left = heightOfTree(node->left);
            } else {
                left = 0;
            }
            if (node->right != NULL) {
                right = heightOfTree(node->right);
            } else {
                right = 0;
            }
            int max = left > right ? left : right;
            return max + 1;
        }

        int depth() {
            return heightOfTree(this->root);
        }
    };
#endif  // INCLUDE_BST_H_
