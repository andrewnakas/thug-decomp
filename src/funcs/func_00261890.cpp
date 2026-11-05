struct Comp_00261890 {
    int m0;
    unsigned int m4;
    int m8;
};

extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" Comp_00261890* func_001E6E90(void* params, Comp_00261890* prev);
extern "C" void func_001E7A68(void* s, unsigned int name, int type, int value);
extern "C" void func_001E7A30(void* s, unsigned int name, int type, int value);
extern "C" int func_001E9B08(void* p, void* a, void* b, int c);
extern "C" void func_001E6AE8(void* p, int flags);

struct Obj_00261890 {
    char pad[0x5C];
    char m_params[4];
    int Fn(void* a, void* b);
};

int Obj_00261890::Fn(void* a, void* b)
{
    void* p = func_001E6978(func_001190D0(8));
    Comp_00261890* c = func_001E6E90(m_params, 0);
    while (c) {
        Comp_00261890* next = func_001E6E90(m_params, c);
        switch (c->m4) {
        case 0x7D02BCC3:
        case 0xC15DBF86:
        case 0xA1DC81F9:
            func_001E7A68(p, c->m4, 13, c->m8);
            break;
        case 0x2AB66CB8:
        case 0x2820E997:
        case 0x562E3ECD:
            func_001E7A30(p, c->m4, 3, c->m8);
            break;
        case 0x9B65D7B8:
        case 0x439F4704:
        case 0x3F813177:
        case 0x6DCB497C:
        case 0x9016B4E7:
        case 0xAE798769:
        case 0xAF895B3F:
        case 0xB1FC0722:
        case 0xEDF5DB70:
        case 0xD82F8AC8:
        case 0xF0D90109:
        case 0xF73A13E3:
            func_001E7A68(p, c->m4, 1, c->m8);
            break;
        }
        c = next;
    }
    int r = func_001E9B08(p, a, b, 1);
    if (p) func_001E6AE8(p, 3);
    return r;
}
