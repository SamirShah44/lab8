#include "BinarySearchTree.h"

void BinarySearchTree::add_iteratively(const CityStateZip &new_city)
{
    CSZNode *new_node = new CSZNode(new_city);
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
