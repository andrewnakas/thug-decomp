struct Pool_001E4DE0 {
    char pad[0xEC];
    void* mEC;
};
extern Pool_001E4DE0* D_00388A70;
extern int D_0038E3F4;
extern "C" void func_0010A950(Pool_001E4DE0* pool, void* ctx);
extern "C" void func_0010A9B0(Pool_001E4DE0* pool);
extern "C" int func_00331BB8(const char* s);
extern "C" char* func_0010BDE0(int size);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" char* func_001E4CD8(const char* s);

extern "C" char* func_001E4DE0(const char* s)
{
    if (D_0038E3F4)
        return func_001E4CD8(s);
    func_0010A950(D_00388A70, D_00388A70->mEC);
    char* p = func_0010BDE0(func_00331BB8(s) + 1);
    func_00331A9C(p, s);
    func_0010A9B0(D_00388A70);
    return p;
}
