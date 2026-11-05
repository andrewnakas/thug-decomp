extern char D_003753A0[];
extern void* D_0038DB38;
extern "C" int func_001E5648(char* name, int a);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void* func_001D05B0(void* self, unsigned int id, int a);
extern "C" void func_001D0460(void* self, void* n);
extern "C" void func_001D04E0(void* self, void* n);

void Fn_00255500(const char* name)
{
    if (func_001E5648(D_003753A0, 0)) {
        void* mgr = D_0038DB38;
        void* n = func_001D05B0(mgr, func_001F0D78(name), 0);
        if (n) {
            func_001D0460(mgr, n);
            func_001D04E0(mgr, n);
        }
    }
}
