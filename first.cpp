#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
bool gameover=false,start=true,update=true;
int i,j,k,pastx,pasty,present_ballx=3,past_bally=4,present_bally=4,past_ballx=3,presentx,presenty;
char board[10][10];
void show(){
for (i=0;i<10;i++){
            for (j=0;j<10;j++){
                cout<<" "<<board[i][j]<<" ";
            }
                cout<<" "<<endl;
        }
}
void draw(){
    if(start){
      
        //border
        for(i=0;i<10;i++){
            board[i][0]='x'; 
            board[i][9]='x';
        }
        for(j=0;j<10;j++){
            board[0][j]='x'; 
            board[9][j]='x';
        }
    board[3][4]='o';
    //past_ballx=3;
    //past_bally=4;
   
    }
    if(update){
     board[pastx][pasty]='o';
    while(1){
        presentx=rand()%10+1;
        presenty=rand()%10+1;
        if(presentx>8 || presenty>8){
            continue;
            }else{
            board[presentx][presenty] = '8';
            pastx=presentx;
            pasty=presenty;
            update=false;
            break;
        }
    }    
   
    }
     show();
}
void move(){
board[past_ballx][past_bally]=' ';
 if(present_ballx<1 || present_ballx>8 ||present_bally<1 || present_bally>8 ){
present_ballx=past_ballx;
present_bally=past_bally;
 }
board[present_ballx][present_bally]='o';
past_ballx=present_ballx;
past_bally=present_bally;
}
char input(){
    char c =' ';
    if(start){
    cout<< "Welcome to O-CATCH-8 "<<endl;
    cout<< "LEVEL 1 "<<"Press ---"<< " left :l"<<endl;
    cout<< "right :r"<<endl;
    cout<< "up :u"<<endl;
    cout<< "down :d"<<endl;
    cout<< "quit the game:q"<<endl;
     start=false;
    }
    cout<<"input";
    cin>>c;
    switch(c){
        case 'l': present_bally=present_bally-1; move();break;
        case 'r': present_bally=present_bally+1; move();break;
        case 'u': present_ballx=present_ballx-1; move();break;
        case 'd': present_ballx=present_ballx+1; move();break;
    }
return c;
}
void logic(){

 if(presentx == present_ballx && presenty == present_bally){
  update=true;
 // board[presentx][presenty]='o';
 }   
}

int main(int argc, char const *argv[])
{  

    if(!gameover){
        draw();
        while(1){
       char p= input();
       if(p=='q'){
           break;
       }
        logic();
        draw();
       

        }
    }
      /* for (i=0;i<10;i++){
            for (j=0;j<10;j++){
            board[i][j]='*';
            }
        }*/
    //std::cout<<"weeeee"<<std::endl;
    return 0;
}
