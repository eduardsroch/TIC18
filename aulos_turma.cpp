#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Aluno {
private:
  string nome;
  string numeroIdentificacao;
  static int ID;

public:
  int ano;
  int semestre;
  int sequencia;

  Aluno(const string& nome, int ano, int semestre, int sequencia) : nome(nome), ano(ano), semestre(semestre), sequencia(sequencia) {
    numeroIdentificacao = to_string(ano) + to_string(semestre) + to_string(sequencia);
    ID++;
  }

  void exibirDetalhes() {
    cout << "Nome: " << nome << endl;
    cout << "Ano: " << ano << endl;
    cout << "Semestre: " << semestre << endl;
    cout << "Sequencia: " << sequencia << endl;
    cout << "Numero de identificacao: " << numeroIdentificacao << endl;
  }
};

int Aluno::ID = 1000; 

class Turma {
private:
  vector<Aluno*> alunos;

public:
  void adicionarAluno(Aluno* aluno) {
    alunos.push_back(aluno);
  }

  void listarAlunos() {
    for (Aluno* aluno : alunos) {
      aluno->exibirDetalhes();
      cout << endl;
    }
  }
};

int main() {

  system("cls");

  Aluno aluno1("Arthur", 2023, 1, 1);
  Aluno aluno2("Nairan", 2023, 1, 2);

  Turma turma;

  turma.adicionarAluno(&aluno1);
  turma.adicionarAluno(&aluno2);

  turma.listarAlunos();

  return 0;
}