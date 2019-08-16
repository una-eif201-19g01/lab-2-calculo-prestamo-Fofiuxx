#include <iostream>
#include "CalculoPrestamo.h"


int main() {

	CalculoPrestamo calcuPres(30000); //creacion del objeto para usar la clase

	std::string reporte;


	reporte = calcuPres.reporteCalculoPrestamo("1A", "8.40%");	//llamado del reporte usando el objeto creado en el main


	std::cout << "Calcular Prestamo: " << std::endl; 
	std::cout << reporte << std::endl;






	return 0;
}