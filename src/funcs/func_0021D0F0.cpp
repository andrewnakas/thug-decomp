extern char D_0038F828[];
extern void* D_0038FC78;

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E81F0(void* params, const char* name, void** out, int required);
extern "C" void* func_0022E050(void* game);
extern "C" int func_00262828(void* p);
extern "C" char* func_00262860(void* p, int i);
extern "C" void func_001E6AC8(void* params, void* src);

bool Cmd_0021D0F0(void* params, void* script)
{
    unsigned int name;
    func_001E8398(params, 0xA1DC81F9, &name, 1);
    void* src = 0;
    func_001E81F0(params, D_0038F828, &src, 1);
    void* list = func_0022E050(D_0038FC78);
    int n = func_00262828(list);
    for (int i = 0; i < n; i++) {
        void* p = func_00262860(list, i) + 0x5C;
        unsigned int k;
        func_001E8398(p, 0xA1DC81F9, &k, 1);
        if (k == name) {
            func_001E6AC8(p, src);
            return true;
        }
    }
    return false;
}
