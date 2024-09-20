#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>

using namespace std;

unsigned t0, t1;

void heapify(vector<double>& arr, int n, int i);
void heapSort(vector<double>& arr);
void muestra_vector(const vector<double>&);
int main()
{
    ifstream fich("DataGen025.txt");
    if (!fich.is_open())
    {
        cout << "Error al abrir ejemplo.dat\n";
        exit(EXIT_FAILURE);
    }
    t0=clock();
    double valor;
    vector<double> datos;
    while (fich >> valor)
        datos.push_back(valor);
    cout<<"Mostrar vector desordenado: "<<endl;
    muestra_vector(datos);
    cout<<"Ordenar vector"<<endl;
    heapSort(datos);
    cout<<"Mostrar vector ordenado: "<<endl;
    muestra_vector(datos);
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
}

void muestra_vector(const vector<double>& v)
{
  for (auto x : v)
    cout << x <<endl;
  cout << endl;
}

void heapify(vector<double>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<double>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
