#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

int read_table(const std::string, std::vector<double> &, std::vector<double> &);
double lagrange(const std::vector<double> &, const std::vector<double> &, const double &);

int main(int argc, char *argv[])
{
    if(argc != 2) {
        std::cout << " Error, please use ./[programmin] [arq name]" << std::endl;
        return EXIT_FAILURE ;
    }

    std::string name = argv[1];

    std::vector<double> x, fx;

    double interpolation_value;

    if (read_table(name, x, fx) != 0)
        return EXIT_FAILURE;

    std::cout << "Enter the value to be interpolated " << std::endl;
    
    std::cin >> interpolation_value;

    std::cout << "O valor sera: " << lagrange(x, fx, interpolation_value) << " para x = " << interpolation_value << std::endl;

    return EXIT_SUCCESS;

}

int read_table(const std::string name, std::vector<double> &x, std::vector<double> &fx )
{
    std::ifstream file;
    
    std::string line;

    int input_x, input_fx;

    file.open(name);		

    if (!file)
    {   
        std::cout << "Error while opening file!" << std::endl;
        return -1 ;
    }

    while (std::getline(file, line))
    {
        std::istringstream iss(line);

        if (!(iss >> input_x >> input_fx)) 
        {
             return -1; 
        } 

        x.push_back(input_x);

        fx.push_back(input_fx);       
    }

    return 0;

}

double lagrange(const std::vector<double> &x, const std::vector<double> &fx, const double &interpolation_value)
{
    double p, r = 0;

    for (int i = 0; i < x.size(); i++)
    {
        p = fx[i];

        for(int j = 0; j < x.size(); j++)
        {
            if(i != j)
                p = p * ((interpolation_value - x[j])/(x[i] - x[j]));
            
        }

        r = r + p;
    }

    return r;
}
