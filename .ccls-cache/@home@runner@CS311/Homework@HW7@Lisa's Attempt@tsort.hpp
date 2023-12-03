// tsort.hpp 
//Lisa Jacklin && Jewel Maldonado
// 2023-11-14
//
// For CS 311 Fall 2023
// Header for function template treesort
// There is no associated source file.

#ifndef FILE_TSORT_HPP_INCLUDED
#define FILE_TSORT_HPP_INCLUDED

#include <iterator>
// For std::iterator_traits

// *******************************************************
// * YOU MIGHT WANT TO GET RID OF THE FOLLOWING INCLUDES *
// *******************************************************

#include <algorithm>
// For std::stable_sort, std::move
#include <vector>
// For std::vector
#include <iterator>
// For std::distance


// treesort
// Sort a given range using Treesort.
// Pre:
//     ???
// Exception safety guarantee:
//     ???
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
  // Check if the range is empty
  if (first == last) {
      return;
  }

  // Build the binary search tree using move semantics
  auto root = buildTree<typename std::iterator_traits<FDIter>::value_type>(first, last);

  // Traverse the tree in in-order to retrieve sorted elements
  try {
      inOrderTraversal(root.get(), first);
  } catch (...) {
      // If an exception occurs during traversal, let it propagate
      throw;
  }
  }


// Definition of TreeNode for Binary Search Tree
template <typename T>
struct TreeNode {
    T data;
    std::unique_ptr<TreeNode<T>> left;
    std::unique_ptr<TreeNode<T>> right;

    TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a value into the Binary Search Tree
template <typename T>
void insert(std::unique_ptr<TreeNode<T>>& root, T value) {
    if (!root) {
        root = std::make_unique<TreeNode<T>>(std::move(value));
    } else if (value < root->data) {
        insert(root->left, std::move(value));
    } else {
        insert(root->right, std::move(value));
    }
}

// Function for in-order traversal of the Binary Search Tree
template <typename T, typename FDIter>
void inOrderTraversal(const TreeNode<T>* root, FDIter& it) {
    if (root) {
        inOrderTraversal(root->left.get(), it);
        *it = root->data;
        ++it;
        inOrderTraversal(root->right.get(), it);
    }
}

// Function to build a Binary Search Tree from a range of elements
template <typename T, typename FDIter>
std::unique_ptr<TreeNode<T>> buildTree(FDIter first, FDIter last) {
    std::unique_ptr<TreeNode<T>> root = nullptr;
    for (FDIter it = first; it != last; ++it) {
        insert(root, *it);
    }
    return root;
}


#endif //#ifndef FILE_TSORT_HPP_INCLUDED

