struct Script_002CB988 {
    char pad[0x18];
    void* m18;
};

extern "C" void func_001E7200(void* p, unsigned int name, int v);

int Cmd_002CB988(void* params, Script_002CB988* script)
{
    func_001E7200(script->m18, 0x7DDC0DA8, 5);
    return 1;
}
