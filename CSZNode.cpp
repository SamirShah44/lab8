#include "CSZNode.h"

void CSZNode::set_left(CSZNode *new_left)
{
    this->left = new_left;
}

void CSZNode::set_right(CSZNode *new_right)
{
    this->right = new_right;
}

CityStateZip CSZNode::get_data() const
{
    return payload;
}

CSZNode *CSZNode::get_left() const
{
    return this->left;
}

CSZNode *CSZNode::get_right() const
{
    return this->right;
}

void CSZNode::write(std::ostream &fout) const
{
    fout << payload;
}

std::ostream &operator<<(std::ostream &fout, const CSZNode &n)
{
    n.write(fout);
    return fout;
}
