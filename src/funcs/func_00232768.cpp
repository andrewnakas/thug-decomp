float func_00232768(signed char flags, unsigned int kind)
{
    float f = 0.0f;
    int v;
    switch (kind) {
    case 0:
        v = flags & 3;
        if (v == 0) return 0.05f;
        if (v == 1) return 0.1f;
        if (v == 2) return 10.1f;
        break;
    case 1:
        v = (flags & 4) > 0;
        if (v == 0) return 0.04f;
        if (v == 1) return 10.1f;
        break;
    case 2:
        v = (flags & 8) > 0;
        if (v == 0) return 0.0022f;
        if (v == 1) return 20.0f;
        break;
    case 3:
        v = (flags & 0x10) > 0;
        if (v == 0) return 0.0017f;
        if (v == 1) return 10.0f;
        break;
    case 4:
        v = (flags & 0x20) > 0;
        if (v == 0) return 1.5f;
        if (v == 1) f = 1.0f;
        break;
    }
    return f;
}
