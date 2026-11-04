struct VSlot_00273378 {
    short m_delta;
    short m_pad;
    void* m_fn;
};

struct Comp_00273378 {
    char m_pad[0x18];
    VSlot_00273378* m_vtbl;
    int m1C;
    void Suspend(bool b)
    {
        VSlot_00273378* s = &m_vtbl[7];
        ((void (*)(void*, bool))s->m_fn)((char*)this + s->m_delta, b);
    }
};

struct Phys_00273378 {
    char m_pad[0x18];
    VSlot_00273378* m_vtbl;
    int m1C;
    char m_pad2[0x9B0 - 0x20];
    int m9B0;
    char m_pad3[0x9C0 - 0x9B4];
    char m9C0[0x20];
    char m9E0[0x20];
};

struct State_00273378 {
    char m_pad[0x20];
    int m20;
};

struct Obj_00273378;

extern "C" int func_0010FC30();
extern "C" void* func_00185578(Obj_00273378* obj, unsigned int name);
extern "C" Obj_00273378* func_00203EE0(Obj_00273378* obj);
extern "C" void func_001BF0A8(Phys_00273378* p);
extern "C" void func_0027C2C8(Comp_00273378* c, bool a, void* b, void* d);
extern "C" void func_001CDEF0(Comp_00273378* c, void* info);
extern "C" void func_001B8450(Comp_00273378* c, void* info);

struct Mode_00273378 {
    char m_pad[0xC];
    Obj_00273378* mC;
    char m_pad2[0xC];
    int m1C;
    int m20;
    int m24;
    char m_pad3[8];
    Comp_00273378* m30;
    State_00273378* m34;
    void Enter();
};

extern "C" void func_00273250(Mode_00273378* self, int a);

void Mode_00273378::Enter()
{
    if (!m34->m20)
        return;
    int last = m20;
    m24 = func_0010FC30() - last;
    m20 = func_0010FC30();
    Phys_00273378* phys = (Phys_00273378*)func_00185578(mC, 0x726E85AA);
    Obj_00273378* o = func_00203EE0(mC);
    Comp_00273378* cam = (Comp_00273378*)func_00185578(o, 0x5E43A604);
    Comp_00273378* view = (Comp_00273378*)func_00185578(o, 0xC7D37EC2);
    func_001BF0A8(phys);
    ((Comp_00273378*)phys)->Suspend(true);
    view->Suspend(true);
    m34->m20 = 0;
    m30->Suspend(false);
    func_0027C2C8(m30, phys->m1C == 0, phys->m9B0 == 1 ? phys->m9C0 : 0, phys->m9B0 == 2 ? phys->m9E0 : 0);
    ((Comp_00273378*)func_00185578(mC, 0x52D61A0D))->Suspend(false);
    ((Comp_00273378*)func_00185578(mC, 0x9F9CC949))->Suspend(false);
    ((Comp_00273378*)func_00185578(mC, 0x9B373E58))->Suspend(false);
    cam->Suspend(false);
    char info[0x60];
    func_001CDEF0(view, info);
    func_001B8450(cam, info);
    if (m1C)
        func_00273250(this, m1C);
}
