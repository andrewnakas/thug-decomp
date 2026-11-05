typedef int qword_001D55B8 __attribute__((mode(TI)));
union Vec_001D55B8 {
    qword_001D55B8 q;
    struct {
        float x, y, z, w;
    } f;
};
struct Mat_001D55B8 {
    Vec_001D55B8 r[4];
};
struct Obj_001D55B8 {
    char pad[0x10];
    Vec_001D55B8 m10;
    Vec_001D55B8 m20;
    Vec_001D55B8 m30;
    Vec_001D55B8 m40;
    char pad2[0xB0 - 0x50];
    char mB0[4];
    void Draw();
};
extern "C" void func_001024A8(void* p, Mat_001D55B8* m, unsigned int color, int n);

void Obj_001D55B8::Draw()
{
    Mat_001D55B8 m;
    m.r[0] = m20;
    m.r[1] = m30;
    m.r[2] = m40;
    m.r[3] = m10;
    func_001024A8(mB0, &m, 0x80808080, 1);
}
