struct Box_002C7370 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    bool Narrower(unsigned char v) { return w < v; }
};

struct Park_002C7370 {
    char pad[0x352C];
    Box_002C7370 m352C;
};

struct Ref_002C7370 {
    int m0;
    Park_002C7370* m4;
};

struct Item_002C7370 {
    char pad[0x14];
    Item_002C7370* m14;
};

extern "C" void func_002BAA28(Box_002C7370* b, int x, int y, int z, int w, int h, int d);
extern "C" void func_002CE120(Item_002C7370* p, void* self, Box_002C7370* b);
extern "C" void func_002CD490(Item_002C7370* p, int v);
extern "C" void func_002C9000(void* self, int v);

struct Obj_002C7370 {
    int m0;
    Ref_002C7370 m4;
    char padC[0x68 - 0xC];
    Item_002C7370* m68;
    Item_002C7370* m6C;
    void Prune();
    Ref_002C7370* GetRef() { return &m4; }
};

void Obj_002C7370::Prune()
{
    Item_002C7370* prev = 0;
    Item_002C7370* it = m68;
    Item_002C7370* next;
    if (it) do {
        next = it->m14;
        Box_002C7370 b;
        Box_002C7370* pb = &b;
        func_002BAA28(pb, 0, 0, 0, 0, 0, 0);
        func_002CE120(it, this, pb);
        Box_002C7370* park = &GetRef()->m4->m352C;
        if (park->Narrower(b.w) || park->d < b.w || park->Narrower(b.d) || park->d < b.d) {
            if (prev) prev->m14 = next;
            if (it == m68) m68 = next;
            if (it) func_002CD490(it, 3);
        } else {
            prev = it;
        }
        it = next;
    } while (next);
    m6C = m68;
    func_002C9000(this, 0);
}
