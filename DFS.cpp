#include "DFS.hpp"

using namespace std;

/*
███████╗██╗   ██╗███╗   ██╗ ██████╗ ██████╗ ███████╗███████╗
██╔════╝██║   ██║████╗  ██║██╔════╝██╔═══██╗██╔════╝██╔════╝
█████╗  ██║   ██║██╔██╗ ██║██║     ██║   ██║█████╗  ███████╗
██╔══╝  ██║   ██║██║╚██╗██║██║     ██║   ██║██╔══╝  ╚════██║
██║     ╚██████╔╝██║ ╚████║╚██████╗╚██████╔╝███████╗███████║
╚═╝      ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚═════╝ ╚══════╝╚══════╝
*/

void printFinal(vector<int> ordemVisitacao){
    for (int i = 0; i < static_cast<int>(ordemVisitacao.size()); i++){
        cout << ordemVisitacao[i] << "\n";
    }
}

/*
 █████╗ ██████╗ ███████╗███████╗████████╗ █████╗ 
██╔══██╗██╔══██╗██╔════╝██╔════╝╚══██╔══╝██╔══██╗
███████║██████╔╝█████╗  ███████╗   ██║   ███████║
██╔══██║██╔══██╗██╔══╝  ╚════██║   ██║   ██╔══██║
██║  ██║██║  ██║███████╗███████║   ██║   ██║  ██║
╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝   ╚═╝   ╚═╝  ╚═╝
*/

Aresta::Aresta(int id, int origem, int destino, double peso, bool visitado, bool direcionado){
    this->id = id;
    this->origem = origem;
    this->destino = destino;
    this->peso = peso;
    this->visitado = visitado;
    this->direcionado = direcionado;
}
Aresta::~Aresta(){}

void Aresta::printInfo(){
    cout << "--------- Aresta ---------\n";
    cout << "Id         : " << this->id << "\n" ;
    cout << "Origem     : " << this->origem << "\n" ;
    cout << "Destino    : " << this->destino << "\n" ;
    cout << "Peso       : " << this->peso << "\n" ;
    cout << "Visitado   : " << this->visitado << "\n" ;
    cout << "Direcionado: " << this->direcionado << "\n\n" ;
}

/*
██╗   ██╗███████╗██████╗ ████████╗██╗ ██████╗███████╗
██║   ██║██╔════╝██╔══██╗╚══██╔══╝██║██╔════╝██╔════╝
██║   ██║█████╗  ██████╔╝   ██║   ██║██║     █████╗  
╚██╗ ██╔╝██╔══╝  ██╔══██╗   ██║   ██║██║     ██╔══╝  
 ╚████╔╝ ███████╗██║  ██║   ██║   ██║╚██████╗███████╗
  ╚═══╝  ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝ ╚═════╝╚══════╝
*/

Vertice::Vertice(int id, bool visitado){
    this->id = id;
    this->visitado = visitado;
}
Vertice::~Vertice(){}
void Vertice::printInfo(){
    cout << "--------- Vertice ---------\n";
    cout << "Id                            : " << this->id << "\n" ;
    cout << "Visitado                      : " << this->visitado << "\n\n" ;
}

/*
 ██████╗███████╗██╗     ██╗   ██╗██╗      █████╗ 
██╔════╝██╔════╝██║     ██║   ██║██║     ██╔══██╗
██║     █████╗  ██║     ██║   ██║██║     ███████║
██║     ██╔══╝  ██║     ██║   ██║██║     ██╔══██║
╚██████╗███████╗███████╗╚██████╔╝███████╗██║  ██║
 ╚═════╝╚══════╝╚══════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝
*/

Celula::Celula(bool status, bool visitado):status(status), visitado(visitado){}
Celula::~Celula(){}

/*
 ██████╗ ██████╗  █████╗ ███████╗ ██████╗ 
██╔════╝ ██╔══██╗██╔══██╗██╔════╝██╔═══██╗
██║  ███╗██████╔╝███████║█████╗  ██║   ██║
██║   ██║██╔══██╗██╔══██║██╔══╝  ██║   ██║
╚██████╔╝██║  ██║██║  ██║██║     ╚██████╔╝
 ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝      ╚═════╝ 
*/

Grafo::Grafo(){}
Grafo::Grafo(int qntd_vertices, int qntd_arestas, int vertice_inicial, bool direcionado):qntd_vertices(qntd_vertices), qntd_arestas(qntd_arestas), vertice_inicial(vertice_inicial), direcionado(direcionado){}
Grafo::~Grafo(){}

void Grafo::inicializaGrafo(){

    // Leitura dos dados iniciais
    int qntd_vertices, qntd_arestas, eh_direcionado, vertice_inicial;
    bool direcionado;

    cin >> qntd_vertices >> qntd_arestas >> eh_direcionado >> vertice_inicial;
    if (eh_direcionado == 1){
        direcionado = true;
    }
    else{
        direcionado = false;
    }

    this->qntd_arestas = qntd_arestas;
    this->qntd_vertices = qntd_vertices;
    this->direcionado = direcionado;
    this->vertice_inicial = vertice_inicial;

    // Lendo vertices
    for (int i = 1; i <= this->qntd_vertices; i++){
        Vertice v(i, false);
        this->vertices.push_back(v);;

        vector<Celula> vet;
        this->matriz.push_back(vet);
        for (int j = 1; j <= this->qntd_vertices; j++){
            this->matriz[i - 1].push_back(Celula());
        }
    }

    // Lendo arestas e criando listas de adjacencia
    int origem, destino;
    double peso;

    for (int i = 1; i <= this->qntd_arestas; i++){
        cin >> origem >> destino >> peso;
        
        Aresta a = Aresta(i, origem, destino, peso, false, this->direcionado);
        this->arestas.push_back(a);

        if (this->direcionado){
            this->matriz[origem - 1][destino - 1].status = true;
        }
        else{
            this->matriz[origem - 1][destino - 1].status = true;
            this->matriz[destino - 1][origem - 1].status = true;
        }
    }
}

void Grafo::DFS(int vertice_inicial, vector<int>* ordem_visitacao){
    this->vertices[vertice_inicial - 1].visitado = true;
    ordem_visitacao->push_back(vertice_inicial);

    for (int i = 0; i < this->qntd_vertices; i++){
        if (!(this->matriz[vertice_inicial - 1][i].status)){
            continue;
        }

        int vertice_atual = i + 1;

        if (this->vertices[vertice_atual - 1].visitado){
            if (!(this->matriz[vertice_inicial - 1][vertice_atual - 1].visitado)){
                this->matriz[vertice_inicial - 1][vertice_atual - 1] = true;
            }
        }
        else{
            this->matriz[vertice_inicial - 1][vertice_atual - 1] = true;
            this->DFS(vertice_atual, ordem_visitacao);
        }
    }
}

void Grafo::printInfo(){
    cout << "--------- Grafo ---------\n";
    cout << "Qntd vertices  : " << this->qntd_vertices << "\n" ;
    cout << "Qntd arestas   : " << this->qntd_arestas << "\n" ;
    cout << "Vertice inicial: " << this->vertice_inicial << "\n" ;
    cout << "Direcionado    : " << this->direcionado << "\n\n" ;
}