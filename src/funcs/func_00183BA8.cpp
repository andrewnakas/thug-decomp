extern "C" void* func_003315B8(void* d, int c, int n);

class Pad_00183BA8 {
public:
    char m0;
    char m1[0x19];
    char pad1A[0x1C - 0x1A];
    unsigned int m1C;
    char pad20[0x28 - 0x20];
    int m28;
    int m2C;
    int m30;
    Pad_00183BA8();
};

Pad_00183BA8::Pad_00183BA8()
{
    func_003315B8(m1, 0, 0x19);
    m1C = 0;
    m2C = 0;
    m28 = 0;
    m30 = 0;
}
