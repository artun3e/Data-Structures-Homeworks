#include <iostream>
#include <string>
#include <vector>

using namespace std;

string rotateToLeft(string & word, int amount)
 {
     reverse(word.begin(),word.begin()+amount);
     reverse(word.begin()+amount,word.end());
     reverse(word.begin(), word.end());

     return word;
 }
 
 string rotateToRight(string & word, int amount)
 {
     rotateToLeft(word,word.length()-amount);
     return word; // if we are rotating reverse, just exract amount
 }

string rotateTheString(string originalString, vector<int> direction, vector<int> amount) {
// 0 for left
// 1 for right
    
    for (int i = 0; i < direction.size(); i++)
    {
        if(direction[i] == '0')
           originalString=rotateToLeft(originalString, amount[i]);
        else {
            originalString= rotateToRight(originalString,  amount[i]);
        }
    }

    return originalString;
}

int main()
{
    vector<int> direction;
    direction.push_back(1);
    
    vector<int> amount;
    amount.push_back(2);
    
  cout <<  rotateTheString("geeksforgeeks", direction, amount);
    
    
}
