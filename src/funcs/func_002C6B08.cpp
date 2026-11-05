struct Sub_002C6B08 {
    char pad0[0x74];
    int m74;
    int m78;
};

extern "C" int func_002C0370(void* p, int a, int b);
extern "C" void func_002C9FA8(void* p, int a, int b, int c);
extern "C" void func_002C9DD0(Sub_002C6B08* s);

struct Obj_002C6B08 {
    char pad0[0x80];
    void* m80;
    char pad84[0xA0 - 0x84];
    Sub_002C6B08* mA0;
    void* mA4;
    void Refresh();
};

void Obj_002C6B08::Refresh()
{
    int x = mA0->m74;
    int y = mA0->m78;
    func_002C9FA8(mA4, func_002C0370(m80, x, 0), x, y);
    if (mA0)
        func_002C9DD0(mA0);
}
