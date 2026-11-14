/* force: {"kind": "lfr", "block": 0, "reg": 120, "hard": 3} */
typedef int qword __attribute__((mode(TI)));

struct Vec_001CEA68 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

extern "C" void func_00183CB8(void* p, void* pp);

struct Coll_001CEA68 {
    Vec_001CEA68 start;
    Vec_001CEA68 end;
    char pad20[0xA0 - 0x20];
    Vec_001CEA68 hit;
    char padB0[0xC0 - 0xB0];
    struct Ref {
        void* p;
        ~Ref()
        {
            if (p) {
                func_00183CB8(p, this);
                p = 0;
            }
        }
    } mC0;
    char padC4[0xE0 - 0xC4];
};

extern "C" void func_00209240(Coll_001CEA68* c);
extern "C" int func_002093E8(Coll_001CEA68* c, int a, int b);
extern "C" int func_00209A00(Coll_001CEA68* c);
extern "C" void* func_00209A30(Coll_001CEA68* c);

struct Obj_001CEA68 {
    void* FindGround(const Vec_001CEA68& pos, Vec_001CEA68* out);
};

void* Obj_001CEA68::FindGround(const Vec_001CEA68& pos, Vec_001CEA68* out)
{
    int tries = 0;
    Coll_001CEA68 down;
    func_00209240(&down);
    down.start = pos;
    down.end = pos;
    down.start.y += 400.0f;
    down.end.y += 6.0f;
    Coll_001CEA68 up;
    func_00209240(&up);
    for (;;) {
        if (++tries == 10 || !func_002093E8(&down, 1, 0) || !func_00209A00(&down)) {
            return 0;
        }
        up.end = down.hit;
        up.start = pos;
        up.end.y += 0.1f;
        if (!func_002093E8(&up, 1, 0)) {
            *out = down.hit;
            return func_00209A30(&down);
        }
        down.start = down.hit;
        down.start.y -= 0.1f;
    }
}
