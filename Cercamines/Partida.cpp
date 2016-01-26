#include "Partida.h"
#include <iostream>
#include <conio.h>

const int OPCIO_SI = 'S';
const int OPCIO_NO = 'N';
const int OPCIO_MARCA = 'M';
const int OPCIO_DESTAPA = 'D';

/**
* Constructor per defecte de la classe Partida
*/
Partida::Partida()
{
	m_nivell = 0;
}


/**
* Destructor per defecte de la classe Partida
*/
Partida::~Partida()
{

}


/**
* Constructor de la classe partida
* @param nivell nivell en què es troba el jugador
*/
Partida::Partida(int nivell)
{
	m_nivell = nivell;
	m_tauler.inicialitza(nivell);
}


/**
* Bucle principal del joc
* @return la puntuacio que ha obtingut el jugador en la partida
*/
int Partida::juga()
{
	int fila, columna, accio;
	char opcio;

	do
	{
		cout << "Fila, Columna, Accio: Marca/Destapa (M/D): ";
		do{
			cin >> fila, columna, opcio;
		} while ((fila < 0 || m_tauler.getMida()) && (columna < 0 || m_tauler.getMida()) 
			&& (opcio != OPCIO_DESTAPA || opcio != OPCIO_MARCA));

		switch (opcio)
		{
		case OPCIO_DESTAPA:
			m_tauler.destapaCasella(fila, columna, /*bool puntua?*/);
			break;

		case OPCIO_MARCA:
			m_tauler.marcaCasella(fila, columna);
			break;

			m_tauler.dibuixa();
		}

	} while ((!m_tauler.getEstatCompletat()) && (!m_tauler.getEstatExplotat()));


	// Intueixo que això va aquí 
	/*
	char opcio;

	cout << "Vols jugar una altra partida?: ";
	do{
		cin >> opcio;
	} while (opcio != OPCIO_SI || opcio != OPCIO_NO);

	switch (opcio)
	{
	case OPCIO_SI:
		break;

	case OPCIO_NO:
		break;
	}
	*/

	return m_tauler.getPuntuacio();
}