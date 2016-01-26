#include "LlistaPuntuacio.h"

class Node
{
public:
	Node();
	~Node();

	LlistaPuntuacio& getValor();
	Node* getNext();
	void setValor(LlistaPuntuacio valor);
	void setNext(Node* next);

private:
	LlistaPuntuacio m_valor;
	Node* m_next;

};