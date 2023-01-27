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

//Función  princpial de ejecucion del programa
int main()
{
//Imprimimos una linea de bienvenida para el usuario indicando que esta haciendo el programa.
	std::cout << "Sumando Arreglos en Paralelo! \n";
	//Creamos variables locales de la funcion main para poder trabajar localmente en las instrucciones dentro del entorno de ejecución.
	float a[N], b[N], c[N];
	int i;
	//Ciclo for para llenar los arreglos con valores en escala de 10 y el otro en escalas mas especificas al usar un producto de 3.7
	for (i = 0; i < N; i++)
	{
		a[i] = i * 10;
		b[i] = (i + 3) * 3.7;
	}
	//Variable local para obtener el tamaño de lineas paralelas a trabajar.
	int pedazos = chunk;

	//Se crea un constructor para tener un grupo de threads, donde las variables seran compartidas en todos los threads esto hara que las operaciones pueden ser llevadas como se busca
	// de forma paralela.
	#pragma omp parallel for shared(a, b, c, pedazos) private(i) schedule(static, pedazos)
	//Ciclo for para poder llevar acabo la operación de suma dentro de los threads.
	for (i = 0; i < N; i++)
		c[i] = a[i] + b[i];
	//Impresion de los arreglos y el resultado de la operacion.
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
	imprimeArreglo(a);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
	imprimeArreglo(b);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
	imprimeArreglo(c);

}
//Función para poder imprimir los arreglos creados.
void imprimeArreglo(float* d)
{
	//Ciclo for para mostrar el tamaño y contenido de los arreglos.
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
