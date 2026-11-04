extern "C" short func_0013E9D8(void* self);
extern "C" int func_0013CA20(void* p, int a, int b, int c);

class C_0013E108 {
public:
    char m_pad0[0x10];
    void* m_items[36];
    int ApplyAll(int a, int b, int c);
};

int C_0013E108::ApplyAll(int a, int b, int c)
{
    int any = 0;
    short n = func_0013E9D8(this);
    for (short i = 0; i < n; i++) {
        any |= func_0013CA20(m_items[i], a, b, c) != 0;
    }
    return any;
}
