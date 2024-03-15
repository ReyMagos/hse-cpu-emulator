#include <iostream>

import Stack;

int main() {
    Parser parser;

    parser.register_all(
            CommandHandler<PushCommand>("PUSH"),
            CommandHandler<PopCommand>("POP"),
            CommandHandler<PushRCommand>("PUSHR"),
            CommandHandler<PopRCommand>("POPR"),
            CommandHandler<AddCommand>("ADD"),
            CommandHandler<SubCommand>("SUB"),
            CommandHandler<MulCommand>("MUL"),
            CommandHandler<DivCommand>("DIV"),
            CommandHandler<OutCommand>("OUT"),
            CommandHandler<InCommand>("IN")
    );


    return 0;
}
