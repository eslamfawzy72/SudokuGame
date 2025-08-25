#include"SudokuGame.hpp"


//Quick checking for winning case
// // Top 3 rows
// s.setValue(0,0,5); s.setValue(0,1,3); s.setValue(0,2,4);
// s.setValue(0,3,6); s.setValue(0,4,7); s.setValue(0,5,8);
// s.setValue(0,6,9); s.setValue(0,7,1); s.setValue(0,8,2);
// s.setValue(1,0,6); s.setValue(1,1,7); s.setValue(1,2,2);
// s.setValue(1,3,1); s.setValue(1,4,9); s.setValue(1,5,5);
// s.setValue(1,6,3); s.setValue(1,7,4); s.setValue(1,8,8);
// s.setValue(2,0,1); s.setValue(2,1,9); s.setValue(2,2,8);
// s.setValue(2,3,3); s.setValue(2,4,4); s.setValue(2,5,2);
// s.setValue(2,6,5); s.setValue(2,7,6); s.setValue(2,8,7);
// // Middle 3 rows
// s.setValue(3,0,8); s.setValue(3,1,5); s.setValue(3,2,9);
// s.setValue(3,3,7); s.setValue(3,4,6); s.setValue(3,5,1);
// s.setValue(3,6,4); s.setValue(3,7,2); s.setValue(3,8,3);
// s.setValue(4,0,4); s.setValue(4,1,2); s.setValue(4,2,6);
// s.setValue(4,3,8); s.setValue(4,4,5); s.setValue(4,5,3);
// s.setValue(4,6,7); s.setValue(4,7,9); s.setValue(4,8,1);
// s.setValue(5,0,7); s.setValue(5,1,1); s.setValue(5,2,3);
// s.setValue(5,3,9); s.setValue(5,4,2); s.setValue(5,5,4);
// s.setValue(5,6,8); s.setValue(5,7,5); s.setValue(5,8,6);
// // Bottom 3 rows (leave last cell empty for win)
// s.setValue(6,0,9); s.setValue(6,1,6); s.setValue(6,2,1);
// s.setValue(6,3,5); s.setValue(6,4,3); s.setValue(6,5,7);
// s.setValue(6,6,2); s.setValue(6,7,8); // 6,8 left empty
// s.setValue(7,0,2); s.setValue(7,1,8); s.setValue(7,2,7);
// s.setValue(7,3,4); s.setValue(7,4,1); s.setValue(7,5,9);
// s.setValue(7,6,6); s.setValue(7,7,3); s.setValue(7,8,5);
// s.setValue(8,0,3); s.setValue(8,1,4); s.setValue(8,2,5);
// s.setValue(8,3,2); s.setValue(8,4,8); s.setValue(8,5,6);
// s.setValue(8,6,1); s.setValue(8,7,7); s.setValue(8,8,9); 
void SudokuGame::enableDifficulty(SudokuBoard& board){
    cout<<"Enter difficulty\n[1]Easy\n[2]Medium\n[3]Hard\n";
    short choice;
    cin>>choice;
    switch(choice){
        case 1:
board.setValue(0,0,5); board.setValue(0,1,3); board.setValue(0,4,7);
board.setValue(1,0,6); board.setValue(1,3,1); board.setValue(1,4,9); board.setValue(1,5,5);
board.setValue(2,1,9); board.setValue(2,2,8); board.setValue(2,7,6);
board.setValue(3,0,8); board.setValue(3,4,6); board.setValue(3,8,3);
board.setValue(4,0,4); board.setValue(4,3,8); board.setValue(4,5,3); board.setValue(4,8,1);
board.setValue(5,0,7); board.setValue(5,4,2); board.setValue(5,8,6);
board.setValue(6,1,6); board.setValue(6,6,2); board.setValue(6,7,8);
board.setValue(7,3,4); board.setValue(7,4,1); board.setValue(7,5,9); board.setValue(7,8,5);
board.setValue(8,4,8); board.setValue(8,7,7); board.setValue(8,8,9);
         break;
         case 2:
 board.setValue(0,1,3); board.setValue(0,4,5); board.setValue(0,6,7);
board.setValue(1,0,6); board.setValue(1,3,1); board.setValue(1,5,9); 
board.setValue(2,2,8); board.setValue(2,7,6);
board.setValue(3,0,8); board.setValue(3,3,6); board.setValue(3,8,3);
board.setValue(4,1,7); board.setValue(4,4,2); board.setValue(4,7,5);
board.setValue(5,0,1); board.setValue(5,5,8); board.setValue(5,8,9);
board.setValue(6,1,6); board.setValue(6,6,4); board.setValue(6,7,7);
board.setValue(7,3,3); board.setValue(7,4,9); board.setValue(7,5,1);
board.setValue(8,2,5); board.setValue(8,4,7); board.setValue(8,7,2);
        break;
        case 3:
        board.setValue(0,2,1); board.setValue(0,5,6);
board.setValue(1,0,2); board.setValue(1,3,3); board.setValue(1,8,5);
board.setValue(2,1,7); board.setValue(2,4,1); board.setValue(2,6,9);
board.setValue(3,0,5); board.setValue(3,2,9); board.setValue(3,7,6);
board.setValue(4,3,5); board.setValue(4,5,3);
board.setValue(5,1,4); board.setValue(5,6,8); board.setValue(5,8,7);
board.setValue(6,2,2); board.setValue(6,4,6); board.setValue(6,7,1);
board.setValue(7,0,7); board.setValue(7,5,9); board.setValue(7,8,4);
board.setValue(8,3,7); board.setValue(8,6,3);
        break;
        default:
        cerr<<"Invalid choice!\n";

    }
}
void SudokuGame::start(){
    SudokuBoard s;   
    enableDifficulty(s);
    short choice;
    bool loop=true;
    int x,y,value;
    while(loop){
    s.printBoard();
    cout<<"1) Enter a move\n2) Solve automatically\n3) Load puzzle from file\n4) Save current puzzle to file\n5) Exit\n";
    try{
    cin>>choice;
     if (cin.fail()) {
                throw runtime_error("Input must be a number!");
            }
    }catch(exception &e){
            cout << "Error: " << e.what() << "\n";
            // Clear the error and discard invalid input
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    }

    switch(choice){
         //go to setter for x,y and value in Sudokuboard function
         case 1:
        cout<<"Enter a row(1-9),Column(1-9) and value(1,9)\n";
        cin>>x>>y>>value;
        if(x>=1&&x<=9){
            s.setPosx(--x);
        }else{
            cout<<"Row must be between 1 and 9\n";
            break;
        }

        if(y>=1&&y<=9){
            s.setPosy(--y);
        }else{
            cout<<"Column must be between 1 and 9\n";
            break;
        }

        if(value>=1&&value<=9){
             if (!s.setValue(x,y,value)) {
            cout << "Invalid move! Resetting board...\n";
           continue;
        }
        }else{
            cout<<"value must be between 1 and 9\n";
            break;
        }
        if (s.isComplete()) {
        s.printBoard(); 
        cout << "YOU WIN THE GAME!!!\n---------------------------------------------------\n\n";
        loop = false; //stop the game
        
    }
        break;
        case 2:
        //go to Backtracking method in sudoku solver
        if (!SudokuSolver::solve(s)) {
        cout << "Error: The puzzle cannot be solved!\n";//medium-hard level
        } else {
        s.printBoard(); 
        cout << "YOU WIN THE GAME!!!\n---------------------------------------------------\n\n";//easy level
        loop=false;
}
        break;
       case 3: // Load from file
        try {
            s.loadFromFile("puzzle.txt");
            cout << "Puzzle loaded successfully!\n";
        } catch (const exception& e) {
            cerr << e.what() << "\n";
        }
        break;

    case 4: // Save to file
        try {
            s.saveToFile("puzzle.txt");
            cout << "Puzzle saved successfully!\n";
        } catch (const exception& e) {
            cerr << e.what() << "\n";
        }
    break;
        case 5:
        exit(0);
        default:
        cout<<"Enter a choice from 1-5\n";
        break;
    }

}

}