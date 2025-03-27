#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            // Recorre cada celda del tablero
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] == '.') continue; // Si la celda está vacía, la salta
                    
                    char num = board[i][j]; // Obtiene el número actual
                    
                    // Verifica si el número se repite en la misma fila
                    for (int k = 0; k < 9; k++) {
                        if (k != j && board[i][k] == num) return false;
                    }
                    
                    // Verifica si el número se repite en la misma columna
                    for (int k = 0; k < 9; k++) {
                        if (k != i && board[k][j] == num) return false;
                    }
                    
                    // Calcula la posición inicial del subcuadro 3x3
                    int boxRowStart = (i / 3) * 3;
                    int boxColStart = (j / 3) * 3;
                    
                    // Verifica si el número se repite en el subcuadro 3x3
                    for (int r = boxRowStart; r < boxRowStart + 3; r++) {
                        for (int c = boxColStart; c < boxColStart + 3; c++) {
                            if ((r != i || c != j) && board[r][c] == num) return false;
                        }
                    }
                }
            }
            return true; // Si no hay repeticiones, el Sudoku es válido
        }
}