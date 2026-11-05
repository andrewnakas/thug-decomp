extern "C" void func_0010BEB8(void* p);

struct Obj_002683E8 {
    char pad[0x50];
    void* m50;
    int m54;
    int m58;
    int m5C;
    int m60;
    int m64;
    void Free();
};

void Obj_002683E8::Free()
{
    m5C = 0;
    func_0010BEB8(m50);
    m50 = 0;
    m64 = 0;
    m58 = 0;
}
