#include <iostream> 
#include <vector> 
 
std::vector<int> Buble(std::vector<int> array) 
{ 
 
for(size_t i_0 = 0; i_0 < array.size(); ++i_0) 
    { 
        for(size_t i = 0; i < array.size() - 1; ++i) 
        { 
            if (array[i] > array[i+1]) 
            { 
                int a = array[i]; 
                array[i] = array[i+1]; 
                array[i+1] = a; 
            } 
        } 
    } 
    return array; 
} 
 
int main() 
{ 

    std::vector<int> array; 
    for(size_t i = 0 ; i< 10000; ++i) 
    { 
        array.push_back(rand() % 9999 + 0); 
    } 

    std::vector<int> return_array; 
    return_array = Buble(array); 


    std::cout << std::endl; 

    for(size_t i = 0; i < array.size(); ++i) 
    { 
        std::cout<<return_array[i] << " "; 
    } 
    return 0; 
}