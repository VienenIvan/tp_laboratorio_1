/*
 * calcular.c
 *
 *  Created on: 7 abr. 2022
 *      Author: Iván
 */

void calcularPrecios (float* tarjetaDebito, float* tarjetaCredito, float* bitcoin,
						float* precioPorKm, float precioVuelo, float kmVuelo) {

	float descuentoDebito;
	float aumentoCredito;
	float precioBitcoin;

	descuentoDebito = 0.9;
	aumentoCredito = 1.25;
	precioBitcoin = 4606954.55;

	*tarjetaDebito = precioVuelo * descuentoDebito;
	*tarjetaCredito = precioVuelo * aumentoCredito;
	*bitcoin = precioVuelo / precioBitcoin;
	*precioPorKm = precioVuelo / kmVuelo;
}

float calcularDiferencia(float precioAerolineas, float precioLatam)
{
	float respuesta;

	if (precioAerolineas == 0 || precioLatam == 0)
	{
		respuesta = 0;
	}
	else
	{
		if (precioAerolineas > precioLatam)
		{
			respuesta = precioAerolineas - precioLatam;
		}
		else
		{
			respuesta = precioLatam - precioAerolineas;
		}
	}

	return respuesta;
}

void presentarDatosAerolineas (float precioIngresadoAerolineas,
					float precioDebitoAerolineas, float precioCreditoAerolineas,
					float precioBtcAerolineas, float precioUnitarioAerolineas) {

	printf("\nPrecio Aerolineas: $%.2f.\n"
			"a) Precio con tarjeta de débito: $%.2f.\n"
			"b) Precio con tarjeta de crédito: $%.2f.\n"
			"c) Precio pagando con bitcoin : %f BTC.\n"
			"d) Precio unitario: $%.3f.\n", precioIngresadoAerolineas, precioDebitoAerolineas, precioCreditoAerolineas,
			precioBtcAerolineas, precioUnitarioAerolineas);
}

void presentarDatosLatam (float precioIngresadoLatam,
		float precioDebitoLatam, float precioCreditoLatam,
		float precioBtcLatam, float precioUnitarioLatam) {
	printf("\nPrecio Latam: %.2f.\n"
			"a) Precio con tarjeta de débito: $%.2f.\n"
			"b) Precio con tarjeta de crédito: $%.2f.\n"
			"c) Precio pagando con bitcoin : %f BTC.\n"
			"d) Precio unitario: $%.3f.\n", precioIngresadoLatam, precioDebitoLatam, precioCreditoLatam,
			precioBtcLatam, precioUnitarioLatam);
}

void mostrarDiferencia(float diferenciaPrecio){
	if (diferenciaPrecio == 0) {
		printf("\nNo hay diferencia ya que no se ingresó alguno de los dos precios.\n\n");
	}
	else {
		printf("\nLa diferencia de precio es: $%.2f\n\n", diferenciaPrecio);
	}
}
