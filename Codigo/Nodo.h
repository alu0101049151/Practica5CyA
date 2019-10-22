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
 * Archivo Nodo.h: Clase Nodo. Clase que representa el nodo de un arbol binario.
 *                       Este fichero contiene la definición de la clase.
 *
 * Referencias:
 *                   Enunciado de la prácita:
 *                   https://campusvirtual.ull.es/1920/pluginfile.php/172406/mod_assign/introattachment/0/CYA_1920_Practica_5.pdf?forcedownload=1
 * Historial de revisiones
 *                   20/10/2019 - Creación (primera versión) del código
 * */

#ifndef PRACTICA5_NODO_H
#define PRACTICA5_NODO_H


class Nodo {
	public:

		Nodo (char dato);
		~Nodo ();

		char getDato ();
		Nodo getIzquierdo ();
		Nodo getDerecho ();

	protected:
	private:
		char dato_;           // Es la información que contiene el nodo en su interior.
		Nodo *izquierdo_;     // Es el hijo izquierdo del nodo.
		Nodo *derecho_;       // Es el hijo derecho del nodo.
};

#endif //PRACTICA5_NODO_H
