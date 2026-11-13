/* fuzzy: 79.6 */
struct Box_002C98B8 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct List_002C98B8 {
    int m0;
};

struct Big_002C98B8 {
    int m[0x48 / 4];
    int m48;
    int m4C[2];
};

struct Ref_002C98B8 {
    int m0;
    void* m4;
};

struct Obj_002C98B8;

extern "C" void func_002C95E8(Obj_002C98B8* o);
extern "C" unsigned char* func_002BAA48(Box_002C98B8* b, int idx);
extern "C" int func_002CDFD8(void* p, Obj_002C98B8* o);
extern "C" int func_002BFC50(void* p, Box_002C98B8* b, int c);
extern "C" void* func_002BF5C0(void* b, Box_002C98B8* box, int a, int c, int d);
extern "C" List_002C98B8* func_002BC630(List_002C98B8* l, void* r);
extern "C" void func_002BC640(List_002C98B8* l, int f);
extern "C" void* func_002BC690(List_002C98B8* l);
extern "C" void* func_002BC5A0(void* n);
extern "C" Box_002C98B8* func_002BAB80(void* p);
extern "C" Big_002C98B8* func_002C0640(void* b, Box_002C98B8* box, int* out);
extern "C" void func_002C9DA8(Obj_002C98B8* o, int v);
extern "C" void func_002C0E60(void* p, int a, Big_002C98B8* b);

struct Obj_002C98B8 {
    int m0;
    Ref_002C98B8 m4;
    char padC[4];
    Box_002C98B8 m10;
    char pad16[0x6C - 0x16];
    void* m6C;
    int m70;
    char pad74[0x7C - 0x74];
    int m7C;
    Big_002C98B8 m80;
    Ref_002C98B8* GetRef() { return &m4; }
    void Move(int dx, int dz);
};

void Obj_002C98B8::Move(int dx, int dz)
{
    func_002C95E8(this);
    Box_002C98B8 old = m10;
    *func_002BAA48(&m10, 0) += dx;
    *func_002BAA48(&m10, 2) += dz;
    func_002C95E8(this);
    if (m7C == 5) {
        if (m6C) {
            m70 = func_002CDFD8(m6C, this);
            *func_002BAA48(&m10, 1) = m70;
        } else {
            *func_002BAA48(&m10, 1) = 0;
        }
    } else {
        Ref_002C98B8* r = GetRef();
        Box_002C98B8 b = m10;
        int h1 = func_002BFC50(r->m4, &b, 0);
        b = old;
        int h2 = func_002BFC50(r->m4, &b, 0);
        *func_002BAA48(&m10, 1) = h2 < h1 ? h1 : h2;
    }
    if (m7C == 2 || m7C == 3) {
        Box_002C98B8 b = m10;
        List_002C98B8 l;
        int out;
        func_002BC630(&l, func_002BF5C0(GetRef()->m4, &b, 0, 0, 0));
        int mode = 2;
        if (l.m0) {
            b = *func_002BAB80(func_002BC5A0(func_002BC690(&l)));
            Big_002C98B8* pk = func_002C0640(GetRef()->m4, &b, &out);
            if (pk) {
                if (m80.m48 != 1) m80 = *pk;
                mode = 3;
            }
        }
        func_002C9DA8(this, mode);
        if (m80.m48 > 0) {
            func_002C0E60(GetRef()->m4, 1, &m80);
        } else {
            func_002C0E60(GetRef()->m4, 1, 0);
        }
        func_002BC640(&l, 2);
    }
}
