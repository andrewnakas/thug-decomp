typedef int qword_001DEB18 __attribute__((mode(TI)));

struct Vec_001DEB18 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_001DEB18 q;
    };
};

struct Ctx_001DEB18 {
    char pad[0x20];
};

struct Params_001DEB18 {
    float m0;
    float m4;
    float m8;
    int mC;
};

struct Sound_001DEB18 {
    char pad[0x10];
    float m10;
};

struct Obj_001DEB18 {
    char pad[0xA0];
    Vec_001DEB18 mA0;
};

extern int D_0038881C;

extern "C" bool func_001DC418();
extern "C" Sound_001DEB18* func_001DCA18(void*, void*);
extern "C" void func_001DC540(Ctx_001DEB18*);
extern "C" void* func_0013B108(Vec_001DEB18*, int);
extern "C" int func_001A35B0(Obj_001DEB18*, void*, Vec_001DEB18*);
extern "C" void func_001A34D0(Vec_001DEB18*, Obj_001DEB18*, void*);
extern "C" int func_001DDB00(void*, Ctx_001DEB18*, Vec_001DEB18*, int, void*, Vec_001DEB18*, float);
extern "C" void func_001DC6D0(Ctx_001DEB18*);
extern "C" int func_001DC658(Ctx_001DEB18*);
extern "C" void func_001DC578(Ctx_001DEB18*, int);
extern "C" void func_001DC5A8(Ctx_001DEB18*, float);
extern "C" int func_001DD290(void*, void*, Ctx_001DEB18*, int, float, Params_001DEB18*, int);
extern "C" void func_001E53A0(unsigned int, int);
extern "C" void func_001DCFB0(void*, int, void*, Obj_001DEB18*);

int func_001DEB18(void* mgr, void* id, Params_001DEB18* params, Obj_001DEB18* obj, int quiet)
{
    if (func_001DC418())
        return 0;
    Sound_001DEB18* snd = func_001DCA18(mgr, id);
    if (!snd)
        return 0;
    Ctx_001DEB18 ctx;
    func_001DC540(&ctx);
    Vec_001DEB18 pos = obj->mA0;
    void* near = func_0013B108(&pos, 0);
    if (near) {
        Vec_001DEB18* pp = 0;
        if (func_001A35B0(obj, near, &pos))
            pp = &pos;
        Vec_001DEB18 dir;
        func_001A34D0(&dir, obj, near);
        float vol;
        if (params->m8 != 0.0f)
            vol = params->m8;
        else
            vol = snd->m10;
        func_001DDB00(mgr, &ctx, &dir, params->mC, near, pp, vol);
    } else {
        func_001DC6D0(&ctx);
    }
    if (func_001DC658(&ctx) && quiet) {
        func_001DC578(&ctx, 2);
        return 0;
    }
    func_001DC5A8(&ctx, params->m4);
    int r = func_001DD290(mgr, id, &ctx, 0, params->m0, params, 0);
    if (!D_0038881C)
        func_001E53A0(0x6D2E270E, 0);
    if (!quiet) {
        func_001DCFB0(mgr, r, id, obj);
        if (!D_0038881C)
            func_001E53A0(0x6D2E270E, 0);
    }
    func_001DC578(&ctx, 2);
    return r;
}
