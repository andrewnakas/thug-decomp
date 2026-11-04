
extern int D_0038DB38;

struct Base_0025AC10 {
    char m_pad[0x14];
};

struct Anim_0025AC10 : Base_0025AC10 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    bool InitFromStructure(void* params);
};

extern "C" void func_0025A9A8(Anim_0025AC10* self, void* params);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" unsigned int func_0025AB70(Anim_0025AC10* self);
extern "C" void* func_001D0638(int mgr, unsigned int id, int a);
extern "C" void func_0025AD48(Anim_0025AC10* self, void* anim, bool a, bool b);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_0025ADB8(Anim_0025AC10* self, float t);
extern "C" int func_0025AB50(Anim_0025AC10* self, int a);

bool Anim_0025AC10::InitFromStructure(void* params)
{
    func_0025A9A8(this, params);
    if (!func_001E8708(params, 0xEE721991)) {
        int mgr = D_0038DB38;
        void* anim = func_001D0638(mgr, func_0025AB70(this), 0);
        if (!anim)
            return false;
        bool a = func_001E8708(params, 0x5EA0E211) != 0;
        func_0025AD48(this, anim, a, func_001E8708(params, 0xF8CFD515));
    } else {
        int frames = 0;
        func_001E7DE8(params, 0x019176C5, &frames, 1);
        func_0025ADB8(this, (float)frames * (1.0f / 60.0f));
    }
    func_0025AB50(this, 1);
    V3();
    return true;
}
