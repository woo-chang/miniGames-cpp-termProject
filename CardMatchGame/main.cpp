#include "match.h"

int main()
{
	CardGame* cardgame = new CardGame();
	cardgame->init();
	cout << cardgame->getScore() << endl;
	delete(cardgame);
	return 0;
}