/* fuzzy: 91.4 */
/* sym: _vt$13Base_00208400 = 0x0035D5C8 */
/* sym: _vt$13Head_00208400 = 0x0035D5B0 */

struct Heap_00208400 {
    char pad[0xD8];
    int m_D8;
};
extern Heap_00208400* D_00388A70;
extern "C" void func_0010A950(Heap_00208400* h, int ctx);
extern "C" void func_0010A9B0(Heap_00208400* h);
extern "C" int func_0010A830(Heap_00208400* h, int size, void* p, int f);
extern "C" int func_0010A798(Heap_00208400* h, int size, void* p, int f);
extern "C" void* func_0010BF10(void* p, int size);
extern "C" void* func_0010BDE0(int size);
extern "C" void func_0010BEB8(void* p);
extern "C" void* func_00331404(void* d, const void* s, int n);

struct Vec_00208400 {
    float x, y, z, w;
};

struct Box_00208400 {
    Vec_00208400 min;
    Vec_00208400 max;
};

struct Shape_00208400 {
    char pad[0x10];
    Box_00208400 box;
};

struct Obj_00208400 {
    int m0;
    int m4;
    Shape_00208400* m8;
};

struct Cell_00208400 {
    Box_00208400 box;
    int m20;
    int m24;
    int m28;
    Obj_00208400** m2C;
};

class Base_00208400 {
public:
    int m0;
    unsigned int m4;
    int m8;
    Base_00208400* mC;
    Base_00208400* m10;
    Base_00208400()
    {
        m4 = 0xFFFFFFFF;
        m8 = 0;
        mC = this;
        m10 = this;
    }
    virtual ~Base_00208400()
    {
        m10->mC = mC;
        mC->m10 = m10;
        mC = this;
        m10 = this;
    }
    virtual void Run();
    Base_00208400* Valid()
    {
        if (m4 == 0xFFFFFFFF) return 0;
        return this;
    }
};

class Head_00208400 : public Base_00208400 {
public:
    virtual ~Head_00208400() {}
    virtual void Run();
};

class Grid_00208400;

extern "C" bool func_00207F48(Cell_00208400* c, Obj_00208400* o);
extern "C" int func_00208AA0(Grid_00208400* g, Obj_00208400* o, Cell_00208400* c, Head_00208400* h, int n);
extern "C" int func_00208B38(Grid_00208400* g, Obj_00208400* o, Cell_00208400* c, Head_00208400* h, int n);

static inline bool Overlap_00208400(Box_00208400* a, Shape_00208400* s)
{
    if (a->max.x < s->box.min.x) return false;
    if (a->min.x > s->box.max.x) return false;
    if (s->box.min.z > a->max.z) return false;
    if (a->min.z > s->box.max.z) return false;
    if (s->box.min.y > a->max.y) return false;
    return !(s->box.max.y < a->min.y);
}

class Grid_00208400 {
public:
    char pad[0x30];
    Cell_00208400 m_cells[20][20];
    void Update(Base_00208400* added, Base_00208400* removed, Base_00208400* moved);
};

void Grid_00208400::Update(Base_00208400* added, Base_00208400* removed, Base_00208400* moved)
{
    Head_00208400 head;
    unsigned int nAdded = 0;
    Base_00208400* pa = added->mC;
    Base_00208400* pr = removed->mC;
    Base_00208400* pm = moved->mC;
    Base_00208400* n;
    Obj_00208400* o;
    unsigned int k;
    int i, j;

    for (Base_00208400* p = pa->Valid(); p; p = p->mC->Valid()) nAdded++;
    unsigned int nRemoved = 0;
    for (Base_00208400* p = pr->Valid(); p; p = p->mC->Valid()) nRemoved++;
    unsigned int nMoved = 0;
    for (Base_00208400* p = pm->Valid(); p; p = p->mC->Valid()) nMoved++;

    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            Cell_00208400* cell = &m_cells[i][j];
            int delta = 0;
            func_0010A950(D_00388A70, D_00388A70->m_D8);

            n = removed->mC->Valid();
            for (k = 0; k < nRemoved; k++) {
                o = (Obj_00208400*)n->m4;
                if (Overlap_00208400(&cell->box, o->m8)) delta = func_00208B38(this, o, cell, &head, delta);
                n = n->mC->Valid();
            }

            n = added->mC->Valid();
            for (k = 0; k < nAdded; k++) {
                o = (Obj_00208400*)n->m4;
                if (Overlap_00208400(&cell->box, o->m8)) delta = func_00208AA0(this, o, cell, &head, delta);
                n = n->mC->Valid();
            }

            n = moved->mC->Valid();
            for (k = 0; k < nMoved; k++) {
                o = (Obj_00208400*)n->m4;
                bool in = func_00207F48(cell, o);
                bool hit = Overlap_00208400(&cell->box, o->m8);
                if (hit != in) {
                    if (in) delta = func_00208B38(this, o, cell, &head, delta);
                    else delta = func_00208AA0(this, o, cell, &head, delta);
                }
                n = n->mC->Valid();
            }

            func_0010A9B0(D_00388A70);

            int count = cell->m24 + delta;
            if (delta < 0) {
                if (!cell->m2C || !func_0010A830(D_00388A70, count * 4, cell->m2C, 0)) {
                    cell->m2C = (Obj_00208400**)func_0010BF10(cell->m2C, count * 4);
                }
            } else if (delta > 0) {
                if (!cell->m2C || !func_0010A798(D_00388A70, count * 4, cell->m2C, 0)) {
                    cell->m2C = (Obj_00208400**)func_0010BF10(cell->m2C, count * 4);
                }
                n = head.mC->Valid();
                k = cell->m24;
                while (n) {
                    Base_00208400* next = n->mC->Valid();
                    cell->m2C[k] = (Obj_00208400*)n->m4;
                    delete n;
                    n = next;
                    k++;
                }
            }
            cell->m24 = count;
        }
    }

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            Cell_00208400* cell = &m_cells[i][j];
            Obj_00208400** p = cell->m2C;
            if (p) {
                int c = cell->m24;
                if (c) {
                    cell->m2C = (Obj_00208400**)func_0010BDE0(c * 4);
                    func_00331404(cell->m2C, p, c * 4);
                    func_0010BEB8(p);
                } else {
                    cell->m2C = 0;
                    func_0010BEB8(p);
                }
            }
        }
    }
}
