#include <vector>
#include "ExtendedVector.cpp"
#include <iostream>

int main()
{
    ExtendedVector v1 = ExtendedVector({1,5,3,6});
    v1.print();
    v1.pop_by_index(2);
    v1.print();
    // v1.push_front(99);
    // v1.print();
    // v1.push_by_index(123,4);
    // v1.print();
    // v1.pop_front();
    // v1.print();
    // std::cout<< v1[2];
    // ExtendedVector v2 = ExtendedVector({1});
    // v2 = v1;
    // ExtendedVector v2 = ExtendedVector({111,222,333});
    // v2.print();
    // v1.push_front(v2);
    // v1.print();
    // ExtendedVector v_rand = ExtendedVector(10);
    // v_rand.print();
    // ExtendedVector v_3 = ExtendedVector({1,3,1,3});
    // std::cout << v_3.num_unique_elem();
    return 0;
}