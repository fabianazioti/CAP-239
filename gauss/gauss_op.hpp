/**
 * 
 * Resolucao de Sistemas de Equacoes Lineares utilizando o Metodo de Gauss
 * 
 * Disciplina CAP - 239: Matematica Computacional I do Institudo Nacional de Pesquisas Espaciais
 * 
 * \date 2018
 *
 * \copyright GNU Lesser Public License version 3
 * 
 **/


#ifndef __GAUSS_OP_HPP__
#define __GAUSS_OP_HPP__

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

double determinant_system(const std::vector<std::vector<double>> &, const int &, const int &);
void solving_system(const std::vector<std::vector<double>> &, const int &, const int &);
void pivot_strategy(std::vector<std::vector<double>> &, const int &, const int &, const int &, const int &);
int stagger_matrix(std::vector<std::vector<double>> &, const int &, const int &);
void print_matrix(const std::vector<std::vector<double>> &, const int &, const int &);
int read_matrix(std::string name, std::vector<std::vector<double>> &);

#endif
