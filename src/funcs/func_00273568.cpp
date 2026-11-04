struct VSlot_00273568 {
    short m_delta;
    short m_pad;
    void* m_fn;
};

struct Sub_00273568 {
    char m_pad[0x1C];
    int m1C;
};

struct Comp_00273568 {
    char m_pad[0x18];
    VSlot_00273568* m_vtbl;
    int m1C;
    char m_pad2[0x5B0 - 0x20];
    Sub_00273568* m5B0;
    void Suspend(bool b)
    {
        VSlot_00273568* s = &m_vtbl[7];
        ((void (*)(void*, bool))s->m_fn)((char*)this + s->m_delta, b);
    }
};

struct State_00273568 {
    char m_pad[0x20];
    int m20;
};

struct Obj_00273568;

extern "C" int func_0010FC30();
extern "C" void* func_00185578(Obj_00273568* obj, unsigned int name);
extern "C" Obj_00273568* func_00203EE0(Obj_00273568* obj);
extern "C" void func_0027C520(Comp_00273568* c);
extern "C" void func_001BEC28(Comp_00273568* c, bool a);
extern "C" void func_001BA498(Comp_00273568* c, void* info);
extern "C" void func_001CDE88(Comp_00273568* c, void* info);

struct Mode_00273568 {
    char m_pad[0xC];
    Obj_00273568* mC;
    char m_pad2[0xC];
    int m1C;
    int m20;
    int m24;
    char m_pad3[8];
    Comp_00273568* m30;
    State_00273568* m34;
    void Exit();
};

extern "C" void func_00273250(Mode_00273568* self, int a);

void Mode_00273568::Exit()
{
    if (m34->m20 == 1)
        return;
    int last = m20;
    m24 = func_0010FC30() - last;
    m20 = func_0010FC30();
    Comp_00273568* phys = (Comp_00273568*)func_00185578(mC, 0x726E85AA);
    Obj_00273568* o = func_00203EE0(mC);
    Comp_00273568* cam = (Comp_00273568*)func_00185578(o, 0x5E43A604);
    Comp_00273568* view = (Comp_00273568*)func_00185578(o, 0xC7D37EC2);
    bool b = m30->m5B0->m1C == 0;
    func_0027C520(m30);
    m30->Suspend(true);
    ((Comp_00273568*)func_00185578(mC, 0x52D61A0D))->Suspend(true);
    ((Comp_00273568*)func_00185578(mC, 0x9F9CC949))->Suspend(true);
    ((Comp_00273568*)func_00185578(mC, 0x9B373E58))->Suspend(true);
    cam->Suspend(true);
    m34->m20 = 1;
    phys->Suspend(false);
    func_001BEC28(phys, b);
    view->Suspend(false);
    char info[0x60];
    func_001BA498(cam, info);
    func_001CDE88(view, info);
    if (m1C)
        func_00273250(this, m1C);
}
