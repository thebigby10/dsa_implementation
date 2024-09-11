#include<bits/stdc++.h>
using namespace std;

class myIntSet{
    int size;
    int arr[100000];

    public:
        myIntSet(){
            size=0;
        }

        int getSize(){
            return size;
        }

        int getElem(int i){
            return arr[i];
        }

        void insert(int num){
            //find the appropriate index and determine if insertion is needed
            int i=0;
            for(i=0;i<size;i++){
              if(arr[i]==num) return; //if the values exists return;
              if(arr[i]<num) break;
            }
            //shift all the elements in the right
            for(int j=size;j>i;j--){
              arr[j] = arr[j-1];
            }
            //insert the element
            arr[i] = num;
            //increase the size by 1
            size++;
        }
        
        int find(int num){
          int low = 0;
          int high = size-1;
          int mid;
          while(low<=high){
            mid = (low+high)/2;
            //cout<<mid<<endl;
            if(arr[mid]>num){
              low = mid + 1;
            }
            else if(arr[mid]<num){
              high = mid - 1;
            }
            else return mid;
          }
          return -1;
        }

        bool erase(int num){
          int ind = find(num);
          if(ind == -1) return false;
          else{
            //shift all the elements in the left
            for(int i=ind;i<size;i++)
              arr[i] = arr[i+1];
            //decrease the size
            size--;
            return true;
          }
        }

        bool erase(int ind1, int ind2){
          //check for invalid index
          if(ind1<0 || ind2 > size ) return false;
          //erase the elements
          for(int i=ind1;i<size;i++){
            arr[i] = arr[i+ind2-ind1+1];
          }
          //dercrease the size
          size -= ind2-ind1+1;
          return true;
        }

        void print(){
          cout<<size<<endl;
          for(int i=0;i<size;i++) cout<<arr[i]<<" ";
          cout<<endl;
        }
};

int main(){
  myIntSet myset;
  myset.insert(7);
  myset.insert(4);
  myset.insert(10);
  myset.insert(10);
  myset.insert(3);
  myset.insert(11);
  myset.insert(1);
  myset.print();
  //cout<<myset.find(7)<<endl;
  //cout<<myset.find(5)<<endl;
  //myset.erase(10);
  //myset.print();
  // cout<<myset.erase(1,7);
  // myset.print();
  return 0;
}
