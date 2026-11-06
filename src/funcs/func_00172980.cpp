extern char D_0038BDC8[];
extern char D_00360D90[];
extern char D_0038BDD0[];
extern "C" int func_00331BB8(const char* s);
extern "C" char* func_0010BDE0(int size);
extern "C" char* func_00331678(char* d, const char* s);
extern "C" int func_00110E38(const char* name, const char* mode);
extern "C" void func_0010BEB8(void* p);

struct Pre_00172980 {
    char c[7];
};

int func_00172980(const char* name)
{
    char* buf = func_0010BDE0(func_00331BB8(name) + 0x11);
    *(Pre_00172980*)buf = *(Pre_00172980*)D_0038BDC8;
    func_00331678(buf, name);
    func_00331678(buf, D_00360D90);
    int r = func_00110E38(buf, D_0038BDD0);
    func_0010BEB8(buf);
    return r;
}
