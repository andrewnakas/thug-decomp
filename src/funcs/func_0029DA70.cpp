typedef int qword __attribute__((mode(TI)));

union Vec_0029DA70 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Component {
    int m0;
    unsigned int m_type;
    int m8;
    int mC;
    int m10;
    int m14;
    Component();
    virtual ~Component();
};

extern "C" bool func_001E7FA8(void* s, unsigned int name, Vec_0029DA70* v, int a);
extern "C" bool func_001E7EB0(void* s, unsigned int name, float* out, int a);

struct Comp_0029DA70 : public Component {
    char pad1C[0x20 - 0x1C];
    Vec_0029DA70 m20;
    char pad30[0x40 - 0x30];
    Vec_0029DA70 m40;
    char pad50[0x70 - 0x50];
    float m70;
    char pad74[0x80 - 0x74];
    float m80;
    char pad84[0x8C - 0x84];
    float m8C;
    virtual void Finalize();
    int CallMemberFunction(unsigned int name, void* params, void* script);
};

int Comp_0029DA70::CallMemberFunction(unsigned int name, void* params, void* script)
{
    switch (name) {
    case 0xF362BBBF:
        func_001E7FA8(params, 0xB9D31B0A, &m40, 0);
        m20 = m40;
        m70 = 700.0f;
        func_001E7EB0(params, 0xC48391A5, &m70, 0);
        m80 = 0.6f;
        func_001E7EB0(params, 0xE3C07609, &m80, 0);
        m8C = 0.0f;
        func_001E7EB0(params, 0xB8D629CA, &m8C, 0);
        break;
    case 0x69CB3AE1: {
        Vec_0029DA70 v;
        func_001E7FA8(params, 0xB9D31B0A, &v, 1);
        m8C = 0.0f;
        m40 = v;
        Finalize();
        m8C = v.f.y - m40.f.y;
        break;
    }
    default:
        return 2;
    }
    return 1;
}
