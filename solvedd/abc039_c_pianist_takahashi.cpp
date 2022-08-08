#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string S;
    cin >> S;
    auto pos = S.find("WWBWBWW");
    string tone[] = {"Si", "", "La", "", "So", "", "Fa", "Mi", "", "Re", "", "Do"};
    cout << tone[pos%12] << endl;
}