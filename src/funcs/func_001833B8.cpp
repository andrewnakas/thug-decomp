extern "C" void func_00107E10(void* p);

struct Entry1833B8 {
    int m0;
    int m4;
    void* m8;
    char m_padC[0x94 - 0xC];
};

extern "C" void func_001833B8(Entry1833B8* e, int i)
{
    if (e[i].m8) {
        func_00107E10(e[i].m8);
    }
}
