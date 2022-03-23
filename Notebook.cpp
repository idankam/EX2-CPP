#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>
#include "Notebook.hpp"

using namespace ariel;


    
void ariel::Notebook::write(int page, int row, int column,Direction dir , string input){

    int input_length = input.size();
    if(column > 99){throw invalid_argument("column is greater than 99");}
    if(dir == Direction::Horizontal && column + input_length > column_length){ throw invalid_argument("passing column number 99");}
    if(checkNegativity(column) || checkNegativity(page) || checkNegativity(row)){ throw invalid_argument("negative param");}

    // for (int i = 0; i < input.length(); i++)
    // {
    //     if ( notebook_data.find("f") == notebook_data.end() ) {
    //     // not found
    //     } else {
    //     // found
    //     }
    // }
    
    return;
}

string ariel::Notebook::read( int page,int row,  int column, Direction dir, int len){
    if(column > 99){throw invalid_argument("column is greater than 99");}
    if(dir == Direction::Horizontal && len+column > column_length){ throw invalid_argument("passing column number 99");}
    if(checkNegativity(column) || checkNegativity(page) || checkNegativity(row)){ throw invalid_argument("negative param");}
    
    return "not implemented";
}

void ariel::Notebook::erase( int page, int row,  int column, Direction dir,  int len){
    if(column > 99){throw invalid_argument("column is greater than 99");}
    if(dir == Direction::Horizontal && len+column > column_length){ throw invalid_argument("passing column number 99");}
    if(checkNegativity(column) || checkNegativity(page) || checkNegativity(row)){ throw invalid_argument("negative param");}
    
    return;
}

void ariel::Notebook::show(int page){
}


bool ariel::Notebook::checkNegativity(int num){
    if(num < 0) 
    {
        return true;
    }
    return false;
}
