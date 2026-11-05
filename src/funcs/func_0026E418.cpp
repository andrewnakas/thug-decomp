/* sym: _$_13Elem_0026E418 = 0x0026DFE0 */
extern int D_00388A70;
extern "C" void func_0010A8D8(int pool, void* p);

struct Elem_0026E418 {
    char m_pad[0x14];
    ~Elem_0026E418();
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Obj_0026E418 {
    int m0;
    int m4;
    Elem_0026E418* m8;
    ~Obj_0026E418();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_0026E418::~Obj_0026E418()
{
    delete[] m8;
}
