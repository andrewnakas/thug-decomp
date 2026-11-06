extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);

struct Buf_001086A8 {
    int m0;
    int m4;
    void* m8;
};

struct Mgr_001086A8 {
    char pad0[0x10];
    Buf_001086A8* m10;
    int m14;
    void FreeBuffer(int dec);
};

void Mgr_001086A8::FreeBuffer(int dec)
{
    if (m10->m8) func_0010A8D8(D_00388A70, m10->m8);
    m10->m8 = 0;
    if (dec) m14--;
}
