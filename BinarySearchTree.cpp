/**
 * @file    BinarySearchTree.cpp
 * @brief   Implementation of the BinarySearchTree class.
 *
 * This file contains the definitions of the methods for the 
 * BinarySearchTree class, which provides functionality for 
 * adding, deleting, and traversing a binary search tree of 
 * CityStateZip objects. The tree maintains order based on 
 * city names, allowing for efficient searches and updates.
 *
 * The BinarySearchTree class supports both recursive and 
 * iterative methods for adding nodes and traversing the tree. 
 * It also ensures proper memory management through a destructor 
 * that cleans up all dynamically allocated nodes.
 *
 * @author  Samir kumar Shah
 * @date    10/24/2024
 * 
 */

#include "BinarySearchTree.h"
#include <stack>

/**
 * @brief       Destructor for the BinarySearchTree class.
 *
 * @detailed    This destructor is responsible for cleaning up the memory 
 *              used by the binary search tree. It calls the 
 *              erase_recursively method to ensure that all nodes 
 *              are deleted and memory is properly deallocated.
 * 
**/

BinarySearchTree::~BinarySearchTree()
{
    erase_recursively();
}

/**
 * @brief       Recursively adds a new city to the binary search tree.
 *
 * @detailed    This function inserts a CityStateZip object as a new node 
 *              into the binary search tree. It creates a new node with the 
 *              provided data and places it based on lexicographical order of 
 *              the city name, using a recursive helper function.
 *
 * @remarks     This functions calls add_recursively(new_node, root) private
 *              method if the tree is not empty.
 *      
 * @param       new_city(CityStateZip&)   The data to be added to the tree.
 *
**/

void BinarySearchTree::add_recursively(const CityStateZip &new_city)
{
    CSZNode *new_node = new CSZNode(new_city);
    if (root == nullptr)
    {
        root = new_node;
    }
    else
    {
        add_recursively(new_node, root);
    }
}

/**
 * @brief       Iteratively adds a new city to the binary search tree.
 *
 * @detailed    This function inserts a CityStateZip object as a new node 
 *              into the binary search tree using an iterative approach. It 
 *              traverses the tree to find the appropriate location based on 
 *              the lexicographical order of the city name.
 *
 * @remarks     The iterative method provides an alternative to recursive 
 *              insertion,  which may be more efficient for large data sets by
 *              avoiding stack overflow in deep trees.
 *      
 * @param       new_city(CityStateZip&)   The data to be added to the tree.
 *
**/

void BinarySearchTree::add_iteratively(const CityStateZip &new_city)
{
    CSZNode *new_node = new CSZNode(new_city);
    if (root)
    {
        CSZNode *current = root;
        CSZNode *previous = nullptr;
        while (current != nullptr)
        {
            previous = current;
            if (*new_node < *current)
                current = current->get_left();
            else // *new_node > *current
                current = current->get_right();
        }
        if (*new_node < *previous)
            previous->set_left(new_node);
        else // *new_node > *previous
            previous->set_right(new_node);
    }
    else
    {
        root = new_node;
    }
}

/**
 * @brief       Recursively adds a new node to the binary search tree.
 *
 * @detailed    This function places a new CSZNode in the tree based on 
 *              lexicographical order of city names. It compares the new_node
 *              with the data at current_root and recursively navigates left 
 *              or right until it finds an appropriate position.
 *
 * @param       new_node(CSZNode*)     A pointer to the node to be inserted.
 * @param       current_root(CSZNode*)  The current root node during traversal.
 *
**/

void BinarySearchTree::add_recursively(CSZNode *new_node, 
                                       CSZNode *current_root)
{
    if (new_node->get_data().city() < current_root->get_data().city())
    {
        if (current_root->get_left() == nullptr)
        {
            current_root->set_left(new_node);
        }
        else
        {
            add_recursively(new_node, current_root->get_left());
        }
    }
    else
    {
        if (current_root->get_right() == nullptr)
        {
            current_root->set_right(new_node);
        }
        else
        {
            add_recursively(new_node, current_root->get_right());
        }
    }
}

/**
 * @brief       Recursively outputs data from nodes in the tree.
 *
 * @detailed    Performs an in-order traversal of the tree starting from 
 *              current_root, outputting each node's data to the provided 
 *              output stream.
 *
 * @remarks     Ensure current_root is not null when calling. For complete tree 
 *              output, call this function starting from the tree's root.
 *      
 * @param[out]  strm(ostream&)      The stream where the node data is output.
 * @param       current_root(CSZNode*)  The root node from where traversal 
 *                                      begins.
 *
**/

void BinarySearchTree::write_recursively // called by public version
    (std::ostream &strm, CSZNode *current_root) const
{
    if (current_root != nullptr)
    {
        write_recursively(strm, current_root->get_left());
        strm << *current_root;
        write_recursively(strm, current_root->get_right());
    }
}

/**
 * @brief       Recursively deletes nodes in the binary search tree.
 *
 * @detailed    This function recursively deletes each node in the tree, 
 *              starting from the currentRoot. It calls itself on both 
 *              left and right child nodes before deleting the currentRoot.
 *
 * @remarks     This method should be used with caution as it permanently 
 *              deletes nodes and deallocates memory, leaving the tree empty.
 *      
 * @param       currentRoot(CSZNode*)   The node to delete during each 
 *                                      recursive call.
 *
**/

void BinarySearchTree::erase_recursively(CSZNode *currentRoot)
{
    if (currentRoot != nullptr)
    {
        erase_recursively(currentRoot->get_left());
        erase_recursively(currentRoot->get_right());
        delete currentRoot;
    }
}

/**
 * @brief       Recursively outputs the contents of the tree.
 *
 * @detailed    This function recursively traverses the binary search tree in 
 *              lexicographical order (in-order traversal) and outputs the 
 *              node data to the provided output stream.
 *
 * @remarks     This function calls the private method 
 *              write_recursively(strm, current) and to print the data to
 *              output stream.
 *
 * @param[out]   strm(ostream&)   The output stream to which the tree data
 *                                is written.
 * 
**/

void BinarySearchTree::write_recursively(std::ostream &strm) const
{
    CSZNode *current = root;
    write_recursively(strm, current);
}

/**
 * @brief       Iteratively outputs the contents of the tree.
 *
 * @detailed    This function iteratively traverses the binary search tree in 
 *              lexicographical order (in-order traversal) and outputs the node
 *              data to the provided output stream.
 *
 * @remarks     Iterative traversal avoids the overhead of recursive stack 
 *              calls. Ensure the tree is populated before calling for 
 *              meaningful output.
 *      
 * @param[out]   strm(ostream&)   The output stream to which the tree data 
 *                                is written.
 *
**/

void BinarySearchTree::write_iteratively(std::ostream &strm) const
{
    CSZNode *current = root;
    std::stack<CSZNode *> list_stack;

    while (current != nullptr || !list_stack.empty())
    {
        while (current != nullptr)
        {
            list_stack.push(current);
            
                current = current->get_left();
            
        }
        current = list_stack.top();
        list_stack.pop();
        strm << current->get_data() << std::endl;
        current = current->get_right();
    }
}

/**
 * @brief       Recursively deletes all nodes in the binary search tree.
 *
 * @detailed    This function erases each node in the binary search tree 
 *              by calling a recursive helper function that traverses the 
 *              tree and deletes each node. After this function, the tree 
 *              will be empty.
 *
 * @remarks     This function deallocates memory used by the tree. Use with 
 *              caution, as it permanently deletes all nodes in the tree.
 *      
**/

void BinarySearchTree::erase_recursively()
{
    erase_recursively(root);
    root = nullptr;
}
