#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "DFS.hpp"

using namespace std;

int main(){

    // Criacao e inicializacao do grafo
    Grafo grafo = Grafo();
    grafo.inicializaGrafo();

    // DFS
    vector<int> ordem_visitacao;
    grafo.DFS(grafo.vertice_inicial, &ordem_visitacao);

    // Print
    printFinal(ordem_visitacao);

    return 0;

}