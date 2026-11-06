extern "C" void* func_001190D0(int n);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* o, int n);
extern "C" void func_001841F0(void* obj, void* params);
extern "C" int func_001E8398(void* params, unsigned int name, void** out, int flags);
extern "C" void func_001F0210(void* script, int a, void* obj, int b, int c);
extern "C" void func_00184950(void* obj);

struct Obj_001B7288 {
    char pad[0x1C];
    void* m1C[2];
    void Method(int i);
};

void Obj_001B7288::Method(int i)
{
    if (m1C[i]) {
        void* params = func_001E6978(func_001190D0(8));
        func_001841F0(m1C[i], params);
        void* script;
        if (func_001E8398(params, 0x40764820, &script, 0))
            func_001F0210(script, 0, m1C[i], 0, 0);
        if (params)
            func_001E6AE8(params, 3);
        func_00184950(m1C[i]);
        m1C[i] = 0;
    }
}
