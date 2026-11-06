extern "C" void* func_00185578(void* p, unsigned int id);
struct Obj_0018F790 {
    int m0, m4, m8;
    void* mC;
    char pad[0x16C - 0x10];
    void* m16C;
    void Init();
};

void Obj_0018F790::Init()
{
    m16C = func_00185578(mC, 0x7713C7B);
}
