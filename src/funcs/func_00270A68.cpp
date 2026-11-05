typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);
extern "C" float fabsf(float);

struct Vec_00270A68 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

struct Body_00270A68 {
    char m_pad0[0xB0];
    Vec_00270A68 mB0;
};

struct Obj_00270A68 {
    char m_pad0[0xC];
    Body_00270A68* mC;
    char m_pad10[0xC];
    int m1C;
    char m_pad20[0xC];
    float m2C;
    int OnEvent(unsigned int id);
};

extern "C" void func_00270D00(Obj_00270A68* o, float v);
extern "C" void func_00270C68(Obj_00270A68* o, float v);
extern "C" void func_00270DB8(Obj_00270A68* o, float v);
extern "C" void func_00270E20(Obj_00270A68* o, float v);

int Obj_00270A68::OnEvent(unsigned int id)
{
    switch (id) {
    case 0x0E338369:
        switch (m1C) {
        case 0:
        case 1:
        case 4:
            func_00270D00(this, mC->mB0.Length() / m2C);
            break;
        }
        break;
    case 0x2C779F22:
        switch (m1C) {
        case 0:
        case 1:
            func_00270C68(this, fabsf(mC->mB0.y) / m2C);
            break;
        case 4:
            func_00270C68(this, mC->mB0.Length() / m2C);
            break;
        }
        break;
    case 0x0069E457:
        func_00270DB8(this, mC->mB0.Length() / m2C);
        break;
    case 0x6F5E9124:
        func_00270E20(this, mC->mB0.Length() / m2C);
        break;
    default:
        return 2;
    }
    return 1;
}
