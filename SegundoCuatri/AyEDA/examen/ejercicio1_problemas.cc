/**
 * Escribe un procedimiento en C++ que ordene la primera mitad de la secuencia 
 * o vector por el método de selección de menor a mayor, luego ordene la 
 * segunda mitad también por el método de inserción, pero de mayor a menor, y 
 * finalmente mezcle ambas mitades de forma que el vector quede ordenado de 
 * mayor a menor ordenada.
 */

#include <vector>
#include <iostream>
#include <utility>

void sort(std::vector<int> &sec, size_t n) {
  size_t mid = n / 2;
  // Primera mitad por selection
  for(int i = 0; i < mid; i++) {
    int min = i;
    for(int j = i + 1; j < mid; j++) {
      if(sec[j] < sec[min]) min = j;
    }
    std::swap(sec[min], sec[i]);
  }

  // Segunda mitad por Insertion de mayor a menor
  for(int i = mid + 1; i < n; i++) {
    int num = sec[i];
    int j = i - 1;
    while(j >= mid && sec[j] < num) {
      sec[j+1] = sec[j];
      j--;
    }
    sec[j + 1] = num;
  }

  // Mezclar
  int i = mid - 1;
  int j = mid;
  int aux[n];
  int k = 0;
    // Recorrer mientras ambas secuencias tengan
  while(i >= 0 && j < n) {
    if(sec[i] > sec[j]) {
      aux[k] = sec[i];
      i--;
    } else {
      aux[k] = sec[j];
      j++;
    }
    k++;
  }
    // Recorrer cuando alguna de las dos hayan terminando
  if(i < 0) {
    while(j < n) {
      aux[k] = sec[j];
      j++; k++;
    }
  } else {
    while(i >= 0) {
      aux[k] = sec[i];
      i--; k++;
    }
  }
    // Copiar array
  for(int i = 0; i < n; i++) {
    sec[i] = aux[i];
  }
}

int main() {
  std::vector<int> sec;
  for(int i = 0; i < 12; i++) {
    sec.push_back(std::rand() % 100);
  }
  for(int i = 0; i < sec.size(); i++) {
    std::cout << sec[i] << " ";
  }
  std::cout << std::endl;
  sort(sec, sec.size());
  for(int i = 0; i < sec.size(); i++) {
    std::cout << sec[i] << " ";
  }
  std::cout << std::endl;
}