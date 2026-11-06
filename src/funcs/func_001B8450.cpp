typedef int qword_001B8450 __attribute__((mode(TI)));

struct Vec_001B8450 {
    qword_001B8450 q;
};

struct State_001B8450 {
    Vec_001B8450 r[4];
    Vec_001B8450 pos;
    float m50;
    float m54;
};

struct Sub_001B8450 {
    char pad[0x1C];
    int m1C;
    char pad20[0xC];
    int m2C;
};

struct Obj_001B8450 {
    char pad[0x30];
    int m30;
    float m34;
    char pad38[8];
    Vec_001B8450 m40;
    Vec_001B8450 m50[3];
    char pad80[0xD8 - 0x80];
    int mD8;
    char padDC[0x104 - 0xDC];
    float m104;
    char pad108[0x160 - 0x108];
    Sub_001B8450* m160;
    void Method(State_001B8450* s);
};

void Obj_001B8450::Method(State_001B8450* s)
{
    m50[0] = s->r[0];
    m50[1] = s->r[1];
    m50[2] = s->r[2];
    m40 = s->pos;
    m34 = s->m50;
    m104 = s->m54;
    mD8 = 0;
    m30 = 0;
    m160->m2C = 0;
    m160->m1C = 0;
}
