struct Appearance_0021B728 {
    char pad[0x48];
    char m_params[0x18];
};

struct Profile_0021B728 {
    int m0;
    Appearance_0021B728 m_appearance;
};

extern "C" bool func_001E8398(void* s, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8180(void* s, unsigned int name, void** out, int required);
extern "C" bool func_001E7DE8(void* s, unsigned int name, int* out, int required);
extern "C" bool func_001E8708(void* s, unsigned int name);
extern "C" Appearance_0021B728* func_0011F880(Appearance_0021B728* app);
extern "C" void func_0011FAB8(Appearance_0021B728* app, void* params, int a);
extern "C" void func_0011F930(Appearance_0021B728* dst, Appearance_0021B728* src);
extern "C" void func_0011F8C8(Appearance_0021B728* app, int flags);
extern "C" void* func_0022E050(void* game);
extern "C" Profile_0021B728* func_002629A8(void* list, int index);
extern "C" Profile_0021B728* func_00263188(void* list, unsigned int name);
extern "C" void func_001E6B30(void* s);
extern "C" void func_001E6AC8(void* dst, void* src);

extern void* D_0038FC78;

bool Cmd_0021B728(void* params, void* script)
{
    unsigned int name;
    func_001E8398(params, 0xA1DC81F9, &name, 1);
    Appearance_0021B728 app;
    func_0011F880(&app);
    void* list = func_0022E050(D_0038FC78);
    void* sparams;
    Appearance_0021B728* src;
    if (func_001E8180(params, 0xEFC8944C, &sparams, 0)) {
        func_0011FAB8(&app, sparams, 1);
        src = &app;
    } else {
        int index;
        func_001E7DE8(params, 0x67E6859A, &index, 1);
        src = &func_002629A8(list, index)->m_appearance;
    }
    Profile_0021B728* profile = func_00263188(list, name);
    Appearance_0021B728* dst = &profile->m_appearance;
    if (func_001E8708(params, 0x3AF36E6D)) {
        void* from = src->m_params;
        func_001E6B30(profile->m_appearance.m_params);
        func_001E6AC8(profile->m_appearance.m_params, from);
    } else {
        func_0011F930(dst, src);
    }
    func_0011F8C8(&app, 2);
    return true;
}
