struct C_001A88B8 {
    int m_pad[7];
    int m1C;
    void Update();
};

extern "C" int func_001A86F8(C_001A88B8* self, int i);

void C_001A88B8::Update()
{
    for (int i = 0; i < 3; i++) {
        if ((m1C >> i) & 1) {
            if (func_001A86F8(this, i)) m1C &= ~(1 << i);
        }
    }
}
