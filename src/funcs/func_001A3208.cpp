extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E7E58(void* params, const char* name, int* out, int req);
extern "C" int func_001E8618(void* params, unsigned int name);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" int func_001DC428(unsigned int id);
extern "C" int func_0026C3E0(unsigned int id);
extern char D_0038CC30[];

struct Base_001A3208 {
    int m_pad[6];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void Start(unsigned int anim, float from, float to);
};

struct C_001A3208 : Base_001A3208 {
    unsigned int m1C[9];
    int m40[32];
    int mC0;
    void Play(unsigned int anim, int a, int b, float from, float to, float blend);
    void Run(void* params);
};

void C_001A3208::Run(void* params)
{
    unsigned int anim = 0;
    unsigned int tree = 0;
    int s = 0;
    float from = 100.0f;
    float to = 100.0f;
    float blend = 0.0f;
    unsigned int skel;
    func_001E8398(params, 0, &anim, 0);
    func_001E7EB0(params, 0xF6A36814, &from, 0);
    func_001E7EB0(params, 0xD8604126, &to, 0);
    if (func_001E8618(params, 0x9E497FC6)) {
        float from1 = 100.0f;
        float from0 = 0.0f;
        float to0 = 100.0f;
        float to1 = 100.0f;
        float t;
        func_001E7EB0(params, 0x0693DAAF, &from1, 0);
        func_001E7EB0(params, 0x4391992D, &from0, 0);
        func_001E7EB0(params, 0xFA3E14C5, &to1, 0);
        func_001E7EB0(params, 0x1C5EBB24, &to0, 0);
        func_001E7EB0(params, 0x9E497FC6, &t, 1);
        t *= 0.01f;
        from = from0 + (from1 - from0) * t;
        to = to0 + (to1 - to0) * t;
    }
    if (func_001E7EB0(params, 0xFF2020EC, &blend, 0)) blend *= 12.0f;
    if (func_001E8398(params, 0x0C6AC50A, &skel, 0)) s = func_001DC428(skel);
    int loop = func_001E8708(params, 0xBB39837F) != 0;
    if (func_001E8398(params, 0x8A7132CE, &tree, 0))
        mC0 = func_0026C3E0(tree);
    else
        mC0 = 0;
    if (!anim) {
        int idx = -1;
        func_001E7E58(params, D_0038CC30, &idx, 0);
        if (idx == -1 || idx >= 9) return;
        anim = m1C[idx];
        if (!anim) return;
    }
    Start(anim, from, to);
    Play(anim, s, loop, from, to, blend);
}
