extern char D_00379E70[];

struct Player_002B4250;

struct LNode_002B4250 {
    int m0;
    Player_002B4250* data;
    int m8;
    LNode_002B4250* next;
    LNode_002B4250* prev;
    Player_002B4250* GetData() { return data; }
    LNode_002B4250* Valid() { return (int)data != -1 ? this : 0; }
    virtual ~LNode_002B4250();
};

struct Player_002B4250 : LNode_002B4250 {
    char m18[0x10];
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    char m44[0x20];
    char m64[0x20];
    int m84;
    int m88;
    char m8C;
    int m90;
    int m94;
    int m98;
    int m9C;
    int mA0;
    int mA4;
    int mA8;
    void* mAC;
};

struct It_002B4250 {
    int m0;
    LNode_002B4250* cur;
    void* vt;
    It_002B4250() { vt = D_00379E70; cur = 0; }
    ~It_002B4250() { vt = D_00379E70; }
    Player_002B4250* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Player_002B4250* Advance(LNode_002B4250* c) {
        cur = c->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Player_002B4250* First(LNode_002B4250* h) {
        cur = h;
        return Next();
    }
};

struct Net_002B4250 {
    char pad[0x124];
    LNode_002B4250 m124;
};

struct Heap_002B4250 {
    char pad[0x104];
    int m104;
};

extern Heap_002B4250* D_00388A70;
extern char D_003799A0[];
extern char D_00379AC8[];
extern char D_00379B78[];
extern char D_00379B88[];
extern char D_00379B98[];
extern char D_00379BA8[];
extern char D_00379BB8[];
extern char D_00379BC8[];
extern char D_00379BD8[];
extern char D_00379BE8[];
extern char D_00379BF8[];
extern char D_00379C08[];
extern char D_00392460[];
extern char D_00392488[];
extern char D_00392490[];
extern char D_00392498[];
extern char D_003924A0[];
extern char D_003924A8[];
extern char D_003924B0[];
extern "C" void func_0010A950(Heap_002B4250* p, int v);
extern "C" void func_0010A9B0(Heap_002B4250* p);
extern "C" void* func_001046B0(int size);
extern "C" Player_002B4250* func_002B51A0(void* p);
extern "C" char* func_00332088(char* dst, const char* src, int n);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" int func_002DFBD8(void* c);
extern "C" int func_002DF708(void* c);
extern "C" int func_002DF6D8(void* c);
extern "C" int func_00305F28(void* p);
extern "C" int func_002DF730(void* c);
extern "C" int func_002DF718(void* c);
extern "C" int func_002DF6E0(void* c);
extern "C" char* func_002DF4A0(void* c, char* name, char* def);
extern "C" int func_002DF4E0(void* c, char* name, int def);
extern "C" int func_002DF5A8(void* c, char* name, int def);
extern "C" int func_002DF660(void* c, int i, char* name, int def);
extern "C" char* func_002DF610(void* c, int i, char* name, char* def);
extern "C" void func_002B53F0(Player_002B4250* p, char* s, int v);
extern "C" int func_002DF6B0(void* c);
extern "C" int func_002DF6C0(void* c);
extern "C" void func_002B3D38(Net_002B4250* n, Player_002B4250* p, int v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_002B4D80(Net_002B4250* n, int v);
extern "C" void func_002B4BF8(Net_002B4250* n);
extern "C" void func_002B5278(Player_002B4250* p);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001E73C8(void* p, char* s, void* v);

extern "C" void func_002B4250(void* a, int ok, char* name, void* c, int u0, int mode, int u1, Net_002B4250* net)
{
    if (!ok) return;
    switch (mode) {
    case 0: {
        func_0010A950(D_00388A70, D_00388A70->m104);
        Player_002B4250* p = func_002B51A0(func_001046B0(0xC8));
        p->mAC = c;
        func_00332088(p->m18, name, 0xF);
        p->m18[0xF] = 0;
        p->m30 = func_002DFBD8(c);
        if (func_002DF708(c)) {
            if (func_002DF6D8(c) == func_00305F28(a)) {
                p->m28 = func_002DF730(c);
                p->m2C = 0x141E;
            } else if (func_002DF718(c)) {
                p->m28 = func_002DF6D8(c);
                p->m2C = func_002DF6E0(c);
            } else {
                p->m28 = func_002DF6D8(c);
                p->m2C = func_002DF6E0(c);
                p->m30 = 9999;
                p->m98 = 0;
            }
        } else if (func_002DF718(c)) {
            p->m28 = func_002DF6D8(c);
            p->m2C = func_002DF6E0(c);
        } else {
            p->m28 = func_002DF6D8(c);
            p->m2C = func_002DF6E0(c);
            p->m30 = 9999;
            p->m98 = 0;
        }
        func_00331A9C(p->m44, func_002DF4A0(c, D_00392488, D_00392490));
        func_00331A9C(p->m64, func_002DF4A0(c, D_00379B78, D_00392490));
        p->m34 = func_002DF4E0(c, D_00379B88, 1);
        p->m38 = func_002DF4E0(c, D_00379B98, 8);
        p->m3C = func_002DF4E0(c, D_00379BA8, 0);
        p->m40 = func_002DF4E0(c, D_00379BB8, 1);
        p->m84 = func_002DF5A8(c, D_00379BC8, 0);
        p->m88 = func_002DF5A8(c, D_00392498, 0);
        p->m90 = func_002DF4E0(c, D_00379BD8, 0);
        p->m94 = func_002DF4E0(c, D_003924A0, 0) != 0;
        p->m8C = func_002DF4E0(c, D_00379BE8, 2);
        for (int k = 0; k < p->m34; k++) {
            int v = func_002DF660(c, k, D_003924A8, 0);
            func_002B53F0(p, func_002DF610(c, k, D_003924B0, D_00392490), v);
        }
        LNode_002B4250* head = &net->m124;
        p->prev = head->prev;
        p->next = head;
        head->prev->next = p;
        head->prev = p;
        if (func_002DF6B0(c)) {
            int n = 0;
            for (LNode_002B4250* x = head->next->Valid(); x; x = x->next->Valid()) n++;
            func_002B3D38(net, p, n - 1);
            func_001F0370(D_003799A0, 0, 0, 0);
            p->mA4 = 1;
        }
        func_0010A9B0(D_00388A70);
        break;
    }
    case 2: {
        It_002B4250 it;
        void* s = func_001E6978(func_001190D0(8));
        func_001E73C8(s, D_00379BF8, c);
        func_001F0370(D_00379C08, s, 0, 0);
        if (s) func_001E6AE8(s, 3);
        Player_002B4250* d = it.First(&net->m124);
        if (d) {
            It_002B4250* pi = &it;
            do {
                Player_002B4250* nx = pi->Advance(it.cur);
                if (d->mAC == c) {
                    delete d;
                    break;
                }
                d = nx;
            } while (d);
        }
        func_001F0370(D_003799A0, 0, 0, 0);
        break;
    }
    case 3:
        func_002B4D80(net, 0);
        func_002B4BF8(net);
        func_001F0370(D_003799A0, 0, 0, 0);
        break;
    case 1: {
        It_002B4250 it;
        func_002DF6C0(c);
        for (Player_002B4250* d = it.First(&net->m124); d; d = it.Next()) {
            if (d->mAC != c) continue;
            func_00332088(d->m18, name, 0xF);
            d->m18[0xF] = 0;
            if (d->m98) d->m30 = func_002DFBD8(c);
            func_00331A9C(d->m44, func_002DF4A0(c, D_00392488, D_00392490));
            func_00331A9C(d->m64, func_002DF4A0(c, D_00379B78, D_00392490));
            d->m34 = func_002DF4E0(c, D_00379B88, 1);
            d->m38 = func_002DF4E0(c, D_00379B98, 8);
            d->m3C = func_002DF4E0(c, D_00379BA8, 0);
            d->m40 = func_002DF4E0(c, D_00379BB8, 1);
            d->m84 = func_002DF5A8(c, D_00379BC8, 0);
            d->m88 = func_002DF5A8(c, D_00392498, 0);
            d->m90 = func_002DF4E0(c, D_00379BD8, 0);
            d->m94 = func_002DF4E0(c, D_003924A0, 0) != 0;
            d->m8C = func_002DF4E0(c, D_00379BE8, 2);
            func_002B5278(d);
            for (int k = 0; k < d->m34; k++) {
                int v = func_002DF660(c, k, D_003924A8, 0);
                func_002B53F0(d, func_002DF610(c, k, D_003924B0, D_00392490), v);
            }
            if (d->mA4 == 0 && func_002DF6B0(c)) {
                func_002B3D38(net, d, 0);
                func_001F0370(D_003799A0, 0, 0, 0);
                d->mA4 = 1;
            }
            if (d->mA8 == 0 && func_002DF6C0(c)) {
                d->mA8 = 1;
                if (d->mA0) {
                    void* s = func_001E6978(func_001190D0(8));
                    func_001E73C8(s, D_00392460, c);
                    func_001F0370(D_00379AC8, s, 0, 0);
                    if (s) func_001E6AE8(s, 3);
                }
            }
            break;
        }
        break;
    }
    }
}
