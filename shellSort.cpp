#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;

unsigned t0, t1;
void shellSort(vector<double>& arr);
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
    shellSort(datos);
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

void shellSort(vector<double>& arr) {
    int n = arr.size();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            double temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
