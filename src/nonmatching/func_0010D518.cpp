/* fuzzy: 94.2 */
struct Entry_0010D518 {
    unsigned int m_size;
    int m_packed;
    unsigned short m_nameLen;
    unsigned short m_refs;
    int m_id;
    char m_name[1];
};

struct Pack_0010D518 {
    int m_size;
    int m4;
    unsigned int m_count;
    Entry_0010D518 m_first;
};

extern "C" int func_00336228(const char* a, const char* b);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" int func_00331BB8(const char* s);
extern "C" int func_0010FEC0(const char* name);
extern "C" char* func_0010BDE0(int size);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" int func_0010FF18(const char* name, char* buf);
extern "C" void func_0010BEB8(void* p);
extern "C" void* func_00110E38(const char* name, const char* mode);
extern "C" long func_00110980(void* f);
extern "C" int func_00110F68(void* buf, int size, int n, void* f);
extern "C" void func_00110EF8(void* f);
extern "C" Pack_0010D518* func_0010D4E0(char* p);
extern "C" Entry_0010D518* func_0010D4A0(Entry_0010D518* e, int f);
extern "C" int func_0010AA28(int pool);
extern "C" char* func_0010BE28(int size, char* p);
extern "C" char* func_0010BE58(int size, char* p);
extern "C" char* func_00105F10(char* src, char* dst, int size);
extern char* D_00396568[100];
extern int D_00388A70;
extern char D_00388C50[];
extern char D_00388C58[];

void func_0010D518(char* name)
{
    for (int i = 0; i < 100; i++) {
        if (D_00396568[i] && func_00336228(D_00396568[i], name) == 0) {
            return;
        }
    }
    int slot = -1;
    for (int j = 0; j < 100; j++) {
        if (!D_00396568[j]) {
            slot = j;
            break;
        }
    }
    char buf[0x200];
    func_003331D0(buf, D_00388C50, name);
    int nameSize = (func_00331BB8(name) + 0x10) & ~0xF;
    int len = func_0010FEC0(buf);
    unsigned int total;
    char* data;
    if (len) {
        total = (len + 0x7FF) & 0xFFFFF800;
        total += nameSize;
        data = func_0010BDE0(total);
        func_00331A9C(data, name);
        if (!func_0010FF18(buf, data + nameSize)) {
            func_0010BEB8(data);
            data = 0;
        }
    } else {
        void* f = func_00110E38(buf, D_00388C58);
        len = func_00110980(f);
        total = (len + 0x7FF) & 0xFFFFF800;
        total += nameSize;
        data = func_0010BDE0(total);
        func_00331A9C(data, name);
        func_00110F68(data + nameSize, 1, len, f);
        func_00110EF8(f);
    }
    Pack_0010D518* pack = func_0010D4E0(data);
    unsigned int need = nameSize + 0xC;
    unsigned int count = pack->m_count;
    Entry_0010D518* e = &pack->m_first;
    for (unsigned int k = 0; k < count; k++) {
        need += 0x10;
        need += e->m_nameLen;
        need = (need + 0xF) & 0xFFFFFFF0;
        need += (e->m_size + 3) & 0xFFFFFFFC;
        e = func_0010D4A0(e, 0);
    }
    need += 0xC00;
    char* out;
    if (func_0010AA28(D_00388A70) == -1) {
        out = func_0010BE28(need, data);
    } else {
        out = func_0010BE58(need, data);
        unsigned int* s = (unsigned int*)(data + total);
        unsigned int* d = (unsigned int*)(out + need);
        for (unsigned int w = 0; w < total >> 2; w++) {
            *--d = *--s;
        }
        data = out + need - total;
    }
    for (int c = 0; c < nameSize; c++) {
        out[c] = data[c];
    }
    Pack_0010D518* src = (Pack_0010D518*)(data + nameSize);
    Pack_0010D518* dst = (Pack_0010D518*)(out + nameSize);
    dst->m_count = src->m_count;
    dst->m4 = src->m4;
    Entry_0010D518* se = &src->m_first;
    Entry_0010D518* de = &dst->m_first;
    for (unsigned int m = 0; m < count; m++) {
        de->m_size = se->m_size;
        de->m_id = se->m_id;
        de->m_packed = 0;
        de->m_refs = 0;
        de->m_nameLen = se->m_nameLen;
        for (int b = 0; b < se->m_nameLen; b++) {
            de->m_name[b] = se->m_name[b];
        }
        Entry_0010D518* next = func_0010D4A0(se, 0);
        char* ddata = (char*)((unsigned int)(de->m_name + de->m_nameLen + 0xF) & 0xFFFFFFF0);
        char* sdata = se->m_name + se->m_nameLen;
        if (se->m_packed) {
            unsigned int n = de->m_size;
            char* p = func_00105F10(sdata, ddata, se->m_packed);
            if (n & 3) {
                do {
                    *p = 0;
                    n++;
                    p++;
                } while (n & 3);
            }
        } else {
            unsigned int* s = (unsigned int*)sdata;
            unsigned int* d = (unsigned int*)ddata;
            unsigned int cnt = (se->m_size + 3) >> 2;
            for (unsigned int w = 0; w < cnt; w++) {
                *d++ = *s++;
            }
        }
        de = func_0010D4A0(de, 1);
        se = next;
    }
    dst->m_size = (char*)de - (char*)dst;
    D_00396568[slot] = out;
}
