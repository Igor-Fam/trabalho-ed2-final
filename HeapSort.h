#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <string>
#include <iostream>

#include "fileManager.h"
#include "resultados.h"

using namespace std;


void max_heapify(int *upvts, int n, int i,resultados *resultH)
{
    int m = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    resultH->addcomp();
    if (left < n && upvts[left] > upvts[m])
        m = left;
    resultH->addcomp();
    if (right < n && upvts[right] > upvts[m])
        m = right;
  
    if (m != i) {
        swap(upvts[i], upvts[m]);
        resultH->addmov();
        max_heapify(upvts, n, m,resultH);
    }
}

void build_heapify(int *upvts, int n, resultados *resultH){
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(upvts, n, i,resultH);
  
}

void heapSort(int *upvts, int n, resultados *resultH)
{
    build_heapify(upvts,n,resultH);
    for (int i = n - 1; i >= 0; i--) {
        swap(upvts[0], upvts[i]);
        resultH->addmov();
        max_heapify(upvts, i, 0,resultH);
    }
}

void StartHeapsort(int *upvts, int n){
  auto c = chrono::high_resolution_clock::now();
  resultados *resultH = new resultados;
  resultH->setresult(n);
  heapSort(upvts,n,resultH);
  auto f = chrono::high_resolution_clock::now();
  auto total = chrono::duration_cast<chrono::microseconds>(f-c);
  float tempo = total.count();
  resultH->addtempo(tempo);
  resultH->addtipo("HeapSort");
  resultH->salvar();
  delete resultH;
}

#endif