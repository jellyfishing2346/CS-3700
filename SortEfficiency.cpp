// CS37 comparing sort algorithm efficiency

#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void simpleBubbleSort(int a[],int n){
for(int i=n-1;i>=0;i--){
for(int j=0;j<i;j++){
if(a[j]>a[j+1]){
int temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
}

void efficientBubbleSort(int arr[], int n)
{
int i, j;
bool swap;
for (i = 0; i < n-1; i++)
{
swap = false;
for (j = 0; j < n-i-1; j++)
{
if (arr[j] > arr[j+1])
{
int temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
swap = true;
}
}
  
if (swap == false)
break;
}
}

int main(){
int choice;
int size;
clock_t t;
double time_taken ;
int *best,*worst,*average;
  
do{
cout<<"1)Create New Data Sets\n";
cout<<"2)Run Comparison of Bubble Sorts\n";
cout<<"3)Quit\n";
cout<<"Enter choice : ";
cin >> choice;
  
switch(choice){
case 1:{
cout<<"Enter number of items in Data set : ";
cin>>size;
  
best = new int[size];
worst = new int[size];
average = new int[size];
  
for(int i=0;i<size;i++){
best[i] = i + 1000;
worst[i] = 1000 - i;
average[i] = rand()%1000;
}
break;
}
case 2:{
int *arr = new int[size];
cout<<"Regular bubble sort (No swap detector): \n";
for(int i=0;i<size;i++)arr[i] = best[i];
t = clock();
simpleBubbleSort(arr , size);
t = clock() - t;
time_taken = ((double)t)/CLOCKS_PER_SEC;
cout<<"best : "<<time_taken<<" seconds\n";
  
for(int i=0;i<size;i++)arr[i] = worst[i];
t = clock();
simpleBubbleSort(arr , size);
t = clock() - t;
time_taken = ((double)t)/CLOCKS_PER_SEC;
cout<<"worst : "<<time_taken<<" seconds\n";
  
for(int i=0;i<size;i++)arr[i] = average[i];
t = clock();
simpleBubbleSort(arr , size);
t = clock() - t;
time_taken = ((double)t)/CLOCKS_PER_SEC;
cout<<"average : "<<time_taken<<" seconds\n";
  
  
cout<<"Efficient bubble sort (with swap detector / break): \n";
for(int i=0;i<size;i++)arr[i] = best[i];
t = clock();
efficientBubbleSort(arr , size);
t = clock() - t;
time_taken = ((double)t)/CLOCKS_PER_SEC;
cout<<"best : "<<time_taken<<" seconds\n";
  
for(int i=0;i<size;i++)arr[i] = worst[i];
t = clock();
efficientBubbleSort(arr , size);
t = clock() - t;
time_taken = ((double)t)/CLOCKS_PER_SEC;
cout<<"worst : "<<time_taken<<" seconds\n";
  
for(int i=0;i<size;i++)arr[i] = average[i];
t = clock();
efficientBubbleSort(arr , size);
t = clock() - t;
time_taken = ((double)t)/CLOCKS_PER_SEC;
cout<<"average : "<<time_taken<<" seconds\n";
  
break;
}
  
case 3:{
cout<<"\nGood Bye!\n";
break;
}
default:{
cout<<"Invalid choice\n";
break;
}
}
  
}while(choice!=3);
  
return 0;
}
