extern "C" short func_0013E9D8(void* self);
extern "C" int func_0013C9F8(void* p, int a, int b, float x, float y);

class C_0013E038 {
public:
    char m_pad0[0x10];
    void* m_items[36];
    int ApplyAll(int a, int b, float x, float y);
};

int C_0013E038::ApplyAll(int a, int b, float x, float y)
{
    int any = 0;
    short n = func_0013E9D8(this);
    for (short i = 0; i < n; i++) {
        any |= func_0013C9F8(m_items[i], a, b, x, y) != 0;
    }
    return any;
}
