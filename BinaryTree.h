#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTree{
    public:
        class BinaryNode{
            public:
                //constructor for BinaryNode which creates a leaf node with a value of type T but no parent or children
                BinaryNode(T val, BinaryNode* parent_node){
                    this->node_value = val;
                    this->parent = parent_node;
                    this->left = left;
                    this->right = right;
                };
                BinaryNode(T val){
                    this->node_value = val;
                    this->parent = nullptr;
                    this->left = left;
                    this->right = right;
                };
                //getter for node value
                T value() const{
                    return this->node_value;
                };
                //getter for parent pointer
                BinaryNode* get_parent() const{
                    return this->parent;
                };
                //getter for left_child pointer
                BinaryNode* get_left() const{
                    return this->left;
                };
                //getter for right_child pointer
                BinaryNode* get_right() const{
                    return this->right;
                };
                //return true if node has no children, otherwise false
                bool isLeaf() const{
                    if(left==nullptr and right==nullptr) return true;
                    else return false;
                };
                //return true if node has no parent, otherwise false
                bool isRoot() const{
                    if(parent==nullptr) return true;
                    else return false;
                };
                //create new BinaryNode with value of type T and attach as left_child to this node
                void insertLeft(T val){
                    left = new BinaryNode(val, this); //**//
                }; 
                //create new BinaryNode with value of type T and attach as right_child to this node
                void insertRight(T val){
                    right = new BinaryNode(val, this);
                };

            private:
                T node_value;
                BinaryNode* parent;
                BinaryNode* left;
                BinaryNode* right;
        };

        //constructor for BinaryTree which creates an empty tree
        BinaryTree(){
            this->root = nullptr;
        };
        //create a BinaryNode and set it as the root
        void createRoot(T val){
            root = new BinaryNode(val);
        };  
        //getter for root pointer
        BinaryNode* get_root() const{
            return this->root;
        };  
        //getter for root value 
        T rootValue() const{
            return root->value();
        };  
        //return true if BinaryTree has no nodes, otherwise false  
        bool empty() const{
            if(root==nullptr) return true;
            else return false;
        };    

	   //recursively delete all children and also the current node itself
        void clear(BinaryNode* node){
            if (node == nullptr) return;
            clear(node->get_left());
            clear(node->get_right());
            delete node; 
        };

        //recursively calculate total number of nodes in BinaryTree
        int size(BinaryNode* node) {
            if (node == nullptr) {
                return 0;
            }
            return 1 + size(node->get_left()) + size(node->get_right());
        } 
        //recursively calculate height of BinaryTree    
        int height(BinaryNode* node) {
           if (node == nullptr) {
                return -1;
            }
            return 1 + max(height(node->get_left()), height(node->get_right()));
        }

        //print the whole BinaryTree branch by branch starting from the root{}
        void DFS_traversal(){
            stack<BinaryNode *> node_stack;
            cout<<"DFS Traversal: "<<endl;
            node_stack.push(this->root);
            while(!node_stack.empty()){
                BinaryNode* top_node = node_stack.top();
                    cout<<top_node->value()<<" "; //**//
                    if(top_node->get_left()!=nullptr) node_stack.push(top_node->get_left());
                    if(top_node->get_right()!=nullptr) node_stack.push(top_node->get_right());
                node_stack.pop();
            }
            cout<<endl;
        };    


    private:
        BinaryNode* root;

};