typedef int qword __attribute__((mode(TI)));

struct Vec_001DCB18 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Pt_001DCB18 {
    float x, y, z, w;
};


struct Src_001DCB18 {
    char pad[0xA0];
    Vec_001DCB18 mA0;
};

struct Flags_001DCB18 {
    int m0;
    int m4;
    char pad[0x18 - 8];
    int m18;
};

struct Sub_001DCB18 {
    int m0;
    float m4;
    char pad[0x28 - 8];
    int m28;
    unsigned int m2C;
};

struct Req_001DCB18 {
    int m0;
    int m4;
    Flags_001DCB18* m8;
    Sub_001DCB18 mC;
};

struct Work_001DCB18 {
    char data[0x20];
};

extern float D_0038E0A8;
extern int D_0038881C;
extern "C" void* func_0013B108(Vec_001DCB18* v, float* dist);
extern "C" bool func_001A35B0(Src_001DCB18* s, void* o, Vec_001DCB18* v);
extern "C" void func_001A3990(Src_001DCB18* s, Sub_001DCB18* sub, unsigned int t);
extern "C" void func_001DC540(Work_001DCB18* w);
extern "C" void func_001DC6D0(Work_001DCB18* w);
extern "C" void func_001DC658(Work_001DCB18* w);
extern "C" void func_001DC578(Work_001DCB18* w, int flags);
extern "C" Pt_001DCB18 func_001A34D0(Src_001DCB18* s, void* o);
extern "C" Pt_001DCB18 func_001A3540(Src_001DCB18* s, void* o);
extern "C" float func_0010FAB8();
extern "C" void func_001DE8F0(void* self, float* f, const Pt_001DCB18& a, const Pt_001DCB18& b, void* o, float t);
extern "C" void func_001DDB00(void* self, Work_001DCB18* w, Pt_001DCB18* a, int n, float r, void* o, Vec_001DCB18* hit);
extern "C" bool func_001E53A0(unsigned int name, int a);
extern "C" int func_001DD7C8(void* self, int id, Work_001DCB18* w, float f);

int Run_001DCB18(void* self, Src_001DCB18* src, Req_001DCB18* req, unsigned int time)
{
    Sub_001DCB18* sub = &req->mC;
    float r = sub->m4 == 0.0f ? D_0038E0A8 : sub->m4;
    Vec_001DCB18 v = src->mA0;
    Work_001DCB18 w;
    float dist;
    float f;
    Vec_001DCB18* hit;
    void* o = func_0013B108(&v, &dist);
    if (!o) return 1;
    hit = 0;
    if (func_001A35B0(src, o, &v)) {
        hit = &v;
    } else if (time >= sub->m2C) {
        if (r + 480.0f <= dist) {
            if (req->m8->m18) func_001A3990(src, sub, time);
            return 0;
        }
        sub->m2C = time + 2000;
    }
    f = 100.0f;
    func_001DC540(&w);
    func_001DC6D0(&w);
    if (hit || dist < r) {
        Pt_001DCB18 a = func_001A34D0(src, o);
        if (req->m8->m4 & 4) {
            func_001DE8F0(self, &f, a, func_001A3540(src, o), o, func_0010FAB8());
        }
        func_001DDB00(self, &w, &a, sub->m28, r, o, hit);
    }
    if (!D_0038881C && func_001E53A0(0x6D2E270E, 0)) func_001DC658(&w);
    int ret = func_001DD7C8(self, req->m0, &w, f);
    func_001DC578(&w, 2);
    return ret;
}
