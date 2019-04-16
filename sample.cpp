#include<iostream>
#include<climits>
using namespace std;
class binaryheap{
public:
int root;
int*arr;
int capasity,heapsize;
//constructor
binaryheap(int cap){
  heapsize=0;
  capasity=cap;
  arr=new int[cap];
  root=0;
}
int parent(int i){
return (i-1)/2;
 }
 int left(int i){
    return 2*i+1;
 }
 int right(int i){

    return 2*i+2;
 }
 //function to swap two values
 void swap(int*x,int*y){
int temp=*x;
*x=*y;
*y=temp;
}

void insert(int value){
if(heapsize>=capasity){
    cout<<"over flow";
    return;
}
heapsize++;

int i=heapsize-1;
arr[i]=value;
while(i!=0 && arr[parent(i)]>arr[i]){
    swap(&arr[i],&arr[parent(i)]);
    i=parent(i);
}
}
//function to decrease the value
void decrease(int i,int newval){
arr[i]=newval;
while(i!=0 && arr[parent(i)] > arr[i]){
    swap(&arr[parent(i)],&arr[i]);
    i=parent(i);
}
}



void heapify(int i){
int l=left(i);
int r=right(i);
int smallest=i;
if(l<heapsize && arr[l]<arr[i])
    smallest=l;
if(r<heapsize && arr[r]<arr[smallest])
    smallest=r;
if(smallest!=i){
    swap(&arr[i],&arr[smallest]);
    heapify(smallest);
}
}/*
void heapify(int value){
int i=0;
while (i!=heapsize && value>arr[i]){
    swap(&value,&arr[i]);
    i=2*i+1;
}
}*/





//method to remove minimum element from heap
int extractmin(){
if(heapsize<=0){return 0;}
if(heapsize==1){
    heapsize--;
    return arr[0];
}
//store and remove it
int root=arr[0];
arr[0]=arr[heapsize-1];
heapsize--;
heapify(0);
return root;
}

//function to delete element from the the binary heap
void Delete(int index){
decrease(index,-1);//minimum element
heapify(index);
extractmin();
cout<<endl;
}

void display(){
for(int i=0;i<heapsize;i++){
    cout<<" "<<arr[i]<<" ";
}
cout<<endl;
}


//function to get the minimum value of array
int getmin(){
return arr[0];
}
/*/2d display
void D2ddisplay(int i,int space,int heapsize){
if(i==heapsize-1){
heapsize--;
return;
}
cout<<arr[i];
space++;
for(int j=0;j<=space;j++){
    cout<<"  ";
}
cout<<endl;
if(i<=heapsize-1){
D2ddisplay(arr[right(i)],space);
D2ddisplay(arr[left(i)],space,heapsize-1);
}
}
*/
};






int main(){
binaryheap b(1000);
for(int i=10;i>0;i--){

b.insert(i);
}
b.display();
/*for(int j=0;j<b.heapsize;j++){
    cout<<b.arr[j];
}*/
cout<<endl;
cout<<b.extractmin()<<endl;
cout<<endl<<" the minimum element of array is "<<b.getmin()<<endl;
cout<<endl;
b.display();
b.Delete(0);
b.display();
b.display();
//b.D2ddisplay(0,0,11);
return 0;
}
