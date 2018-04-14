/*
    Usage: ./conversao <num> <base-entrada> <base-saida>

*/

#include <algorithm>   
#include <iostream>
#include <string>

std::string decimal2base( double &, int &);
int base2decimal( std::string &,int &);

std::string caracteres = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main(int argc, char *argv[]) {

    if(argc != 4) {
        std::cout << " Uso errado" << std::endl;
        return -1 ;
    }

    std::string input_number(argv[1]);
    int base_result, base_entrada = std::stoi(argv[2]), base_saida =  std::stoi(argv[3]);
    int aux_base = 10;
    double input;
    std::string result;


    if(base_entrada == aux_base)
    {
        input = std::stod(input_number);
        
        result = decimal2base(input, base_saida);

        std::cout << "("<< result << ")" << base_saida << std::endl;
    }

    else if(base_saida != aux_base)
    {
        
        input = base2decimal(input_number, base_entrada);

        result = decimal2base(input, base_saida);

        std::cout << "("<< result << ")" << base_saida << std::endl;

    }

    else
    {        
        base_result = base2decimal(input_number, base_entrada);
        
        std::cout << "("<< base_result << ")" << base_saida << std::endl; 
        
    }       

    return EXIT_SUCCESS;
}


std::string decimal2base( double &number_input, int &base_saida)
{
    std::string result;    

    auto num = number_input - (int)number_input;

    auto parte_inteira = (int)number_input;    

    if(parte_inteira == 0)
        result = std::to_string(parte_inteira);

    for(; parte_inteira >= 1; parte_inteira = parte_inteira / base_saida)      
        result += caracteres[parte_inteira % base_saida];
        
    std::reverse(result.begin(),result.end());

    if(num > 0)
    {
        result.append(",");

        while(num != 0)
        {
            num = num * 2;
            result.append(std::to_string((int)num));
            num = num - (int)num;                       
        }
        

    }  

    return result;

}

int base2decimal( std::string &input_number, int &base_entrada){

    int result = 0;

    size_t max = input_number.size()-1;

    // base_entrada = (base_entrada == 10) ? 2 : base_entrada;

    std::reverse(input_number.begin(),input_number.end());  

    for(size_t i = 0; i <= max; i++)
        result += caracteres.find(input_number[i]) * pow(base_entrada, i);  
            

    return result;

}
