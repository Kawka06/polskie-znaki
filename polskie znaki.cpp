#include <iostream>
#include <string>

using namespace std;

const string PATTERN = "ąĄśŚźŹłŁóżŻńŃęĘćĆÓ";

int *zle_pl (string);

int *zle_polskie_znaki = zle_pl(PATTERN);

string pl(string);

const int polskie_znaki[] = { -91, -92, -104, -105, -85, -115, -120, -99, -94, -66, -67, -28, -29, -87, -88, -122, -113, -32 };

int main()
{
    char zn;
    cin >> zn;

    cout << static_cast<int>('ą') << endl;
    cout << pl("wpisany ąĄśŚźŹłŁ znak to : ąĄśŚźŹłŁóżŻńŃęĘćĆÓ") << static_cast<int>(zn) << endl;

    return 0;

}

int *zle_pl(string pattern)
{
    int* tab = new int[pattern.length()];

    for (int i = 0; i < pattern.length(); i++)
        tab[i] = static_cast<long int>(pattern[i]); // przepełnienie bufora , 4 bajty na normalnym int , może być 8 , dlatego long int

    return &tab[0];

}

string pl(string napis)
{
    for (int i = 0; i < napis.length(); i++)
        for (int j = 0; j < PATTERN.length(); j++)
        {
            if (napis[i] == zle_polskie_znaki[j])
            {
                napis[i] = polskie_znaki[j];
                break;
            }
        }
    return napis;
}
