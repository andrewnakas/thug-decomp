struct Block_0010C098 {
    char pad[0x38];
    int m_flags;
    char* m_end;
};

struct Heap_0010C098;
extern "C" int func_0010C258(Heap_0010C098* self);

struct Heap_0010C098 {
    int m0;
    char* m_lo;
    int m_minFree;
    char* m_hi;
    Block_0010C098* m_last[2];
    char* Resize(Block_0010C098* b, int n);
};

char* Heap_0010C098::Resize(Block_0010C098* b, int n)
{
    int dir = (b->m_flags & 2) >> 1;
    char* end = b->m_end + n * b->m_flags;
    Block_0010C098* o = m_last[dir ^ 1];
    int bad;
    if (o) {
        if (!dir) {
            bad = o->m_end < end;
        } else {
            bad = end < o->m_end;
        }
    } else {
        if (!dir) {
            bad = m_hi < end;
        } else {
            bad = end < m_lo;
        }
    }
    if (bad) {
        return 0;
    }
    char* r;
    if (dir) {
        r = end;
    } else {
        r = b->m_end;
    }
    b->m_end = end;
    int f = func_0010C258(this);
    if (f < m_minFree) {
        m_minFree = f;
    }
    return r;
}
