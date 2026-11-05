struct Data_002D3230 {
    char pad0[0x15C];
    void* m15C;
    void* m160;
    void* m164;
    void* m168;
};

struct Mgr_002D3230 {
    int m0;
    Data_002D3230* m4;
};

extern Mgr_002D3230* D_00392068;
extern "C" void func_00303F20(void* p);
extern "C" void func_00304190();
extern "C" void func_00303958();
extern "C" void func_001048F0(void* p);

bool func_002D3230(void* params, void* script)
{
    Mgr_002D3230* m = D_00392068;
    func_00303F20(m->m4->m15C);
    func_00304190();
    func_00303958();
    func_001048F0(m->m4->m164);
    func_001048F0(m->m4->m168);
    return true;
}
