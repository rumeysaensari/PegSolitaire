#include"PegSoliter.h"

#include<iostream>
#include<string>




using namespace std;




PegSoliter::Cell::Cell(int row,int column, point x){
	this->row=row;
	this->column=column;
	this->x=x;

}
PegSoliter::PegSoliter(){

}

PegSoliter::~PegSoliter(){

	
}


void PegSoliter::initBoard(){

	v1={
		{Cell(0,0,point::space),	Cell(0,1,point::space),	 Cell(0,2,point::space),	Cell(0,3,point::letter),		Cell(0,4,point::letter),		Cell(0,5,point::letter),		Cell(0,6,point::space),	 Cell(0,7,point::space),	Cell(0,8,point::space)	},
		{Cell(1,0,point::space),	Cell(1,1,point::space),	 Cell(1,2,point::space),	Cell(1,3,point::letter),		Cell(1,4,point::letter),		Cell(1,5,point::letter),		Cell(1,6,point::space),	 Cell(1,7,point::space),	Cell(1,8,point::space)	},
		{Cell(2,0,point::space),	Cell(2,1,point::space),	 Cell(2,2,point::space),	Cell(2,3,point::letter),		Cell(2,4,point::letter),		Cell(2,5,point::letter),		Cell(2,6,point::space),	 Cell(2,7,point::space),	Cell(2,8,point::space)	},
		{Cell(3,0,point::letter),	Cell(3,1,point::letter), Cell(3,2,point::letter),	Cell(3,3,point::letter),		Cell(3,4,point::letter),		Cell(3,5,point::letter),		Cell(3,6,point::letter), Cell(3,7,point::letter),	Cell(3,8,point::letter)	},
		{Cell(4,0,point::letter),	Cell(4,1,point::letter), Cell(4,2,point::letter),	Cell(4,3,point::letter),		Cell(4,4,point::dot),			Cell(4,5,point::letter),		Cell(4,6,point::letter), Cell(4,7,point::letter),	Cell(4,8,point::letter)	},
		{Cell(5,0,point::letter),	Cell(5,1,point::letter), Cell(5,2,point::letter),	Cell(5,3,point::letter),		Cell(5,4,point::letter),		Cell(5,5,point::letter),		Cell(5,6,point::letter), Cell(5,7,point::letter),	Cell(5,8,point::letter)	},
		{Cell(6,0,point::space),	Cell(6,1,point::space),	 Cell(6,2,point::space),	Cell(6,3,point::letter),		Cell(6,4,point::letter),		Cell(6,5,point::letter),		Cell(6,6,point::space),	 Cell(6,7,point::space),	Cell(6,8,point::space)	},
		{Cell(7,0,point::space),	Cell(7,1,point::space),	 Cell(7,2,point::space),	Cell(7,3,point::letter),		Cell(7,4,point::letter),		Cell(7,5,point::letter),		Cell(7,6,point::space),	 Cell(7,7,point::space),	Cell(7,8,point::space)	},
		{Cell(8,0,point::space),	Cell(8,1,point::space),	 Cell(8,2,point::space),	Cell(8,3,point::letter),		Cell(8,4,point::letter),		Cell(8,5,point::letter),		Cell(8,6,point::space),	 Cell(8,7,point::space),	Cell(8,8,point::space)	}
	};

}

void PegSoliter::printBoard(){
	point temp;
	for(int i=0;i<9;i++){
		for(int j=0; j<9; j++){
			temp=v1[i][j].getPoint();
			if(point::dot==temp){
				cout<<".";
			}
			if(point::letter==temp){
				cout<<"P";
			}
			if(point::space==temp){
				cout<<" ";
			}
		}
		cout<<"\n";
	}
}
int PegSoliter::typecasting(char letter)
{
	int let;
	switch(letter)
	{
		case 'A' : case 'a':
			let=0;
			break;

		case 'B' : case 'b':
			let=1;
			break;

		case 'C' : case 'c':
			let=2;
			break;	

		case 'D' : case 'd':
			let=3;
			break;		
		
		case 'E' : case 'e':
			let=4;
			break;

		case 'F' : case 'f':
			let=5;
			break;

		case 'G' : case 'g':
			let=6;
			break;

		case 'H' : case 'h':
			let=7;
			break;	

		case 'I' : case 'i':
			let=8;
			break;

		case 'J' : case 'j':
			let=9;
			break;	

	}
	return let;
}
bool PegSoliter::Cell::operator!=(const Cell c )const{
	return this->x!=c.x;
}

bool PegSoliter::Cell::operator==(const Cell c )const{
	return this->x==c.x;
}
// if return 1 game is over 
// if return 0 I did move valid 
int PegSoliter::move(string str){
	
				int num=str[1]-49;
				char direction=str[3];
				int let=typecasting(str[0]);

				int row=9,column=9;


				if((direction=='R' || direction=='r')  && let<row-2 && v1[num][let].getPoint()!=point::space )
				{
					if(v1[num][let].getPoint()==point::letter && v1[num][let+1].getPoint()==point::letter && v1[num][let+2].getPoint()==point::dot)
					{
						v1[num][let+1].setPoint(point::dot);
						v1[num][let+2].setPoint(point::letter);
						v1[num][let].setPoint(point::dot);
						printBoard();
						
						if(final()==1)
							return 1;
					}
					else if(v1[num][let].getPoint()!=point::space || v1[num][let+2].getPoint()!=point::space){
						cerr<<"Error! Try again."<<endl;
						printBoard();
					}

					else{
						cerr<<"Error! Try again."<<endl;
						printBoard();
	
					}
					
				}
				else if((direction=='L' || direction=='l') && let>1 && v1[num][let].getPoint()!=point::space )
				{
					if(v1[num][let].getPoint()==point::letter && v1[num][let-1].getPoint()==point::letter && v1[num][let-2].getPoint()==point::dot)
					{
						v1[num][let-1].setPoint(point::dot);
						v1[num][let-2].setPoint(point::letter);
						v1[num][let].setPoint(point::dot);
						printBoard();

						if(final()==1)
							return 1;
					}
					else if(v1[num][let].getPoint()!=point::space || v1[num][let-2].getPoint()!=point::space){
						cerr<<"Error! Try again."<<endl;
						printBoard();

					}

					else{
						cerr<<"Error! Try again."<<endl;
						printBoard();

					}
				}
				else if((direction=='U' || direction=='u')&& num>1 && v1[num][let].getPoint()!=point::space )
				{
					if(v1[num][let].getPoint()==point::letter && v1[num-1][let].getPoint()==point::letter && v1[num-2][let].getPoint()==point::dot)
					{
						v1[num-1][let].setPoint(point::dot);
						v1[num-2][let].setPoint(point::letter);
						v1[num][let].setPoint(point::dot);
						printBoard();

						
						if(final()==1)
							return 1;
					}
					else if(v1[num][let].getPoint()!=point::space || v1[num-2][let].getPoint()!=point::space){
						cerr<<"Error! Try again."<<endl;
						printBoard();

					}
					else if(v1[num][let-1].getPoint()==point::space){
						cerr<<"Error! Try again."<<endl;
					}
					else{
						cout<<"Error! Try again."<<endl;
						printBoard();

					}
				}
				else if((direction=='D' || direction=='d') && num<row-2 && v1[num][let].getPoint()!=point::space)
				{
					if(v1[num][let].getPoint()==point::letter && v1[num+1][let].getPoint()==point::letter && v1[num+2][let].getPoint()==point::dot)
					{
						v1[num+1][let].setPoint(point::dot);
						v1[num+2][let].setPoint(point::letter);
						v1[num][let].setPoint(point::dot);
						printBoard();

						
						if(final()==1)
							return 1;
							
					
					}
					else if(v1[num][let].getPoint()!=point::space || v1[num+2][let].getPoint()!=point::space){
						cerr<<"Error! Try again."<<endl;
						printBoard();

					}
			
					else{
						cerr<<"Error! Try again."<<endl;
						printBoard();
		
					}
				}
				else
					cerr<<"Invalid. Please try."<<endl;
					




}

void PegSoliter::playUser(string str){
	move(str);
}


void PegSoliter::playUser(){
	while(0!=rand_move()){
		cout <<"a";
		printBoard();
		move();

	}
	cout<<"bitti";
		
}


int  PegSoliter::rand_move(){
	char direction;
					int num=rand()%9; 
					char letter=(char)(rand() % 9) + 65;
					int let=typecasting(letter);   
					
					int direct=rand()%4;
					if(direct==0)
					{
						direction='R';
					}
					else if (direct==1)
					{
						direction='L';
					}
					else if(direct==2)
					{
						direction='U';
					}
					else if (direct==3)
					{
						direction='D';
					}
					int y=num+1;
					cout<<letter<<y<<"-"<<direction<<endl;
					string temp="";
					//string =num+let+direction
					string str_temp(1,'-');
					string str_dir_temp(1,direction);
					string str_letter_temp(1,letter);

					temp =temp+ str_letter_temp;
					temp =temp+ to_string(num);

					temp = temp+ str_temp;//
					temp =temp +str_dir_temp;
					

					cout<<"----------------------------------------"+temp<<endl;
					int ret=move(temp);
					return ret;	
}


int PegSoliter::final(){  //To check if there are moves that can be made 
	int count=0;

	for (int i = 0; i < static_cast<int>(v1.size()); i++)
	{
		for (int j = 0; j < static_cast<int>(v1[0].size()); j++) //j=5
												//                                             p  .	
		{									        //                                             P  P
			if(j+2<static_cast<int>(v1.size()) && i+2<static_cast<int>(v1.size())) // so as not to exceed the vector size PP. .PP  .  P
			{
				if( (v1[i][j].getPoint()==v1[i][j+1].getPoint() && v1[i][j].getPoint()==point::letter && v1[i][j+2].getPoint()==point::dot ) || (v1[i][j+2].getPoint()==v1[i][j+1].getPoint() && v1[i][j].getPoint()==point::dot && v1[i][j+2].getPoint()==point::letter ) || ( v1[i][j].getPoint()==v1[i+1][j].getPoint() && v1[i][j].getPoint()==point::letter && v1[i+2][j].getPoint()==point::dot) || ( v1[i+2][j].getPoint()==v1[i+1][j].getPoint() && v1[i][j].getPoint()==point::dot && v1[i+2][j].getPoint()==point::letter) )
					count=1;
			}		
			if(j-2>=0 && i-2>=0) //to set the vector size
			{
					if( ( v1[i][j-2].getPoint()==v1[i][j-1].getPoint() && v1[i][j-1].getPoint()==point::letter && v1[i][j].getPoint()==point::dot ) ||  (v1[i][j].getPoint()==v1[i][j-1].getPoint() && v1[i][j-2].getPoint()==point::dot && v1[i][j].getPoint()==point::letter ) || ( v1[i-2][j].getPoint()==v1[i-1][j].getPoint() && v1[i-1][j].getPoint()==point::letter && v1[i][j].getPoint()==point::dot ) || ( v1[i][j].getPoint()==v1[i-1][j].getPoint() && v1[i-2][j].getPoint()==point::dot && v1[i][j].getPoint()==point::letter ) )
					count=1;
			}
		}
	}	
return count;
}