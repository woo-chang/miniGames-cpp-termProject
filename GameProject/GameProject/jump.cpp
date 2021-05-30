#include "jumpGame.h"


using namespace std;



void JumpGame::	init (){
	system("mode con cols=110 lines=40 | title jumpGame"); //콘솔창 크기
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//콘솔핸들가져오기 
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize =1; 
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}
int JumpGame::input_k(){

	if(_kbhit()!= 0) {
		return _getch();
	}
	return 0;

}


int JumpGame::menu(){
	int x=45,y=20;
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"                        O        O         O        O             O        O O O O O O  "<<endl;
	cout<<"                        O        O         O        O  O       O  O        O           O"<<endl;
	cout<<"                        O        O         O        O    O   O    O        O           O"<<endl;
	cout<<"                        O        O         O        O      O      O        O O O O O O  "<<endl;
	cout<<"                        O        O         O        O             O        O            "<<endl;
	cout<<"              O         O        O         O        O             O        O            "<<endl;
	cout<<"              O         O        O         O        O             O        O            "<<endl;
	cout<<"               O O O O O          O O O O O         O             O        O            "<<endl;
	
	gotoxy(10,25);
	
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"             w( ↑ )                   "<<endl;
	cout<<"   a( ← )               ( → )d        "<<endl;
	cout<<"             s( ↓ )                   "<<endl<<endl;
	cout<<"           space bar( 선택 )          "<<endl<<endl; 
	gotoxy(x-2,y);
	cout<<"> 게임시작 "<<endl;
	gotoxy(x,y+1);
	cout<<"  종료     "<<endl;
	

	while(1){
		char temp = input_k();
		if(temp=='w' && y>20){
			gotoxy(x-2,y);
			cout<<" ";
			gotoxy(x-2,--y);
			cout<<">";
		 
		}
		else if(temp=='s' && y<21){
			gotoxy(x-2,y);
			cout<<" ";
			gotoxy(x-2,++y);
			cout<<">";
		 	
		}
		
		else if(temp==' ') return y-20; //스페이스바로 선택후return (게임시작:0,종료:1)  
		
	}
}

void JumpGame::gotoxy(int x, int y){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
void JumpGame:: Dino_draw(int dino_move){
	gotoxy(0,dino_move);
	static bool legFlag = true;
	cout<<"           ■■■■■■"<<endl;
	cout<<"          ■■ ■■■■■"<<endl;
	cout<<"          ■■ ■■■■■"<<endl;
	cout<<"          ■■■■■■■"<<endl;
	cout<<"■        ■■■"<<endl;
	cout<<"■■      ■■■■■■"<<endl;
	cout<<" ■■     ■■■■"<<endl;
	cout<<"  ■■    ■■■■■■■■"<<endl;
	cout<<"   ■■■■■■■■■   ■"<<endl;
	cout<<"    ■■■■■■■■"<<endl;
	cout<<"      ■■■■■■" <<endl;
	
	if(legFlag){
		cout<<"     ■    ■■■"<<endl;
		cout<<"     ■■          ";
		legFlag=false;
	}
	else{
		cout<<"     ■■■   ■"<<endl;
		cout<<"              ■■";
		legFlag=true;
	}
}

void JumpGame:: tree(int tree_x){
	int tree_y=36;
	gotoxy(tree_x,tree_y);
	cout<<"   ■■■■  ";
	gotoxy(tree_x,tree_y+1);
	cout<<"     ■■  ";
	gotoxy(tree_x,tree_y+2);
	cout<<"     ■■";
	gotoxy(tree_x,tree_y+3);
	cout<<"     ■■";
}

void JumpGame:: DrawGameOver(const int score)
{
    system("cls");
    int x = 25;
    int y = 10;
    gotoxy(x, y);
    cout<<"===========================";
    gotoxy(x, y + 1);
    cout<<"======G A M E O V E R======";
    gotoxy(x, y + 2);    
    cout<<"===========================";
    gotoxy(x, y + 5);
    cout<<"SCORE : "<<score;
    cout<<endl<<endl<<endl<<endl;
    system("pause");
}


bool JumpGame:: gameover(const int tree_x, const int dino_move){
	gotoxy(0,0);
	if(tree_x<=8 && dino_move>25) {
	return true;
	}//충 돌  
	return false;
}
int JumpGame:: game_start(){
	int score=0;
	bool jump=false;
	bool j_condition=true;
	
	int dino_move=DINO_BOTTOM_Y;
	int tree_x=TREE_BOTTOM_X;
	
		while(true){
			
			if(gameover(tree_x,dino_move)){
				break;
			}
		
			//w를 누르고 바닥에 위치하면 jump 가능  
			if((input_k()=='w') && j_condition){ 
				jump=true;
				j_condition=false;
			}
			if(jump){
				dino_move-=20;
			} 
			else dino_move+=20;
			
			if(dino_move>=DINO_BOTTOM_Y){
				dino_move=DINO_BOTTOM_Y;
				j_condition=true;
			}
			
			if(dino_move<=5){
				jump=false;
			}
			
			tree_x-=7;
			if(tree_x<=0) {
				tree_x=TREE_BOTTOM_X;
				score++;	
			}
			
			Dino_draw(dino_move);
			tree(tree_x);
			
			gotoxy(80,0);
			cout<<"SCORE: "<<score<<endl;
			
			Sleep(80);
			system("cls");
	}
	
	DrawGameOver(score);
	return score;
	
	
	
}

