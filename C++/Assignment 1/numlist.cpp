#include<iostream>

using namespace std;

typedef struct numlist_s {
    int *list;
    int num;
} numlist_t;

void numlist_init(numlist_t *numlist) {
    numlist->list=NULL;
    numlist->num=0;
}

void numlist_add(numlist_t *numlist, int number){
    numlist->list = new int[number];
    numlist->num = number;
    for(int i = 0; i < number; i++) {
        int val;
        cout<<"\nEnter no. to add to list at index "<<i<<" : ";
        cin>>val;
        numlist->list[i] = val;
    }
}

int num_list_search(numlist_t *numlist, int target) {
    for(int i = 0; i < numlist->num; i++) {
        if(numlist->list[i] == target) {
            return i;
        }
    }
    return -1;
}

int num_list_delete(numlist_t *numlist, int target){
    int index=-1, del;
    for(int i = 0; i < numlist->num; i++) {
        if(numlist->list[i] == target){
            index = i;
            del = numlist->list[i];
        }
    }
    if(index != -1) {
        for(int i = index; i < numlist->num-1; i++) {
            numlist->list[i] = numlist->list[i+1];
        }
        numlist->num--;
        return del;
    }
    return index;
}

void num_list_copy(numlist_t *numlist, numlist_t *dup_numlist) {
    dup_numlist->list = new int[numlist->num];
    dup_numlist->num = numlist->num;
    for(int i = 0; i < numlist->num; i++) {
        dup_numlist->list[i] = numlist->list[i];
    }
}

void num_list_print(numlist_t *numlist) {
    for(int i = 0; i < numlist->num; i++) {
        cout<<numlist->list[i]<<" ";
    }
    cout<<endl;
} 

int main() {
    int size, search, del;
    numlist_t list;
    cout<<"Intitialising list...."<<endl;
    numlist_init(&list);
    cout<<"Enter no. of elements in the list: ";
    cin>>size;
    cout<<"\nAdd elements to the list - "<<endl;
    numlist_add(&list, size);
    cout<<"\nPrinting the list created - "<<endl;
    num_list_print(&list);
    cout<<"\nEnter element to be searched in the list: ";
    cin>>search;
    int index = num_list_search(&list, search);
    if(index == -1) {
        cout<<"\nElement not found in the list"<<endl;
    }
    else {
        cout<<"\nElement found at index: "<<index<<endl;
    }
    cout<<"\nEnter element to be deleted from the list: ";
    cin>>del;
    int ele = num_list_delete(&list, del);
    if(ele == -1) {
        cout<<"\nElement not in the list"<<endl;
    }
    else{
        cout<<"\nElement "<<ele<<" deleted"<<endl;
    }
    cout<<"\nPrinting list after deletion - "<<endl;
    num_list_print(&list);
    cout<<"\nCreating copy of the list....."<<endl;
    numlist_t duplist;
    num_list_copy(&list, &duplist);
    cout<<"\nPrinting copy of the list - "<<endl;
    num_list_print(&duplist);
    delete []list.list;
    delete []duplist.list;
    return 0;
}