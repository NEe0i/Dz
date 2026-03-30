#include <iostream>
#include <vector>
#include <string>
#include <format>
#include <chrono>
#include <string_view>

enum class LogLevel { Debug, Info, Warning, Error };

struct LogMessage {
    LogLevel level;
    std::string text;
};


template <>
struct std::formatter<LogLevel> : std::formatter<std::string_view> {
    auto format(LogLevel level, format_context& ctx) const {
        std::string_view name = "UNKNOWN";
        switch (level) {
            case LogLevel::Debug:   name = "DEBUG";   break;
            case LogLevel::Info:    name = "INFO";    break;
            case LogLevel::Warning: name = "WARNING"; break;
            case LogLevel::Error:   name = "ERROR";   break;
        }

        return std::formatter<std::string_view>::format(std::format("{:<7}", name), ctx);
    }
};


template <>
struct std::formatter<LogMessage> {
    constexpr auto parse(format_parse_context& ctx) { return ctx.begin(); }
    auto format(const LogMessage& msg, format_context& ctx) const {
        auto now = std::chrono::system_clock::now();

        return std::format_to(ctx.out(), "[{:%Y-%m-%d %H:%M:%S}] [{}] {}", 
                              now, msg.level, msg.text);
    }
};

int main() {

    std::vector<LogMessage> logs = {
        {LogLevel::Info,    "Система запущена."},
        {LogLevel::Debug,   "Подключение к БД установлено."},
        {LogLevel::Warning, "Низкий уровень дискового пространства."},
        {LogLevel::Error,   "Критическая ошибка доступа!"}
    };

    for (const auto& log : logs) {
        std::cout << std::format("{}\n", log);
    }

    return 0;
}
