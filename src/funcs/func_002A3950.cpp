extern "C" void func_001F9400(int mgr, int obj);
extern int D_0038EB78;

struct Obj_002A3950 {
    char pad0[0x20];
    int m20;
    void Release();
};

void Obj_002A3950::Release() {
    if (m20) {
        func_001F9400(D_0038EB78, m20);
        m20 = 0;
    }
}
