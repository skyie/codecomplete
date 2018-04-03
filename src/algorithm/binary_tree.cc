/** 
 * 二叉树相关算法实现
 */


#include <iostream>
#include <assert.h>

using namespace std;

class BinaryNode
{
public:
    BinaryNode(int v, BinaryNode* _lchild, BinaryNode* _rchild): val(v), lchild(_lchild), rchild(_rchild) {};

    ~BinaryNode(){};
    
private:
    int val;
    friend class BinaryTree;
    BinaryNode* lchild;
    BinaryNode* rchild;
};

class BinaryTree
{
public:
    BinaryTree(BinaryNode* _root): root(_root) {};
    ~BinaryTree() { destroy_tree(root); };

    BinaryNode* create_binary_tree(int arr[], int len);
    BinaryNode* insert(int val);

    /* 递归方式遍历 */
    void pre_travel(BinaryNode* root);
    void post_travel(BinaryNode* root);
    void in_travel(BinaryNode* root);

    /* 非递归方式遍历 */
    void pre_travel_no_recursive(BinaryNode* root);
    void post_travel_no_recursive(BinaryNode* root);
    void in_travel_no_recursive(BinaryNode* root);


    
private:
    void destroy_tree(BinaryNode* root);
    BinaryNode* _insert(BinaryNode* root, int val);
private:
    BinaryNode* root;

};

//BinaryTree::~BinaryTree() {
    //destroy_tree(root);    
//}

void BinaryTree::destroy_tree(BinaryNode * root)
{
    if (root == NULL) {
        return;
    }
    if (root->lchild == NULL && root->rchild == NULL) {
        delete root;
    }    
    destroy_tree(root->lchild);
    destroy_tree(root->rchild);
}    


BinaryNode* BinaryTree::_insert(BinaryNode* root, int val)
{
  if (root == NULL) {
        return root;
  }
  int cur_value = root->val;
  if (cur_value == val) {
        return root;
  }
  if (val < cur_value) {
    if (root->lchild == NULL) {
        BinaryNode* new_node = new BinaryNode(val, NULL, NULL);
        root->lchild = new_node;
    
    } else {
        _insert(root->lchild, val);
    }

  } else {
    if (root->rchild == NULL) {
        BinaryNode* new_node = new BinaryNode(val, NULL, NULL);
        root->rchild = new_node;
    } else {
        _insert(root->rchild, val);
    }
  }
  return root;   
}


BinaryNode* BinaryTree::insert(int val)
{
    if (root == NULL) {
        root = new BinaryNode(val, NULL, NULL);
        return root;
    } 
    return _insert(root, val);
    

}

BinaryNode* BinaryTree::create_binary_tree(int arr[], int len)
{
    int i;
    BinaryNode* root;
    for (i = 0;i < len; i++) {
        root = insert(arr[i]);
    }
    return root;

}

void BinaryTree::pre_travel(BinaryNode* root)
{
    if (root == NULL) {
        return;
    }

    if (root->lchild != NULL) {
        pre_travel(root->lchild);
    }     
    cout<< root->val<< endl;
    if (root->rchild) {
        pre_travel(root->rchild);
    }

}

void BinaryTree::post_travel(BinaryNode* root)
{
    if (root == NULL) {
        return;
    }
    if (root->rchild != NULL) {
        pre_travel(root->rchild);
    }     
    cout<< root->val<< endl;
    if (root->lchild) {
        pre_travel(root->lchild);
    }

}

void BinaryTree::in_travel(BinaryNode* root)
{
    if (root == NULL) {
        return;
    }
    cout << root->val << endl;
    if (root->lchild != NULL) {
        pre_travel(root->lchild);
    }     
    if (root->rchild) {
        pre_travel(root->rchild);
    }

}



void BinaryTree::pre_travel_no_recursive(BinaryNode* root)
{




}
void BinaryTree::post_travel_no_recursive(BinaryNode* root)
{




}
void BinaryTree::in_travel_no_recursive(BinaryNode* root)
{



}


void test()
{
    int arr[] = {4,10, 8, 1};
    BinaryTree* tree = new BinaryTree(NULL);
    BinaryNode* root = tree->create_binary_tree(arr, sizeof(arr)/sizeof(int));
    assert(root);
    cout<< "pre travel ------"<<endl;
    tree->pre_travel(root);
    cout<< "post travel ------"<<endl;
    tree->post_travel(root);
    
    cout<< "in travel ------"<<endl;
    tree->in_travel(root);
}

int main()
{
    test();
}

