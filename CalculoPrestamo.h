#ifndef CALCULOPRESTAMO_CALCULOPRESTAMO_H
#define CALCULOPRESTAMO_CALCULOPRESTAMO_H


#include <cstdint>
#include <string>
#include <string.h>

class CalculoPrestamo {
		// atributos y metodos privados de la clase
	float monto;

	float obtenerPorcentaje(std::string porcentajeTXT);


	int calcularTiempoEnMeses(std::string tiempoTXT);

	float calcularInteresesMensual(float balance, float tasaAnual);
	
	// metodos publicos de la clase
public:
	CalculoPrestamo();

	explicit CalculoPrestamo(int64_t monto);

	std::string reporteCalculoPrestamo(std::string tiempoTXT, std::string
		porcentajeTXT);

	//metodos set y get

	float getMonto() const;

	void setMonto(float monto);

};

#endif //CALCULOPRESTAMO_CALCULOPRESTAMO_H
