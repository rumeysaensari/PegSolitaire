#ifndef __BOARDGAME__
#define __BOARDGAME__

#include<string>

using namespace std;
class BoardGame2D
{
public:
	BoardGame2D();
	~BoardGame2D();

	virtual void initBoard();
	virtual void printBoard();
	virtual void playUser(string str);
	virtual void playUser();
	
	int move(string str);
	int typcast(char);  

	
};

#endif