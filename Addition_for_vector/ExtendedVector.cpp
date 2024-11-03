#include "ExtendedVector.h"
#include <cstddef>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

ExtendedVector::ExtendedVector()
{
    vector = {};
}

ExtendedVector::ExtendedVector(std::vector<double> vector)
{
    this->vector = vector;
}

ExtendedVector::ExtendedVector(size_t size)
{
    vector = {};
    for(size_t i = 0 ; i< size + 1; ++i) 
    {
        vector.push_back(rand() % size + 0); 
    } 
}

std::vector<double> ExtendedVector::get_vector()
{
    return vector;
}

void ExtendedVector::print()
{
    for(size_t i = 0; i < vector.size(); ++i)
    {
        std::cout << vector[i] << " ";
    }
    std::cout<<std::endl;
}

void ExtendedVector::push_by_index(double elem, size_t index)
{
    std::vector<double> ret_vec;
    for(size_t i = 0; i < index - 1; ++i)
    {
        ret_vec.push_back(vector[i]);
    }
    ret_vec.push_back(elem);

    for (size_t i = index - 1; i < vector.size(); ++i)
    {
        ret_vec.push_back(vector[i]);
    }
    vector = ret_vec;
}

void ExtendedVector::push_front(double elem)
{
    std::vector<double> ret_vec;
    ret_vec.push_back(elem);
    for(size_t i = 0; i < vector.size(); ++i)
    {
        ret_vec.push_back(vector[i]);
    }
    vector = ret_vec;
}

void ExtendedVector::push_back(double elem)
{
    std::vector<double> ret_vec;
    for(size_t i = 0; i < vector.size(); ++i)
    {
        ret_vec.push_back(vector[i]);
    }
    ret_vec.push_back(elem);
    vector = ret_vec;
}


void ExtendedVector::pop_by_index(size_t index)
{
    std::vector<double> ret_vec;
    for(size_t i = 0; i < index - 1; ++i)
    {
        ret_vec.push_back(vector[i]);
    }

    for (size_t i = index; i < vector.size(); ++i)
    {
        ret_vec.push_back(vector[i]);
    }
    vector = ret_vec;
}

void ExtendedVector::pop_front()
{
    std::vector<double> ret_vec;
    for(size_t i = 1; i < vector.size(); ++i)
    {
        ret_vec.push_back(vector[i]);
    }
    vector = ret_vec;
}

void ExtendedVector::pop_back()
{
    std::vector<double> ret_vec;
    for(size_t i = 0; i < vector.size() - 1; ++i)
    {
        ret_vec.push_back(vector[i]);
    }
    vector = ret_vec;
}

ExtendedVector ExtendedVector::vector_less_val(double value)
{
    std::vector<double> ret_vec = {};
    for(size_t i = 0; i < vector.size(); ++i)
    {
        if(vector[i] <= value)
        {
            ret_vec.push_back(vector[i]);
        }
    }
    return ExtendedVector(ret_vec);
}

ExtendedVector ExtendedVector::vector_larger_val(double value)
{
    std::vector<double> ret_vec = {};
    for(size_t i = 0; i < vector.size(); ++i)
    {
        if(vector[i] > value)
        {
            ret_vec.push_back(vector[i]);
        }
    }
    return ExtendedVector(ret_vec);
}

size_t ExtendedVector::size()
{
    return vector.size();
}

double ExtendedVector::operator[](size_t index)
{
    return vector[index];
}

ExtendedVector& ExtendedVector::operator=(const ExtendedVector& other) 
{
    if (this != &other) 
    {
        vector = other.vector;
    }
    
    return *this;
}

void ExtendedVector::push_front(ExtendedVector left_vec)
{   
    ExtendedVector ret_vec;
    for(size_t i = 0; i < left_vec.size(); ++i)
    {
        ret_vec.push_back(left_vec[i]);
    }

    for(size_t j = 0; j < vector.size(); ++j)
    {
        ret_vec.push_back(vector[j]);
    }
    vector = ret_vec.vector;
}

void ExtendedVector::push_back(ExtendedVector right_vec)
{   
    ExtendedVector ret_vec;
    for(size_t i = 0; i < vector.size(); ++i)
    {
        ret_vec.push_back(vector[i]);
    }

    for(size_t i = 0; i < right_vec.size(); ++i)
    {
        ret_vec.push_back(right_vec[i]);
    }
    vector = ret_vec.vector;
}

size_t ExtendedVector::num_unique_elem()
{
    std::set<int> uniqueElements(vector.begin(), vector.end());
    return uniqueElements.size();
}