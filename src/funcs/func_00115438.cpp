/* sym: _$_12Str_00115438 = 0x001040A8 */
struct Str_00115438 {
    int m0;
    int m_id;
    char* m_str;
    ~Str_00115438();
};

extern char D_00389180[];
extern "C" Str_00115438 func_00131688(const char* a, const char* b);
extern "C" const char* func_001041B8(Str_00115438* s);
extern "C" void func_00132120(void* p);
extern "C" void* func_00132100();
extern "C" int func_0013D2F0(void* p, const char* name, int a, int b, int c, int d, int e);

struct Obj_00115438 {
    char pad[0xC];
    void* mC;
    void Load(const char* name);
};

void Obj_00115438::Load(const char* name)
{
    if (mC) {
        func_00132120(mC);
        mC = 0;
    }
    mC = func_00132100();
    Str_00115438 path = func_00131688(name, D_00389180);
    const char* s = func_001041B8(&path);
    func_0013D2F0(mC, s, 0, 1, 0, 0, 0);
}
