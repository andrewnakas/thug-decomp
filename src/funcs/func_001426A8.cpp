/* sym: _$_12Tab_001426A8 = 0x00142AB0 */
/* sym: _vt$12Obj_001426A8 = 0x0035EDC0 */
extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);

class Tab_001426A8 {
public:
    int m0[6];
    ~Tab_001426A8();
};

class Obj_001426A8 {
public:
    Tab_001426A8* m_tab;
    virtual void V0();
    virtual ~Obj_001426A8();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_001426A8::~Obj_001426A8()
{
    if (m_tab) {
        delete m_tab;
    }
}
