#include <cstddef>
#include <vector>

class ExtendedVector
{
    private: std::vector<double> vector;
    
    public:

ExtendedVector();

ExtendedVector(std::vector<double> vector);

/**
 * @brief Конструирует вектор из рандомных чисел, размерностью size
 * 
 * @param size 
 */
ExtendedVector(size_t size);

std::vector<double> get_vector();

void print();

void push_by_index(double elem, size_t index);

void push_front(double elem);

void push_back(double elem);

/**
 * @brief Вставляет значение входного вектора в начало исходного
 * 
 * @param left_vec входной вектор с одним значением
 */
void push_front(ExtendedVector left_vec);

/**
 * @brief Вставляет значение входного вектора в конец исходного
 * 
 * @param left_vec входной вектор с одним значением
 */
void push_back(ExtendedVector right_vec);

void pop_by_index(size_t index);

void pop_front();

void pop_back();

size_t size();

ExtendedVector vector_less_val(double value);

ExtendedVector vector_larger_val(double value);

double operator[](size_t index);

ExtendedVector& operator=(const ExtendedVector& other);

size_t num_unique_elem();

};