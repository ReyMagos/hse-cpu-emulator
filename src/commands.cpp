class AbstractCommand {
public:
    virtual void exec(ProgramContext &ctx) {}
}

class PushCommand: public AbstractCommand {
    uint32_t value0;

public:
    PushCommand(uint32_t value0): value0(value0) {}

    void exec(ProgramContext &ctx) {
        ctx.stack.push(value0);
    }
};

class PopCommand: public AbstractCommand {
    void exec(ProgramContext &ctx) {
        ctx.stack.pop();
    }
};

class PushRCommand: public PushCommand {
    std::string reg0;

public:
    PushRCommand(std::string reg0): reg0(reg0) {}

    void exec(ProgramContext &ctx) {
        PushCommand::exec(ctx, get(reg0));
    }
};

class PopRCommand: public PopCommand {
    std::string reg0;

public:
    PopRCommand(std::string reg0): reg0(reg0) {}

    void exec(ProgramContext &ctx) {
        // write to reg0
        PopCommand::exec(ctx);
    }
};

class AddCommand: public AbstractCommand {
    void exec(ProgramContext &ctx) {
        uint32_t a = ctx.stack.pop();
        uint32_t b = ctx.stack.pop();
        ctx.stack.push(a + b);
    }
};

class SubCommand: public AbstractCommand {
    void exec(ProgramContext &ctx) {
        uint32_t a = ctx.stack.pop();
        uint32_t b = ctx.stack.pop();
        ctx.stack.push(a - b);
    }
};

class MulCommand: public AbstractCommand {
    void exec(ProgramContext &ctx) {
        uint32_t a = ctx.stack.pop();
        uint32_t b = ctx.stack.pop();
        ctx.stack.push(a * b);
    }
};

class DivCommand: public AbstractCommand {
    void exec(ProgramContext &ctx) {
        uint32_t a = ctx.stack.pop();
        uint32_t b = ctx.stack.pop();
        ctx.stack.push(a / b);
    }
};

class OutCommand: public AbstractCommand {
    void exec(ProgramContext &ctx) {

    }
};

class InCommand: public AbstractCommand {
    void exec(ProgramContext &ctx) {

    }
};
