/* sym: _vt$14Voice_00187DC8 = 0x00361CE0 */

extern void* D_00388A70;
extern void* D_0038C7B0;
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void func_00183CB8(void* list, void* ref);
extern "C" void func_00189CA0(void* mgr, void* voice);

class Ref_00187DC8 {
public:
    void* m_obj;
    Ref_00187DC8* m_prev;
    Ref_00187DC8* m_next;

    ~Ref_00187DC8()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
};

class Voice_00187DC8 {
public:
    Ref_00187DC8 m_owner;
    int mC;
    int m10;
    int m14;

    virtual void Key();
    virtual ~Voice_00187DC8();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Voice_00187DC8::~Voice_00187DC8()
{
    func_00189CA0(D_0038C7B0, this);
}
