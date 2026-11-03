extern "C" int func_001E8398(void* params, unsigned int id, int* out, int req);
extern "C" bool func_001E8708(void* s, unsigned int id);
extern "C" void func_001E6AC8(void* list, void* o);

struct Script_0011FE98 {
    char pad[0x18];
    void* m18;
};

struct C_0011FE98 {
    bool CallMember(unsigned int id, void* params, Script_0011FE98* script);
};

extern "C" void func_0011F6D8(C_0011FE98* o, int a);
extern "C" void func_0011F6F8(C_0011FE98* o, int a, int b, void* params);
extern "C" void* func_0011FE68(C_0011FE98* o, int a);
extern "C" void func_0011F860(C_0011FE98* o, int a, int b);
extern "C" void* func_0011FE18(C_0011FE98* o, int a);
extern "C" bool func_001842E0(C_0011FE98* o, unsigned int id, void* params, Script_0011FE98* script);

bool C_0011FE98::CallMember(unsigned int id, void* params, Script_0011FE98* script)
{
    switch (id) {
    case 0x0A23400C: {
        int a;
        func_001E8398(params, 0xB6F08F39, &a, 1);
        func_0011F6D8(this, a);
        return true;
    }
    case 0x83339D0B: {
        int a;
        int b;
        func_001E8398(params, 0xB6F08F39, &a, 1);
        func_001E8398(params, 0x4BB2084E, &b, 1);
        func_0011F6F8(this, a, b, params);
        return true;
    }
    case 0x10A225D6: {
        int a;
        func_001E8398(params, 0xB6F08F39, &a, 1);
        void* v = func_0011FE68(this, a);
        if (!v)
            goto fail;
        func_001E6AC8(script->m18, v);
        return true;
    }
    case 0xD27427FF: {
        int a;
        int b;
        func_001E8398(params, 0xA40ABAA7, &a, 1);
        func_001E8398(params, 0xE288A7CB, &b, 1);
        func_0011F860(this, a, b);
        return true;
    }
    case 0xB13906B0: {
        int a;
        func_001E8398(params, 0xB6F08F39, &a, 1);
        return func_0011FE18(this, a) != 0;
    }
    case 0xE961BAFA: {
        int a;
        int b;
        func_001E8398(params, 0xB6F08F39, &a, 1);
        func_001E8398(params, 0x2E0B1465, &b, 1);
        void* v = func_0011FE18(this, a);
        if (v)
            return func_001E8708(v, b);
    }
    fail:
        return false;
    default:
        return func_001842E0(this, id, params, script);
    }
}
