#include<iostream>
using namespace std;

template <typename T>
class CircularQueue{
    public:
        CircularQueue(int queue_capacity){
            this->capacity = queue_capacity;
            arr = new T[queue_capacity];
        };
        bool empty() const{
            if(q_size==0) return true;
            else return false;
        };
        int size() const{
            return q_size;
            // return abs(ifront - iback) + 1; 
        };
        T front() const{
            return *(arr+ifront);
        };
        void enqueue(T data){
            //add an element to the last of the queue
            if(full()) return;
            q_size++;
            //if the iback is capacity-1 remove the elemen and go to front
            if(iback==capacity-1){
                *(arr+iback) = data;
                iback = 0;
            }
            //otherwise add to the front
            else{
                *(arr+iback) = data;
                iback++;
            }
        };
        T dequeue(){
            //remove an element from the first of the queue
            if(empty()) return -1;
            q_size--;
            //if the ifront is capacity-1 go to front
            if(ifront==capacity-1){
                ifront = 0;
            }
            else{
                ifront++;
            }
            return *(arr+ifront);
        };
        void show(){
            if(empty()) return;
            if(ifront<iback){
                for(int i=ifront;i<iback;i++){
                    cout<<*(arr+i)<<" ";
                }
                cout<<endl;
            }
            else{
                for(int i=ifront;i<capacity-1;i++){
                    cout<<*(arr+i)<<" ";
                }
                for(int i=0;i<=iback;i++){
                    cout<<*(arr+i)<<" ";
                }
                cout<<endl;
            }
        };
        bool full() const{
            if(q_size==capacity) return true;
            return false;
        };
    private:
        int q_size = 0;
        int capacity = 1000;
        int ifront = 0;
        int iback = 0;
        T *arr;
};