#include <iostream>
using namespace std;

/*
猴子吃桃问题
一只小猴子一天摘了许多桃子，第一天吃了一半，然后忍不住又吃了一个；第二天又吃了一半，再加上一个；后面每天都是这样吃。到第10天的时候，小猴子发现只有一个桃子了。问小猴子第一天共摘了多少个桃子。
*/
int main13()
{
    int x;
    int y = 1;
    for (int i = 0; i < 9; i++) 
    {
        x = 2 * (y + 1);
        y = x;
    }
    cout << y << endl;

    return 0;
}