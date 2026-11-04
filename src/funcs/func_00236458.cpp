/* sym: __14ListA_00236458i = 0x0023AE70 */
/* sym: __14ListB_00236458ii = 0x0023AF30 */
/* sym: __14Entry_00236458 = 0x001E4C80 */
struct ListA_00236458 {
    char m_pad[0x18];
    ListA_00236458(int n);
};

struct ListB_00236458 {
    char m_pad[0x14];
    ListB_00236458(int a, int b);
};

struct Slot_00236458 {
    int m0;
    Slot_00236458() {}
};

struct Entry_00236458 {
    char m_pad[0xC];
    Entry_00236458();
};

extern char D_00373398[];
extern "C" void func_0023AC30(void* self, int a);
extern "C" int func_001E5400(const char* name, int a);
extern "C" void func_00238920(void* self);

struct Obj_00236458 {
    short m0;
    unsigned short m2;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    ListA_00236458 m2C;
    ListB_00236458 m44;
    int m58;
    int m5C;
    int m60;
    int m64;
    int m68;
    Slot_00236458 m6C[3];
    int m78;
    int m7C;
    int m80;
    int m84;
    int m88;
    Entry_00236458 m8C[20];
    int m17C;
    Entry_00236458 m180;
    int m18C;
    Entry_00236458 m190[2];
    Obj_00236458();
};

Obj_00236458::Obj_00236458() : m2C(0x10), m44(8, 8)
{
    m2 = 0;
    m4 = 0;
    mC = 0;
    m18 = 0;
    m1C = 0;
    m58 = 0;
    m5C = 0;
    m60 = -1;
    m64 = -1;
    m68 = 0;
    func_0023AC30(this, 0);
    m7C = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m84 = func_001E5400(D_00373398, 0) != 0;
    func_00238920(this);
}
