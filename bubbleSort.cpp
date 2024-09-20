#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;

unsigned t0, t1;
void bubbleSort(vector<double>& arr);
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
    bubbleSort(datos);
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

void bubbleSort(vector<double>& arr) {
    bool swapped;
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) // Si no hubo cambios, el arreglo ya está ordenado
        {
            break;
        }
    }
}
