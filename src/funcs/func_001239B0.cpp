struct Obj1239B0 {
    char pad[0x16C];
    float m16C;
    char pad2[0x188 - 0x170];
    float m188;
    float Product() const;
};

float Obj1239B0::Product() const
{
    float b = m16C;
    return m188 * b;
}
