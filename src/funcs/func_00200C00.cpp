/* sym: _vt$11Cb_00200C00 = 0x00366B58 */
struct Item_00200C00 {
    char m_pad0[0x48];
    int m48;
};

struct Cb_00200C00 {
    int m0;
    int m4;
    Cb_00200C00() : m4(0) {}
    virtual ~Cb_00200C00() {}
    virtual void Run();
};

extern "C" Item_00200C00* func_00200EC0(void* self, Cb_00200C00* cb);
extern "C" void func_001FF970(void* self, int a, int b);

extern "C" void func_00200C00(void* self, int b)
{
    Cb_00200C00 cb;
    Item_00200C00* it = func_00200EC0(self, &cb);
    if (it)
        func_001FF970(self, it->m48, b);
}
