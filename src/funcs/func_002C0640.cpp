struct Box_002C0640 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct List_002C0640 {
    int m0;
    int m4;
    int m8;
};

extern "C" void* func_002BF5C0(void* b, Box_002C0640* box, int a, int c, int d);
extern "C" List_002C0640* func_002BC630(List_002C0640* l, void* r);
extern "C" void func_002BC640(List_002C0640* l, int f);
extern "C" void* func_002BC690(List_002C0640* l);
extern "C" void* func_002BC5A0(void* n);
extern "C" void* func_002BAB80(void* p);
extern "C" int func_002CC318(void* p, void* piece, int* out);
extern "C" void* func_002CC5A0(void* p, int v, void* out);

struct Obj_002C0640 {
    char pad0[0x6B00];
    void* m6B00;
    void* Pick(Box_002C0640* box, void* out);
};

void* Obj_002C0640::Pick(Box_002C0640* box, void* out)
{
    List_002C0640 l;
    box->w = 1;
    box->h = 1;
    box->d = 1;
    Box_002C0640 b = *box;
    func_002BC630(&l, func_002BF5C0(this, &b, 0, 0, 0));
    if (l.m0) {
        int idx[4];
        if (func_002CC318(m6B00, func_002BAB80(func_002BC5A0(func_002BC690(&l))), idx)) {
            void* r = func_002CC5A0(m6B00, idx[0], out);
            func_002BC640(&l, 2);
            return r;
        }
    }
    func_002BC640(&l, 2);
    return 0;
}
