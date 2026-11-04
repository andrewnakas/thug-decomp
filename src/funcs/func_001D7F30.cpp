/* sym: _$_13Elem_001D7F30 = 0x001D7720 */
extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);

struct Elem_001D7F30 {
    int m0;
    int m4;
    ~Elem_001D7F30();
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

extern "C" void* func_001D79C0(Elem_001D7F30* e);

struct Self_001D7F30 {
    char pad0[0x34];
    Elem_001D7F30* m34;

    bool Free();
};

bool Self_001D7F30::Free()
{
    if (!m34)
        return false;
    void* p = func_001D79C0(m34);
    if (p)
        func_0010A8D8(D_00388A70, p);
    delete[] m34;
    m34 = 0;
    return true;
}
