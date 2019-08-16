#include <iostream>
#include <string>
#include <string.h>
#include "CalculoPrestamo.h"

//llamado al constructor sin parametros
CalculoPrestamo::CalculoPrestamo() {

	setMonto(0);

};

//llamado al constructor con parametros
 CalculoPrestamo::CalculoPrestamo(int64_t monto) : monto(monto){}


//llamados de los metodos 
float CalculoPrestamo::obtenerPorcentaje(std::string porcentajeTXT) {

	float p = 0;

	int bp = porcentajeTXT.find("%");

	if (bp > 0) {	

		p = std::stof(porcentajeTXT.substr(0, bp));	 // busca el rango del valor %

		if (p > 0) {

			p = p / 100;
		}

	}

	return p;
}



int CalculoPrestamo::calcularTiempoEnMeses(std::string tiempoTXT){

	int m;
	int a;

	int bta = tiempoTXT.find("A");
	int btm = tiempoTXT.find("M");

	if (bta > 0) {

		a = stoi(tiempoTXT.substr(0, bta));   //busca el rango en anos

		if (a > 0) {

			m = a * 12;						// convierte los anos en meses
		}
	}

	if (btm > 0) {

		m = stoi(tiempoTXT.substr(0, btm));			//busca el rango en meses


	}

	return m;	//retorna el valor en meses
}

float CalculoPrestamo::calcularInteresesMensual(float balance, float tasaAnual){

	float tm = tasaAnual / 12;
									//calcula los intereses mensuales 
	float in = tm * balance;
		
	return in;		//retorna el interes mensual


}


std::string CalculoPrestamo::reporteCalculoPrestamo(std::string tiempoTXT, std::string porcentajeTXT) {

	std::string reporte = " ";

	int meses = calcularTiempoEnMeses(tiempoTXT);

	float por = obtenerPorcentaje(porcentajeTXT);			// llama los metodos necesarios para imprimor por pantalla

	float bl = getMonto();

	float bln = getMonto();

	for (int mes = 1; mes <= meses; ++mes) {			//ciclo para mostrar cada mes con sus respectivos valores 

		float inmensual = calcularInteresesMensual(bln, por);

		bl = bln;

		bln = bl + inmensual;


		reporte = reporte + "Tasa [" + porcentajeTXT + "], Mes[" + std::to_string(mes) + "], balance inicial[" + std::to_string(bl) + "],interes[" + std::to_string(inmensual) + "], balance nuevo[" + std::to_string(bln) +"]\n";

	}
	return reporte;  // retorna todos los meses con los respectivos valores
}


// llamado de los metodos set y get 

float CalculoPrestamo::getMonto() const{

	return monto;
}



void CalculoPrestamo::setMonto(float monto){

	CalculoPrestamo::monto = monto;
}
