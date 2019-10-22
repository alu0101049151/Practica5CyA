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
 * Archivo ER2Tree.h: Clase ER2Tree. Esta clase lee de un fichero de entrada
 *                    una serie de expresiones regulares a las que se les
 *                    aplican una serie de algoritmos para luego imprimirlas en
 *                    las 3 notaciones posibles (infija, postfija y prefija) a
 *                    un fichero de salida determinado.
 *                    Este fichero contiene la implementación de la clase.
 *
 * Referencias:
 *                   Enunciado de la prácita:
 *                   https://campusvirtual.ull.es/1920/pluginfile.php/172406/mod_assign/introattachment/0/CYA_1920_Practica_5.pdf?forcedownload=1
 * Historial de revisiones
 *                   20/10/2019 - Creación (primera versión) del código
 * */

#include "ER2TRee.h"

ER2Tree::ER2Tree (std::string& ficheroEntrada, std::string& ficheroSalida, std::string& ficheroAlfabeto):
  alfabeto_(ficheroAlfabeto)
  {
	  run (ficheroEntrada);
	  escrituraFichero (ficheroSalida);
  }


ER2Tree::~ER2Tree (){}


std::string introduceConcatenacion (ExpresionRegular expresion) {
	bool condicion1 = expresion.getInfija[i] != '(';
	bool condicion2 = expresion.getInfija[i] != '|';
	bool condicion3 = expresion.getInfija[i + 1] != '|';
	bool condicion4 = expresion.getInfija[i + 1] != ')';
	bool condicion5 = expresion.getInfija[i + 1] != '*';


	if (alfabeto_.analizar(expresion)) {    // Comprobamos que los símbolos de la cadena pertenecen al alfabeto.
		for (int i = 0; i < expresion.getInfija().size(); ++i) {
			if ((condicion1 && condicion2) && (condicion3 && condicion4 && condicion5)) {
				expresion.getInfija().insertInfija(i);
				std::cout << "Después de insertar &: " << expresion.getInfija() << NEWLINE;
			}
		}	
	}
	else {
		std::cerr << "ERROR: Al menos un simbolo de la expresión regular no pertenece al alfabeto" << NEWLINE;
		exit(EXIT_FAILURE);
	}

}


