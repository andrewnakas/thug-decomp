struct Key_002C7B90 {
    char b[6];
};

extern "C" void* func_002C0640(void* board, Key_002C7B90* key, void* out);
extern "C" int func_002C9EB0(void* self, void* r);

struct Obj_002C7B90 {
    char pad0[8];
    void* m8;
    char padC[0xC8 - 0xC];
    int mC8;
    void Check(Key_002C7B90* k);
};

void Obj_002C7B90::Check(Key_002C7B90* k)
{
    Key_002C7B90 key = *k;
    char buf[0x10];
    void* r = func_002C0640(m8, &key, buf);
    if (r && func_002C9EB0(this, r))
        mC8 = 0;
}
