class Elem_0012BA50;
extern "C" void func_00184000(Elem_0012BA50* self, unsigned int name, int v);
extern "C" void func_00183FB0(Elem_0012BA50* self, unsigned int name, int v);

class Elem_0012BA50 {
public:
    char pad0[0x1A0];
    int m1A0;
    int m1A4;
    char pad1A8[0x1D0 - 0x1A8];
    int m1D0;
    void Publish();
};

void Elem_0012BA50::Publish()
{
    func_00184000(this, 0xAC988EBE, m1A4);
    func_00183FB0(this, 0xF2239871, m1A0);
    func_00183FB0(this, 0x8321DD71, m1D0);
}
