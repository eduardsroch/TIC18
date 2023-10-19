#include "Venda.h"
#include <iostream>

void Venda::realizarVenda(const Produto* produto, int quantidade) {
    produtosVendidos.push_back(produto);
    quantidades.push_back(quantidade);
}

double Venda::calcularTotalVenda() const {
    double total = 0.0;
    for (size_t i = 0; i < produtosVendidos.size(); ++i) {
        total += produtosVendidos[i]->getPreco() * quantidades[i];
    }
    return total;
}

void Venda::listarVenda() const {
    std::cout << "Produtos vendidos:\n";
    for (size_t i = 0; i < produtosVendidos.size(); ++i) {
        std::cout << "Código: " << produtosVendidos[i]->getCodigo() << " | Nome: " << produtosVendidos[i]->getNome()
                  << " | Quantidade: " << quantidades[i] << " | Preço Unitário: " << produtosVendidos[i]->getPreco()
                  << " | Subtotal: " << produtosVendidos[i]->getPreco() * quantidades[i] << std::endl;
    }
}
