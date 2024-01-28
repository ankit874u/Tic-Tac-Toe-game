#include<iostream>
using namespace std;


char arr[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}}; //2d array
char turn = 'x';
int row,coloumn;
bool draw = false;

void display_board(){
    system("cls");

    cout<<"TIC TAC TOE GAME:-"<<endl;
    cout<<"\t player1 [x] \n\t player2 [0]\n\n";

    cout<<"    |     |     \n";
    cout<<"  "<<arr[0][0]<<" |  "<<arr[0][1]<<"  |  "<<arr[0][2]<<"  \n";
    cout<<"----|-----|-----\n";
    cout<<"    |     |     \n";
    cout<<"  "<<arr[1][0]<<" |  "<<arr[1][1]<<"  |  "<<arr[1][2]<<"  \n";
    cout<<"----|-----|-----\n";
    cout<<"  "<<arr[2][0]<<" |  "<<arr[2][1]<<"  |  "<<arr[2][2]<<"  \n";
    cout<<"    |     |     \n"; 
}
void player_turn(){
    int choice;
    if(turn == 'x')
    cout<<"\n\t player1[x] turn:";
    if(turn == 'o')
    cout<<"\n\t player2[o] turn:";
    cin>>choice;

    switch(choice){
        case 1: row=0; coloumn=0; break;
        case 2: row=0; coloumn=1; break;
        case 3: row=0; coloumn=2; break;
        case 4: row=1; coloumn=0; break;
        case 5: row=1; coloumn=1; break;
        case 6: row=1; coloumn=2; break;
        case 7: row=2; coloumn=0; break;
        case 8: row=2; coloumn=1; break;
        case 9: row=2; coloumn=2; break;
        default:
        cout<<"invalid choice\n";  break;  
    }

    if(turn == 'x' && arr[row][coloumn]!='x' && arr[row][coloumn]!= 'o'){
        arr[row][coloumn] = 'x';
        turn = 'o';
    } 
      
    else if(turn == 'o' && arr[row][coloumn]!='x' && arr[row][coloumn]!= 'o'){
        arr[row][coloumn] = 'o';
        turn = 'x';
    }
    else{
        cout<<"Box already filled!\n please try again! \n\n";
        player_turn();
    }
     display_board();
    }

    bool gameover(){
       //check win game 
       for(int i=0;i<3;i++)
       //if(arr[0][0] == [0][1] && arr[0][0] == [0][2])
       //return false;
       if(arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2]|| arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i]) 
       return false;

       if(arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] || arr[0][2]  == arr[1][1] && arr[0][2] == arr[2][0])
       return false;
        //if there is any box not field
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        if(arr[i][j] != 'x' && arr[i][j] != 'o')
        return true;
        //draw
        draw = true;
        return false;
    }
int main() { 
    while(gameover())
    {
    display_board();
    player_turn();
    gameover(); 
    } 

if(turn =='x' && draw == false)
cout<<"player2 [o] wine!! congratulations\n";
else if(turn =='o' && draw == false)
cout<<"player1 [x] wine!! congratulations\n";
else
cout<<"game draw!!\n";

return 0;
}