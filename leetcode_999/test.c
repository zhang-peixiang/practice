//
// Created by zpx on 2020/5/2.
//

#include <stdio.h>

int numRookCaptures(char board[][8], int boardSize, int *boardColSize) {
    int i = 0;
    int j = 0;
    int a = 0;
    int b = 0;
    int count = 0;
    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < *boardColSize; j++) {
            if (board[i][j] == 'R') {
                for (a = 1; i - a >= 0; a++)//车向左、上移动
                {
                    //向上移动
                    if (board[i - a][j] == 'B') {
                        break;
                    } else if (board[i - a][j] == 'p') {
                        count++;
                        break;
                    }
                }
                for (a = 1; j - a >= 0; a++) {
                    //向左移动
                    if (board[i][j - a] == 'B') {
                        break;
                    } else if (board[i][j - a] == 'p') {
                        count++;
                        break;
                    }
                }
                for (a = 1; i + a < *boardColSize; a++)//向右、下移动
                {
                    //向下移动

                    if (board[i + a][j] == 'B') {
                        break;
                    } else if (board[i + a][j] == 'p') {
                        count++;
                        break;
                    }
                }
                for (a = 1; j + a < boardSize; a++) {
                    //向右移动
                    if (board[i][j + a] == 'B') {
                        break;
                    } else if (board[i][j + a] == 'p') {
                        count++;
                        break;
                    }
                }
            }
        }
        if(count !=0)
        {
            break;
        }
    }
    return count;
}

int main() {
    char str[8][8] = {{'.','.','.','.','.','.','.','.'},
                      {'.','.','.','p','.','.','.','.'},
                      {'.','.','.','R','.','.','.','p'},
                      {'.','.','.','.','.','.','.','.'},
                      {'.','.','.','.','.','.','.','.'},
                      {'.','.','.','p','.','.','.','.'},
                      {'.','.','.','.','.','.','.','.'},
                      {'.','.','.','.','.','.','.','.'}};
    int a = sizeof(str) / sizeof(str[0]);
    int b = sizeof(str[0]) / sizeof(str[0][0]);
    int ret = numRookCaptures(str, 8, &b);
    printf("%d\n", ret);
    return 0;
}
