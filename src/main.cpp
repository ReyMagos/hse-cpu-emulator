#include <iostream>

import Stack;

int main() {
    Parser parser;

    parser.register_all(
        CommandHandler<PushCommand>("PUSH", Value),
        CommandHandler<PopCommand>("POP"),
        CommandHandler<PushRCommand>("PUSHR", Register),
        CommandHandler<PopRCommand>("POPR", Register),
        CommandHandler<AddCommand>("ADD"),
        CommandHandler<SubCommand>("SUB"),
        CommandHandler<MulCommand>("MUL"),
        CommandHandler<DivCommand>("DIV"),
        CommandHandler<OutCommand>("OUT"),
        CommandHandler<InCommand>("IN"),
        CommandHandler<JumpEqualCommand>("JEQ", Label),
        CommandHandler<JumpNotEqualCommand>("JNE", Label),
        CommandHandler<JumpGreaterCommand>("JA", Label),
        CommandHandler<JumpGreaterOrEqualCommand>("JAE", Label),
        CommandHandler<JumpLessCommand>("JB", Label),
        CommandHandler<JumpLessOrEqualCommand>("JBE", Label),
        MarkerHandler<LabelMarker>(':')
    );


    return 0;
}
