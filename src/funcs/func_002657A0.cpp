struct Obj_002657A0 {
    char m_pad[0x18];
    int m18;
    unsigned int m_time;
    int m_gen;
    int m_valid;
};

extern char D_00375F38[];
extern char D_00452F28[];

extern "C" void func_00103F28(const char* fmt, ...);
extern "C" Obj_002657A0* func_00265EA0(void* mgr, unsigned int id);
extern "C" void* func_00240850();
extern "C" void func_0023D230(void* sys, int a, unsigned int time);

extern "C" unsigned int func_002657A0(void* mgr, unsigned int n, unsigned int* ids, char* flags, int gen,
                                      unsigned int time)
{
    func_00103F28(D_00375F38);
    unsigned int i;
    for (i = 0; i < n; i++)
        D_00452F28[i] = 0;
    for (i = 0; i < n; i++) {
        Obj_002657A0* o = func_00265EA0(mgr, ids[i]);
        if (!o)
            continue;
        func_0023D230(func_00240850(), o->m18, time);
        if (o->m_time < time) {
            bool changed = o->m_gen != gen;
            if (!o->m_valid || changed)
                D_00452F28[i] = 1;
            if (o->m_valid && changed)
                flags[o->m_gen] = 1;
            o->m_valid = 1;
            o->m_time = time;
            o->m_gen = gen;
        }
    }
    unsigned int count = 0;
    for (i = 0; i < n; i++) {
        if (D_00452F28[i])
            ids[count++] = ids[i];
    }
    return count;
}
