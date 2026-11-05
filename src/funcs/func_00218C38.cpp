struct Params_00218C38 {
    char pad0[0x18];
    void* m18;
};

extern void* D_0038FC78;
extern char D_00370EA8[];
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F938(void* p);
extern "C" void func_001E73C8(void* p, char* key, int v);

extern "C" bool func_00218C38(void* unused, Params_00218C38* s)
{
    int v = func_0024F938(func_0022E358(D_0038FC78));
    func_001E73C8(s->m18, D_00370EA8, v);
    return true;
}
