/*
=============================================================================
 Name        : TP_1.c
 Author      : Iván Rudiferia
=============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "calcular.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcionElegida;
	float kmVuelo;
	float precioAerolineas;
	float precioLatam;
	char empresaAElegir;
	float diferenciaPrecio;

	float precioDebitoLatam;
	float precioCreditoLatam;
	float precioBitcoinLatam;
	float precioPorKmLatam;

	float precioDebitoAerolineas;
	float precioCreditoAerolineas;
	float precioBitcoinAerolineas;
	float precioPorKmAerolineas;

	int banderaCalculos;

	float precioAerolineasForzado;
	float precioLatamForzado;
	float kmVueloForzado;

	kmVueloForzado = 7090;
	precioAerolineasForzado = 162965;
	precioLatamForzado = 159339;

	banderaCalculos = 0;

	kmVuelo = 0;
	precioAerolineas = 0;
	precioLatam = 0;

	do {
		printf("Elija una opción: \n"
				"1)Ingresar kilometros del vuelo. \n"
				"2)Ingresar precio de los vuelos. \n"
				"3)Calcular costos. \n"
				"4)Informar resultados. \n"
				"5)Carga forzada de datos. \n"
				"6)Salir.");
		scanf("%d", &opcionElegida);

		while(opcionElegida < 1 || opcionElegida > 6) {
			printf("¡Error! \n"
					"Elija una opción: \n"
					"1)Ingresar kilometros del vuelo. \n"
					"2)Ingresar precio de los vuelos. \n"
					"3)Calcular costos. \n"
					"4)Informar resultados. \n"
					"5)Carga forzada de datos. \n"
					"6)Salir.");
			scanf("%d", &opcionElegida);
		}

		switch (opcionElegida) {
			case 1:

				do {
					printf("Ingrese la cantidad de km totales del vuelo: (KMs actuales ingresados: %2.fKm)", kmVuelo);
					scanf("%f", &kmVuelo);
				}while(kmVuelo < 1);
				break;
			case 2:
				printf("Elija la empresa: (Precios actuales: Aerolineas: $%.2f - Latam: $%.2f)\n"
						"A)Aerolineas. \n"
						"L)Latam.", precioAerolineas, precioLatam);
				fflush(stdin);
				scanf("%c", &empresaAElegir);
				tolower(empresaAElegir);
					while (empresaAElegir != 'a' && empresaAElegir != 'l' && empresaAElegir != 'A' && empresaAElegir != 'L') {
						printf("¡Error! \n"
								"Elija la empresa: \n"
								"A)Aerolineas. \n"
								"L)Latam.");
						fflush(stdin);
						scanf("%c", &empresaAElegir);
						tolower(empresaAElegir);
					}
					if (empresaAElegir == 'a' || empresaAElegir == 'A') {
						printf("Ingrese el precio en Aerolineas: ");
						scanf("%f", &precioAerolineas);
					}
					else {
						printf("Ingrese el precio en Latam: ");
						scanf("%f", &precioLatam);
					}
				break;
			case 3:

				if ((precioLatam > 0 || precioAerolineas > 0) && kmVuelo > 0){
					calcularPrecios (&precioDebitoLatam, &precioCreditoLatam, &precioBitcoinLatam,
									&precioPorKmLatam, precioLatam, kmVuelo);
					calcularPrecios (&precioDebitoAerolineas, &precioCreditoAerolineas, &precioBitcoinAerolineas,
										&precioPorKmAerolineas, precioAerolineas, kmVuelo);
					diferenciaPrecio = calcularDiferencia(precioAerolineas, precioLatam);

					banderaCalculos = 1;

					printf("Calculos realizados exitosamente, ya puede ver los resultados.\n");
				}
				else {
					if (kmVuelo < 1){
						printf("No ingreso los Km totales del vuelo.\n");
					}
					else {
						if (precioLatam < 1 && precioAerolineas < 1) {
							printf("Calculos no realizados, no ingreso ningún precio.\n");
						}
					}
				}
				break;
			case 4:

				if (banderaCalculos == 0){
					printf("No se realizaron calculos, no hay nada que mostrar.\n");
				}
				else {
					printf("\nKms ingresados: %.2f\n", kmVuelo);

					if (precioAerolineas > 0){
						presentarDatosAerolineas(precioAerolineas, precioDebitoAerolineas, precioCreditoAerolineas,
												precioBitcoinAerolineas, precioPorKmAerolineas);
					}
					else {
						printf("\nNo se ingresaron precios de Aerolineas.\n");
					}

					if(precioLatam > 0) {
						presentarDatosLatam(precioLatam, precioDebitoLatam, precioCreditoLatam,
								precioBitcoinLatam, precioPorKmLatam);
					}
					else {
						printf("\nNo se ingresaron precios de Latam.\n");
					}

					mostrarDiferencia(diferenciaPrecio);
				}
				break;
			case 5:
				calcularPrecios (&precioDebitoLatam, &precioCreditoLatam, &precioBitcoinLatam,
									&precioPorKmLatam, precioLatamForzado, kmVueloForzado);
				calcularPrecios (&precioDebitoAerolineas, &precioCreditoAerolineas, &precioBitcoinAerolineas,
								 &precioPorKmAerolineas, precioAerolineasForzado, kmVueloForzado);

				presentarDatosAerolineas(precioAerolineasForzado, precioDebitoAerolineas, precioCreditoAerolineas,
											precioBitcoinAerolineas, precioPorKmAerolineas);

				presentarDatosLatam(precioLatamForzado, precioDebitoLatam, precioCreditoLatam,
										precioBitcoinLatam, precioPorKmLatam);

				diferenciaPrecio = calcularDiferencia(precioAerolineasForzado, precioLatamForzado);
				mostrarDiferencia(diferenciaPrecio);
				break;
		}
	}while(opcionElegida != 6);

	printf("¡Hasta la proxima!");

	return 0;
}
