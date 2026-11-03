extern void* D_00392068;
extern char D_00370C80[];
extern char D_00370C40[];
extern char D_0038F650[];
extern "C" void* func_002A6070(void* mgr);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" void* func_00202EF8(void* owner, unsigned int id);
extern "C" bool func_001E8A50(void* params, const char* name, unsigned int* out, int required);

bool Check_00216F30()
{
    void* owner = func_002A6070(D_00392068);
    void* params = func_00202EF8(owner, func_001F0D78(D_00370C80));
    unsigned int value;
    func_001E8A50(params, D_00370C40, &value, 1);
    return value == func_001F0D78(D_0038F650);
}
