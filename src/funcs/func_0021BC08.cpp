extern "C" bool func_002A19A8(void* p);
extern "C" bool func_001E5648(const char* name, int a);
extern "C" void func_0010BFC0(const char* name);
extern "C" void func_0010BFC8();
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" void func_0021B230(unsigned int name);
extern "C" void* func_001E9378(void* arr, unsigned int i);
extern "C" bool func_001E8398(void* s, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8890(void* s, const char* name, const char** out, int required);
extern "C" bool func_001E8A30(void* s, unsigned int name, unsigned int* out, int required);
extern "C" void* func_001E5548(unsigned int name, int a);
extern "C" void* func_00104008(void* str);
extern "C" void func_00131688(void* out, const char* name, const char* ext);
extern "C" void* func_00104170(void* str, void* other);
extern "C" void func_001040A8(void* str, int flags);
extern "C" const char* func_001041B8(void* str);
extern "C" void* func_00132100();
extern "C" void func_00132120(void* p);
extern "C" void func_0013D2F0(void* p, const char* name, int a, int b, int c, int d, int e);
extern "C" void* func_0011F880(void* app);
extern "C" void func_0011FAB8(void* app, void* profile, int a);
extern "C" void* func_00120168(void* obj, int a, int b);
extern "C" void func_001201C0(void* obj, void* app, void* p, int a, unsigned int name);
extern "C" void func_00183D80(void* obj, int flags);
extern "C" void func_0011F8C8(void* app, int flags);

struct Array_0021BC08 {
    int m0;
    int m4;
    int m8;
    unsigned int m_size;
};

extern "C" Array_0021BC08* func_001E55B8(unsigned int name, int a);

extern void* D_00392068;
extern char D_00371530[];
extern char D_00371548[];
extern char D_00371560[];
extern char D_00371570[];
extern char D_00371580[];
extern char D_00371590[];
extern char D_003715A0[];
extern char D_003715B0[];
extern char D_003715C0[];
extern char D_003715D0[];
extern char D_003715E0[];
extern char D_0038F7E0[];
extern char D_0038F7E8[];
extern char D_0038F7F0[];
extern char D_0038F7F8[];

bool Cmd_0021BC08(void* params, void* script)
{
    char str[16];
    char tmp[16];
    if (!func_002A19A8(D_00392068) && !func_001E5648(D_00371530, 0)) {
        func_0010BFC0(D_00371548);
        if (!func_001E8708(params, 0xF6F8E158)) {
            func_0021B230(func_001F0D78(D_00371560));
            func_0021B230(func_001F0D78(D_00371570));
            func_0021B230(func_001F0D78(D_00371580));
            func_0021B230(func_001F0D78(D_00371590));
            func_0021B230(func_001F0D78(D_003715A0));
            func_0021B230(func_001F0D78(D_003715B0));
        }
        Array_0021BC08* arr = func_001E55B8(0xC472ECC5, 0);
        for (unsigned int i = 0; i < arr->m_size; i++) {
            void* s = func_001E9378(arr, i);
            unsigned int type = 0;
            func_001E8398(s, func_001F0D78(D_0038F7E8), &type, 0);
            if (type != func_001F0D78(D_003715C0)) {
                continue;
            }
            const char* model;
            if (func_001E8890(s, D_0038F7F0, &model, 0)) {
                func_00104008(str);
                func_00131688(tmp, model, D_0038F7F8);
                func_00104170(str, tmp);
                func_001040A8(tmp, 2);
                void* p = func_00132100();
                func_0013D2F0(p, func_001041B8(str), 0, 1, 8, 0, 0);
                func_00132120(p);
                func_001040A8(str, 2);
            }
            const char* shadow;
            if (func_001E8890(s, D_003715D0, &shadow, 0)) {
                func_00104008(str);
                func_00131688(tmp, shadow, D_0038F7E0);
                func_00104170(str, tmp);
                func_001040A8(tmp, 2);
                void* p = func_00132100();
                func_0013D2F0(p, func_001041B8(str), 0, 1, 8, 0, 0);
                func_00132120(p);
                func_001040A8(str, 2);
            }
            unsigned int profile_name;
            if (func_001E8A30(s, 0x7EA855F0, &profile_name, 0)) {
                void* profile = func_001E5548(profile_name, 0);
                if (profile) {
                    void* p = func_00132100();
                    char app[0x60];
                    char obj[0x50];
                    func_0011F880(app);
                    func_0011FAB8(app, profile, 0);
                    func_00120168(obj, 1, 8);
                    func_001201C0(obj, app, p, 0, func_001F0D78(D_003715E0));
                    func_00132120(p);
                    func_00183D80(obj, 2);
                    func_0011F8C8(app, 2);
                }
            }
        }
        func_0010BFC8();
        return true;
    }
    return false;
}
