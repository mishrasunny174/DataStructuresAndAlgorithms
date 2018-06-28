#include <iostream>

using namespace std;

class ChessBoard
{
    int **board;
    const int size;
    int numberOfSolutions;
    void putQueens(int row = 0);
    bool isAvailable(int row, int col);
    void printBoard();

  public:
    ChessBoard(int size = 8);
    ~ChessBoard();
    void findSolutions();
};

int main(int argc, char const *argv[])
{
    int size;
    cout<<"Enter size of board: ";
    cin>>size;
    ChessBoard* board = new ChessBoard(size);
    board->findSolutions();
    delete board;
    return 0;
}

ChessBoard::ChessBoard(int size) : size(size)
{
    board = new int *[size];
    for (int i = 0; i < size; i++)
        board[i] = new int[size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = 0;
        }
    }
    numberOfSolutions = 0;
}

ChessBoard::~ChessBoard()
{
    for (int i = 0; i < size; i++)
        delete[] board[i];
    delete[] board;
}

void ChessBoard::findSolutions()
{
    this->putQueens();
    cout << "Number of solutions are: " << this->numberOfSolutions << endl;
}

void ChessBoard::putQueens(int row)
{
    for (int col = 0; col < size; col++)
    {
        if (isAvailable(row, col))
        {
            this->board[row][col] = 1;
            if (row < size - 1)
            {
                putQueens(row + 1);
            }
            else
            {
                printBoard();
            }
            this->board[row][col] = 0;
        }
    }
}

bool ChessBoard::isAvailable(int row, int col)
{
    for (int i = 0; i < size; i++)
        if (this->board[i][col] == 1)
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (this->board[i][j] == 1)
            return false;
    for (int i = row, j = col; i >= 0 && j < size; i--, j++)
        if (this->board[i][j] == 1)
            return false;
    return true;
}

void ChessBoard::printBoard()
{
    cout << endl
         << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << this->board[i][j] << " ";
        }
        cout << endl;
    }
    this->numberOfSolutions++;
}