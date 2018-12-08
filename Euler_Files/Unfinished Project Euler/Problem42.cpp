THIS IS ALL WRONG

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
	{
	vector <int> triangles(39);
	vector <int> words(0);
	char release;
	ifstream reader ("Problem42_text.txt");
	
	for (int i = 1; i < 40 ; i++)
		{
		triangles[i] = 0.5 * i * (i+1);
		}
	if (!reader)
		{
		cout << "Error opening file\n";
		}
	string currentWord;
	int wordValue = 0;
	for (int i = 0; !reader.eof(); i++)
		{
		reader.getline(reader, currentWord);
		for (int j = 0; j < currentWord.length-1; j++)
			{
			int currentValue = (currentWord.substr(j, 1)).c_str();
			wordValue += currentValue;
			}
		}
		words.push_back(wordValue);
		wordValue = 0;
	
	cin >> release;
	return 0;
	}