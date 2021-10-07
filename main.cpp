#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include "sha256.cpp"

using namespace std;

string letters [70] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", 
"K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", 
"Z", "Ą", "Č", "Ę", "Ė", "Į", "Š", "Ų", "Ū", "Ž", "a", "b", "c", "d", "e", 
"f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", 
"u", "v", "w", "x", "y", "z", "ą", "č", "ę", "ė", "į", "š", "ų", "ū", "ž"};
int numbers [70] = {1111, 2222, 3333, 4444, 5555, 6666, 7777, 8888, 
9999, 1112, 2223, 3334, 4445, 5556, 6667, 7778, 8889, 9990, 1123,
2234, 3345, 4456, 5567, 678, 7789, 8890, 9901, 1134, 2345, 3346, 
4567, 5578, 6689, 7780, 8801, 9912, 1245, 2346, 3567, 4578, 5789, 
6890, 7801, 8912, 9134, 9685, 6852, 3857, 8574, 5241, 2740, 7496,
9745, 9765, 8654, 7643, 6532, 5421, 4320, 3209, 2098, 1987, 1375, 
8640, 5657, 8989, 5356, 2525, 6523, 1259};

void txtFILE (string &info)
{
    ifstream in ("empty.txt");
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
    cout << "Hash: " <<hex<< bye << endl; 
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
                if(integer<0)
                    integer=integer*(-1);
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
        int change = numbers[INPUTsize+i]*(INPUTsize+i);
        change = change % 10;
        code += to_string(change);
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
string HASHING2(string text)
{
    srand((unsigned int)time(NULL));
    string code;
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
                if(integer<0)
                    integer=integer*(-1);
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
        int iSecret = rand() % 69;
        int change = numbers[iSecret+i]*(INPUTsize+i);
        change = change % 10;
        if(change<0)
        {
            change=change*(-1);
        }
        code += to_string(change);//+letters[iSecret];
        i++;
        if(i >= 70)
        {
            i=0;
        }
    }
    
    while(code.size() >= 65)
    {
        code.erase(code.end()-1);
    }  
    return code;
}
int Kolizija10(int NumOfstrings, vector<string> poros10)
{
    int diff=0;
    int SameHash10=0;
    for(int i=0; i<NumOfstrings; i++)
    {
        if(poros10[i]!=poros10[i+1])
        {
            if(HASHING2(poros10[i])!=HASHING2(poros10[i+1]))
            {
                diff+=1;
            }
        }
        i++;
    }
    SameHash10=25000-diff;
    return SameHash10;
}
void Kolizija()
{
    int NumOfstrings=50000;
    vector <string> poros10, poros100, poros500, poros1000;
    string tempp;
    int SameHash10=0, SameHash100=0, SameHash500=0, SameHash1000=0;
    char temp[11];
    ifstream in ("poros10.txt");
    for(int i=0; i<NumOfstrings; i++)
    {
        in.get (temp, 11);
        in.ignore (20, '\n');
        tempp=temp;
        poros10.push_back(tempp);
    }
    in.close();
    SameHash10=Kolizija10(NumOfstrings, poros10);
    char t[101];
    ifstream inf ("poros100.txt");
    for(int i=0; i<NumOfstrings; i++)
    {
        inf.get (t, 101);
        inf.ignore (20, '\n');
        tempp=t;
        poros100.push_back(tempp);
    }
    inf.close();
    SameHash100=Kolizija10(NumOfstrings, poros100);
    char tmp[501];
    ifstream fin ("poros500.txt");
    for(int i=0; i<NumOfstrings; i++)
    {
        fin.get (tmp, 501);
        fin.ignore (20, '\n');
        tempp=tmp;
        poros500.push_back(tempp);
    }
    fin.close();
    SameHash500=Kolizija10(NumOfstrings, poros500);
    char tem[1001];
    ifstream f ("poros1000.txt");
    for(int i=0; i<NumOfstrings; i++)
    {
        f.get (tem, 1001);
        f.ignore (20, '\n');
        tempp=tem;
        poros1000.push_back(tempp);
    }
    f.close();
    SameHash1000=Kolizija10(NumOfstrings, poros1000);
    cout<<"Hash kodai sutapo: \nPorose po 10: "<<SameHash10<<"\nPorose po 100: "<<SameHash100
    <<"\nPorose po 500: "<<SameHash500<<"\nPorose po 1000: "<<SameHash1000<<"\n";
}
void Efektyvumas()
{
    vector <string> kons;
    string temp, out;
    ifstream in ("konstitucija.txt");
    for(int i=0; i<774; i++)
    {
        getline(in, temp);
        temp.erase(remove(temp.begin(), temp.end(), ','), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '.'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '-'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '('), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), ')'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '/'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), ';'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), ':'), temp.end());
        kons.push_back(temp);
    }
    in.close();
    auto start = std::chrono::steady_clock::now();
    for(int j=0; j<774; j++)
    {
        HASHING2(kons[j]);
    }
    cout << "Failo konstitucija.txt hashavimas truko: " << 
    chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << " ms" << endl;
}
void Papildoma(vector <string> words)
{
    string input;auto start = std::chrono::steady_clock::now();
    for(int i=0; i<100000; i++)
    {
        sha256(words[i]);
    }
    cout << "100 000 string'u hash'avimas su SHA256 truko: " << 
    chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << " ms" << endl;
    auto start1 = std::chrono::steady_clock::now();
    for(int i=0; i<100000; i++)
    {
        HASHING2(input);
    }
    cout << "100 000 string'u hash'avimas su mano funkcija truko: " << 
    chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start1).count() << " ms" << endl;
}
string FileForPapildoma()
{
    vector <string> words;
    string word;
    ifstream in ("visos.txt");
    for(int i=0; i<100000; i++)
    {
        in >> word;
        words.push_back(word);
    }
    in.close();
    Papildoma(words);
}
void Skirtingumas()
{
    vector <string> wrd;
    string ww, code, code2;
    int equal =0, percentage[40], num=0, nn=0;
    int minimal=100, maximal=0;
    double all;
    ifstream in ("skirtingumas.txt");
    for(int i=0; i<80; i++)
    {
        in >> ww;
        wrd.push_back(ww);
    }
    in.close();
    for(int a=0; a<80; a++)
    {
        code = HASHING2(wrd[a]);
        code2 = HASHING2(wrd[a+1]);
        for(int b=0; b<64; b++)
        {
            if(code[b] == code2[b])
            {
                equal++;
            }
        }
        percentage[num]=64/equal;
        if(num>-1 && percentage[num]>maximal)
        {
            maximal=percentage[num];
        }
        if(num>-1 && percentage[num]<minimal)
        {
            minimal=percentage[num];
        }
        a++;
        equal=0;
        num++;
    }
    for(int jj=0; jj<40; jj++)
    {
        nn+=percentage[jj];
    }
    all=nn/40;
    cout<<"HEX LYGMENYJE:"<<endl;
    cout<<"Minimali skirtingumo reiksme: "<<minimal<<"%"<<endl;
    cout<<"Maksimali skirtingumo reiksme: "<<maximal<<"%"<<endl;
    cout<<"Visu 40 poru skirtingumo koeficientas: "<<all<<"%"<<endl;
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Lithuanian");
    string in;
    string answer, answer1;
    int answer2;
    string output;
    string FileNameInput, inside;
    vector <string> comparing, FileName;
    cout << "Kokia bus jusu ivestis? (t-tekstinio failo ar n-rankiniu budu ar l-tyrimai)" << endl;
    cin >> answer;
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
    else if(answer=="l")
    {
        cout << "Ka norite tikrinti? \n(e-efektyvuma / k-kolizija / p-papildoma / s-skirtinguma)" << endl;
        cin >> answer1;
        if(answer1=="e")
        {
            Efektyvumas();
        }
        else if(answer1=="k")
        {
            Kolizija();
        }
        else if(answer1=="p")
        {
            FileForPapildoma();
        }
        else if(answer1=="s")
        {
            Skirtingumas();
        }
    }
    else 
    {
        cout << "Jusu atsakymas neteisingas, paleiskite programa is naujo" ;
        exit;
    }    
    return 0;
}