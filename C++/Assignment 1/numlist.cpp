#include <iostream>
using namespace std;

typedef struct numlist_s {
    int *list;
    int num;
} numlist_t;

void numlist_init(numlist_t *numlist) {
    numlist = new numlist_t;
    numlist->list = NULL;
    numlist->num = 0;
}

void numlist_add(numlist_t *numlist, int number) {
    numlist_t *newNumList = new numlist_t;
    newNumList->list = NULL;
    newNumList->num = number;
    numlist->list = &newNumList->num;
    numlist = newNumList;
}

void num_list_print(numlist_t *numlist) {
    while (numlist->list != NULL) {
        cout << numlist->num;
    }
}
