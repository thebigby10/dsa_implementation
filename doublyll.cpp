#include<iostream>
using namespace std;

class doubly{
	class Node{
		int node_value = -1;
		Node* prev_node = nullptr;
		Node* next_node = nullptr;
	public:
		Node();
		Node(int node_value, Node* prev_node, Node* next_node){
			this->node_value = node_value;
			this->prev_node = prev_node;
			this->next_node = next_node; 
		}
		int value() const{
			return this->node_value;
		}
		Node* prev() const{
			return this->prev_node;
		}
		Node* next() const{
			return this->next_node;
		}
		void set_prev(Node* prev_node){
			this->prev_node = prev_node; 
		}
		void set_next(Node* next_node){
			this->next_node = next_node;
		}
	};

	Node* head = nullptr;
	Node* tail = nullptr;
public:
	bool empty(){
		if(head==nullptr) return true;
		return false;
	}
	int size(){
		if(empty()) return 0;
		int size = 0;
		while(head->next()!=nullptr){
			size++;
			head = head->next();
		}
		return size;
	}
	void push_front(int val){
		//create new node
		Node* new_node = new Node(val, nullptr ,head );
		//if empty add to tail too and add first node's prev to new node
		if(empty()) tail = new_node;
		else head->set_prev(new_node);
		//add to head
		head = new_node;
	}
	void push_back(int val){
		// create new node
		Node* new_node = new Node(val, tail, nullptr);
		//if empty add to head and add last node's next to new node
		if(empty()) head = new_node;
		else tail->set_next(new_node);
		// add to tail
		tail = new_node;
		//add last node's 
	}
	// TODO : FIX
	int pop_front(){
		if(empty()) return -1;
		int val = head->value();
		head = head->next();
		if(empty()){
			tail = nullptr;
		} 
		else{
			head->set_prev(nullptr);
		}
		return val;
	}
	// TODO : FIX
	int pop_back(){
		if(empty()) return -1;
		int val = tail->value();
		tail = tail->prev();
		if(empty()) head = nullptr;
		else{
			tail->set_next(nullptr);
		}
		return val;
	}
	// TODO : IMPLEMENT
	void show(){

	}

};

int main(){
	doubly dll;
	cout<<dll.empty()<<endl;
	dll.push_back(10);
	dll.push_back(11);
	dll.push_front(9);
	dll.push_front(8);
	cout<<dll.empty()<<endl;
	cout<<endl;
	cout<<dll.pop_front()<<endl;
	cout<<dll.pop_front()<<endl;
	cout<<dll.pop_front()<<endl;
	// cout<<dll.pop_front()<<endl;
	cout<<dll.pop_back()<<endl;
	// cout<<dll.pop_back()<<endl;
}