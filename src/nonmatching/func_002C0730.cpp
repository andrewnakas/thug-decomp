/* fuzzy: 92.8 */
typedef int qword __attribute__((mode(TI)));
struct Vec_002C0730 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        } f;
    };
};

struct Box_002C0730 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Piece_002C0730 {
    Box_002C0730 box;
    char pad6[2];
    unsigned int m8;
};

struct List_002C0730 {
    int m0;
    int m4;
    int m8;
};

struct Set_002C0730 {
    Box_002C0730 boxes[2];
    int type[2];
    int a[2];
    int b[2];
    char pad24[0x48 - 0x24];
    int count;
    int id;
};

extern const float D_00392610;
extern const float D_00392614;
extern const float D_00392618;

extern "C" int func_002CC030(void* mgr);
extern "C" void* func_002BF5C0(void* self, Box_002C0730* box, int a, int c, int d);
extern "C" List_002C0730* func_002BC630(List_002C0730* l, void* r);
extern "C" void func_002BC640(List_002C0730* l, int f);
extern "C" void* func_002BC690(List_002C0730* l);
extern "C" void* func_002BC5A0(void* n);
extern "C" Piece_002C0730* func_002BAB80(void* p);
extern "C" void* func_002BA8A0(void* m, Vec_002C0730* pos, int flag, float ang);
extern "C" void func_002B7028(void* q, float s);
extern "C" void func_002CC060(void* mgr, void* q, Piece_002C0730* p, int id);
extern "C" void func_002CC108(void* mgr, void* q, Piece_002C0730* p, int id);
extern "C" void func_002CC1F8(void* mgr, int id, Set_002C0730* s);

struct Obj_002C0730 {
    void* m0;
    char pad4[0x6B00 - 4];
    void* m6B00;
    bool Build(Set_002C0730* s);
};

bool Obj_002C0730::Build(Set_002C0730* s)
{
    int id = func_002CC030(m6B00);
    if (id == -1)
        return false;
    Box_002C0730* bx = s->boxes;
    for (int i = 0; i < s->count; i++, bx++) {
        List_002C0730 l;
        bx->w = 1;
        bx->h = 1;
        bx->d = 1;
        Box_002C0730 b = *bx;
        func_002BC630(&l, func_002BF5C0(this, &b, 0, 0, 0));
        if (!l.m0) {
            func_002BC640(&l, 2);
            return false;
        }
        float ang = 0.0f;
        Piece_002C0730* p = func_002BAB80(func_002BC5A0(func_002BC690(&l)));
        p->m8 |= 0x1000;
        *bx = p->box;
        b = p->box;
        Vec_002C0730 pos;
        int flag = 0;
        switch (s->type[i]) {
        case 0:
            flag = 1;
            ang = (float)(b.d + s->a[i] + s->b[i]) * D_00392618;
            pos.f.x = (float)(b.x + b.w) * D_00392610 - D_00392610 * 0.5f - 1.0f;
            pos.f.y = (float)b.y * D_00392614;
            pos.f.z = (float)(b.z - s->b[i]) * D_00392618 + ang * 0.5f - D_00392618;
            break;
        case 1:
            ang = (float)(b.w + s->a[i] + s->b[i]) * D_00392610;
            pos.f.x = (float)(b.x - s->b[i]) * D_00392610 + ang * 0.5f - D_00392610;
            pos.f.y = (float)b.y * D_00392614;
            pos.f.z = (float)b.z * D_00392618 - D_00392618 * 0.5f + 1.0f;
            break;
        case 2:
            flag = 1;
            ang = (float)(b.d + s->a[i] + s->b[i]) * D_00392618;
            pos.f.x = (float)b.x * D_00392610 - D_00392610 * 0.5f + 1.0f;
            pos.f.y = (float)b.y * D_00392614;
            pos.f.z = (float)(b.z - s->a[i]) * D_00392618 + ang * 0.5f - D_00392618;
            break;
        case 3:
            ang = (float)(b.w + s->a[i] + s->b[i]) * D_00392610;
            pos.f.x = (float)(b.x - s->a[i]) * D_00392610 + ang * 0.5f - D_00392610;
            pos.f.y = (float)b.y * D_00392614;
            pos.f.z = (float)(b.z + b.d) * D_00392618 - D_00392618 * 0.5f - 1.0f;
            break;
        }
        pos.f.x -= D_00392610 * 28.0f;
        pos.f.z -= D_00392618 * 28.0f;
        void* q = func_002BA8A0(m0, &pos, flag, ang);
        func_002B7028(q, ang / D_00392610);
        if (i == 0)
            func_002CC060(m6B00, q, p, id);
        else
            func_002CC108(m6B00, q, p, id);
        func_002BC640(&l, 2);
    }
    s->id = id;
    func_002CC1F8(m6B00, id, s);
    return true;
}
