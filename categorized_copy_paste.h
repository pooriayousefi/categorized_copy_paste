
#pragma once
#include <filesystem>
#include <algorithm>
#include <cwctype>
#include <map>
#include <vector>
#include <string>

namespace
{
	// a copy/paste function which categorizes file types at the destination folder
	auto categorized_copy_paste(const std::wstring& from, const std::wstring& to)->void
	{
		std::filesystem::path from_path(from), to_path(to);

		std::map<std::wstring, std::vector<std::filesystem::path> > sieve{};
		for (auto& entry : std::filesystem::directory_iterator(from_path))
			sieve[entry.path().extension().wstring()].emplace_back(entry.path());
		for (auto& kv : sieve)
		{
			std::wstring categorized_folder_name{ to };
			categorized_folder_name += L"\\";
			categorized_folder_name += kv.first;
			std::filesystem::path categorized_folder_path(categorized_folder_name);
			std::filesystem::create_directory(categorized_folder_path);
			for (auto& file_paths : kv.second)
			{
				if (!std::filesystem::is_directory(file_paths))
				{
					std::filesystem::copy(file_paths,
						categorized_folder_path,
						std::filesystem::copy_options{ std::filesystem::copy_options::overwrite_existing });
				}
			}
		}
	}
}
