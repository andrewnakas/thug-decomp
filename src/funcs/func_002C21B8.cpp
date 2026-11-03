struct Box_002C21B8 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Entry_002C21B8 {
    int key;
    Box_002C21B8 box;
};

extern "C" void* func_002BE5F0(void* self, int key, int* out);
extern "C" int func_002BE6E0(void* self, void* p, int a);
extern "C" void func_002BF008(void* self, Box_002C21B8* b, int r);

struct Obj_002C21B8 {
    char pad0[0x78];
    int m78;
    Entry_002C21B8* m7C;
    void Flush();
};

void Obj_002C21B8::Flush()
{
    for (int i = 0; i < m78; i++) {
        void* p = func_002BE5F0(this, m7C[i].key, 0);
        int r = func_002BE6E0(this, p, 0);
        Box_002C21B8 b = m7C[i].box;
        func_002BF008(this, &b, r);
    }
    m78 = 0;
    if (m7C) m7C = 0;
}
