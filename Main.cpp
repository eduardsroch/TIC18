#include <iostream>
#include <vector>
#include "Produto.h"
#include "Venda.h"

void incluirProduto(std::vector<Produto*>& produtos, int& proximoCodigo) {
    std::string nome;
    double preco;

    std::cout << "Nome do produto: ";
    std::cin.ignore();
    std::getline(std::cin, nome);
    std::cout << "Preço do produto: ";
    std::cin >> preco;

    Produto* novoProduto = new Produto(proximoCodigo, nome, preco);
    produtos.push_back(novoProduto);
    proximoCodigo++;
}

void excluirProduto(std::vector<Produto*>& produtos) {
    int codigo;
    std::cout << "Digite o código do produto a ser excluído: ";
    std::cin >> codigo;

    for (auto it = produtos.begin(); it != produtos.end(); ++it) {
        if ((*it)->getCodigo() == codigo) {
            delete *it;
            produtos.erase(it);
            std::cout << "Produto excluído com sucesso.\n";
            return;
        }
    }

    std::cout << "Produto não encontrado.\n";
}

void listarProdutos(const std::vector<Produto*>& produtos) {
    if (produtos.empty()) {
        std::cout << "Nenhum produto cadastrado.\n";
        return;
    }

    std::cout << "Lista de produtos:\n";
    for (const Produto* produto : produtos) {
        std::cout << "Código: " << produto->getCodigo() << " | Nome: " << produto->getNome()
                  << " | Preço: " << produto->getPreco() << std::endl;
    }
}

int main() {
    std::vector<Produto*> produtos;
    int proximoCodigo = 1;

    std::vector<Venda> vendas;

    while (true) {
        std::cout << "\nEscolha uma opção:\n";
        std::cout << "1. Incluir um produto\n";
        std::cout << "2. Excluir um produto\n";
        std::cout << "3. Listar todos os produtos\n";
        std::cout << "4. Realizar uma venda\n";
        std::cout << "5. Listar todas as vendas\n";
        std::cout << "6. Mostrar uma venda a partir de um código\n";
        std::cout << "7. Mostrar total faturado\n";
        std::cout << "8. Sair\n";

        int escolha;
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                incluirProduto(produtos, proximoCodigo);
                break;
            case 2:
                excluirProduto(produtos);
                break;
            case 3:
                listarProdutos(produtos);
                break;
            case 4: {
                Venda novaVenda;
                listarProdutos(produtos);

                while (true) {
                    int codigo, quantidade;
                    std::cout << "Digite o código do produto a ser vendido (0 para sair): ";
                    std::cin >> codigo;

                    if (codigo == 0) {
                        break;
                    }

                    bool encontrado = false;
                    for (const Produto* produto : produtos) {
                        if (produto->getCodigo() == codigo) {
                            encontrado = true;
                            std::cout << "Produto: " << produto->getNome() << " | Preço: " << produto->getPreco() << "\n";
                            std::cout << "Quantidade a ser vendida: ";
                            std::cin >> quantidade;
                            novaVenda.realizarVenda(produto, quantidade);
                        }
                    }

                    if (!encontrado) {
                        std::cout << "Produto não encontrado.\n";
                    }
                }

                if (!novaVenda.calcularTotalVenda()) {
                    std::cout << "Nenhuma venda realizada.\n";
                } else {
                    vendas.push_back(novaVenda);
                    std::cout << "Venda realizada com sucesso.\n";
                }

                break;
            }
            case 5:
                std::cout << "Listagem de vendas:\n";
                for (size_t i = 0; i < vendas.size(); ++i) {
                    std::cout << "Venda " << i + 1 << " - Total: " << vendas[i].calcularTotalVenda() << "\n";
                }
                break;
            case 6: {
                int codigoVenda;
                std::cout << "Digite o número da venda a ser visualizada: ";
                std::cin >> codigoVenda;

                if (codigoVenda >= 1 && static_cast<size_t>(codigoVenda) <= vendas.size()) {
                    std::cout << "Detalhes da venda " << codigoVenda << ":\n";
                    vendas[codigoVenda - 1].listarVenda();
                } else {
                    std::cout << "Venda não encontrada.\n";
                }
                break;
            }
            case 7: {
                double totalFaturado = 0.0;
                for (const Venda& venda : vendas) {
                    totalFaturado += venda.calcularTotalVenda();
                }
                std::cout << "Total faturado: " << totalFaturado << "\n";
                break;
            }
            case 8:
                
                for (Produto* produto : produtos) {
                    delete produto;
                }
                return 0;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    }
}
