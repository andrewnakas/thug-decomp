class Anim_0011D0C0 {
public:
    int m_pad[5];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3(unsigned int anim, float start, float end, int loop, float blend, float speed);
};

struct Comp_0011D0C0 {
    char pad0[0x18];
    Anim_0011D0C0* m_anim;
    void* m_1C;
    unsigned int m_20;
};

extern "C" void func_0011ABE0(Comp_0011D0C0* self, void* params);
extern "C" int func_001E8398(void* s, unsigned int name, unsigned int* out, int);
extern "C" int func_001E7EB0(void* s, unsigned int name, float* out, int);
extern "C" void* func_0011AC30(Comp_0011D0C0* self);
extern "C" void* func_00185578(void* obj, unsigned int crc);
extern "C" float func_001A0AB0(void* comp, unsigned int anim);
extern "C" void func_00131430(float* start, float* end, void* params, int, float blend, float dur);
extern "C" void func_001313B0(int* loop, void* params);
extern "C" void func_001197A8(Anim_0011D0C0* a, float blend);
extern "C" void func_00144CE8(void* p, unsigned int id);

extern "C" void func_0011D0C0(Comp_0011D0C0* self, void* params)
{
    unsigned int anim;
    float start;
    float end;
    int loop;
    float speed;
    float blend;
    func_0011ABE0(self, params);
    func_001E8398(params, 0x6C2BFB7F, &anim, 1);
    start = 0.0f;
    end = 0.0f;
    blend = 0.0f;
    float dur = func_001A0AB0(func_00185578(func_0011AC30(self), 0x72AD7B23), anim);
    func_00131430(&start, &end, params, 0, blend, dur);
    func_001313B0(&loop, params);
    speed = 1.0f;
    func_001E7EB0(params, 0xF0D90109, &speed, 0);
    func_001E7EB0(params, 0x230CCBF4, &blend, 0);
    self->m_anim->V3(anim, start, end, loop, 0.0f, speed);
    if (blend != 0.0f) {
        func_001197A8(self->m_anim, blend);
    }
    func_00144CE8(self->m_1C, self->m_20 + anim);
}
