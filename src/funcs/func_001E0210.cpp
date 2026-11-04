struct Entry_001E0210 {
    char m_names[0x50][0x28];
    int m_count;
    char padC84[0xCA8 - 0xC84];
    int mCA8;
    int padCAC;
};

struct Desc_001E0210 {
    char m_text[100];
};

struct Str18_001E0210 {
    char c[18];
};

extern Entry_001E0210 D_003F0898[];
extern Desc_001E0210 D_003EE958[];
extern Str18_001E0210 D_003643D0;

extern "C" int func_001DED20();
extern "C" char* func_00331A9C(char*, char*);
extern "C" unsigned int func_00331BB8(char*);
extern "C" char* func_00332088(char*, char*, int);
extern "C" int func_001E3DF0(char*, int);

void func_001E0210(char* name, int slot, char* desc)
{
    if (func_001DED20())
        return;
    Entry_001E0210* e = &D_003F0898[slot];
    if (slot == 1)
        e->m_count = 0;
    if (e->m_count < 0x50) {
        char* str = e->m_names[e->m_count];
        func_00331A9C(str, name);
        char* p = str;
        for (unsigned int i = 0; i < func_00331BB8(str); i++) {
            if ((unsigned char)(*p - 0x61) < 26)
                *p = *p - 0x20;
            p++;
        }
        if (slot == 0) {
            char* d = D_003EE958[e->m_count].m_text;
            if (desc) {
                func_00332088(d, desc, 100);
                d[99] = 0;
            } else {
                *(Str18_001E0210*)d = D_003643D0;
            }
        }
        if (func_001E3DF0(str, 1)) {
            e->mCA8 = 0;
            e->m_count++;
        }
    }
}
