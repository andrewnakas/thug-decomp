struct Box_002BBB40 {
    unsigned char x;
    signed char y;
    int GetY() const { return y; }
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    bool Inside(const Box_002BBB40* o) const
    {
        if (o->x < x + w && o->y < y + h && o->z < z + d
            && x < o->x + o->w && y < o->y + o->h && z < o->z + o->d)
            return true;
        return false;
    }
};

struct Child_002BBB40 {
    unsigned char x;
    unsigned char y; int GetY() const { return y; }
    unsigned char z;
    unsigned char m3;
    unsigned char m4;
};

extern "C" Child_002BBB40* func_002BB3B0(void* self, unsigned int i);
extern "C" void* func_002B6CF8(void* n);
extern "C" void func_002BAA28(Box_002BBB40* c, int a, int b, int d, int e, int f, int g);
extern "C" void func_002B6C58(void* t, Box_002BBB40* b);
extern "C" char* func_002BAA48(Box_002BBB40* b, int idx);

struct Obj_002BBB40 {
    Box_002BBB40 m0;
    char pad[0x30 - 6];
    unsigned int m30;
    int m34;
    virtual void* Get(unsigned int i);
    bool Hit(Box_002BBB40* b, int deep);
};

bool Obj_002BBB40::Hit(Box_002BBB40* b, int deep)
{
    if (!(b->x < m0.x + m0.w && m0.x < b->x + b->w))
        return false;
    if (!(b->y < m0.y + m0.h && m0.y < b->y + b->h))
        return false;
    if (!(b->z < m0.z + m0.d && m0.z < b->z + b->d))
        return false;
    bool any = false;
    if (deep) {
        for (unsigned int i = 0; i < m30; i++) {
            if (func_002BB3B0(this, i)->m4)
                any = true;
        }
    }
    if (!any)
        return true;
    for (unsigned int i = 0; i < m30; i++) {
        Child_002BBB40* c = func_002BB3B0(this, i);
        void* t = func_002B6CF8(Get(i));
        Box_002BBB40 box;
        func_002BAA28(&box, 0, 0, 0, 0, 0, 0);
        func_002B6C58(t, &box);
        *func_002BAA48(&box, 0) = m0.x + c->x;
        *func_002BAA48(&box, 1) = m0.GetY() + c->GetY();
        *func_002BAA48(&box, 2) = m0.z + c->z;
        if (!c->m4) {
            if (b->x < box.x + box.w && box.y + box.h > b->y && b->z < box.z + box.d
                && box.x < b->x + b->w && box.y < b->y + b->h && box.z < b->z + b->d)
                return true;
        }
    }
    return false;
}
