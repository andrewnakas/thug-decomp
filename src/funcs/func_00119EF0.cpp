class Item_00119EF0 {
public:
    int m_pad[5];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
};

struct Blend_00119EF0 {
    char pad0[0x30];
    int m_30;
    int pad34[2];
    Item_00119EF0* m_items[4];
    int m_count;
    float m_rate;
    float m_weight;
    float m_sign;
};

extern "C" int func_0011A210(Blend_00119EF0* self);
extern "C" void func_0011A218(Blend_00119EF0* self, int state);
extern "C" float func_0010FAB8();

extern "C" void func_00119EF0(Blend_00119EF0* self)
{
    self->m_30 = 0;
    if (func_0011A210(self) == 1) {
        float dt = func_0010FAB8() * 60.0f;
        self->m_weight -= self->m_rate * dt;
        if (self->m_weight <= 0.0f) {
            func_0011A218(self, 0);
        } else if (self->m_weight * self->m_sign < 0.0f) {
            func_0011A218(self, 0);
        }
    }
    if (func_0011A210(self) == 2) {
        for (int i = 0; i < self->m_count; i++) {
            self->m_items[i]->V5();
        }
    }
}
