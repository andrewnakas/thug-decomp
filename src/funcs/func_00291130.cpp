struct Pair_00291130 { int a, b; };

struct Obj_00291130 {
    char pad0[0x1C];
    unsigned int m1C;
    char pad1[0x80 - 0x20];
    Pair_00291130 m80;
    char pad2[0x100 - 0x88];
    Pair_00291130 m100;
    char pad3[0x180 - 0x108];
    Pair_00291130 m180;
    char pad4[0x200 - 0x188];
    Pair_00291130 m200;
    void Get(int* type, Pair_00291130* out);
};

void Obj_00291130::Get(int* type, Pair_00291130* out)
{
    switch (m1C) {
    case 0x0AC90769:
    case 0xEF24413B:
        *type = 2;
        out->a = m80.a;
        out->b = m80.b;
        break;
    case 0xA549B57B:
        *type = 2;
        out->a = m180.a;
        out->b = m180.b;
        break;
    case 0x255ED86F:
    case 0x8D10119D:
        *type = 2;
        out->a = m100.a;
        out->b = m100.b;
        break;
    case 0x3506CE64:
        *type = 2;
        out->a = m200.a;
        out->b = m200.b;
        break;
    default:
        *type = 0;
        break;
    }
}
