#ifndef DFS_H
#define DFS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// CLASSES
class Aresta{
    public:
        //Atributos
        int id;
        int origem;
        int destino;
        double peso;
        bool visitado;
        bool direcionado;

        //Metodos
        Aresta(int id = -1, int origem = -1, int destino = -1, double peso = -1.0, bool visitado = false, bool direcionado = false);
        ~Aresta();

        void printInfo();
};

class Vertice{
    public:
        //Atributos
        int id;
        bool visitado;

        //Metodos
        Vertice(int id, bool visitado = false);
        ~Vertice();

        void printInfo();
};

class Celula{
    public:
        //Atributos
        bool status; // TRUE caso tenha aresta de i para j e FALSE caso nao exista
        bool visitado;

        //Metodos
        Celula(bool status = false, bool visitado = false);
        ~Celula();
};

class Grafo{
    public:
        //Atributos
        int qntd_vertices;
        int qntd_arestas;
        int vertice_inicial;
        bool direcionado;
        vector<Vertice> vertices;
        vector<Aresta> arestas;
        vector<vector<Celula>> matriz;

        //Metodos
        Grafo();
        Grafo(int qntd_vertices, int qntd_arestas, int vertice_inicial, bool direcionado);
        ~Grafo();

        void inicializaGrafo();
        void DFS(int vertice_inicial, vector<int>* ordem_visitacao);

        void printInfo();
};

void printFinal(vector<int> ordem_visitacao);

#endif
