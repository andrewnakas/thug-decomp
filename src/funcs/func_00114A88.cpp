/* sym: _vt$12Obj_00114A88 = 0x0035C438 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_00183CB8(void* ref, void** slot);
extern void* D_00388A70;

struct Ref_00114A88 {
    void* m_p;
    ~Ref_00114A88()
    {
        if (m_p) {
            func_00183CB8(m_p, &m_p);
            m_p = 0;
        }
    }
};

class Obj_00114A88 {
public:
    char pad[0x18];
    Ref_00114A88 m18;
    int m1C;
    int m20;
    virtual ~Obj_00114A88() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_00114A88::~Obj_00114A88()
{
}
