struct Mgr_002A9E40 {
    char pad0[0x48];
    int m48;
    char pad4C[0x80 - 0x4C];
    void* m80;
    char pad84[8];
    void* m8C;
};

extern Mgr_002A9E40* D_00392068;
extern char* D_0038C308;
extern "C" void func_00105260(void* list, void* p);

extern "C" bool func_002A9E40()
{
    Mgr_002A9E40* m = D_00392068;
    char* g = D_0038C308 + 8;
    func_00105260(g, m->m8C);
    func_00105260(g, m->m80);
    m->m48 = 1;
    return true;
}
