/* This file implements queue data structure. Array is used for implemetation. we have also provided driver main function 
which will call different API. ONe sample Input is 
Sample Input

5  
1 4  
1 9  
3  
2 4  
3  
Sample Output

4  
9 
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* Heap API */
int *szpointer;
int parent(int i)
{
    if(i==1)
        return i;
    else
        return (i/2);
}

int Lchild(int i)
{
    if((*szpointer)>=(2*i))
        return (2*i);
    else
        return -1;
}

int Rchild(int i)
{
    if((*szpointer)>=(2*i+1))
        return (2*i+1);
    else
        return -1; 
}

void swp(int arr[], int ind1, int ind2)
{
    arr[ind1] = arr[ind1] + arr[ind2];
    arr[ind2] = arr[ind1] - arr[ind2];
    arr[ind1] = arr[ind1] - arr[ind2];
}

void heapify(int arr[], int index)
{
    if(arr[index] < arr[parent(index)])
    {
        swp(arr, index, parent(index));
        heapify(arr, parent(index));
    }
}

void insert(int arr[], int *sz, int data)
{
    *sz = *sz + 1;
    arr[*sz] = data;
    heapify(arr, *sz);
}

void percolate_down(int arr[], int index)
{
    int min = index;
    if(Lchild(index)!=-1 && arr[Lchild(index)] < arr[index])
    {
        min = Lchild(min);
    }
    if(Rchild(index)!=-1 && arr[Rchild(index)] < arr[min])
    {
        min = Rchild(index);
    }
    if(min!=index)
    {
        swp(arr, index, min);
        percolate_down(arr, min);
    }
}

void heap_delete(int arr[], int *sz, int item)
{
    int i;
    for(i=1; i<=*sz; i++)
    {
        if(arr[i]==item)
            break;
    }
    swp(arr, i, *sz);
    *sz = *sz - 1;
    percolate_down(arr, i);
}

void print_heap(int arr[], int sz)
{
    int i;
    for(i=1; i<=sz; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int heap[100002]; /* heap will start from index 1*/
    int sz = 0;
    szpointer = &sz;
    int n,i, option, a;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>option;
        switch(option)
        {
            case 1:
                cin>>a;
                insert(heap, &sz, a);
                break;
            case 2:
                cin>>a;
                heap_delete(heap, &sz, a);
                break;
            case 3:
                cout<<heap[1]<<"\n";
                break;
            default:
                break;
                
        }
        //print_heap(heap, sz); /**you can use this function for debugging purpose /
    }
    return 0;
}
