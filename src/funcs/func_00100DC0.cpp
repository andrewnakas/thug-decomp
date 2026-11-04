typedef int qword_00100DC0 __attribute__((mode(TI)));

union Vec_00100DC0 {
    qword_00100DC0 q;
    struct {
        float x, y, z, w;
    } f;
};

struct Mat_00100DC0 {
    Vec_00100DC0 row[4];
    Mat_00100DC0* OrthoNormalize(int axis);
};

extern "C" void func_003233B8(Vec_00100DC0* d, Vec_00100DC0* s);

static inline float fabs_00100DC0(float v)
{
    return __builtin_fabsf(v);
}

Mat_00100DC0* Mat_00100DC0::OrthoNormalize(int i)
{
    int j = i + 1;
    if (j == 3)
        j = 0;
    int k = j + 1;
    if (k == 3)
        k = 0;
    Vec_00100DC0 t;
    if (fabs_00100DC0((&row[k])->f.x * (&row[i])->f.x + (&row[k])->f.y * (&row[i])->f.y + (&row[k])->f.z * (&row[i])->f.z)
        < fabs_00100DC0((&row[i])->f.x * (&row[j])->f.x + (&row[i])->f.y * (&row[j])->f.y + (&row[i])->f.z * (&row[j])->f.z)) {
        t.f.x = (&row[k])->f.y * (&row[i])->f.z - (&row[k])->f.z * (&row[i])->f.y;
        t.f.y = (&row[k])->f.z * (&row[i])->f.x - (&row[k])->f.x * (&row[i])->f.z;
        t.f.z = (&row[k])->f.x * (&row[i])->f.y - (&row[k])->f.y * (&row[i])->f.x;
        t.f.w = 0.0f;
        row[j] = t;
        func_003233B8(&row[j], &row[j]);
        t.f.x = (&row[i])->f.y * (&row[j])->f.z - (&row[i])->f.z * (&row[j])->f.y;
        t.f.y = (&row[i])->f.z * (&row[j])->f.x - (&row[i])->f.x * (&row[j])->f.z;
        t.f.z = (&row[i])->f.x * (&row[j])->f.y - (&row[i])->f.y * (&row[j])->f.x;
        t.f.w = 0.0f;
        row[k] = t;
        func_003233B8(&row[k], &row[k]);
    } else {
        t.f.x = (&row[i])->f.y * (&row[j])->f.z - (&row[i])->f.z * (&row[j])->f.y;
        t.f.y = (&row[i])->f.z * (&row[j])->f.x - (&row[i])->f.x * (&row[j])->f.z;
        t.f.z = (&row[i])->f.x * (&row[j])->f.y - (&row[i])->f.y * (&row[j])->f.x;
        t.f.w = 0.0f;
        row[k] = t;
        func_003233B8(&row[k], &row[k]);
        t.f.x = (&row[k])->f.y * (&row[i])->f.z - (&row[k])->f.z * (&row[i])->f.y;
        t.f.y = (&row[k])->f.z * (&row[i])->f.x - (&row[k])->f.x * (&row[i])->f.z;
        t.f.z = (&row[k])->f.x * (&row[i])->f.y - (&row[k])->f.y * (&row[i])->f.x;
        t.f.w = 0.0f;
        row[j] = t;
        func_003233B8(&row[j], &row[j]);
    }
    return this;
}
