struct Obj_002951A0 {
    char pad0[0x160];
    float m160;
    float m164;
    float m168;
    char pad16C[0x2A1 - 0x16C];
    unsigned char m2A1;
    bool Outside(float x0, float z0, float x1, float z1);
};

bool Obj_002951A0::Outside(float x0, float z0, float x1, float z1)
{
    if (m2A1 >= 2) {
        float x = m160;
        float z = m168;
        if (x < x0 || x1 < x || z < z0 || z1 < z)
            return true;
    }
    return false;
}
