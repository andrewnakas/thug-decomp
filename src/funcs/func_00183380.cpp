extern "C" void func_00107D80(void* p);

struct Entry183380 {
    int m0;
    int m4;
    void* m8;
    char m_padC[0x94 - 0xC];
};

extern "C" void func_00183380(Entry183380* e, int i)
{
    if (e[i].m8) {
        func_00107D80(e[i].m8);
    }
}
