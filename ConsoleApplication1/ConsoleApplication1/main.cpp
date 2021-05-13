#include "match.h"

int main()
{
	CardGame* cardgame = new CardGame();
	cardgame->init();
	delete(cardgame);
	return 0;
}