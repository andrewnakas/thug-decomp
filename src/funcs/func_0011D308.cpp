class AnimBase_0011D308 {
public:
    int m_pad[5];
    virtual void V0();
    virtual void V1();
    virtual void V2();
};

class Anim_0011D308 : public AnimBase_0011D308 {
public:
    float m_18;
    float m_time;
};

struct Comp_0011D308 {
    char pad0[0x18];
    Anim_0011D308* m_anim;
    void* m_1C;
};

class Struct_0011D308 {
public:
    void AddFloat(unsigned int name, float v);
    void AddInt(unsigned int name, int v);
    void AddChecksum(unsigned int name, int v);
};

struct Script_0011D308 {
    char pad0[0x18];
    Struct_0011D308* m_params;
};

extern "C" void func_00144CB0(void* p, int);
extern "C" float func_00119768(Anim_0011D308* a);
extern "C" int func_00119760(Anim_0011D308* a);
extern "C" int func_00119818(Anim_0011D308* a);
extern "C" int func_001E7EB0(void* s, unsigned int name, float* out, int);
extern "C" float func_00119890(Anim_0011D308* a);
extern "C" void func_00119880(Anim_0011D308* a, float speed);
extern "C" void func_001198A8(Anim_0011D308* a);

extern "C" int func_0011D308(Comp_0011D308* self, unsigned int crc, void* params, Script_0011D308* script)
{
    float speed;
    float delta;
    switch (crc) {
    case 0x5F495AE0:
        func_00144CB0(self->m_1C, 0);
        return 2;
    case 0xD63A1B81: {
        Struct_0011D308* p0 = script->m_params;
        p0->AddFloat(0xAAECB346, func_00119768(self->m_anim));
        Struct_0011D308* p1 = script->m_params;
        p1->AddInt(0x659BF355, func_00119760(self->m_anim));
        Struct_0011D308* p2 = script->m_params;
        p2->AddChecksum(0x4966CC11, func_00119818(self->m_anim));
        return 1;
    }
    case 0xBD4EDD44:
        func_001E7EB0(params, 0xF0D90109, &speed, 1);
        func_00119880(self->m_anim, speed);
        return 1;
    case 0x6AAEB76F: {
        func_001E7EB0(params, 0x06C9F278, &delta, 1);
        float old = func_00119890(self->m_anim);
        func_00119880(self->m_anim, 0.0f);
        self->m_anim->m_time += delta;
        self->m_anim->V2();
        func_00119880(self->m_anim, old);
        return 1;
    }
    case 0xF5E2B871:
        func_001198A8(self->m_anim);
        return 1;
    }
    return 2;
}
