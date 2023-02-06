#include <iostream>
#include "TestesDataArt\Pessoa.hpp"

int main() {
	Pessoa p1{ "Joao", static_cast<unsigned long int>(11111111111), 20 };
	Pessoa p2{ "Maria" };
	std::cout << p1.getNome() << '\t' << p1.getIdade() << '\t' << p1.getCpf() << std::endl;
	std::cout << p2.getNome() << std::endl;
	return 0;
}