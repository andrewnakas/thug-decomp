struct Pool_001E9CF8 {
    char pad[0xD8];
    void* mD8;
};
extern Pool_001E9CF8* D_00388A70;
extern "C" void func_0010A950(Pool_001E9CF8* pool, void* ctx);
extern "C" void func_0010A9B0(Pool_001E9CF8* pool);
extern "C" void* func_0010BDE0(int size);
extern "C" void func_0010BEB8(void* p);
extern "C" int func_001E9B08(void* a, void* buf, int size, int b);

extern "C" int func_001E9CF8(void* a, int size)
{
    func_0010A950(D_00388A70, D_00388A70->mD8);
    void* buf = func_0010BDE0(size);
    int r = func_001E9B08(a, buf, size, 1);
    func_0010BEB8(buf);
    func_0010A9B0(D_00388A70);
    return r;
}
