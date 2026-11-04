extern "C" int func_00265EC8(void* self);
extern "C" void* func_0029C320();
extern "C" void func_0029C128(void* a, int key);
extern "C" void* func_001046B0(int size);
extern "C" void* func_00264FC8(void* self, int key);
extern "C" int func_00266AA0(void* tbl, int* key, void* v);
extern "C" void func_00266070(void* self, int a, int b);

struct Game_00265F58 {
    char pad0[0x3B0];
    unsigned int m_3B0;
};

extern Game_00265F58* D_0038FC78;

struct Tbl_00265F58 {
    int m0;
    int m4;
    void Insert(int* key, void* v) { func_00266AA0(this, key, v); }
};

struct Obj_00265F58 {
    int m0;
    int m_count;
    Tbl_00265F58 m_tbl;
    bool Add(int key);
};

bool Obj_00265F58::Add(int key)
{
    if (!func_00265EC8(this)) {
        if (D_0038FC78->m_3B0 == 0xB664035D) {
            func_0029C128(func_0029C320(), key);
        }
        m_tbl.Insert(&key, func_00264FC8(func_001046B0(0x40), key));
        m_count++;
        func_00266070(this, key, key);
        return true;
    }
    return false;
}
