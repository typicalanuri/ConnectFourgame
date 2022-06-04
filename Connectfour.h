#ifndef Connectfour
#define Connectfour

class Cell{
    private: 
        char val;
    public: 
        Cell(); //destructor is not needed since pointers are not used
        bool addChar(char newchar); //used as a sanity check
        char getChar();
};

class Board{
    private: 
        Cell board[6][7];
    public:
        bool get_userInput(char user);
        void print();
        char start();
        int get_currentStatus(char user1);
        void undo(char user, int col, int row); //stack is composed of an object that holds the three data elements
};

#endif