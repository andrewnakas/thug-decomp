/* fuzzy: 90.3 */
/* nonmatch func_002C7F88: best earlier draft (thug-claude-lane3/work/w53/p2/func_002C7F88.fail), 174 of 347 words differ (size 0x55c, want 0x56c). */
struct Box_002C7F88 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Move_002C7F88 {
    Box_002C7F88 box[2];
    int rot[2];
    int b[2];
    int c[2];
    char pad24[0x48 - 0x24];
    int m48;
    char pad4C[0x54 - 0x4C];
    Box_002C7F88* GetBox(int i) { return &box[i]; }
};

struct Board_002C7F88 {
    char pad0[0x352C];
    Box_002C7F88 m352C;
};

struct Obj_002C7F88;
extern "C" Move_002C7F88* func_002C0640(Board_002C7F88* b, Box_002C7F88* box, int* out);
extern "C" int func_002C9EB0(Obj_002C7F88* o, Move_002C7F88* m);
extern "C" void func_002C0BE0(Board_002C7F88* b, Move_002C7F88* p);
extern "C" void func_002C0730(Board_002C7F88* b, Move_002C7F88* p);
extern "C" void func_002BD7D8(Board_002C7F88* b, int v);

struct Sub_002C7F88 {
    int m0;
    Board_002C7F88* m4;
    Board_002C7F88* Get() { return m4; }
};

struct Obj_002C7F88 {
    char pad0[0x4];
    Sub_002C7F88 m4;
    char padC[0x4];
    Box_002C7F88 m10;
    char pad16[0x80 - 0x16];
    Move_002C7F88 m80;
    int Nudge(int rot, int db, int dc);
};

int Obj_002C7F88::Nudge(int rot, int db, int dc)
{
    Move_002C7F88 s;
    Box_002C7F88 gb;
    int idx;
    Move_002C7F88* src = func_002C0640(m4.Get(), &m10, &idx);
    if (!src || !func_002C9EB0(this, src)) return 0;
    s = *src;
    int changed = 0;
    if (rot) {
        s.rot[idx] -= rot;
        s.b[idx] = 0;
        s.c[idx] = 0;
        changed = 1;
    }
    if (db) {
        s.b[idx] += db;
        if (s.b[idx] < 0) {
            s.b[idx] = 0;
        } else if (s.b[idx] >= 7) {
            s.b[idx] = 6;
        }
        changed = 1;
    }
    if (dc) {
        s.c[idx] += dc;
        if (s.c[idx] < 0) s.c[idx] = 0;
        if (s.c[idx] >= 7) s.c[idx] = 6;
        changed = 1;
    }
    if (changed) {
        func_002C0BE0(m4.Get(), src);
        s.rot[idx] &= 3;
        gb = m4.Get()->m352C;
        int r = s.rot[idx];
        if (r == 0) {
            if (s.GetBox(idx)->z - s.c[idx] < gb.z) s.c[idx]--;
            if (gb.z + gb.d < s.GetBox(idx)->d + s.GetBox(idx)->z + s.b[idx]) s.b[idx]--;
        } else if (r == 2) {
            if (s.GetBox(idx)->z - s.b[idx] < gb.z) s.b[idx]--;
            if (gb.z + gb.d < s.GetBox(idx)->d + s.GetBox(idx)->z + s.c[idx]) s.c[idx]--;
        } else if (r == 1) {
            if (s.GetBox(idx)->x - s.c[idx] < gb.x) s.c[idx]--;
            if (gb.x + gb.w < s.GetBox(idx)->w + s.GetBox(idx)->x + s.b[idx]) s.b[idx]--;
        } else if (r == 3) {
            if (s.GetBox(idx)->x - s.b[idx] < gb.x) s.b[idx]--;
            if (gb.x + gb.w < s.GetBox(idx)->w + s.GetBox(idx)->x + s.c[idx]) s.c[idx]--;
        }
        for (idx = 0; idx < 2; idx++) {
        }
        func_002C0730(m4.Get(), &s);
        func_002BD7D8(m4.Get(), 0);
        if (m80.m48 == 1) m80 = s;
    }
    return 1;
}
