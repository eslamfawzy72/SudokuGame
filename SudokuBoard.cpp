#include"SudokuBoard.hpp"

SudokuBoard::SudokuBoard():posx(0),posy(0){
    board={9,vector<int>(9, 0)};
}
void SudokuBoard::setPosx(int x){
    posx=x;
}
void SudokuBoard::setPosy(int y){
    posy=y;
}
bool SudokuBoard::setValue(int x,int y,int v){
    //check for avaliablitiy for this position
    if(board[x][y]!=0){
      cout<<"Can not replace, there is a value in this position!\n";
      return 1;//assumption:make the user enter the a value again but in a new position 
}
         //check there is no same value in the row & column
       for(int i=0;i<9;i++){
        if(board[i][y]==v){//check for the same column
             cout<<"LOSE,TOW VALUES IN THE SAME Column!\n";
                return false; 
        }
       }
        for(int j=0;j<9;j++){
            if(v==board[x][j])//check for the same row
            {
                cout<<"LOSE,TOW VALUES IN THE SAME ROW!\n";
                return false; 
            }
        }
        //getting the boundries using eqn
        int startx = (x / 3) * 3;
        int starty = (y / 3) * 3;
        int endx   = startx + 3;
        int endy   = starty + 3;
        //check for the same grid 3x3 or not 
        //   int startx,endx;
        // int starty,endy;
        // if (x >= 0 && x <= 2) {
        // startx = 0;
        // endx   = 3;   // exclusive so equivalent to 2 
        // }
        // else if (x >= 3 && x <= 5) {
        //     startx = 3;
        //     endx   = 6;
        // }
        // else if (x >= 6 && x <= 8) {
        //     startx = 6;
        //     endx   = 9;
        // }
        // if (y >= 0 && y <= 2) {
        //     starty = 0;
        //     endy   = 3;
        // }
        // else if (y >= 3 && y <= 5) {
        //     starty = 3;
        //     endy   = 6;
        // }
        // else if (y >= 6 && y <= 8) {
        //     starty = 6;
        //     endy   = 9;
        // }
        for(int i=startx;i<endx;i++){
            for(int j=starty;j<endy;j++){
                if(v==board[i][j]){
                cout<<"LOSE,TOW VALUES IN THE SAME 3X3 GRID!\n";
                return false;
                }
            }
        }
        board[x][y]=v;
        return true;
}
bool SudokuBoard::isComplete()const{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                return false; // found an empty cell
            }
        }
    }
    return true; // all cells filled
}

void SudokuBoard::resetBoard() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = 0;  // 0 means empty cell
        }
    }
}
void SudokuBoard::printBoard() const {
        for (int row = 0; row < 9; row++) {
            if (row % 3 == 0) {
                cout << "-------------------------------------\n";
            }
            for (int col = 0; col < 9; col++) {
                if (col % 3 == 0) std::cout << "| "; // vertical separator

                if (board[row][col] == 0)
                    cout << ". ";   // empty cell
                else
                    cout << board[row][col] << " ";
            }
            cout << "|\n";
        }
        cout << "-------------------------------------\n";
    }

int SudokuBoard::getPosx(){
    return posx;
}
int SudokuBoard::getPosy(){
    return posy;
}
int SudokuBoard::getValue(int x,int y){
return board[x][y];
}
void SudokuBoard::clearValue(int x,int y){
    board[x][y]=0;
}

void SudokuBoard::loadFromFile(const string& filename){
ifstream file(filename);
if(!file.is_open()){
    throw runtime_error("Error can not open file "+filename);
}
resetBoard();
int value;
for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
        if(!(file>>value)){
              throw runtime_error("Error: Invalid file format at row " 
                                    + to_string(i) + " col " + to_string(j));
        }
     if (value != 0) {
        setValue(i, j, value);        
    }
}
}

}
void SudokuBoard::saveToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Error: Could not open file " + filename);
    }
    
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            file << getValue(row, col);
            if (col < 8) file << " ";
        }
        file << "\n";
    }
    cout<<"File saved successfully!\n";
}
