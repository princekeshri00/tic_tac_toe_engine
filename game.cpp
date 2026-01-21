//Prince Keshri (wizard_ninja)
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;

static string p1,p2;
static int type;

void clear(int r){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    if(r == 1) {
        if(type == 2) cout << "YOU ARE O\n";
        else cout << p1 + " IS O\n";

        cout << p2 + " IS X\n\n\n";
    }
}

void slp(int s) { 
    this_thread::sleep_for(chrono::seconds(s)); 
}
//------


class computer {
    private:
        int parse_array[9];

        int move_count() {
            int c = 0;
            for(int i = 0 ; i < 9 ; ++i) if(computer::parse_array[i] != 0) c++;
            return c;
        }

        int combo(int a, int b, int c, int p) {
            if(a == 0 && b == p && c == p) return 1;
            else if(a == p && b == 0 && c == p) return 2;
            else if(a == p && b == p && c == 0) return 3;

            return -1;
        }

        int isWL(int p) {

            // horizontal
            if(combo(computer::parse_array[0],computer::parse_array[1],computer::parse_array[2],p) == 1) return 0;
            if(combo(computer::parse_array[0],computer::parse_array[1],computer::parse_array[2],p) == 2) return 1;
            if(combo(computer::parse_array[0],computer::parse_array[1],computer::parse_array[2],p) == 3) return 2;
            if(combo(computer::parse_array[3],computer::parse_array[4],computer::parse_array[5],p) == 1) return 3;
            if(combo(computer::parse_array[3],computer::parse_array[4],computer::parse_array[5],p) == 2) return 4;
            if(combo(computer::parse_array[3],computer::parse_array[4],computer::parse_array[5],p) == 3) return 5;
            if(combo(computer::parse_array[6],computer::parse_array[7],computer::parse_array[8],p) == 1) return 6;
            if(combo(computer::parse_array[6],computer::parse_array[7],computer::parse_array[8],p) == 2) return 7;
            if(combo(computer::parse_array[6],computer::parse_array[7],computer::parse_array[8],p) == 3) return 8;
            //vertical
            if(combo(computer::parse_array[0],computer::parse_array[3],computer::parse_array[6],p) == 1) return 0;
            if(combo(computer::parse_array[0],computer::parse_array[3],computer::parse_array[6],p) == 2) return 3;
            if(combo(computer::parse_array[0],computer::parse_array[3],computer::parse_array[6],p) == 3) return 6;
            if(combo(computer::parse_array[1],computer::parse_array[4],computer::parse_array[7],p) == 1) return 1;
            if(combo(computer::parse_array[1],computer::parse_array[4],computer::parse_array[7],p) == 2) return 4;
            if(combo(computer::parse_array[1],computer::parse_array[4],computer::parse_array[7],p) == 3) return 7;
            if(combo(computer::parse_array[2],computer::parse_array[5],computer::parse_array[8],p) == 1) return 2;
            if(combo(computer::parse_array[2],computer::parse_array[5],computer::parse_array[8],p) == 2) return 5;
            if(combo(computer::parse_array[2],computer::parse_array[5],computer::parse_array[8],p) == 3) return 8;
            //l diagonal
            if(combo(computer::parse_array[0],computer::parse_array[4],computer::parse_array[8],p) == 1) return 0;
            if(combo(computer::parse_array[0],computer::parse_array[4],computer::parse_array[8],p) == 2) return 4;
            if(combo(computer::parse_array[0],computer::parse_array[4],computer::parse_array[8],p) == 3) return 8;
            //r diagonal
            if(combo(computer::parse_array[2],computer::parse_array[4],computer::parse_array[6],p) == 1) return 2;
            if(combo(computer::parse_array[2],computer::parse_array[4],computer::parse_array[6],p) == 2) return 4;
            if(combo(computer::parse_array[2],computer::parse_array[4],computer::parse_array[6],p) == 3) return 6;


            return -1;
        }

    
    public:
        void calculate(int p[3][3]) {
            int parse_index = 0;
            for(int i = 0; i < 3 ; ++i) for(int j = 0 ; j < 3 ; ++j) computer::parse_array[parse_index++] = p[i][j];

            int current_move = move_count() + 1;

            if(current_move == 1) computer::parse_array[4] = 2;
            else if(current_move == 2){
                if(computer::parse_array[0] == 1) computer::parse_array[8] = 2;
                else if(computer::parse_array[2] == 1) computer::parse_array[6] = 2;
                else if(computer::parse_array[6] == 1) computer::parse_array[2] = 2;
                else if(computer::parse_array[8] == 1) computer::parse_array[0] = 2;
                else if(computer::parse_array[4] == 1) computer::parse_array[0] = 2;
                else computer::parse_array[4] = 2;
            }
            else if(current_move == 3) {
                int r = rand()%3 + 1;
                if(r == 1) {
                    if(computer::parse_array[0] == 0) computer::parse_array[0] = 2;
                    else {
                        r = rand() % 2 + 1;
                        if(r == 1) computer::parse_array[2] = 2;
                        else if(r == 2) computer::parse_array[6] = 2;
                        else computer::parse_array[8] = 2;
                    }
                }
                else if(r == 2) {
                    if(computer::parse_array[2] == 0) computer::parse_array[2] = 2;
                    else {
                        r = rand() % 2 + 1;
                        if(r == 1) computer::parse_array[0] = 2;
                        else if(r == 2) computer::parse_array[6] = 2;
                        else computer::parse_array[8] = 2;
                    }
                }
                else if(r == 3) {
                    if(computer::parse_array[6] == 0) computer::parse_array[6] = 2;
                    else {
                        r = rand() % 2 + 1;
                        if(r == 1) computer::parse_array[0] = 2;
                        else if(r == 2) computer::parse_array[2] = 2;
                        else computer::parse_array[8] = 2;
                    }
                }
                else if(r == 4) {
                    if(computer::parse_array[8] == 0) computer::parse_array[8] = 2;
                    else {
                        r = rand() % 2 + 1;
                        if(r == 1) computer::parse_array[0] = 2;
                        else if(r == 2) computer::parse_array[2] = 2;
                        else computer::parse_array[6] = 2;
                    }
                }
            }
            else { // move = 4,5,6,7,8,9
                int losing = isWL(1);
                int winning = isWL(2);

                if(winning != -1) computer::parse_array[winning] = 2;
                else {
                    if(losing != -1) computer::parse_array[losing] = 2;
                    else {
                        if(current_move == 4) {
                            if(computer::parse_array[0] == 0 && computer::parse_array[8] == 0) {
                                if((rand()%2) == 0) computer::parse_array[0] = 2;
                                else computer::parse_array[8] = 2;
                            }
                            else if(computer::parse_array[2] == 0 && computer::parse_array[6] == 0){
                                if((rand()%2) == 0) computer::parse_array[2] = 2;
                                else computer::parse_array[6] = 2;
                            }
                            //else exit(1); // testing
                        }
                        //else if(current_move == 5) exit(0); // testing
                        else if(current_move == 6) {
                            if((rand()%2) == 0) {
                                if(computer::parse_array[1]==0) computer::parse_array[1] = 2;
                                else if(computer::parse_array[3]==0) computer::parse_array[3] = 2;
                            }
                            else {
                                if(computer::parse_array[5]==0) computer::parse_array[5] = 2;
                                else if(computer::parse_array[7]==0) computer::parse_array[7] = 2;
                            }
                        }
                        else if(current_move == 7) {
                            
                            if(computer::parse_array[0] == 0) {
                                if(computer::parse_array[1] == 0) computer::parse_array[1] = 2;
                                else if(computer::parse_array[3] == 0) computer::parse_array[3] = 2;
                            }
                            else if(computer::parse_array[2] == 0) {
                                if(computer::parse_array[1] == 0) computer::parse_array[1] = 2;
                                else if(computer::parse_array[5] == 0) computer::parse_array[5] = 2;
                            }
                            else if(computer::parse_array[6] == 0) {
                                if(computer::parse_array[3] == 0) computer::parse_array[3] = 2;
                                else if(computer::parse_array[7] == 0) computer::parse_array[7] = 2;
                            }
                            else if(computer::parse_array[8] == 0) {
                                if(computer::parse_array[7] == 0) computer::parse_array[7] = 2;
                                else if(computer::parse_array[5] == 0) computer::parse_array[5] = 2;
                            }
                            //else exit(0); //testing

                        }
                        else if(current_move == 8) {
                            for(int i = 0 ; i < 9 ; ++i) {
                                if(computer::parse_array[i]==0) { 
                                    computer::parse_array[i] = 2;
                                    break;
                                }
                            }
                        }
                        else for(int i = 0 ; i < 9 ; ++i) if(computer::parse_array[i]==0) computer::parse_array[i] = 2;
                    }
                }
            }
            
            //refill matrix
            parse_index = 0;
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    p[i][j] = computer::parse_array[parse_index++];
                }
            }
        }
};




//------
int is_win(int p[3][3])
{
    if(p[0][0] == p[0][1] && p[0][1] == p[0][2] && p[0][1] != 0) return p[0][0];
    if(p[1][0] == p[1][1] && p[1][1] == p[1][2] && p[1][1] != 0) return p[1][0];
    if(p[2][0] == p[2][1] && p[2][1] == p[2][2] && p[2][1] != 0) return p[2][0];

    if(p[0][0] == p[1][0] && p[1][0] == p[2][0] && p[1][0] != 0) return p[0][0];
    if(p[0][1] == p[1][1] && p[1][1] == p[2][1] && p[1][1] != 0) return p[0][1];
    if(p[0][2] == p[1][2] && p[1][2] == p[2][2] && p[1][2] != 0) return p[0][2];

    if(p[0][0] == p[1][1] && p[1][1] == p[2][2] && p[1][1] != 0) return p[0][0];
    if(p[2][0] == p[1][1] && p[1][1] == p[0][2] && p[1][1] != 0) return p[2][0];

    return -1;
}

int isValidpos(int p[3][3], int x,int player) // 0 no error // 1 already occupied // 2 out of bounds
{
    if(x>=1 && x<=9) {

        int i,j;
        if(x==1) {i = 0;j = 0;}
        else if(x==2) {i = 0;j = 1;}
        else if(x==3) {i = 0;j = 2;}
        else if(x==4) {i = 1;j = 0;}
        else if(x==5) {i = 1;j = 1;}
        else if(x==6) {i = 1;j = 2;}
        else if(x==7) {i = 2;j = 0;}
        else if(x==8) {i = 2;j = 1;}
        else {i = 2;j = 2;}

        if(p[i][j] == 0) {
            p[i][j] = player;
            return 0;
        }
        return 1;
    }
    return 2;
}

char xo(int p,char i) {
    if (p == 0) return i;
    return ((p==1) ? 'O' : 'X');
}

void display(int p[3][3],bool f) {

    if(f) {
        cout << "\n   |   |   \n";
        cout << " " << xo(p[0][0],' ') << " | " << xo(p[0][1],' ') << " | " << xo(p[0][2],' ') << "\n";
        cout << "   |   |   \n";
        cout << "---+---+---\n";
        cout << "   |   |   \n";
        cout << " " << xo(p[1][0],' ') << " | " << xo(p[1][1],' ') << " | " << xo(p[1][2],' ') << "\n";
        cout << "   |   |   \n";
        cout << "---+---+---\n";
        cout << "   |   |   \n";
        cout << " " << xo(p[2][0],' ') << " | " << xo(p[2][1],' ') << " | " << xo(p[2][2],' ') << "\n";
        cout << "   |   |   \n" << endl;
    }
    else {
        cout << "\n   |   |   \n";
        cout << " " << xo(p[0][0],'1') << " | " << xo(p[0][1],'2') << " | " << xo(p[0][2],'3') << "\n";
        cout << "   |   |   \n";
        cout << "---+---+---\n";
        cout << "   |   |   \n";
        cout << " " << xo(p[1][0],'4') << " | " << xo(p[1][1],'5') << " | " << xo(p[1][2],'6') << "\n";
        cout << "   |   |   \n";
        cout << "---+---+---\n";
        cout << "   |   |   \n";
        cout << " " << xo(p[2][0],'7') << " | " << xo(p[2][1],'8') << " | " << xo(p[2][2],'9') << "\n";
        cout << "   |   |   \n" << endl;
    }
}


//----

void game() {

    clear(1);

    int p[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    int player = rand()%2 + 1; //  1 / 2

    //int player = 1; // testing purposes

    int win = -1;
    int moves = 0;

    cout << "\n\n";
    if(player == 2) cout << ((type == 1) ? (p2 + " ") : "COMPUTER ");
    else cout << ((type == 2) ? "YOU " : (p1 + " "));
    cout << "WILL START THE GAME!! \n\n\nWAIT..." << endl;

    slp(5);

    while(win == -1 && ++moves <= 9) {

        string turn;
        if(player == 2) turn = p2 + "'s";
        else {
            if(type == 1) turn = p1 + "'s";
            else turn = p1 + "R";
        }

        clear(1);
        display(p,false);
        if(type == 1 || player == 1) {
            cout << turn + " TURN\n\n";
            cout << "ENTER POSITION (1-9)\n";
            int pos;
            cin >> pos;
            while(true) {
                
                int validity = isValidpos(p,pos,player);
                if(validity == 0) break;
                else if(validity == 1) {
                    clear(1);
                    display(p,false);

                    cout << "POSITION ALREADY PICKED BEFORE\n\n";
                    cout << turn + " TURN\n";
                    cout << "ENTER POSITION (1-9)\n";
                    cin >> pos;
                }
                else {
                    clear(1);
                    display(p,false);

                    cout << turn + " TURN\n\n";
                    cout << "CORRECT POSITON VALUE IS FROM 1 TO 9\n";
                    cout << "ENTER POSITION (1-9)\n";
                    cin >> pos;
                }

            }
            clear(1);
            display(p,false);
        }
        else {
            computer c;
            c.calculate(p);
            clear(1);
            display(p,false);
        }

        player = (player == 1) ? 2 : 1;
        win = is_win(p);
    }

    clear(1);
    if(win == -1) {
        display(p,true);
        cout << "\n\nGAME DRAW!" << endl;
    }
    else {
        if(win == 1) cout << "\n" + p1 + "(O) WON!!!" << endl;
        else cout << "\n" +  p2 + "(X) WON!!!" << endl;
        display(p,true);
    }
}

//---

int main(){
    
    srand(time(0));
    clear(0);

    bool replay = false;

    while(true) {
        cout << "1 -> 2P\n2 -> VS COMP\n\nENTER YOUR CHOICE" << endl;

        cin >> type;
        while (type != 1 && type != 2)
        {
            clear(0);
            cout << "1 -> 2P\n2 -> VS COMP\n\nENTER THE CORRECT CHOICE" << endl;
            cin >> type;
            if(type == 2) replay = false;
        }

        if(replay && type == 1) {
            clear(0);
            cout << "WANT TO CONTINUE WITH SAME PLAYERS ?\n (Y/N)";
            char op;
            cin >> op;
            while (op != 'Y' && op != 'y' && op != 'N' && op != 'n')
            {
                clear(0);
                cout << "ENTER YOUR CHOICE PROPERLY" << endl;
                cout << "WANT TO CONTINUE WITH SAME PLAYERS ?\n (Y/N)";
                cin >> op;
            }
            if(op == 'n' || op == 'N') replay = false;

        }

        if(type == 1 && !replay) {
            clear(0);
            cout << "\n\nENTER PLAYER 1's NAME" << endl;
            cin >> p1;
            cout << "\nENTER PLAYER 2's NAME" << endl;
            cin >> p2;
        }
        if(type == 2) {
            p1 = "YOU";
            p2 = "COMPUTER";
        }

        game();

        cout << "\n\n\n\n\nWANT TO PLAY AGAIN ? (Y/N)" << endl;

        char op;
        cin >> op;
        while(op != 'Y' && op != 'y' && op != 'N' && op != 'n') {
            clear(0);
            cout << "ENTER YOUR CHOICE PROPERLY" << endl;
            cout << "WANT TO PLAY AGAIN ? (Y/N)" << endl;
            cin >> op;
        }

        if(op == 'n' || op == 'N') break;
        clear(0);
        replay = true;
    }
    clear(0);
    return 0;
}
