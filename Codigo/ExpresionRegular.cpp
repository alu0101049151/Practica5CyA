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
 * Archivo ExpresionRegular.cpp: Clase ExpresionRegular. Clase que representa una expresión regular con sus
 *                         tres posibles notaciones (infija, postfija y prefija).
 *                         Este fichero contiene la implementación de la clase.
 *
 * Referencias:
 *                   Enunciado de la prácita:
 *                   https://campusvirtual.ull.es/1920/pluginfile.php/172406/mod_assign/introattachment/0/CYA_1920_Practica_5.pdf?forcedownload=1
 * Historial de revisiones
 *                   20/10/2019 - Creación (primera versión) del código
 * */

#include "ExpresionRegular.h"

ExpresionRegular::ExpresionRegular (std::string infija):
	infija_(infija),
  postfija_(" "),
  prefija_ (" "){}


ExpresionRegular::ExpresionRegular ():
	infija_(" "),
  postfija_(" "),
  prefija_ (" "){}


ExpresionRegular::~ExpresionRegular () {}


std::string ExpresionRegular::getInfija () const {
	return infija_;
}


std::string ExpresionRegular::getPostfija () const {
	return postfija_;
}


std::string ExpresionRegular::getPrefija () const {
	return prefija_;
}


void ExpresionRegular::setInfija (std::string newInfija) {
	infija_ = newInfija;
}


void ExpresionRegular::setPostfija (std::string newPostfija) {
	postfija_ = newPostfija;
}


void ExpresionRegular::setPefija (std::string newPrefija) {
	prefija_ = newPrefija;
}


void ExpresionRegular::imprimirPrefija(Nodo* raiz) {
	if (raiz == NULL)
		return;

	prefija_.push_back(raiz->getDato());

	imprimirPrefija(raiz->getIzquierdo());
	imprimirPrefija(raiz->getDerecho());
}
