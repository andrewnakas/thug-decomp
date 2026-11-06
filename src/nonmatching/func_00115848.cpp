/* fuzzy: 59.6 */
struct Hdr_00115848 {
    int m_count;
    unsigned short m_4;
    unsigned short pad6;
    unsigned short m_8;
    unsigned short padA;
    unsigned int m_numSub;
    int m_size0;
    int m_size1;
};

struct Obj_00115848 {
    int m_0;
    int m_flags;
    int m_count;
    int padC[3];
    char* m_18;
    char* m_1C;
    int pad20;
    int m_24;
    char* m_28;
    int pad2C;
    void** m_subs;
    unsigned short* m_34;
    unsigned short* m_38;
    unsigned short m_3C;
    unsigned short m_3E;
    unsigned short m_40;
};

extern "C" int func_00115CC8(Obj_00115848* self);
extern "C" int func_00115840(Obj_00115848* self, int a, int b, int c);
extern "C" void* func_0010BDE0(int size);
extern "C" void* func_00118DF0(char** p);

static inline void Align4_00115848(char*& p)
{
    int r = (int)p & 3;
    if (r) {
        p = p + 4 - r;
    }
}

extern "C" int func_00115848(Obj_00115848* self, Hdr_00115848* hdr)
{
    char* p = (char*)&hdr->m_size0;
    self->m_count = hdr->m_count;
    self->m_3C = hdr->m_4;
    self->m_3E = hdr->m_8;
    int size0 = *(int*)p;
    p += 4;
    int size1 = *(int*)p;
    p += 4;
    self->m_34 = (unsigned short*)p;
    self->m_38 = self->m_34 + self->m_count;
    p = (char*)(self->m_38 + self->m_count);
    Align4_00115848(p);
    if (self->m_flags & 0x1000000) {
        self->m_24 = 0;
    } else {
        self->m_24 = 0;
    }
    if (self->m_flags & 0x80000) {
        self->m_28 = p;
        int bits = *(int*)p;
        p += 4 + ((bits - 1) / 32 + 1) * 4;
    }
    Align4_00115848(p);
    if (!func_00115CC8(self)) {
        self->m_18 = p;
        self->m_1C = p + size0;
        p = p + size0 + size1;
    }
    func_00115840(self, size0, size1, 0);
    Align4_00115848(p);
    if (hdr->m_numSub == 0) {
        self->m_subs = 0;
    } else {
        self->m_subs = (void**)func_0010BDE0(hdr->m_numSub * 4);
        for (unsigned int i = 0; i < hdr->m_numSub; i++) {
            void* sub = func_00118DF0(&p);
            if (!sub) {
                return 0;
            }
            self->m_subs[i] = sub;
        }
    }
    self->m_40 = hdr->m_numSub;
    return 1;
}
