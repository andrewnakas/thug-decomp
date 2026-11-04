extern "C" int func_001E7200(int a, unsigned int crc, int v);
extern "C" int func_001E8708(void* a, unsigned int crc);
extern "C" int func_0023D5E8(int a);
extern "C" int func_0023D5F0(int a);
extern "C" int func_00240850();

struct Script_002415F8 {
    char pad0[0x18];
    int m_18;
};

bool Cmd_002415F8(void* params, Script_002415F8* script)
{
    int obj = func_00240850();
    int v;
    if (func_001E8708(params, 0x3DD01EA1)) {
        v = func_0023D5F0(obj);
    } else {
        v = func_0023D5E8(obj);
    }
    func_001E7200(script->m_18, 0x42C20492, v);
    return true;
}
