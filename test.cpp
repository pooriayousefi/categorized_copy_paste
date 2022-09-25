
#include "categorized_copy_paste.h"
#include <iostream>
#include <stdexcept>

auto main()->int
{
	try
	{
		std::wstring from{}, to{};

		std::wcout << L"\n\nfrom: "; std::wcin >> from;
		std::wcout << L"\n\nto: "; std::wcin >> to;

		categorized_copy_paste(from, to);

		return EXIT_SUCCESS;
	}
	catch (const std::exception & xxx)
	{
		std::cerr << xxx.what() << std::endl;
		return EXIT_FAILURE;
	}
}
