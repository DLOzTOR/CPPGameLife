#include <iostream>
#include <stdlib.h>
#include "windows.h"

//gameLife DLOzTOR realization

const int fieldScale = 20; 
int field[fieldScale][fieldScale] = {0}; 


void initializeField(){
    for(int i = 0; i < fieldScale; i++ ){
        for(int j = 0; j < fieldScale; j++){
            field[i][j] = 0;
        }
    }
}

int loopField(int i){
    if(i < 0) return fieldScale-1;
    if(i>fieldScale-1)return 0; 
    return i;
}

int cellUpdate(int i, int j){
    int lifeCellsCount = 0;

    if(field[loopField(i-1)][loopField(j+1)] == 1)  lifeCellsCount++;
    if(field[loopField(i)][loopField(j+1)] == 1)  lifeCellsCount++;
    if(field[loopField(i+1)][loopField(j+1)] == 1)  lifeCellsCount++;
    if(field[loopField(i+1)][loopField(j)] == 1)  lifeCellsCount++;
    if(field[loopField(i+1)][loopField(j-1)] == 1)  lifeCellsCount++;
    if(field[loopField(i)][loopField(j-1)] == 1)  lifeCellsCount++;
    if(field[loopField(i-1)][loopField(j-1)] == 1)  lifeCellsCount++;
    if(field[loopField(i-1)][loopField(j)] == 1)  lifeCellsCount++;
    if((field[i][j] == 0 && lifeCellsCount == 3)||(field[i][j] == 1 && (lifeCellsCount == 2 || lifeCellsCount ==3))) return 1;
    return 0;
    std::cout << lifeCellsCount;
}

void changeField(){
    int tempField[fieldScale][fieldScale] = {0};
    for(int i = 0; i < fieldScale; i++ ){
        for(int j = 0; j < fieldScale; j++){
            tempField[i][j] = field[i][j];
        }
    }
    for(int i = 0; i < fieldScale; i++ ){
        for(int j = 0; j < fieldScale; j++){
            tempField[i][j] = cellUpdate(i,j);
        }
    }
    for(int i = 0; i < fieldScale; i++ ){
        for(int j = 0; j < fieldScale; j++){
            field[i][j] = tempField[i][j];
        }
    }
}

void outputField(){
    for(int i = 0; i < fieldScale; i++ ){
        for(int j = 0; j < fieldScale; j++){
            std::cout<< field[j][i];
        }
        std::cout<<std::endl;
    }
}

//initialize here start state of field
int lifeCells[3][2] = {{4,5},{5,5},{6,5}};
//

void setField( ){
    int size= sizeof(lifeCells)/2;
    for (int i = 0; i < size; i ++){
        field[loopField(lifeCells[i][0])][loopField(lifeCells[i][1])] = 1;
    }
}

main(int argc, char *argv[]){
    initializeField();

    setField();
    while(true){
        changeField();
        outputField();
        Sleep(1000);//duration between iteration
        system("cls");
        }
    return 0;
}