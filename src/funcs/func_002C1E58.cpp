struct Cell_002C1E58 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Obj_002C1E58 {
    char pad0[0x3538];
    Cell_002C1E58** m3538;
    void Clamp();
};

void Obj_002C1E58::Clamp()
{
    for (int i = 0; i < 0x3A; i++) {
        for (int j = 0; j < 0x3A; j++) {
            if (m3538[i][j].m8) {
                m3538[i][j].m8 = 0;
                m3538[i][j].m0 -= m3538[i][j].mC;
            }
            if (m3538[i][j].m0 >= 16) m3538[i][j].m0 = 15;
            if (m3538[i][j].m0 < -16) m3538[i][j].m0 = -16;
        }
    }
}
