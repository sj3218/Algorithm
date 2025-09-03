#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int service = n/10;
    int drinks = k- service;
    
    return 12000 * n + drinks * 2000;
}