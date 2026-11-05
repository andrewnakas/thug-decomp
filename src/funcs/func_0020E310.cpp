extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" void func_001E0390(bool on);

bool Cmd_0020E310(void* params)
{
    func_001E0390(!func_001E8708(params, 0x389129E4));
    return true;
}
