#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <cctype>


struct ParserContext {
    std::string token;
    std::vector<AbstractCommand> commands;
    std::unordered_map<std::string, unsigned> labels;

    unsigned carry;
    bool error_flag = false;
    std::string error_msg;
};

class Parser {
    std::unordered_map<char, AbstractHandler> markers;
    std::unordered_map<std::string, AbstractHandler> keywords;
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
        unsigned n = 1;
        std::string line;
        while (std::getline(source, line)) {
            parse_line(line);

            if (ctx.error_flag) {
                std::cerr << "Error at line " << n << ":\n"
                          << "\t" << line << "\n"
                          << std::setw(ctx.carry) << "^\n"
                          << ctx.error_msg << endl;
                return;
            }

            n++;
        }

        if (source.bad())
            perror("Parser reading error");

        source.close();
    }

    void parse_line(std::string &line) {
        for (ctx.carry = 0; ctx.carry < line.size(); ++ctx.carry) {
            char c = line[ctx.carry];

            if (std::isalnum(c)) {
                
            } else if (markers.find(c) != markers.end()) {
                markers[c].handle(ctx);
            } else if (c == ' ') {

            } else {
                ctx.error_flag = true;
                ctx.error_msg = "Unexpected symbol";
                return;
            }
        }
    }
};