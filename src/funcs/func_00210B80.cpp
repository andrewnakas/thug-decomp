extern char D_0038F368[];
extern char D_0038F450[];

struct Str_00210B80 {
    char* m_str;
    int pad[3];
};

extern "C" bool func_001E8890(void* params, const char* name, const char** out, int required);
extern "C" void* func_00132100();
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_00104008(Str_00210B80* s);
extern "C" void func_00131688(Str_00210B80* out, const char* name, const char* ext);
extern "C" void func_00104170(Str_00210B80* dst, Str_00210B80* src);
extern "C" void func_001040A8(Str_00210B80* s, int flags);
extern "C" const char* func_001041B8(Str_00210B80* s);
extern "C" int func_0013D2F0(void* p, const char* path, int a, int b, int c, bool d, int e);
extern "C" void func_00132120(void* p);

bool Cmd_00210B80(void* params, void* script)
{
    Str_00210B80 path;
    Str_00210B80 tmp;
    const char* name;
    func_001E8890(params, D_0038F368, &name, 1);
    void* scene = func_00132100();
    bool flag = func_001E8708(params, 0x6C37FDC7);
    func_00104008(&path);
    Str_00210B80* t = &tmp;
    func_00131688(t, name, D_0038F450);
    func_00104170(&path, t);
    func_001040A8(t, 2);
    const char* file = func_001041B8(&path);
    func_0013D2F0(scene, file, 0, 1, 0, flag, 0);
    func_00132120(scene);
    func_001040A8(&path, 2);
    return true;
}
