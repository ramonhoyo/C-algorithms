#ifndef DNODE_H
#define DNODE_H


class DNode
{
public:
    DNode();
    ~DNode();

    inline DNode* Left()  { return left ; }
    inline DNode* Right() { return right; }
    inline int Data()     { return data ; }

    int SetData(int);

private:
    int data;
    DNode * left;
    DNode * right;
};

#endif // DNODE_H
