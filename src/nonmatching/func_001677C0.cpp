/* fuzzy: 76.4 */
typedef int qword __attribute__((mode(TI)));

struct Vec_001677C0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_001677C0 {
    Vec_001677C0 row[4];
};

struct Obj_001677C0 {
    Mat_001677C0 m;
    Vec_001677C0 pos;
    unsigned int flags;
    char pad54[0x70 - 0x54];
    Mat_001677C0 m70;
};

extern "C" void func_00323318(Mat_001677C0* d, const Mat_001677C0* a, const Mat_001677C0* b);
extern "C" Vec_001677C0 func_00323298(const Mat_001677C0* m, const Vec_001677C0* v);
extern "C" void func_00167A50(Obj_001677C0* o);

extern Mat_001677C0 D_003E1240;
extern Mat_001677C0 D_003E12C0;

static inline void Copy_001677C0(Mat_001677C0* d, const Mat_001677C0* s)
{
    d->row[0] = s->row[0];
    d->row[1] = s->row[1];
    d->row[2] = s->row[2];
    d->row[3] = s->row[3];
}

void func_001677C0(Obj_001677C0* self, const Mat_001677C0* mat)
{
    Mat_001677C0 tmp;
    {
        Mat_001677C0 m;
        Mat_001677C0* pm = &m;
        Copy_001677C0(pm, mat);
        func_00323318(pm, &self->m, pm);
        self->m = m;
        tmp = m;
    }
    {
        Vec_001677C0 v2;
        Vec_001677C0 v;
        Vec_001677C0 p = tmp.row[3];
        float x = p.x * tmp.row[0].x + p.y * tmp.row[0].y + p.z * tmp.row[0].z;
        float y = p.x * tmp.row[1].x + p.y * tmp.row[1].y + p.z * tmp.row[1].z;
        float z = p.x * tmp.row[2].x + p.y * tmp.row[2].y + p.z * tmp.row[2].z;
        float t;
        t = tmp.row[0].y; tmp.row[0].y = tmp.row[1].x; tmp.row[1].x = t;
        t = tmp.row[0].z; tmp.row[0].z = tmp.row[2].x; tmp.row[2].x = t;
        t = tmp.row[1].z; tmp.row[1].z = tmp.row[2].y; tmp.row[2].y = t;
        tmp.row[3].x = -x;
        tmp.row[3].y = -y;
        tmp.row[3].z = -z;
        v.x = -tmp.row[3].x;
        v.y = -tmp.row[3].y;
        v.z = -tmp.row[3].z;
        v.w = -tmp.row[3].w;
        v2.x = v.x * 16.0f;
        v2.y = v.y * 16.0f;
        v2.z = v.z * 16.0f;
        v2.w = v.w * 16.0f;
        self->pos = v2;
    }
    self->pos.x = (float)(int)self->pos.x;
    self->pos.y = (float)(int)self->pos.y;
    self->pos.z = (float)(int)self->pos.z;
    {
        Mat_001677C0 m2 = self->m;
        Vec_001677C0 v4;
        Vec_001677C0 r;
        Vec_001677C0 v3;
        v3.x = -self->pos.x;
        v3.y = -self->pos.y;
        v3.z = -self->pos.z;
        v3.w = -self->pos.w;
        r = func_00323298(&self->m, &v3);
        v4.x = r.x * 0.0625f;
        v4.y = r.y * 0.0625f;
        v4.z = r.z * 0.0625f;
        v4.w = r.w * 0.0625f;
        m2.row[3] = v4;
        func_00323318(&tmp, &D_003E1240, &m2);
    }
    func_00323318(&self->m70, &D_003E12C0, &tmp);
    if (self->flags & 1) {
        func_00167A50(self);
    }
}
