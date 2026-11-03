struct Sub1239E8 {
    char pad[0x2C];
    float m2C;
    float m30;
};

struct Obj1239E8 {
    char pad[0xD0];
    Sub1239E8 mD0;
    void Get(float* a, float* b);
};

void Obj1239E8::Get(float* a, float* b)
{
    Sub1239E8* s = &mD0;
    *a = s->m2C;
    *b = s->m30;
}
