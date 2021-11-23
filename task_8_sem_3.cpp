#include <iostream>
#include <list>
#include <iterator>
using namespace std;
typedef pair<int, int> monom;
typedef list<monom> polynom;
/*monom operator+ (monom A, monom B) {
    monom p;
    p.first = A.first;
    p.second = A.second + B.second;
    return p;
}
*/

polynom operator+ (polynom B, polynom A) {
    auto iter = A.begin();
    for (auto it = B.begin(); it != B.end(); it++) {
        for (iter = A.begin(); iter != A.end(); iter++) {
            if (it->first == iter->first) {
                iter->second = iter->second + it->second;
                break;
            }
        }
        if (iter == A.end()) A.push_back(*it);

    }
    A.sort();
    return A;
}
monom operator* (int a, monom B) {
    monom p;
    p.first = B.first;
    p.second = a * B.second;
    return p;
}
polynom operator* (int a, polynom B) {
    polynom p;
    if (B.size() >= 1) {
        for (auto it = B.begin(); it != B.end(); it++) {
            p.push_back(a*(*it));
        }
    }
    return p;
}
monom operator* (monom A, monom B) {
    monom p;
    p.first = A.first + B.first;
    p.second = A.second * B.second;
    return p;
}
/*monom operator- (monom A, monom B) {
    monom p;
    p = A + (-1) * B;
    return p;
}
*/
polynom operator- (polynom A, polynom B) {
    list<pair<int, int>> p;
    p = A + (-1) * B;
    return p;
}

polynom operator* (monom A, polynom B) {
    polynom p;
    for (auto it = B.begin(); it != B.end(); it++) {
        p.push_back((*it) * A);
    }

    return p;

}
polynom operator* (polynom A, polynom B) {
    polynom p;
    p.push_back(make_pair(0, 0));
    for (auto it = B.begin(); it != B.end(); it++) {
        p = (*it)*A + p;
    }
    p.sort();
    return p;

}
int main()
{
    polynom  A[11];
    monom  x = { 1,1 };
    A[0].push_back(make_pair(0, 1));
    A[1].push_back(make_pair(1, 1));
    for (int i = 2; i < 11; i++) {
        A[i] = x * A[i - 1] - (i - 1) * A[i - 2];
        for (auto it = A[i].begin(); it != A[i].end(); it++) {
            if (it->second) cout << it->second << " " << it->first << "  ";
        }
        cout << endl;
    }
   
    
    return 0;
}

