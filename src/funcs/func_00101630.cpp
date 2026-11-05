struct Vec_00101630 {
    float x, y, z, w;
};

extern "C" Vec_00101630* func_00101630(Vec_00101630* v, int quarter)
{
    float t;
    switch (quarter) {
    case 0:
        break;
    case 1:
        t = v->x;
        v->x = v->z;
        v->z = -t;
        break;
    case 2:
        v->x = -v->x;
        v->z = -v->z;
        break;
    case 3: {
        t = v->x; v->x = -v->z; v->z = t;
        break;
    }
    }
    return v;
}
