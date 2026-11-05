extern void* D_0038E0A0;
extern "C" void func_001DD448(void* mgr, void* p);

struct Obj_002708C0 {
    char pad[0x1C];
    void* m1C;
    void Release();
};

void Obj_002708C0::Release()
{
    if (m1C) {
        func_001DD448(D_0038E0A0, m1C);
        m1C = 0;
    }
}
