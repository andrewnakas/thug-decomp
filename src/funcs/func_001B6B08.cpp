extern "C" void func_0013EE68(void* p, int a);

struct Item1B6B08 {
    int m0;
    int m4;
    virtual ~Item1B6B08();
};

struct Owner1B6B08 {
    char m_pad[0x260];
    void* m260;
};

struct Comp1B6B08 {
    int m_pad[7];
    Item1B6B08* m1C;
    char m_pad20[0x44 - 0x20];
    Owner1B6B08* m44;
    void Release();
};

void Comp1B6B08::Release()
{
    if (m1C) {
        if (m44) {
            func_0013EE68(m44->m260, 0);
        }
        delete m1C;
        m1C = 0;
    }
}
