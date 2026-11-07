/* fuzzy: 94.7 */
struct Obj_002A7A08 {
    char pad0[0x1A4];
    void* m1A4;
};

extern void* D_0038EB78;
extern Obj_002A7A08* D_00392068;

extern "C" int func_001FA698(void* p);
extern "C" int func_001FA6A8(void* p);
extern "C" void func_001FA6A0(void* p, int v);
extern "C" void func_001F0210(void* p, int a, int b, int c, int d);
extern "C" void func_002A7918(Obj_002A7A08* p);
extern "C" void func_002A7AF0(Obj_002A7A08* p, int v);

void func_002A7A08()
{
    void* q = D_0038EB78;
    int st = func_001FA698(q);
    Obj_002A7A08* p = D_00392068;
    switch (st) {
    case 7:
        if (func_001FA6A8(q) == 3) {
            goto done;
        }
    case 0:
    case 1:
        func_002A7918(p);
        func_002A7AF0(p, 0);
        break;
    done:
        func_001F0210(p->m1A4, 0, 0, 0, 0);
        func_002A7918(p);
        break;
    case 5:
        func_002A7918(p);
        func_001F0210(p->m1A4, 0, 0, 0, 0);
        break;
    case 2:
        func_001FA6A0(q, 6);
        break;
    case 3:
    case 4:
    case 6:
        break;
    }
}
