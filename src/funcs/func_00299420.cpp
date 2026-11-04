extern "C" void func_00135048(void* p, int v);

struct Obj_00299420 {
    char pad0[0x34];
    void* m34;
    void* m38;
    void SetAll(int v);
};

void Obj_00299420::SetAll(int v)
{
    if (m38)
        func_00135048(m38, v);
    if (m34)
        func_00135048(m34, v);
}
