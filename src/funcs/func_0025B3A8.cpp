
extern int D_0038DB38;

struct VSlot_0025B3A8 {
    short m_delta;
    short m_pad;
    int (*m_fn)(void*);
};

struct Anim_0025B3A8 {
    char m_pad[0x14];
    VSlot_0025B3A8* m_vtbl;
    char m_pad2[0x7C - 0x18];
    char m_7C[0x10];
    bool InitFromStructure(void* params);
};

extern "C" void func_0025A9A8(Anim_0025B3A8* self, void* params);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" unsigned int func_0025AB70(Anim_0025B3A8* self);
extern "C" void* func_001D0638(int mgr, unsigned int id, int a);
extern "C" void func_0025B648(Anim_0025B3A8* self, void* anim, bool a, bool b);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_0025B538(Anim_0025B3A8* self, void* params);
extern "C" void func_0025B828(Anim_0025B3A8* self);
extern "C" float func_00119768(void* p);
extern "C" void func_0025B788(Anim_0025B3A8* self, int a, float x, float y);
extern "C" void func_0025B6B8(Anim_0025B3A8* self, float t);
extern "C" int func_0025AB50(Anim_0025B3A8* self, int a);

bool Anim_0025B3A8::InitFromStructure(void* params)
{
    func_0025A9A8(this, params);
    if (!func_001E8708(params, 0xEE721991)) {
        int mgr = D_0038DB38;
        void* anim = func_001D0638(mgr, func_0025AB70(this), 0);
        if (!anim)
            return false;
        bool a = func_001E8708(params, 0x5EA0E211) != 0;
        func_0025B648(this, anim, a, func_001E8708(params, 0xF8CFD515));
    } else {
        int frames = 0;
        func_001E7DE8(params, 0x019176C5, &frames, 1);
        func_0025B6B8(this, (float)frames * (1.0f / 60.0f));
    }
    func_0025AB50(this, 1);
    func_0025B538(this, params);
    VSlot_0025B3A8* s = &m_vtbl[4];
    s->m_fn((char*)this + s->m_delta);
    func_0025B828(this);
    float x = func_00119768(m_7C);
    func_0025B788(this, 1, x, func_00119768(m_7C));
    return true;
}
