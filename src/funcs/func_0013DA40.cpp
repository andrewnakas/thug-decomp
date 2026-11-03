extern "C" short func_0013E9D8(void* self);
extern "C" int func_0013E9B8(void* self, int i);

class C_0013DA40 {
public:
    char m_pad0[0xA0];
    int m_keys[1];
    int Find(int key);
};

int C_0013DA40::Find(int key)
{
    short n = func_0013E9D8(this);
    for (short i = 0; i < n; i++) {
        if (key == m_keys[i]) {
            return func_0013E9B8(this, i);
        }
    }
    return 0;
}
