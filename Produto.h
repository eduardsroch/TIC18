#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

class Produto {
public:
    Produto(int codigo, const std::string& nome, double preco);
    int getCodigo() const;
    const std::string& getNome() const;
    double getPreco() const;

private:
    int codigo;
    std::string nome;
    double preco;
};

#endif
