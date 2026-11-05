extern "C" unsigned int func_0010FC30();
extern "C" void func_001E72B0(void* params, unsigned int name, float value);
extern "C" void func_00273250(void* self, int on);
extern "C" void func_00273378(void* self);
extern "C" void func_00273568(void* self);

struct Cfg_00272F68 {
    char pad[0x20];
    int m20;
    char pad2[0x180 - 0x24];
    int m180;
};

struct Script_00272F68 {
    char pad[0x18];
    void* m18;
};

struct Obj_00272F68 {
    char pad[0x1C];
    int m1C;
    unsigned int m20;
    unsigned int m24;
    int m28;
    char pad2[0x34 - 0x2C];
    Cfg_00272F68* m34;
    int CallMemberFunction(unsigned int name, void* params, Script_00272F68* script);
};

int Obj_00272F68::CallMemberFunction(unsigned int name, void* params, Script_00272F68* script)
{
    switch (name) {
    case 0x3522D612:
        if (!m1C)
            func_00273250(this, 1);
        break;
    case 0x0595627C:
        if (m1C)
            func_00273250(this, 0);
        break;
    case 0x57BFBAE8:
        return !m34->m180 && m34->m20 == 1;
    case 0xF2813EE5:
        return !m34->m180 && !m34->m20;
    case 0xEE584CBC:
        return m34->m180 != 0;
    case 0xB32E9EAE:
        m34->m180 = 1;
        break;
    case 0x953A7B6D:
        m34->m180 = 0;
        break;
    case 0x9569D5B1: {
        unsigned int start = m20;
        void* out = script->m18;
        func_001E72B0(out, 0x27F48E93, (float)(func_0010FC30() - start) * 0.001f);
        break;
    }
    case 0xA887285A: {
        unsigned int t = m24;
        void* out = script->m18;
        func_001E72B0(out, 0x24D061BA, (float)t * 0.001f);
        break;
    }
    case 0x5C038F9B:
        func_00273378(this);
        break;
    case 0x6E8E39B3:
        func_00273568(this);
        break;
    case 0x9366A509:
        m28 = 1;
        break;
    case 0x04830E80:
        m28 = 0;
        break;
    case 0xD5A9F889:
        return m28 != 0;
    default:
        return 2;
    }
    return 1;
}
