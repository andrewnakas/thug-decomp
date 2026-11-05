struct VEntry_0024A558 {
    short m_delta;
    short m_pad;
    void (*m_fn)(void* self);
};

struct Obj_0024A558 {
    char pad0[0x14];
    VEntry_0024A558* m_vt;
    char pad18[0xAC - 0x18];
    int mAC;
    char padB0[0xC8 - 0xB0];
    int mC8;
};

extern char D_00373E00[];
extern char D_00373E10[];
extern "C" void* func_00240850();
extern "C" void* func_0023BAD8(void* mgr, int id, int a);
extern "C" void* func_00244528(void* obj);
extern "C" bool func_001E7E58(void* params, char* name, int* out, int required);
extern "C" int func_00103F28(char* fmt, ...);

int func_0024A558(Obj_0024A558* self)
{
    int v;
    if (func_001E7E58(func_00244528(func_0023BAD8(func_00240850(), self->mAC, 1)), D_00373E00, &v, 0)) {
        self->mC8 = v;
    }
    VEntry_0024A558* e = &self->m_vt[11];
    e->m_fn((char*)self + e->m_delta);
    func_00103F28(D_00373E10);
    return 1;
}
