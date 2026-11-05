extern "C" int func_00329438(int sectors, void* buf, int n, int* res);
extern "C" int func_0031EEC0(void* f, void* buf, int size);

struct Obj_001F6D38 {
    int m0;
    char pad[0x2C];
    void* m30;
    int Read(void* buf, int size);
};

int Obj_001F6D38::Read(void* buf, int size)
{
    int res[4];
    if (!m0)
        return func_0031EEC0(m30, buf, size);
    return func_00329438(size >> 11, buf, 1, res) << 11;
}
