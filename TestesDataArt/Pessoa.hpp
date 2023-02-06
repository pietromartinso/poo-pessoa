#pragma once

#include <string>

class Pessoa
{
public:
	Pessoa();
	Pessoa(std::string nomePessoa);
	Pessoa(std::string nomePessoa,
		unsigned short int idadePessoa);
	Pessoa(std::string nomePessoa,
		unsigned long cpfPessoa,
		unsigned short int idadePessoa);

	unsigned long getCpf();
	bool setCpf(unsigned long novoCpf);

	std::string getNome();
	void setNome(std::string novoNome);

	unsigned short int getIdade();
	void setIdade(unsigned short int novaIdade);

private:
	bool validarCPF(unsigned long cpfTeste);
	std::string nome;
	unsigned long cpf;
	unsigned char idade;
};

