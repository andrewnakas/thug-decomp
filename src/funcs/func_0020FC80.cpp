extern "C" int func_001E8398(void* p, unsigned int id, unsigned int* v, int f);
extern "C" void func_001375C0(unsigned int v, void* p);
extern "C" int func_001E7DE8(void* p, unsigned int id, int* v, int f);
extern "C" int func_001E8540(void* p, unsigned int id, int* v, int f);
extern "C" int func_00229C20(int v, unsigned short* out);
extern "C" void func_00136440(int a, unsigned short b, int c, void* p);

bool func_0020FC80(void* params, void* script)
{
    unsigned short idx;
    unsigned int name;
    int a;
    int b;
    name = 0;
    if (func_001E8398(params, 0x40C698AF, &name, 0)) {
        func_001375C0(name, params);
        return true;
    }
    a = 0;
    func_001E7DE8(params, 0x906B67BA, &a, 0);
    b = 0;
    if (func_001E8540(params, 0x6C4E7971, &b, 0)) {
        idx = 0;
        int h = func_00229C20(b, &idx);
        func_00136440(h, idx, a, params);
        return true;
    }
    return false;
}
