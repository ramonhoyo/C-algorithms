#include "DNode.h"

DNode::DNode()
{
    left = nullptr;
    right = nullptr;
    data = 0;
}


DNode::~DNode()
{
    if(left){
        delete left;
        left = nullptr;
    }
    if(right){
        delete right;
        right = nullptr;
    }
}

int DNode::SetData(int _data)
{
    data = _data;
    return 0;
}



