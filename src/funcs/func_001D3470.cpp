typedef int qword __attribute__((mode(TI)));

struct Vec_001D3470 {
    union {
        struct {
            float x, y, z, w;
        };
        float c[4];
        qword q;
    };
    Vec_001D3470() {}
    Vec_001D3470(float ax, float ay, float az, float aw)
    {
        c[0] = ax;
        c[1] = ay;
        c[2] = az;
        c[3] = aw;
    }
    float& operator[](int i) { return c[i]; }
    const float& operator[](int i) const { return c[i]; }
};

inline Vec_001D3470 operator+(const Vec_001D3470& a, const Vec_001D3470& b)
{
    return Vec_001D3470(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

inline Vec_001D3470 operator-(const Vec_001D3470& a, const Vec_001D3470& b)
{
    return Vec_001D3470(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

struct Box_001D3470 {
    Vec_001D3470 mn;
    Vec_001D3470 mx;
    Box_001D3470() {}
    void Set(const Vec_001D3470& a, const Vec_001D3470& b)
    {
        mn = a;
        mx = b;
    }
    bool Inside(const Box_001D3470& o) const
    {
        return mn.x >= o.mn.x && mx.x <= o.mx.x && mn.y >= o.mn.y && mx.y <= o.mx.y && mn.z >= o.mn.z &&
               mx.z <= o.mx.z;
    }
    bool Intersects(const Box_001D3470& b) const
    {
        if (mn.x > b.mx.x || b.mn.x > mx.x || mn.z > b.mx.z || b.mn.z > mx.z || mn.y > b.mx.y || b.mn.y > mx.y)
            return false;
        return true;
    }
};

struct Tri_001D3470 {
    Vec_001D3470 v[3];
};

struct Out_001D3470 {
    char pad[0x1000];
    int m_count;
};

struct Coll_001D3470 {
    char pad[0xC];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int Overlaps(Box_001D3470* box);
    virtual void v14();
    virtual int Collide(Tri_001D3470* t, Box_001D3470* box, Out_001D3470* out);
};

struct Entry_001D3470 {
    Coll_001D3470* obj;
    Box_001D3470* box;
};

struct Cache_001D3470 {
    Box_001D3470 box;
    Entry_001D3470 items[(0xFC4 - 0x20) / 8];
    int m_pad;
    int m_count;
};

extern "C" void func_00102328(Box_001D3470* b, const Vec_001D3470* p);
extern "C" void func_00102358(Box_001D3470* b, const Vec_001D3470* p);
extern "C" void* func_001324F8(Tri_001D3470* t);
extern "C" Coll_001D3470** func_00208C50(void* w, Box_001D3470* b);

extern "C" bool func_001D3470(Tri_001D3470* t, Out_001D3470* out, Cache_001D3470* cache)
{
    Box_001D3470 box;
    bool cached = cache != 0;
    func_00102328(&box, &t->v[0]);
    func_00102358(&box, &(t->v[0] + t->v[1]));
    func_00102358(&box, &(t->v[0] + t->v[2]));
    func_00102358(&box, &(t->v[0] + t->v[1] + t->v[2]));
    if (cached)
        cached = box.Inside(cache->box);
    Coll_001D3470** list = 0;
    if (!cached) {
        void* w = func_001324F8(t);
        if (!w)
            return false;
        list = func_00208C50(w, &box);
    }
    Vec_001D3470 ext(0.5f, 0.5f, 0.5f, 1.0f);
    box.Set(box.mn - ext, box.mx + ext);
    out->m_count = 0;
    if (cached) {
        Entry_001D3470* e = cache->items;
        int n = cache->m_count;
        while (n--) {
            if (box.Intersects(*e->box))
                e->obj->Collide(t, &box, out);
            e++;
        }
    } else {
        Coll_001D3470* c;
        while ((c = *list) != 0) {
            if (c->Overlaps(&box))
                c->Collide(t, &box, out);
            list++;
        }
    }
    return out->m_count > 0;
}
