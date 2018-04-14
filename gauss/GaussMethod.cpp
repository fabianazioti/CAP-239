#include "gauss_op.h"

/**
 * 
 * using ./solvin matriz.txt 3 4
 * 
 * */

int main(int argc, char *argv[]) 
{
    if(argc != 4) {
        std::cout << " Error, please use ./[programmin] [tam_i] [tam_j]" << std::endl;
        return EXIT_FAILURE ;
    }

    std::string name = argv[1];

    const int tam_i = std::stoi(argv[2]);
    const int tam_j = std::stoi(argv[3]);

    std::vector <std::vector<double> > matrix(tam_i, std::vector<double>(tam_j));

    if (read_matrix(name, matrix) != 0)
        return EXIT_FAILURE;

    print_matrix(matrix, tam_i, tam_j); 

    if (stagger_matrix(matrix, tam_i, tam_j) != 0)
        return EXIT_FAILURE;
    
    std::cout << "Stepped Matrix : " << std::endl;

    print_matrix(matrix,tam_i, tam_j);

    std::cout << "Solved System : " << std::endl;

    solving_system(matrix, tam_i, tam_j);

    std::cout << "Determinant: " << determinant_system(matrix, tam_i, tam_j) << std::endl;

    return EXIT_SUCCESS;
    
}

double determinant_system(const std::vector<std::vector<double>> &matrix, const int &tam_i, const int &tam_j)
{
    double result_determinant = 1;

    for(size_t i = 0; i < tam_i; i++)
    {
        for(size_t j = 0; j < tam_j; j++)
        {
            if(i == j)
                result_determinant *= matrix[i][j];
        }
    }

    return result_determinant;

}

void solving_system(const std::vector<std::vector<double>> &matrix, const int &tam_i, const int &tam_j)
{
    std::vector<double> x(tam_j - 1);
    
    double s;

    x[(tam_j-1)-1] = matrix[tam_i-1][tam_j-1] / matrix[tam_i-1][tam_j-2];
    
    for(int i = (tam_i-1)-1; i >= 0; i--)
    {   
        s = 0;

        for(int j = i+1; j < tam_j-1; j++)
            s += matrix[i][j] * x[j];

        x[i] = (matrix[i][tam_j-1] - s)/matrix[i][i];

    }

    for(int i = 0; i < tam_j-1; i++)
    {
        std::cout << "x[" << i << "] = " << x[i] << std::endl; 
    }

}


void pivot_strategy(std::vector<std::vector<double>> &matrix, const int &tam_i, const int &tam_j,
                    const int &i_column, const int &j_column)
{
    int aux_i = i_column + 1;

    for(; aux_i < tam_i; aux_i++)
    {
        if(matrix[aux_i][j_column] != 0)
        {
            for(int j = 0; j < tam_j; j++)
                std::swap(matrix[aux_i][j], matrix[i_column][j]);

            return;           

        }
    }


}

int stagger_matrix(std::vector<std::vector<double>> &matrix, const int &tam_i, const int &tam_j)
{
    int i = 1, j, pivo_i = 0, pivo_j;

    double pivo;

    for(pivo_j = 0; pivo_j < tam_j; pivo_j++)
    {
            for(; i < tam_i; i++)
            {
                if(matrix[pivo_i][pivo_j] == 0)
                    pivot_strategy(matrix, tam_i, tam_j, pivo_i, pivo_j);
                    
                pivo = matrix[i][pivo_j] / matrix[pivo_i][pivo_j];
                
                for(j = 0; j < tam_j; j++)
                    matrix[i][j] = matrix[i][j] - (pivo * matrix[pivo_i][j]);
                            
            }

            pivo_i++;

            i = pivo_i + 1;        
    }

    return 0;
        
}

void print_matrix(const std::vector<std::vector<double>> &matrix, const int &tam_i, const int & tam_j)
{
    for(size_t i = 0; i < tam_i; i++)
    {
        for(size_t j = 0; j < tam_j; j++)
            std::cout << matrix[i][j] << "\t";

        std::cout << "\n";
    }
}

int read_matrix(std::string name, std::vector<std::vector<double>> &matrix)
{
    std::ifstream file;

    file.open(name);		

    if (!file)
    {   
        std::cout << "Error while opening file!" << std::endl;
        return -1 ;
    }

    for(size_t i = 0; i < matrix.size(); i++)
    {
        for(size_t j = 0; j < matrix[i].size(); j++)
            file >> matrix[i][j];
    }
    
    file.close();

    return 0;


}
