class Item_0025F620 {
public:
    char pad0[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual int Start();
};

class Entry_0025F620 : public Item_0025F620 {
public:
    char pad18[0x20 - 0x18];
    int m20;
};

struct Self_0025F620;
extern "C" Entry_0025F620* func_0025F128(Self_0025F620* s, int a);
extern "C" void func_0025F508(Self_0025F620* s, Entry_0025F620* e);
extern "C" void func_0025F0F0(Self_0025F620* s);

struct Self_0025F620 {
    int m0;
    bool Advance(int all);
};

bool Self_0025F620::Advance(int all)
{
    bool done = false;
    if (!all) {
        Entry_0025F620* e = func_0025F128(this, 0);
        if (e) {
            func_0025F508(this, e);
            done = true;
        }
    } else {
        Entry_0025F620* e = func_0025F128(this, 0);
        if (e && e->m20) {
            done = true;
            do {
                func_0025F508(this, e);
                e = func_0025F128(this, 0);
            } while (e && e->m20);
        }
    }
    Entry_0025F620* e = func_0025F128(this, 0);
    if (e)
        e->Start();
    if (!done)
        func_0025F0F0(this);
    return true;
}
