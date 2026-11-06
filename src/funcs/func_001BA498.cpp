typedef int qword_001BA498 __attribute__((mode(TI)));

struct Vec_001BA498 {
    union {
        qword_001BA498 q;
        struct {
            float x, y, z, w;
        };
    };
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct State_001BA498 {
    Vec_001BA498 r[4];
    Vec_001BA498 pos;
    float m50;
    float m54;
};

struct Obj_001BA498 {
    char pad[0x34];
    float m34;
    char pad38[8];
    Vec_001BA498 m40;
    Vec_001BA498 m50[3];
    char pad80[0x104 - 0x80];
    float m104;
    void Method(State_001BA498* s);
};

void Obj_001BA498::Method(State_001BA498* s)
{
    s->r[0] = m50[0];
    s->r[1] = m50[1];
    s->r[2] = m50[2];
    s->r[3].Set(0.0f, 0.0f, 0.0f, 1.0f);
    s->pos = m40;
    s->m50 = m34;
    s->m54 = m104;
}
