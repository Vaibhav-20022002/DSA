#include <iostream>
#include <vector>
using namespace std;
string direction = "DLRU";
int di[] = {1, 0, 0, -1};
int dj[] = {0, -1, 1, 0};
void FindPaths(vector<vector<int>> &arr, int r, int c, int i, int j, string s, vector<vector<int>> &visit)
{
    if (i == r || j == c || i < 0 || j < 0 || visit[i][j] == 1)
        return;
    if (i == r - 1 && j == c - 1)
    {
        cout << s << "\n";
        return;
    }
    visit[i][j] = 1;
    for (int x = 0; x < 4; ++x)
    {
        s += direction[x];
        FindPaths(arr, r, c, i + di[x], j + dj[x], s, visit);
        s.pop_back();
    }
    visit[i][j] = 0;
}
int main(void)
{
    int r = 3, c = 2;
    vector<vector<int>> arr(r, vector<int>(c, 0));
    string s = "";
    vector<vector<int>> visit(r, vector<int>(c, 0));
    FindPaths(arr, r, c, 0, 0, s, visit);
    return 0;
}