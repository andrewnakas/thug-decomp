extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* self);
extern "C" int func_001E6A00(void* s, int v);
extern "C" void func_001E6AE8(void* self, int chrg);
extern "C" void func_001EE8C8(void* self, int a, void* s, int b);

struct Info_001EEBA8 {
    int m_0;
    int m_4;
    int m_8;
    int m_C;
};

struct Obj_001EEBA8 {
    char pad0[0x18];
    int m_18;
    char pad1C[0x38 - 0x1C];
    int m_38;
    char pad3C[0x94 - 0x3C];
    Info_001EEBA8* m_94;
    char pad98[0xBC - 0x98];
    int m_BC;
    char padC0[0xC8 - 0xC0];
    int m_C8;
    void Run();
};

void Obj_001EEBA8::Run()
{
    void* s = func_001E6978(func_001190D0(8));
    if (m_38) {
        func_001E6A00(s, m_94->m_4);
        func_001EE8C8(this, m_94->m_0, s, m_94->m_C);
    } else {
        func_001E6A00(s, m_18);
        func_001EE8C8(this, m_C8, s, m_BC);
    }
    if (s) {
        func_001E6AE8(s, 3);
    }
}
