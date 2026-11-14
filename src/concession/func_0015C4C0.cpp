/* force: {"kind": "spill", "order": [501, 497, 496, 494, 498]} */
/* force: {"kind": "sched", "pass": 2, "block": 8, "clock": 4, "first": [1724, 1615]} */
/* Grass field setup: samples the ground height (feeler ray from +50000 down to -50000) on a 128-unit grid over
   the world bounding box (clamped to 0x15F x 0x12D cells), quantises heights into a shared table (within 0x1E0),
   keeps for each cell the highest of itself and its +x/+z/+xz neighbours, packs every row's non-empty span into
   the cell stream at D_003CBDE0, prints the grid statistics and randomises the blade tables. */
typedef int qword __attribute__((mode(TI)));

struct Vec_0015C4C0 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        };
    };
};

struct Box_0015C4C0 {
    Vec_0015C4C0 min;
    Vec_0015C4C0 max;
};

extern "C" void func_00183CB8(int obj, int* ref);

struct Ref_0015C4C0 {
    int m_p;
    ~Ref_0015C4C0()
    {
        if (m_p) {
            func_00183CB8(m_p, &m_p);
            m_p = 0;
        }
    }
};

struct Feeler_0015C4C0 {
    Vec_0015C4C0 m_start;
    Vec_0015C4C0 m_end;
    char pad20[0xA0 - 0x20];
    Vec_0015C4C0 m_point;
    Vec_0015C4C0 m_normal;
    Ref_0015C4C0 m_ref;
    char padC4[0xE0 - 0xC4];
};

struct Row_0015C4C0 {
    unsigned short m_start;
    unsigned short m_end;
    unsigned short m_offset;
};

struct Tex_0015C4C0 {
    char pad[0x1C];
    int m1C;
    char pad20[0xC];
    int m2C;
    int Get() { return m2C ? m2C : m1C; }
};

struct Field_0015C4C0 {
    char pad0[0x28];
    int m_enabled;
    int m_ready;
    char pad30[0x4C - 0x30];
    int m_tex;
    int m_tex2;
    unsigned char* m_cells;
    Row_0015C4C0* m_rows;
    int m_heights[0x100];
    int m_cols;
    int m_rowCount;
    float m_originX;
    float m_originZ;
    char pad46C[0x490 - 0x46C];
    unsigned char m_blade[0x400];
    unsigned char m_bladeX[0x400];
    unsigned char m_bladeZ[0x400];
    int m_1090;
    char pad1094[0x1230 - 0x1094];
    int m_left[32];
    int m_12B0;
};

struct Mem_0015C4C0 {
    char pad[0xD8];
    void* m_D8;
};

extern Mem_0015C4C0* D_00388A70;
extern void* D_00393EF8;
extern Row_0015C4C0 D_003CBDE0[];
extern char D_00360688[];

extern "C" void func_00101F38(Box_0015C4C0* b);
extern "C" Box_0015C4C0* func_001324B8(Box_0015C4C0* b);
extern "C" void func_0010A950(Mem_0015C4C0* mem, void* heap);
extern "C" void* func_0010A638(Mem_0015C4C0* mem, int size, int align, void* heap);
extern "C" void func_0010A9B0(Mem_0015C4C0* mem);
extern "C" void func_0010A8D8(Mem_0015C4C0* mem, void* p);
extern "C" void func_00209240(Feeler_0015C4C0* f);
extern "C" void func_00209360(Feeler_0015C4C0* f, Vec_0015C4C0* a);
extern "C" void func_00209370(Feeler_0015C4C0* f, Vec_0015C4C0* b);
extern "C" int func_002093E8(Feeler_0015C4C0* f, int a, int b);
extern "C" void func_00103F28(const char* fmt, ...);
extern "C" int func_00100030(int n);
extern "C" Tex_0015C4C0* func_00139468(void* table, unsigned int id);

static inline int Abs(int v)
{
    return v < 0 ? -v : v;
}

void func_0015C4C0(Field_0015C4C0* o)
{
    Box_0015C4C0 box;
    o->m_ready = 0;
    func_00101F38(&box);
    Box_0015C4C0* world = func_001324B8(&box);
    if (!world)
        return;

    int x0 = (int)world->min.x / 128 - 1;
    int x1 = (int)world->max.x / 128 + 1;
    int z0 = (int)world->min.z / 128 - 1;
    int z1 = (int)world->max.z / 128 + 1;
    if (x1 - x0 > 0x15E) {
        int d = (x1 - x0 - 0x15E) / 2;
        x0 += d;
        x1 -= d;
    }
    if (z1 - z0 > 0x12C) {
        int d = (z1 - z0 - 0x12C) / 2;
        z0 += d;
        z1 -= d;
    }
    int numHeights = 0;
    o->m_originX = (float)(x0 << 7);
    o->m_originZ = (float)(z0 << 7);
    o->m_cols = x1 - x0 + 1;
    o->m_rowCount = z1 - z0 + 1;

    func_0010A950(D_00388A70, D_00388A70->m_D8);
    unsigned char* grid = (unsigned char*)func_0010A638(D_00388A70, o->m_cols * o->m_rowCount, 1, 0);
    func_0010A9B0(D_00388A70);

    Feeler_0015C4C0 f;
    func_00209240(&f);
    int x, z;
    for (z = z0; z <= z1; z++) {
        for (x = x0; x <= x1; x++) {
            int idx = (z - z0) * o->m_cols + (x - x0);
            Vec_0015C4C0 v;
            v.x = (float)(x << 7);
            v.y = 50000.0f;
            v.w = 1.0f;
            v.z = (float)(z << 7);
            func_00209360(&f, &v);
            v.y = -50000.0f;
            func_00209370(&f, &v);
            int h;
            if (func_002093E8(&f, 0, 0))
                h = (int)(f.m_point.y * 16.0f);
            else
                h = 800000;
            unsigned char* cell = grid + idx;
            int found = -1;
            for (int i = 0; i < numHeights; i++) {
                if (Abs(o->m_heights[i] - h) < 0x1E0) {
                    found = i;
                    break;
                }
            }
            if (found != -1) {
                *cell = found;
            } else {
                *cell = numHeights;
                o->m_heights[numHeights] = h;
                numHeights++;
            }
        }
    }

    for (z = z0; z <= z1; z++) {
        for (x = x0; x <= x1; x++) {
            int c = (z - z0) * o->m_cols + (x - x0);
            int r = (z - z0) * o->m_cols + (x + 1 - x0);
            int d = (z + 1 - z0) * o->m_cols + (x - x0);
            int rd = (z + 1 - z0) * o->m_cols + (x + 1 - x0);
            if (o->m_heights[grid[c]] < o->m_heights[grid[r]])
                grid[c] = grid[r];
            if (o->m_heights[grid[c]] < o->m_heights[grid[d]])
                grid[c] = grid[d];
            if (o->m_heights[grid[c]] < o->m_heights[grid[rd]])
                grid[c] = grid[rd];
        }
    }

    o->m_rows = D_003CBDE0;
    o->m_cells = (unsigned char*)(D_003CBDE0 + o->m_rowCount);
    unsigned short total = 0;
    /* Equivalence (asm): rowCount+1 rows are packed. Entry test `bltz $v0` at 0x15C9B4 (skip only if rowCount < 0),
       loop test `slt $v0,$v0,$a2; beql $v0,$zero` at 0x15CAEC (continue while !(rowCount < z+1)). */
    for (z = 0; z <= o->m_rowCount; z++) {
        unsigned short first = 0;
        unsigned short last = o->m_cols - 1;
        int any = 0;
        for (x = 0; x < o->m_cols; x++) {
            if (o->m_heights[grid[z * o->m_cols + x]] != 800000) {
                if (!any) {
                    first = x;
                    any = 1;
                } else {
                    last = x;
                }
            }
        }
        if (first < last) {
            o->m_rows[z].m_start = first;
            o->m_rows[z].m_end = last;
            o->m_rows[z].m_offset = total;
            for (x = first; x <= last; x++) {
                o->m_cells[total] = grid[z * o->m_cols + x];
                total++;
            }
        } else {
            o->m_rows[z].m_start = 0x4000;
            o->m_rows[z].m_end = 0;
            o->m_rows[z].m_offset = 0;
        }
    }
    func_0010A8D8(D_00388A70, grid);
    func_00103F28(D_00360688, o->m_cols * o->m_rowCount, o->m_rowCount * 6 + total, numHeights);

    for (int i = 0; i < 0x400; i++) {
        o->m_blade[i] = 0xFF;
        o->m_bladeX[i] = func_00100030(0xFF);
        o->m_bladeZ[i] = func_00100030(0xFF);
    }
    o->m_enabled = 0;
    o->m_tex = 0;
    o->m_1090 = 0x19B;
    Tex_0015C4C0* t = func_00139468(D_00393EF8, 0x45C7EB0F);
    if (t)
        o->m_tex = t->Get();
    t = func_00139468(D_00393EF8, 0xC97C5A4C);
    if (t)
        o->m_tex2 = t->Get();
    o->m_ready = 1;
    for (int i = 31; i >= 0; i--)
        o->m_left[i] = 0;
    o->m_12B0 = 0;
}
