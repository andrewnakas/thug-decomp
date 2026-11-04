struct Obj_001CE528 {
    char m_pad[0x20];
    int m20;
    int Handle(unsigned int name, void* params);
};

extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" void func_001CE618(Obj_001CE528* self, float a, float b, float c, float d);

int Obj_001CE528::Handle(unsigned int name, void* params)
{
    switch (name) {
    case 0xB8F23899: {
        float a;
        float b;
        float c;
        float d = 1.0f;
        func_001E7EB0(params, 0xFD4BC03E, &a, 1);
        func_001E7EB0(params, 0xE3C07609, &b, 1);
        func_001E7EB0(params, 0x906B67BA, &c, 1);
        func_001E7EB0(params, 0x48D4868B, &d, 0);
        func_001CE618(this, a, b, c, d);
        return 1;
    }
    case 0xE3B327C0:
        m20 = 0;
        return 1;
    }
    return 2;
}
