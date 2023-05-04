#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <iostream>
using namespace std;
class ShowData{
public:
    ShowData( const char *filename , const char *input_string) { 
        OutputDev = fopen(filename, "w");
        if (OutputDev == NULL) {
            cout << "Error:" << filename << "is not found" << endl;
            exit(1);
        }
        else {
            cout << filename << "is opened." << endl;
        }
        text = input_string;
    }

    ~ShowData() {
        cout << text << "is written to " << filename << endl;
        fclose(OutputDev);
    }

    void write() {
        fprintf(OutputDev , text);
    }
private:
    FILE *OutputDev;
    const char *text;
    const char *filename;
}

ShowData sd1("test", "test in test file");

int main() {
    sd1.write();
    return 0;
}