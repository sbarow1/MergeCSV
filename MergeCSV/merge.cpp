#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "CSVLibrary.h"

int main()
{
	std::string temp;
	std::vector<std::string> inputFiles;
	std::string outputFile;

	std::cout << "What is the first input file?";
	while (std::getline(std::cin, temp) && temp != "q")
	{
		inputFiles.push_back(temp);
		std::cout << "What is the next input file <q to quit>: ";
	}
	
	std::ifstream fin;
	std::cout << "What is the output file?";
	std::getline(std::cin, outputFile);
	std::ofstream fout(outputFile);
	if (!fout.is_open())
	{
		std::cerr << "Could not open the output file";
		exit(EXIT_FAILURE);
	}
	CSVLibrary::CSVRow row;
	int count;
	bool firstFile = true;

	for (auto i : inputFiles)
	{
		fin.open(i.c_str());
		if (!fin.is_open())
		{
			std::cerr << "Could not open " << i << std::endl;
			fin.clear();
			continue;
		}
		count = 0;
		while (fin >> row)
		{
			if (!firstFile)
			{
				if (count != 0)
				{
					fout << row;
				}
			}
			else {
				fout << row;
			}
			count++;
		}
		firstFile = false;
		fin.clear();
		fin.close();
	}
	return 0;
}