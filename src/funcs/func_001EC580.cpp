struct Entry_001EC580 {
    char m_0[2];
    unsigned char m_type;
    char m_3[0xC - 3];
    void* m_C;
};

extern "C" unsigned char* func_001EDAD8(unsigned char* p);
extern "C" int func_001EC7A0(unsigned char* p);
extern "C" Entry_001EC580* func_001E5040(int name);
extern "C" void func_001EC7F8(unsigned char* p, void* fn);

extern "C" void func_001EC580(unsigned char* p)
{
    p = func_001EDAD8(p);
    while (*p != 0x24) {
        switch (*p) {
        case 0x25:
            p++;
            continue;
        case 0x16: {
            p++;
            int name = func_001EC7A0(p);
            p += 4;
            Entry_001EC580* e = func_001E5040(name);
            if (e) {
                if (e->m_type == 8) {
                    p[-5] = 0x43;
                    func_001EC7F8(p - 4, e->m_C);
                } else if (e->m_type == 9) {
                    p[-5] = 0x44;
                }
            }
            break;
        }
        }
        p = func_001EDAD8(p);
    }
}
