//#include <fstream>
//#include <iostream>
//#include <string>
//using namespace std;
//char **readGrid(const int rows, const int cols);
//bool isThere(string word,char** grid,int rows, int cols, int **output, int totalWords, int &idx);
//string *getWords(int& rows, int& cols, int &totalWords);
//int** searchWords(char **grid, string *list, int totalWords, const int rows, const int cols);
//int calLen(string line);
//
//int calLen(string line){
//    int len=0;
//    for(int i=0; line[i] != '\0'; i++)
//        len++;
//    return len;
//}
//char **readGrid(const int rows, const int cols){
//    char word;
//    ifstream fin;
//    fin.open("/Users/admin/Desktop/Semester 2/ISE/Assignments++/Assignment 2/Assignment 2/Assignment 2/Grid_for_Q2.txt", ios::in);
//    char **arr = new char* [rows];
//    for(int i=0; i<rows; i++)
//        arr[i] = new char [cols];
//    
//    fin>>word;
//    for(int i=0; i<rows; i++){
//        for(int j=0; j<cols; j++){
//            arr[i][j] = word;
//            fin>>word;
//        }
//    }
//    return arr;
//}
//string *getWords(int& rows, int& cols, int &totalWords){
//    string word;
//    ifstream fin;
//    fin.open("/Users/admin/Desktop/Semester 2/ISE/Assignments++/Assignment 2/Assignment 2/Assignment 2/Input_for_Q2.txt", ios::in);
//    fin>>rows;
//    fin>>cols;
//    fin>>totalWords;
//    string *arr = new string[totalWords];
//    
//    fin>>word;
//    for(int i=0; i<totalWords; i++){
//        arr[i] = word;
//        fin>>word;
//    }
//    return arr;
//}
//int** searchWords(char **grid, string *list, int totalWords, const int rows, const int cols){
//    int idx=0;
//    int **output = new int*[totalWords + 1];
//    for(int i=0; i<=totalWords; i++)
//        output[i] = new int [5];
//    
//    for(int i=0; i<totalWords; i++){
//        if(!isThere(list[i], grid, rows, cols, output, totalWords, idx)){
//            idx++;
//            output[idx][0] = -1;
//            output[idx][1] = -1;
//            output[idx][2] = -1;
//            output[idx][3] = -1;
//            idx++;
//            cout<<list[i]<<" not found ";
//        }
//    }
//    return output;
//}
//bool isThere(string word,char** grid,int rows, int cols, int **output, int totalWords, int& idx){
//    bool flag = false;
//    int s1 = 0, s2 = 0, l=0; //starting index
//    for(int i=0; i<rows && idx<=totalWords; i++){
//        for(int j=0; j<cols; j++){
//            if(word[0] == grid[i][j]){
//                s1=i; s2=j;
//                l=j;
//                int m=i, k=0;
//                //liner check
//                for(k=0; k<calLen(word); k++, l++){
//                    if(word[k] == grid[i][l])
//                        flag = true;
//                    else{
//                        flag = false;
//                        break;
//                    }
//                }
//                if(flag && k == calLen(word)){
//                    output[idx][0] = s1;
//                    output[idx][1] = s2;
//                    output[idx][2] = m;
//                    output[idx][3] = l;
//                    idx++;
//                    return flag;
//                }
//                //anti-liner check
//                l=j;
//                m=i;
//                for(k=0; k<calLen(word); k++, l--){
//                    if(char(word[k]) == grid[m][l])
//                        flag = true;
//                    else{
//                        flag = false;
//                        break;
//                    }
//                }
//                if(flag && k == calLen(word)){
//                    output[idx][0] = s1;
//                    output[idx][1] = s2;
//                    output[idx][2] = m;
//                    output[idx][3] = l;
//                    idx++;
//                    return flag;
//                }
////                //vertical check
//                l=i;
//                m=j;
//                for(k=0; k<calLen(word) && l<rows; k++, l++){
//                    if(word[k] == grid[l][m]){
//                        flag = true;
//                    }
//                    else{
//                        flag = false;
//                        break;
//                    }
//                }
//                if(flag && k == calLen(word)){
//                    output[idx][0] = s1;
//                    output[idx][1] = s2;
//                    output[idx][2] = l;
//                    output[idx][3] = m;
//                    idx++;
//                    return flag;
//                }
////                //anti-vertical check
//                l=i;
//                m=j;
//                for(k=0; k<calLen(word) && l>0; k++, l--){
//                    if(word[k] == grid[l][m])
//                        flag = true;
//                    else{
//                        flag = false;
//                        break;
//                    }
//                }
//                if(flag && k == calLen(word)){
//                    output[idx][0] = s1;
//                    output[idx][1] = s2;
//                    output[idx][2] = l;
//                    output[idx][3] = j;
//                    idx++;
//                    return flag;
//                }
////                //Diagonal check
//                l=j;
//                m=i;
//                for(k=0; k<calLen(word) && l<cols && m<rows; k++, m++, l++){
//                    if(word[k] == grid[m][l])
//                        flag = true;
//                    else{
//                        flag = false;
//                        break;
//                    }
//                }
//                if(flag && k == calLen(word)){
//                    output[idx][0] = s1;
//                    output[idx][1] = s2;
//                    output[idx][2] = m;
//                    output[idx][3] = l;
//                    idx++;
//                    return flag;
//                }
////                //Diagonal Inverted check
//                m=i;
//                l=j;
//                for(k=0; k<calLen(word) && l>0 && m>0; k++, l--, m--){
//                    if(word[k] == grid[m][l])
//                        flag = true;
//                    else{
//                        flag = false;
//                        break;
//                    }
//                }
//                if(flag && k == calLen(word)){
//                    output[idx][0] = s1;
//                    output[idx][1] = s2;
//                    output[idx][2] = m;
//                    output[idx][3] = l;
//                    idx++;
//                    return flag;
//                }
////                //Anti-Diagonal check
//                m=i;
//                l=j;
//                for(k=0; k<calLen(word) && l<cols && m>0; k++, l++, m--){
//                    if(word[k] == grid[m][l])
//                        flag = true;
//                    else{
//                        flag = false;
//                        break;
//                    }
//                }
//                if(flag && k == calLen(word)){
//                    output[idx][0] = s1;
//                    output[idx][1] = s2;
//                    output[idx][2] = m;
//                    output[idx][3] = l;
//                    idx++;
//                    return flag;
//                }
////                //Anti-Diagonal Inverted check
//                m=i;
//                l=j;
//                for(k=0; k<calLen(word) && l>0 && m<rows; k++, l--, m++){
//                    if(word[k] == grid[m][l])
//                        flag = true;
//                    else{
//                        flag = false;
//                        break;
//                    }
//                }
//                if(flag && k == calLen(word)){
//                    output[idx][0] = s1;
//                    output[idx][1] = s2;
//                    output[idx][2] = m;
//                    output[idx][3] = l;
//                    idx++;
//                    return flag;
//                }
//            }
//        }
//    }
//    if(!flag)
//        idx--;
//    return flag;
//}
//
//
//int main(){
//    int rows, cols, totalWords;
//    string *list = getWords(rows, cols, totalWords);
//    char **grid = readGrid(rows, cols);
//    int **output = searchWords(grid, list, totalWords, rows, cols);
//    
//    ofstream fout;
//    fout.open("/Users/admin/Desktop/Semester 2/ISE/Assignments++/Assignment 2/Assignment 2/Assignment 2/Output_for_Q2.txt", ios::out);
//    for(int i=0; i<totalWords; i++){
//        for(int j=0; j<4; j+=2){
//            if(output[i][0] == -1){
//                fout<<"Not Found ";
//                j=4;
//            }
//            else
//                fout<<"{"<<output[i][j]<<","<<output[i][j+1]<<"} ";
//        }
//        fout<<endl;
//    }
//    fout.close();
//    
//    return 0;
//}
