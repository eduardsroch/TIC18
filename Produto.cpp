#include "Produto.h"

Produto::Produto(int codigo, const std::string& nome, double preco) : codigo(codigo), nome(nome), preco(preco) {}

int Produto::getCodigo() const {
    return codigo;
}

const std::string& Produto::getNome() const {
    return nome;
}

double Produto::getPreco() const {
    return preco;
}
