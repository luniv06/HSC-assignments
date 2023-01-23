#include <iostream>

using namespace std;

typedef struct point_s {
    int x;
    int y;
    int z;
    void print() {
        cout << "x: " << x << " y: " << y << " z: " << z << endl;
    }
} point_t;

void increment_using_pointer(point_t *ptr) {
    ptr->x++;
    ptr->y++;
    ptr->z++;
}

void increment_using_reference(point_t *ptr) {
    ptr->x++;
    ptr->y++;
    ptr->z++;
}

int main() {
    point_t *obj1 = new point_t;
    obj1->x = 1;
    obj1->y = 2;
    obj1->z = 3;
    cout << "Using pointer to structure: " << endl;
    cout << "before increment" << endl;
    obj1->print();
    increment_using_pointer(obj1);
    cout << "after increment" << endl;
    obj1->print();
    cout << endl;
    point_t obj2;
    obj2.x = 4;
    obj2.y = 5;
    obj2.z = 6;
    cout << "Using reference to structure: " << endl;
    cout << "before increment" << endl;
    obj2.print();
    increment_using_reference(&obj2);
    cout << "after increment" << endl;
    obj2.print();
}