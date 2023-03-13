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
//laba1OP\x64\Debug\laba1OP.exe fileStream
using namespace std;

void inputFileStream() //������� ������ � ����
{
    string line;
    ofstream ioFile;
    ioFile.open("test.txt", ios::out);
    if (!ioFile){
        cout << "Error opening the file!\n";
        return;
    }
    cout << "Enter the text, if you want to finish recording, enter EXIT" << endl;
    cin.ignore();
    while (true)//����� � ���� ������ �� ������ ���� ���������� �� ����� "EXIT"
    {
        getline(cin, line);
        if (line == "EXIT") { 
            break;
        }
        ioFile << line << endl;
    } 
    ioFile.close();
}
void inputFilePointer()//������� ������ � ����
{
    FILE* File;
    errno_t err = fopen_s(&File, "test.txt", "w");
    if (err != 0) {
        cout << "Error opening file!" << endl;
        return;
    }
    char line[300];
    char exit[] = "EXIT";
    cout << "Enter the text, if you want to finish recording, enter EXIT" << endl;
    cin.ignore();
    while (true)//����� � ���� ������ �� ������ ���� ���������� �� ����� "EXIT"
    {
        cin.getline(line, 300);
        if (strcmp(line, exit) == 0) {
            break;
        }
        fprintf(File, "%s\n", line);
    }
    fclose(File);
}

void printFileStream(string name) //������� ������ ����� �����
{
    string line;
    ifstream inFile;
    inFile.open(name);
    if (!inFile) {
        cout << "Unable to open file";
        return;
    }
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
    cout << "====================================" << endl;
}

void printFilePointer(char name[]) //������� ������ ����� �����
{
    FILE* fp;
    char text[300];
    fopen_s(&fp, name, "r");
    while (fgets(text, 300, fp) != NULL) { 
        cout << text;
    }
    fclose(fp); 
    cout << "====================================\n";
}

void changeFileStream() //������� ���� �����
{
    string line;
    int n = 1;
    ifstream File("test.txt", ios::in);
    ofstream inFile("output.txt", ios::out);
    ofstream NewFile("newfile.txt", ios::out);
    if (!File){
        cout << "Error opening the file!\n";
        return;
    }
    if (!inFile) {
        cout << "Error opening the file!\n";
        return;
    }
    if (!NewFile) {
        cout << "Error opening the file!\n";
        return;
    }
    while (getline(File, line))
    {
        if (n % 2 != 0)
        {
            string word = ""; // ����� ��� ���������� ��������� �����
            char last_letter = '\0'; // ����� ��� ���������� �������� ����� ������� 
            bool first_word = true; // ����, �� �����, �� ������������ ����� �����
            for (char c : line) {
                if (c == ' ' || c == '.') {
                    if (first_word) {     // ���� ������� ����� - ����� �����, �� �������� ������� �����
                        last_letter = word[word.length() - 1];
                        first_word = false;
                    }
                    if (word.find(last_letter) == string::npos) {   // ���� ������� ����� �� ������ ������� ����� ������� �����, �������� ���� � ����� ����
                        NewFile << word << " ";  
                    }
                    word = "";    // ������� ����� ��� ��������� ��������� �����
                }
                else {
                    word += c;  // ���� ������ �� ����� � �� ������, �� �� �������� �� ��������� �����
                }
            }
            NewFile << "\n";
        }
        if (n % 2 == 0)
        {
            //NewFile << line << endl;
            string word = ""; // ����� ��� ���������� ��������� �����
            for (int i = 0; i < line.length(); i++)  //����, �� ��������� ���� ����� ������ �������� ����� line
            {
                char ch = line[i];  //������� �������� ������ ch � �������� �����
                if (ch == ' ' || ch == '.')   //���� �������� ������ - ����� ��� ������
                {
                    char last_letter = word[word.length() - 1];  //�� ��������� ����� last_letter, � ��� �������� ������� ����� ��������� ����� word
                    for (int j = 0; j < word.length() - 1; j++)
                    {
                        if (word[j] == last_letter) {
                            word[j] = '.';            //���������� ����� ����� ��������� ����� word, ��� ��������, � ���� ���� ������� � ��������� ������ last_letter, �� �������� �� �� ������
                        }
                    }
                    inFile << word << ch << " ";
                    word = "";
                }
                else {
                    word += ch; 
                }
            }
           inFile << endl;
        }
        n++;
    }
    NewFile.close();
    inFile.close();
    File.close();
    remove("test.txt");
    rename("newfile.txt", "test.txt");

}

void changeFilePointer() //������� ���� �����
{
    FILE* File;
    FILE* output;
    FILE* newfile;
    errno_t err1 = fopen_s(&File, "test.txt", "r");
    if (err1 != 0) {
        cout << "Error opening the file!" << endl;
        return;
    }
    errno_t err2 = fopen_s(&output, "output.txt", "w");
    if (err2 != 0) {
        cout << "Error opening the file!" << endl;
        return;
    }
    errno_t err3 = fopen_s(&newfile, "newfile.txt", "w");
    if (err3 != 0) {
        cout << "Error opening the file!" << endl;
        return;
    }
    char line[300];
    int n = 1;
    while (fgets(line, 300, File) != NULL)
    {
        if (n % 2 != 0)
        {
            char result[300];   // ��� ��������� ���������� ������� �����
            char first_word[300];  //����� �����
            char* word;  //�������� �� ������� �����, ��� ������������.
            char* token;  //�������� �� �������� ����� (�����), ��� �����������
            int i = 0;
            while (line[i] != ' ' && line[i] != '.') {   //��������� ������� ����� ������� ����� 
                first_word[i] = line[i];
                i++;
            }
            first_word[i] = '\0';
            token = strtok(line, " ");  //�������� ����� �� ������ (�����)
            result[0] = '\0';
            while (token != NULL) {
                word = token;
                // ���������� �� ����� ������ ������� ����� ������� �����
                bool contains_last_letter = false;
                for (int j = 0; j < strlen(word); j++) {
                    if (word[j] == first_word[strlen(first_word) - 1]) {
                        contains_last_letter = true;
                        break;
                    }
                }
                if (!contains_last_letter) {
                    strcat(result, word);// ���� ����� ������ ������� ����� ������� ����� - ���� �� �������� �� ����������
                    strcat(result, " ");
                }
                token = strtok(NULL, " ");
            }
            fprintf(newfile, "%s", result);
        }
        if (n % 2 == 0)
        {
            //fprintf(newfile, "\n%s", line);
            char* word = strtok(line, " .");   //�������� ����� �� ������ (�����)
            while (word != NULL) {
                char last_char = word[strlen(word) - 1];  //�������� ������� ����� ������� �����
                for (int i = strlen(word) - 2; i >= 0; i--) {   //����� ���� ��������� �� ��� �������� ����� � ���� �� �������, ��� ���������� �������
                    if (word[i] == last_char) {
                        word[i] = '.';
                    }
                }
                fprintf(output, "%s ", word);
                word = strtok(NULL, " .");
            }
        }
        n++;
    }
    fclose(File);
    fclose(output);
    fclose(newfile);
    remove("test.txt");
    rename("newfile.txt", "test.txt");
}

void addFilePointer()   //��������� ������ �� �����
{
    FILE* File;
    errno_t err = fopen_s(&File, "test.txt", "a");
    if (err != 0) {
        cout << "Error opening file!" << endl;
        return;
    }
    char line[300];
    char exit[] = "EXIT";
    cout << "Enter the text, if you want to finish recording, enter EXIT" << endl;
    cin.ignore();
    while (true)//����� � ���� ������ �� ������ ���� ���������� �� ����� "EXIT"
    {
        cin.getline(line, 300);
        if (strcmp(line, exit) == 0) {
            break;
        }
        fprintf(File, "%s\n", line);
    }
    fclose(File);
    char filename[] = "test.txt";
    cout << "\nThe contents of the changed file" << endl;
    printFilePointer(filename);
    char c;
    cout << "Do you want to change the file according to the task? Y/N >>";
    cin >> c;
    if (c == 'y' || c == 'Y')
    {
        char filename[] = "test.txt";
        char outputName[] = "output.txt";
        cout << "\nThe contents of the source file:" << endl;
        printFilePointer(filename);
        changeFilePointer();
        cout << "The contents of the modified source file:" << endl;
        printFilePointer(filename);
        cout << "The contents of the new file" << endl;
        printFilePointer(outputName);
    }
}

void addFileStream()
{
    int n_line;
    string line;
    ofstream ioFile;
    ioFile.open("test.txt", ios::app);
    if (!ioFile) {
        cout << "Error opening the file!\n";
        return;
    }
    cout << "Enter the text, if you want to finish recording, enter EXIT" << endl;
    cin.ignore();
    while (true)//����� � ���� ������ �� ������ ���� ���������� �� ����� "EXIT"
    {
        getline(cin, line);
        if (line == "EXIT") {
            break;
        }
        ioFile << line << endl;
    }
    ioFile.close();
    string filename = "test.txt";
    cout << "\nThe contents of the changed file" << endl;
    printFileStream(filename);
    char c;
    cout << "Do you want to change the file according to the task? Y/N >>";
    cin >> c;
    if (c == 'y' || c == 'Y')
    {
        string filename = "test.txt";
        string newfilename = "output.txt";
        cout << "\nThe contents of the source file:" << endl;
        printFileStream(filename);
        changeFileStream();
        cout << "The contents of the modified source file:" << endl;
        printFileStream(filename);
        cout << "The contents of the new file:" << endl;
        printFileStream(newfilename);
    }
}

void meny()
{
    cout << "---------WORKING WITH FILES----------" << endl;
    cout << "The program changes the lines of the file.\n" << endl;
    cout << "In odd lines, it sees words that contain the last letter of the first word of this line." << endl;
    cout << "And in even lines processes each word, and replaces all previous occurrences \nof the last letter of the word with '.' and writes the changed line to a new file.\n" << endl;
}

