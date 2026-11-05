extern "C" void func_00229058();
extern "C" void func_00229088();
extern "C" void func_00229098();
extern "C" bool func_00229068();
extern "C" bool func_002290F0();
extern "C" bool func_00229110();
extern "C" void func_002290A8();
extern "C" void func_002290B8();
extern "C" void func_002290C8();

bool Cmd_00228F68(void* params, void* script)
{
    func_00229058();
    func_00229088();
    func_00229098();
    if (func_00229068() && func_002290F0() && func_00229110()) {
        return true;
    }
    func_002290A8();
    func_002290B8();
    func_002290C8();
    return false;
}
