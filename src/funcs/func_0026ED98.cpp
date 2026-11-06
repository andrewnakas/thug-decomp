/* sym: _$_13Elem_0026ED98 = 0x0026E908 */
extern int D_00388A70;
extern "C" void func_0010A8D8(int pool, void* p);

struct Elem_0026ED98 {
    char m_pad[0x1C];
    ~Elem_0026ED98();
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Obj_0026ED98 {
    int m0;
    int m4;
    void* m8;
    Elem_0026ED98* mC;
    ~Obj_0026ED98();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_0026ED98::~Obj_0026ED98()
{
    delete[] mC;
    func_0010A8D8(D_00388A70, m8);
}
