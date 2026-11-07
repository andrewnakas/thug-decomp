/* fuzzy: 84.9 */
struct Heap_00108AB0 {
    char pad[0xD8];
    int m_D8;
    int m_DC;
};

struct Entry_00108AB0 {
    int m_handle;
    char m_name[0x40];
};

struct Loader_00108AB0 {
    char pad[0x14];
    int m_14;
    int m_18;
    Entry_00108AB0 m_entries[8];
    int m_count;
    void Load(const char* name, int async, int required, int top);
};

extern Heap_00108AB0* D_00388A70;
extern int D_0038881C;
extern char D_0035AF40[];
extern char D_00388A38[];
extern char D_00388A40[];
extern char D_0035AF58[];
extern char D_0035AF80[];
extern char D_0035AF98[];
extern char D_0035AFB8[];

extern "C" int func_001E5648(const char* name, int def);
extern "C" int func_0010EC50();
extern "C" int func_001DFD90();
extern "C" void func_003331D0(char* buf, const char* fmt, ...);
extern "C" int func_0010FC30();
extern "C" int func_0010EC78(const char* path, int mode, int prio);
extern "C" int  func_00331A9C(char* d, const char* s);
extern "C" int func_0010E558(int h);
extern "C" void func_0010BFC0(const char* path);
extern "C" void* func_0010A638(Heap_00108AB0* heap, int size, int align, int sub);
extern "C" void func_0010BFC8();
extern "C" void func_0010E548(int h, void (*cb)(), void* data, void* buf);
extern "C" void func_00108F88();
extern "C" void func_0010E698(int h, void* buf, int n, int size);
extern "C" int func_0010FEC0(const char* path);
extern "C" int func_0010FF18(const char* path, void* buf);
extern "C" void func_00103F28(const char* fmt, ...);
extern "C" void* func_00110E38(const char* path, const char* mode);
extern "C" long func_00110980(void* fh);
extern "C" void func_00110F68(void* buf, int n, int size, void* fh);
extern "C" void func_00110EF8(void* fh);
extern "C" void* func_00104760(int size, int heap, int n);
extern "C" void* func_001081A8(void* p, void* buf, int top);
extern "C" void func_0010A1E8(int dict, const char* name, void* item);

static inline void* Alloc(int size, int top)
{
    Heap_00108AB0* heap = D_00388A70;
    if (top) {
        return func_0010A638(heap, size, 1, heap->m_DC);
    }
    return func_0010A638(heap, size, 1, heap->m_D8);
}

static inline int HeapId(int top)
{
    return top ? D_00388A70->m_DC : D_00388A70->m_D8;
}

void Loader_00108AB0::Load(const char* name, int async, int required, int top)
{
    char path[0x100];
    if ((m_18 = func_001E5648(D_0035AF40, 0) != 0)) {
        return;
    }
    if (!func_0010EC50()) {
        async = 0;
    }
    if (!async && func_001DFD90()) {
        return;
    }
    func_003331D0(path, D_00388A38, name);
    int start = func_0010FC30();
    int size;
    void* buf;
    if (async) {
        int h = func_0010EC78(path, async ^ 1, 100);
        if (h) {
            func_00331A9C(m_entries[m_count].m_name, name);
            int n = m_count;
            m_entries[n].m_handle = h;
            m_count = n + 1;
            size = func_0010E558(h);
            func_0010BFC0(path);
            buf = Alloc(size, top);
            func_0010BFC8();
            func_0010E548(h, func_00108F88, this, buf);
            func_0010E698(h, buf, 1, size);
            return;
        }
    }
    size = func_0010FEC0(path);
    if (size) {
        func_0010BFC0(path);
        buf = Alloc(size, top);
        func_0010BFC8();
        if (!func_0010FF18(path, buf)) {
            func_00103F28(D_0035AF58, path);
        }
    } else {
        void* fh = func_00110E38(path, D_00388A40);
        if (!fh && (required || D_0038881C)) {
            func_00103F28(D_0035AF80, path);
            return;
        }
        size = func_00110980(fh);
        func_0010BFC0(path);
        buf = Alloc(size, top);
        func_0010BFC8();
        func_00110F68(buf, 1, size, fh);
        if (D_0038881C && size != *(int*)buf) {
            func_00103F28(D_0035AF98, path);
        }
        func_00110EF8(fh);
    }
    func_00103F28(D_0035AFB8, name, size, func_0010FC30() - start);
    if (top) {
        func_0010A1E8(m_14, name, func_001081A8(func_00104760(0x1C, D_00388A70->m_DC, 1), buf, top));
    } else {
        func_0010A1E8(m_14, name, func_001081A8(func_00104760(0x1C, D_00388A70->m_D8, 1), buf, top));
    }
}
