extern "C" float func_001018F8(const float* v, int* idx)
{
    int local;
    if (!idx) idx = &local;
    *idx = 0;
    float ay = __builtin_fabsf(v[1]);
    float ax = __builtin_fabsf(v[0]);
    if (ax < ay) {
        if (ay < __builtin_fabsf(v[2])) {
            *idx = 2;
        } else {
            *idx = 1;
        }
    } else if (ax < __builtin_fabsf(v[2])) {
        *idx = 2;
    }
    const float* p = v;
    p += *idx;
    return *p;
}
