extern "C" void func_00133D48(void* p, int v);

struct Obj_002B7DB0 {
    int m0;
    char pad4[0x14];
    void* m18;
    void Refresh(int force);
};

void Obj_002B7DB0::Refresh(int force)
{
    if (!(m0 & 0x40) && !force) {
        if (!(m0 & 8))
            return;
        if (!(m0 & 4))
            return;
    }
    func_00133D48(m18, 0);
    m0 = (m0 | 0x10) & ~0x40;
}
