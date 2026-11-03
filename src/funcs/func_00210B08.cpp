extern "C" void func_00210988(char* buf, void* params, void* script);

bool Cmd_00210B08(void* params, void* script)
{
    char buf[1024];
    func_00210988(buf, params, script);
    return true;
}
