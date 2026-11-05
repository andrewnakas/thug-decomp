struct Info_002233F8 {
    int m0;
    unsigned int m4;
    unsigned int m8;
};

extern void* D_0038FC78;
extern char D_0038F940[];
extern char D_00371BC0[];
extern char D_003718E0[];
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int required);
extern "C" void* func_0022E050(void* self);
extern "C" void* func_00262990(void* obj);
extern "C" void func_00264728(Info_002233F8* info);
extern "C" int func_002620D8(void* obj, int index, Info_002233F8* info, int flag);

bool Cmd_002233F8(void* params, void* script)
{
    Info_002233F8 info;
    int index;
    unsigned int a;
    unsigned int b;
    func_001E7E58(params, D_0038F940, &index, 1);
    func_001E84E8(params, D_00371BC0, &a, 1);
    func_001E84E8(params, D_003718E0, &b, 1);
    void* obj = func_00262990(func_0022E050(D_0038FC78));
    if (obj) {
        func_00264728(&info);
        info.m4 = a;
        info.m8 = b;
        func_002620D8(obj, index, &info, 0);
        return true;
    }
    return false;
}
