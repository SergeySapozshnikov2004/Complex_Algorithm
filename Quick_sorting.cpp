#include "Addition_for_vector/ExtendedVector.cpp"

ExtendedVector quick_sort(ExtendedVector vector)
{
    ExtendedVector ret_vec = ExtendedVector();
    size_t index = vector.size() / 2;
    ret_vec.push_back(vector[index]);
    double elem = vector[index];
    vector.pop_by_index(index+1);
    ExtendedVector left_vec = vector.vector_less_val(elem);
    ExtendedVector right_vec = vector.vector_larger_val(elem);
    
    if (left_vec.num_unique_elem() < 3 and left_vec.size() < 3) 
    {
        ret_vec.push_front(left_vec);
    }
    else
    {
        left_vec = quick_sort(left_vec);  
        ret_vec.push_front(left_vec);
    }

    if (right_vec.num_unique_elem() < 3 and right_vec.size() < 3) 
    {
        ret_vec.push_back(right_vec);
    }
    else
    {
        right_vec = quick_sort(right_vec);  
        ret_vec.push_back(right_vec);  
    }

    return ret_vec;
}

int main()
{
    ExtendedVector v1 = ExtendedVector(1000);
    quick_sort(v1).print();
    return 0;
}