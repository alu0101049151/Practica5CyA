/* *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia (CyA)
 * Curso: 2º
 * Práctica 5 CyA - Expresiones Regulares
 * Autor: Basilio Gómez Navarro
 * Correo: alu0101049151@ull.edu.es
 * Fecha 20/10/2019
 * Archivo Arbol.h: Clase Arbol. Esta clase lee de un fichero de entrada
 *                  Representa un árbol binario.
 *                  Este fichero contiene la definición de la clase.
 *
 * Referencias:
 *                   Enunciado de la prácita:
 *                   https://campusvirtual.ull.es/1920/pluginfile.php/172406/mod_assign/introattachment/0/CYA_1920_Practica_5.pdf?forcedownload=1
 * Historial de revisiones
 *                   20/10/2019 - Creación (primera versión) del código
 * */

#ifndef PRACTICA5_ARBOL_H
#define PRACTICA5_ARBOL_H

#include "Nodo.h"

class Arbol {
	public:
		Arbol(Nodo* raiz);


	
	private:
		Nodo* raiz_;   // Es la raíz del árbol.
		int contador;  // Cuenta el número de nodos que hay en el árbol.
		

};


#endif //PRACTICA5_ARBOL_H
