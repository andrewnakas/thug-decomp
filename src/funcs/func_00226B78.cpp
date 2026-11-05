extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

static inline void Read_00226B78(void* params, int* out)
{
    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    out[3] = 0;
    out[4] = 0;
    out[5] = 0;
    func_001E7DE8(params, 0x447D8CC8, &out[0], 0);
    func_001E7DE8(params, 0x7149EFF9, &out[1], 0);
    func_001E7DE8(params, 0x1A5FD66F, &out[2], 0);
    func_001E7DE8(params, 0x8FE1EEB1, &out[3], 0);
    func_001E7DE8(params, 0x5F94B55C, &out[4], 0);
    func_001E7DE8(params, 0xD029F619, &out[5], 0);
}

bool Cmp_00226B78(void* pa, void* pb)
{
    int t[2][6];
    Read_00226B78(pa, t[0]);
    Read_00226B78(pb, t[1]);
    bool r = false;
    if (t[0][0] < t[1][0]) {
        goto done;
    }
    if (t[0][0] > t[1][0]) {
        r = true;
        goto done;
    }
    if (t[0][1] < t[1][1]) {
        goto done;
    }
    if (t[0][1] > t[1][1]) {
        r = true;
        goto done;
    }
    if (t[0][2] < t[1][2]) {
        goto done;
    }
    if (t[0][2] > t[1][2]) {
        r = true;
        goto done;
    }
    if (t[0][3] < t[1][3]) {
        goto done;
    }
    if (t[0][3] > t[1][3]) {
        r = true;
        goto done;
    }
    if (t[0][4] < t[1][4]) {
        goto done;
    }
    if (t[0][4] > t[1][4]) {
        r = true;
        goto done;
    }
    if (t[0][5] < t[1][5]) {
        goto done;
    }
    if (t[0][5] > t[1][5]) {
        r = true;
        goto done;
    }
    r = true;
done:
    return r;
}
