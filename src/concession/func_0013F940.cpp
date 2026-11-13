/* force: {"kind": "ga", "before": [134, 149]} */
/* blocked: global-alloc priority difference (p 2.50 < j 2.67, self 2.56; ga p-before-j forced = MATCH) (oracle) */
struct Part_0013F940 {
    float x, y, z;
    float vx, vy, vz;
    char pad18[0x10];
    float m28;
    float m2C;
};

struct Glob_0013F940 {
    char pad[0x38];
    int m38;
};

struct Base_0013F940 {
    int m0;
    int m4;
    virtual ~Base_0013F940();
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
    virtual void V11();
    virtual void GetPoint(int part, int idx, float* x, float* y, float* z);
    virtual void SetPoint(int part, int idx, float x, float y, float z);
    virtual void SetHead(int part, int idx, float x, float y, float z);
    virtual int GetCount();
};

struct Trail_0013F940 : Base_0013F940 {
    char padC[0x168 - 0xC];
    int m168;
    char pad16C[0x1C8 - 0x16C];
    int m1C8;
    Part_0013F940* m1CC;
    void* m1D0;
    void* m1D4;
    char pad1D8[0x10];
    int m1E8;
};

extern Glob_0013F940* D_00390828;
extern "C" void* func_00185578(void* o, unsigned int name);
extern "C" int func_001A9E60(void* o);
extern "C" void func_001EFDC0(void* o);

extern "C" void func_0013F940(Trail_0013F940* self, float dt)
{
    if (self->m1C8 && !self->m168) {
        delete self;
        return;
    }
    if (D_00390828->m38)
        return;
    if (func_001A9E60(func_00185578(self, 0xCE0CA665)))
        return;
    if (self->m1D4)
        func_001EFDC0(self->m1D4);
    if (self->m1D0)
        func_001EFDC0(self->m1D0);
    if (!self->m1E8)
        return;
    Part_0013F940* p = self->m1CC;
    int i;
    for (i = 0; i < self->m168; i++, p++) {
        p->m28 += dt;
        p->x += p->vx;
        p->y += p->vy;
        p->z += p->vz;
        for (int j = self->GetCount() - 1; j > 0;) {
            float x, y, z;
            int prev = j - 1;
            self->GetPoint(i, prev, &x, &y, &z);
            self->SetPoint(i, j, x, y, z);
            j = prev;
        }
        self->SetHead(i, 0, p->x, p->y, p->z);
    }
    Part_0013F940* q = self->m1CC;
    for (i = 0; i < self->m168; i++, q++) {
        if (q->m28 > q->m2C) {
            self->m168--;
            *q = self->m1CC[self->m168];
            q--;
            for (int k = 0; k < self->GetCount(); k++) {
                float x, y, z;
                self->GetPoint(self->m168, k, &x, &y, &z);
                self->SetPoint(i, k, x, y, z);
                self->SetPoint(self->m168, k, 1024.0f, 1024.0f, 1024.0f);
            }
            i--;
        }
    }
}
