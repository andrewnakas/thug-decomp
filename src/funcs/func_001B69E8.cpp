typedef int qword_001B69E8 __attribute__((mode(TI)));

struct Vec_001B69E8 {
    union {
        qword_001B69E8 q;
        struct {
            float x, y, z, w;
        };
    };
};

extern "C" void* func_001046B0(unsigned int size);
extern "C" void* func_00185578(int obj, unsigned int name);

class Sphere_001B69E8 {
public:
    char pad[0x40];
    Sphere_001B69E8(int model, Vec_001B69E8* axis, float angle);
    static void* operator new(unsigned int size) { return func_001046B0(size); }
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
    Shape_001B69E8();
    void SetName(const char* name);
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

struct Model_001B69E8 {
    char pad[0xF0];
    Vec_001B69E8 mF0;
    char pad100[0x160];
    int m260;
};

struct Owner_001B69E8 {
    char pad[0x70];
    char m70[1];
};

extern char D_00362BC0[];

struct C_001B69E8 {
    char pad[0xC];
    Owner_001B69E8* mC;
    char pad10[0xC];
    void* m1C;
    char m20[0x10];
    Vec_001B69E8 m30;
    void Create(int type);
};

void C_001B69E8::Create(int type)
{
    if (m1C)
        return;
    int model = 0;
    Model_001B69E8* m = (Model_001B69E8*)func_00185578((int)mC, 0x286A8D26);
    if (m)
        model = m->m260;
    switch (type) {
    case 1: {
        Vec_001B69E8 axis;
        axis.x = 0.0f;
        axis.y = -1.0f;
        axis.z = 0.0f;
        axis.w = 1.0f;
        m1C = new Sphere_001B69E8(model, &axis, 72.0f);
        break;
    }
    case 2: {
        Shape_001B69E8* s = new Shape_001B69E8;
        {
            Vec_001B69E8 v = ((Model_001B69E8*)model)->mF0;
            s->m10 = v.x;
        }
        s->SetName(D_00362BC0);
        m1C = s;
        Vec_001B69E8 p = m30;
        s->Place(m20, mC->m70, &p);
        break;
    }
    }
}
