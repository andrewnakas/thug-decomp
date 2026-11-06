extern "C" void func_0010BEB8(void* p);

struct Buf_001E8E38 {
    int m0;
    void* m4;
    int m8;
    int mC;
    void Clear();
};

void Buf_001E8E38::Clear()
{
    if (mC == 1) {
        if (m4)
            m4 = 0;
    } else if (m4) {
        func_0010BEB8(m4);
        m4 = 0;
    }
    m8 = 0;
    mC = 0;
}
