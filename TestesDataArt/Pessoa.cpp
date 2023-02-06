#include "Pessoa.hpp"

Pessoa::Pessoa() {
}
Pessoa::Pessoa(std::string nomePessoa)
	:nome{ nomePessoa } {
}
Pessoa::Pessoa(std::string nomePessoa,
	unsigned short int idadePessoa)
	: nome{ nomePessoa },
	idade{ (unsigned char)idadePessoa }{
}
Pessoa::Pessoa(std::string nomePessoa,
	unsigned long cpfPessoa,
	unsigned short int idadePessoa)
	: Pessoa{ nomePessoa, idadePessoa } {
	if (validarCPF(cpfPessoa))
		cpf = cpfPessoa;
	else
		cpf = 0;
}

unsigned long Pessoa::getCpf() {
	//retorna uma cópia do cpf
	return cpf;
}

bool Pessoa::setCpf(unsigned long novoCpf) {
	if (validarCPF(novoCpf)) {
		cpf = novoCpf;
		return true;
	}
	return false;
}

std::string Pessoa::getNome() {
	return nome;
}

void Pessoa::setNome(std::string novoNome) {
	nome = novoNome;
}

unsigned short int Pessoa::getIdade() {
	return (unsigned short int)idade;
}

void Pessoa::setIdade(unsigned short int novaIdade) {
	idade = (unsigned char)novaIdade;
}

bool Pessoa::validarCPF(unsigned long cpfTeste) {
	int somatorioValidaUltimo;
	int modulo;
	int somatorioValidaPenultimo = 0;
	int ultimo = cpfTeste % 10;
	cpfTeste = cpfTeste / 10;
	int penultimo = cpfTeste % 10;
	cpfTeste = cpfTeste / 10;
	somatorioValidaUltimo = penultimo * 2;
	for (int i = 2; i <= 11; i++) {
		modulo = cpfTeste % 10;
		cpfTeste = cpfTeste / 10;
		somatorioValidaPenultimo += modulo * i;
		somatorioValidaUltimo += modulo * (i + 1);
	}
	modulo = somatorioValidaPenultimo % 11;
	if (modulo < 2) {
		if (!penultimo) return false;//cpf invalido
	}
	else {
		if (penultimo != 11 - modulo) return false;//cpf invalido
	}
	modulo = somatorioValidaUltimo % 11;
	if (modulo < 2) {
		if (!ultimo) return false;//cpf invalido
	}
	else {
		if (ultimo != 11 - modulo) return false;//cpf invalido
	}
	return true;//cpf valido
}
