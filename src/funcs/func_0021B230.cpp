struct Array_0021B230 {
    int m0;
    int m4;
    int m8;
    unsigned int m_size;
};

extern "C" Array_0021B230* func_001E55B8(char* name, int a);
extern "C" void* func_001E9378(Array_0021B230* a, unsigned int i);
extern "C" bool func_001E7DE8(void* s, unsigned int name, int* out, int required);
extern "C" bool func_001E8870(void* s, unsigned int name, char** out, int required);
extern "C" void* func_00132100();
extern "C" void func_00132120(void* p);
extern "C" void func_0013D2F0(void* p, char* s, int a, int b, int c, int d, int e);

void func_0021B230(char* name)
{
    unsigned int i = 0;
    Array_0021B230* arr = func_001E55B8(name, 0);
    for (; i < arr->m_size; i++) {
        void* s = func_001E9378(arr, i);
        int v = 0;
        char* str;
        func_001E7DE8(s, 0xF1E3CD22, &v, 0);
        if (v && func_001E8870(s, 0x1E90C5A9, &str, 0)) {
            void* p = func_00132100();
            func_0013D2F0(p, str, 0, 1, 0, 0, 0);
            func_00132120(p);
        }
    }
}
