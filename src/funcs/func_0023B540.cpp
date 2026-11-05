/* sym: _$_13List_0023B540 = 0x00243AD0 */
extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void func_0023C1A0(void* self);
extern "C" void func_001E6AE8(void* p, int flags);

struct List_0023B540 {
    char pad[0x18];
    ~List_0023B540();
};

struct Obj_0023B540 {
    int m0;
    List_0023B540 m_4;
    void* m_1C;
    ~Obj_0023B540();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_0023B540::~Obj_0023B540()
{
    func_0023C1A0(this);
    if (m_1C) {
        func_001E6AE8(m_1C, 3);
    }
}
