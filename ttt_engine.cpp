//Prince Keshri (wizard_ninja)
// cpp tic-tac-toe engine class
#include <iostream>

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
            srand(time(0));
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

// computer c;
// c.calculate(p);
// p is a 3x3 matrix, after calculate() function, the matrix is edited with the new move