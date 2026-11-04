struct Loop_001EFB00 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};

extern "C" void func_001E6B30(void* p);
extern "C" int func_001ED6B8(void* p, int a, int b);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int required);

struct Script_001EFB00 {
    char pad[0x10];
    int m10;
    void* m14;
    int m18;
    Loop_001EFB00* m1C;
    char pad2[0x34 - 0x20];
    Loop_001EFB00* m34;
    void Next();
};

void Script_001EFB00::Next()
{
    if (m1C->mC) {
        m10++;
        func_001E6B30(m14);
        m1C->m4 = func_001ED6B8(m14, m10, m18);
        m1C->m8 = func_001E7DE8(m14, 0, &m1C->m10, 0);
        m1C->mC = 0;
    }
    if (!m1C->m8) {
        m10 = m1C->m0;
        return;
    }
    m1C->m10--;
    if (m1C->m10) {
        m10 = m1C->m0;
        return;
    }
    m10 = m1C->m4;
    if (m1C == m34) {
        m1C = 0;
    } else {
        m1C = m1C - 1;
    }
}
