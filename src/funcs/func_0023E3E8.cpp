struct Item_0023E3E8 {
    char pad0[0x14];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual int IsActive();
};

struct Arr_0023E3E8;

extern char D_0038FF28[];
extern char D_0038FF30[];
extern char D_00373820[];
extern char D_00373830[];
extern char D_00373840[];
extern char D_00373850[];

struct Obj_0023E3E8;
extern "C" int func_0023C040(Obj_0023E3E8* self);
extern "C" void* func_00122CF8(int size);
extern "C" Arr_0023E3E8* func_001E8DD0(void* mem);
extern "C" void func_001E8E98(Arr_0023E3E8* a, int n, int type);
extern "C" Item_0023E3E8* func_00243C18(void* list, int* i, int* out);
extern "C" void* func_00244528(Item_0023E3E8* it);
extern "C" bool func_001E8618(void* p, unsigned int name);
extern "C" int func_00246258(Item_0023E3E8* it);
extern "C" void func_001E90F8(Arr_0023E3E8* a, int i, int v);
extern "C" int func_001E9300(Arr_0023E3E8* a, int i);
extern "C" bool func_001E7DE8(void* s, unsigned int id, int* out, int req);
extern "C" void func_00246D18(Item_0023E3E8* it, char** out);
extern "C" bool func_001E8708(void* p, unsigned int name);
extern "C" bool func_00246C60(Item_0023E3E8* it);
extern "C" bool func_00246C88(Item_0023E3E8* it);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E7360(void* p, unsigned int name, int v);
extern "C" void func_001E70C0(void* p, unsigned int name, char* v);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" char* func_00331678(char* d, char* s);
extern "C" bool func_001E8398(void* p, unsigned int name, unsigned int* out, int req);
extern "C" char* func_001044A8(int v, int sep);
extern "C" void func_001F0210(unsigned int name, void* p, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int flags);
extern "C" void func_001E6518(Arr_0023E3E8* a);
extern "C" void func_001E8DE8(Arr_0023E3E8* a, int flags);

struct Obj_0023E3E8 {
    int m0;
    char m4[4];
    void Show();
};

extern "C" Item_0023E3E8* func_0023BAD8(Obj_0023E3E8* o, int id, int a);
extern "C" bool func_0023F248(Obj_0023E3E8* o);

void Obj_0023E3E8::Show()
{
    char buf[0x80];
    int i;
    int out;
    int r2;
    int rank;
    char* name;
    int v;
    unsigned int type;
    int t;
    int sec;
    int min;
    int n1 = 0;
    int n2 = 0;
    int n = func_0023C040(this);
    Arr_0023E3E8* a1 = func_001E8DD0(func_00122CF8(0x10));
    Arr_0023E3E8* a2 = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(a1, n, 0xD);
    func_001E8E98(a2, n, 0xD);
    for (i = 0; i < n; i++) {
        Item_0023E3E8* it = func_00243C18(m4, &i, &out);
        if (func_001E8618(func_00244528(it), 0x09B048FC))
            {
            func_001E90F8(a1, n1, func_00246258(it));
            n1++;
        }
        else
            {
            func_001E90F8(a2, n2, func_00246258(it));
            n2++;
        }
    }
    for (int k = 0; k < n1; k++) {
        for (int j = k; j < n1; j++) {
            int x = func_001E9300(a1, j);
            func_001E7DE8(func_00244528(func_0023BAD8(this, x, 1)), 0x09B048FC, &rank, 1);
            if (rank - 1 != k)
                continue;
            if (j == k)
                break;
            int y = func_001E9300(a1, k);
            func_001E7DE8(func_00244528(func_0023BAD8(this, y, 1)), 0x09B048FC, &r2, 1);
            func_001E90F8(a1, k, x);
            func_001E90F8(a1, j, y);
            break;
        }
    }
    for (int m = 0; m < n2; m++)
        func_001E90F8(a1, m + n1, func_001E9300(a2, m));
    for (int k = 0; k < n; k++) {
        Item_0023E3E8* it = func_0023BAD8(this, func_001E9300(a1, k), 1);
        void* prm = func_00244528(it);
        name = 0;
        func_00246D18(it, &name);
        if (name && (func_0023F248(this) || !func_001E8708(prm, 0xD303A1A3)) && !func_00246C60(it)) {
            void* p = func_001E6978(func_001190D0(8));
            func_001E7360(p, 0x9982E501, func_00246258(it));
            func_001E70C0(p, 0xC4745838, name);
            if (it->IsActive()) {
                v = 0;
                if (func_00246C88(it)) {
                    func_001E7DE8(prm, 0xC22A2B72, &v, 0);
                    func_003331D0(buf, D_0038FF28, v);
                    switch (v) {
                    case 1:
                        func_00331678(buf, D_00373820);
                        break;
                    case 2:
                        func_00331678(buf, D_00373830);
                        break;
                    case 3:
                        func_00331678(buf, D_00373840);
                        break;
                    }
                    func_001E70C0(p, 0xBB48AF8B, buf);
                } else
                if (func_001E8398(prm, 0x96963902, &type, 0)) {
                    if (type == 0xCD66C8AE) {
                        func_001E7DE8(prm, 0xC22A2B72, &v, 0);
                        func_003331D0(buf, D_0038FF30, func_001044A8(v, ','));
                        func_001E70C0(p, 0xBB48AF8B, buf);
                    } else if (type == 0x906B67BA) {
                        t = 0;
                        func_001E7DE8(prm, 0xC22A2B72, &t, 0);
                        sec = t / 1000;
                        min = sec / 60;
                        sec = sec - min * 60;
                        int ms = t % 1000 / 10;
                        func_003331D0(buf, D_00373850, min, sec, ms);
                        func_001E70C0(p, 0xBB48AF8B, buf);
                    }
                } else {
                    func_001E7360(p, 0, 0x0C80E196);
                }
            }
            func_001F0210(0x380AEA65, p, 0, 0, 0);
            if (p)
                func_001E6AE8(p, 3);
        }
    }
    func_001E6518(a1);
    func_001E6518(a2);
    if (a1)
        func_001E8DE8(a1, 3);
    if (a2)
        func_001E8DE8(a2, 3);
}
