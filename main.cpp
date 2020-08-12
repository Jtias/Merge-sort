/* Implementation of Mergesort using C++ */
/*
    This program takes an array and divides it into two halves, then it takes each halves and sorts them respectively. 
    Then both of the sorted halves are merged together using the Merge function
*/
#include <iostream>
#include <stdlib.h>

using namespace std;

void MergeSort(int [], int, int);
void Merge(int [] , int, int, int);

int main()
{
   int List_size;
   cout<<"PLEASE INPUT THE SIZE OF THE LIST TO BE SORTED: ";
   cin>>List_size;
   int List[List_size];
   cout<<"PLEASE ENTER THE ELEMENTS IN THE LIST: ";
   for(int i=0;i<List_size;i++)
   {
       cin>>List[i];
   }
   MergeSort(List, 0, List_size - 1);

   cout <<"THE SORTED LIST IS: " << endl;
   for (int i = 0; i < List_size; i++)
       cout<<List[i]<<" ";
   cout << endl;
   
   return 0;
}

void Merge(int list[], int left, int mid, int right)
{
   int leftSize = mid - left + 1;
   int rightSize = right - mid;
   int i, j , k;
   // Initialize right and left half of the array
   int Left_half[leftSize], Right_half[rightSize];

   // Move the elements into the array created
   for (int i = 0; i < leftSize; i++)
       Left_half[i] = list[left + i];
   for (int j = 0; j < rightSize; j++)
       Right_half[j] = list[mid + 1 + j];
       
   i = 0;
   j = 0;
   k = left;
   while (i < leftSize && j < rightSize) {
       if (Left_half[i] <= Right_half[j]) {
           list[k] = Left_half[i];
           i++;
       }
       else {
           list[k] = Right_half[j];
           j++;
       }
       k++;
   }
   while (i < leftSize) {
       list[k] = Left_half[i];
       i++;
       k++;
   }
   while (j < rightSize) {
       list[k] = Right_half[j];
       j++;
       k++;
   }
}

void MergeSort(int list[], int left, int right)
{
   if (left < right) {
       int midpoint = left + (right - left) / 2;

       // Sort first and second halves
       
       MergeSort(list, left, midpoint);
       MergeSort(list, midpoint + 1, right);
       Merge(list, left, midpoint, right);
   }
}
