extern char D_003891E8[];
extern char D_003BE0E8[];
extern "C" void* func_00110E38(const char* name, const char* mode);
extern "C" int func_001156C8(void* f, void* dst);
extern "C" void func_00110EF8(void* f);

extern "C" int func_001157E0(const char* name)
{
    int r = 0;
    void* f = func_00110E38(name, D_003891E8);
    if (f) {
        r = func_001156C8(f, D_003BE0E8);
    }
    func_00110EF8(f);
    return r;
}
