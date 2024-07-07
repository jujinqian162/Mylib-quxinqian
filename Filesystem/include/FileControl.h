#pragma once
#include <future>
#include <coroutine>
#include "Coroutine.hpp"
namespace File
{
	std::future<std::string> open_file_async(const std::string& path);
	std::future<void> open_file_async(std::ifstream& stream, const std::string& path);
	std::string get_str_from_ifstream(std::ifstream& stream);

	class FileController
	{
	public:
		FileController(const std::string& file_name);
		FileController(const char* file);
		FileController() = default;

		template<typename Func>
		std::future<void> for_all_files(Func f) {
			for (auto& file_name : file_names_) {
				std::string str = co_await File::open_file_async(file_name);
				f(str);
			}
		}

		template<typename T>
		FileController& file(T&& path) {
			file_names_.push_back(std::forward<T>(path));
			return *this;
		}

	private:
		std::vector<std::string> file_names_;
	};
	
}