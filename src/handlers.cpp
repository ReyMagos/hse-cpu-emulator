#include <string>


class AbstractHandler {
    AbstractHandler* next = nullptr;

public:
    AbstractHandler pipe(AbstractHandler* dest) {
        next = dest;
        return *this;
    }

    template <typename... Args>
    virtual void handle(ProgramContext &ctx, Args... args) {}

    virtual void complete() {

    }
};

template <typename T>
class CommandHandler: public AbstractHandler {
public:
    template <typename... Args>
    void handle(ProgramContext &ctx, Args... args) {
        ctx.commands.push_back(T(args));
    }
};

class LabelHandler: public AbstractHandler {

};
