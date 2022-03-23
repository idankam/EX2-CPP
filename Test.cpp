#include "doctest.h"
#include "Notebook.hpp"

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
using namespace ariel;
using ariel::Direction;


TEST_CASE("WRITE - Good input") {

    srand(time(NULL));
    Direction dir;
    string input = "test input";
    Notebook notebook;

    for(int i = 0 ; i < 10; i++){
        
        int column;
        int row = rand();
        int page = rand();
        
        if(i%2 == 0) {
            dir = Direction:: Horizontal;
            column = rand() % (99 - int(input.length())); // change column in the correct range
        }else{
            dir = Direction::Vertical; 
            column = rand() % 100;
        }
        CHECK_NOTHROW(notebook.write(page,row,column,dir,input));  
        
        // make sure the notebook is "clean" for the next iteration
        Notebook notebook;
    }
     // last column is 99, and can write one char only.
    dir = Direction:: Horizontal;
    CHECK_NOTHROW(notebook.write(0,99,0,dir,"a"));
}

TEST_CASE("READ and ERASE - Good input") {

    srand(time(NULL));
    Direction dir;
    Notebook notebook;

    for(int i = 0 ; i < 10; i++){
        int column = rand()% 100;
        int row = rand();
        int page = rand();
        int len = rand()%(99 - column);
        if(i%2 == 0) {
            dir = Direction:: Horizontal;
            len = rand()%(99 - column);
        }else{
            dir = Direction::Vertical; 
            len = rand();
        }
        CHECK_NOTHROW(notebook.read(page,row,column,dir,len));
        CHECK_NOTHROW(notebook.erase(page,row,column,dir,len));  
    }
    CHECK_NOTHROW(notebook.read(0,0,99,Direction:: Horizontal,1)); // last column
    CHECK_NOTHROW(notebook.erase(0,0,99,Direction:: Horizontal,1)); // last column
    CHECK_NOTHROW(notebook.read(0,0,0,Direction:: Horizontal,100)); // first column
    CHECK_NOTHROW(notebook.erase(0,0,0,Direction:: Horizontal,100));// first column
}


TEST_CASE("BAD Input - negative values") {
    srand(time(NULL));
    Direction dir;
    string input = "test input";
    Notebook notebook;

    for(int i = 0 ; i < 20; i++){

        int column;
        int row = rand();
        int page = rand();
        
        if(i%2 == 0) {
            dir = Direction:: Horizontal;
            column = rand() % (99 - int(input.length())); // change column in the correct range
        }else{
            dir = Direction::Vertical; 
            column = rand() % 100;
        }
        
        if(i%3 == 0){
            column *= (-1);
        }else if(i%3 == 1){
            row *= (-1);
        }else{
            page = page * -1;
        }
        CHECK_THROWS(notebook.write(page,row,column,dir,input));
        CHECK_THROWS(notebook.read(page,row,column,dir,input.length()));
        CHECK_THROWS(notebook.erase(page,row,column,dir,input.length()));  
    }

    CHECK_THROWS(notebook.write(-1,-1,1,Direction:: Horizontal,"test"));
    CHECK_THROWS(notebook.read( -1,-1,1,Direction:: Horizontal,10));
    CHECK_THROWS(notebook.erase(-1,-1,1,Direction:: Horizontal,10));

    CHECK_THROWS(notebook.write(-1,1,-1,Direction:: Horizontal,"test"));
    CHECK_THROWS(notebook.read( -1,1,-1,Direction:: Horizontal,10));
    CHECK_THROWS(notebook.erase(-1,1,-1,Direction:: Horizontal,10));

    CHECK_THROWS(notebook.write(1,-1,-1,Direction:: Horizontal,"test"));
    CHECK_THROWS(notebook.read( 1,-1,-1,Direction:: Horizontal,10));
    CHECK_THROWS(notebook.erase(1,-1,-1,Direction:: Horizontal,10));

    CHECK_THROWS(notebook.write(-1,-1,-1,Direction:: Horizontal,"test"));
    CHECK_THROWS(notebook.read( -1,-1,-1,Direction:: Horizontal,10));
    CHECK_THROWS(notebook.erase(-1,-1,-1,Direction:: Horizontal,10));
}

TEST_CASE("Horizontal - Bad input Length") {
    srand(time(NULL));
    Direction dir;
    Notebook notebook;
    string input;

    // input length = 101
    for(int i = 1 ; i <= 101; i++){
        input+='#';
    }
    CHECK_THROWS(notebook.write(1,1,1,Direction:: Horizontal,input));
    for(int j=0; j<5; ++j){
        string input2;
        int column_loc = rand()%100;
        int inputLen = 101 - column_loc;
        for(int m = 0 ; m < inputLen;++m){
            input2 += '#';
        }
        CHECK_THROWS(notebook.write(5,4,column_loc,Direction:: Horizontal,input2));
    }
}

TEST_CASE("READ and ERASE - Bad input Length") {
    srand(time(NULL));
    Direction dir;
    Notebook notebook;

    for(int i = 0 ; i < 5; ++i){
        int len = 3;
        int loc = rand();
        if(loc < 100){
            len = 150 - loc; 
        }
        CHECK_THROWS(notebook.read(0,4,loc,Direction:: Horizontal,len));
        CHECK_THROWS(notebook.erase(0,4,loc,Direction:: Horizontal,len)); 
    }
        CHECK_THROWS(notebook.read(0,0,0,Direction:: Horizontal,101));
        CHECK_THROWS(notebook.erase(0,0,0,Direction:: Horizontal,101));
}








// TEST_CASE("Test write") {

    

//     Notebook nt;
//     Direction direction = Direction::Horizontal;
//     srand((unsigned)time(NULL));

//     // Testing if message that was posted last is the one to return 
//     for(uint i = 0; i < INPUTS.size(); i++) {
//         direction = i%2 == 0 ? Direction::Horizontal : Direction::Vertical;
//         CHECK_NOTHROW(nt.write(i, 0, direction, INPUTS.at(i)));

//         CHECK(INPUTS.at(i) == nt.read(i, 0, direction, INPUTS.at(i).size()));
//     }

//     string message = "zich";
//     CHECK_NOTHROW(board.post(0,0, direction, message));
//     CHECK(board.read(0,0, direction, message.size()) == message);

//     direction = Direction::Vertical;
//     CHECK_NOTHROW(board.post(0, message.size()-1, direction, "bbbb"));

//     direction = Direction::Horizontal;
//     CHECK(nt.read(0,0, direction, message.size()) != message);
//     CHECK(nt.read(0,0, direction, message.size()) == "aaab");
// }