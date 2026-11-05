struct Obj_0011A080;
extern "C" int func_0011A210(Obj_0011A080* self);
extern "C" void func_0011A218(Obj_0011A080* self, int state);

struct Obj_0011A080 {
    char pad[0x54];
    float m_rate;
    int SetRate(float rate);
};

int Obj_0011A080::SetRate(float rate)
{
    if (rate == 0.0f) {
        func_0011A218(this, 0);
    }
    if (func_0011A210(this) == 2) {
        func_0011A218(this, 1);
        m_rate = rate;
        return 1;
    }
    return 0;
}
