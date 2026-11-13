struct Node_001842E0 {
    unsigned char m0;
    unsigned char m_type;
    char pad2[2];
    void* m4;
    int m_value;
};

struct Script_001842E0 {
    char pad0[0x18];
    void* m18;
};

struct Base_001842E0 {
    int m0;
    int m4;
    virtual void V0();
    virtual void V1(void* params);
};

struct Obj_001842E0 : Base_001842E0 {
    unsigned int m_flags;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    unsigned int m_mask;
    int CallMember(unsigned int name, void* params, Script_001842E0* script);
};

extern char D_0038C4B0[];
extern char D_0038C4B8[];
extern char D_0038C4C0[];
extern "C" void func_001840F8(Obj_001842E0* o, void* params);
extern "C" void func_001841F0(Obj_001842E0* o, void* p);
extern "C" unsigned int func_00184758(Obj_001842E0* o, void* params, Script_001842E0* script);
extern "C" void func_00184950(Obj_001842E0* o);
extern "C" void func_00184AB0(Obj_001842E0* o, int a, int b);
extern "C" void func_00184B30(Obj_001842E0* o, int a, int b, int c, int d);
extern "C" Node_001842E0* func_001E6E90(void* params, Node_001842E0* n);
extern "C" void func_001E73C8(void* s, const char* name, int v);
extern "C" int func_001E81F0(void* params, const char* name, int* out, int req);
extern "C" int func_001E8398(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E84E8(void* params, const char* name, int* out, int req);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" void func_001EEC50(Script_001842E0* script, Obj_001842E0* o);
extern "C" void func_001F0B50(Obj_001842E0* o, int v, Script_001842E0* script);
extern "C" void func_001F0C10(Obj_001842E0* o, int v, Script_001842E0* script);
extern "C" int func_001F0CD0(Script_001842E0* script);

int Obj_001842E0::CallMember(unsigned int name, void* params, Script_001842E0* script)
{
    switch (name) {
    case 0x3611C136:
        func_001841F0(this, script->m18);
        break;
    case 0xA58079EB:
        func_001840F8(this, params);
        break;
    case 0xC6870028:
        func_00184950(this);
        break;
    case 0xB3C262EC:
        func_001EEC50(script, this);
        break;
    case 0x500EB224:
        func_001E73C8(script->m18, D_0038C4B0, m18);
        break;
    case 0x4BABC987: {
        unsigned int old = m_mask;
        unsigned int mask = func_00184758(this, params, script);
        if (!mask) {
            return 0;
        }
        if (func_001E8708(params, 0x1A4E0EF9)) {
            m_mask &= ~mask;
        }
        return (old & mask) != 0;
    }
    case 0x53EBEE03: {
        unsigned int mask = func_00184758(this, params, script);
        if (!mask) {
            return 0;
        }
        return (m_mask & mask) == 0;
    }
    case 0x6C2B67F9: {
        if (func_001E8708(params, 0xC4E78E22)) {
            m_mask = 0;
            break;
        }
        unsigned int mask = func_00184758(this, params, script);
        if (!mask) {
            return 0;
        }
        m_mask &= ~mask;
        break;
    }
    case 0xBE563426: {
        unsigned int mask = func_00184758(this, params, script);
        if (!mask) {
            return 0;
        }
        m_mask |= mask;
        break;
    }
    case 0xFBD89CD5: {
        int a = 0;
        if (func_001E8398(params, 0xA1DC81F9, &a, 0)) {
            func_001F0C10(this, a, script);
            break;
        }
        int b = 0;
        if (func_001E8398(params, 0x40C698AF, &b, 0)) {
            func_001F0B50(this, b, script);
        }
        break;
    }
    case 0x23A4E5C2: {
        Node_001842E0* n = func_001E6E90(params, 0);
        if (n && n->m_type == 0xD) {
            int v = n->m_value;
            // The game stores the 0 first (sw $zero, 0x8($sp) at 0x00184644), then the call's result.
            /* The game stores 0 to a's slot first (`sw $zero, 0x8($sp)` at 0x00184644); a is address-taken. */
            int a = 0;
            a = func_001F0CD0(script);
            func_001E84E8(params, D_0038C4B8, &a, 0);
            int b = 0;
            func_001E81F0(params, D_0038C4C0, &b, 0);
            func_00184B30(this, v, b, a, 0);
        }
        break;
    }
    case 0x714937C7: {
        int a;
        if (func_001E8398(params, 0, &a, 0)) {
            int b = 0;
            func_001E81F0(params, D_0038C4C0, &b, 0);
            func_00184AB0(this, a, b);
        }
        break;
    }
    case 0x6C63C7C5:
        V1(params);
        break;
    case 0x20D125D7:
        m_flags &= ~4;
        break;
    case 0x3578E5A9:
        m_flags |= 4;
        break;
    }
    return 1;
}
