/*
    Usage: ./conversao <num> <base-entrada> <base-saida>

*/

#include <algorithm>    
#include <iostream>
#include <string>


std::string decimal2base( int &, int &);
int base2decimal( std::string &,int &);

std::string caracteres = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main(int argc, char *argv[]) {

    if(argc != 4) {
        std::cout << " Use ./conversao <num> <base-entrada> <base-saida> " << std::endl;
        return -1 ;
    }

    std::string input_number(argv[1]);
    int base_result, base_entrada = std::stoi(argv[2]), base_saida =  std::stoi(argv[3]), input = 0;
    int aux_base = 10;
    std::string result;


    if(base_entrada == aux_base)
    {
        input = std::stoi(input_number);
        
        result = decimal2base(input, base_saida);

        std::cout << "("<< result << ")" << base_saida << std::endl;

        base_result = base2decimal(result, base_saida);

        std::cout << "("<< base_result << ")" << base_entrada << std::endl;
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


std::string decimal2base( int &input_number, int &base_saida)
{
    std::string result;    

    if(input_number == 0 || input_number == 1)
    {
        result = std::to_string(input_number);
        return result;
    }
       
    while(input_number >= 1) {   
        result += caracteres[input_number % base_saida];
        input_number = input_number / base_saida;
    };

    std::reverse(result.begin(),result.end());

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
