#include<iostream> 
using namespace std;

// 判断元音/辅音(英语有 26 个字母，元音只包括 a、e、i、o、u 这五个字母，其余的都为辅音。y是半元音、半辅音字母，但在英语中都把他当作辅音。)
int main3() {
    char c;
    bool ischar;
    int isLowercaseVowel, isUppercaseVowel;
    cout << "输入一个字母：";
    cin >> c;
    ischar = ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    if (ischar) {
        // 小写字母元音
        isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        // 大写字母元音
        isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
        // if 语句判断
        if (isLowercaseVowel || isUppercaseVowel)
            cout << c << " 是元音";
        else
            cout << c << " 是辅音";
    }
    else {
        cout << "输入的不是字母。";
    }

    return 0;
}