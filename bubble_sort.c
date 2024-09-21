//Bubble sort is that you compare two elements and swap based on the elements.
//Input: X as the array that will be sorted
//Output: Every step of selection sort algorithm

#include<stdio.h>

void bubbleSort(int *x, int arr_len);
void print_array(int *x, int arr_len,int underline_ind_1, int underline_ind_2);
void swap(int *x, int *y);

int main(){
    int x[] = {1,6,3,2,8,3,1,1,10,100,0,-1};
    int arr_len = 12;
    printf("Initial array:\n");
    print_array(x,arr_len,-1,-1);
    bubbleSort(x,arr_len);
    printf("\033[4mSorted Array:\033[0m\n");
    print_array(x,arr_len,-1,-1);
    return 0;
}

void bubbleSort(int *x, int arr_len){
    int step_count = 0;
    for(int i=0;i<arr_len-1;i++){
        //Comparing two elements and swapping if necessary
        for(int j=i+1;j<arr_len;j++){
            printf("Step %d: ",++step_count);
            //Printing
            print_array(x,arr_len,i,j);
            //Printing
            if( *(x+j)<*(x+i) ){ 
                swap((x+i),(x+j));
                printf("Swapped\n");
                print_array(x,arr_len,i,j);
            
            }
        }
    }
}

void print_array(int *x, int arr_len,int underline_ind_1, int underline_ind_2){
    for(int i=0;i<arr_len;i++){
        if(i==underline_ind_1 || i==underline_ind_2) printf("\033[4m%d\033[0m ",*(x+i));
        printf("%d ",*(x+i));
    }
    printf("\n");
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
