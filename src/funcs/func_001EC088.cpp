struct Comp_001EC088 {
    char m_0;
    unsigned char m_type;
    char m_pad2[0x4 - 2];
    int m_name;
    void* m_8;
};

struct Struct_001EC088;

extern "C" int func_001EC7A0(unsigned char* p);
extern "C" unsigned char* func_001EC880(unsigned char* p);
extern "C" unsigned char* func_001ECA68(unsigned char* p);
extern "C" void* func_001E8CD0(int size);
extern "C" Comp_001EC088* func_001E4ED8(void* mem);
extern "C" unsigned char* func_001ED1C0(unsigned char* p, int flags, Comp_001EC088* c);
extern "C" void func_001E8D20(Comp_001EC088* c);
extern "C" void func_001E6F90(Struct_001EC088* s, Comp_001EC088* c);
extern "C" void func_001E6AC8(Struct_001EC088* s, void* src);
extern "C" void func_001E6250(Comp_001EC088* c);
extern "C" unsigned char* func_001EBC48(Struct_001EC088* s, int name, unsigned char* p, int flags);

extern "C" unsigned char* func_001EC088(Struct_001EC088* s, unsigned char* p, int flags)
{
    p++;
    for (;;) {
        p = func_001ECA68(func_001EC880(p));
        if (*p == 4) {
            break;
        }
        switch (*p) {
        case 22: {
            unsigned char* start = p;
            p++;
            int name = func_001EC7A0(p);
            p = func_001ECA68(func_001EC880(p + 4));
            if (*p == 7) {
                p = func_001ECA68(func_001EC880(p + 1));
                if (*p == 14) {
                    Comp_001EC088* c = func_001E4ED8(func_001E8CD0(0x10));
                    p = func_001ED1C0(p, flags, c);
                    if (c->m_type) {
                        c->m_name = name;
                        func_001E6F90(s, c);
                    } else {
                        func_001E8D20(c);
                    }
                } else {
                    p = func_001EBC48(s, name, p, flags);
                }
            } else {
                p = func_001EBC48(s, 0, start, flags);
            }
            break;
        }
        case 3:
            p = func_001EC088(s, p, flags);
            break;
        case 9:
            p++;
            break;
        case 1:
        case 2:
            p = func_001EC880(p);
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        default:
            if (*p == 14) {
                Comp_001EC088* c = func_001E4ED8(func_001E8CD0(0x10));
                p = func_001ED1C0(p, flags, c);
                if (c->m_type == 10) {
                    func_001E6AC8(s, c->m_8);
                    func_001E6250(c);
                    func_001E8D20(c);
                } else if (c->m_type) {
                    c->m_name = 0;
                    func_001E6F90(s, c);
                } else {
                    func_001E8D20(c);
                }
            } else {
                p = func_001EBC48(s, 0, p, flags);
            }
            break;
        }
    }
    return p + 1;
}
