#include "Partida.h"
#include "Puntuacions.h"
#include <iostream>
#include <conio.h>

using namespace std;

const int OPCIO_JUGAR = 'J';
const int OPCIO_NOM = 'N';
const int OPCIO_NIVELL = 'L';
const int OPCIO_PUNTS = 'P';
const int OPCIO_SORTIR = 'S';

const int NUM_CARACTERS_NOM = 15;

void  main()
{
	Partida partida;
	Puntuacions puntuacions;
	tResultat dades;
	char opcio;

	cout << "Jugar \n";
	cout << "Mostar opcions ordenades per nom (N) \n";
	cout << "Mostar opcions ordenades per nivell (L) \n";
	cout << "Mostar opcions ordenades per punts (P) \n";
	cout << "Sortir (S) \n";

	do
	{
		opcio = _getch();

		switch (opcio)
		{
		case OPCIO_JUGAR:
			cout << "Introdueix el nom: ";
			cin >> dades.nom;
			cout << "\n\n\n Tria el nivell: ";
			cin >> dades.nivell;
			partida = Partida(dades.nivell);
			dades.puntuacio = partida.juga();
			cout << "Puntuacio = %d", dades.puntuacio;
			cout << "Jugador: %c", dades.nom, "Nivell: %d ", dades.nivell, "Puntuacio: %d", dades.puntuacio;
			break;

		case OPCIO_NOM:
			puntuacions.veureOrdenatPerNom();
			break;

		case OPCIO_NIVELL:
			puntuacions.veureOrdenatPerNivell();
			break;

		case OPCIO_PUNTS:
			puntuacions.veureOrdenatPerPuntuacio();
			break;
		}

	} while (opcio != OPCIO_SORTIR);

	// Actualitza els resultats
	puntuacions.desaResultat(dades);

	
}