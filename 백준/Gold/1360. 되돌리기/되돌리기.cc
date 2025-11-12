#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int N;
string text[51];

struct ORDER
{
    bool is_type; 
    string c;
    int time_;
};

ORDER orders[51];

ORDER Split()
{
    ORDER order;
    string token;

    cin >> token;

    if (token == "type")
        order.is_type = true;
    else
        order.is_type = false;

    cin >> token;
    order.c = token;
    cin >> token;
    order.time_ = stoi(token);
    return order;
}

void Undo(ORDER order, int idx)
{
    string s;
    int taking_time = 0;
    int i = idx;
    int order_time = stoi(order.c);
    while (taking_time <= order_time)
    {
        if (i <= 0)
        {
            text[idx] = "";
            return;
        }
        taking_time += (orders[i].time_ - orders[i - 1].time_);
        --i;
    }

    text[idx] = text[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    ORDER order;

    for (int i = 1; i <= N; ++i)
    {
        order = Split();
        orders[i] = order;

        if (order.is_type)
        {
            text[i] = text[i - 1] + order.c;
        }
        else
        {
            Undo(order, i);
        }
    }

    cout << text[N];
    return 0;
}