#define _CRT_SECURE_NO_WARNINGS
#include "myfile.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <cctype>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " [filePointer/fileStream]" << endl;
        return 1;
    }
     string mode = argv[1];
    meny(); //������ ������� ��� ������ ����
    if (mode == "filePointer") 
    {
        char filename[] = "test.txt";
        char outputName[] = "output.txt";
        inputFilePointer();//��������� ����, ���������� ����
        cout << "\nThe contents of the source file:" << endl;
        printFilePointer(filename); //���� ����� �����
        changeFilePointer();//���� ����� �� ������
        cout << "The contents of the modified source file:" << endl;
        printFilePointer(filename);//���� ����� �����
        cout << "The contents of the new file" << endl;
        printFilePointer(outputName);//���� ����� �����
    }
    else if (mode == "fileStream") 
    {
        string filename = "test.txt";
        string newfilename = "output.txt";
        inputFileStream();//��������� ����, ���������� ����
        cout << "\nThe contents of the source file:" << endl;
        printFileStream(filename);//���� ����� �����
        changeFileStream();//���� ����� �� ������
        cout << "The contents of the modified source file:" << endl;
        printFileStream(filename);//���� ����� �����
        cout << "The contents of the new file:" << endl;
        printFileStream(newfilename);//���� ����� �����
    }
    else {
        cout << "Unknown mode: " << mode << endl;
        return 1;
    }
    char c;
    cout << "Do you want to add a file? Y/N >>"; //���������� �����
    cin >> c;
    if (c == 'y' || c == 'Y')
    {
        if (mode == "filePointer") {
            addFilePointer();
        }
        else if (mode == "fileStream")
        {
            addFileStream();
        }
    }
    return 0;
}

