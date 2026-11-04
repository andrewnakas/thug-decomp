struct Body_00278558 {
    char pad0[0x18];
    unsigned int m18;
};

struct Obj_00278558 {
    char pad0[0xC];
    Body_00278558* mC;
    char pad10[0xC];
    unsigned int m1C;
    void SetAnim();
};

void Obj_00278558::SetAnim()
{
    switch (mC->m18) {
    case 0: m1C = 0xE797A186; break;
    case 1: m1C = 0x90909110; break;
    case 2: m1C = 0x0999C0AA; break;
    case 3: m1C = 0x7E9EF03C; break;
    case 4: m1C = 0xE0FA659F; break;
    case 5: m1C = 0x97FD5509; break;
    case 6: m1C = 0x0EF404B3; break;
    case 7: m1C = 0x79F33425; break;
    }
}
