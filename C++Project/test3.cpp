#include<iostream> 
using namespace std;

// �ж�Ԫ��/����(Ӣ���� 26 ����ĸ��Ԫ��ֻ���� a��e��i��o��u �������ĸ������Ķ�Ϊ������y�ǰ�Ԫ�����븨����ĸ������Ӣ���ж���������������)
int main3() {
    char c;
    bool ischar;
    int isLowercaseVowel, isUppercaseVowel;
    cout << "����һ����ĸ��";
    cin >> c;
    ischar = ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    if (ischar) {
        // Сд��ĸԪ��
        isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        // ��д��ĸԪ��
        isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
        // if ����ж�
        if (isLowercaseVowel || isUppercaseVowel)
            cout << c << " ��Ԫ��";
        else
            cout << c << " �Ǹ���";
    }
    else {
        cout << "����Ĳ�����ĸ��";
    }

    return 0;
}