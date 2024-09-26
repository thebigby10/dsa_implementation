#include<iostream>
class myStack{

    class SingleList{
    public:
        class Node{
            public:
                Node(int node_value, Node* next_node){
                    this->node_value = node_value;
                    this->next_node = next_node;
                }
                int value() const{
                    return node_value;
                }
                Node* next() const{
                    return next_node;
                }


            private:
                int node_value = 0;
                Node* next_node = nullptr;
        };

        SingleList(){
            head = nullptr;
        }
        bool empty() const{
            if(head == nullptr) return true;
            else return false;
        }
        int front(){
            if(empty()) return -1;
            return head->value();
        }
        Node* begin(){
            return head;
        }
        Node* end(){
            Node* current_node = head;
            if(empty()) return nullptr;
            while(current_node->next()!=nullptr){
                current_node = current_node->next();
            }
            return current_node;

        }
        void push_front(int val){
            Node* new_node = new Node(val, head);
            head = new_node;
        }
        int pop_front(){
            if(empty()) return -1;
            int val = head->value();
            head = head->next();
            return val;
        }
        void show(){
            Node* current_node = head;
            while(current_node->next()!=nullptr){
                std::cout<<current_node->value()<<" ";
                current_node = current_node->next();
            }
            std::cout<<current_node->value()<<" "<<std::endl;
        }

    private:
        Node* head;

    };
    myStack(){
        
    }
    int top() const;
    bool push_top(int);
    int pop_top();
    bool is_empty();
}
