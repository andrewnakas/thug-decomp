class Evt_00118158 {
public:
    int m0[5];
    virtual void V0();
    virtual int InRange(float from, float to, int dir);
};

class Track_00118158;
extern "C" int func_001180C8(Track_00118158* self);
extern "C" Evt_00118158* func_001180D0(Track_00118158* self, int i);
extern "C" void func_00118350(Evt_00118158* e, void* ctx);

class Track_00118158 {
public:
    int Fire(void* ctx, int dir, float from, float to);
};

int Track_00118158::Fire(void* ctx, int dir, float from, float to)
{
    float a = from * 60.0f;
    float b = to * 60.0f;
    int n = func_001180C8(this);
    for (int i = 0; i < n; i++) {
        Evt_00118158* e = func_001180D0(this, i);
        if (e->InRange(a, b, dir)) {
            func_00118350(e, ctx);
        }
    }
    return 1;
}
