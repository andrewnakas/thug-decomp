/* fuzzy: 96.3 */
struct Entry_002D41E0;
struct Node_002D41E0 {
    int m0;
    void* data;
    int m8;
    Node_002D41E0* next;
    Node_002D41E0* prev;
    Entry_002D41E0* GetData() { return (Entry_002D41E0*)data; }
    Node_002D41E0* Valid(unsigned k = 0) { return k < ~(unsigned)data ? this : 0; }
    void AddAfter(Node_002D41E0* n) {
        n->prev = this;
        n->next = next;
        next->prev = n;
        next = n;
    }
};

struct Entry_002D41E0 : Node_002D41E0 {
    char pad14[4];
    int m18;
    char m1C[0x18];
    Node_002D41E0 m34;
};

struct Item_002D41E0 : Node_002D41E0 {
    char pad14[4];
    char m18[0x80];
    char m98[0x18];
    char mB0[0x10];
    char mC0[0x10];
    char mD0[0x21];
    char mF1[0x103];
    int m1F4;
    char pad1F8[8];
    int m200;
    int m204;
    int m208;
    int m20C;
    int m210;
    int m214;
};

struct It_002D41E0 {
    int m0;
    Node_002D41E0* cur;
    Entry_002D41E0* Next() {
        cur = cur->next->Valid();
        if (!cur)
            return 0;
        return cur->GetData();
    }
    Entry_002D41E0* First(Node_002D41E0* h) {
        cur = h;
        return Next();
    }
};

struct Pool_002D41E0 {
    char pad[0x104];
    int m104;
    int m108;
};

struct Dl_002D41E0 {
    void* m0;
    int m4;
    int m8;
    int mC;
    int m10;
    char pad14[4];
    char* m18;
    unsigned int m1C;
    char pad20[0x324 - 0x20];
    void* m324;
    char pad328[0x350 - 0x328];
    Node_002D41E0 m350;
    char pad364[4];
    It_002D41E0 m368;
    char pad370[4];
    Entry_002D41E0* m374;
    unsigned int m378;
    char m37C[0x40];
    unsigned int m3BC;
    unsigned int m3C0;
    unsigned int m3C4;
    unsigned int m3C8;
};

extern Pool_002D41E0* D_00388A70;
extern char D_00392C28[];
extern char D_00392C30[];
extern char D_00392C38[];
extern char D_00392C40[];
extern char D_00392C48[];
extern char D_0037BE78[];
extern char D_0037BE98[];
extern char D_0037BEC0[];
extern char D_0037BED0[];
extern char D_0037BEE8[];

extern "C" unsigned int func_0010FC30();
extern "C" void func_0010A8D8(Pool_002D41E0* p, void* m);
extern "C" void func_0010A950(Pool_002D41E0* p, int v);
extern "C" void func_0010A9B0(Pool_002D41E0* p);
extern "C" void func_002E4A08(void* p);
extern "C" void func_002E49E8();
extern "C" void func_001F0210(unsigned int id, void* s, int a, int b, int c);
extern "C" void func_001F0370(char* name, void* s, int a, int b);
extern "C" void func_001048F0(void* p);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" void* func_001190D0(int n);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* o, int n);
extern "C" int func_001F0D78(char* s);
extern "C" void func_001E7A30(void* s, int name, int type, char* v);
extern "C" void func_001E73C8(void* s, char* name, unsigned int v);
extern "C" void func_001E7138(void* s, char* name, char* v);
extern "C" char* func_00336558(char* s, char* delim);
extern "C" char* func_003364D8(char* s, char* delim);
extern "C" char* func_00331A9C(char* d, char* s);
extern "C" int func_00334120(char* s);
extern "C" void* func_001046B0(int n);
extern "C" Entry_002D41E0* func_002D63F0(void* p);
extern "C" Item_002D41E0* func_002D65A8(void* p);
extern "C" void func_002D4DC0(Dl_002D41E0* d, Entry_002D41E0* e);
extern "C" void func_002D5050(Dl_002D41E0* d);

static inline bool Elapsed_002D41E0(unsigned int ms, unsigned int now, unsigned int start) { return now - start > ms; }

struct Task_002D41E0 {
    char pad[0x20];
    Dl_002D41E0* m20;
    void Update();
};

void Task_002D41E0::Update()
{
    Dl_002D41E0* d = m20;
    char num[0x10];
    char name[0x20];
    char tmp[0x80];
    if (Elapsed_002D41E0(25000, func_0010FC30(), d->m1C)) {
        if (d->m4 && d->m18)
            func_0010A8D8(D_00388A70, d->m18);
        func_002E4A08(d->m324);
        func_001F0210(d->m3BC, 0, 0, 0, 0);
        d->m4 = 0;
        func_001048F0(d->m0);
        return;
    }
    func_0010A950(D_00388A70, D_00388A70->m104);
    func_002E49E8();
    func_0010A9B0(D_00388A70);
    if (d->m8 < 100) {
        if (d->m4 == 3 || d->m4 == 6) {
            func_003331D0(num, D_00392C28, d->m8);
            void* s = func_001E6978(func_001190D0(8));
            func_001E7A30(s, func_001F0D78(D_00392C30), 3, num);
            func_001F0210(d->m3C4, s, 0, 0, 0);
            if (s)
                func_001E6AE8(s, 3);
        }
        return;
    }
    if (d->m4 == 3 || d->m4 == 6) {
        if (d->m18)
            func_0010A8D8(D_00388A70, d->m18);
    }
    int m = d->m4;
    int st = m;
    if (m == 3 || m == 6 || m == 4) {
        func_001048F0(d->m0);
        d->m4 = 0;
        if (d->mC == 1) {
            void* s = func_001E6978(func_001190D0(8));
            func_001E73C8(s, D_00392C38, d->m378);
            if (st == 4)
                func_001F0370(D_0037BE78, s, 0, 0);
            else
                func_001F0210(d->m3C0, s, 0, 0, 0);
            if (s)
                func_001E6AE8(s, 3);
        } else if (d->m10 == 11) {
            func_001F0210(d->m3C8, 0, 0, 0, 0);
        } else {
            func_001F0210(d->m3BC, 0, 0, 0, 0);
        }
        if (st == 4 && d->m18)
            func_0010A8D8(D_00388A70, d->m18);
        return;
    }
    if (m == 1) {
        if (d->mC == 1) {
        func_0010A950(D_00388A70, D_00388A70->m108);
        char* tok = func_00336558(d->m18, D_00392C40);
        if (tok) {
            Node_002D41E0* h = &d->m350;
            do {
                Entry_002D41E0* e = func_002D63F0(func_001046B0(0x4C));
                h->AddAfter(e);
                func_00331A9C(e->m1C, tok);
                tok = func_00336558(0, D_00392C40);
            } while (tok);
            d->m374 = d->m368.First(&d->m350);
            if (d->m374->m18)
                d->m374 = d->m368.Next();
            d->m4 = 0;
            if (d->m18)
                func_0010A8D8(D_00388A70, d->m18);
            func_002D4DC0(d, d->m374);
        }
        } else {
            d->m4 = 0;
            func_001048F0(d->m0);
            if (d->m18)
                func_0010A8D8(D_00388A70, d->m18);
            func_001F0210(d->m3BC, 0, 0, 0, 0);
            return;
        }
    } else if (m == 2) {
        func_0010A950(D_00388A70, D_00388A70->m108);
        if (d->mC == 1) {
            char* tok = func_00336558(d->m18, D_00392C40);
            while (tok) {
                Item_002D41E0* it = func_002D65A8(func_001046B0(0x218));
                d->m374->m34.AddAfter(it);
                char* e = func_003364D8(tok, D_00392C48);
                *e = 0;
                func_00331A9C(name, tok);
                tok = e + 1;
                func_003331D0(it->m18, D_0037BE98, d->m37C, d->m374->m1C, name);
                e = func_003364D8(tok, D_00392C48);
                *e = 0;
                func_00331A9C(it->m98, tok);
                tok = e + 1;
                e = func_003364D8(tok, D_00392C48);
                *e = 0;
                func_00331A9C(it->mB0, tok);
                if (d->m378 == 0x5BE5569F) {
                    tok = e + 1;
                    e = func_003364D8(tok, D_00392C48);
                    *e = 0;
                    func_00331A9C(it->mC0, tok);
                    tok = e + 1;
                    e = func_003364D8(tok, D_00392C48);
                    *e = 0;
                    func_00331A9C(tmp, tok);
                    tok = e + 1;
                    it->m200 = func_00334120(tmp);
                    e = func_003364D8(tok, D_00392C48);
                    *e = 0;
                    func_00331A9C(tmp, tok);
                    tok = e + 1;
                    it->m204 = func_00334120(tmp);
                    e = func_003364D8(tok, D_00392C48);
                    *e = 0;
                    func_00331A9C(tmp, tok);
                    tok = e + 1;
                    it->m208 = func_00334120(tmp);
                    e = func_003364D8(tok, D_00392C48);
                    *e = 0;
                    func_00331A9C(tmp, tok);
                    tok = e + 1;
                    it->m20C = func_00334120(tmp);
                    e = func_003364D8(tok, D_00392C48);
                    *e = 0;
                    func_00331A9C(tmp, tok);
                    it->m210 = func_00334120(tmp);
                }
                if (d->m378 == 0x1E26FD3E) {
                    tok = e + 1;
                    e = func_003364D8(tok, D_00392C48);
                    *e = 0;
                    func_00331A9C(tmp, tok);
                    it->m1F4 = func_00334120(tmp);
                }
                if (d->m378 == 0x07364EA1) {
                    tok = e + 1;
                    e = func_003364D8(tok, D_00392C48);
                    *e = 0;
                    func_00331A9C(tmp, tok);
                    it->m214 = func_00334120(tmp);
                }
                if (d->m378 == 0x38DBE1D0) {
                    tok = e + 1;
                    e = func_003364D8(tok, D_00392C48);
                    *e = 0;
                    func_00331A9C(tmp, tok);
                    it->m208 = func_00334120(tmp);
                }
                tok = e + 1;
                e = func_003364D8(tok, D_00392C48);
                *e = 0;
                func_00331A9C(it->mD0, tok);
                func_00331A9C(it->mF1, e + 1);
                tok = func_00336558(0, D_00392C40);
            }
            d->m4 = 0;
            if (d->m18)
                func_0010A8D8(D_00388A70, d->m18);
            d->m374 = d->m368.Next();
            if (!d->m374 || d->m374->m18) {
                d->m374 = d->m368.First(&d->m350);
                func_001048F0(d->m0);
                void* s = func_001E6978(func_001190D0(8));
                func_001E7138(s, D_0037BEC0, d->m374->m1C);
                func_001E73C8(s, D_00392C38, d->m378);
                func_001F0370(D_0037BED0, s, 0, 0);
                if (s)
                    func_001E6AE8(s, 3);
            } else {
                func_002D4DC0(d, d->m374);
            }
        } else {
            d->m4 = 0;
            func_001048F0(d->m0);
            if (d->m18)
                func_0010A8D8(D_00388A70, d->m18);
            func_001F0210(d->m3BC, 0, 0, 0, 0);
        }
    } else {
        goto other;
    }
    func_0010A9B0(D_00388A70);
    return;
other:
    if (m == 5) {
        func_0010A950(D_00388A70, D_00388A70->m108);
        char* tok = func_00336558(d->m18, D_00392C40);
        while (tok) {
            Item_002D41E0* it = func_002D65A8(func_001046B0(0x218));
            d->m374->m34.AddAfter(it);
            func_003331D0(it->m18, D_0037BEE8, d->m37C, tok);
            char* e = func_003364D8(tok, D_00392C48);
            *e = 0;
            func_00331A9C(it->m98, tok);
            tok = e + 1;
            e = func_003364D8(tok, D_00392C48);
            *e = 0;
            func_00331A9C(it->mB0, tok);
            tok = e + 1;
            e = func_003364D8(tok, D_00392C48);
            *e = 0;
            func_00331A9C(it->mC0, tok);
            tok = e + 1;
            e = func_003364D8(tok, D_00392C48);
            *e = 0;
            func_00331A9C(it->mD0, tok);
            func_00331A9C(it->mF1, e + 1);
            tok = func_00336558(0, D_00392C40);
        }
        d->m4 = 0;
        func_001048F0(d->m0);
        if (d->m18)
            func_0010A8D8(D_00388A70, d->m18);
        func_002D5050(d);
        func_0010A9B0(D_00388A70);
    }
}
