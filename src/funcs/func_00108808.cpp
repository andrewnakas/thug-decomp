/* sym: _$_12Tbl_00108808 = 0x00109FE0 */

extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);

struct Tbl_00108808 {
    int m0;
    ~Tbl_00108808();
};

struct Mgr_00108808 {
    char pad0[0x14];
    Tbl_00108808* m14;
    ~Mgr_00108808();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Mgr_00108808::~Mgr_00108808()
{
    if (m14) delete m14;
}
