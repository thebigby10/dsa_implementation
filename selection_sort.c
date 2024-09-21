//Selection sort is to determine a place and get the item for that place
//Input: X as the array that will be sorted
//Output: Every step of selection sort algorithm
#include<stdio.h>

void swap(int *x, int *y);
void selectionSort(int *x,int arr_len);
int find_min_val_ind(int *x, int start_ind, int end_ind);

int main(){
    int x[] = {1,6,3,2,8,3,1,1,10,100,0,-1};
    int arr_len = 12;
    selectionSort(x,arr_len); //Argument: reference of x and the length of the array
    printf("\033[4mSorted Array:\033[0m\n");
    for(int i=0;i<12;i++) printf("%d ", *(x+i)); 
    return 0;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int find_min_val_ind(int *x, int start_ind, int end_ind){
    int min_val_ind = start_ind;
    for(int i=start_ind+1;i<=end_ind;i++) if(*(x+i)<*(x+min_val_ind)) min_val_ind = i;
    return min_val_ind;
}

void selectionSort(int *x,int arr_len){
    int stepCount = 0;
    for(int i=0;i<arr_len-1;i++){
        int min_val_ind = find_min_val_ind(x,i,arr_len-1); // This determines the index of the minimum value
        for(int j=i+1;j<arr_len;j++) if(*(x+j)<*(x+min_val_ind)) min_val_ind = j;
        //Printing
        printf("\033[4mStep %d:\n\033[0m",++stepCount);
        for(int j=0;j<arr_len;j++){
            if(j==i)
                printf("\033[4m%d\033[0m ",*(x+j));
            else
                printf("%d ",*(x+j));
        }
        printf("\nMin value %d will be swapped at position : %d\n",*(x+min_val_ind),i+1);
        //Swapping
        //swapping the min value with the position
        swap((x+i),(x+min_val_ind));
        //Swapping
        for(int j=0;j<arr_len;j++){
            if(j==i)
                printf("\033[4m%d\033[0m ",*(x+j));
            else
                printf("%d ",*(x+j));
        }
        printf("\n");
        //Printing
    }
}

