struct Obj_00197880 {
    char pad0[0x324];
    int m324;
    float m328[7];
    float m344;
    float m348;
    int Fn(float x);
};

int Obj_00197880::Fn(float x)
{
    x *= m344;
    int i = 0;
    float lim = m348;
    float* r = m328;
    do {
        if (lim < x * *r && i < m324 - 1) {
            r++;
            i++;
        } else
            break;
    } while (1);
    return i;
}
