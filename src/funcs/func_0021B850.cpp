extern void* D_0038FC78;

struct Entry_0021B850 {
    int pad0;
    char m_info[0x48];
    char m_params[8];
};

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void* func_0022E050(void* game);
extern "C" Entry_0021B850* func_002629A8(void* list, int index);
extern "C" Entry_0021B850* func_00263188(void* list, unsigned int name);
extern "C" void func_001E6B30(void* params);
extern "C" void func_001E6AC8(void* params, void* src);
extern "C" void func_0011F930(void* dst, void* src);

bool Cmd_0021B850(void* params, void* script)
{
    unsigned int name;
    func_001E8398(params, 0xA1DC81F9, &name, 1);
    int index;
    func_001E7DE8(params, 0x67E6859A, &index, 1);
    void* list = func_0022E050(D_0038FC78);
    Entry_0021B850* dst = func_002629A8(list, index);
    Entry_0021B850* src = func_00263188(list, name);
    void* dstInfo = dst->m_info;
    void* srcInfo = src->m_info;
    if (func_001E8708(params, 0x3AF36E6D)) {
        void* to = dst->m_params;
        void* from = src->m_params;
        func_001E6B30(to);
        func_001E6AC8(to, from);
    } else {
        func_0011F930(dstInfo, srcInfo);
    }
    return true;
}
