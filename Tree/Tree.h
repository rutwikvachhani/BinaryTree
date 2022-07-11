
#include <iostream>

using namespace std;

class Node
{
public:

    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        data=d;
        left = NULL;
        right = NULL;
    }
};

class TreeData
{
public:
    int height;
    int diam;

    TreeData(int h, int d)
    {
        this->height = h;
        this->diam = d;
    }
};

class Tree
{
public:
    Tree();

    //Tree(int a[]);
    ~Tree();

    Node* Create(int*);
    void Insert();
    void InOrder(Node*);
    void PreOrder(Node*);
    void PostOrder(Node*);
    void LevelOrder(Node*);
    int CountNodes(Node*);
    int SumOfNodes(Node*);
    int Height(Node*);
    int Diameter(Node*);
    TreeData* Diameter2(Node*);
    bool IsIdentical(Node*, Node*);
    bool IsSubTree(Node*, Node*);
    void LeftViewUtil(Node*, int, int*);
    void LeftView(Node*);
    void RightViewUtil(Node*, int, int*);
    void RightView(Node*);
    int LeftRightView(Node*);
    void Delete(Node*, int);
    int depth();
    int level();

    static int idx;
    static int maxHeight;

private:

};