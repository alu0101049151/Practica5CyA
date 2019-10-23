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

#include "ER2Tree.h"

ER2Tree::ER2Tree (std::string& ficheroEntrada, std::string& ficheroSalida, std::string& ficheroAlfabeto):
  alfabeto_(ficheroAlfabeto)
  {
	  run (ficheroEntrada);
	  //escrituraFichero (ficheroSalida);
  }


ER2Tree::~ER2Tree (){}


std::string ER2Tree::introduceConcatenacion (ExpresionRegular expresion) {
	
	std::string auxInfija = expresion.getInfija();
  bool condicion1;
  bool condicion2;
  bool condicion3;
  bool condicion4;
  bool condicion5;
  bool condicion6;
  bool condicion7;	
	
	if (alfabeto_.analizar(expresion)) {    // Comprobamos que los símbolos de la cadena pertenecen al alfabeto.
		for (int i = 1; i < auxInfija.size(); ++i) {
	       condicion1 = auxInfija[i - 1] != PABIERTO;
         condicion2 = auxInfija[i - 1] != OR;
         condicion3 = auxInfija[i - 1] != CONCATENA;
         condicion4 = auxInfija[i] != OR;
         condicion5 = auxInfija[i] != PCERRADO;
         condicion6 = auxInfija[i] != STAR;
         condicion7 = auxInfija[i] != CONCATENA;
	 	   //std::cout << "auxInfija[i]: " << auxInfija[i] << " " << i << NEWLINE;
	 	   //std::cout << "auxInfija[i+1]: " << auxInfija[i + 1] << " " << i << NEWLINE;
			if ((condicion1 && condicion2 && condicion3) && (condicion4 && condicion5 && condicion6 && condicion7)) {
			   auxInfija.insert(i, CONCATENACION);
				 i++;
				//std::cout << "Después de insertar &: " << auxInfija << NEWLINE;
			}
		}	
	}
	else {
		std::cerr << "ERROR: Al menos un simbolo de la expresión regular no pertenece al alfabeto" << NEWLINE;
		exit(EXIT_FAILURE);
	}
 std::cout << "Después de insertar &: " << auxInfija << NEWLINE;
	return auxInfija;
}

// Método que lee el fichero de entrada, aplica los algoritmos 1 y 2 a las
// ER leidas y finalmente almacena cada ER en el vector de Expresiones
// Regulares.
void ER2Tree::run (std::string& ficheroEntrada) {
	std::ifstream entrada;
	entrada.open(ficheroEntrada);

	if (!entrada.is_open())
		std::cerr << "Ha ocurrido un problema al abrir el fichero de entrada, por favor inténtelo de nuevo" << NEWLINE;
	else {
		std::string leido;
		std::string auxInfija; //Es la expresión leida en infija pero con los & puestos donde hay una concatenación
		
		while (!entrada.eof()) {
			std::getline(entrada, leido);
			ExpresionRegular expresionActual(leido);
			auxInfija = introduceConcatenacion(expresionActual);
			algoritmo1(expresionActual, auxInfija);      // Convertimos a postfija.
		  algoritmo2(expresionActual); // Construimos el árbol a partir de la expresión postfija
			leido.clear();
			auxInfija.clear();


		}
	}
}



// Convierte la expresión regular de notación infija a postfija.
void ER2Tree::algoritmo1 (ExpresionRegular& expresionRegular, std::string& auxInfija) {
	std::stack<char> pila;
	std::string auxPostfija;
	char auxChar;
	char auxOpcion;

	if (pila.empty())
	std::cout << "auxInfija = " << auxInfija << NEWLINE;

	for (int i = 0; i < auxInfija.size(); ++i) {
	//	if (pila.empty() || pila.top() == PABIERTO) {
		std::cout << "auxInfija[i]: " << auxInfija[i] << NEWLINE;
		auxOpcion = auxInfija[i];
			switch (auxOpcion) {
				case '(':
					{
						std::cout << "Ha entrado en PABIERTO\n";
						auxChar = auxInfija[i];
						pila.push(auxChar);
						break;
					}
				case '|':
					{
						auxChar = auxInfija[i];
						pila.push(auxChar);
						std::cout << "Ha entrado en OR\n";
						break;
					}
				case '&':
					{
						std::cout << "Ha entrado en CONCATENA\n";
						if (pila.top() == CONCATENA) {
							auxPostfija.push_back(CONCATENA);
							pila.pop();
						  pila.push(auxOpcion);
						}
						else {
							auxChar = auxInfija[i];
							pila.push(auxChar);
						}
						break;
					}
				case '*':
					{
						std::cout << "Ha entrado en STAR\n";
						auxPostfija.push_back(STAR);
						break;
					}
				case ')':
					{
						std::cout << "Ha entrado en PCERRADO\n";
						while ((pila.top() != PABIERTO) && (!pila.empty())) {
							auxChar = pila.top();
						//	std::cout << "top: " << auxChar << NEWLINE;
							auxPostfija.push_back(auxChar);
							pila.pop();
						}
						break;
					}
				default:
					{
						std::cout << "Ha entrado en DEFAULT\n";
						auxChar = auxInfija[i];
						auxPostfija.push_back(auxChar);
						break;
					}
			}
		//}
	}
	while (!pila.empty()) {
	std::cout << "Pila.top: " << pila.top() << NEWLINE;
		if (pila.top() != PABIERTO) {
		  auxChar = pila.top();
		  auxPostfija.push_back(auxChar);
		}
		pila.pop();
	}
	expresionRegular.setPostfija(auxPostfija);
	std::cout << "Resultado de aplicar el algoritmo 1: " << auxPostfija << NEWLINE;
}


// Obtiene el árbol de una expresión regular en notación postfija.
void ER2Tree::algoritmo2 (ExpresionRegular& expresion) {
	std::stack<Nodo> pila // Pila que irá almacenando el árbol en cuestión.
	bool condicion1;
	bool condicion2;
	bool condicion3;
	bool condicion4;

	// TODO:
	// Crear árbol;
	// Inicializar árbol;
	// Meter el árbol en la pila.
		
		for (int i = 0; i < expresion.getPostfija().size(); ++i) {
			condicion1 = expresion.getPostfija()[i] != OR;
			condicion2 = expresion.getPostfija()[i] != STAR;
			condicion3 = expresion.getPostfija()[i] != CONCATENA;

		if (condicion1 && condicion2 && condicion3) {
			// Si es un operando, genera un nuevo nodo e introducirlo en el árbol.
		}
	}
}

