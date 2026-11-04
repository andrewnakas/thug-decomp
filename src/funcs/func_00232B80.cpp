struct List_00232B80 {
    int m_count;
    unsigned int m_ids[1];
};

extern "C" void func_002161F8(int a, int b);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E6AE8(void* params, int flags);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001F0210(unsigned int script, void* params, void* a, int b, int c);

bool func_00232B80(List_00232B80** data)
{
    func_002161F8(0, 0);
    List_00232B80* list = *data;
    for (int i = 0; i < list->m_count; i++) {
        void* params = func_001E6978(func_001190D0(8));
        func_001E7360(params, 0xF649D637, 0);
        func_001E7360(params, 0xAE94C183, list->m_ids[i]);
        func_001F0210(0x3CF9E86D, params, 0, 0, 0);
        if (params) {
            func_001E6AE8(params, 3);
        }
    }
    return true;
}
