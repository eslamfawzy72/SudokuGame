#pragma once 
using namespace std;
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
class SudokuBoard{
private:
int posx;
int posy;
vector<vector<int>> board;
public:
SudokuBoard();
void setPosx(int x);//can remove setters and getters  of positions and just use setvalue and getvalue
void setPosy(int y);
int getPosx();
int getPosy();
void printBoard()const;
void resetBoard();
bool isComplete()const;
bool setValue(int x,int y, int value);
int getValue(int x,int y);
void clearValue(int row,int col);
void loadFromFile(const string& filename);
void saveToFile(const string& filename);

};