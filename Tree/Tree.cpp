
#include "Tree.h"
#include <queue>

Tree::Tree()
{
    
}

int Tree::idx = -1;

Node* Tree::Create(int* a)
{
    idx++;
    if(a[idx]==-1)
        return NULL;

    Node* newNode = new Node(a[idx]);
    newNode->left = Create(a);
    newNode->right = Create(a);

    return newNode;
}

void Tree::PreOrder(Node* root)
{
    if(root==NULL)
    {
        //cout << "-1, ";
        return;
    }

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void Tree::InOrder(Node* root)
{
    if(root==NULL)
    {
        //cout << "-1, ";
        return;
    }

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void Tree::PostOrder(Node* root)
{
    if(root==NULL)
    {
        //cout << "-1, ";
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

void Tree::LevelOrder(Node* root)
{
    if(root==NULL)
        return;

    //queue<Node*>* q = new(queue<Node*>);
    queue<Node*> q;

    q.push(root);
    q.push(NULL);
    while(!q.empty())
    { 
        Node* curr = q.front();
        q.pop();
        if(curr==NULL)
        {
            cout << endl;
            if(q.empty())
            {
                break;
            }
            else
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << curr->data << " ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
}

int Tree::CountNodes(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    return (CountNodes(root->left) + CountNodes(root->right) + 1);
}

int Tree::SumOfNodes(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    return (root->data + SumOfNodes(root->left) + SumOfNodes(root->right) );
}

int Tree::maxHeight = 0;

int Tree::Height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);

    if(leftHeight>rightHeight)
        return leftHeight+1;
    else
        return rightHeight+1;

}

int Tree::Diameter(Node* root)
{
    // Number of nodes in the longest path between two nodes  O(n^2)
    if(root==NULL)
    {
        return 0;
    }

    int Diam1 = Diameter(root->left);
    int Diam2 = Diameter(root->right);
    int Diam3 = Height(root->left) + Height(root->right) + 1;

    //cout << Diam1 << " " << Diam2 << " " << Diam3 << endl;
    return ( Diam1>=Diam2 ? ( Diam1>=Diam3 ? Diam1 : Diam3 )  : Diam2 );
}

TreeData* Tree::Diameter2(Node* root)
{
    // Number of nodes in the longest path between two nodes  O(n^2)

    if(root==NULL)
    {
        return new TreeData(0,0);
    }

    TreeData* infoLeft  = Diameter2(root->left);
    TreeData* infoRight  = Diameter2(root->right);
    
    int myHeight = ( infoLeft->height>=infoRight->height ? infoLeft->height : infoRight->height  ) + 1;

    int Diam1 = infoLeft->diam;
    int Diam2 = infoRight->diam;
    int Diam3 = infoLeft->height + infoRight->height + 1;

    int myDiam = ( Diam1>=Diam2 ? ( Diam1>=Diam3 ? Diam1 : Diam3 )  : Diam2 );
    
    //cout << Diam1 << " " << Diam2 << " " << Diam3 << endl;
    return new TreeData(myHeight,myDiam);

}

bool Tree::IsIdentical(Node* root, Node* subroot)
{
    if ( (root==NULL) && (subroot==NULL) )
        return true;

    if ( (root==NULL) || (subroot==NULL) )
        return false;

    if(root->data==subroot->data)
    {
        return ( IsIdentical(root->left, subroot->left) && IsIdentical(root->right, subroot->right) );
    }


    return false;
}

bool Tree::IsSubTree(Node* root, Node* subroot)
{
    if(subroot==NULL)
        return true;

    if(root==NULL)
        return false;

    if(root->data == subroot->data)
    {
        if(IsIdentical(root, subroot))
            return true;
    }

    return ( IsSubTree(root->left, subroot) || IsSubTree(root->right, subroot) );
}

void Tree::LeftViewUtil(Node* root, int level, int* maxLevel)
{
    if(root==NULL)
    {
        return;
    }

    if(*maxLevel < level)
    {
        cout << root->data << " " ;
        *maxLevel = level;
    }

    LeftViewUtil(root->left, level+1, maxLevel);
    LeftViewUtil(root->right, level+1, maxLevel);
}

void Tree::LeftView(Node* root)
{
    int max_level=0;
    LeftViewUtil(root, 1, &max_level);
}

void Tree::RightViewUtil(Node* root, int level, int* maxLevel)
{
    if(root==NULL)
    {
        return;
    }

    if(*maxLevel < level)
    {
        cout << root->data << " " ;
        *maxLevel = level;
    }

    RightViewUtil(root->right, level+1, maxLevel);
    RightViewUtil(root->left, level+1, maxLevel);
}

void Tree::RightView(Node* root)
{
    int max_level = 0;
    RightViewUtil(root, 1, &max_level);
}

int main()
{
    /*
             1
          2     3
        4   5     6
    */
    //int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};


    /*
             1
          2       3
        4   5       6
      7  8   9    10
    */
    //int nodes[] = {1, 2, 4, 7, -1, -1, 8, -1, -1,  5, -1, 9, -1, -1, 3, -1, 6, 10, -1, -1, -1};

    /*
             1
          2       3
        4   5       6
      7  8   9    10
                 11
    */
    int nodes[] = {1, 2, 4, 7, -1, -1, 8, -1, -1,  5, -1, 9, -1, -1, 3, -1, 6, 10, 11, -1, -1, -1, -1};

    /*
        4
      7   8
    */
    //int subnodes[] = {4, 7, -1, -1, 8, -1, -1};

    /*
        4
      7   9
    */
    int subnodes[] = {4, 7, -1, -1, 9, -1, -1};
    
    Tree* T = new Tree();
    Node* root = T->Create(nodes);

    Tree::idx = -1;

    Tree* T2 = new Tree();
    Node* subroot = T2->Create(subnodes);

/*
    cout << root->data << endl;
    cout << root->left->data << endl;


    cout << "PreOrder : ";
    T->PreOrder(root);
    cout << endl;

    cout << "InOrder : ";
    T->InOrder(root);
    cout << endl;

    cout << "PostOrder : ";
    T->PostOrder(root);
    cout << endl;


    cout << "LevelOrder : " << endl;
    T->LevelOrder(root);
    cout << endl;
 

    cout << "Count Of Nodes : ";
    cout << T->CountNodes(root);
    cout << endl;


    cout << "Sum Of Nodes : ";
    cout << T->SumOfNodes(root);
    cout << endl;


    cout << "Height : ";
    cout << T->Height(root);
    cout << endl;


    cout << "Diameter : ";
    cout << T->Diameter(root);
    cout << endl;


    cout << "Diameter2 : ";
    cout << T->Diameter2(root)->diam;
    cout << endl;


    cout << "IsSubTree : ";
    cout << T->IsSubTree(root, subroot);
    cout << endl;
*/

    cout << "LeftView : ";
    T->LeftView(root);
    cout << endl;

    cout << "RightView : ";
    T->RightView(root);
    cout << endl;

    system("pause");
}