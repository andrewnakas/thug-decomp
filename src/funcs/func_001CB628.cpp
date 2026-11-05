typedef int qword_001CB628 __attribute__((mode(TI)));
union Vec_001CB628 {
    qword_001CB628 q;
    struct {
        float x, y, z, w;
    } f;
};
struct Obj_001CB628 {
    char pad[0x40];
    Vec_001CB628 m40;
    Vec_001CB628 m50;
    Vec_001CB628 m60;
    char pad2[0xC4 - 0x70];
    float mC4;
    char pad3[0xB70 - 0xC8];
    Vec_001CB628 mB70;
    char pad4[0xC44 - 0xB80];
    float mC44;
    void Reset();
};
extern "C" void func_001BF130(Obj_001CB628* self, int v);
extern "C" void func_001C4030(Obj_001CB628* self, Vec_001CB628* a, Vec_001CB628* b);

void Obj_001CB628::Reset()
{
    func_001BF130(this, 1);
    mB70 = m60;
    func_001C4030(this, &m40, &m50);
    mC4 = mC44;
}
