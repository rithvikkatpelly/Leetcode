#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = (int)graph.size();
        // color[m][c][t]: 0 unknown, 1 mouse win, 2 cat win
        static int color[50][50][2];
        static int degree[50][50][2];
        memset(color, 0, sizeof(color));
        memset(degree, 0, sizeof(degree));

        // Initialize degrees (number of moves available from a state)
        for (int m = 0; m < n; m++) {
            for (int c = 0; c < n; c++) {
                degree[m][c][0] = (int)graph[m].size(); // mouse can go anywhere in graph[m]
                // cat cannot go to 0
                int d = 0;
                for (int nxt : graph[c]) if (nxt != 0) d++;
                degree[m][c][1] = d;
            }
        }

        queue<tuple<int,int,int>> q;

        // Terminal: mouse at hole => mouse win for both turns
        for (int c = 0; c < n; c++) {
            for (int t = 0; t < 2; t++) {
                if (color[0][c][t] == 0) {
                    color[0][c][t] = 1;
                    q.emplace(0, c, t);
                }
            }
        }
        // Terminal: cat catches mouse (m==c, m!=0) => cat win for both turns
        for (int m = 1; m < n; m++) {
            for (int t = 0; t < 2; t++) {
                if (color[m][m][t] == 0) {
                    color[m][m][t] = 2;
                    q.emplace(m, m, t);
                }
            }
        }

        auto parents = [&](int m, int c, int t) {
            vector<tuple<int,int,int>> res;
            if (t == 0) {
                // mouse to move now, so parent was cat move
                // parent states: (m, pc, 1) where pc -> c (pc can't be 0 restriction only on moves to 0, not from)
                for (int pc : graph[c]) {
                    if (pc == 0) continue; // cat cannot be at 0 in valid play (can't move into 0)
                    // from pc, cat could move to c if c is in graph[pc]; but graph is undirected per statement,
                    // and input uses adjacency list, so pc in graph[c] implies c in graph[pc].
                    res.emplace_back(m, pc, 1);
                }
            } else {
                // cat to move now, so parent was mouse move
                // parent states: (pm, c, 0) where pm -> m
                for (int pm : graph[m]) {
                    res.emplace_back(pm, c, 0);
                }
            }
            return res;
        };

        while (!q.empty()) {
            auto [m, c, t] = q.front();
            q.pop();
            int curColor = color[m][c][t];

            for (auto [pm, pc, pt] : parents(m, c, t)) {
                if (color[pm][pc][pt] != 0) continue;

                // If it's player's turn at parent, and they can move to a winning state for themselves,
                // then parent is winning for that player.
                int player = (pt == 0 ? 1 : 2); // mouse turn => player 1, cat turn => player 2

                if (curColor == player) {
                    color[pm][pc][pt] = player;
                    q.emplace(pm, pc, pt);
                } else {
                    // otherwise, this move leads to opponent win; reduce degree
                    degree[pm][pc][pt]--;
                    if (degree[pm][pc][pt] == 0) {
                        // all moves lead to opponent winning => parent is losing for current player
                        color[pm][pc][pt] = (player == 1 ? 2 : 1);
                        q.emplace(pm, pc, pt);
                    }
                }
            }
        }

        // start state: mouse at 1, cat at 2, mouse to move (t=0)
        return color[1][2][0]; // 0 means draw
    }
};
