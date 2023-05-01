# [main関数とコマンドライン引数](https://learn.microsoft.com/ja-jp/cpp/cpp/main-function-command-line-args?view=msvc-170)

[コマンドラインの各引数について](https://learn.microsoft.com/ja-jp/cpp/cpp/main-function-command-line-args?view=msvc-170#example-of-command-line-argument-parsing)

```cpp
// command_line_arguments.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
int main( int argc,      // Number of strings in array argv
          char *argv[],   // Array of command-line argument strings
          char *envp[] )  // Array of environment variable strings
{
    int count;

    // Display each command-line argument.
    cout << "\nCommand-line arguments:\n";
    for( count = 0; count < argc; count++ )
         cout << "  argv[" << count << "]   "
                << argv[count] << "\n";
}
```