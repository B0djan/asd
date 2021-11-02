#include <stdio.h>
#include <string>

using namespace std;

bool DFA(string const &s) {
    enum {OUT, IN1, IN2} state = OUT;
    for (auto c: s) {
        if (state == IN1 && c == '\'') state = OUT;
        else if (state == IN2 && c == '"') state = OUT;
        else if (state == OUT && c == '\'') state = IN1;
        else if (state == OUT && c == '"') state = IN2;
    }
    return state == OUT;
}

int main() {
    string str1 = "'Строка ли я?'";
    bool first = DFA(str1);
    printf("%d\n",int(first));
    string str2 = "'А я строка ?";
    bool second = DFA(str2);
    printf("%d\n",int(second));
    string str3 = "";
    bool fird = DFA(str3);
    printf("%d\n",int(fird));
    return 0;
}