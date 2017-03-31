#include <iostream>
#include "CircLinklist.h"

int main() {
    CircleLinkList<int> cl;
    int position = 0;
    int n, m, out, king;
    cout << "猴子数量:";
    cin >> m;
    cout << "第几个出局:";
    cin >> n;
    cl.CreateCircleList(m);
    cout << "出局:";
    for (int i = 1; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            position++;
            if (position > cl.Length())
                position = 1;
        }
        cl.Delete(position--, out);
        cout << out << " ";
    }
    cl.GetElem(1, king);
    cout << endl << "大王是第" << king << "个猴子" << endl;
}