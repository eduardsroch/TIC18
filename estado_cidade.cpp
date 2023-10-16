#include <iostream> 
#include <vector> 
#include <memory> 
 
class Estado { 
  private: 
    std::string nome; 
    std::string sigla; 
 
  public: 
    Estado(const std::string &nome, const std::string &sigla) : nome(nome), sigla(sigla) {} 
 
    std::string getNome() const { 
      return nome; 
    } 
 
    std::string getSigla() const { 
      return sigla; 
    } 
}; 
 
class Cidade { 
  private: 
    std::string nome; 
    std::shared_ptr<Estado> estado; 
 
  public: 
    Cidade(const std::string &nome, std::shared_ptr<Estado> estado) : nome(nome), estado(estado) {} 
 
    std::string getNome() const { 
      return nome; 
    } 
 
    std::shared_ptr<Estado> getEstado() const { 
      return estado; 
    } 
}; 

int main() { 
system("cls"); 

std::vector<std::shared_ptr<Estado>> estados; 
estados.push_back(std::make_shared<Estado>("Sao Paulo", "SP")); 
estados.push_back(std::make_shared<Estado>("Rio de Janeiro", "RJ")); 
estados.push_back(std::make_shared<Estado>("Minas Gerais", "MG")); 

std::vector<std::shared_ptr<Cidade>> cidades; 
cidades.push_back(std::make_shared<Cidade>("Sao Paulo", estados[0])); 
cidades.push_back(std::make_shared<Cidade>("Rio de Janeiro", estados[1])); 
cidades.push_back(std::make_shared<Cidade>("Belo Horizonte", estados[2])); 

for (const auto &estado : estados) { 
std::cout << estado->getNome() << std::endl; 
} 

for (const auto &cidade : cidades) { 
std::cout << cidade->getNome() << " - " << cidade->getEstado()->getNome() << std::endl; 
} 
return 0; 
} 