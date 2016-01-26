#include "Casella.h"
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

const int MIDA_BASE = 5;

class Tauler
{
public:
	Tauler();
	~Tauler();

	void inicialitza(int nivell);
	void dibuixa();
	void marcaCasella(int fila, int columna);
	void desmarcaCasella(int fila, int columna);
	void destapaCasella(int fila, int columna, bool puntua);
	void incrementaVeinesMinades();
	bool getEstatCompletat();
	bool getEstatExplotat();
	// Agfegit per mi
	int getPuntuacio() const;
	int getMida() const;

private:
	Casella** m_tauler;
	int m_puntuacio;
	int m_mida;
	int m_numCaselles;
	int m_numCasellesDestapades;
	bool m_estatCompletat;
	bool m_estatExplotat;
};
