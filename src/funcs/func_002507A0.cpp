extern char D_00390618[];
extern char D_00390620[];
extern char D_00374A10[];
extern "C" bool func_001E8A50(void* params, const char* name, unsigned int* out, int required);
extern "C" bool func_001E88F8(void* params, const char* name, int* out, int required);
extern "C" void* func_001046B0(int size);
extern "C" void* func_0024FFA8(void* p);
extern "C" void* func_002500E0(void* p, int v);
extern "C" void* func_00250638(void* p, int v);
extern "C" void* func_002503F0(void* p);
extern "C" void* func_002508F0(void* p);

void* Create_002507A0(void* params)
{
    unsigned int type;
    func_001E8A50(params, D_00390618, &type, 1);
    void* obj = 0;
    switch (type) {
    case 0x8F30FD26:
        obj = func_0024FFA8(func_001046B0(8));
        break;
    case 0x71CD53A2: {
        int v;
        func_001E88F8(params, D_00390620, &v, 1);
        obj = func_002500E0(func_001046B0(0xC), v);
        break;
    }
    case 0x6FAD9811: {
        int v;
        func_001E88F8(params, D_00374A10, &v, 1);
        obj = func_00250638(func_001046B0(0xC), v);
        break;
    }
    case 0x6FC19399:
        obj = func_002503F0(func_001046B0(8));
        break;
    case 0xCC06880F:
        obj = func_002508F0(func_001046B0(8));
        break;
    }
    return obj;
}
