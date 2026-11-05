/* sym: _vt$12Obj_0011ECE8 = 0x0035CA68 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

class Obj_0011ECE8 {
public:
    char pad[0x48C];
    void* m48C;
    int m490;
    virtual ~Obj_0011ECE8() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_0011ECE8::~Obj_0011ECE8()
{
    if (m48C) {
        func_0010A8D8(D_00388A70, m48C);
        m48C = 0;
    }
}
