typedef int qword_001B69E8 __attribute__((mode(TI)));

struct Vec_001B69E8 {
    union {
        qword_001B69E8 q;
        struct {
            float x, y, z, w;
        };
    };
};


class Base_001B69E8 {
public:
    int m0;
    int m4;
    virtual void V0();
    virtual void V1();
    virtual void Place(void* where, void* mat, Vec_001B69E8* pos);
};

class Shape_001B69E8 : public Base_001B69E8 {
public:
    int mC;
    float m10;
    int m14;
    void SetName(const char* name);
};

struct Owner_001B69E8 {
    char pad[0x70];
    char m70[1];
};

extern char D_00362BC0[];
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E7C80(void* params, unsigned int name, const char** out, int req);
extern "C" void func_001B6B08(void* self);
extern "C" void func_001B69E8(void* self, int type);

struct C_001B69E8 {
    char pad[0xC];
    Owner_001B69E8* mC;
    char pad10[0xC];
    Shape_001B69E8* m1C;
    char m20[0x10];
    Vec_001B69E8 m30;
    unsigned int m40;
    void Setup(void* params);
};

void C_001B69E8::Setup(void* params)
{
    m40 = 0x3E84C2FD;
    func_001E8398(params, 0x9AC24B18, &m40, 0);
    if (m1C)
        func_001B6B08(this);
    switch (m40) {
    case 0x3E84C2FD: {
        if (!m1C)
            func_001B69E8(this, 2);
        float radius = 1.0f;
        func_001E7EB0(params, 0x6F8CD62F, &radius, 0);
        const char* name = D_00362BC0;
        func_001E7C80(params, 0x545F8172, &name, 0);
        Shape_001B69E8* s = m1C;
        s->m10 = radius;
        s->SetName(name);
        Vec_001B69E8 p = m30;
        s->Place(m20, mC->m70, &p);
        break;
    }
    case 0x76A54CD1:
        if (!m1C)
            func_001B69E8(this, 1);
        break;
    case 0x806FFF30:
        if (m1C)
            func_001B6B08(this);
        break;
    }
}
