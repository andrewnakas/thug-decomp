struct Name_002CE7F0 {
    char c[8];
};

struct Stat_002CE7F0 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Parm_002CE7F0 {
    int m0;
    char* m4;
    int m8;
    char* mC;
    int m10;
};

struct Opt_002CE7F0 {
    int m0;
    int m4;
};

extern Name_002CE7F0 D_00392A50[];
extern Name_002CE7F0 D_00392A58[];
extern Name_002CE7F0 D_00392A60[];
extern Name_002CE7F0 D_00392A68[];
extern Name_002CE7F0 D_00392A70[];
extern Name_002CE7F0 D_00392A78[];
extern char D_00392A80[];
extern char D_0037AF58[];
extern char D_0037AF78[];
extern char D_0037AF98[];
extern char D_0037AFB8[];
extern char D_0037AFD8[];
extern char D_0037AFF8[];
extern void* D_00388A70;
extern int D_0038880C;
extern int D_0038882C;

extern "C" char* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void* func_00110E38(char* path, char* mode);
extern "C" int func_00110F68(void* buf, int size, int n, void* f);
extern "C" int func_00110EF8(void* f);
extern "C" int func_002CE7B0();
extern "C" void* func_0031BB90();
extern "C" void func_0031BB30(void* t, int p);
extern "C" void* func_003315B8(void* p, int v, int n);
extern "C" int func_00331370(void* a, void* b, int n);
extern "C" int func_100BB20(Parm_002CE7F0* p, int a, int b, int c, Opt_002CE7F0* o);
extern "C" int func_100BFC8(int a, int b, unsigned short c);
extern "C" int func_100C050(int* a, char* buf, int n, int* b);
extern "C" int func_100C0D0();
extern "C" int func_100BF70(Stat_002CE7F0* s);
extern "C" void func_100BB60();
static inline int Recv_002CE7F0(int* len, char* buf, int* got) { return func_100C050(got, buf, 0x200, len); }

extern "C" int func_002CE7F0(int conn, int addr, unsigned short port, int opt, Stat_002CE7F0* st)
{
    int result = 0;
    char* buf;
    char* name = 0;
    void* f = 0;
    Parm_002CE7F0 p;
    Stat_002CE7F0 prev;
    Opt_002CE7F0 o;
    char data[0x200];
    int len;
    int got = 0;
    Name_002CE7F0 n0 = D_00392A50[0];
    Name_002CE7F0 n1 = D_00392A58[0];
    Name_002CE7F0 n2 = D_00392A60[0];
    Name_002CE7F0 n3 = D_00392A68[0];
    Name_002CE7F0 n4 = D_00392A70[0];
    Name_002CE7F0 n5 = D_00392A78[0];
    buf = func_0010A638(D_00388A70, 0x10000, 1, 0);
    if (D_0038880C == 2) {
        if (D_0038882C == 1) {
            f = func_00110E38(D_0037AF58, D_00392A80);
            name = n0.c;
        } else {
            f = func_00110E38(D_0037AF78, D_00392A80);
            name = n1.c;
        }
    } else if (D_0038880C == 3) {
        f = func_00110E38(D_0037AF98, D_00392A80);
        name = n4.c;
    } else if (D_0038880C == 5) {
        f = func_00110E38(D_0037AFB8, D_00392A80);
        name = n3.c;
    } else if (D_0038880C == 6) {
        f = func_00110E38(D_0037AFD8, D_00392A80);
        name = n5.c;
    } else if (D_0038880C == 4) {
        f = func_00110E38(D_0037AFF8, D_00392A80);
        name = n2.c;
    }
    func_00110F68(buf, 1, 0x10000, f);
    func_00110EF8(f);
    int pri = func_002CE7B0();
    func_0031BB30(func_0031BB90(), 0x31);
    func_003315B8(st, 0, 0x10);
    func_003315B8(&prev, 0, 0x10);
    func_003315B8(&p, 0, 0x14);
    if (opt > 0) {
        func_003315B8(&o, 0, 8);
        o.m4 = 0x30;
        o.m0 = opt;
    }
    p.m0 = 1;
    p.m10 = 0x10000;
    p.m4 = name;
    p.m8 = 4;
    p.mC = buf;
    int r;
    if (opt > 0)
        r = func_100BB20(&p, 0x30, 0, 0, &o);
    else
        r = func_100BB20(&p, 0x30, 0, 0, 0);
    if (r < 0) {
        func_100BF70(st);
        result = r;
        goto done;
    }
    if (conn) {
        r = func_100BFC8(1, addr, port);
        if (r < 0) {
            func_100BF70(st);
            result = r;
            goto done;
        }
        r = Recv_002CE7F0(&len, data, &got);
        if (r < 0) {
            func_100BF70(st);
            result = r;
            goto done;
        }
    }
    r = func_100C0D0();
    if (r < 0) {
        func_100BF70(st);
        result = r;
    } else {
            for (;; prev = *st) {
                r = func_100BF70(st);
                if (r < 0) {
                    result = r;
                    break;
                }
                if (func_00331370(&prev, st, 0x10)) {
                    if (st->m0 == 5) {
                        prev = *st;
                        break;
                    }
                    if (st->m0 == 6 || st->m0 == 7) {
                        result = -1;
                        break;
                    }
                }
            }
    }
done:
    func_100BB60();
    func_0031BB30(func_0031BB90(), pri);
    if (buf)
        func_0010A8D8(D_00388A70, buf);
    return result;
}
