struct Array_00217A80 {
    int m0;
    int m4;
    int m8;
    unsigned int m_size;
};

extern "C" bool func_001E82B8(void* params, const char* name, Array_00217A80** out, int required);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" unsigned int func_001E9300(Array_00217A80* arr, unsigned int i);
extern "C" void* func_00229668(unsigned int name, int a);
extern "C" void* func_00229DF0(void* node);
extern "C" bool func_001E8890(void* s, const char* name, const char** out, int required);
extern "C" void func_001E7138(void* s, const char* name, const char* value);
extern "C" void func_001E73C8(void* s, const char* name, unsigned int value);
extern "C" void func_001E7860(void* s, const char* name, void* value);
extern "C" void func_001F0370(const char* name, void* params, int a, int b);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" void func_001E6AE8(void* p, int flags);

extern char D_0038F680[];
extern char D_00370CF0[];
extern char D_00370D00[];
extern char D_0038F5F0[];
extern char D_00370D20[];
extern char D_00370DC0[];
extern char D_00370DD0[];
extern char D_00370D68[];
extern char D_00370DE0[];

bool Cmd_00217A80(void* params, void* script)
{
    Array_00217A80* nodes = 0;
    func_001E82B8(params, D_0038F680, &nodes, 0);
    for (unsigned int i = 0; i < nodes->m_size; i++) {
        void* item = func_001E6978(func_001190D0(8));
        const char* name;
        if (!func_001E8890(func_00229DF0(func_00229668(func_001E9300(nodes, i), 1)), D_00370CF0, &name, 0)) {
            name = D_00370D00;
        }
        func_001E7138(item, D_0038F5F0, name);
        func_001E73C8(item, D_00370D20, func_001F0D78(D_00370DC0));
        void* choose = func_001E6978(func_001190D0(8));
        func_001E73C8(choose, D_00370DD0, func_001E9300(nodes, i));
        func_001E7860(item, D_00370D68, choose);
        func_001F0370(D_00370DE0, item, 0, 0);
        if (item) {
            func_001E6AE8(item, 3);
        }
    }
    return true;
}
