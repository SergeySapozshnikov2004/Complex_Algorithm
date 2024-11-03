#include "Matrix/Matrix.cpp"
#include <cstddef>
#include <random>
#include <vector>

/**
 * @brief выводит нулевую матрицу заданной размерности
 * 
 * @param size 
 * @return std::vector<std::vector<double>> 
 */
std::vector<std::vector<double>> get_zero_matrix(size_t size)
{
    std::vector<std::vector<double>> matrix;
    for(size_t i = 0; i < size; ++i)
    {
        matrix.push_back({});
        for(size_t j = 0; j < size; ++j)
        {
            matrix[i].push_back(0);
        }
    }
    return matrix;
}

/**
 * @brief выдаёт слуачайную матрицу неориентированного графа, заданной размерности
 * 
 * @param size 
 * @return Matrix 
 */
Matrix get_matrix_undirected_graph(size_t size)
{
    std::vector<std::vector<double>> ret_matrix = get_zero_matrix(size);
    for(size_t i = 0; i < size; ++i)
    {
        for(size_t j = 0; j < size; ++j)
        {
            if (i == j)
            {
                ret_matrix[i][j] = 0;
            }
            else
            {
                std::random_device dev;
                std::mt19937 rng(dev());
                std::uniform_int_distribution<std::mt19937::result_type> dist(1,100);
                double a = dist(rng);
                if (a > 71)
                {
                    a = std::numeric_limits<double>::max();
                }
                ret_matrix[i][j] = a;
                ret_matrix[j][i] = a;
            }
        }
    }
    return Matrix(ret_matrix);
}

/**
 * @brief делает матрицу оптимальных путей
 * 
 * @param D_0 матрица случайного неориентированного графа
 * @return Matrix матрица оптимальных путей
 */
Matrix dijstra_optimum_matrix(Matrix D_0)
{
    std::vector<std::vector<double>> D = D_0.get_matrix();
    std::vector<std::vector<double>> D_1;
    for(size_t i_0 = 0; i_0 < D.size(); ++i_0)
    {
        for(size_t i = 0; i < D.size(); ++i)
        {
            D_1.push_back({});
            for(size_t j = 0; j < D[0].size(); ++j)
            {
                D_1[i].push_back(std::min(D[i][j], D[i][i_0] + D[i_0][j]));
            }
        }
        D = D_1;
        D_1.clear();
    }
    return D;
}

/**
 * @brief выдаёт минимальное расстояние из вершины i в вершину j
 * 
 * @param D_opt матрица неориентированного графа
 * @param i вершина отправки
 * @param j вершина завершения
 * @return double way кратчайший путь
 */
double dijstra_optimum_way(Matrix D_opt, size_t i, size_t j)
{
    std::vector<std::vector<double>> D = dijstra_optimum_matrix(D_opt).get_matrix();
    return D[i-1][j-1];
}


int main()
{
    const double inf = std::numeric_limits<double>::max();
    Matrix D_0 = Matrix({{0,70,50,inf},{70,0,inf,15},{50,inf,0,130},{inf,15,130,0}});
    // D_0.print();
    // Matrix D_1 = dijstra_optimum_matrix(D_0);
    // D_1.print();
    // Matrix m_test = get_matrix_undirected_graph(4);
    // m_test.print();
    // dijstra_optimum_matrix(m_test).print();

    std::cout << dijstra_optimum_way(D_0, 2,3);
    return 0;
}