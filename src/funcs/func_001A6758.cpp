extern "C" void* func_001046B0(int size);
extern "C" void* func_00258700(void* mem, void* src);

struct Obj_001A6758 {
    char pad0[0x21C];
    void* m21C;
    void Fn(void* src);
};

void Obj_001A6758::Fn(void* src)
{
    if (!m21C)
        m21C = func_00258700(func_001046B0(0x110), src);
}
