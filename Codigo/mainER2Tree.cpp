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
 * Archivo main.cpp: Este fichero contiene la función main del programa.
 * Referencias:
 *                   Enunciado de la prácita:
 *                   https://campusvirtual.ull.es/1920/pluginfile.php/172406/mod_assign/introattachment/0/CYA_1920_Practica_5.pdf?forcedownload=1
 * Historial de revisiones
 *                   20/10/2019 - Creación (primera versión) del código
 * */

#include "ER2Tree.h"

int main (int argc, char const* argv[]) {
	std::string input = "../Entradas/alfabeto.txt";

	if (argv[1] == NULL) {
		std::cout << "NOMBRE\n";
    std::cout << "       ER2Tree\n";
    std::cout << "\n";
    std::cout << "EJECUCIÓN\n";
    std::cout << "       ER2Tree [fichero_entrada] [fichero_salida]\n";
    std::cout << "\n";
    std::cout << "DESCRICIÓN\n";
    std::cout << "      Lee un fichero de entrada con expresiones regulares, y escribe en un\n";
    std::cout << "      fichero de salida, cada expresion regular en notación infija, postfija y \n";
		std::cout << "      prefija, además de mostrar el número de nodos que tiene el arbol de la expresión\n";
    std::cout << "\n";
    std::cout << "AUTOR\n";
    std::cout << "     Escrito por Basilio Gómez Navarro como práctica de la asignatura\n";
    std::cout << "     Computabilidad y Algoritmia. Octubre de 2019.\n";
    std::cout << "\n\n";

	}
	else {
		std::string ficheroEntrada = argv[1];
		std::string ficheroSalida = argv[2];

		ER2Tree conversor(ficheroEntrada, ficheroSalida, input);
		//ExpresionRegular er("(a|b)(c|d)");
		//conversor.introduceConcatenacion(er);
	}
	return 0;
}

