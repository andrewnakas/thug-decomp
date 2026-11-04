extern "C" short func_0013E9D8(void* self);
extern "C" int func_0013CA48(void* p, int a, int b);

class C_0013E1C8 {
public:
    char m_pad0[0x10];
    void* m_items[36];
    int ApplyAll(int a, int b);
};

int C_0013E1C8::ApplyAll(int a, int b)
{
    int any = 0;
    short n = func_0013E9D8(this);
    for (short i = 0; i < n; i++) {
        any |= func_0013CA48(m_items[i], a, b) != 0;
    }
    return any;
}
