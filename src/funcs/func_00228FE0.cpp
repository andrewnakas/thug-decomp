extern "C" bool func_00229130();
extern "C" bool func_00229138();
extern "C" bool func_00229140();
extern "C" void func_002290A8();
extern "C" void func_002290B8();
extern "C" void func_002290C8();

bool Cmd_00228FE0(void* params, void* script)
{
    if (func_00229130() || func_00229138() || func_00229140()) {
        func_002290A8();
        func_002290B8();
        func_002290C8();
        return true;
    }
    return true;
}
