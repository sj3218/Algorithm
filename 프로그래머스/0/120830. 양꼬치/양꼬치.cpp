#include <string>
#include <vector>

using namespace std;
const int lamb_price = 12000;
const int drink_price = 2000;
int solution(int n, int k) {
    int service = n/10;
    int drinks = k- service;
    return lamb_price * n + drink_price * drinks;
}