struct ObjA_00213388 {
    char m_pad0[0x14];
    ObjA_00213388* m_next;
    char m_pad18[0xC4 - 0x18];
    int mC4;
};

struct ObjB_00213388 {
    char m_pad0[0x14];
    ObjB_00213388* m_next;
    char m_pad18[0x2C - 0x18];
    int m2C;
};

extern void* D_0038C608;

extern "C" void* func_00187278(void* mgr, unsigned int type);
extern "C" void func_0026B770();

bool Cmd_00213388()
{
    for (ObjA_00213388* a = (ObjA_00213388*)func_00187278(D_0038C608, 0x07713C7B); a; a = a->m_next)
        a->mC4 = 0;
    for (ObjB_00213388* b = (ObjB_00213388*)func_00187278(D_0038C608, 0x0F1641E3); b; b = b->m_next)
        b->m2C = 0;
    func_0026B770();
    return true;
}
