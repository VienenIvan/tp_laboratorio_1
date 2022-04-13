/*
 * calcular.h
 *
 *  Created on: 7 abr. 2022
 *      Author: Iván
 */

/* Explicacion
 *
 * */

void calcularPrecios (float* tarjetaDebito, float* tarjetaCredito, float* bitcoin,
						float* precioPorKm, float precioVuelo, float kmVuelo);

float calcularDiferencia(float precioAerolineas, float precioLatam);

void presentarDatosAerolineas (float precioIngresadoAerolineas,
		float precioDebitoAerolineas, float precioCreditoAerolineas,
		float precioBtcAerolineas, float precioUnitarioAerolineas);

void presentarDatosLatam (float precioIngresadoLatam,
		float precioDebitoLatam, float precioCreditoLatam,
		float precioBtcLatam, float precioUnitarioLatam);

void mostrarDiferencia(float diferenciaPrecio);


#ifndef CALCULAR_H_
#define CALCULAR_H_

#endif /* CALCULAR_H_ */
