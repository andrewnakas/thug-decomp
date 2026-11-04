struct Obj_00293928;
extern "C" void func_002938A0(Obj_00293928* o, unsigned char v);

struct Obj_00293928 {
    char pad0[0x30C];
    unsigned char m30C[10];
    unsigned char m316;
    void Remove(unsigned char v);
};

void Obj_00293928::Remove(unsigned char v)
{
    func_002938A0(this, v);
    for (int i = 0; i < m316; i++) {
        if (v < m30C[i])
            m30C[i]--;
    }
}
