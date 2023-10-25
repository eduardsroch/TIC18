#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Paciente
{
private:
    string cpf;
    string nome;
    string data;

public:
    // Construtor da classe Paciente
    Paciente(string _cpf, string _nome, string _data) : cpf(_cpf), nome(_nome), data(_data) {}
    string getNome() // Métodos para acessar e modificar os atributos
    {
        return nome;
    }
    string getCpf()
    {
        return cpf;
    }
    string getData()
    {
        return data;
    }
    void setNome(string _nome)
    {
        nome = _nome;
    }
    void setCpf(string _cpf)
    {
        cpf = _cpf;
    }
    void setData(string _data)
    {
        data = _data;
    }
};

class Medico
{
private:
    string crm;
    string nome;
    string especialidade;

public:
    // Construtor da classe Medico
    Medico(string _crm, string _nome, string _especialidade) : crm(_crm), nome(_nome), especialidade(_especialidade) {}
    string getCrm() // Métodos para acessar e modificar os atributos
    {
        return crm;
    }
    string getNome()
    {
        return nome;
    }
    string getEspecialidade()
    {
        return especialidade;
    }
    void setCrm(string _crm)
    {
        crm = _crm;
    }
    void setNome(string _nome)
    {
        nome = _nome;
    }
    void setEspecialidade(string _especialidade)
    {
        especialidade = _especialidade;
    }
};

class Consulta
{
private:
    string crm;
    string cpf;
    string data;
    string hora;
    string duracao;
    string realizada;
    string convenio;

public: // Construtor da classe Consulta
    Consulta(string _cpf, string _crm, string _data, string _hora, string _duracao, string _convenio)
        : crm(_crm), cpf(_cpf), data(_data), hora(_hora), duracao(_duracao), convenio(_convenio), realizada("n") {}

    string getConvenio() // Métodos para acessar e modificar os atributos
    {
        return this->convenio;
    }
    string getCPFPaciente()
    {
        return this->cpf;
    }

    string getCRMMedico()
    {
        return this->crm;
    }

    string getData()
    {
        return data;
    }

    string getHora()
    {
        return hora;
    }

    string getDuracao()
    {
        return duracao;
    }

    string getRealizada()
    {
        return realizada;
    }

    void setRealizada(string _realizada)
    {
        realizada = _realizada;
    }
    void setConvenio(string _convenio)
    {
        convenio = _convenio;
    }

    void setData(string _data)
    {
        data = _data;
    }

    void setHora(string _hora)
    {
        hora = _hora;
    }

    void setDuracao(string _duracao)
    {
        duracao = _duracao;
    }
};
// Vetores para armazenar pacientes, médicos e consultas
vector<Consulta> consultas;
vector<Paciente> pacientes;
vector<Medico> medicos;

void incluirPaciente() // Funções para a gestão de pacientes
{
    string nome, data, cpf;

    cout << "Nome do paciente: ";
    cin.ignore(); // Limpar o buffer de entrada
    getline(cin, nome);
    cout << "CPF do paciente: ";
    cin >> cpf;
    cout << "Data de nascimento (DD/MM/AAAA): ";
    cin >> data;
    pacientes.push_back(Paciente(cpf, nome, data));
    cout << "Paciente incluido com sucesso." << endl;
}

void excluirPaciente()
{
    string cpf;
    cout << "Digite o CPF do paciente a ser excluido: ";
    cin >> cpf;
    for (auto it = pacientes.begin(); it != pacientes.end();)
    {
        if (it->getCpf() == cpf)
        {
            it = pacientes.erase(it);
            cout << "Paciente excluido com sucesso." << endl;
        }
        else
        {
            ++it;
        }
    }
}

void alterarPaciente()
{
    string cpf;
    cout << "CPF do paciente a ser alterado: ";
    cin >> cpf;
    for (auto &paciente : pacientes)
    {
        if (paciente.getCpf() == cpf)
        {
            cout << "Dados atuais do paciente: " << endl;
            cout << "Nome: " << paciente.getNome() << endl;
            cout << "Data de Nascimento: " << paciente.getData() << endl;
            string novoNome, novaData;
            char escolha;

            cout << "Deseja alterar o Nome (S/N)? ";
            cin >> escolha;
            if (escolha == 'S' || escolha == 's')
            {
                cout << "Novo Nome ";
                cin.ignore();
                getline(cin, novoNome);
                paciente.setNome(novoNome);
            }

            cout << "Deseja alterar a Data de Nascimento (S/N)? ";
            cin >> escolha;
            if (escolha == 'S' || escolha == 's')
            {
                cout << "Nova Data de Nascimento (DD/MM/AAAA): ";
                cin >> novaData;
                paciente.setData(novaData);
            }
            cout << "Paciente alterado com sucesso." << endl;
            return;
        }
    }
    cout << "Paciente nao encontrado." << endl;
}

void listarPacientes()
{
    if (pacientes.empty())
    {
        cout << "Nenhum paciente cadastrado." << endl;
        return;
    }

    for (Paciente &paciente : pacientes)
    {
        cout << "Nome: " << paciente.getNome() << endl;
        cout << "CPF: " << paciente.getCpf() << endl;
        cout << "Data de Nascimento: " << paciente.getData() << endl;
        cout << endl;
    }
}

void localizarPaciente()
{
    string cpf;
    cout << "CPF do paciente a ser localizado: ";
    cin >> cpf;
    for (Paciente &paciente : pacientes)
    {
        if (paciente.getCpf() == cpf)
        {
            cout << "Nome: " << paciente.getNome() << endl;
            cout << "CPF: " << paciente.getCpf() << endl;
            cout << "Data de Nascimento: " << paciente.getData() << endl;
            return;
        }
    }
    cout << "Paciente nao encontrado." << endl;
}

void incluirMedico() // Funções para a gestão de médicos
{
    string crm, nome, especialidade;
    cout << "Nome do medico: ";
    cin.ignore();
    getline(cin, nome);
    cout << "CRM do medico: ";
    getline(cin, crm);
    cout << "Especialidade ";
    getline(cin, especialidade);
    medicos.push_back(Medico(crm, nome, especialidade));
    cout << "Medico incluido com sucesso." << endl;
}

void excluirMedico()
{
    string crm;
    cout << "CRM do medico a ser excluido: ";
    cin >> crm;
    for (auto it = medicos.begin(); it != medicos.end();)
    {
        if (it->getCrm() == crm)
        {
            it = medicos.erase(it);
            cout << "Medico excluido com sucesso." << endl;
        }
        else
        {
            ++it;
        }
    }
}
void alterarMedico()
{
    string crm;
    cout << "CRM do medico a ser alterado: ";
    cin >> crm;
    for (Medico &medico : medicos)
    {
        if (medico.getCrm() == crm)
        {
            cout << "Dados atuais do medico" << endl;
            cout << "Nome: " << medico.getNome() << endl;
            cout << "Especialidade: " << medico.getEspecialidade() << endl;
            string novoNome, novaEspecialidade;
            cout << "Deseja alterar o Nome (S/N)? ";
            char escolha;
            cin >> escolha;
            if (escolha == 'S' || escolha == 's')
            {
                cout << "Novo Nome: ";
                cin.ignore();
                getline(cin, novoNome);
                medico.setNome(novoNome);
                cout << "Nome alterado com sucesso.\n"
                     << endl;
            }
            cout << "Deseja alterar a Especialidade (S/N)? ";
            cin >> escolha;
            if (escolha == 'S' || escolha == 's')
            {
                cout << "Nova Especialidade: ";
                cin.ignore();
                getline(cin, novaEspecialidade);
                medico.setEspecialidade(novaEspecialidade);
                cout << "Especialidade alterada com sucesso." << endl;
            }
        }
        else
        {
            cout << "Medico nao encontrado." << endl;
        }
    }
}

void listarMedicos()
{
    for (Medico &medico : medicos)
    {
        cout << "Nome: " << medico.getNome() << endl;
        cout << "CRM: " << medico.getCrm() << endl;
        cout << "Especialidade: " << medico.getEspecialidade() << endl;
        cout << endl;
    }
}

void localizarMedico()
{
    string crm;
    cout << "CRM do medico a ser localizado: ";
    cin >> crm;
    for (Medico &medico : medicos)
    {
        if (medico.getCrm() == crm)
        {
            cout << "Nome: " << medico.getNome() << endl;
            cout << "CRM: " << medico.getCrm() << endl;
            cout << "Especialidade: " << medico.getEspecialidade() << endl;
            return;
        }
    }
    cout << "Medico nao encontrado." << endl;
}
void incluirConsulta() // Funções para a gestão de consultas
{
    string cpfPaciente, crmMedico, data, hora, duracao, convenio;
    cout << "CPF do paciente: " << endl;
    cin >> cpfPaciente;
    cout << "CRM do medico: " << endl;
    cin >> crmMedico;

    // Verificar se o paciente e o médico existem
    bool pacienteEncontrado = false;
    bool medicoEncontrado = false;

    for (Paciente &paciente : pacientes)
    {
        if (paciente.getCpf() == cpfPaciente)
        {
            pacienteEncontrado = true;
            break;
        }
    }

    for (Medico &medico : medicos)
    {
        if (medico.getCrm() == crmMedico)
        {
            medicoEncontrado = true;
            break;
        }
    }

    if (!pacienteEncontrado)
    {
        cout << "CPF de paciente nao encontrado." << endl;
        return;
    }

    if (!medicoEncontrado)
    {
        cout << "CRM de madico nao encontrado." << endl;
        return;
    }

    cout << "Data da consulta (DD/MM/AAAA): ";
    cin >> data;
    cout << "Hora da consulta: ";
    cin >> hora;
    cout << "Duracao da consulta: ";
    cin >> duracao;
    cout << "Nome do convenio: ";
    cin >> convenio;

    consultas.push_back(Consulta(cpfPaciente, crmMedico, data, hora, duracao, convenio));
    cout << "Consulta registrada com sucesso." << endl;
}

void excluirConsulta()
{
    string crmMedico;
    cout << "CRM do medico: ";
    cin >> crmMedico;

    cout << "Consultas do medico com CRM :" << crmMedico << ":" << endl;

    // Listar todas as consultas do médico
    for (Consulta &consulta : consultas)
    {
        if (consulta.getCRMMedico() == crmMedico)
        {
            cout << "Paciente (CPF): " << consulta.getCPFPaciente() << ", Data: " << consulta.getData() << ", Hora: " << consulta.getHora() << ", Duracao: " << consulta.getDuracao() << ", Realizada: " << (consulta.getRealizada() == "s" ? "Sim" : "Nao") << endl;
        }
    }

    string cpfPaciente;
    cout << "CPF do paciente para excluir a consulta: ";
    cin >> cpfPaciente;

    for (auto it = consultas.begin(); it != consultas.end();)
    {
        if (it->getCRMMedico() == crmMedico && it->getCPFPaciente() == cpfPaciente)
        {
            it = consultas.erase(it);
            cout << "Consulta excluida com sucesso." << endl;
        }
        else
        {
            ++it;
        }
    }
}

void alterarConsulta()
{

    string crmMedico, dataconsulta, duracaoconsulta, horaconsulta, convenioconsulta;
    cout << "CRM do medico: ";
    cin >> crmMedico;

    cout << "Consultas do medico com CRM " << crmMedico << ":" << endl;

    // Listar todas as consultas do médico
    for (Consulta &consulta : consultas)
    {
        if (consulta.getCRMMedico() == crmMedico)
        {
            cout << "Paciente (CPF): " << consulta.getCPFPaciente() << ", Data: " << consulta.getData() << ", Hora: " << consulta.getHora() << ", Duracao: " << consulta.getDuracao() << ", Realizada: " << (consulta.getRealizada() == "s" ? "Sim" : "Nao") << endl;
        }
    }

    string cpfPaciente;
    cout << "CPF do paciente para alterar a consulta: ";
    cin >> cpfPaciente;

    for (Consulta &consulta : consultas)
    {
        if (consulta.getCRMMedico() == crmMedico && consulta.getCPFPaciente() == cpfPaciente)
        {
            cout << "Deseja registrar a consulta como 'Realizada' (S/N)? ";
            char escolha;
            cin >> escolha;

            if (escolha == 'S' || escolha == 's')
            {
                consulta.setRealizada("s");
                cout << "Consulta registrada como 'Realizada'." << endl;
            }
            else
            {
                cout << "Deseja alterar a data (S/N)? ";
                cin >> escolha;
                if (escolha == 'S' || escolha == 's')
                {
                    cout << "Nova data (DD/MM/AAAA): ";
                    cin >> dataconsulta;
                    consulta.setData(dataconsulta);
                }

                cout << "Deseja alterar a hora (S/N)? ";
                cin >> escolha;
                if (escolha == 'S' || escolha == 's')
                {
                    cout << "Nova hora: ";
                    cin >> horaconsulta;
                    consulta.setHora(horaconsulta);
                }

                cout << "Deseja alterar a duracao (S/N)? ";
                cin >> escolha;
                if (escolha == 'S' || escolha == 's')
                {
                    cout << "Nova duracao: ";
                    cin >> duracaoconsulta;
                    consulta.setDuracao(duracaoconsulta);
                }
                cout << "Deseja alterar o convenio (S/N)? ";
                cin >> escolha;
                if (escolha == 'S' || escolha == 's')
                {
                    cout << "Novo convenio: ";
                    cin >> convenioconsulta;
                    consulta.setDuracao(convenioconsulta);
                }
            }
            cout << "Consulta alterada com sucesso." << endl;
            return;
        }
    }
    cout << "Consulta nao encontrada." << endl;
}

void listarConsultas()
{
    if (consultas.empty())
    {
        cout << "Nenhuma consulta registrada." << endl;
        return;
    }

    cout << "Lista de consultas:" << endl;

    for (Consulta &consulta : consultas)
    {
        cout << "Paciente (CPF): " << consulta.getCPFPaciente() << ", CRM do Medico: " << consulta.getCRMMedico() << ", Data: " << consulta.getData() << ", Hora: " << consulta.getHora() << ", Duracao: " << consulta.getDuracao() << "Convenio: " << consulta.getConvenio() << ", Realizada: " << (consulta.getRealizada() == "s" ? "Sim" : "Nao") << endl;
    }
}

int main()
{
    while (true)
    {
        cout << endl;
        cout << " ---- BEM VINDO (A) A CLINICA MEDICA SEM DODOI. ----" << endl
             << endl;
        cout << "Menu Principal\n"
             << endl;
        cout << "1. Gestao de Pacientes" << endl;
        cout << "2. Gestao de Medicos" << endl;
        cout << "3. Gestao de Consultas" << endl;
        cout << "0. Sair do Programa" << endl;
        int escolha;
        cout << "Digite a opcao desejada: " << endl;
        cin >> escolha;

        if (escolha == 1)
        {
            while (true)
            {
                cout << " ---- GERENCIAMENTO DE PACIENTES ----\n"
                     << endl;
                cout << "Menu de Pacientes\n"
                     << endl;
                cout << "1.Incluir" << endl;
                cout << "2. Excluir" << endl;
                cout << "3. Alterar (apenas por CPF)" << endl;
                cout << "4. Listar" << endl;
                cout << "5. Localizar (por CPF)" << endl;
                cout << "0. Voltar" << endl;
                cout << "Digite a opcao desejada: " << endl;
                cin >> escolha;
                system("CLS");

                switch (escolha)
                {
                case 1:
                    incluirPaciente();
                    break;
                case 2:
                    excluirPaciente();
                    break;
                case 3:
                    alterarPaciente();
                    break;
                case 4:
                    listarPacientes();
                    break;
                case 5:
                    localizarPaciente();
                    break;
                case 0:
                    break;
                default:
                    cout << "Opcao invalida tente novamente." << endl;
                    break;
                }

                if (escolha == 0)
                    break;
            }
        }
        else if (escolha == 2)
        {

            while (true)
            {
                cout << " ---- GERENCIAMENTO DE MEDICOS ----\n"
                     << endl;
                cout << "Menu de Medicos\n"
                     << endl;
                cout << "1. Incluir" << endl;
                cout << "2. Excluir" << endl;
                cout << "3. Alterar (apenas por CRM)" << endl;
                cout << "4. Listar" << endl;
                cout << "5. Localizar (por CRM)" << endl;
                cout << "0. Voltar" << endl;
                cout << "Digite a opcao desejada: " << endl;
                cin >> escolha;
                system("CLS");

                switch (escolha)
                {
                case 1:

                    incluirMedico();
                    break;
                case 2:
                    excluirMedico();
                    break;
                case 3:
                    alterarMedico();
                    break;
                case 4:
                    listarMedicos();
                    break;
                case 5:
                    localizarMedico();
                    break;
                case 0:
                    break;
                default:
                    cout << "Opcao invalida tente novamente." << endl;
                    break;
                }

                if (escolha == 0)
                    break;
            }
        }
        else if (escolha == 0)
        {
            cout << "Saindo do programa." << endl;
            break;
        }
        else if (escolha == 3)
        {
            while (true)
            {
                cout << " ---- GERENCIAMENTO DE CONSULTAS ----\n"
                     << endl;
                cout << "Menu de Consultas\n"
                     << endl;
                cout << "1. Incluir Consultas" << endl;
                cout << "2. Excluir um Consulta" << endl;
                cout << "3. Alterar Consulta" << endl;
                cout << "4. Listar todas as Consultas" << endl;
                cout << "0. Voltar" << endl;
                cin >> escolha;
                system("CLS");

                switch (escolha)
                {
                case 1:
                    incluirConsulta();
                    break;
                case 2:
                    excluirConsulta();
                    break;
                case 3:
                    alterarConsulta();
                    break;
                case 4:
                    listarConsultas();
                    break;
                case 0:
                    break;
                default:
                    cout << "Opcao invalida tente novamente." << endl;
                    break;
                }
            }
        }
        else
        {
            cout << "Opcao invalida tente novamente." << endl;
        }
    }

    return 0;
}