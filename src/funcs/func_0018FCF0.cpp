typedef int qword __attribute__((mode(TI)));

struct Vec_0018FCF0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_0018FCF0& operator+=(const Vec_0018FCF0& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
    Vec_0018FCF0& operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }
};

struct Node_0018FCF0 {
    int m0;
    int m4;
    unsigned int m8;
};

struct Target_0018FCF0 {
    char pad0[0x50];
    Vec_0018FCF0 m50;
    char pad60[0xB0 - 0x60];
    Vec_0018FCF0 mB0;
};

struct Src_0018FCF0 {
    char pad0[0xB0];
    Vec_0018FCF0 mB0;
};

struct Src2_0018FCF0 {
    char pad0[0x110];
    Vec_0018FCF0 m110;
};

struct Base_0018FCF0 {
    int m0[3];
    Target_0018FCF0* mC;
    int m10[2];
    virtual void V0();
    virtual void V1();
    virtual void V2(void* params);
};

struct Comp_0018FCF0 : Base_0018FCF0 {
    char pad1C[0xB4 - 0x1C];
    int mB4;
    char padB8[0xD4 - 0xB8];
    int mD4;
    char padD8[0xE0 - 0xD8];
    Vec_0018FCF0 mE0;
    Vec_0018FCF0 mF0;
    char pad100[0x110 - 0x100];
    Vec_0018FCF0 m110;
    char pad120[0x164 - 0x120];
    float m164;
    int CallMember(unsigned int name, void* params, void* script);
};

extern void* D_0038C608;
extern "C" float func_001000D0(float range);
extern "C" Src2_0018FCF0* func_00185578(void* obj, unsigned int name);
extern "C" Src_0018FCF0* func_00187B48(void* mgr, unsigned int name);
extern "C" void func_00190E28(Comp_0018FCF0* c);
extern "C" void func_00190E50(Comp_0018FCF0* c);
extern "C" Node_0018FCF0* func_001E6E90(void* params, Node_0018FCF0* n);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E7FA8(void* params, unsigned int name, Vec_0018FCF0* out, int req);
extern "C" int func_001E8708(void* params, unsigned int name);

int Comp_0018FCF0::CallMember(unsigned int name, void* params, void* script)
{
    switch (name) {
    case 0xCC12CF87:
        func_001E7EB0(params, 0, &m164, 1);
        if (func_001E8708(params, 0x019176C5) || func_001E8708(params, 0x4A07C332)) {
            m164 *= 1.0f / 60.0f;
        }
        break;
    case 0xCD5BA67B:
        func_00190E50(this);
        break;
    case 0xAE24DF9F: {
        Vec_0018FCF0 v;
        if (func_001E7FA8(params, 0x0C4C809E, &v, 0)) {
            Target_0018FCF0* t = mC;
            mF0 += v;
            t->mB0 = mF0;
        }
        if (func_001E7FA8(params, 0xFB1A83B2, &v, 0)) {
            m110 += v;
        }
        if (func_001E7FA8(params, 0x7F261953, &v, 0)) {
            Target_0018FCF0* t = mC;
            mE0 += v;
            t->m50 = mE0;
        }
        func_00190E28(this);
        break;
    }
    case 0x92F5DB9A:
        V2(params);
        break;
    case 0x0A2BBB3A:
        mB4 |= 2;
        break;
    case 0x49F44585:
        mB4 &= ~2;
        break;
    case 0x949BE8A9: {
        Vec_0018FCF0& vel = mF0;
        Src_0018FCF0* obj = func_00187B48(D_0038C608, func_001E6E90(params, 0)->m8);
        int rnd = func_001E8708(params, 0x8ACE8A0F);
        vel = obj->mB0;
        if (rnd) {
            vel *= func_001000D0(0.4f) + 1.0f;
        }
        mC->mB0 = mF0;
        if (!mD4 && __builtin_fabsf(mF0.y) < 1.0f) {
            mF0.y = 1.0f;
        }
        Src2_0018FCF0* c = func_00185578(obj, 0xFFB39248);
        if (c) {
            Vec_0018FCF0& rot = m110;
            rot = c->m110;
            if (rnd) {
                rot *= func_001000D0(0.4f);
            }
        }
        func_00190E28(this);
        break;
    }
    case 0x9599C10F:
        func_00190E28(this);
        break;
    default:
        return 2;
    }
    return 1;
}
