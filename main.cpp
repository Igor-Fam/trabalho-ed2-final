#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

#include "ShellSort.h"
#include "fileManager.h"
#include "HuffmanCompression.h"
#include "BalancedStructures.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "Sorting.h"

using namespace std;

int BNode::comparisons;
int VPNode::comparisons;
string path;

int main(int argc, char *argv[])
{
    path = argv[1];
    ifstream check;
    check.open("tiktok_app_reviews.bin");
    if (check.is_open()) {
        cout << "Arquivo binario encontrado." << endl;
        check.close();
    }
    else {
        cout << "Erro: arquivo binario nao encontrado.";
        processamento();
    }
    int option = -1;
    while(option != 4){
        cout << "Qual parte do trabalho deseja executar?" << endl;
        cout << "1. Ordenacao" << endl;
        cout << "2. Estruturas Balanceadas" << endl;
        cout << "3. Compressao de Huffman" << endl;
        cout << "4. Sair" << endl;
        cin >> option;
        switch(option){
            case 1:
                cout<< "Escolha qual algoritmo de ordenacao deseja executar: " << endl;
                cout << "1. QuickSort" << endl;
                cout << "2. HeapSort" << endl;
                cout << "3. ShellSort" << endl;
                int op;
                cin >> op;
                switch(op){
                    case 1:
                        analiseQuickSort();
                        break;
                    case 2:
                        analiseHeapSort();
                        break;
                    case 3:
                        analiseShellSort();
                        break;
                }
                            break;
            case 2: 
                BalancedStructuresInterface();
                break;
            case 3: 
                compressionInterface();
                break;
            case 4:
                break;
            default:
                cout << "Opcao invalida!" << endl;
                break;
        }
    }
    return 0;
}