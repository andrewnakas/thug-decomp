struct Comp_00255E98 {
    char m_pad[0x44];
    void* m_model;
};

extern void* D_0038DB38;

extern "C" Comp_00255E98* func_00185578(void* obj, unsigned int name);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void* func_001D05B0(void* mgr, unsigned int name, int a);
extern "C" void func_001D0460(void* mgr, void* anim);
extern "C" void func_001D04E0(void* mgr, void* anim);
extern "C" void func_001D0AA8(void* mgr, const char* name, int a, void* model, int b, int c);
extern "C" void func_00255968(void* self, int a);

void func_00255E98(void* self, const char* name, int a)
{
    if (func_00185578(self, 0x72AD7B23)) {
        void* mgr = D_0038DB38;
        void* anim = func_001D05B0(mgr, func_001F0D78(name), 0);
        if (anim) {
            func_001D0460(mgr, anim);
            func_001D04E0(mgr, anim);
        }
        func_001D0AA8(mgr, name, a, func_00185578(self, 0x72AD7B23)->m_model, 0, 0);
        func_00255968(self, a);
    }
}
