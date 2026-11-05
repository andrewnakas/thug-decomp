extern "C" int func_001E5628(unsigned int checksum, int a);
extern "C" void* func_001E5548(int id, int a);
extern "C" int func_001E8398(void* obj, unsigned int name, int* out, int required);
extern "C" void* func_00184D70(int id);
extern "C" void func_00184950(void* p);

struct Obj_00118D80 {
    char pad[0x20];
    int m_id;
    int Run();
};

int Obj_00118D80::Run()
{
    func_001E5628(0x2F510F45, 0);
    void* obj = func_001E5548(m_id, 1);
    if (obj) {
        int v;
        func_001E8398(obj, 0xA1DC81F9, &v, 1);
        func_00184950(func_00184D70(v));
    }
    return 1;
}
