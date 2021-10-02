#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <time.h>

using namespace std;

string letters [52] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", 
"k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", 
"z", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", 
"O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
int numbers [52] = {11111, 22222, 33333, 44444, 55555, 66666, 77777, 88888, 
99999, 11112, 22223, 33334, 44445, 55556, 66667, 77778, 88889, 99990, 11123,
22234, 33345, 44456, 55567, 66678, 77789, 88890, 99901, 11234, 22345, 33456, 
44567, 55678, 66789, 77890, 88901, 99012, 12345, 23456, 34567, 45678, 56789, 
67890, 78901, 89012, 91234, 96385, 63852, 38527, 85274, 52741, 27410, 74196};
void txtFILE (string &info)
{
    ifstream in ("tekstas.txt");
    in >> info;
    in.close();
}
string FilesForComparing (string FileName)
{
    string Coming;
    ifstream in (FileName);
    in >> Coming;
    in.close();
    return Coming;
}
void HAND (string &info)
{
    cout<<"Iveskite norima hash'inti teksta: "<<endl;
    cin >> info;
}
string MoreThanOne ()
{
    string coming;
    cout<<"Iveskite norima hash'inti teksta: "<<endl;
    cin >> coming;
    return coming;
}
void isvedimas(string bye)
{
    cout << "Hex: " <<hex<< bye << endl; 
}
void HASHING(string text, string code)
{
    code.clear();
    vector <string> arr;
    string temp, temprorary;
    long int integer;
    int sizes, index, n=64;
    int INPUTsize = text.size();
    int ii= 0;
    if(INPUTsize > 6)
    {
        string::size_type i = 0;
        while( i < text.size() && arr.size() < 6) 
        {
            temp = text[i];
            arr.push_back(temp);
            i=i+3;
        }
    }
    else
    {
        for (string::size_type i = 0; i < text.size(); i++) 
        {
            temp = text[i];
            arr.push_back(temp);
        }
    }
    int m=code.size();
    for(int i = 0; i<arr.size(); i++)
    {
        for(int j=0; j<52; j++)
        {
            if(arr[i] == letters[j])
            {
                integer = 0;
                integer = numbers[j+5] * INPUTsize;
                integer = integer + ((integer+5)* (INPUTsize * (j + j + 3)));
                //if(integer<0)
                //    integer=integer*(-1);
                temprorary = ' ';
                temprorary = letters[j+1];
                code += to_string(integer);
                code += temprorary;
            }
        }
    }

    int i = 0;
    while(code.size() < 64)
    {
        int k1 = numbers[INPUTsize+i]*(INPUTsize+i);
        k1 = k1 % 10;
        code += to_string(k1);
        i++;
        if(i >= 52)
        {
            i=0;
        }
    }
    
    while(code.size() >= 65)
    {
        code.erase(code.end()-1);
    }  
    isvedimas(code);
}
int main()
{
    string in;
    string answer;
    int answer2;
    string output;
    string FileNameInput, inside;
    vector <string> comparing, FileName;
    cout << "Kokia bus jusu ivestis? (t-tekstinio failo ar n-rankiniu budu)" << endl;
    cin >> answer;
    cout << "Kiek atskiru ivesciu norite lyginti? (iveskite skaiciu nuo 1 iki 5)\nJei nenorite lyginti, rasykite 1" << endl;
    cin >> answer2;
    if(answer == "t") 
    {
        if (answer2>1 && answer2<=5)
        {
            for(int i=0; i<answer2; i++)
            {
                cout<<"Iveskite "<< i+1<<" skaitomo failo pavadinima:"<<endl;
                cin>>FileNameInput;
                FileName.push_back(FileNameInput);
                string myStr=FilesForComparing(FileNameInput);
                comparing.push_back(myStr);
            }
            cout<<"VYKDOMA..."<<endl;
            for(int a=0; a<answer2; a++)
            {
                cout<<FileName[a]<<": "<<endl;
                HASHING(comparing[a], output);
            } 
        }
        else if(answer2>5)
        {
            cout<<"Norite lyginti per daug ivesciu, paleiskite programa is naujo."<<endl;
            exit;
        }
        else 
        {
            txtFILE(in);
            HASHING(in, output);
        }
    }
    else if(answer == "n") 
    {
        
        if (answer2>1 && answer2<=5)
        {
            for(int i=0; i<answer2; i++)
            {
                string myStr = MoreThanOne();
                comparing.push_back(myStr);
            }
            for(int a=0; a<answer2; a++)
            {
                cout<<comparing[a]<<": "<<endl;
                HASHING(comparing[a], output);
            }
        }
        else if(answer2>5)
        {
            cout<<"Norite lyginti per daug ivesciu, paleiskite programa is naujo."<<endl;
            exit;
        }
        else 
        {
            HAND(in);
            HASHING(in, output);
        }
    }
    else 
    {
        cout << "Jusu atsakymas neteisingas, paleiskite programa is naujo" ;
        exit;
    }

    return 0;
}