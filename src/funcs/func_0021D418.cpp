struct Obj_0021D418 {
    char pad[0x5C];
    char m5C[4];
};
extern void* D_0038FC78;
extern char D_0038F828[];
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E81F0(void* params, const char* name, void** out, int required);
extern "C" void* func_0022E050(void* mgr);
extern "C" Obj_0021D418* func_002629A8(void* p, int a);
extern "C" void func_001E6AC8(void* p, void* s);

extern "C" bool func_0021D418(void* params, void* script)
{
    int a;
    void* s;
    func_001E7DE8(params, 0x67E6859A, &a, 1);
    func_001E81F0(params, D_0038F828, &s, 1);
    func_001E6AC8(func_002629A8(func_0022E050(D_0038FC78), a)->m5C, s);
    return true;
}
