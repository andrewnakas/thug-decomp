extern "C" void func_00184000(void* p, unsigned int id, int v);
struct Obj_00183F08 {
    char pad[0x1C];
    int m1C;
    void Set(int v);
};

void Obj_00183F08::Set(int v)
{
    m1C = v;
    func_00184000(this, 0x7321A8D6, v);
}
