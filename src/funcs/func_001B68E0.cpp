struct Shape_001B68E0 {
    int m0;
    int m_type;
    char pad8[0xC];
    float m14;
};

class Base_001B68E0 {
public:
    char pad[0x18];
    virtual void V0();
    virtual void V1();
    virtual void Setup(void* params);
};

extern char D_00362BD0[];
extern "C" void func_001B6B08(void* self);
extern "C" int func_001E84E8(void* params, const char* name, void* out, int req);
extern "C" void func_001E73C8(void* params, const char* name, unsigned int value);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);

class C_001B68E0 : public Base_001B68E0 {
public:
    Shape_001B68E0* m1C;
    int Call(unsigned int name, void* params);
};

int C_001B68E0::Call(unsigned int name, void* params)
{
    switch (name) {
    case 0xAAF6E513:
        func_001B6B08(this);
        break;
    case 0xF272C43A: {
        int value;
        if (!func_001E84E8(params, D_00362BD0, &value, 0))
            func_001E73C8(params, D_00362BD0, 0x3E84C2FD);
        Setup(params);
        if (m1C && m1C->m_type == 2) {
            float r = 0.2f;
            func_001E7EB0(params, 0xA6F5352F, &r, 0);
            m1C->m14 = r;
        }
        break;
    }
    default:
        return 2;
    }
    return 1;
}
