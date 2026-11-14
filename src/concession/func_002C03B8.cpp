/* force: {"kind": "lfr", "block": 4, "reg": 136, "hard": 2} */
/* force: {"kind": "lfr", "block": 6, "reg": 138, "hard": 2} */
/* force: {"kind": "lfr", "block": 8, "reg": 144, "hard": 2} */
struct Box_002C03B8 {
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

static inline bool Overlap_002C03B8(const Box_002C03B8* a, const Box_002C03B8* b)
{
    bool r = true;
    int end = a->x + a->w;
    if (b->x >= end) r = false;
    else {
        end = b->x + b->w;
        if (a->x >= end) r = false;
        else {
            end = a->z + a->d;
            if (b->z >= end) r = false;
            else {
                end = b->z + b->d;
                if (a->z >= end) r = false;
            }
        }
    }
    return r;
}

struct Obj_002C03B8 {
    char pad[0x6AA8];
    Box_002C03B8 m_boxes[8];
    unsigned int m_numBoxes;
    bool Hits(const Box_002C03B8* box);
};

bool Obj_002C03B8::Hits(const Box_002C03B8* box)
{
    for (unsigned int i = 0; i < m_numBoxes; i++) {
        bool hit = Overlap_002C03B8(box, &m_boxes[i]);
        if (hit) return true;
    }
    return false;
}
