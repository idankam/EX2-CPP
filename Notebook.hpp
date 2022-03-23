#include "Direction.hpp"
#include <string>
#include <map>

using namespace std;
namespace ariel{
    const int column_length = 100;

    class Notebook{

        std::map<string, char> notebook_data;
        
    public:

        void write (int page,int row,int column,Direction dir , string input);
        string read(int page,int row,int column, Direction dir, int len);
        void erase(int page,int row, int column, Direction dir,int len);
        void show(int page);
        bool checkNegativity(int j);
    };
}
