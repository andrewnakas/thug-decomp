extern "C" int func_001E5628(unsigned int checksum, int a);
extern "C" void* func_001E5548(int id, int a);
extern "C" void func_001F0210(unsigned int name, void* obj, int a, int b, int c);

struct Obj_00118CD8 {
    char pad[0x20];
    int m_id;
    int Run();
};

int Obj_00118CD8::Run()
{
    func_001E5628(0x2F510F45, 0);
    void* obj = func_001E5548(m_id, 1);
    if (obj) {
        func_001F0210(0xBDF7F843, obj, 0, 0, 0);
    }
    return 1;
}
