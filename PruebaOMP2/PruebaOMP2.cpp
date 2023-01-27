// PruebaOMP2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

// Aqui cargamos las librerias necesarias para poder trabajar con las funciones de c++ y de omp.
#include <iostream>
#include <omp.h>


//Creamos variables locales para poder trabajar con ellas dentro de todo el código.
#define N 1000
#define chunk 100
#define mostrar 100

//Creamos una función para ahorro de instrucciones y poder trabajar con una ejecucion de instrucciones en cualquier parte del código donde se necesite.
void imprimeArreglo(float* d);

int main()
{
	std::cout << "Sumando Arreglos en Paralelo! \n";
	float a[N], b[N], c[N];
	int i;

	for (i = 0; i < N; i++)
	{
		a[i] = i * 10;
		b[i] = (i + 3) * 3.7;
	}

	int pedazos = chunk;

	#pragma omp parallel for shared(a, b, c, pedazos) private(i) schedule(static, pedazos)

	for (i = 0; i < N; i++)
		c[i] = a[i] + b[i];

	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
	imprimeArreglo(a);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
	imprimeArreglo(b);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
	imprimeArreglo(c);

}

void imprimeArreglo(float* d)
{
	for (int x = 0; x < mostrar; x++)
	{
		std::cout << d[x] << "-";
	}
	std::cout << std::endl;

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
