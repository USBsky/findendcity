#include <cstdio>
#include <algorithm>
#include <iostream>
#include <random>
#define LB long double
using namespace std;
const int maxn = 32;

class point
{
public:
    LB x = 0, y = 0;
    point() {};
    point(LB x, LB y)
    {
        this->x = x;
        this->y = y;
    }
    ~point() {};
};

class line
{
public:
    LB k, b;
    line() {};
    line(point p1, point p2)
    {
        k = (p2.y - p1.y) / (p2.x - p1.x);
        b = p2.y - k * p2.x;
    }
};

line arr[6];

LB minp(LB a, LB b, LB c)
{
    if (c < min(a, b))
        return c;
    else
        return min(a, b);
}
LB maxp(LB a, LB b, LB c)
{
    if (c > max(a, b))
        return c;
    else
        return max(a, b);
}

point getmid(line l1, line l2, line l3)
{
    LB xlow, xhigh, ylow, yhigh;
    point p1 = { (l2.b - l1.b) / (l1.k - l2.k), (l1.k * l2.b - l1.b * l2.k) / (l1.k - l2.k) };
    point p2 = { (l2.b - l3.b) / (l3.k - l2.k), (l3.k * l2.b - l3.b * l2.k) / (l3.k - l2.k) };
    point p3 = { (l3.b - l1.b) / (l1.k - l3.k), (l1.k * l3.b - l1.b * l3.k) / (l1.k - l3.k) };
    xlow = minp(p1.x, p2.x, p3.x), xhigh = maxp(p1.x, p2.x, p3.x), ylow = minp(p1.y, p2.y, p3.y), yhigh = maxp(p1.y, p2.y, p3.y);
    return { (xlow + xhigh) / 2, (ylow + yhigh) / 2 };
}

void getans()
{
    point ans[maxn];
    int cnt = 0;
    LB x = 0, y = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            for (int k = j + 1; k < 6; k++)
            {
                ans[cnt++] = getmid(arr[i], arr[j], arr[k]);
            }
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        x += ans[i].x, y += ans[i].y;
    }
    x /= cnt, y /= cnt;
    cout << "末地入口 x = " << x << " " << "y = " << y << endl;
}


void read()
{
    printf("总共需要测量六次！\n");
    for (int i = 0; i < 6; i++)
    {
        LB x1, y1, x2, y2;
        printf("第%d次测量：\n请输入第一个坐标，x, y用空格隔开：\n", i + 1);
        cin >> x1 >> y1;
        printf("请输入第二个坐标， x, y用空格隔开：\n");
        cin >> x2 >> y2;
        arr[i] = line({ x1, y1 }, { x2, y2 });
    }
}

int main()
{
    freopen("data.in", "r", stdin);
    read();
    getans();
}