struct Sub_0029E3E8 {
    char pad[0x18];
    int m18;
    char pad2[0x320 - 0x1C];
    int m320;
};

struct Script_0029E3E8 {
    char pad[0x18];
    void* m18;
};

extern void* D_0038C7B0;
extern "C" float func_00203D40(Sub_0029E3E8* o, unsigned int name);
extern "C" void func_00189750(void* p, unsigned int a, int b, int c, int d, int e);
extern "C" void func_001E72B0(void* s, unsigned int name, float v);
extern "C" void func_001E7360(void* s, unsigned int name, int v);

struct Obj_0029E3E8;
extern "C" void func_0029E630(Obj_0029E3E8* o);

struct Obj_0029E3E8 {
    char pad[0xC];
    Sub_0029E3E8* m0C;
    char pad2[0x1C - 0x10];
    int m1C;
    float m20;
    int Dispatch(unsigned int name, void* params, Script_0029E3E8* script);
};

int Obj_0029E3E8::Dispatch(unsigned int name, void* params, Script_0029E3E8* script)
{
    switch (name) {
    case 0x82445966:
        if (m1C) {
            m1C = 2;
            func_00189750(D_0038C7B0, 0x813CC576, m0C->m320 + 0x83321DEA, m0C->m18, 0, 0);
        }
        break;
    case 0x956236B1:
        func_0029E630(this);
        break;
    case 0xAB04CBF9: {
        void* p = script->m18;
        func_001E72B0(p, 0x41F56511, m20 / func_00203D40(m0C, 0x0B84F532));
        break;
    }
    case 0x96D81D8E:
        func_001E7360(script->m18, 0x39778122, m0C->m320 + 0x83321DEA);
        break;
    case 0x81AAA6DD:
        func_001E7360(script->m18, 0x628F21C9, m0C->m320 + 0x7D42821C);
        break;
    default:
        return 2;
    }
    return 1;
}
