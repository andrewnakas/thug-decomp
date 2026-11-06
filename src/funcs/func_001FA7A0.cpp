extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

class Obj_001FA7A0 {
public:
    char m_pad0[0x2C];
    void* m2C;
    char m_pad30[0x40 - 0x30];
    int m40;
    ~Obj_001FA7A0();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_001FA7A0::~Obj_001FA7A0()
{
    if (m2C && !m40)
        func_0010A8D8(D_00388A70, m2C);
}
