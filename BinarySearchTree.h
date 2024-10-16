#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinarySearchTree{
    public:
        class BinarySearchNode{
            public:
            //constructor for BinarySearchNode which creates a leaf node with a value of type T but no parent or children
                BinarySearchNode(T const &value, BinarySearchNode* parent = nullptr){
                    this->node_value = value;
                    this->parent_node = parent;
                    this->left_child = nullptr;
                    this->right_child = nullptr;
                };  
            //getter for node value
                T value() const{
                    return this->node_value;
                }; 
            //getter for parent pointer
                BinarySearchNode* parent() const{
                    return this->parent_node;
                };
            //getter for left_child pointer     
                BinarySearchNode* left() const{
                    return this->left_child;
                };   
            //getter for right_child pointer
                BinarySearchNode* right() const{
                    return this->right_child;
                };  
            //return true if the node is null
                bool empty() const{
                    return (this==nullptr);
                };
            //return true if node has no children (both left and right is null), otherwise false     
                bool isLeaf() const{
                    return (this->left_child == nullptr && this->right_child == nullptr);
                };  
            //return true if node has no parent, otherwise false      
                bool isRoot() const{
                    return (this->parent_node == nullptr);
                };        
            //recursively calculate total number of nodes in the BST
                int size(BinarySearchNode* current_node){
                    if(current_node->left()==nullptr && current_node->right()==nullptr) return 1;
                    return 1 + size(current_node->left()) + size(current_node->right());
                };     
            //recursively calculate height of the BST
                int height(){
                    if(this==nullptr) return -1;
                    int left_height = -1;
                    int right_height = -1;
                    if(this->left_child!=nullptr){
                        left_height = this->left_child->height();
                    }
                    if(this->right_child!=nullptr){
                        right_height = this->right_child->height();
                    }
                    if(left_height>=right_height) return 1+left_height;
                    else return 1+right_child;
                };   
            //find the minimum element in the BST
                T front() const{
                    BinarySearchNode* current_node = this;
                    while(true){
                        if(current_node->left_child==nullptr) return current_node->node_value;
                        current_node = current_node->left_child;
                    }
                };    
            //find the maximum element in the BST
                T back() const{
                    BinarySearchNode* &current_node = this;
                    while(true){
                        if(current_node->right_child==nullptr) return current_node->node_value;
                        current_node = current_node->right_child;
                    }
                };    
            //return true if the node with value of type T exists in the BST
                bool find(T const &val){
                    if(val==this->node_value) return true;
                    else if(val < this->node_value){
                        if(this->left_child!=nullptr){
                            return this->left_child->find(val);
                        }
                        else return false;
                    }
                    else{
                        if(this->right_child!=nullptr){
                            return this->right_child->find(val);
                        }
                        else return false;
                    }
                };    
            //traverse to the appropriate location of the BST and create new BinarySearchNode with value of type T 
                bool insert(T const &val){
                    if(val==this->node_value) return false;
                    if(val < this->node_value){
                        if(this->left_child==nullptr){
                            this->left_child = new BinarySearchNode(val, this);
                            return true;
                        }
                        else{
                            return this->left_child->insert(val);
                        }
                    }
                    if(val > this->node_value){
                        if(this->right_child==nullptr){
                            this->right_child = new BinarySearchNode(val, this);
                            return true;
                        }
                        else{
                            return this->right_child->insert(val);
                        }
                    }
                    // return false;
                };     
            //delete the node having value of type T from the BST (do not clear subtree)
                bool erase(T const &val);     


            private:
                T node_value;
                BinarySearchNode* parent_node;
                BinarySearchNode* left_child;
                BinarySearchNode* right_child;
        };
    //constructor for BinarySearchTree which creates an empty tree
        BinarySearchTree(){
            this->root_node = nullptr;
        };   
    //getter for root_node pointer
        BinarySearchNode* root() const{
            return this->root_node;
        };  
    //getter for root_node value 
        T rootValue() const{
            if(this->root_node==nullptr) return -1;
            return this->root_node->value();
        };
    //return true if the BST has no nodes, otherwise false    
        bool empty() const{
            return (this->root_node==nullptr);
        };    
    //simply call the size function of the BinarySearchNode class
        int size(){
            return root_node->size(root_node);
        }; 
    //simply call the height function of the BinarySearchNode class    
        int height();   
    //handle any exceptions, then simply call the front function of the BinarySearchNode class
        T front() const{
            return root_node->front();
        };    
    //handle any exceptions, then simply call the back function of the BinarySearchNode class
        T back() const{
            return root_node->back();
        };    
    //simply call the find function of the BinarySearchNode class
        bool find(T const &val){
            return root_node->find(val);
        };  
    //simply call the insert function of the BinarySearchNode class
        bool insert(T const &val){
            return root_node->insert(val);
        };  
    //simply call the erase function of the BinarySearchNode class
        bool erase(T const &); 
    //print the whole BST recursively in the Breadth-First order
        void level_order_traversal(){
            queue<BinarySearchNode*> bfs_queue;
            bfs_queue.push(root_node);
            // BinarySearchNode* current_node = root_node;
            while(!bfs_queue.empty()){
                cout<<bfs_queue.front().value()<<" ";
                if(bfs_queue.front()->right_child!=nullptr) bfs_queue.push(root_node->right_child);
                if(bfs_queue.front()->left_child!=nullptr) bfs_queue.push(root_node->left_child);
                bfs_queue().pop();
            }
            cout<<endl;
        };    


    private:
        BinarySearchNode* root_node;

};