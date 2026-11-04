struct Blend {
    char pad[0x1C];
    int m1C;
    int m20;
    float m24;
    int m28;
    int m2C;
};

struct Owner {
    char pad[0x95C];
    int m95C;
};

struct Ctrl {
    char pad[0x20];
    int m20;
    char pad2[0xA4 - 0x24];
    Blend* mA4;
    char pad3[0xB4 - 0xA8];
    Owner* mB4;
    void Activate();
};

void Ctrl::Activate()
{
    m20 = 1;
    mB4->m95C = 1;
    mA4->m2C = 0;
    mA4->m28 = 0;
    mA4->m24 = 1.0f;
    mA4->m1C = 0;
}
