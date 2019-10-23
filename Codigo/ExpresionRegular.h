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
 * Archivo ExpresionRegular.h: Clase ExpresionRegular. Clase que representa una expresión regular con sus
 *                         tres posibles notaciones (infija, postfija y prefija).
 *                         Este fichero contiene la definición de la clase.
 *
 * Referencias:
 *                   Enunciado de la prácita:
 *                   https://campusvirtual.ull.es/1920/pluginfile.php/172406/mod_assign/introattachment/0/CYA_1920_Practica_5.pdf?forcedownload=1
 * Historial de revisiones
 *                   20/10/2019 - Creación (primera versión) del código
 * */

#ifndef PRACTICA5_ER_H
#define PRACTICA5_ER_H

#include <string>

const char NEWLINE = '\n';
const std::string CONCATENACION = "&";
const char CONCATENA = '&';
const char PABIERTO = '(';
const char PCERRADO = ')';
const char STAR = '*';
const char OR = '|';

class ExpresionRegular {
	public:
		ExpresionRegular (std::string infija);
		ExpresionRegular ();
		~ExpresionRegular ();

		std::string getInfija () const;
		std::string getPostfija () const;
		std::string getPrefija () const;
		
		void setInfija (std::string newInfija);
		void setPostfija (std::string newPostfija);
		void setPefija (std::string newPrefija);
	//	void insertarInfija (int i);

	protected:

	private:
		std::string infija_;    // Expresión Regular -> Notación infija.
		std::string postfija_;  // Expresión Regular -> Notación postfija.
		std::string prefija_;   // Expresión Regular -> Notación prefija.
};


#endif //PRACTICA5_ER_H
