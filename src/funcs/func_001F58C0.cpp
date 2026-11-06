struct Pair_001F58C0 {
    long a;
    long b;
};

struct Info_001F58C0 {
    Pair_001F58C0 m0;
    long m10;
    long m18;
};

struct Script_001F58C0 {
    char m_pad0[0x8];
    Pair_001F58C0 m8;
};

extern char* D_0038E320;
extern "C" void func_001F6868(char* p, Info_001F58C0* out);

bool Cmd_001F58C0(void* params, Script_001F58C0* script)
{
    Info_001F58C0 tmp;
    func_001F6868(D_0038E320 + 0x673608, &tmp);
    script->m8 = tmp.m0;
    return true;
}
