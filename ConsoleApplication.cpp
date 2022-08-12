#include <iostream>
#include <string>

std::string make_array(const std::string& word)
{
	std::string arr_char;
	std::string arr_word = word;

	for (size_t i = 0; i < arr_word.length(); i++)
	{
		char character = arr_word[i];
		static bool count = 0;
		for (size_t l = i + 1; l < arr_word.length();)
		{
			if ((char)tolower(character) == (char)tolower(arr_word[l]))
			{
				if (character == (char)tolower(arr_word[l]) && character != arr_word[l])
				{
					arr_char.push_back(arr_word[l]);
					arr_char.push_back(')');
				}
				else if (character == (char)toupper(arr_word[l]) && character != arr_word[l])
				{
					arr_char.push_back(arr_word[l]);
					arr_char.push_back(')');
				}
				arr_word.erase(arr_word.begin() + l);
				if (count == 0)
				{
					arr_char.push_back(arr_word[i]);
					arr_char.push_back(')');
					arr_word.erase(arr_word.begin() + i);
					i--;
					count = 1;
				}
			}
			else
			{
				l++;
			}

		}
		count = 0;
	}
	for (size_t i = 0; i < arr_word.length(); i++)
	{
		arr_char.push_back(arr_word[i]);
		arr_char.push_back('(');
	}
	return arr_char;
}

std::string duplicate_encoder(const std::string& word) 
{
	std::string result;
	std::string parts_array = make_array(word);
	for (size_t i = 0; i < word.length(); i++)
	{
		for (size_t l = 0; l < parts_array.length(); l+=2)
		{
			if (word[i] == parts_array[l])
			{
				result += parts_array[l + 1];
				break;
			}
		}
	}
	return result;
}

int main()
{
	std::cout << duplicate_encoder("Success");


}