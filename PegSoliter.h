#ifndef __PEG__
#define __PEG__
#include<string>


using namespace std;
#include<vector>

enum class point{dot='.' ,letter='P' ,space=' '};

class PegSoliter
{
public:
	PegSoliter();
	~PegSoliter();
	
	void initBoard();
	void printBoard();
	int typecasting(char);  

	int move(string str);
	void playUser(string str);
	void playUser();




	class Cell{

		public:

			Cell(int,int,point);

			void setRow(int row){this->row=row;}
			void setColumn(int column){this->column=column;}
			void setPoint(point x){this->x=x;}

			int getRow()const{return row;}
			int getColumn()const{return column;}
			point getPoint(){return x;}

			bool operator!=(const Cell )const;
			bool operator==(const Cell )const;
		private:
			int row;
			int column;
			point x;
	};
	vector<vector<Cell>> v1;

	private:
	int  rand_move();
	int final();
};
#endif