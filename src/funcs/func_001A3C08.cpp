extern "C" void func_001DEF68(void* p);

struct C_001A3C08 {
    int m_pad[7];
    void* m1C[3];
    int Call(unsigned int name, void* params, void* script);
};

extern "C" void func_001A3DA0(C_001A3C08* self, void* params, void* script);

int C_001A3C08::Call(unsigned int name, void* params, void* script)
{
    switch (name) {
    case 0xDB05A233:
        func_001A3DA0(this, params, script);
        return 1;
    case 0xA738AEB8:
        for (int i = 0; i < 3; i++) {
            if (m1C[i]) {
                func_001DEF68(m1C[i]);
                m1C[i] = 0;
            }
        }
        return 1;
    }
    return 2;
}
