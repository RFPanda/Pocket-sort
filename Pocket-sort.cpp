#include "pch.h" //RFPanda
#include <iostream>
#include <locale.h>
using namespace std;
void bucketSort(int[], int, int[][10]); // один из масс в ф-цию.
int main()
{
  const int size = 10; // размер массивов
  int array[size] = { 5,141,15,12,97,3,45,3,62,100 };
  int array1[size][size] = { 0 }; // массив в котором будут заноситься числа
  bucketSort(array, size, array1); 
  cout << endl;
  return (0);
} 
void bucketSort(int ar[], int x, int ar1[][10]) { // передаем функции оба массива
  setlocale(LC_ALL, "Rus");
  cout << "Введённый массив: 5,141,15,12,97,3,45,3,62,100  " << endl << endl;
  int t = 0;
  int d = 1;
  for (int z = 0; z < 3; z++) // 3 т.к. 100 трёхзнач.
  { 
    t = 0;
    for (int i = 0; i < x; i++)
    {
      ar1[(ar[i] / d) % 10][i] = ar[i];
    }
    for (int i = 0; i < x; i++)
    {
      for (int j = 0; j < x; j++)
        if (ar1[i][j] != 0)
        {
          ar[t] = ar1[i][j];
          t++;
        }
    }
   // обнуляем блочный массив 
    for (int i = 0; i < x; i++)
      for (int j = 0; j < x; j++)
        ar1[i][j] = 0;
    
    d *= 10; // в конце каждого цикла умножаем d на 10 для следующего разряда
  }  cout << "Отсортированный массив: ";
  for (int i = 0; i < x; i++)
    cout << ar[i] << " ";
} 
