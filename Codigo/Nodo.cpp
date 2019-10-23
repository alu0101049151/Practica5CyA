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
 * Archivo Nodo.cpp: Clase Nodo. Clase que representa el nodo de un arbol binario.
 *                       Este fichero contiene la definición de la clase.
 *
 * Referencias:
 *                   Enunciado de la prácita:
 *                   https://campusvirtual.ull.es/1920/pluginfile.php/172406/mod_assign/introattachment/0/CYA_1920_Practica_5.pdf?forcedownload=1
 * Historial de revisiones
 *                   20/10/2019 - Creación (primera versión) del código
 * */


#include "Nodo.h"

Nodo::Nodo (char dato):
	dato_(dato),
	izquierdo_(NULL),
	derecho_(NULL) {}
   

Nodo::Nodo ():
	izquierdo_(NULL),
	derecho_(NULL) {}	


char Nodo::getDato () {
	return dato_;
}	


Nodo* Nodo::getIzquierdo () {
	return izquierdo_;
}


Nodo* Nodo::getDerecho () {
	return derecho_;
}


void Nodo::setIzquierdo(Nodo* auxNodo) {
	izquierdo_ = auxNodo;
}


void Nodo::setDerecho(Nodo* auxNodo) {
	derecho_ = auxNodo;
}

