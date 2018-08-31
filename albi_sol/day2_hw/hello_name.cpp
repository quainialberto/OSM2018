#include <stdio.h>
#include <string>

int main (void)
{
    //string name {""};
    //cout << "Insert your name: ";
    //getline(cin, name);
    const std::string name {"albi"};
    printf("Hello %s, how are you? ", name.c_str());

    return 0;
}
