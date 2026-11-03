struct Obj1239C0 {
    char pad[0x170];
    float m170;
    char pad2[0x18C - 0x174];
    float m18C;
    float Product() const;
};

float Obj1239C0::Product() const
{
    float b = m170;
    return m18C * b;
}
