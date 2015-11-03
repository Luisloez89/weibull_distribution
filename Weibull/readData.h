#include <fstream>
#include <iostream>

bool readData(char *_fileName, float *_data, int _dataCount = -1)
{
	std::fstream file(_fileName, std::ios_base::in);

	if (!file.good())
	{
		std::cerr << "File not found!";
		file.close();
		return false;
	}

	int k = 0;

	if (_dataCount == -1)
		while (file >> _data[k++]);

	else
		for (int i = 0; i < _dataCount; i++)
			file >> _data[k++];
    return true;
}