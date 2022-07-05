#include <exception>
#include <functional>
#include <optional>

void Sleep(int) {}

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func,
                                  int retryCount,
                                  int sleepTime,
                                  bool throwLast) {
    for (int i = 0; i < retryCount; ++i) {
        try {
            auto value = func;
            return value;
        } catch (Exception) {
            Sleep(sleepTime);
        }
    }

    try {
        auto value = func;
        return value;
    } catch (Exception) {
        if (throwLast) {
            throw;
        } else {
            return std::optional<Result>();
        }
    }
}