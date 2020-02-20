#include <cstdio>
#include <algorithm>
#include <iostream>

#define LD long double
using namespace std;

namespace axis {
    static const int maxn = 6 + 5;

    class point {
    public:
        LD x, y;

        point() {}

        point(LD x, LD y) : x(x), y(y) {}
    };

    class line {
    public:
        LD A, B, C;

        line() {}

        line(point p1, point p2) {
            A = p1.y - p2.y;
            B = p2.x - p1.x;
            C = p1.x * p2.y - p2.x * p1.y;
        }
    };

    line arr[maxn];

    point getCross(line l1, line l2) {
        return {(l1.B * l2.C - l2.B * l1.C) / (l1.A * l2.B - l2.A - l1.B),
                -(l1.A * l2.C - l2.A - l1.C) / (l1.A * l2.B - l2.A * l1.B)};
    }

    void getPlace() {
        point cnt[33 + 10];
        LD x = 0, y = 0;
        int tot = 0;
        for (int i = 0; i < 6; i++)
            for (int j = i + 1; j < 6; j++) {
                cnt[tot++] = getCross(arr[i], arr[j]);
            }
        for (int i = 0; i < tot; i++) {
            x += cnt[i].x, y += cnt[i].y;
        }
        cout << "末地入口的坐标为：\nx = " << x / tot << "\n" << "y = " << y / tot << endl;
    }

    void read() {
        for (int i = 0; i < 6; i++) {
            printf("第%d组数据，请任选一个坐标点：\n", i + 1);
            LD x1, y1, x2, y2;
            cin >> x1 >> y1;
            printf("请根据末影珍珠的方向，前进一段距离，然后输入坐标，请务必将屏幕中的十字准星对准珍珠！\n");
            cin >> x2 >> y2;
            arr[i] = {{x1, y1},
                      {x2, y2}};
        }
    }
};


int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    axis::read();
    axis::getPlace();
    system("pause");
}