/* fuzzy: 60.0 */
/* Loads a .HED index (from cdrom0: in uppercase, or host: on a dev kit) and builds a lookup table grouped by
   the first key func_001124E8 derives from each file name: one 12-byte group header per distinct key, a 0xFFFFFFFF
   terminator, then each group's {offset or name, size, key2} entries. With `keepNames` the index stays loaded,
   entries point at the names and sizes get bit 31 set. Returns 0 if the file cannot be opened or read. */
struct HedEntry_00112728 {
    unsigned int m_offset;
    unsigned int m_size;
    char m_name[4];
    HedEntry_00112728* Next(int len)
    {
        return (HedEntry_00112728*)((char*)this + ((len + 4) & ~3) + 8);
    }
};

struct Item_00112728 {
    unsigned int m_where;
    unsigned int m_size;
    unsigned int m_key2;
};

struct Group_00112728 {
    unsigned int m_count;
    unsigned int m_key;
    Item_00112728* m_items;
};

struct Heap_00112728;

struct Mem_00112728 {
    char pad0[0xD8];
    Heap_00112728* m_D8;
    char padDC[0x11C - 0xDC];
    Heap_00112728* m_11C;
};

extern int D_0038881C;
extern Mem_00112728* D_00388A70;
extern unsigned char D_00385971[];
extern char D_0035BFD0[];
extern char D_0035BFE8[];
extern char D_0035C000[];
extern char D_0035C018[];
extern char D_0035C040[];
extern char D_0035C068[];
extern char D_0035C078[];
extern char D_0035C088[];
extern char D_00388ED8[];

extern "C" int func_00331BB8(const char* s);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void func_00103F28(const char* fmt, ...);
extern "C" void func_0010FE68();
extern "C" char* func_00106818();
extern "C" int func_0031E880(const char* name, int mode);
extern "C" int func_0031EC88(int fd, int offset, int whence);
extern "C" int func_0031EEC0(int fd, void* buf, int size);
extern "C" int func_0031EB08(int fd);
extern "C" void* func_00110E38(const char* name, const char* mode);
extern "C" int func_00110980(void* f);
extern "C" int func_001110F8(void* f, int offset, int whence);
extern "C" int func_00110F68(void* buf, int size, int count, void* f);
extern "C" int func_00110EF8(void* f);
extern "C" void* func_0010A638(Mem_00112728* mem, int size, int align, Heap_00112728* heap);
extern "C" void* func_0010BDE0(int size);
extern "C" void func_0010A8D8(Mem_00112728* mem, void* p);
extern "C" void func_001124E8(const char* name, unsigned int* key, unsigned int* key2);

static inline int SectorAlign(int n)
{
    return (n + 0x7FF) & ~0x7FF;
}

Group_00112728* func_00112728(const char* name, int fromCd, int keepNames)
{
    char path[256];
    char upper[256];
    HedEntry_00112728* data;

    if (D_0038881C || fromCd) {
        int len = func_00331BB8(name);
        int i;
        for (i = 0; i < len; i++) {
            char c = name[i];
            upper[i] = (D_00385971[c] & 2) ? c - 0x20 : c;
        }
        upper[i] = 0;
        func_0010FE68();
        func_003331D0(path, D_0035BFD0, func_00106818(), upper);
        int fd;
        int tries = 0;
        while ((fd = func_0031E880(path, 1)) < 0) {
            func_00103F28(D_0035BFE8, path);
            if (++tries == 10)
                return 0;
        }
        func_00103F28(D_0035C000, upper);
        int size = func_0031EC88(fd, 0, 2);
        if (keepNames)
            data = (HedEntry_00112728*)func_0010A638(D_00388A70, SectorAlign(size), 1, D_00388A70->m_11C);
        else
            data = (HedEntry_00112728*)func_0010BDE0(SectorAlign(size));
        tries = 0;
        if (size) {
            for (;;) {
                func_0031EC88(fd, 0, 0);
                if (func_0031EEC0(fd, data, size) == size)
                    break;
                func_00103F28(D_0035C018, path);
                if (++tries == 4) {
                    func_00103F28(D_0035C040, path);
                    func_0010A8D8(D_00388A70, data);
                    return 0;
                }
            }
        }
        func_0031EB08(fd);
    } else {
        func_003331D0(path, keepNames ? D_0035C068 : D_0035C078, name);
        void* f = func_00110E38(path, D_00388ED8);
        if (!f) {
            func_00103F28(D_0035C088, path);
            return 0;
        }
        int size = func_00110980(f);
        func_001110F8(f, 0, 0);
        if (keepNames)
            data = (HedEntry_00112728*)func_0010A638(D_00388A70, SectorAlign(size), 1, D_00388A70->m_11C);
        else
            data = (HedEntry_00112728*)func_0010BDE0(SectorAlign(size));
        func_00110F68(data, 1, size, f);
        func_00110EF8(f);
    }

    int count = 0;
    int groups = 0;
    HedEntry_00112728* e;
    for (e = data; e->m_offset != 0xFFFFFFFF; e = e->Next(func_00331BB8(e->m_name)))
        count++;
    int total = count + 1;
    unsigned int* offsets = (unsigned int*)func_0010A638(D_00388A70, count * 4, 1, D_00388A70->m_D8);
    unsigned int* sizes = (unsigned int*)func_0010A638(D_00388A70, count * 4, 1, D_00388A70->m_D8);
    unsigned int* keys = (unsigned int*)func_0010A638(D_00388A70, count * 4, 1, D_00388A70->m_D8);
    unsigned int* keys2 = (unsigned int*)func_0010A638(D_00388A70, count * 4, 1, D_00388A70->m_D8);
    char** names = (char**)func_0010A638(D_00388A70, count * 4, 1, D_00388A70->m_D8);

    unsigned int* po = offsets;
    unsigned int* ps = sizes;
    unsigned int* pk = keys;
    unsigned int* pk2 = keys2;
    char** pn = names;
    for (e = data; e->m_offset != 0xFFFFFFFF; e = e->Next(func_00331BB8(e->m_name))) {
        *po++ = e->m_offset;
        *ps++ = e->m_size;
        *pn++ = e->m_name;
        func_001124E8(e->m_name, pk++, pk2++);
    }

    for (int i = 0; i < count; i++) {
        int isNew = 1;
        for (int j = 0; j < i; j++) {
            if (keys[i] == keys[j]) {
                isNew = 0;
                break;
            }
        }
        if (isNew)
            groups++;
    }

    Group_00112728* table = (Group_00112728*)func_0010A638(D_00388A70, (groups + total) * 12, 1, 0);
    int n = 0;
    for (int i = 0; i < count; i++) {
        int isNew = 1;
        for (int j = 0; j < n; j++) {
            if (table[j].m_key == keys[i]) {
                isNew = 0;
                break;
            }
        }
        if (isNew) {
            table[n].m_key = keys[i];
            n++;
        }
    }

    Item_00112728* item = (Item_00112728*)&table[groups + 1];
    for (int g = 0; g < groups; g++) {
        table[g].m_items = item;
        int k = 0;
        for (int i = 0; i < count; i++) {
            if (keys[i] == table[g].m_key) {
                item->m_size = sizes[i];
                if (keepNames) {
                    item->m_size = sizes[i] | 0x80000000;
                    item->m_where = (unsigned int)names[i];
                } else {
                    item->m_where = offsets[i];
                }
                item->m_key2 = keys2[i];
                k++;
                item++;
            }
        }
        table[g].m_count = k;
    }
    table[groups].m_count = 0xFFFFFFFF;

    func_0010A8D8(D_00388A70, names);
    func_0010A8D8(D_00388A70, keys2);
    func_0010A8D8(D_00388A70, keys);
    func_0010A8D8(D_00388A70, sizes);
    func_0010A8D8(D_00388A70, offsets);
    if (!keepNames)
        func_0010A8D8(D_00388A70, data);
    return table;
}
