extern "C" int func_001EFDC0(void* s);
extern "C" void func_001EE4D8(void* s, int flags);
extern "C" void* func_00121960(unsigned int size);
extern "C" void* func_001EE428(void* mem);
extern "C" void func_001EE8C8(void* s, void* script, int a, int b);

struct Self_0024FEC8 {
    int m0;
    int m4;
    void* m8;
    int mC;
    void* m10;
    void* m14;

    void Update();
};

void Self_0024FEC8::Update()
{
    if (m14)
        func_001EFDC0(m14);
    if (mC) {
        mC = 0;
        if (m8)
            func_001EE4D8(m8, 3);
        m8 = func_001EE428(func_00121960(0xF4));
        func_001EE8C8(m8, m10, 0, 0);
    }
    if (m4 == 0 && m8 && !func_001EFDC0(m8)) {
        if (m8)
            func_001EE4D8(m8, 3);
        m8 = 0;
    }
}
