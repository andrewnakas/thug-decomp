extern void* D_0038FC78;
struct Script_0021D488 {
    char pad[0x18];
    void* m18;
};
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);
extern "C" void* func_0022E050(void* mgr);
extern "C" char* func_002629A8(void* p, int v);
extern "C" void func_001E6AC8(void* s, void* p);

bool func_0021D488(void* params, Script_0021D488* script)
{
    int v;
    func_001E7DE8(params, 0x67E6859A, &v, 1);
    char* p = func_002629A8(func_0022E050(D_0038FC78), v);
    func_001E6AC8(script->m18, p + 0x5C);
    return true;
}
