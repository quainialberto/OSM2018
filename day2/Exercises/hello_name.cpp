#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name = "";
    cout << "Insert your name: ";
    getline(cin, name);
    cout << "Hello " << name << ", how are you?" << std::endl;

    return 0;

}
