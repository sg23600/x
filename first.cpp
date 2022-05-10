// Input: input.txt

// S->ACB|CbB|Ba
// A->da|BC
// B->g|e
// C->h|e

#include <bits/stdc++.h>
using namespace std;

set<char> ss;

bool dfs(char i, char org, char last, map<char, vector<vector<char>>> &mp)
{
    bool rtake = false;
    for (auto r : mp[i])
    {
        bool take = true;
        for (auto s : r)
        {
            if (s == i)
                break;
            if (!take)
                break;
            if (!(s >= 'A' and s <= 'Z') and s != 'e')
            {
                ss.insert(s);
                break;
            }
            else if (s == 'e')
            {
                if (org == i or i == last)
                    ss.insert(s);
                rtake = true;
                break;
            }
            else
            {
                take = dfs(s, org, r[r.size() - 1], mp);
                rtake |= take;
            }
        }
    }
    return rtake;
}

int main()
{
    int i, j;
    ifstream fin("input.txt");
    string num;
    vector<int> fs;
    vector<vector<int>> a;
    map<char, vector<vector<char>>> mp;
    char start;
    bool flag = 0;
    cout << "Grammar: " << '\n';
    while (getline(fin, num))
    {
        // cout<<num<<" ] "<<endl;
        if (flag == 0)
            start = num[0], flag = 1;
        cout << num << '\n';
        vector<char> temp;
        char s = num[0];
        for (i = 3; i < num.size(); i++)
        {
            if (num[i] == '|')
            {
                mp[s].push_back(temp);
                temp.clear();
            }
            else
                temp.push_back(num[i]); // Build each prod rule until |
        }
        mp[s].push_back(temp);
    }

    // mp stores all production rules as a hashmap
    // S : [{ACB, CbB, Ba}]
    // A : [{da, BC}]
    // B : [g, e]
    // C : [h, e]

    map<char, set<char>> fmp;
    for (auto it1 : mp)
    {
        ss.clear();
        dfs(it1.first, it1.first, it1.first, mp);
        for (auto it2 : ss)
            fmp[it1.first].insert(it2);
    }

    // fmp stores all unique terminals we can reach from a given non terminal

    // A: d,e,g,h
    // B: e,g
    // C: e,h
    // S: a,b,d,e,g,h

    cout << "\n";

    // Contents of fmp is printed here
    cout << "FIRST: " << '\n';
    for (auto q : fmp)
    {
        string ans = "";
        ans += q.first;
        ans += " = {";
        for (char r : q.second)
        {
            ans += r;
            ans += ',';
        }
        ans.pop_back();
        ans += "}";
        cout << ans << '\n';
    }
    return 0;
}
