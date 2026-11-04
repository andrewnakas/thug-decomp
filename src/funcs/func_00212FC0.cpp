struct Script_00212FC0 {
    char m_pad[0x18];
    void* m_params;
};

extern char D_0038F4D0[];
extern void* D_0038E0A0;

extern "C" bool func_001E8A30(void* params, unsigned int name, unsigned int* out, int required);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" float func_001DD618(void* p);
extern "C" float func_001E0180();
extern "C" float func_001E0208();
extern "C" void func_001E7A68(void* params, unsigned int name, int type, int v);

static inline int Scale_00212FC0(float v, int div)
{
    return (int)v / div;
}

bool ScriptCmd_00212FC0(void* params, Script_00212FC0* script)
{
    unsigned int type;
    func_001E8A30(params, 0, &type, 1);
    switch (type) {
    case 0x8D6F6554: {
        void* p = script->m_params;
        void* mgr = D_0038E0A0;
        unsigned int name = func_001F0D78(D_0038F4D0);
        func_001E7A68(p, name, 1, Scale_00212FC0(func_001DD618(mgr), 10));
        break;
    }
    case 0xA5162BD2: {
        void* p = script->m_params;
        unsigned int name = func_001F0D78(D_0038F4D0);
        func_001E7A68(p, name, 1, Scale_00212FC0(func_001E0180(), 10));
        break;
    }
    case 0xE32F3525: {
        void* p = script->m_params;
        unsigned int name = func_001F0D78(D_0038F4D0);
        func_001E7A68(p, name, 1, Scale_00212FC0(func_001E0208(), 10));
        break;
    }
    }
    return true;
}
