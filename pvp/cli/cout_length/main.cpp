#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
//    string s;
//    getline(cin, s);
//    for (int i = s.length() - 1; i >= 0; i--) {
//        cout << s[i] << endl;
//    for (char &slovo : s) {
//        slovo = toupper(slovo);

//        cout << "velkejma " << s << endl;
//    }

//}
    string s;
    getline(cin, s);
    reverse(s.begin(), s.end());
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s;
}
