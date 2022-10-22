#include "Matrix.hpp"
#include <conio.h>

bool is_exists(const std::string& name) 
{
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

unsigned long str_to_ulong(const std::string& str)
{
	try
	{
		unsigned long i{ std::stoul(str) };
		return i;
	}
	catch (std::invalid_argument const& ex)
	{
		std::cout << "INVALID TYPE: " << std::string(str) << '\n'
			<< "    Value must be unsigned integer\n\n"
			<< ex.what() << '\n';
	}
	catch (std::out_of_range const& ex)
	{
		std::cout << "OUT OF RANGE: N = " << std::string(str) << "\n\n"
			<< ex.what() << '\n';
	}
	system("pause > nul");
	_exit(EXIT_FAILURE);
}

int main(int argc, char** argv)
{
	system("title Parallel Programming [Lab ¹2]");

	if (argc > 7 || (argc == 2 && std::string(argv[1]) == "-help"))
	{
		std::cout	<< "Locate paths to matrix files in arguments, to output file (optional) and specify number of threads (optional)\n"
					<< "Use [-o] before <output_path> and [-t] before <threads>\n\n"
					<< "EXAMPLE:\n"
					<< "    .../PP_2.exe <matrix_1_path> <matrix_2_path> -o <output_path> -t <threads>\n\n";
		system("pause > nul");
        _exit(EXIT_FAILURE);
	}

	std::string str[3];
	unsigned long threads = 10;
	try
	{
		if (argc > 1)
		{
			if (!is_exists(argv[1]))
				throw std::invalid_argument(std::to_string(1) + "]: " + argv[1] + " (File doesn't exist)");
			str[0] = argv[1];

			if (!is_exists(argv[2]))
				throw std::invalid_argument(std::to_string(2) + "]: " + argv[2] + " (File doesn't exist)");
			str[1] = argv[2];
		}
		else
		{
			std::cout << "Locate path to matrix A: ";
			std::cin >> str[0];
			std::cout << "Locate path to matrix B: ";
			std::cin >> str[1];
		}

		if (argc >= 5 && (std::string(argv[3]) != "-o" && std::string(argv[3]) != "-t"))
			throw std::invalid_argument("INVALID MODE: " + std::string(argv[3]));

		if (argc == 7 && (std::string(argv[5]) != "-o" && std::string(argv[5]) != "-t"))
			throw std::invalid_argument("INVALID MODE: " + std::string(argv[5]));

		if ((argc >= 5 && std::string(argv[3]) == "-o") || (argc == 7 && std::string(argv[5]) == "-o"))
			str[2] = (std::string(argv[3]) == "-o" ? argv[4] : argv[6]);
		else
		{
			std::cout << "\nLocate path to output file? (Y/N)";
			int key;
			do
			{
				key = _getch();
				key = toupper(key);
			} while (key != 'Y' && key != 'N');
			std::cout << "\r                                       \r";
			if (key == 'Y')
			{
				std::cout << "Locate path to output file: ";
				std::cin >> str[2];
			}
			else
				str[2] = "output.txt";
		}

		if ((argc >= 5 && std::string(argv[3]) == "-t") || (argc == 7 && std::string(argv[5]) == "-t"))
			threads = str_to_ulong(std::string(argv[3]) == "-t" ? argv[4] : argv[6]);
		else
		{
			std::cout << "\nSpecify threads number? (Y/N)";
			int key;
			do
			{
				key = _getch();
				key = toupper(key);
			} while (key != 'Y' && key != 'N');
			std::cout << "\r                                       \r";
			if (key == 'Y')
			{
				std::cout << "Specify threads number: ";
				std::cin >> threads;
			}
		}
		if (threads < 2)
			throw std::out_of_range("OUT OF RANGE: threads = " + std::to_string(threads));
	}
	catch (std::invalid_argument const& ex)
	{
		std::cout << std::string("INVALID ARGUMENT [") << ex.what() << '\n'
			<< "Use [.../PP_2.exe -help] to get more info\n";
		system("pause > nul");
		_exit(EXIT_FAILURE);
	}
	catch (std::out_of_range const& ex)
	{
		std::cout	<< ex.what() << "\n\n"
					<< "Threads must be > 2\n\n";
		system("pause > nul");
		exit(EXIT_FAILURE);
	}

	Matrix<unsigned long> a, b, c;

	std::cout << "Reading matrix A";
	read_file(a, str[0]);

	std::cout << "\rReading matrix B";
	read_file(b, str[1]);

	std::cout << "\rPerforming C = A * B";
	double runtime = multiply_matrix(a, b, c, threads);
	
	std::cout << "\rWriting matrix C to file [" << str[2] << "]";
	write_file(c, runtime, str[2]);
	std::cout << "\r                                ";
	for (size_t i = str[2].size(); i > 0; i--)
		std::cout << ' ';
	
	std::cout << "\rSaved matrix in file [" << str[2] << "]\n";
	system("pause > nul");
	return 0;
}