extern "C" unsigned int func_0010FC30();

struct Obj_001AE910 {
    char pad[0x12AC];
    int m12AC;
    char pad4784[0x12B8 - 0x12AC - 4];
    unsigned int m12B8;
    unsigned int m12BC;
    void Method();
};

void Obj_001AE910::Method()
{
    if (m12AC && m12BC != 0xFFFFFFFF) {
        unsigned int start = m12B8;
        if (func_0010FC30() - start > m12BC)
            m12AC = 0;
    }
}
