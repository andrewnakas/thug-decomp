/* sym: __13Temp_00217210 = 0x001E4ED8 */
struct Comp_00217210 {
    unsigned char m0;
    unsigned char m_type;
    char pad2[2];
    int m_name;
    int m_value;
};

struct Type_00217210 {
    char pad0[2];
    unsigned char m_type;
};

struct Ref_00217210 {
    char pad0[2];
    unsigned char m_type;
    char pad3[0x9];
    int m_value;
};

struct Dest_00217210 {
    char pad0[2];
    unsigned char m_type;
    char pad3[0x9];
    union {
        int i;
        float f;
    } m_value;
};

struct Temp_00217210 {
    unsigned char m0;
    unsigned char m_type;
    char pad2[6];
    union {
        int i;
        float f;
    } m_value;
    Temp_00217210();
    ~Temp_00217210() { m_value.i = 0; }
};

extern "C" Comp_00217210* func_001E6E90(void*, int);
extern "C" Type_00217210* func_001E4FC8(int);
extern "C" void func_001ED8D0(Type_00217210* t);
extern "C" Dest_00217210* func_001E5188(int);
extern "C" bool func_001E8708(void*, unsigned int);
extern "C" Ref_00217210* func_001E5040(int);

bool func_00217210(void* params)
{
    Comp_00217210* c = func_001E6E90(params, 0);
    if (!c)
        return false;
    Type_00217210* t = func_001E4FC8(c->m_name);
    if (!t)
        return false;
    if (t->m_type == 7)
        return false;
    if (t->m_type == 8)
        return false;
    if (t->m_type == 9)
        return false;
    func_001ED8D0(t);
    Dest_00217210* d = func_001E5188(c->m_name);
    Temp_00217210 tmp;
    tmp.m_type = c->m_type;
    tmp.m_value.i = c->m_value;
    if (tmp.m_type == 0xD && func_001E8708(params, 0x991A7BC3)) {
        Ref_00217210* r = func_001E5040(tmp.m_value.i);
        if (r) {
            tmp.m_type = r->m_type;
            tmp.m_value.i = r->m_value;
        }
    }
    unsigned char type = tmp.m_type;
    switch (type) {
    case 2:
        d->m_type = type;
        d->m_value.f = tmp.m_value.f;
        break;
    case 1:
    case 0xD:
        d->m_type = type;
        d->m_value.i = tmp.m_value.i;
        break;
    }
    return true;
}
