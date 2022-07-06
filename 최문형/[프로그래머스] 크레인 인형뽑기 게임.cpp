#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int N = board[0].size();
    vector<int> idx(N);

    for (int i = 0; i < N; i++) {
        while (idx[i] < N) {
            if (board[idx[i]][i] != 0) {
                break;
            }

            idx[i]++;
        }
    }


    int answer = 0;
    stack<int> basket;

    for (auto move : moves) {
        move--;
        if (idx[move] == N) { // 해당 위치엔 인형이 없음
            continue;
        }


        int cur = board[idx[move]][move];
        idx[move]++;

        if (!basket.empty() && cur == basket.top()) {
            basket.pop();
            answer += 2;
        }
        else {
            basket.push(cur);
        }
    }

    return answer;
}
