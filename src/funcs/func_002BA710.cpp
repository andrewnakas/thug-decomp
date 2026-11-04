extern "C" void func_002BA688(void* self, int x, int* lo, int* hi);

struct Key_002BA710 {
    unsigned char m0;
    signed char m1;
    unsigned char m2;
};

struct Item_002BA710 {
    Key_002BA710 m0;
    char pad3[0x5];
    int m8;
    char padC[0x24];
};

struct Obj_002BA710 {
    char pad0[0xC4];
    Item_002BA710 m_items[18];
    void Clear(const Key_002BA710* key, int x);
};

void Obj_002BA710::Clear(const Key_002BA710* key, int x) {
    int lo = 0;
    int hi = 0;
    func_002BA688(this, x, &lo, &hi);
    for (int i = lo; i <= hi; i++) {
        Item_002BA710* it = &m_items[i];
        if (it->m0.m0 == key->m0 && it->m0.m1 == key->m1 && it->m0.m2 == key->m2) {
            it->m8 = 0;
        }
    }
}
