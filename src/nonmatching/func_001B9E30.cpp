/* fuzzy: 88.0 */
struct Sub_001B9E30 {
    char pad[0x1C];
    int m1C;
    int m20;
    char pad24[0x40 - 0x24];
    int m40;
    char pad44[0x64 - 0x44];
    int m64;
    char pad68[0xAC - 0x68];
    int mAC;
    char padB0[0x150 - 0xB0];
    int m150;
    int Check()
    {
        if (m1C == 3 || (m40 && !m64 && !mAC))
            return 1;
        return m150 != 0;
    }
};

struct Obj_001B9E30 {
    char pad[0x168];
    void* m168;
    Sub_001B9E30* m16C;
    int Method();
};

int Obj_001B9E30::Method()
{
    if (!m168)
        return 0;
    if (m16C->m20)
        return 0;
    return m16C->Check();
}
