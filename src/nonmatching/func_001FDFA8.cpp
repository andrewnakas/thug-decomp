/* cflags: -mno-split-addresses */
/* fuzzy: 96.4 */
/* sym: dpmul = 0x0033E220 */
/* sym: dptoli = 0x0033E8E8 */
extern "C" double func_0010FAC8();
extern const double D_00366AD8[];
extern "C" void func_001FDBA8(void* p);
extern "C" void func_0031BCE0(int sema);
extern "C" void func_0031BCC0(int sema);
extern "C" void func_0031BBD0(int thread);

struct State_001FDFA8 {
    int m0;
    char pad4[0x4294 - 0x4];
    int m4294;
    int m4298;
    char pad429C[0x4350 - 0x429C];
    double m4350;
};

struct Owner_001FDFA8 {
    char pad0[0x20];
    State_001FDFA8* m20;
    void Tick();
};

void Owner_001FDFA8::Tick()
{
    State_001FDFA8* s = m20;
    s->m4350 = s->m4350 + func_0010FAC8() * D_00366AD8[0];
    s->m0 = (int)s->m4350;
    func_001FDBA8(s);
    func_0031BCE0(s->m4298);
    func_0031BCC0(s->m4298);
    func_0031BBD0(s->m4294);
}
