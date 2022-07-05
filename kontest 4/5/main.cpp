#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    ifstream inFile("input.txt");
    string line;
    getline(inFile, line);
    cout << line << "\n";

    vector<vector<string>> a;
    vector<string> empty;
    a.push_back(empty);
    a.size();
    int i = 0;

    while (inFile.good())
    {
        string elem;
        inFile >> elem;
        a[i].push_back(elem);
        if (inFile.peek()=='\n')
        {
            ++i;
            a.push_back(empty);
        }
    }

    a.size();

    for (auto& j : a) {
        for (auto& k : j) {
            cout << k << " ";
        }
        cout << "\n";
    }

    return 0;
}
