extern "C" void func_00306EC0(void* p);
extern "C" void func_001048F0(void* p);

struct Obj_002D2CF8 {
    char pad0[0x14C];
    int m14C;
    char pad150[8];
    void* m158;
    char pad15C[0xC];
    void* m168;
    void Stop();
};

void Obj_002D2CF8::Stop()
{
    if (m158) {
        func_00306EC0(m158);
        func_001048F0(m168);
    }
    m14C = 0;
}
