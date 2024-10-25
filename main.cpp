/**
*******************************************************************************
* @file    main.cpp
* @brief   Main program for handling City, State, and Zip data using a
*          binary search tree.
*
* This program reads city, state, and zip code data from a file and
* constructs a binary search tree using the CityStateZip objects.
* It demonstrates adding nodes both recursively and iteratively, and
* provides options to display the tree contents and erase it.
*
* The main() function serves as the entry point for the program. It
* handles file I/O, manages the binary search tree, and provides
* user interaction for viewing the tree's contents.
*
* @remarks
*      Course:        Computer Science 2124, Fall 2024
*      Due Date:      Monday, October 28
*      Instructor:    Steven Gilland
*
* @author  Samir kumar Shah
* @date    10/24/2024
*******************************************************************************
**/

#include "CSZNode.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
#include <limits>
using std::cout;
using std::endl;

CityStateZip read_CityStateZip(std::istream &fin)
{
    std::string city, state;
    unsigned int zip = 0;
    getline(fin, city, ',');
    getline(fin, state, ',');
    fin >> zip;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // creates a temporary CityStateZip object and returns it
    return CityStateZip{city, state, zip};
}

int main()
{
    std::ifstream fin{"city_list.txt"};
    if (!fin)
    {
        cout << "Error opening city_list.txt!\n";
        exit(1);
    }

    CSZNode n1{read_CityStateZip(fin)};
    CSZNode n2{read_CityStateZip(fin)};

    cout << "test CSZNodes:\n";
    cout << n1 << endl;
    cout << n2 << endl;
    cout << endl;

    cout << "Press <enter> to continue...\n";
    std::cin.get();
    BinarySearchTree city_tree;
    fin.clear();  // restore stream state so I/O may proceed
    fin.seekg(0); // seek "get" to file start (byte #0)
    while (fin.good())
    {
        city_tree.add_iteratively(read_CityStateZip(fin));
    }
    cout << "Recursive Tree Listing of Iterative Additions\n";
    city_tree.write_recursively(cout);

    cout << "Press <enter> to continue...\n";
    std::cin.get();
    city_tree.erase_recursively();
    cout << "Iterative Tree Listing After Erase:\n";
    city_tree.write_iteratively(cout);
    cout << "<end of tree output>\n\n";
    fin.clear();  // restore stream state so I/O may proceed
    fin.seekg(0); // seek "get" to file start (byte #0)
    while (fin.good())
    {
        city_tree.add_recursively(read_CityStateZip(fin)); // recursive add
    }
    cout << "Iterative Listing of Recursive Additions\n";
    city_tree.write_iteratively(cout);
    fin.close();
    return 0;
}
