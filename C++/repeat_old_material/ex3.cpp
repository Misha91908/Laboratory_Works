#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    int length = 0;
    string count, token;
    double out = 0.0;

    for(int i = 0; i < argc; i++ )
    {
        if(strstr(argv[i], "-poly="))
        {
            count = argv[i];
        }
    }

    unsigned long equals_index_pos = count.find('=');
    count = count.erase(0, equals_index_pos+1);

    stringstream ss(count);
    while(getline(ss, token, ','))
    {
        length++;
    }

    int* data =  new int[length];
    stringstream ss1(count);

    for(int i = 0; i < length; i++)
    {
        getline(ss1, token, ',');
        data[i] = stoi(token);
    }

    for (int i = 0; i < length; i++)
    {
        out += 1.0/(data[i]*3.0);
    }
    cout << out << endl;
    return 0;
}