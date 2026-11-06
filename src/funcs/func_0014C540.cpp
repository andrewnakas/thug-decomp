struct Pod_0014C540 {
    unsigned char r, g, b, a;
};

struct Col_0014C540 {
    Pod_0014C540 c;
    Col_0014C540(const Pod_0014C540& p) : c(p) {}
    Col_0014C540(const Col_0014C540& o);
};

extern "C" unsigned int func_001707A0(void* p);

struct Scrn_0014C540 {
    char pad[0x290];
    void* m290;
};

Col_0014C540 GetColor_0014C540(Scrn_0014C540* s)
{
    unsigned int v = func_001707A0(s->m290);
    return Col_0014C540(*(Pod_0014C540*)&v);
}
