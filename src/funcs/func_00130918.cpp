struct Entry_00130918 {
    char m_name[0x18];
    void* m_obj;
};

struct Arr_00130918 {
    char pad[0xC];
    unsigned int mC;
};

extern Entry_00130918 D_003BE920[16];
extern char D_003BEAE0[];
extern char D_0035D370[];
extern int D_00389B50;
extern char D_00465390[32];

extern "C" void* func_00130BB8(const char* name);
extern "C" void* func_0014A918(const char* name);
extern "C" void func_001357E0(void* o, int a, int b);
extern "C" void func_00135808(void* o, int c);
extern "C" void func_00135830(void* o, int d);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_00130E78(void* map, unsigned int* key, Entry_00130918* e);
extern "C" Arr_00130918* func_001E55F8(const char* name, int flags);
extern "C" int func_001E9270(Arr_00130918* arr, int i);

void func_00130918(const char* name, int a, int b, int c, int d)
{
    if (func_00130BB8(name)) {
        func_001357E0(func_00130BB8(name), a, b);
        if (c)
            func_00135808(func_00130BB8(name), c);
        func_00135830(func_00130BB8(name), d);
        return;
    }
    for (int i = 0; i < 16; i++) {
        if (!D_003BE920[i].m_obj) {
            D_003BE920[i].m_obj = func_0014A918(name);
            func_001357E0(D_003BE920[i].m_obj, a, b);
            if (c)
                func_00135808(D_003BE920[i].m_obj, c);
            func_00135830(D_003BE920[i].m_obj, d);
            func_00331A9C(D_003BE920[i].m_name, name);
            unsigned int key = func_001F0D78(name);
            func_00130E78(D_003BEAE0, &key, &D_003BE920[i]);
            break;
        }
    }
    if (!D_00389B50) {
        Arr_00130918* arr = func_001E55F8(D_0035D370, 1);
        if (arr) {
            for (unsigned int i = 0; i < 32; i++) {
                int v = i < arr->mC ? func_001E9270(arr, i) : 0;
                D_00465390[i] = v < 10 ? v + '0' : v + 'a' - 10;
            }
            D_00389B50 = 1;
        }
    }
}
