#include <iostream>
#include <string.h>

using namespace std;
int main(int argc, char *argv[], char *envp[])
{
    int count;

    cout << "\nCommand line arguments:\n";
    for (count = 0; count < argc; count++)
        cout << "argv[" << count << "]  "
            << argv[count] << "\n";
}