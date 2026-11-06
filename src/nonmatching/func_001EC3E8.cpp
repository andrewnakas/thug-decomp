/* fuzzy: 96.1 */
struct Comp_001EC3E8 {
    char m_0;
    unsigned char m_type;
    char m_pad2[0x8 - 2];
    void* m_8;
};

struct Entry_001EC3E8 {
    char m_0[2];
    unsigned char m_type;
    char m_3[0x8 - 3];
    int m_8;
    void* m_C;
};

extern "C" int func_001EC7A0(unsigned char* p);
extern "C" unsigned char* func_001EC880(unsigned char* p);
extern "C" void* func_001E4FC8(int name);
extern "C" void func_001ED8D0(void* e);
extern "C" Entry_001EC3E8* func_001E5188(int name);
extern "C" int func_00105520(char* s);
extern "C" void* func_001E8CD0(int size);
extern "C" Comp_001EC3E8* func_001E4ED8(void* mem);
extern "C" unsigned char* func_001ED1C0(unsigned char* p, int a, Comp_001EC3E8* c);
extern "C" unsigned char* func_001ECE50(unsigned char* p, int a, Comp_001EC3E8* c);
extern "C" void func_001E8D20(Comp_001EC3E8* c);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" unsigned char* func_001EC088(void* s, unsigned char* p, int a);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* mem);
extern "C" unsigned char* func_001EB450(void* s, unsigned char* p, int a);

extern "C" unsigned char* func_001EC3E8(unsigned char* p, char* file)
{
    p++;
    int name = func_001EC7A0(p);
    p = func_001EC880(p + 4);
    p = func_001EC880(p + 1);
    void* old = func_001E4FC8(name);
    if (old) {
        func_001ED8D0(old);
    }
    Entry_001EC3E8* e = func_001E5188(name);
    e->m_8 = func_00105520(file);
    Comp_001EC3E8* c;
    switch (*p) {
    case 14:
        c = func_001E4ED8(func_001E8CD0(0x10));
        p = func_001ED1C0(p, 0, c);
        goto done;
    case 22:
    case 23:
    case 26:
    case 27:
    case 28:
    case 30:
    case 31:
        c = func_001E4ED8(func_001E8CD0(0x10));
        p = func_001ECE50(p, 0, c);
    done:
        e->m_type = c->m_type;
        e->m_C = c->m_8;
        c->m_8 = 0;
        func_001E8D20(c);
        return p;
    case 3:
        e->m_type = 10;
        e->m_C = func_001E6978(func_001190D0(8));
        p = func_001EC088(e->m_C, p, 0);
        break;
    case 5:
        e->m_type = 12;
        e->m_C = func_001E8DD0(func_00122CF8(0x10));
        p = func_001EB450(e->m_C, p, 0);
        break;
    }
    return p;
}
