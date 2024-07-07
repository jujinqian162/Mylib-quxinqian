#pragma once
#include <coroutine>
#include <thread>

namespace co
{

	std::future<void> sleep(long long int miliseconds);


	template<typename Rep, typename Period>
	std::future<void> sleep(const std::chrono::duration<Rep, Period>& __rtime){
		return std::async([&]{
			std::this_thread::sleep_for(__rtime);
		});
	}
} // namespace co

namespace impl
{
	


template<typename Derived,typename T>
struct _Result {
	template<typename U>
	void return_value(U&& value) noexcept {
		static_cast<Derived*>(this)->set_value(std::forward<U>(value));
	}
};
template<typename Derived>
struct _Result<Derived, void> {
	void return_void() noexcept {}
};
template<class T>
struct promise_ : std::promise<T> , _Result<promise_<T>, T>
{
	std::future<T> get_return_object() { return this->get_future(); }
	auto initial_suspend() { return std::suspend_never{}; }
	auto final_suspend() noexcept { return std::suspend_never{}; }
	void unhandled_exception() { this->set_exception(std::current_exception()); }

	template<typename U>
	struct Awaiter {
		bool await_ready() {
			
			return fut_.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
		}
		void await_suspend(std::coroutine_handle<> handle) {
			std::thread(
				[=, this]() {
					fut_.wait();
					handle.resume();
				}
			).detach();
		}
		decltype(auto) await_resume() { return fut_.get(); }
		std::future<U> fut_;
	};
	template<typename U>
	Awaiter<U> await_transform(std::future<U>&& fut) {
		return { std::move(fut) };
	}
};





} // namespace impl

template<class T, class ...Args>
struct std::coroutine_traits<std::future<T>, Args... >
{
	using promise_type = impl::promise_<T>;
};