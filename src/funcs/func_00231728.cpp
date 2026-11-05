struct Obj_00231728 {
    char pad[0x20];
    void* m_20;
    void Update();
};

extern void* D_00392068;
extern "C" bool func_002A7DE0(void* a);
extern "C" unsigned int* func_002A39D8(void* a);
extern "C" unsigned int func_002A7ED0(void* a);
extern "C" void func_002313E0(void* a, int b);

void Obj_00231728::Update()
{
    void* mgr = D_00392068;
    void* target = m_20;
    if (func_002A7DE0(mgr)) {
        unsigned int* t = func_002A39D8(mgr);
        if (*t - func_002A7ED0(mgr) >= 2000) {
            func_002313E0(target, 0);
        }
    }
}
