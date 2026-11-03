extern "C" void func_00259DD0(void* p, void* obj);
extern "C" void* func_00259EB8();
extern "C" void* func_00259BA8(void* mgr, void* obj, void* e);
extern "C" void func_00259348(void* p, void* e, void* pos);

struct Obj_001A6AB8 {
    int m_pad[20];
    int m50[4];
};

struct C_001A6AB8 {
    int m_pad[3];
    Obj_001A6AB8* mC;
    int m10[68];
    void* m120;
    void Select(void* e);
};

extern "C" void func_001A6758(C_001A6AB8* self, Obj_001A6AB8* obj);
extern "C" void* func_001A67A8(C_001A6AB8* self);

void C_001A6AB8::Select(void* e)
{
    if (m120) func_00259DD0(m120, mC);
    m120 = func_00259BA8(func_00259EB8(), mC, e);
    func_001A6758(this, mC);
    func_00259348(func_001A67A8(this), e, mC->m50);
}
