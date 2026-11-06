/* fuzzy: 62.1 */
typedef int qword_001D8170 __attribute__((mode(TI)));

extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" void* func_00331404(void*, const void*, unsigned int);

struct Mesh_001D8170 {
    int m0;
    unsigned short m4;
    unsigned short m6;
    unsigned short m8;
    unsigned char mA;
    unsigned char mB;
    void* mC;
    qword_001D8170 m10;
    qword_001D8170 m20;
    void* m30;
    void* m34;
    void* m38;
    int m3C;
};

extern "C" void* func_001D7770(void*, int);

Mesh_001D8170* func_001D8170(Mesh_001D8170* src, int arg, int check)
{
    if (check && src->m6 == 0)
        return 0;
    Mesh_001D8170* d = (Mesh_001D8170*)func_0010A638(D_00388A70, 0x40, 1, 0);
    d->m0 = src->m0;
    d->m4 = src->m4;
    d->m6 = src->m6;
    d->m8 = src->m8;
    d->mA = src->mA;
    d->mB = src->mB;
    d->m10 = src->m10;
    d->m20 = src->m20;
    d->m34 = src->m34;
    d->m38 = src->m38;
    d->m3C = src->m3C;
    d->mC = src->mC;
    d->m30 = src->m30;
    d->m30 = func_0010A638(D_00388A70, src->m6 * (src->mB ? 6 : 12), 1, 0);
    unsigned int n = src->m6;
    d->mC = func_0010A638(D_00388A70, src->mA ? src->m8 * 8 : src->m8 * 10, 1, 0);
    if (!d->m30)
        return 0;
    if (!d->mC)
        return 0;
    func_00331404(d->m30, src->m30, src->m6 * (src->mB ? 6 : 12));
    func_00331404(d->mC, src->mC, src->mA ? src->m8 * 8 : src->m8 * 10);
    if (src->m38) {
        d->m38 = func_0010A638(D_00388A70, n, 1, 0);
        func_00331404(d->m38, src->m38, n);
    }
    d->m34 = func_001D7770(src->m34, arg);
    return d;
}
