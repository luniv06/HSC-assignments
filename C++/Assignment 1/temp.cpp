#include <iostream>
using namespace std;
#define N 1000
typedef struct numlist_s
{
    int *list; //pointer to the numlist
    int num;  //length of the list

}numlist_t;

//function to allocate and initialise
void numlist_init(numlist_t *numlist)
{
    numlist->list=NULL;
    numlist->num=0;
}

//function to append to the list
void numlist_add(numlist_t *numlist,int number)
{
   numlist->list=new int[number];//dynamic allocation
   for(int i=0;i<number;i++)
   {
       int data;
       cout<<"Enter the element:";
       cin>>data;
       numlist->list[i]=data;//copying the value to the original list
   }
   
}

//function to print the list
void numlist_print(numlist_t *numlist){
    for(int i=0;i<numlist->num;i++){
        cout<<numlist->list[i]<<" ";
    }
    cout<<endl;
}

//function to search an element in the list
int numlist_search(numlist_t *numlist, int key)
{
    int flag=0;
    int key_index;
    for(int i=0;i<numlist->num;i++)
    {
        if(numlist->list[i]==key)
        {
            flag=1;
            key_index=i;
        }
    }
    
    if(flag)
        return key_index;
    else
        return -1;
}

//function to delete from the list
bool numlist_delete(numlist_t *numlist, int element)
{
    int element_index;
    int flag=0;
    for(int i=0;i<numlist->num;i++)
    {
        if(numlist->list[i]==element)
        {
            flag=1;
            element_index=i;
            break;
        }
    }
    
    //moving & shifting the values
    for(int j=element_index;j<numlist->num-1;j++){
        numlist->list[j]=numlist->list[j+1];
    }
    
    //reducing the length of the list-new length stored
    
    numlist->num = numlist->num - 1;
    return flag;
}

//function to create a deepcopy of the list
void numlist_copy(numlist_t *numlist,numlist_t *numlist_deepcopy)
{
    numlist_deepcopy->list=new int[numlist->num];//dynamic allocation
    numlist_deepcopy->num=numlist->num;//assigning length to the deepcopy
    for(int i=0;i<numlist->num;i++)
    {
        numlist_deepcopy->list[i] = numlist->list[i];//assigning elements to the deepcopy 
    }
}

//sorting of the list using selection sort
void numlist_sort(numlist_t *numlist)
{
    int i, j, min, temp;
    for (i = 0; i < numlist->num - 1; i++) {
      min = i;
      for (j = i + 1; j < numlist->num; j++)
      if (numlist->list[j] < numlist->list[min])
      min = j;
      temp = numlist->list[i];
      numlist->list[i] = numlist->list[min];
      numlist->list[min] = temp;
   }
}


int main()
{
    int value, search_value, search_index, delete_value, flag_delete;
    numlist_t List; 
    
    //allocate & initialise
    numlist_init(&List);
    
    cout<<"Determine the length of your Numlist:";
    cin>>value;
    List.num=value;
    
    //appending numbers
    numlist_add(&List,value);
    
    cout<<"Numlist:"<<endl;
    
    //printing numbers
    numlist_print(&List);
    
    cout<<endl;
    
    //sorted List
    numlist_sort(&List);
    
    cout<<"Sorted List:";
    numlist_print(&List);
    
    //searching a numbers
    cout<<"Enter the number to be searched:";
    cin>>search_value;
    search_index=numlist_search(&List,search_value);
    if(search_index==-1)
        cout<<"Element not present in the numlist."<<endl;
    else
        cout<<"Element found at index:"<<search_index<<endl;
    
    cout<<endl;
    
    //deleting a number
    cout<<"Enter the number to be deleted:";
    cin>>delete_value;
    flag_delete=numlist_delete(&List,delete_value);
    if(flag_delete)
        cout<<"Number deleted."<<endl;
    else
        cout<<"Number not found."<<endl;
    
    cout<<endl;
    
    cout<<"List after Manipulation:";
    numlist_print(&List);
    
    cout<<endl;
    
    //deep copy of the List
    numlist_t numlist_deepcopy;
    numlist_copy(&List,&numlist_deepcopy);
    cout<<"Deep copy of the numlist:";
    numlist_print(&numlist_deepcopy);
    
    //deallocating memory
    delete [] List.list;
    delete [] numlist_deepcopy.list;

    return 0;
}