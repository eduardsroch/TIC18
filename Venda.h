#ifndef VENDA_H
#define VENDA_H

#include <vector>
#include "Produto.h"

class Venda {
public:
    void realizarVenda(const Produto* produto, int quantidade);
    double calcularTotalVenda() const;
    void listarVenda() const;

private:
    std::vector<const Produto*> produtosVendidos;
    std::vector<int> quantidades;
};

#endif
