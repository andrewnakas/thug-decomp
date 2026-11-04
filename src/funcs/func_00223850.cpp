struct Str7_00223850 {
    unsigned int a;
    unsigned short b;
    unsigned char c;
};
extern Str7_00223850 D_0038F948[];
extern char D_0038F950[];
extern char D_0038F958[];
extern char D_00371BD0[];
extern char D_00371BE0[];
extern char D_00371BF0[];

struct Skater_00223850 {
    char pad[0x168];
    int m_custom;
    int m_female;
    char m_name[1];
};

struct Script_00223850 {
    char pad[0xBC];
    Skater_00223850* m_skater;
};

extern "C" bool func_001E7C80(void* params, unsigned int key, char** out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int key, int* out, int required);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int size, int type);
extern "C" void func_001E90A8(void* arr, int i, int value);
extern "C" int func_001E9270(void* arr, int i);
extern "C" int func_00100030(int n);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" char* func_00331678(char* dst, const char* src);
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" bool func_001E11A8(unsigned int key);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E73C8(void* params, char* name, unsigned int value);
extern "C" void func_001F0370(char* name, void* params, Skater_00223850* skater, int a);
extern "C" void func_001E6AE8(void* p, int flags);
extern "C" void func_001E6518(void* arr);
extern "C" void func_001E8DE8(void* arr, int flags);

bool func_00223850(void* params, Script_00223850* script)
{
    Skater_00223850* skater = script->m_skater;
    char name[128];
    char prefix[128];
    char buf[128];
    char* suffix;
    func_001E7C80(params, 0x7321A8D6, &suffix, 1);
    int n = 10;
    func_001E7DE8(params, 0x58492707, &n, 0);
    void* arr = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(arr, n, 1);
    for (int i = 0; i < n; i++)
        func_001E90A8(arr, i, i + 1);
    for (int i = 0; i < n; i++) {
        int r = func_00100030(n);
        int a = func_001E9270(arr, r);
        func_001E90A8(arr, r, func_001E9270(arr, i));
        func_001E90A8(arr, i, a);
    }
    func_00331A9C(name, skater->m_name);
    if (skater->m_custom) {
        void* s = func_001E5548(0x5775194E, 1);
        char* str;
        func_001E7C80(s, func_001F0D78(name), &str, 1);
        func_00331A9C(prefix, str);
    } else {
        Str7_00223850* src = D_0038F948;
        unsigned int a = src->a;
        unsigned short b = src->b;
        unsigned char c = src->c;
        *(unsigned int*)prefix = a;
        *(unsigned short*)(prefix + 4) = b;
        prefix[6] = c;
        if (skater->m_female)
            func_00331678(prefix, D_0038F950);
        else
            func_00331678(prefix, D_0038F958);
    }
    for (int i = 0; i < n; i++) {
        func_003331D0(buf, D_00371BD0, prefix, suffix, func_001E9270(arr, i));
        if (func_001E11A8(func_001F0D78(buf))) {
            void* p = func_001E6978(func_001190D0(8));
            func_001E73C8(p, D_00371BE0, func_001F0D78(buf));
            func_001F0370(D_00371BF0, p, script->m_skater, 0);
            if (p)
                func_001E6AE8(p, 3);
            break;
        }
    }
    func_001E6518(arr);
    if (arr)
        func_001E8DE8(arr, 3);
    return true;
}
