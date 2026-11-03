struct Pair1239D0 {
    char pad[0x20];
    float a;
    float b;
};

struct Obj1239D0 {
    char pad[0xD0];
    Pair1239D0 m;
    void Get(float* pa, float* pb) const;
};

void Obj1239D0::Get(float* pa, float* pb) const
{
    const Pair1239D0* p = &m;
    *pa = p->a;
    *pb = p->b;
}
