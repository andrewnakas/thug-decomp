struct Buf_00122AA8 {
    char m_data[0x40];
};

extern char D_0035CBC0[];
extern "C" int func_001E81F0(void* params, const char* name, int* out, int req);
extern "C" void func_001228A8(Buf_00122AA8* b, int v);
extern "C" void func_00122060(Buf_00122AA8* b);

extern "C" bool func_00122AA8(void* params, void* script)
{
    Buf_00122AA8 b;
    int v = 0;
    func_001E81F0(params, D_0035CBC0, &v, 0);
    if (v) {
        func_001228A8(&b, v);
        func_00122060(&b);
    }
    return true;
}
