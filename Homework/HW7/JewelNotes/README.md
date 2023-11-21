## Exercise A - Treesort
### Purpose
  The purpose of this exercise is to implement the Treesort Algoirithm which will require at elast a partial implementation of a Binary Search Tree including insertion, inorder traversal, and iterator usage.

### Instructions
- At this point, all coding standards now apply!
-  [ ] call your function template treesort using the following prototype:
  ```
  template <typename FDIter>
  void treesort(FDIter first, FDIer, last);
  ```
- [x] implement your function template with in tsort.hpp
  - since this is a template there will be no associated source file!
  - note that your header file may define any other functions and classes you want.

- [ ] what the functions should do!
  - treesort should take two forward iterators. These will specify a range to be sorted as normal.
    - if both first and last iterators are equal, the range is empty.
  - treesort sorts the given range in a STABLE maner using operator <.
      - the stored data is in the same place as the original data.
      - the function must use the treesort algorithm from in class.

- [ ] the Binary Search tree


Code with comments:
```c++
// tsort.hpp
// Lisa Jacklin && Jewel Maldonado
// 2023-11-12
// For CS 311 Fall 2023
// Header for function template treesort
// There is no associated source file.

#ifndef FILE_TSORT_HPP_INCLUDED
#define FILE_TSORT_HPP_INCLUDED

#include <iterator>
#include <memory>
#include <vector>

// BSTree - Binary Search Tree class
template<typename Value>
class BSTree {
private:
    // Node structure for BST
    struct Node {
        Value data; // Data stored in the node
        std::unique_ptr<Node> left, right; // Unique pointers to left and right children

        // Constructor for Node, initializes data and nullifies children pointers
        Node(const Value& value) : data(value), left(nullptr), right(nullptr) {}
    };

    std::unique_ptr<Node> root; // Root node of the BST

    // Helper function to insert a value into the BST
    void insertNode(std::unique_ptr<Node>& node, const Value& value) {
        if (!node) {
            // If the node is null, create a new node with the value
            node = std::make_unique<Node>(value);
            return;
        }
        // Recursively find the correct position and insert the node
        if (value < node->data) {
            insertNode(node->left, value);
        } else {
            insertNode(node->right, value);
        }
    }

    // Helper function for in-order traversal
    //void inOrderTraversal(const Node* node, std::vector<Value>& elements) const {
    //    if (node) {
    //        // Traverse left subtree, process current node, then traverse right subtree
    //        inOrderTraversal(node->left.get(), elements);
    //        elements.push_back(node->data);
    //        inOrderTraversal(node->right.get(), elements);
    //    }
    //}

    // Helper function for in-order traversal
    template<typename Iter>
    void inOrderTraversal(const Node* node, Iter& iter) const {
        if (node) {
            inOrderTraversal(node->left.get(), iter);
            *iter++ = node->data;  // Write directly to the original range
            inOrderTraversal(node->right.get(), iter);
        }
    }

public:
    // Public method to insert a value into the BST
    void insert(const Value& value) {
        insertNode(root, value);
    }

    // Public method to perform in-order traversal and return sorted elements
    //std::vector<Value> inOrder() const {
    //    std::vector<Value> elements;
    //    inOrderTraversal(root.get(), elements);
    //    return elements; // Return the elements in sorted order
    //}

    // Public method to perform in-order traversal and write sorted elements
    template<typename Iter>
    void inOrder(Iter iter) const {
        inOrderTraversal(root.get(), iter);
    }
};

// treesort
// Sort a given range using Treesort.
// Pre:
//     [first, last) is a valid range. 
// Valid range denoted by two iterators, first and last. 
// The range includes the element pointed to by first but does not include the element pointed to by last.
// Exception safety guarantee:
//     Strong guarantee, provided that copying elements does not throw.
//     State of the program remains unchanged. 
template<typename FDIter>
void treesort(FDIter first, FDIter last) {
    using Value = typename std::iterator_traits<FDIter>::value_type;
    BSTree<Value> tree; // Create a BSTree instance

    // Insert elements into the BST
    for (FDIter it = first; it != last; ++it) {
        tree.insert(*it); // Insert each element in the range into the tree
    }

    // Perform in-order traversal to get sorted elements and write them directly into the original range
    tree.inOrder(first);
}

#endif //#ifndef FILE_TSORT_HPP_INCLUDED
```