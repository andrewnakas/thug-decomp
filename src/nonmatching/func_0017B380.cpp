/* fuzzy: 97.5 */
struct Pkt_0017B380 {
    Pkt_0017B380* next;
    int m4;
    int m8;
    int mC;
    unsigned int m10[2];
    unsigned int m18[2];
    char pad20[0x28 - 0x20];
    float m28[2];
};

extern Pkt_0017B380 D_003E26A0;
extern int D_00394094;
extern Pkt_0017B380* D_003942E8;
extern Pkt_0017B380* D_003942EC;
extern Pkt_0017B380* D_003942F4;
extern int D_0038BFF8;
extern int D_00393F30;
extern int D_00393F34;

extern "C" void func_0031BF20(int a);
extern "C" void func_003312D8(int a, int b);

extern "C" void func_0017B380()
{
    func_0031BF20(0);
    *(volatile int*)0x10009020 = 0;
    *(volatile unsigned int*)0x10009030 = D_003E26A0.m18[D_00394094 ? 0 : 1];
    *(volatile int*)0x10009000 = 0x145;
    func_003312D8(0, 0);
    D_003942EC = D_003942E8 = D_003942F4;
    if (D_0038BFF8) {
        Pkt_0017B380* p = D_003942E8;
        int i = 0;
        while (p->next) {
            i++;
            if (i >= 3 && i != D_0038BFF8) p->m28[D_00394094 ? 0 : 1] = 0.0f;
            p = p->next;
        }
    }
    D_00393F30 = 0;
    D_00393F34 = 1;
    func_0031BF20(0);
    *(volatile int*)0x1000A020 = 0;
    *(volatile unsigned int*)0x1000A030 = D_003942E8->m10[D_00394094 ? 0 : 1];
    *(volatile int*)0x1000A000 = 0x105;
}
