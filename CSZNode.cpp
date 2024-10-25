/**
 * @file    CSZNode.cpp
 * @brief   Implementation of the CSZNode class, which represents nodes in a 
 *          binary search tree for managing city, state, and ZIP code data.
 *
 * This file contains the method implementations for the CSZNode class, 
 * including functions for setting and retrieving child nodes, accessing node 
 * data, comparing nodes, and outputting node information to a stream. The 
 * CSZNode class is designed to work with a CityStateZip structure and to be 
 * compatible with a binary search tree structure, where nodes are ordered 
 * based on city name.
 *
 * @author  Samir kumar Shah
 * @date    10/24/2024
 */

#include "CSZNode.h"

/**
 * @brief       Outputs the data of the node to the provided output stream
 *
 * @detailed    This function writes the data contained in the node's payload 
 *              (city, state, and ZIP code information) to the given output 
 *              stream.
 *
 * @remarks     This function performs output to an external stream, fout. 
 *              It does not modify the contents of the node itself.
 *      
 *
 * @param[out]   fout(ostream&)   The output stream to which the node data 
 *                                is written.
 * 
**/

void CSZNode::write(std::ostream &fout) const
{
    fout << payload << std::endl;
}

/**
 * @brief       Compares this node with another node based on city.
 *
 * @detailed    This function defines a comparison operator to compare two  
 *              CSZNode objects based on their payload (CityStateZip). 
 *              Specifically, the function returns true if the city name 
 *              in this node's payload is lexicographically less than the 
 *              city name in op2.
 *
 * @remarks     This function is useful for ordering nodes in a binary search 
 *              tree by city name. It does not modify the contents of either 
 *              node.
 *      
 *
 * @param        op2(CSZNode&)   The object to compare with this node.
 *
 * @return      (boolean)    True if this node's city data is less than 
 *                           op2's city data; otherwise, false.
**/

bool CSZNode::operator<(const CSZNode &op2) const
{
    return this->get_data().city() < op2.get_data().city();
}

/**
 * @brief       Outputs the data of a node to an output stream using the 
 *              << operator.
 *
 * @detailed    This operator overload enables the use of << to output CSZNode 
 *              data directly to an output stream, formatted according to the 
 *              CityStateZip structure's output operator.
 *
 * @remarks     This function enables easy and formatted output of CSZNode 
 *              instances, making it compatible with common stream operations. 
 *              This is an external function and does not modify the node’s 
 *              contents.
 *      
 *
 * @param[out]   fout(ostream&)   The output stream to which the node data is 
 *                                written.
 * @param        n(CSZNode&)      The object whose data is output to fout.
 *
 * @return       fout(ostream&)   Allows for chaining << operations.
**/

std::ostream &operator<<(std::ostream &fout, const CSZNode &n)
{
    n.write(fout);
    return fout;
}
