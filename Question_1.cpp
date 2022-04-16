//#include <iostream>
//#include <cstring>
//#include <fstream>
//using namespace std;
//int lines = 1;
//int calLen(string line);
//void set1dArr(string arr[], int size);
//void set2dArr(char **arr, int rows, int cols);
//void printIt(char **arr, int rows, int cols);
//void printIt(string arr[], int size);
//void fillEmpty(char **arr, int rows);
//bool diagonalSimple(char **arr, int rows, string word);
//bool diagonalInverted(char **arr, int rows, string word);
//bool antiDiagonalSimple(char **arr, int rows, string word);
//bool antiDiagonalInverted(char **arr, int rows, string word);
//bool upToDown(char **arr, int rows, string word);
//bool downToUp(char **arr, int rows, string word);
//bool leftToRight(char **arr, int rows, string word, int &index);
//bool rightToLeft(char **arr, int rows, string word);
//void putInFile(char **arr, int rows, string word);
//
//
//int calLen(string line){
//    int len=0;
//    for(int i=0; line[i] != '\0'; i++)
//        len++;
//    return len;
//}
//void set1dArr(string arr[], int size){
//    ifstream fin;
//    string word;
//    int i=0;
//    fin.open("/Users/admin/Desktop/Semester 2/ISE/Assignments++/Assignment 2/Assignment 2/Assignment 2/input.txt", ios::in);
//    fin>>word;
//    while(!fin.eof()){
//        fin>>word;
//        arr[i] = word;
//        i++;
//    }
//}
//void set2dArr(char **arr, int rows, int cols){
//    for(int i=0; i<rows; i++)
//        arr[i] = new char[rows];
//    for(int i=0; i<rows; i++){
//        for(int j=0; j<cols; j++)
//            arr[i][j] = '-';
//    }
//}
//void printIt(char **arr, int rows, int cols){
//    for(int i=0; i<rows; i++){
//        for(int j=0; j<cols; j++)
//            cout<<arr[i][j]<<" ";
//        cout<<endl;
//    }
//}
//void printIt(string arr[], int size){
//    for(int j=0; j<size-1; j++)
//        cout<<arr[j]<<endl;
//}
//void fillEmpty(char **arr, int rows){
//    int mode = 0;
//    char random;
//    for(int i=0; i<rows; i++){
//        for(int j=0; j<rows; j++){
//            if(arr[i][j] == '-'){
//                mode = rand() % 26;
//                random = 'A' + mode;
//                arr[i][j] = random;
//            }
//        }
//    }
//}
//
//bool diagonalSimple(char **arr, int rows, string word){
//    for(int i=0, j=0; i<calLen(word); i++, j++)
//        arr[i][j] = word[i];
//    return true;
//}
//bool diagonalInverted(char **arr, int rows, string word){
//    for(int i=0, j=0; i<calLen(word); i++, j++)
//        arr[rows-i-2][rows-j-1] = word[i];
//    return true;
//}
//bool antiDiagonalSimple(char **arr, int rows, string word){
//    for(int i=0, j=rows-1; i<calLen(word); i++, j--)
//        arr[i][j] = word[i];
//    return true;
//}
//bool antiDiagonalInverted(char **arr, int rows, string word){
//    for(int i=0, j=0; i<calLen(word); i++, j++)
//        arr[rows-i-1][j] = word[i];
//    return true;
//}
//bool upToDown(char **arr, int rows, string word){
//    for(int i=0; i<calLen(word); i++)
//        arr[rows-2-i][0] = word[calLen(word)-i-1];
//    return true;
//}
//bool downToUp(char **arr, int rows, string word){
//    for(int i=0; i<calLen(word); i++)
//        arr[rows-3-i][rows-1] = word[i];
//    return true;
//}
//bool rightToLeft(char **arr, int rows, string word){
//    for(int i=0; i<calLen(word); i++)
//        arr[rows-1][rows-i-2] = word[i];
//    return true;
//}
//bool leftToRight(char **arr, int rows, string word, int &index){
//    int idx = 0;
//    if(lines % 2 != 0){
//        for(int i=lines+0; idx<calLen(word) && i<rows; i++){
//            for(int j=lines+1; idx<calLen(word) && j<rows; j++){
//                if(arr[i][j] == '-'){
//                    arr[i][j] = word[idx];
//                    idx++;
//                }
//            }
//        }
//    }
//    else{
//        for(int i=rows-lines-1; idx<calLen(word);){
//            for(int j=lines+1; idx<calLen(word) && j<rows; j++){
//                if(arr[i][j] == '-'){
//                    arr[i][j] = word[idx];
//                    idx++;
//                }
//            }
//        }
//    }
//    lines++;
//    return true;
//}
//
//void putInFile(char **arr, int rows){
//    ofstream fout;
//    fout.open("/Users/admin/Desktop/Semester 2/ISE/Assignments++/Assignment 2/Assignment 2/Assignment 2/output.txt", ios::out);
//    for(int i=0; i<rows; i++){
//        for(int j=0; j<rows; j++){
//            fout<<arr[i][j];
//        }
//        fout<<endl;
//    }
//    fout.close();
//}
//int main(){
//    string word;
//    int rows=0, size=0;
//    ifstream fin;
//    fin.open("/Users/admin/Desktop/Semester 2/ISE/Assignments++/Assignment 2/Assignment 2/Assignment 2/input.txt", ios::in);
//    fin>>word;
//    rows = calLen(word);
//    while(!fin.eof()){
//        fin>>word;
//        if(rows<calLen(word))
//            rows = calLen(word);
//        size++;
//    }
//    string arr[size];
//    set1dArr(arr, size);
//
//    if(rows<10)
//        rows = 10;
//    else
//        rows += rows;
//    char **outputArr = new char*[rows];
//    set2dArr(outputArr, rows, rows);
//    int idx=0;
//    ///checks to be added here
//    diagonalSimple(outputArr, rows, arr[idx]); idx++;
//    antiDiagonalSimple(outputArr, rows, arr[idx]); idx++;
//    diagonalInverted(outputArr, rows, arr[idx]); idx++;
//    antiDiagonalInverted(outputArr, rows, arr[idx]); idx++;
//    upToDown(outputArr, rows, arr[idx]); idx++;
//    downToUp(outputArr, rows, arr[idx]); idx++;
//    rightToLeft(outputArr, rows, arr[idx]); idx++;
//
//    for(; idx<size-1; idx++)
//        leftToRight(outputArr, rows, arr[idx], idx);
//
//    fillEmpty(outputArr, rows);
//    printIt(outputArr, rows, rows);
//    putInFile(outputArr, rows);
//    return 0;
//}
