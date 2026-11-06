struct Comp_001A1AE8;

struct Obj_001A1AE8 {
    char pad0[0x34];
    int m34;
    float m38;
    char pad3C[0x40 - 0x3C];
    int m40;
    int m44;
    char pad48[0x50 - 0x48];
    float m50;
};

extern "C" Comp_001A1AE8* func_001A0718(Obj_001A1AE8* p);
extern "C" float func_00119768(Comp_001A1AE8* c);
extern "C" int func_001A0D78(Obj_001A1AE8* p);
extern "C" int func_001E8398(void* params, unsigned int id, void* out, int req);
extern "C" int func_001E93D0(void* params, int a);
extern "C" int func_001E7EB0(void* params, unsigned int id, float* out, int req);
extern "C" unsigned int func_001A0E08(Obj_001A1AE8* p);
extern "C" int func_001E8708(void* params, unsigned int id);
extern "C" int func_001A0AD0(Obj_001A1AE8* p, unsigned int name);
extern "C" float func_001A0AB0(Obj_001A1AE8* p, unsigned int name);
extern "C" void func_001A0E50(Obj_001A1AE8* p, float* x, float* y, float* z);
extern "C" void func_00131430(float* a, float* b, void* params, float c, float d, void* script);
extern "C" void func_001313B0(int* out, void* params);
extern "C" void func_001A0F78(Obj_001A1AE8* self, unsigned int name, int send, float a, float b, int k, float c, float d);
extern "C" void func_001197A8(Comp_001A1AE8* c, float v);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int v);
extern "C" void func_001E72B0(void* s, unsigned int name, float v);
extern "C" void func_00119A70(Comp_001A1AE8* c, void* s);
extern "C" void func_001E6AE8(void* s, int flags);

extern "C" unsigned int func_001A1AE8(Obj_001A1AE8* self, void* params, void* script, float f)
{
    Comp_001A1AE8* c = func_001A0718(self);
    if (c) {
        self->m50 = func_00119768(c);
    }
    if (self->m40 && !func_001A0D78(self)) {
        return 0;
    }
    if (!self->m44) {
        return 0;
    }
    unsigned int name = 0;
    func_001E8398(params, 0x98549BA4, &name, 0);
    if (!name) {
        func_001E93D0(params, 0);
    }
    float blend = 1.0f;
    func_001E7EB0(params, 0xF0D90109, &blend, 0);
    unsigned int cur = func_001A0E08(self);
    if (name == 0x230CCBF4) {
        name = cur;
    } else if (cur == name && func_001E8708(params, 0xFE09FE09)) {
        return 0;
    }
    if (!func_001A0AD0(self, name)) {
        name = 0x1CA1FF20;
    }
    float period = f;
    float pct = 0.0f;
    if (self->m34) {
        period = self->m38;
        self->m34 = 0;
    } else if (func_001E7EB0(params, 0x4F3ABD6C, &pct, 0)) {
        float x = func_001A0AB0(self, name) * 0.01f;
        period = x * pct;
    } else {
        func_001E7EB0(params, 0x8F0D24ED, &period, 0);
    }
    float len = func_001A0AB0(self, name);
    float start = 0.0f;
    float end = len;
    float t = 0.0f;
    if (func_001E8708(params, 0x099371AE)) {
        float a;
        float b;
        func_001A0E50(self, &a, &b, &a);
        float d = func_001A0AB0(self, cur);
        func_001E7EB0(params, 0x4B4A153A, &d, 0);
        float r = b / func_001A0AB0(self, cur);
        if (r > 1.0f) {
            r = 1.0f;
        }
        if (r < t) {
            r = t;
        }
        t = r * len;
        if (func_001E8708(params, 0xF8CFD515)) {
            t -= len;
        }
    } else if (func_001E8708(params, 0xFF5AC79E)) {
        float a;
        float b;
        func_001A0E50(self, &a, &b, &a);
        float d = func_001A0AB0(self, cur);
        func_001E7EB0(params, 0x4B4A153A, &d, 0);
        float r = (d - b) / d;
        if (r > 1.0f) {
            r = 1.0f;
        }
        if (r < t) {
            r = t;
        }
        t = r * len;
        if (func_001E8708(params, 0xF8CFD515)) {
            t -= len;
        }
    }
    float p;
    float q;
    func_001A0E50(self, &p, &q, &p);
    func_00131430(&start, &end, params, q, len, script);
    int mode;
    func_001313B0(&mode, params);
    self->m40 = func_001E8708(params, 0x84F13067);
    func_001A0F78(self, name, 1, start, end, mode, period, blend);
    if (t != 0.0f) {
        func_001197A8(func_001A0718(self), t);
    }
    unsigned int cb;
    if (!func_001E8398(params, 0x6C565F57, &cb, 0)) {
        return name;
    }
    void* s = func_001E6978(func_001190D0(8));
    unsigned int arg;
    if (func_001E8398(params, 0xF0CE9E0F, &arg, 0)) {
        func_001E7360(s, 0x40C698AF, arg);
    }
    func_001E7360(s, 0x7321A8D6, 0x659BF355);
    func_001E7360(s, 0x6C2BFB7F, cb);
    func_001E72B0(s, 0x46E55E8F, start);
    func_001E72B0(s, 0x28782D3B, end);
    func_001E7360(s, 0, 0xD029F619);
    func_001E72B0(s, 0x230CCBF4, t);
    func_001E72B0(s, 0xF0D90109, blend);
    switch (mode) {
    case 0:
        break;
    case 1:
        func_001E7360(s, 0, 0x4F792E6C);
        break;
    case 2:
        func_001E7360(s, 0, 0x3153E314);
        break;
    case 3:
        func_001E7360(s, 0, 0x6D941203);
        break;
    }
    func_00119A70(func_001A0718(self), s);
    if (s) {
        func_001E6AE8(s, 3);
    }
    return name;
}
