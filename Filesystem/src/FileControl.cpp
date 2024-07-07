
#include <string_view>
#include <string>
#include "exception"
#include <vector>
#include <fstream>
#include <cassert>
#include <future>

#include "Coroutine.hpp"
#include "FileControl.h"

//std::string File::FileName::name()
//{
//	std::string point = ".";
//	std::string name = std::string{ file_name } + point + std::string{ file_extension };
//	return name;
//}

std::future<std::string> File::open_file_async(const std::string& path)
{
	return std::async(std::launch::async, [&]()->std::string {
		std::ifstream file(path);
		if (!file.is_open()) {
			throw std::runtime_error("file connot open");
		}
		std::string content((std::istreambuf_iterator<char>(file)),
			std::istreambuf_iterator<char>());
		return content;
		});
}

std::future<void> File::open_file_async(std::ifstream &stream, const std::string &path)
{
	return std::async([&](){
		stream.open(path);
		if (!stream.is_open())
			assert(false);
	}
	);

}

std::string File::get_str_from_ifstream(std::ifstream &stream)
{
	
	std::stringstream buffer;
	buffer << stream.rdbuf();
    return buffer.str();
}

File::FileController::FileController(const std::string& file_name)
{
	file_names_.push_back(file_name);
}

File::FileController::FileController(const char* file)
{
	file_names_.emplace_back(std::string{ file });
}


std::future<void> v(){
	co_await File::open_file_async("d");
}