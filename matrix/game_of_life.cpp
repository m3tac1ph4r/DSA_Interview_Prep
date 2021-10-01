#include<bits/stdc++.h>
using namespace std;
#define ll long long

void display(vector<vector<int>> board, int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int x, int y, int R, int C)
{
    return (x >= 0 && x < R && y >= 0 && y < C);
}

int main()
{
    vector<vector<int>> board = {{0, 1, 0 }, {0, 0, 1 }, {1, 1, 1 }, {0, 0, 0}};
    int R = board.size();
    int C = board[0].size();

    int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            int liveCounts = 0;
            for (int k = 0; k < 8; k++)
                if (isSafe(i + dx[k], j + dy[k], R, C) && abs(board[i + dx[k]][j + dy[k]]) == 1)
                    liveCounts++;

            if (board[i][j] == 0 && liveCounts == 3)
                board[i][j] = 2;
            if (board[i][j] == 1 && (liveCounts < 2 || liveCounts > 3))
                board[i][j] = -1;
        }
    }
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            board[i][j] = board[i][j] > 0 ? 1 : 0;
    display(board,R,C);
}

/*
https://leetcode.com/problems/game-of-life/
*/