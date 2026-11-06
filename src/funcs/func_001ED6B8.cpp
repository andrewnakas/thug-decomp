struct Comp_001ED6B8 {
    char m_0;
    unsigned char m_type;
    char m_pad2[0x4 - 2];
    int m_name;
    void* m_8;
};

struct Struct_001ED6B8;

extern "C" int func_001EC7A0(unsigned char* p);
extern "C" unsigned char* func_001ECA68(unsigned char* p);
extern "C" void* func_001E8CD0(int size);
extern "C" Comp_001ED6B8* func_001E4ED8(void* mem);
extern "C" unsigned char* func_001ED1C0(unsigned char* p, int flags, Comp_001ED6B8* c);
extern "C" void func_001E8D20(Comp_001ED6B8* c);
extern "C" void func_001E6F90(Struct_001ED6B8* s, Comp_001ED6B8* c);
extern "C" void func_001E6AC8(Struct_001ED6B8* s, void* src);
extern "C" void func_001E6250(Comp_001ED6B8* c);
extern "C" unsigned char* func_001EBC48(Struct_001ED6B8* s, int name, unsigned char* p, int flags);
extern "C" unsigned char* func_001EC088(Struct_001ED6B8* s, unsigned char* p, int flags);
extern "C" int func_001EB440(unsigned char* p);
extern "C" void func_001E6A50(Struct_001ED6B8* s, int flags);

extern "C" unsigned char* func_001ED6B8(Struct_001ED6B8* s, unsigned char* p, int flags)
{
    
    while (p = func_001ECA68(p), !func_001EB440(p) && *p != 15) {
        switch (*p) {
        case 22: {
            unsigned char* start = p;
            p++;
            int name = func_001EC7A0(p);
            p = func_001ECA68(p + 4);
            if (*p == 7) {
                p = func_001ECA68(p + 1);
                if (*p == 14) {
                    Comp_001ED6B8* cp = func_001E4ED8(func_001E8CD0(0x10));
                    p = func_001ED1C0(p, flags, cp);
                    if (cp->m_type) {
                        cp->m_name = name;
                        func_001E6F90(s, cp);
                    } else {
                        func_001E8D20(cp);
                    }
                } else {
                    p = func_001EBC48(s, name, p, flags);
                }
            } else {
                p = func_001EBC48(s, 0, start, flags);
            }
            break;
        }
        case 44:
            p++;
            if (flags) {
                func_001E6A50(s, flags);
            }
            break;
        case 3:
            p = func_001EC088(s, p, flags);
            break;
        case 9:
            p++;
            break;
        case 0:
        case 1:
        case 2:
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
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        default:
            if (*p == 14) {
                Comp_001ED6B8* cp = func_001E4ED8(func_001E8CD0(0x10));
                p = func_001ED1C0(p, flags, cp);
                if (cp->m_type == 10) {
                    func_001E6AC8(s, cp->m_8);
                    func_001E6250(cp);
                    func_001E8D20(cp);
                } else if (cp->m_type) {
                    cp->m_name = 0;
                    func_001E6F90(s, cp);
                } else {
                    func_001E8D20(cp);
                }
            } else {
                p = func_001EBC48(s, 0, p, flags);
            }
            break;
        case 45:
            p = func_001EBC48(s, 0, p, flags);
            break;
        }
    }
    return p;
}
