struct Obj_0026B460 {
    char pad[0x58];
    unsigned int m58;
    void Clear(int bit);
};

void Obj_0026B460::Clear(int bit)
{
    m58 &= ~(1 << bit);
}
