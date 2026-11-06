struct Key_0018DFF0 {
    unsigned char c[4];
};

extern "C" void* func_0013E9B8(void* p, int a);
extern "C" void func_0013C438(void* p, Key_0018DFF0* key);

struct Obj_0018DFF0 {
    char pad0[0x260];
    void* m260;
    char pad264[0x28C - 0x264];
    int m28C;
    void Fn(const Key_0018DFF0* key);
};

void Obj_0018DFF0::Fn(const Key_0018DFF0* key)
{
    if (m28C) {
        Key_0018DFF0 k = *key;
        func_0013C438(func_0013E9B8(m260, 0), &k);
    }
}
