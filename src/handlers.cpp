#include <string>


class AbstractHandler {
    AbstractHandler* next = nullptr;

public:
    AbstractHandler pipe(AbstractHandler* dest) {
        next = dest;
        return *this;
    }

    virtual void handle(ParserContext &ctx) {}

    virtual void complete() {

    }
};

template <typename T>
class CommandHandler: public AbstractHandler {
public:
    void handle(ProgramContext &ctx) {
        ctx.commands.push_back(T(args));
    }
};

class RegisterHandler: public AbstractHandler {
public:
    void handle(ProgramContext &ctx) {

    }
};

class LabelHandler: public AbstractHandler {
public:
    void handle(ParserContext &ctx) {
        if (ctx.labels.find(ctx.token) == ctx.labels.end()) {
            ctx.labels[ctx.token] = ...;
        } else {
            ctx.error_flag = true;
            ctx.error_msg = "Duplicate label found";
        }
    }
};
