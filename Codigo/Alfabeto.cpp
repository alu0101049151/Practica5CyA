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
 *                     Este fichero contiene la implementación de la clase.
 *
 * Referencias:
 *                   Enunciado de la prácita:
 *                   https://campusvirtual.ull.es/1920/pluginfile.php/172406/mod_assign/introattachment/0/CYA_1920_Practica_5.pdf?forcedownload=1
 * Historial de revisiones
 *                   20/10/2019 - Creación (primera versión) del código
 * */

#include "Alfabeto.h"

Alfabeto::Alfabeto (std::string& ficheroEntrada) {
	lee (ficheroEntrada);
}


Alfabeto::~Alfabeto () {}


// Lee el fichero con el conjunto de símbolos que conforman el alfabeto y
// rellena el Alfabeto como tal.
void Alfabeto::lee (std::string& ficheroEntrada) {
	std::ifstream entrada;

	entrada.open(ficheroEntrada);

	if (!entrada.is_open())
		std::cerr << "Ha ocurrido un problema al abrir el fichero de entrada, por favor inténtelo de nuevo" << NEWLINE;
	else {
		char leido;

		while (!entrada.eof()){
			entrada.get(leido);
			if (leido != NEWLINE){
		  	//std::cout << "Leido: " << leido << NEWLINE;
			  alfabeto_.insert(leido);
			}
		}
		entrada.close();
	}

}



// Comprueba que todos los símbolos de la Expresion Regular, pertenecen al
// alfabeto.
bool Alfabeto::analizar (ExpresionRegular& expresion) {
	bool pertenece = true;
	int i = 0;
	while (pertenece && i < expresion.getInfija().size()) {
		pertenece = false;
		for (auto j: alfabeto_) {
			if (j == expresion.getInfija()[i])
				pertenece = true;
		}
		i++;
	}
	return pertenece;
}




