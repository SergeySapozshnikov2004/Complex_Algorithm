#include <cstddef>
#include <iostream>
#include <vector>

void vec_print(std::vector<int> vec)
{
    for(size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout<<std::endl;
}

std::vector<int> push_by_index(std::vector<int> vec,int elem, size_t index)
{
    std::vector<int> ret_vec;
    for(size_t i = 0; i < index; ++i)
    {
        ret_vec.push_back(vec[i]);
    }
    ret_vec.push_back(elem);

    for (size_t i = index; i < vec.size(); ++i)
    {
        ret_vec.push_back(vec[i]);
    }

    return ret_vec;

}

std::vector<int> pop_front(std::vector<int> vec)
{
    std::vector<int> ret_vec;
    for(size_t i = 1; i < vec.size(); ++i)
    {
        ret_vec.push_back(vec[i]);
    }
    return ret_vec;
}

std::vector<int> insert_sort(std::vector<int> vec)
{
    std::vector<int> unsort_vec = vec;
    std::vector<int> sort_vec;

    sort_vec.push_back(unsort_vec[0]);

    for(size_t i = 1; i < vec.size(); ++i)
    {
        size_t size = sort_vec.size();
        for(size_t j = 0; j < size; ++j)
        {
            if(unsort_vec[i] <= sort_vec[j])
            {
                sort_vec = push_by_index(sort_vec,unsort_vec[i],j);
                break;
            }
            else 
            {
                if (j == sort_vec.size() - 1)
                {
                    sort_vec.push_back(unsort_vec[i]);
                }
            }
        }
    }
    return sort_vec;


}

int main()
{
    std::vector<int> vec; 
    for(size_t i = 0 ; i< 10000; ++i) 
    {
        vec.push_back(rand() % 9999 + 0); 
    } 

    vec = insert_sort(vec);
    vec_print(vec);

    return 0;
}