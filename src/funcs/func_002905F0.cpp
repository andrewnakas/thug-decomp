struct Obj_002905F0 {
    char pad0[0x1C];
    int m1C;
    int Cmd(unsigned int id);
};

int Obj_002905F0::Cmd(unsigned int id)
{
    switch (id) {
    case 0x4C58771E:
        m1C |= 2;
        m1C &= ~4;
        break;
    case 0xB866BF9B:
        m1C &= ~1;
        m1C &= ~8;
        m1C &= ~2;
        m1C &= ~0x10;
        m1C &= ~4;
        m1C &= ~0x20;
        break;
    case 0x962DEA01:
        m1C |= 1;
        break;
    case 0x00AFC6A7:
        m1C |= 8;
        break;
    case 0x69A9E37F:
        m1C |= 0x10;
        m1C &= ~0x20;
        break;
    case 0x95BDCFCD: {
        bool r = false;
        if (m1C & 1) { if (m1C & 2) r = false; else r = true; }
        return r;
    }
    default:
        return 2;
    }
    return 1;
}
