/* fuzzy: 90.4 */
/* nonmatch func_002C2880: best earlier draft (thug-claude-lane2/work/wk23/mine/nm_func_002C2880.cpp), 578 of 628 words differ (size 0x9c0, want 0x9d0). */
/* sym: __12Box_002C2880UcScUcUcUcUc = 0x002BAA28 */
struct Box_002C2880 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    Box_002C2880(unsigned char x = 0, signed char y = 0, unsigned char z = 0,
                 unsigned char w = 0, unsigned char h = 0, unsigned char d = 0);
    void SetPos(unsigned char nx, signed char ny, unsigned char nz) { x = nx; y = ny; z = nz; }
};

struct Array_002C2880 {
    char pad0[0xC];
    unsigned int mC;
};

struct Struct_002C2880;

struct Comp_002C2880 {
    char pad0[8];
    int m8;
};

struct Elem_002C2880;

struct Info_002C2880 {
    Box_002C2880 m0;
};

struct Piece_002C2880 {
    char pad0[8];
    int m8;
    char padC[0x34 - 0xC];
    int m34;
    virtual void V0();
    virtual void V1();
    virtual void Place(Elem_002C2880* e, Box_002C2880* b, int rot, int flip);
};

struct Node_002C2880 {
    char pad0[8];
    Piece_002C2880* m8;
    Node_002C2880* mC;
};

struct Heap_002C2880;
extern "C" void func_0010A950(Heap_002C2880* h, int v);
struct Heap_002C2880 {
    void Push(int v) { func_0010A950(this, v); }
};
extern Heap_002C2880* D_00388A70;

struct Loader_002C2880 {
    void* m0;
    char pad4[0x84 - 4];
    Node_002C2880* m84;
    char pad88[0x90 - 0x88];
    int m90;
    void Load();
};

extern char D_0037A4F8[];
extern char D_00392780[];
extern char D_00392788[];
extern char D_00392790[];
extern char D_00392758[];
extern char D_0037A5E8[];
extern char D_0037A5F8[];
extern char D_0037A608[];

extern "C" Array_002C2880* func_001E55F8(char* name, int a);
extern "C" Struct_002C2880* func_001E9378(Array_002C2880* a, unsigned int i);
extern "C" int func_001E9270(Array_002C2880* a, int i);
extern "C" int func_001E84E8(Struct_002C2880* s, char* name, int* out, int a);
extern "C" int func_001E82B8(Struct_002C2880* s, char* name, Array_002C2880** out, int a);
extern "C" int func_001E8398(Struct_002C2880* s, unsigned int name, unsigned int* out, int a);
extern "C" int func_001E87B8(Struct_002C2880* s, char* name);
extern "C" int func_001E8708(Struct_002C2880* s, unsigned int name);
extern "C" int func_001E8248(Struct_002C2880* s, int a, Array_002C2880** out, int b);
extern "C" Comp_002C2880* func_001E6E90(Struct_002C2880* s, int a);
extern "C" Elem_002C2880* func_002B7740(void* m, int id, int quiet);
extern "C" int func_002B74E0(void* m);
extern "C" void* func_0010A638(Heap_002C2880* h, int size, int a, int b);
extern "C" void func_0010A9B0(Heap_002C2880* h);
extern "C" Piece_002C2880* func_002BBF20(void* p);
extern "C" void func_002BB298(Piece_002C2880* p, unsigned int n);
extern "C" void func_002B6C58(Elem_002C2880* e, Box_002C2880* b);
extern "C" int func_002B6E90(Elem_002C2880* e);
extern "C" void func_002C3250(Loader_002C2880* l, int i, int v);
extern "C" Info_002C2880* func_002BE5F0(Loader_002C2880* l, int id, int* out);
extern "C" unsigned int func_002BC120(Piece_002C2880* p, Info_002C2880* info, Box_002C2880* b, int rot, int flip);
extern "C" Node_002C2880* func_002C48E0(int size);

void Loader_002C2880::Load()
{
    int ids[1000];
    unsigned int count;
    Array_002C2880* list = func_001E55F8(D_0037A4F8, 1);
    count = 0;
    for (unsigned int i = 0; i < list->mC; i++) {
        Struct_002C2880* s = func_001E9378(list, i);
        int id = 0;
        if (func_001E84E8(s, D_00392780, &id, 0))
            func_002B7740(m0, id, 0);
    }
    for (unsigned int j = 0; j < list->mC; j++) {
        Struct_002C2880* s = func_001E9378(list, j);
        {
            Heap_002C2880* h = D_00388A70;
            h->Push(func_002B74E0(m0));
        }
        Piece_002C2880* p = func_002BBF20(func_0010A638(D_00388A70, 0x3C, 1, 0));
        func_0010A9B0(D_00388A70);
        int id = 0;
        Array_002C2880* multi = 0;
        if (func_001E84E8(s, D_00392780, &id, 0)) {
            func_002BB298(p, 1);
            Elem_002C2880* e = func_002B7740(m0, id, 1);
            Box_002C2880 box;
            func_002B6C58(e, &box);
            Array_002C2880* pos = 0;
            if (func_001E82B8(s, D_00392788, &pos, 0))
                box.SetPos(func_001E9270(pos, 0), func_001E9270(pos, 1), func_001E9270(pos, 2));
            p->Place(e, &box, 0, 0);
            ids[count++] = p->m34 = func_002B6E90(e);
            p->m8 |= 0x80;
            unsigned int type;
            if (func_001E8398(s, 0xF176A9FD, &type, 0)) {
                if (type == 0x2813AB8A)
                    p->m8 |= 0x800;
                if (type == 0xFC26B6F4)
                    p->m8 |= 0x8000;
                if (type == 0xFFD81C08)
                    p->m8 |= 0x10000;
                if (type == 0x48FA9C7B)
                    func_002C3250(this, 1, id);
                if (type == 0x419183B2)
                    func_002C3250(this, 2, id);
                if (type == 0xE69AEFAF)
                    func_002C3250(this, 3, id);
                if (type == 0xA091CE25)
                    func_002C3250(this, 4, id);
                if (type == 0x74B0F4E9) {
                    func_002C3250(this, 5, id);
                    p->m8 |= 0x2000;
                }
                if (type == 0xC893ACF8) {
                    func_002C3250(this, 6, id);
                    p->m8 |= 0x2000;
                }
                if (type == 0x40BDFA7E) {
                    func_002C3250(this, 7, id);
                    p->m8 |= 0x2000;
                }
                if (type == 0x3AE047FC) {
                    func_002C3250(this, 8, id);
                    p->m8 |= 0x2000;
                }
            }
        } else if (func_001E82B8(s, D_0037A5E8, &multi, 0)) {
            int any = 0;
            func_002BB298(p, multi->mC);
            for (unsigned int k = 0; k < multi->mC; k++) {
                Struct_002C2880* sub = func_001E9378(multi, k);
                int rot = 0;
                int sid = func_001E6E90(sub, 0)->m8;
                Array_002C2880* pos = 0;
                func_001E8248(sub, 0, &pos, 1);
                Elem_002C2880* e = func_002B7740(m0, sid, 1);
                ids[count++] = sid;
                Box_002C2880 box;
                func_002B6C58(e, &box);
                box.SetPos(func_001E9270(pos, 0), func_001E9270(pos, 1), func_001E9270(pos, 2));
                if (pos->mC >= 4)
                    rot = func_001E9270(pos, 3);
                if (func_001E8708(sub, 0x0CD75A3F))
                    any = 1;
                p->Place(e, &box, rot, func_001E8708(sub, 0x0CD75A3F));
            }
            if (any)
                p->m8 |= 0x4000;
        } else if (func_001E82B8(s, D_00392790, &multi, 0)) {
            func_002BB298(p, multi->mC);
            for (unsigned int k = 0; k < multi->mC; k++) {
                int rot = 0;
                Struct_002C2880* sub = func_001E9378(multi, k);
                int sid = func_001E6E90(sub, 0)->m8;
                Array_002C2880* pos = 0;
                func_001E8248(sub, 0, &pos, 1);
                Info_002C2880* info = func_002BE5F0(this, sid, 0);
                Box_002C2880 box = info->m0;
                box.SetPos(func_001E9270(pos, 0), func_001E9270(pos, 1), func_001E9270(pos, 2));
                if (pos->mC >= 4)
                    rot = func_001E9270(pos, 3);
                func_002BC120(p, info, &box, rot, func_001E8708(sub, 0x0CD75A3F));
            }
        }
        if (func_001E84E8(s, D_00392758, &p->m34, 0))
            p->m8 &= ~0x80;
        if (func_001E87B8(s, D_0037A5F8))
            p->m8 |= 8;
        if (func_001E87B8(s, D_0037A608))
            p->m8 |= 0x400;
        {
            Heap_002C2880* h = D_00388A70;
            h->Push(func_002B74E0(m0));
        }
        Node_002C2880* n = func_002C48E0(0x10);
        func_0010A9B0(D_00388A70);
        n->m8 = p;
        n->mC = m84;
        m84 = n;
        m90++;
    }
    for (unsigned int k = 0; k < count; k++) {
        if (func_002BE5F0(this, ids[k], 0))
            continue;
        {
            Heap_002C2880* h = D_00388A70;
            h->Push(func_002B74E0(m0));
        }
        Piece_002C2880* p = func_002BBF20(func_0010A638(D_00388A70, 0x3C, 1, 0));
        func_0010A9B0(D_00388A70);
        func_002BB298(p, 1);
        Elem_002C2880* e = func_002B7740(m0, ids[k], 1);
        Box_002C2880 box;
        func_002B6C58(e, &box);
        p->Place(e, &box, 0, 0);
        p->m34 = ids[k];
        p->m8 |= 0x80;
        {
            Heap_002C2880* h = D_00388A70;
            h->Push(func_002B74E0(m0));
        }
        Node_002C2880* n = func_002C48E0(0x10);
        func_0010A9B0(D_00388A70);
        n->m8 = p;
        n->mC = m84;
        m84 = n;
        m90++;
    }
}
