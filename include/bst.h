// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <memory>
#include <utility>
#include <algorithm>
#include <string>

template <typename T>
class BST {
public:
    struct Found {
        T value;
        int count;
        std::unique_ptr<Found> left;
        std::unique_ptr<Found> right;

        explicit Found(const T& val)
            : value(val), count(1), left(nullptr), right(nullptr) {}
    };

    BST() : root(nullptr) {}

    void paste(const T& value) {
        root = pasteImpl(std::move(root), value);
    }

    int look(const T& value) const {
        const Found* found = lookImpl(root.get(), value);
        return found ? found->count : 0;
    }

    int profound() const {
        return profoundImpl(root.get()) - 1;
    }

private:
    std::unique_ptr<Found> root;

    std::unique_ptr<Found>pasteImpl(std::unique_ptr<Found> found, const T& value) {
        if (!found) {
            return std::make_unique<Found>(value);
        }

        if (value == found->value) {
            found->count++;
        }
        else if (value < found->value) {
            found->left = pasteImpl(std::move(found->left), value);
        }
        else {
            found->right = pasteImpl(std::move(found->right), value);
        }

        return found;
    }

    const Found* lookImpl(const Found* found, const T& value) const {
        if (!found || found->value == value) {
            return found;
        }

        if (value < found->value) {
            return lookImpl(found->left.get(), value);
        }
        else {
            return lookImpl(found->right.get(), value);
        }
    }

    int profoundImpl(const Found* found) const {
        if (!found) {
            return 0;
        }
        int leftProfound = profoundImpl(found->left.get());
        int rightProfound = profoundImpl(found->right.get());
        return std::max(leftProfound, rightProfound) + 1;
    }
};

#endif  // INCLUDE_BST_H_
