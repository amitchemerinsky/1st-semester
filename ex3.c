#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#pragma warning(disable:4996)

#define MAX_SIZE 35
#define MIN_SIZE 5

// global variables
char firstName[16];
char lastName[16];
int rows;
int columns;
char board[MAX_SIZE][MAX_SIZE];
int robberRow, robberCol;

// function prototypes
void CopsAndRobbers();
void SetNames();
void PrintBoard1();
int SetRows();
int SetColumns();
void InitializeBoard();
void PlaceCops();
void PrintBoard();
int IsValidMove(int row, int col);
int IsLegalMove(int oldRow, int oldCol, int newRow, int newCol);
bool PlayCopsTurn();
void PlayRobberTurn();



int main()
{

    CopsAndRobbers();
    return 0;
}

void CopsAndRobbers() {
    SetNames();
    PrintBoard1();
    PlaceCops();
    PrintBoard();
    
    int turn = 0;
    while (1) {
        // Cops' turn
        // Cops' turn
        if (turn % 2 == 0) {
            printf("Cops:\n");
            bool turnSuccessful = PlayCopsTurn();
            if (turnSuccessful) {
                PrintBoard();
                if (board[robberRow][robberCol] == 'C') {
                    printf("The cops won!\n");
                    break;
                }
            }
        }

        // Robber's turn
        else {
            printf("Robbers:\n");
            PlayRobberTurn();
            PrintBoard();

        }

        turn++;
        if (turn == 30) {
            printf("The robber managed to escape!\n");
            break;
        }
    }
    printf("Thank you, %s %s for playing!\n", firstName, lastName);

}

void SetNames()
{
    printf("Enter your first name: \n");
    scanf("%15s", firstName);  // Read first name from user, with a maximum of 15 characters

    printf("Enter your last name: \n");
    scanf("%15s", lastName);  // Read last name from user, with a maximum of 15 characters

    printf("Hello %s %s, welcome to the game.\n", firstName, lastName);
    
}

void PrintBoard1()
{
    printf("Let's choose the size: \n");
    scanf(" %d %d", &rows, &columns);
    rows = SetRows(rows);
    columns = SetColumns(columns);
    InitializeBoard(rows, columns);
}

int SetRows(int rows)
{
    if (rows > MAX_SIZE)
    {
        rows = MAX_SIZE;
    }
    else if (rows < MIN_SIZE)
    {
        rows = MIN_SIZE;
    }
    return rows;
}

int SetColumns(int columns)
{
    if (columns == 0)
    {
        columns = rows;
    }
    else if (columns > MAX_SIZE)
    {
        columns = MAX_SIZE;
    }
    else if (columns < MIN_SIZE)
    {
        columns = MIN_SIZE;
    }
    return columns;        
}

void InitializeBoard(int rows, int columns)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            board[i][j] = '-';
        }
    }
    
    // Print the initial board
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

int IsValidMove(int row, int col)
{
    int i, j;

    // check if the slot is not occupied by a policeman or a thief
    if (board[row][col] != '-')
    {
        return 0;
    }

    // check if there are no other policemen on the same column
    for (i = 0; i < rows; i++)
    {
        if (board[i][col] == 'C')
        {
            return 0;
        }
    }

    // check if there are no two cops in a row diagonally in any direction
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            if (i != row && j != col && abs(row - i) == abs(col - j) && abs(row - i) == 1 && board[i][j] == 'C')
            {
                return 0;
            }
        }
    }

    return 1;
}

void PlaceCops()
{
    int i, j;
    int numCops;
    int row, col;

    // Place the thief at the starting position
    robberRow = 2;
    robberCol = 3;
    board[robberRow][robberCol] = 'R';

    printf("How many cops would you like (1-5)?\n");
    scanf(" %d", &numCops);
    for (i = 1; i <= numCops; i++)
    {
        printf("Let's choose cells: \n");
        scanf(" %d%d", &row, &col);
        while (IsValidMove(row, col) == 0) // while move is not valid
        {
            printf("Illegal choice!\n");
            scanf(" %d%d", &row, &col); // read row and column for cop again
        }
        board[row][col] = 'C';
    }
    printf("Let's play!\n");
    printf("Initial states: \n");

}

void PrintBoard()
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            if (board[i][j] == 'C')
            {
                printf("C");
            }
            else if (board[i][j] == 'R')
            {
                printf("R");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int IsLegalMove(int oldRow, int oldCol, int newRow, int newCol) {
    int i, j;

    // Check if new position is occupied by another cop
    if (board[newRow][newCol] == 'C') {
        return 0;
    }

    // Check if cop can "jump" to the other side of the board
    if (oldRow == 0) {
        newRow = rows - 1;
    }
    else if (newRow >= rows) {
        newRow = 0;
    }
    if (newCol < 0) {
        newCol = columns - 1;
    }
    else if (newCol >= columns) {
        newCol = 0;
    }
    return 1;
}

bool PlayCopsTurn() {
    int oldRow, oldCol, newRow, newCol;
    char direction;
    int i, j;

    // Print all legal moves for each cop piece
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            if (board[i][j] == 'C') {
                printf("Cop [%d, %d] can move: ", i, j);
                if (IsLegalMove(i, j, i - 1, j))
                {
                    if (i == 0 && board[rows -1][j] == 'C') 
                    {

                    }
                    else
                    {
                        printf("up(w) ");
                    }
                    
                }
                if (IsLegalMove(i, j, i + 1, j)) 
                {
                    if (i == rows -1 && board[0][j] == 'C')
                    {

                    } 
                    else
                    {
                        printf("down(s) ");
                    }
                }
                if (IsLegalMove(i, j, i, j - 1))
                {
                    if (j == 0 && board[i][columns - 1] == 'C')
                    {

                    }
                    else
                    {
                        printf("left(a) ");
                    }
                }
                if (IsLegalMove(i, j, i, j + 1)) 
                {
                    if (j == columns -1 && board[i][0] == 'C') 
                    {

                    }
                    else
                    {
                        printf("right(d) ");
                    }
                }
                printf("\n");
            }
        }
    }
  
    // Read user input for cop piece to move and direction
    printf("Select a cop[row,col] and a direction\n");
    scanf("%d %d %c", &oldRow, &oldCol, &direction);

    // Check if cop piece exists at inputted position
    if (board[oldRow][oldCol] != 'C') {
        printf("You lose your turn\n");
        return false;
    }
    else
    {
        // Determine new position based on direction
        switch (direction) {
        case 'w':
            if (oldRow == 0)
            {
                newRow = rows - 1;
                newCol = oldCol;
                break;
            }
            else
            {
                newRow = oldRow - 1;
                newCol = oldCol;
                break;
            }
        case 's':
            if (oldRow == rows - 1)
            {
                newRow = 0;
                newCol = oldCol;
                break;
            }
            else
            {
                newRow = oldRow + 1;
                newCol = oldCol;
                break;
            }
        case 'a':
            if (oldCol == 0)
            {
                newCol = rows - 1;
                newRow = oldRow;
                break;
            }
            else
            {
                newRow = oldRow;
                newCol = oldCol - 1;
                break;
            }

        case 'd':
            if (oldCol == columns - 1) {
                newCol = 0;
                newRow = oldRow;
                break;
            }
            else {
                newRow = oldRow;
                newCol = oldCol + 1;
                break;
            }

        }

        // Check if move is legal
        if (!IsLegalMove(oldRow, oldCol, newRow, newCol)) {
            printf("Illegal move\n");
            return;
        }
        if (IsLegalMove(oldRow, oldCol, newRow, newCol)) {
            // update the position of the cop
            board[newRow][newCol] = 'C';
            board[oldRow][oldCol] = '-';
        }


    }
    return true;
}
/* 
void PlayRobberTurn()
{
    int i, j;
    int copRow = -1, copCol = -1;
    double distance;
    double minDistance = 100000;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            if (board[i][j] == 'C') {
                distance = sqrt((i - robberRow) * (i - robberRow) + (j - robberCol) * (j - robberCol));
                if (distance < minDistance) {
                    minDistance = distance;
                    copRow = i;
                    copCol = j;
                }
                else if (distance == minDistance) { //two cops at the same distance
                    if (i < copRow) {
                        copRow = i;
                        copCol = j;
                    }
                    else if (i == copRow && j < copCol) {
                        copRow = i;
                        copCol = j;
                    }
                }
            }
        }
    }

    int dx = 0, dy = 0;
    if (copRow > robberRow) { // up
        dy = -1;
    }
    else if (copRow < robberRow) { //down
        dy = 1;
    }
    if (copCol > robberCol) { // left
        dx = -1;
    }
    else if (copCol < robberCol) { // right
        dx = 1;
    }

    int newRow = robberRow + dy;
    int newCol = robberCol + dx;

    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < columns && board[newRow][newCol] == '-') {
        // move the thief
        board[robberRow][robberCol] = '-';
        board[newRow][newCol] = 'R';
        robberRow = newRow;
        robberCol = newCol;
    }

}
*/

void PlayRobberTurn()
{
    int i, j;
    int copRow = -1, copCol = -1;
    double distance;
    double minDistance = INFINITY;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            if (board[i][j] == 'C') {
                distance = sqrt((i - robberRow) * (i - robberRow) + (j - robberCol) * (j - robberCol));
                if (distance < minDistance) {
                    minDistance = distance;
                    copRow = i;
                    copCol = j;
                }
                else if (distance == minDistance) {
                    if (i < copRow) {
                        copRow = i;
                        copCol = j;
                    }
                    else if (i == copRow && j < copCol) {
                        copRow = i;
                        copCol = j;
                    }
                }
            }
        }
    }

    double maxDistance = 0;
    int dx = 0, dy = 0;
    if (robberRow > 0) { // up
        double distance = sqrt(((robberRow - 1) - copRow) * ((robberRow - 1) - copRow) + (robberCol - copCol) * (robberCol - copCol));
        if (distance > maxDistance) {
            maxDistance = distance;
            dx = 0;
            dy = -1;
        }
    }
    if (robberRow < rows - 1) { // down
        double distance = sqrt(((robberRow + 1) - copRow) * ((robberRow + 1) - copRow) + (robberCol - copCol) * (robberCol - copCol));
        if (distance > maxDistance) {
            maxDistance = distance;
            dx = 0;
            dy = 1;
        }
    }
    if (robberCol > 0) { // left
        double distance = sqrt((robberRow - copRow) * (robberRow - copRow) + ((robberCol - 1) - copCol) * ((robberCol - 1) - copCol));
        if (distance > maxDistance) {
            maxDistance = distance;
            dx = -1;
            dy = 0;
        }
    }
    if (robberCol < columns - 1) { // right
        double distance = sqrt((robberRow - copRow) * (robberRow - copRow) + ((robberCol + 1) - copCol) * ((robberCol + 1) - copCol));
        if (distance > maxDistance) {
            maxDistance = distance;
            dx = 1;
            dy = 0;
        }
    }

    int newRow = robberRow + dy;
    int newCol = robberCol + dx;

    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < columns && board[newRow][newCol] == '-') {
        // move the robber
        board[robberRow][robberCol] = '-';
        board[newRow][newCol] = 'R';
        robberRow = newRow;
        robberCol = newCol;
    }
}



/*// Check if cop can "jump" to the other side of the board
   if (j == 0 && IsLegalMove(i, j, i, columns - 1)) {
       printf(" left(a)");
   }
   if (j == columns - 1 && IsLegalMove(i, j, i, 0)) {
       printf(" right(d)");
   }
   if (i == 0 && IsLegalMove(i, j, rows - 1, j)) {
       printf(" up(w)");
   }
   if (i == rows - 1 && IsLegalMove(i, j, 0, j)) {
       printf(" down(s)");
   }
   */