extern "C" void func_00210988(char* buf, void* params, void* script);
extern "C" void func_00103F28(char* text);

bool Cmd_00210AD8(void* params, void* script)
{
    char buf[1024];
    func_00210988(buf, params, script);
    func_00103F28(buf);
    return true;
}
