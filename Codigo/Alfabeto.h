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
 * Archivo Alfabeto.h: Clase Alfabeto. Representa un conjunto no vacío y finito
 *                     de símbolos.
 *                     Este fichero contiene la definición de la clase.
 *
 * Referencias:
 *                   Enunciado de la prácita:
 *                   https://campusvirtual.ull.es/1920/pluginfile.php/172406/mod_assign/introattachment/0/CYA_1920_Practica_5.pdf?forcedownload=1
 * Historial de revisiones
 *                   20/10/2019 - Creación (primera versión) del código
 * */


#ifndef PRACTICA5_ALFABETO_H
#define PRACTICA5_ALFABETO_H

#include <set>
#include <fstream>
#include <iostream>
#include <stdlib.h>  // exit, EXIT_FAILURE

#include "ExpresionRegular.h"

class Alfabeto {
	public:
		Alfabeto (std::string& ficheroEntrada);
		~Alfabeto ();

		// Comprueba que todos los símbolos de la Expresion Regular, pertenecen al
		// alfabeto.
		bool analizar (ExpresionRegular& expresion);

	private:
		// Lee el fichero con el conjunto de símbolos que conforman el alfabeto y
		// rellena el Alfabeto como tal.
		void lee (std::string& ficheroEntrada);
	
	private:
		std::set<char> alfabeto_;

};

#endif //PRACTICA5_ALFABETO_H
