#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;

unsigned t0, t1;
int partition(vector<double>& arr, int low, int high);
void quickSort(vector<double>& arr, int low, int high);
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
    quickSort(datos, 0, datos.size()-1);
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

int partition(vector<double>& arr, int low, int high) {
    double pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<double>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
