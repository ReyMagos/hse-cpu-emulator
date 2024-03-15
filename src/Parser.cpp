#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <cctype>

class AlreadyRegistered: std::exception {
    std::string key;

public:
    const char* what() const noexcept {
        return std::format("Handler with key \"{}\" already registered", key);
    }
};

struct ParserContext {

    std::vector<AbstractCommand> commands;
    std::unordered_map<std::string, int> labels;
};

class Parser {
    std::unordered_map<std::string, AbstractHandler> handlers;
    ParserContext ctx;

public:
    void register_handler(AbstractHandler handler) {
        if (handlers.find(handler.key) != handlers.end())
            throw AlreadyRegistered(key);
        handlers[key] = handler;
    }

    template <typename... Handlers>
    void register_all(Handlers... handlers) {

    }

    void parse(std::ifstream source) {


        if (!sourse.is_open())
            throw std::runtime_error("");

        char c;
        std::string token;
        while ((c = source.get()) != EOF)) {
            if (std::isalnum(c))
                token += c;
            else {

            }
        }

        source.close()
    }
};