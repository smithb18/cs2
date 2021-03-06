// Ben Smith
// 5/31/2017
// lab10.cpp

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void insertSort(string data[], int size);
void printList(string data[], int size);
void swap(string& a, string& b);
int binarySearch(string data[], string keyWord, int size);

const int MAX_SIZE = 50;
const string DAT = "/home/fac/sreeder/class/cs1430/lab7.dat";

int main()
{
  ifstream inputFile;
  int count = 0;
  string input;
  string searchWord;
  string data;
  string dataArray[MAX_SIZE] ={" "};

  inputFile.open(DAT);

  if(inputFile.fail()){
    cout << "Error opening file..."<<endl;
    return 0;
  }

  while(count < MAX_SIZE && inputFile >> data){
    dataArray[count] = data;
    count++;
  }

  insertSort(dataArray,count);

  cout << endl;

  cout << "Would you like to search for a word [y/n]? ";
  cin >> searchWord;
  while(searchWord == "y"){
    cout << "Enter a word to search for: ";
    cin >> input;
    int index = binarySearch(dataArray,input,count);
    if(index == -1){
      cout << endl;
      cout << input << " not found" << endl;
    }
    else{
      cout << endl;
      cout << input <<" found at index [ " << index <<" ]"<< endl;
    }
    cout << endl;
    cout << "Would you like to search for another word [y/n]? ";
    cin >> searchWord;
  }
  cout << endl;
  cout << "Goodbye..." << endl;

  inputFile.close();
  return 0;
}
int binarySearch(string data[], string keyWord, int size)
{
  int first = 0;
  int mid;
  int last = size-1;
  int index = -1;
  while(first <= last){
    mid = (first + last)/2;
    if(data[mid] < keyWord){
      first = mid + 1;
    }
    else if(data[mid] > keyWord){
      last = mid - 1;
    }
    else{
      index = mid;
      return index;
    }
  }
  return index;
}
void insertSort(string data[], int size)
{
  int index;
  for(int i = 1; i < size; i++){
    index = i;
    while(index > 0 && data[index] < data[index-1]){
      swap(data[index],data[index-1]);
      index--;
    }
  }
}
void swap(string& a, string& b)
{
  string temp = a;
  a = b;
  b = temp;
}
