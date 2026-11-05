struct Obj_0023AC30 {
    short m0;
    short m_2;
    char pad4[0x6C - 4];
    int m_6C;
    void SetState(int v);
};

extern void* D_0038FC78;
extern "C" void* func_0022DF08(void* self, int id);
extern "C" void func_00184920(void* obj, unsigned int name, int a, float t);

void Obj_0023AC30::SetState(int v)
{
    if (v != m_6C) {
        m_6C = v;
        void* p = func_0022DF08(D_0038FC78, m_2);
        if (p) {
            func_00184920(p, m_6C ? 0xD0CD8081 : 0x7CCF5EE2, 0, 0.0f);
        }
    }
}
