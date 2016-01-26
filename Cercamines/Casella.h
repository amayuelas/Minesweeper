class Casella
{
public:
	Casella();
	~Casella();

	bool getMinada();
	void setMinada(bool minada);
	bool getMarcada();
	void setMarcada(bool marcada);
	bool getTapada();
	void setTapada(bool tapada);
	bool getExplotada();
	void setExplotada(bool explotada);
	int getVeinesMinades() const;
	void incrementaVeinesMinades();

private: 
	bool m_minada;
	bool m_marcada;
	bool m_tapada;
	int m_numVeinesMinades;
	bool m_explotada;
};