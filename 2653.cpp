#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    set<string> jewels;
    char buffer[1000001];
    
    while (scanf("%s", buffer) != EOF) {
        string jewel = buffer;
        jewels.insert(jewel);
    }
    
    printf("%lu\n", jewels.size());
    
    return 0;
}
