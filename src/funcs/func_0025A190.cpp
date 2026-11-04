/* sym: _$_13Elem_0025A190 = 0x00259CF0 */
extern "C" void func_00259F30(void* self);
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct Elem_0025A190 {
    char pad[0x258];
    ~Elem_0025A190();
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Obj_0025A190 {
    Elem_0025A190* m_arr;
    void Free();
};

void Obj_0025A190::Free()
{
    if (m_arr) {
        func_00259F30(this);
        delete[] m_arr;
        m_arr = 0;
    }
}
