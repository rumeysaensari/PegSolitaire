#include"BoardGame2D.h"
#include"PegSoliter.h"
#include<string>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	PegSoliter ps;
	ps.initBoard();
	ps.printBoard();
	string str="E3-D";
	cout<<str<<endl;
	cout<<"\n\n\n\n";
	ps.playUser();
	cout<<"\n\n\n\n";

	//ps.printBoard();

	return 0;
}