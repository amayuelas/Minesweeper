#include "Tauler.h"
#include <iostream>

/**
* Constructor per defecte de la classe Tauler
*/
Tauler::Tauler()
{

}


/**
* Destructor per defecte de la classe Tauler
*/
Tauler::~Tauler()
{
	for (int i = 0; i < m_mida; i++)
		delete[] m_tauler[i];

	delete[] m_tauler;
}


/**
* Inicialitza el tauler
*/
void Tauler::inicialitza(int nivell)
{
	m_mida = MIDA_BASE*nivell;
	m_numCaselles = m_mida*m_mida;
	m_puntuacio = 0;
	m_numCasellesDestapades = 0;
	m_estatCompletat = false;
	m_estatExplotat = false;
	m_tauler = new Casella*[m_mida];

	for (int i = 0; i < m_mida; i++)
		m_tauler[i] = new Casella[m_mida];

	// Generar mines de manera aleatòria
	srand((unsigned int)time(NULL));
	int mines = m_mida;
	int fila, columna;
	int i, j;
	do{
		fila = rand() % m_mida;
		columna = rand() % m_mida;
		if (!m_tauler[fila][columna].getMinada())
		{
			m_tauler[fila][columna].setMinada(true);
			mines--;
			for (i = max(0, fila - 1); i < min(m_mida, fila + 2); i++)
			{
				for (j = max(0, columna - 1); j < min(m_mida, columna + 2); j++)
					m_tauler[i][j].incrementaVeinesMinades();
			}
		}
	} while (mines > 0);
}


/**
* Dibuixa tots els gràfics del tauler
*/
void Tauler::dibuixa()
{
	for (int i = 0; i < m_mida; i++)
	{
		for (int j = 0; j < m_mida; j++)
		{
			if (m_tauler[i][j].getExplotada())
				cout << " X ";
			else
			{
				if (!m_tauler[i][j].getTapada() && m_tauler[i][j].getVeinesMinades() == 0
					&& !m_tauler[i][j].getMinada())
					cout << " ";
				else
				{
					if (!m_tauler[i][j].getTapada() && m_tauler[i][j].getVeinesMinades() > 0)
						cout << " " << m_tauler[i][j].getVeinesMinades() << " ";
					else
					{
						if (m_tauler[i][j].getMarcada())
							cout << "[?]";
						else
						{
							if (!m_tauler[i][j].getTapada() && !m_tauler[i][j].getMarcada())
								cout << "[ ]";
							else
							{
								if (m_estatCompletat && m_tauler[i][j].getMinada())
									cout << "[*]";
							}
						}
					}
				}
			}
		}
	}
}


/**
* Permet marcar una casella
* @param fila fila en què es troba la casella
* @param columa columna en què es troba la casella
*/
void Tauler::marcaCasella(int fila, int columna)
{
	if (!m_tauler[fila][columna].getMarcada())
		m_tauler[fila][columna].setMarcada(true);
	else
		desmarcaCasella(fila, columna);
}


/**
* Permet desmarcar una casella
* @param fila fila en què es troba la casella
* @param columa columna en què es troba la casella
*/
void Tauler::desmarcaCasella(int fila, int columna)
{
	m_tauler[fila][columna].setMarcada(false);
}


/**
* Permet destapar una casella
* @param fila fila en què es troba la casella
* @param columa columna en què es troba la casella
*/
void Tauler::destapaCasella(int fila, int columna, bool puntua)
{
	if (m_tauler[fila][columna].getTapada())
	{
		if (m_tauler[fila][columna].getMinada())
		{
			m_estatExplotat = true;
			m_tauler[fila][columna].setExplotada(true);
		}
		else
		{
			m_tauler[fila][columna].setTapada(false);

			if (puntua)
				m_puntuacio++;

			m_numCasellesDestapades++;

			if (m_numCasellesDestapades != m_numCaselles - m_mida)
			{
				if (m_tauler[fila][columna].getVeinesMinades() == 0)
				{
					for (int i = max(0, fila - 1); i < min(m_mida, fila + 2); i++)
					{
						for (int j = max(0, columna - 1); j < min(m_mida, columna + 2); j++)
						{
							destapaCasella(i, j, false);
						}
					}
				}
			}
		}
	}
}


/**
* Ens diu s'hi ha explotat alguna de les caselles del joc
* @return true si alguna casella ha explotat i false si no n'ha explotat cap
*/
bool Tauler::getEstatExplotat()
{
	return m_estatExplotat;
}


/**
* Ens diu si s'ha completat el joc
* @return true si ha estat completat i false si no ha estat completat
*/
bool Tauler::getEstatCompletat()
{
	return m_estatCompletat;
}


/**
* Permet obtenir la puntuacio que té el jugador
* @return puntuacio que te el jugador
*/
int Tauler::getPuntuacio() const
{
	return m_puntuacio;
}


/**
* Permet obtenir la mida del tauler
* @return la mida del tauler
*/
int Tauler::getMida() const
{
	return m_mida;
}