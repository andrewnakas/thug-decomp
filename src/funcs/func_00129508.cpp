typedef int qword __attribute__((mode(TI)));

struct Vec_00129508 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00129508() {}
    Vec_00129508(float ax, float ay, float az, float aw = 1.0f)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    Vec_00129508 operator+(const Vec_00129508& b) const
    {
        return Vec_00129508(x + b.x, y + b.y, z + b.z);
    }
};


struct Box_00129508 {
    Vec_00129508 min;
    Vec_00129508 max;
    const Vec_00129508& GetMin() const { return min; }
    const Vec_00129508& GetMax() const { return max; }
};

struct Entry_00129508 {
    void* m0;
    char pad4[0xC];
    Vec_00129508 pos;
};

struct Obj_00129508 {
    char pad0[0x188];
    float m188;
    float m18C;
    char pad190[0x10];
    Entry_00129508 m1A0[(0x4C0 - 0x1A0) / 0x20];
    int m4C0;
    float m4C4;
    char pad4C8[0x570 - 0x4C8];
    Vec_00129508 m570;
    float m580;
};

extern "C" void* func_0013DA40(void* id, int a);
extern "C" Box_00129508* func_0013C5B8(void* o);
extern "C" float func_00128B90(float a, float b, float c, float d, float e);

extern "C" void func_00129508(Obj_00129508* self)
{
    Box_00129508 total;
    for (int i = 0; i < self->m4C0; i++) {
        Entry_00129508* e = &self->m1A0[i];
        Box_00129508 b = *func_0013C5B8(func_0013DA40(e->m0, 0));
        Vec_00129508 mn = e->pos + b.GetMin();
        Vec_00129508 mx = e->pos + b.GetMax();
        if (i == 0) {
            total.min = mn;
            total.max = mx;
        } else {
            if (mn.x < total.min.x)
                total.min.x = mn.x;
            if (mn.y < total.min.y)
                total.min.y = mn.y;
            if (mn.z < total.min.z)
                total.min.z = mn.z;
            if (mx.x > total.max.x)
                total.max.x = mx.x;
            if (mx.y > total.max.y)
                total.max.y = mx.y;
            if (mx.z > total.max.z)
                total.max.z = mx.z;
        }
    }
    float dx = total.max.x - total.min.x;
    float dz = total.max.z - total.min.z;
    float dy = total.max.y - total.min.y;
    self->m580 = func_00128B90(self->m188, self->m18C, self->m4C4, dx > dz ? dx : dz, dy);
    self->m570.Set(-(total.max.x + total.min.x) * 0.5f, -(total.max.y + total.min.y) * 0.5f,
                   -(total.max.z + total.min.z) * 0.5f, 0.0f);
}
