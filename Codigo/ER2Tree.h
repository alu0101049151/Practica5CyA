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
 *                    Este fichero contiene la definición de la clase.
 *
 * Referencias:
 *                   Enunciado de la prácita:
 *                   https://campusvirtual.ull.es/1920/pluginfile.php/172406/mod_assign/introattachment/0/CYA_1920_Practica_5.pdf?forcedownload=1
 * Historial de revisiones
 *                   20/10/2019 - Creación (primera versión) del código
 * */


#ifndef PRACTICA5_ER2TREE_H
#define PRACTICA5_ER2TREE_H


#include <vector>
#include <stack>

#include "Alfabeto.h"
#include "Nodo.h"

class ER2Tree {
	public:
		ER2Tree (std::string& ficheroEntrada, std::string& ficheroSalida, std::string& ficheroAlfabeto);
		~ER2Tree ();

    std::string introduceConcatenacion (ExpresionRegular expresion);
	
	protected:
		// Método que lee el fichero de entrada, aplica los algoritmos 1 y 2 a las
		// ER leidas y finalmente almacena cada ER en el vector de Expresiones
		// Regulares.
		void run (std::string& ficheroEntrada);


		// Método para modificar la Expresion Regular leída del fichero en notación
		// infija. Añade los símbolos & que en la notación infija están implícitos.
		//std::string introduceConcatenacion (ExpresionRegular expresion);


    // Convierte la expresión regular de notación infija a postfija.
		void algoritmo1 (ExpresionRegular& expresionRegular, std::string& auxInfija);


    // Obtiene el árbol de una expresión regular en notación postfija.
		void algoritmo2 (ExpresionRegular& expresion);


		// Escribe en el fichero de salida la tabla solicitada en el enunciado de la
		// práctica.
		void escrituraFichero (std::string& ficheroSalida);	
	
	private:
    // Es el alfabeto que contiene los símbolos posibles de todas las expresiones
		// regulares con las que se trate.
		Alfabeto alfabeto_; 

		// Vector que contiene todas las expresiones regulares leídas y
		// en con todas sus notaciones (infija, postfija y prefija) tras haberle
		// aplicado los algoritmos correspondientes. Este vector se usa para
		// imprimir el resultado final al fichero de salida.
		std::vector<ExpresionRegular> expresionesRegulares_;
};

#endif //PRACTICA5_ER2TREE_H
